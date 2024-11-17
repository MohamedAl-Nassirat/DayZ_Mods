class HordeLeader
{
    private PlayerBase player;
    private bool isActive;
    private ref Timer noiseEmissionTimer;

    void HordeLeader(PlayerBase playerInstance)
    {
        player = playerInstance;
        isActive = false;
        noiseEmissionTimer = new Timer(CALL_CATEGORY_GAMEPLAY);
    }

    // Activate horde leading if the player has the full zombie suit
    void Activate()
    {
        if (!isActive)
        {
            isActive = true;
            StartNoiseEmission();
        }
    }

    // Deactivate horde leading
    void Deactivate()
    {
        if (isActive)
        {
            isActive = false;
            StopNoiseEmission();
        }
    }

    // Start the timer to emit noise periodically
    private void StartNoiseEmission()
    {
        noiseEmissionTimer.Run(5, this, "EmitZombieNoise", null, true); // Emit noise every 5 seconds (adjust as needed)
    }

    // Stop emitting noise
    private void StopNoiseEmission()
    {
        noiseEmissionTimer.Stop();
    }

    // Emit zombie noise at the player's position
    void EmitZombieNoise()
    {
        if (!isActive) return;

        vector position = player.GetPosition();
        
        if (GetGame().IsServer())
        {
            // Emit noise to aggro zombies on the server
            ZombieNoiseEmitter.EmitNoise(position);
            Print("Server-side noise emitted for zombie aggro at position: " + position.ToString());
        }

        if (GetGame().IsClient())
        {
            // Play sound effect on the client
            EffectSound sound = SEffectManager.PlaySound("ZombieWhistle_SoundSet", position);
            if (sound)
            {
                sound.SetAutodestroy(true);
            }
            Print("Client-side sound effect played.");
        }
    }
}
