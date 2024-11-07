modded class PlayerBase
{
    protected bool m_WearingZombieSkin;

    override void EEItemAttached(EntityAI item, string slot_name)
    {
        super.EEItemAttached(item, slot_name);
        UpdateZombieSkinStatus();
        Print("[ZombieSkinning] EEItemAttached called for " + item.GetType());
    }

    override void EEItemDetached(EntityAI item, string slot_name)
    {
        super.EEItemDetached(item, slot_name);
        UpdateZombieSkinStatus();
    }

    void UpdateZombieSkinStatus()
    {
        EntityAI bodyAttachment = FindAttachmentBySlotName("Body");
        if (bodyAttachment && bodyAttachment.IsKindOf("ZombieSkinJacket"))
        {
            Print("[ZombieSkin] m_WearingZombieSkin = true");
            m_WearingZombieSkin = true;
        }
        else
        {
            Print("[ZombieSkin] m_WearingZombieSkin = false");
            m_WearingZombieSkin = false;
        }
    }

    override bool CanBeTargetedByAI(EntityAI ai)
    {
        if (m_WearingZombieSkin && ai.IsInherited(ZombieBase))
        {
            return false; // Player cannot be targeted by zombies
        }
        return super.CanBeTargetedByAI(ai);
    }
}
