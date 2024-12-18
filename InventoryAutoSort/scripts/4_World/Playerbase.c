modded class PlayerBase
{
<<<<<<< HEAD
    /// WIP: - Part of SelectItems
    private EntityAI m_SourceEntity;
    private EntityAI m_TargetEntity;


    private ref AutoSort m_InventorySorter;
    private ref AutoStack m_InventoryStacker;



    void PlayerBase()
    {
        m_InventorySorter = new AutoSort();
        m_InventoryStacker = new AutoStack();
    }

    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        super.OnRPC(sender, rpc_type, ctx);

        Object entityIB;
        Param1<Object> param;

        if (rpc_type == InventoryAutoSort.SORT_CARGO)
        {
            if (ctx.Read(param))
                entityIB = param.param1;

            Print("[InventoryAutoSort] SORT_CARGO entity: " + entityIB.GetType());
            EntityAI sortEntity = EntityAI.Cast(entityIB);
            m_InventorySorter.RunMultiIterationSort(sortEntity);
        }

        if (rpc_type == InventoryAutoSort.STACK_CARGO)
        {
            if (ctx.Read(param))
                entityIB = param.param1;

            Print("[InventoryAutoSort] STACK_CARGO entity: " + entityIB.GetType());

            EntityAI stackEntity = EntityAI.Cast(entityIB);
            if (!stackEntity)
            {
                Print("[InventoryAutoSort] STACK_CARGO failed: Invalid entity");
                return;
            }
            m_InventoryStacker.InventoryAutoStackCargo(stackEntity);
        }

        if (rpc_type == InventoryAutoSort.CHECK_CARGO)
        {
            if (ctx.Read(param))
                entityIB = param.param1;

            m_TargetEntity = EntityAI.Cast(entityIB);

            Print("[InventoryAutoSort] CHECK_CARGO entity: " + entityIB.GetType());


            /// TODO: Implement what happens after we check the cargo
            /// WIP: - Part of SelectItems
        }

        if (rpc_type == InventoryAutoSort.SEND_CARGO)
        {
            if (ctx.Read(param))
                entityIB = param.param1;

            /// TODO: Implement what happens after we send the cargo over to checked item
            /// WIP: - Part of SelectItems
        }
    }

  
    

    /// WIP: - Part of SelectItems
    private void TryMoveItemToStorage()
    {
        if (m_SourceEntity && m_TargetEntity)
        {
            MoveItemToStorage(m_SourceEntity, m_TargetEntity);
            // Clear references after moving
            m_SourceEntity = null;
            m_TargetEntity = null;
=======

    void PlayerBase()
    {

    }

    override void OnRPC( PlayerIdentity sender, int rpc_type, ParamsReadContext ctx )
    {
        super.OnRPC( sender, rpc_type, ctx );

        Object entityIB;
        Param1< Object > param;

        if ( rpc_type == InventoryAutoSort.SORT_CARGO )
        {
            if ( ctx.Read( param ) )
                entityIB = param.param1;

            Print("[InventoryAutoSort] SORT_CARGO entity: " + entityIB.GetType());

        }

        if ( rpc_type == InventoryAutoSort.STACK_CARGO )
        {
            if ( ctx.Read( param ) )
                entityIB = param.param1;
            
            Print("[InventoryAutoSort] STACK_CARGO entity: " + entityIB.GetType());
        }


        if ( rpc_type == InventoryAutoSort.CHECK_CARGO)
        {
            if (ctx.Read ( param ))
                entityIB = param.param1;

            Print("[InventoryAutoSort] CHECK_CARGO entity: " + entityIB.GetType());
>>>>>>> 44e944fde28666e46944e83837bd08c387384c85
        }
    }


<<<<<<< HEAD
    /// WIP: - Part of SelectItems
    private void MoveItemToStorage(EntityAI item, EntityAI targetStorage)
    {
        if (!item || !targetStorage)
        {
            Print("[InventoryAutoSort] MoveItemToStorage failed: Invalid parameters");
            return;
        }

        InventoryLocation src = new InventoryLocation();
        InventoryLocation dst = new InventoryLocation();

        if (item.GetInventory().GetCurrentInventoryLocation(src))
        {
            if (targetStorage.GetInventory().FindFreeLocationFor(item, FindInventoryLocationType.ANY, dst))
            {
                if (GetGame().GetPlayer().GetHumanInventory().TakeToDst(InventoryMode.PREDICTIVE, src, dst))
                {
                    Print("[InventoryAutoSort] Item moved to storage: " + item.GetType());
                }
                else
                {
                    Print("[InventoryAutoSort] MoveItemToStorage failed: Unable to move item.");
                }
            }
        }
    }
}


=======
}
>>>>>>> 44e944fde28666e46944e83837bd08c387384c85
