class ManicSystem
{
    private PlayerBase player;
    private int manicRating;
    private ref Timer manicUpdateTimer;
    // private Widget hudRoot;
    // private TextWidget manicTextWidget;

    void ManicSystem(PlayerBase playerInstance)
    {
        player = playerInstance;
        manicRating = 0;
        manicUpdateTimer = new Timer(CALL_CATEGORY_GAMEPLAY);
        // hudRoot = GetGame().GetWorkspace().CreateWidgets("HiddenZombie/manic_rating.layout");
        // manicTextWidget = TextWidget.Cast(hudRoot.FindAnyWidget("ManicRatingText"));
        // hudRoot.SetPos(0.5, 0.5);
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
        if (player && player.CheckForFullZombieSuit())
        {
            manicRating = Math.Clamp(manicRating + 5, 0, 100);
            HandleManicEffects();
        }
        else if (manicRating > 0)
        {
            manicRating = Math.Clamp(manicRating - 2, 0, 100);
        }

        // UpdateManicUI();
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
        GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.DoCameraShake, 0, false);
    }

    void DoCameraShake()
    {
        CameraShake(2.0, 1.5, 1, 0.5);
    }

    void CauseBlurEffect()
    {
        if (player && player.GetGame() && player.GetGame().GetWorld())
        {
            player.GetGame().GetWorld().SetAperture(0.5);
            GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.ResetBlurEffect, Math.RandomIntInclusive(2000, 5000), false);
        }
    }

    void ResetBlurEffect()
    {
        if (player && player.GetGame() && player.GetGame().GetWorld())
        {
            player.GetGame().GetWorld().SetAperture(1.0);
        }
    }

    void CauseHallucinations()
    {
        vector position = player.GetPosition();
        vector offset = Vector(Math.RandomFloatInclusive(-5, 5), 0, Math.RandomFloatInclusive(-5, 5));
        GetGame().CreateObject("SurvivorM_Mirek", position + offset, false, true);
    }

    void TriggerDeath()
    {
        player.SetHealth(0);
    }

    // void UpdateManicUI()
    // {
    //     if (player && manicTextWidget)
    //     {
    //         string message = string.Format("Manic Rating: %1", manicRating);
    //         manicTextWidget.SetText(message);
    //     }
    // }
}
