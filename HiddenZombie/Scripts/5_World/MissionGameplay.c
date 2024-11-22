modded class MissionGameplay
{
    private ref ManicUIManager manicUIManager;

    override void OnInit()
    {
        super.OnInit();
        manicUIManager = new ManicUIManager();
        GetRPCManager().AddRPC("HiddenZombie", "UpdateManicUI", this, SingeplayerExecutionType.Client);
    }

    void UpdateManicUI(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        Param1<int> data;
        if (!ctx.Read(data)) return;

        int manicRating = data.param1;

        if (manicUIManager)
        {
            manicUIManager.ShowUI(true);
            manicUIManager.UpdateManicRatingUI(manicRating);
        }
    }
}
