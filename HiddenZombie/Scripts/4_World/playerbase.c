modded class PlayerBase
{
    protected bool p_IsUndetectable;
    protected bool p_HasFullZombieSuit;
    protected ref HordeLeader hordeLeader;
    protected ref ManicSystem manicSystem;

    void PlayerBase()
    {
        hordeLeader = new HordeLeader(this);
        manicSystem = new ManicSystem(this);  
        SetEventMask(EntityEvent.FRAME);
    }

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


    void UpdateUndetectableStatus()
    {
        bool hasPartialSuit = CheckForPartialZombieSuit();
        bool hasFullSuit = CheckForFullZombieSuit();

        p_IsUndetectable = hasPartialSuit;
        p_HasFullZombieSuit = hasFullSuit;

        // Activate or deactivate horde leading based on full suit status
        if (p_HasFullZombieSuit)
        {
            hordeLeader.Activate();
            manicSystem.Start();
        }
        else
        {
            hordeLeader.Deactivate();
            manicSystem.Stop();
        }
    }

    override bool CanBeTargetedByAI(EntityAI ai)
    {
        // If undetectable and AI is a zombie, return false to prevent targeting
        if (p_IsUndetectable && ai.IsInherited(ZombieBase))
        {
            return false;
        }
        return super.CanBeTargetedByAI(ai);
    }


    bool CheckForPartialZombieSuit()
    {
        EntityAI bodyAttachment = FindAttachmentBySlotName("Body");
        EntityAI legsAttachment = FindAttachmentBySlotName("Legs");
        EntityAI feetAttachment = FindAttachmentBySlotName("Feet");


        // Rest of the suit not implemented yet
        return bodyAttachment && bodyAttachment.IsKindOf("ZombieJacket");
    }

    bool CheckForFullZombieSuit()
    {
        EntityAI bodyAttachment = FindAttachmentBySlotName("Body");
        EntityAI legsAttachment = FindAttachmentBySlotName("Legs");
        EntityAI feetAttachment = FindAttachmentBySlotName("Feet");
        EntityAI headAttachment = FindAttachmentBySlotName("Headgear");

        // Rest of the suit not implemented yet
        return headAttachment && headAttachment.IsKindOf("ZombieMask");
    }

}
