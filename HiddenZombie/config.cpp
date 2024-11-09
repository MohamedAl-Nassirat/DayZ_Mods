class CfgPatches
{
    class HiddenZombie
    {
        units[] = {"ZombieJacket", "ZombieMask", "ZombiePelt"};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data", "DZ_Characters"};
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

        class defs
        {
            class worldScriptModule
            {
                value = "";
                files[] = {"HiddenZombie/scripts/4_World"};
            };
        };
    };
};



class CfgVehicles
{

    #include "Config\zombieSkinningConfig.c"
    
    class Shemag_ColorBase;
    class LeatherJacket_ColorBase;
    class Pelt_Base;

    // Define the custom Zombie Dress
    class ZombieJacket: LeatherJacket_ColorBase
    {
        scope = 2;
        displayName = "Zombie Jacket";
        descriptionShort = "A jacket born from the flesh of zombies.";
        model = "\DZ\characters\tops\top_leatherjacket_g.p3d"; // Path to the original model
        hiddenSelections[] = {"camoGround", "camoMale", "camoFemale"};
        hiddenSelectionsTextures[] = {"\HiddenZombie\Data\zombieJacket\top_zombiejacket_co.paa", "\HiddenZombie\Data\zombieJacket\top_zombiejacket_co.paa", "\HiddenZombie\Data\zombieJacket\top_zombiejacket_co.paa"};
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
    // Define the custom Zombie Mask
    class ZombieMask: Shemag_ColorBase
    {
        scope = 2;
        displayName = "Zombie Mask";
        descriptionShort = "A mask worn by zombies.";
        model = "\DZ\characters\headgear\ShemagHybrid_g.p3d";
        hiddenSelections[] = {"camoGround", "camoMale_H", "camoMale_M", "camoFemale_H", "camoFemale_M"};
        hiddenSelectionsTextures[] = {
            "\HiddenZombie\data\zombieScarf\zombie_mask.paa", // Ground texture
            "\HiddenZombie\data\zombieScarf\zombie_mask.paa", // Male head texture
            "\HiddenZombie\data\zombieScarf\zombie_mask.paa", // Male mask texture
            "\HiddenZombie\data\zombieScarf\zombie_mask.paa", // Female head texture
            "\HiddenZombie\data\zombieScarf\zombie_mask.paa"  // Female mask texture
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
        weight = 500;
        itemSize[] = {2, 2};
    };






};