class ZombieNoiseEmitter
{
    static void EmitNoise(vector position)
    {
        Print("ZombieNoiseEmitter.ForceEmitNoise called at position: " + position.ToString());

        if (GetGame().IsServer())
        {
            NoiseParams noiseParams = new NoiseParams();
            noiseParams.LoadFromPath("CfgVehicles ZombieNoise");

            NoiseSystem noiseSystem = GetGame().GetNoiseSystem();
            if (noiseSystem)
            {
                Print("NoiseSystem available. Adding fresh noise target for zombie aggro.");
                // Force noise emission with updated strength and duration to ensure zombie recognition
                noiseSystem.AddNoiseTarget(position, 10.0, noiseParams, 2.0);
                Print("Aggro noise target added at position: " + position.ToString() + " with strength 10.0 and duration 2.0.");
            }
            else
            {
                Print("NoiseSystem not available on server.");
            }
        }
        else
        {
            Print("ForceEmitNoise called on client - no noise emitted for zombies.");
        }
    }
}