class AutoStack {


    /// @brief  Stacks any items possible in a given container
    /// @param entity 
    void InventoryAutoStackCargo(EntityAI entity)
    {
        CargoBase cargo = entity.GetInventory().GetCargo();
        if (!cargo)
        {
            Print("[InventoryAutoSort] STACK_CARGO failed: No cargo found");
            return;
        }

        ref array<ItemBase> cargoItems = new array<ItemBase>;
        for (int i = 0; i < cargo.GetItemCount(); i++)
        {
            ItemBase item = ItemBase.Cast(cargo.GetItem(i));
            if (item)
                cargoItems.Insert(item);
        }

        for (int j = 0; j < cargoItems.Count(); j++)
        {
            ItemBase itemA = cargoItems[j];
            if (!itemA)
                continue;

            for (int k = j + 1; k < cargoItems.Count(); k++)
            {
                ItemBase itemB = cargoItems[k];
                if (!itemB || !itemA.CanBeCombined(itemB, false))
                    continue;

                if (itemA.IsInherited(Ammunition_Base))
                {
                    Magazine magA = Magazine.Cast(itemA);
                    if (magA && magA.GetAmmoCount() > 0)
                        magA.CombineItems(itemB);
                }
                else
                {
                    itemA.CombineItems(itemB);
                }

                if (itemB.GetQuantity() <= 0)
                {
                    cargoItems.Remove(k);
                    k--; 
                }
            }
        }
    }



}