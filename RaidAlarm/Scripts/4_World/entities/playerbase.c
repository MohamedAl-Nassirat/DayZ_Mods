modded class PlayerBase
{
    const float DETECTION_RADIUS = 1.0;
    bool isButtonActivated = false; 

    override void OnScheduledTick(float deltaTime)
    {
        super.OnScheduledTick(deltaTime);

        if (isButtonActivated)
        {
            array<Object> nearbyObjects = new array<Object>;
            GetGame().GetObjectsAtPosition(this.GetPosition(), DETECTION_RADIUS, nearbyObjects, null);
            foreach (Object obj : nearbyObjects)
            {
                EntityAI item = EntityAI.Cast(obj);
                if (item && item.GetType() == "BookMobyDick")
                {
                    PlayAlarmSound();
                    break;
                }
            }
        }
    }

    void PlayAlarmSound()
    {
        vector position = this.GetPosition();
        EffectSound sound = SEffectManager.PlaySound("Alarm_SoundSet", position, 0, 0, false);
        sound.SetSoundAutodestroy(true);
    }
}

modded class PersonalRadio extends ItemRadio
{
    override void OnSwitchOn()
    {
        super.OnSwitchOn();
        PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
        if (player)
        {
            player.isButtonActivated = true;
            Print("[PersonalRadio] Radio turned on, button activated");
        }
    }

    override void OnSwitchOff()
    {
        super.OnSwitchOff();
        PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
        if (player){
            player.isButtonActivated = false;
            Print("[PersonalRadio] Radio turned off, button deactivated");
        }
    }
}
