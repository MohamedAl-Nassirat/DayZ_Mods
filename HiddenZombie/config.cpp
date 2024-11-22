class CfgPatches
{
    class HiddenZombie
    {
        units[] = {"ZombieJacket", "ZombieMask", "ZombiePelt", "ZombiePants"};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data", "DZ_Characters", "DZ_Scripts"};
    };
};

class CfgMods
{
    class HiddenZombie
    {
        dir = "HiddenZombie";
        picture = ""; // Optional: path to an icon image
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "Zombie Undetectable Jacket Mod";
        credits = "";
        author = "";
        authorID = ""; // Optional: Steam or BI ID
        version = "1.0";
        extra = 0;
        type = "mod";
        
        dependencies[] = {"World"};
        inputs = "HiddenZombie/inputs.xml";


        class defs
        {
            class gameScriptModule
            {
                value = "";
                files[] = {"HiddenZombie/scripts/3_Game"};
            };
            class worldScriptModule
            {
                value = "";
                files[] = {"HiddenZombie/scripts/4_World"};
            };
            class missionScriptModule
            {
                value = "";
                files[] = {"HiddenZombie/scripts/5_Mission"};
            };
        };

        
    };
};

class CfgSoundShaders
{
    class ZombieWhistle_SoundShader
    {
        samples[] = {{"\HiddenZombie\Data\sounds\sound.ogg", 1}};
        volume = 1.0;
        range = 50; // Range for the sound
    };
};

class CfgSoundSets
{
    class ZombieWhistle_SoundSet
    {
        soundShaders[] = {"ZombieWhistle_SoundShader"};
        volumeFactor = 1.0;
        spatial = 1;
        doppler = 0;
        loop = 0;
    };
};



class CfgVehicles
{

    #include "Config\zombieSkinningConfig.c"

    class SurvivorBase; 
    class ZombieNoise
    {
        strength = 200;
        type = "shot";
    };
    
    class Shemag_ColorBase;
    class LeatherJacket_ColorBase;
    class Pelt_Base;
    class LeatherPants_ColorBase;

    // Define the custom Zombie Dress
    class ZombieJacket: LeatherJacket_ColorBase
    {
        scope = 2;
        displayName = "Zombie Jacket";
        descriptionShort = "A jacket born from the flesh of zombies.";
        model = "\DZ\characters\tops\top_leatherjacket_g.p3d"; // Path to the original model
        hiddenSelections[] = {"camoGround", "camoMale", "camoFemale"};
        hiddenSelectionsTextures[] = {
            "\HiddenZombie\Data\zombieJacket\draft_zombiejacket_g_co.paa",
            "\HiddenZombie\Data\zombieJacket\draft_zombiejacket_g_co.paa",
            "\HiddenZombie\Data\zombieJacket\draft_zombiejacket_g_co.paa"};
        inventorySlot[] = {"Body"};
        itemInfo[] = {"Clothing", "Body"};
        weight = 1000;
        itemSize[] = {3, 3};
        heatIsolation = 1;
        repairableWithKits[] = {5, 3};
        repairCosts[] = {30, 25};
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                };
            };
        };


    };
\
    // // Define the custom Zombie Mask
    // class ZombieMask: Shemag_ColorBase
    // {
    //     scope = 2;
    //     displayName = "Zombie Mask";
    //     descriptionShort = "A mask worn by zombies.";
    //     model = "\DZ\characters\headgear\ShemagHybrid_g.p3d";
    //     hiddenSelections[] = {"camoGround", "camoMale_H", "camoMale_M", "camoFemale_H", "camoFemale_M"};
    //     hiddenSelectionsTextures[] = {
    //         "\HiddenZombie\data\zombieScarf\zombie_mask.paa", // Ground texture
    //         "\HiddenZombie\data\zombieScarf\zombie_mask.paa", // Male head texture
    //         "\HiddenZombie\data\zombieScarf\zombie_mask.paa", // Male mask texture
    //         "\HiddenZombie\data\zombieScarf\zombie_mask.paa", // Female head texture
    //         "\HiddenZombie\data\zombieScarf\zombie_mask.paa"  // Female mask texture
    //     };
    //     inventorySlot[] = {"Headgear"};
    //     itemInfo[] = {"Clothing", "Headgear"};
    //     weight = 200;
    //     itemSize[] = {2, 2};
    //     heatIsolation = 1;
    //     repairableWithKits[] = {5, 3};
    //     repairCosts[] = {20, 15};
    //     class DamageSystem
    //     {
    //         class GlobalHealth
    //         {
    //             class Health
    //             {
    //                 hitpoints = 100;
    //             };
    //         };
    //     };
    // };


    class Balaclava3Holes_ColorBase;

    class ZombieMask: Balaclava3Holes_ColorBase
    {
        scope = 2;
        displayName = "Zombie Skin Mask";
        descriptionShort = "";
        hiddenSelectionsTextures[] = {
            "\HiddenZombie\Data\zombieScarf\Zombie_skinmask_co.paa", 
            "\HiddenZombie\Data\zombieScarf\Zombie_skinmask_co.paa", 
            "\HiddenZombie\Data\zombieScarf\Zombie_skinmask_co.paa"
        };
        hiddenSelectionsMaterials[] = {
            "\HiddenZombie\Data\zombieScarf\Zombie_3holes.rvmat", 
            "\HiddenZombie\Data\zombieScarf\Zombie_3holes.rvmat", 
            "\HiddenZombie\Data\zombieScarf\Zombie_3holes.rvmat"
        };
        inventorySlot[] = {"Headgear"};
        itemInfo[] = {"Clothing", "Headgear"};
        weight = 200;
        itemSize[] = {2, 2};
        heatIsolation = 1;
        repairableWithKits[] = {5, 3};
        repairCosts[] = {20, 15};
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                };
            };
        };
    };

    class ZombiePelt: Pelt_Base
    {
        scope = 2;
        displayName = "Zombie Pelt";
        descriptionShort = "A piece of pelt from a zombie.";
        model = "\DZ\gear\consumables\pelt_pig.p3d"; // Path to your pelt model
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\HiddenZombie\Data\zombieLeather\zombie_pelt.paa"};
        canBeSplit= 1;
        varQuantityInit= 1;
        varQuantityMin= 0;
        varQuantityMax= 10;
        varStackMax= 10;
        weight = 500;
        itemSize[] = {2, 2};
    };


    class ZombiePants: LeatherPants_ColorBase
    {
        scope = 2;
        displayName = "Zombie Pants";
        descriptionShort = "Pants crafted from the flesh of zombies.";
        model = "\DZ\characters\pants\pants_leatherpants_g.p3d"; // Path to the default leather pants model
        hiddenSelections[] = {"camoGround", "camoMale", "camoFemale"};
        hiddenSelectionsTextures[] = {
            "\HiddenZombie\Data\zombiePants\draft_zombiepants_co.paa", // Ground texture
            "\HiddenZombie\Data\zombiePants\draft_zombiepants_co.paa", // Male texture
            "\HiddenZombie\Data\zombiePants\draft_zombiepants_co.paa"  // Female texture
        };
        inventorySlot[] = {"Legs"};
        itemInfo[] = {"Clothing", "Legs"};
        weight = 800;
        itemSize[] = {3, 3};
        heatIsolation = 1;
        repairableWithKits[] = {5, 3};
        repairCosts[] = {25, 20};
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                };
            };
        };
    };





};



