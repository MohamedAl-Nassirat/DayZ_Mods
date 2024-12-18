class AutoSort {


    void RunMultiIterationSort(EntityAI entity)
    {
        int maxIterations = 10; // Safety limit, in case it never stabilizes
        int iterationCount = 0;
        bool changed;

        while (true)
        {
            array<vector> oldPositions = CaptureCurrentItemPositions(entity);

            // Run a single sorting iteration
            InventoryAutoSortCargo(entity);

            array<vector> newPositions = CaptureCurrentItemPositions(entity);
            changed = !PositionsAreSame(oldPositions, newPositions);
            iterationCount++;

            if (!changed || iterationCount >= maxIterations)
            {
                break;
            }
        }

        Print("[InventoryAutoSort] Sorting stabilized after " + iterationCount + " iterations.");
    }



    private void InventoryAutoSortCargo(EntityAI entity)
    {
        CargoBase cargo = entity.GetInventory().GetCargo();
        if (!cargo)
        {
            Print("[InventoryAutoSort] SORT_CARGO failed: No cargo found");
            return;
        }
        
        // Props
        int cargoWidth = cargo.GetWidth();
        int cargoHeight = cargo.GetHeight();

        // initalize final output cargo
        array< ref array<int> > cargoGrid = InitializeCargoGrid( cargoWidth, cargoHeight );
        
        // Step 1: Get all items and create their EntityProperty identity
        ref array<ItemBase> cargoItems = new array<ItemBase>;
        ref EntityPropertySorter entityProperties = new EntityPropertySorter();
        
        for (int i = 0; i < cargo.GetItemCount(); i++)
        {
            ItemBase item = ItemBase.Cast(cargo.GetItem(i));
            if (!item) continue;
            
            cargoItems.Insert(item);
            
            int itemWidth, itemHeight;
        
            InventoryLocation itemLoc = new InventoryLocation();
        
            item.GetInventory().GetCurrentInventoryLocation(itemLoc);
            
            cargo.GetItemSize(i, itemWidth, itemHeight); // Get dimensions from cargo\

            bool flip = itemLoc.GetFlip(); // is it better to flip an item?
            if (flip)
            {
                int temp = itemWidth;
                itemWidth = itemHeight;
                itemHeight = temp;
            }
            
            // Create EntityProperty inline and add to array
            entityProperties.Insert(new EntityProperty(item, itemWidth, itemHeight, flip));
        }

        // Step 2: Now entity properties is populated with the correct EntityProperty identity for each item
        entityProperties.Sort();

        // --- Build a snapshot of the current layout ---
        // Mark all current item placements in a temporary grid
        array<ref array<int>> currentLayoutGrid = InitializeCargoGrid(cargoWidth, cargoHeight);
        for (int c = 0; c < cargo.GetItemCount(); c++)
        {
            ItemBase it = ItemBase.Cast(cargo.GetItem(c));
            InventoryLocation itLoc = new InventoryLocation();
            it.GetInventory().GetCurrentInventoryLocation(itLoc);
            int ix = itLoc.GetCol();
            int iy = itLoc.GetRow();
            int iW, iH;
            cargo.GetItemSize(c, iW, iH);

            // Mark these cells as occupied
            for (int hh = 0; hh < iH; hh++)
            {
                for (int ww = 0; ww < iW; ww++)
                {
                    currentLayoutGrid[iy + hh][ix + ww] = 1;
                }
            }
        }




        // Step 3: Now we send over the items


        foreach ( ref EntityProperty entityProp : entityProperties )
        {
            ItemBase eAI = ItemBase.Cast( entityProp.entity );

            InventoryLocation src = new InventoryLocation();
            eAI.GetInventory().GetCurrentInventoryLocation( src );
            InventoryLocation dst = new InventoryLocation();
            bool isPlaced = false;

            isPlaced = TryPlaceItem( cargoGrid, entityProp, cargo, src, dst, cargoWidth, cargoHeight );
            if ( !isPlaced )
            {
                int temp2 = entityProp.width;
                entityProp.width = entityProp.height;
                entityProp.height = temp2;
                TryPlaceItem( cargoGrid, entityProp, cargo, src, dst, cargoWidth, cargoHeight, true );
            }
        }
    }

    private bool PositionsAreSame(array<vector> oldPositions, array<vector> newPositions)
    {
        if (oldPositions.Count() != newPositions.Count())
            return false;

        // Sort both arrays so that order differences do not affect comparison
        oldPositions.Sort();
        newPositions.Sort();

        for (int i = 0; i < oldPositions.Count(); i++)
        {
            if (oldPositions[i] != newPositions[i])
                return false;
        }

        return true;
    }

    private array<vector> CaptureCurrentItemPositions(EntityAI entity)
    {
        array<vector> positions = new array<vector>;
        CargoBase cargo = entity.GetInventory().GetCargo();
        if (!cargo) return positions;

        for (int i = 0; i < cargo.GetItemCount(); i++)
        {
            ItemBase item = ItemBase.Cast(cargo.GetItem(i));
            if (!item) continue;

            InventoryLocation il = new InventoryLocation();
            item.GetInventory().GetCurrentInventoryLocation(il);

            // Store the (row, col) of the item in the vector's x and y components
            // The z component is unused, so we can leave it as 0.
            vector pos = Vector(il.GetRow(), il.GetCol(), 0);
            positions.Insert(pos);
        }

        return positions;
    }



    bool TryPlaceItem(ref array<ref array<int>> cargoGrid, ref EntityProperty entityProp, CargoBase cargo, InventoryLocation src, InventoryLocation dst, int cargoWidth, int cargoHeight, bool flip = false)
    {
        // Step 1: Prioritize filling gaps in existing rows
        for (int y = 0; y < cargoHeight; y++) // Iterate through rows
        {
            for (int x = 0; x <= cargoWidth - entityProp.width; x++) // Scan for gaps
            {
                if (CanPlaceItem(cargoGrid, x, y, entityProp.width, entityProp.height))
                {
                    PlaceItem(cargoGrid, x, y, entityProp.width, entityProp.height);
                    PlaceItemInInventory(cargo, entityProp, src, dst, x, y, flip);
                    return true; // Item placed successfully
                }
            }
        }

        // Step 2: If no gaps, perform default top-left to bottom-right placement
        for (int z = 0; z <= cargoHeight - entityProp.height; z++)
        {
            for (int j = 0; j <= cargoWidth - entityProp.width; j++)
            {
                if (CanPlaceItem(cargoGrid, j, z, entityProp.width, entityProp.height))
                {
                    PlaceItem(cargoGrid, j, z, entityProp.width, entityProp.height);
                    PlaceItemInInventory(cargo, entityProp, src, dst, j, z, flip);
                    return true; // Item placed successfully
                }
            }
        }

        return false; // No valid placement found
    }

    void PlaceItemInInventory(CargoBase cargo, EntityProperty entityProp, InventoryLocation src, InventoryLocation dst, int x, int y, bool flip)
    {
        dst.SetCargoAuto(cargo, ItemBase.Cast(entityProp.entity), y, x, flip);
        InventoryInputUserData.SendServerMove(null, InventoryCommandType.SYNC_MOVE, src, dst);
        GameInventory.LocationSyncMoveEntity(src, dst);
    }


    void PlaceItem(array<ref array<int>> grid, int x, int y, int width, int height)
    {
        for (int i = 0; i < height; i++) // Item height
        {
            for (int j = 0; j < width; j++) // Item width
            {
                grid[y + i][x + j] = 1; // Mark cell as occupied
            }
        }
    }

    bool CanPlaceItem(array<ref array<int>> grid, int x, int y, int width, int height)
    {
        for (int i = 0; i < height; i++) // Iterate item height
        {
            for (int j = 0; j < width; j++) // Iterate item width
            {
                if (grid[y + i][x + j] != 0) // Check if cell is already occupied
                    return false;
            }
        }
        return true; // All cells are free
    }


    array< ref array<int> > InitializeCargoGrid( int cargoWidth, int cargoHeight )
    {
        array<ref array<int>> cargoGrid = new array< ref array<int> >;
        for (int y = 0; y < cargoHeight; y++)
        {
            array<int> row = new array<int>;
            for ( int x = 0; x < cargoWidth; x++ )
                row.Insert( 0 );

            cargoGrid.Insert( row );
        }
        return cargoGrid;
    }
}

class EntityPropertySorter : array<ref EntityProperty>
{
    int Compare(ref EntityProperty a, ref EntityProperty b)
    {
        // Compare by area first
        if (a.area < b.area) return -1;
        if (a.area > b.area) return 1;

        // If areas are equal, compare alphabetically
        string nameA = a.entity.GetType();
        string nameB = b.entity.GetType();

        if (nameA < nameB) return -1;
        if (nameA > nameB) return 1;

        return 0; // Strings are equal
    }
}