class CfgPatches
{
    class RaidAlarm
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data"};
    };
};

class CfgMods
{
    class RaidAlarm
    {
        dir = "RaidAlarm";
        picture = "";
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "RaidAlarm";
        credits = "";
        author = "MoMoney";
        authorID = "0";
        version = "1.0";
        extra = 0;
        type = "mod";
        dependencies[] = {"Game", "World"};
        class defs
        {
            class gameScriptModule
            {
                value = "";
                files[] = {"RaidAlarm/scripts/3_Game"};
            };
            class worldScriptModule
            {
                value = "";
                files[] = {"RaidAlarm/scripts/4_World"};
            };
        };
    };
};


class CfgSoundShaders
{
    class Alarm_SoundShader
    {
        samples[] = {{"\RaidAlarm\Sounds\sound.ogg", 1}};
        volume = 1.0;
        range = 50;
    };
};

class CfgSoundSets
{
    class Alarm_SoundSet
    {
        soundShaders[] = {"Alarm_SoundShader"};
        volumeFactor = 1.0;
        spatial = 1;
        doppler = 0;
        loop = 0;
    };
};
