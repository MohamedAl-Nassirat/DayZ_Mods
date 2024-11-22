class ManicSystem
{
    private PlayerBase player;
    private int manicRating;
    private ref Timer manicUpdateTimer;

    void ManicSystem(PlayerBase playerInstance)
    {
        player = playerInstance;
        manicRating = 0;
        manicUpdateTimer = new Timer(CALL_CATEGORY_GAMEPLAY);

        if (GetGame().IsServer())
        {
            Start();
        }
    }

    void Start()
    {
        if (!manicUpdateTimer.IsRunning())
        {
            manicUpdateTimer.Run(10, this, "UpdateManicRating", null, true);
        }
    }

    void Stop()
    {
        manicUpdateTimer.Stop();
    }

    void UpdateManicRating()
    {
        if (!player) return;

        if (player.CheckForFullZombieSuit())
        {
            manicRating = Math.Clamp(manicRating + 5, 0, 100);
            HandleManicEffects();
        }
        else if (manicRating > 0)
        {
            manicRating = Math.Clamp(manicRating - 2, 0, 100);
        }

        SendManicRatingToClient();
    }

    void HandleManicEffects()
    {
        if (manicRating > 25 && manicRating <= 50)
        {
            Print("Mild tremors occurring!");
            CauseTremor();
        }
        else if (manicRating > 50 && manicRating <= 75)
        {
            Print("Vision blurring often!");
            CauseBlurEffect();
        }
        else if (manicRating > 75 && manicRating < 100)
        {
            Print("Hallucinations happening!");
            CauseHallucinations();
        }
        else if (manicRating >= 100)
        {
            Print("Player has reached maximum manic rating! Death triggered.");
            TriggerDeath();
        }
    }

    void CauseTremor()
    {
        if (GetGame().IsClient())
        {
            GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.DoCameraShake, 0, false);
        }
    }

    void DoCameraShake()
    {
        CameraShake(2.0, 1.5, 1, 0.5);
    }

    void CauseBlurEffect()
    {
        if (GetGame().IsClient() && GetGame().GetWorld())
        {
            GetGame().GetWorld().SetAperture(0.5);
            GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.ResetBlurEffect, Math.RandomIntInclusive(2000, 5000), false);
        }
    }

    void ResetBlurEffect()
    {
        if (GetGame().IsClient() && GetGame().GetWorld())
        {
            GetGame().GetWorld().SetAperture(1.0);
        }
    }

    void CauseHallucinations()
    {
        if (GetGame().IsClient())
        {
            vector position = player.GetPosition();
            vector offset = Vector(Math.RandomFloatInclusive(-5, 5), 0, Math.RandomFloatInclusive(-5, 5));
            GetGame().CreateObject("SurvivorM_Mirek", position + offset, false, true);
        }
    }

    void TriggerDeath()
    {
        if (GetGame().IsServer())
        {
            player.SetHealth(0);
        }
    }

    void SendManicRatingToClient()
    {
        if (GetGame().IsServer() && player)
        {
            auto params = new Param1<int>(manicRating);
            GetRPCManager().SendRPC("HiddenZombie", "UpdateManicUI", params, true, player.GetIdentity());
        }
    }
}
