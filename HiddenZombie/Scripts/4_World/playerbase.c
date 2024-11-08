modded class PlayerBase
{
    protected bool m_IsUndetectable; 

    override void EEItemAttached(EntityAI item, string slot_name)
    {
        super.EEItemAttached(item, slot_name);
        UpdateUndetectableStatus();
    }

    override void EEItemDetached(EntityAI item, string slot_name)
    {
        super.EEItemDetached(item, slot_name);
        UpdateUndetectableStatus();
    }

    // Checks if the player is wearing the specific jacket and sets the undetectable flag
    void UpdateUndetectableStatus()
    {
        EntityAI bodyAttachment = FindAttachmentBySlotName("Body");
        if (bodyAttachment && bodyAttachment.IsKindOf("ZombieJacket"))
        {
            m_IsUndetectable = true;
        }
        else
        {
            m_IsUndetectable = false;
        }
    }

    // Override the method that zombies use to detect players
    override bool CanBeTargetedByAI(EntityAI ai)
    {
        // If undetectable and AI is a zombie, return false to prevent targeting
        if (m_IsUndetectable && ai.IsInherited(ZombieBase))
        {
            return false;
        }
        return super.CanBeTargetedByAI(ai);
    }
}
