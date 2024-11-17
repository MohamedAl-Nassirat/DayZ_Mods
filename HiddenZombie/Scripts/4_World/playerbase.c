modded class PlayerBase
{
    protected bool p_IsUndetectable;
    protected bool p_HasFullZombieSuit;
    protected ref Timer m_HordeLeaderTimer;
    protected ref HordeLeader hordeLeader;



    void PlayerBase()
    {
        hordeLeader = new HordeLeader(this);  // Initialize HordeLeader
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



    // THIS CAUSES HORDE LEADING TO WORK ONLY UPON ITEMATTACH OR DETTACH
    // THE K BUTTON WORKS THAT IT PLAYS THE ZOMBIE SOUND LOCALLY ON CLIENT SIDE BUT SERVER DOES NOT HEAR IT SO ZOMBIES DONT AGGRO
    // NEEDS MAJOR OVERHAUL AND POTENTIAL SERPERATION FROM PLAYERBASE CODE
    // if (p_HasFullZombieSuit)
    // {
    //     EmitZombieNoise();
    // }
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
        }
        else
        {
            hordeLeader.Deactivate();
        }
    }



    // Polling for key press in the update loop
    // Most defintitly giving us an error right now
    // override void EOnFrame(IEntity other, float timeSlice)
    // {
    //     super.EOnFrame(other, timeSlice);

    //     // Check for the custom input action "ZombieEmitNoise"
    //     if (GetGame().GetInput().LocalPress("ZombieEmitNoise"))
    //     {
    //         Print("Key 'K' pressed for ZombieEmitNoise");
    //         EmitZombieNoise();

    //         if (p_HasFullZombieSuit)
    //         {
    //             Print("Full suit detected on key press. Emitting noise.");
    //         }
    //         else
    //         {
    //             Print("Full suit not detected on key press. No noise emitted.");
    //         }
    //     }
    // }

    // void EmitZombieNoise()
    // {
    //     Print("EmitZombieNoise called");

    //     if (GetGame().IsServer())
    //     {
    //         // Emit noise to aggro zombies
    //         vector position = GetPosition();
    //         ZombieNoiseEmitter.EmitNoise(position);
    //         Print("Server-side noise emitted for zombie aggro at position: " + position.ToString());
    //     }

    //     if (GetGame().IsClient())
    //     {
    //         // Play sound effect on the client
    //         EffectSound sound = SEffectManager.PlaySound("ZombieWhistle_SoundSet", GetPosition());
    //         if (sound)
    //         {
    //             sound.SetAutodestroy(true);
    //         }
    //         Print("Client-side sound effect played.");
    //     }
    // }

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
