class CfgPatches
{
    class HiddenZombie
    {
        units[] = {"ZombieJacket", "ZombieMask"};
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
    
    class BalaclavaMask_ColorBase;
    class LeatherJacket_ColorBase;

    // Define the custom Zombie Dress
    class ZombieJacket: LeatherJacket_ColorBase
    {
        scope = 2;
        displayName = "Zombie Jacket";
        descriptionShort = "A jacket born from the flesh of zombies.";
        model = "\DZ\characters\tops\top_leatherjacket_g.p3d"; // Path to the original model
        hiddenSelections[] = {"camoGround", "camoMale", "camoFemale"};
        hiddenSelectionsTextures[] = {"\HiddenZombie\Data\top_zombiejacket_co.paa", "\HiddenZombie\Data\top_zombiejacket_co.paa", "\HiddenZombie\Data\top_zombiejacket_co.paa"};
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


    // Define the custom Zombie Mask
    class ZombieMask: BalaclavaMask_ColorBase
    {
        scope = 2;
        displayName = "Zombie Mask";
        descriptionShort = "A mask worn by zombies.";
        model = "\DZ\characters\masks\balaclava_g.p3d"; // Path to the original model
        hiddenSelections[] = {"camoGround", "camoMale", "camoFemale"};
        hiddenSelectionsTextures[] = {"\HiddenZombie\data\zombie_mask.paa", "\HiddenZombie\data\zombie_mask.paa", "\HiddenZombie\data\zombie_mask.paa"};
        inventorySlot[] = {"Mask"};
        itemInfo[] = {"Clothing", "Mask"};
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

        class ClothingTypes
        {
            male = "\DZ\characters\masks\balaclava_m.p3d";
            female = "\DZ\characters\masks\balaclava_f.p3d";
        };

    };

    class Skinning
    {
        class ObtainedSteaks
        {
            item = "ZombieJacket";
            count = 1;
            transferToolDamageCoef = 1;
        };
        class ObtainedPelt
        {
            item = "ZombieMask";
            count = 1;
            transferToolDamageCoef = 1;
        };
    };

};