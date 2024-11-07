modded class MissionServer
{
    override void OnInit()
    {
        super.OnInit();
        ActionManagerServer am = GetDayZGame().GetMission().GetActionManager();
        am.RegisterAction(ActionSkinZombie);
        Print("[ZombieSkinning] ActionSkinZombie registered in MissionServer.");
    }
}