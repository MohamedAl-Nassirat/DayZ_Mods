class ZombieNoiseEmitter
{
    static void EmitNoise(vector position)
    {
        if (GetGame().IsServer())
        {
            NoiseParams noiseParams = new NoiseParams();
            noiseParams.LoadFromPath("CfgVehicles ZombieNoise");

            NoiseSystem noiseSystem = GetGame().GetNoiseSystem();
            noiseSystem.AddNoiseTarget(position, 10.0, noiseParams, 2.0);
        }
        else
        {
            Print("ForceEmitNoise called on client - no noise emitted for zombies.");
        }
    }
}