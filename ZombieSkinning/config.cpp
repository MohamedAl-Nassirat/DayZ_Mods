class CfgPatches
{
    class ZombieSkinning
    {
        units[] = {"ZombieSkinJacket"};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data"};
    };
};

class CfgVehicles
{
    class Clothing;
    class ZombieSkinJacket: Clothing
    {
        scope = 2;
        displayName = "Zombie Skin Jacket";
        descriptionShort = "A jacket made from zombie skin.";
        model = "\dz\characters\tops\m65_jacket_g.p3d"; // Temporary model
        inventorySlot[] = {"Body"};
        itemInfo[] = {"Clothing", "Body"};
        weight = 2000;
        itemSize[] = {3,3};
        heatIsolation = 0.5;
        repairableWithKits[] = {5,3};
        repairCosts[] = {30,25};
        hiddenSelections[] = {"camoGround", "camoMale", "camoFemale"};
        hiddenSelectionsTextures[] =
        {
            "\dz\characters\tops\data\m65_jacket_black_co.paa",  // camoGround
            "\dz\characters\tops\data\m65_jacket_black_co.paa",  // camoMale
            "\dz\characters\tops\data\m65_jacket_black_co.paa"   // camoFemale
        };
        //hiddenSelectionsTextures[] = {"\YourMod\data\zombie_skin_co.paa"};
    };
};
