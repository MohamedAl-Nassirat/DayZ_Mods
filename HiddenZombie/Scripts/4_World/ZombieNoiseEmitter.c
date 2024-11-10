class ZombieNoiseEmitter
{
    static void EmitNoise(vector position)
    {
        if (GetGame().IsServer())
        {
            NoiseParams noiseParams = new NoiseParams();
            noiseParams.LoadFromPath("CfgVehicles ZombieNoise");

            NoiseSystem noiseSystem = GetGame().GetNoiseSystem();
            if (noiseSystem)
            {
                noiseSystem.AddNoiseTarget(position, 5.0, noiseParams, 1.0); // Adjust duration and strength as needed
            }
        }
    }
}