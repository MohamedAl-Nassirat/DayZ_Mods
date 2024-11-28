class CfgPatches
{
    class InventoryAutoSort
    {
        requiredAddons[] = {"DZ_Data", "DZ_Scripts"};
    };
};

class CfgMods
{
    class InventoryAutoSort
    {
        dir = "InventoryAutoSort";
        picture = "";
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "Inventory Auto Sort";
        credits = "FG MoMoney";
        author = "BasicallyVanilla";
        authorID = "0";
        version = "1.0";
        extra = 0;
        type = "mod";
        dependencies[] = {"Game", "World", "Mission"};
        
        class defs
        {
            class gameScriptModule
			{
				value = "";
				files[] = {"InventoryAutoSort/scripts/4_World"};
			};
            class worldScriptModule
            {
                value = "";
                files[] = {"InventoryAutoSort/scripts/4_World"};
            };
            class missionScriptModule
            {
                value = "";
                files[] = {"InventoryAutoSort/scripts/5_Mission"};
            };
        };
    };
};
