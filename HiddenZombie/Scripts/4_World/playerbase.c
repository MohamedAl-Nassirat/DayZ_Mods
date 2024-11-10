modded class PlayerBase
{
    protected bool p_IsUndetectable;
    protected bool p_HasFullZombieSuit;
    protected ref Timer m_HordeLeaderTimer;

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


        p_IsUndetectable = hasPartialSuit; // Player is undetectable if they have the partial suit (Jacket + Pants + Boots)
        p_HasFullZombieSuit = hasFullSuit; // Player can lead hordes if they have the full suit (Mask + Jacket + Pants + Boots)
        

        if (p_HasFullZombieSuit)
        {
            StartHordeLeaderTimer();
        }
        else
        {
            StopHordeLeaderTimer();
        }
        // if (bodyAttachment && bodyAttachment.IsKindOf("ZombieMask"))
        // {
        //     p_IsUndetectable = true;
        //     EmitZombieNoise();
        // }
        // else
        // {
        //     p_IsUndetectable = false;
        // }
    }



    bool CheckForPartialZombieSuit()
    {
        EntityAI bodyAttachment = FindAttachmentBySlotName("Body");
        EntityAI legsAttachment = FindAttachmentBySlotName("Legs");
        EntityAI feetAttachment = FindAttachmentBySlotName("Feet");

        return bodyAttachment && bodyAttachment.IsKindOf("ZombieJacket");
        
        // NOT IMPLEMENTED YET
        // &&
            //    legsAttachment && legsAttachment.IsKindOf("ZombiePants") &&
            //    feetAttachment && feetAttachment.IsKindOf("ZombieBoots");
    }

    bool CheckForFullZombieSuit()
    {
        EntityAI bodyAttachment = FindAttachmentBySlotName("Body");
        EntityAI legsAttachment = FindAttachmentBySlotName("Legs");
        EntityAI feetAttachment = FindAttachmentBySlotName("Feet");
        EntityAI headAttachment = FindAttachmentBySlotName("Head");

        return headAttachment && headAttachment.IsKindOf("ZombieMask");

        // bodyAttachment && bodyAttachment.IsKindOf("ZombieJacket") &&
        //        legsAttachment && legsAttachment.IsKindOf("ZombiePants") &&
        //        feetAttachment && feetAttachment.IsKindOf("ZombieBoots") &&
    }


    void StartHordeLeaderTimer()
    {
        if (!m_HordeLeaderTimer)
        {
            m_HordeLeaderTimer = new Timer(CALL_CATEGORY_GAMEPLAY);
        }

        if (!m_HordeLeaderTimer.IsRunning())
        {
            // Start the timer with a 15-30 second interval
            m_HordeLeaderTimer.Run(Math.RandomFloatInclusive(15, 30), this, "EmitZombieNoise", null, true);
        }
    }


    void StopHordeLeaderTimer()
    {
        if (m_HordeLeaderTimer && m_HordeLeaderTimer.IsRunning())
        {
            m_HordeLeaderTimer.Stop();
        }
    }











    void EmitZombieNoise()
    {
        // Emit noise only if the player has the full zombie suit (including the mask)
        if (p_HasFullZombieSuit)
        {
            vector position = GetPosition();
            ZombieNoiseEmitter.EmitNoise(position);
        }



        // if (GetGame().IsClient())
        // {
        //     // Play the sound effect on the client
        //     EffectSound sound = SEffectManager.PlaySound("ZombieWhistle_SoundSet", GetPosition());
        //     if (sound)
        //     {
        //         sound.SetAutodestroy(true);
        //     }
        // }
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
}
