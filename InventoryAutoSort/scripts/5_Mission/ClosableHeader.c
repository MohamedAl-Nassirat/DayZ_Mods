<<<<<<< HEAD
modded class ClosableHeader 
{ 

=======
modded class ClosableHeader
{
>>>>>>> 44e944fde28666e46944e83837bd08c387384c85
    protected Widget m_widget;
    protected ButtonWidget m_SortButton;
    protected ButtonWidget m_StackButton;
    protected CheckBoxWidget m_CheckMark;
<<<<<<< HEAD
    
    protected ButtonWidget m_InventoryGridPlaceholder;

    protected ref map<ButtonWidget, int> m_ButtonIndices = new map<ButtonWidget, int>();
    protected InventoryGrid m_InventoryGrid;
=======

>>>>>>> 44e944fde28666e46944e83837bd08c387384c85
    protected PlayerBase m_LocalPlayer;

    void ClosableHeader(LayoutHolder parent, string function_name)
    {
        m_LocalPlayer = PlayerBase.Cast(GetGame().GetPlayer());

        m_widget = GetGame().GetWorkspace().CreateWidgets("InventoryAutoSort/scripts/GUI/sort.layout", parent.GetMainWidget());

<<<<<<< HEAD

        m_SortButton = ButtonWidget.Cast(m_widget.FindAnyWidget("ButtonWidget0"));
        m_StackButton = ButtonWidget.Cast(m_widget.FindAnyWidget("ButtonWidget1"));
        

        WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown(m_SortButton, this, "SortCargo");
        WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown(m_StackButton, this, "StackCargo");



        /// WIP: - Part of SelectItems
        m_CheckMark = CheckBoxWidget.Cast(m_widget.FindAnyWidget("CheckMark"));
        WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown(m_CheckMark, this, "CheckCargo");

    }


    void SortCargo()
    {
        if (!m_Entity) return;

        Object entityIB;
        if (!Class.CastTo(entityIB, m_Entity)) return;

        m_LocalPlayer.RPCSingleParam(InventoryAutoSort.SORT_CARGO, new Param1<Object>(entityIB), true, null);
    }

    void StackCargo()
    {
        if (!m_Entity) return;

        Object entityIB;
        if (!Class.CastTo(entityIB, m_Entity)) return;

        m_LocalPlayer.RPCSingleParam(InventoryAutoSort.STACK_CARGO, new Param1<Object>(entityIB), true, null);
    }

    override void SetItemPreview(EntityAI entity_ai)
    {
        super.SetItemPreview(entity_ai);

        CargoBase cargo = entity_ai.GetInventory().GetCargo();
        if (!cargo || (cargo.GetWidth() <= 0 && cargo.GetHeight() <= 0))
            m_widget.Show(false);
    }

    override void SetName(string name)
    {
        super.SetName(name);
    }







    /// WIP: - Part of SelectItems
=======
        m_SortButton = ButtonWidget.Cast(m_widget.FindAnyWidget("ButtonWidget0"));
        m_StackButton = ButtonWidget.Cast(m_widget.FindAnyWidget("ButtonWidget1"));
        m_CheckMark = CheckBoxWidget.Cast(m_widget.FindAnyWidget("CheckMark"));

        // Register events for buttons and checkbox
        WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown(m_SortButton, this, "SortCargo");
        WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown(m_StackButton, this, "StackCargo");
        WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown(m_CheckMark, this, "CheckCargo");
    }

>>>>>>> 44e944fde28666e46944e83837bd08c387384c85
    void CheckCargo(Widget w, int x, int y, int button)
    {
        if (button == MouseState.LEFT)
        {
            bool isChecked = m_CheckMark.IsChecked();

            if (isChecked)
            {
                m_CheckMark.SetChecked(false);
                if (!m_Entity) return;



                Object entityIB;
                if (!Class.CastTo(entityIB, m_Entity)) return;
                m_LocalPlayer.RPCSingleParam(InventoryAutoSort.CHECK_CARGO, new Param1<EntityAI>(entityIB), true, null);
                Print("[InventoryAutoSort] Selected container: " + entityIB);
            }
            else
            {
                m_CheckMark.SetChecked(true);
                Print("[InventoryAutoSort] Deselected container.");
            }
        }
    }

<<<<<<< HEAD
=======


    void SortCargo()
    {
        if (!m_Entity) return;

        Object entityIB;
        if (!Class.CastTo(entityIB, m_Entity)) return;

        m_LocalPlayer.RPCSingleParam(InventoryAutoSort.SORT_CARGO, new Param1<Object>(entityIB), true, null);
    }

    void StackCargo()
    {
        if (!m_Entity) return;

        Object entityIB;
        if (!Class.CastTo(entityIB, m_Entity)) return;

        m_LocalPlayer.RPCSingleParam(InventoryAutoSort.STACK_CARGO, new Param1<Object>(entityIB), true, null);
    }






















    override void SetItemPreview(EntityAI entity_ai)
    {
        super.SetItemPreview(entity_ai);

        CargoBase cargo = entity_ai.GetInventory().GetCargo();
        if (!cargo || (cargo.GetWidth() <= 0 && cargo.GetHeight() <= 0))
            m_widget.Show(false);
    }

    override void SetName(string name)
    {
        super.SetName(name);
    }
>>>>>>> 44e944fde28666e46944e83837bd08c387384c85
}