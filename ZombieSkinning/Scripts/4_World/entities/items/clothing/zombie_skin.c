modded class ZombieSkinJacket extends Clothing
{
    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionWearClothing);
    }
}
