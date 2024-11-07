class ActionSkinZombieCB : ActionContinuousBaseCB
{
    override void CreateActionComponent()
    {
        m_ActionData.m_ActionComponent = new CAContinuousTime(4); // Duration of the action
        Print("[SKINNING_FEATURE] Action component created with duration 4 seconds.");
    }
}

class ActionSkinZombie : ActionContinuousBase
{
    void ActionSkinZombie()
    {
        m_CallbackClass = ActionSkinZombieCB;
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ANIMALSKINNING;
        m_FullBody = true;
        m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
        Print("[SKINNING_FEATURE] ActionSkinZombie initialized with skinning command UID.");
    }

    override void CreateConditionComponents()
    {
        m_ConditionItem = new CCINonRuined();
        m_ConditionTarget = new CCTDeadZombie(UAMaxDistances.DEFAULT);
        Print("[SKINNING_FEATURE] Condition components for ActionSkinZombie created.");
    }

    override string GetText()
    {
        return "Skin Zombie";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        Object targetObject = target.GetObject();
        ZombieBase targetZombie;

        if (targetObject && Class.CastTo(targetZombie, targetObject))
        {
            if (!targetZombie.m_skinned && !targetZombie.IsAlive())
            {
                Print("[SKINNING_FEATURE] Action condition met: Target is a dead zombie that has not been skinned.");
                return true;
            }
            Print("[SKINNING_FEATURE] Action condition failed: Zombie is either skinned or alive.");
        }
        else
        {
            Print("[SKINNING_FEATURE] Action condition failed: Target is not a zombie.");
        }
        return false;
    }

    override void OnFinishProgressServer(ActionData action_data)
    {
        Object targetObject = action_data.m_Target.GetObject();
        ZombieBase targetZombie;

        if (targetObject && Class.CastTo(targetZombie, targetObject))
        {
            targetZombie.SetAsSkinned();
            Print("[SKINNING_FEATURE] Zombie set as skinned.");

            EntityAI item = action_data.m_Player.GetInventory().CreateInInventory("ZombieSkinJacket");
            if (!item)
            {
                item = action_data.m_Player.SpawnEntityOnGroundPos("ZombieSkinJacket", action_data.m_Player.GetPosition());
                Print("[SKINNING_FEATURE] ZombieSkinJacket spawned on the ground.");
            }
            else
            {
                Print("[SKINNING_FEATURE] ZombieSkinJacket added to player inventory.");
            }

            action_data.m_MainItem.DecreaseHealth(UADamageApplied.SKINNING, false);
            PluginLifespan module_lifespan = PluginLifespan.Cast(GetPlugin(PluginLifespan));
            module_lifespan.UpdateBloodyHandsVisibility(action_data.m_Player, true);
            action_data.m_Player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);
            Print("[SKINNING_FEATURE] Skinning action completed on server.");
        }
        else
        {
            Print("[SKINNING_FEATURE] OnFinishProgressServer: Target is not a zombie or invalid.");
        }
    }
}

// Extend the ZombieBase class to include skinning functionality
modded class ZombieBase
{
    bool m_skinned = false;

    void SetAsSkinned()
    {
        m_skinned = true;
        // Optionally, you can change the zombie's appearance to reflect that it has been skinned.
        // For example, you can replace the zombie's model with a skinned version.
    }
}
