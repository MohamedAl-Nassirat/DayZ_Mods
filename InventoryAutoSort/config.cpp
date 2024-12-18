#define _ARMA_

class CfgPatches
{
	class InventoryAutoSort
	{
		requiredAddons[] = {"DZ_Data","DZ_Animals","DZ_Characters","DZ_AI","DZ_Scripts"};
	};
};


class CfgMods
{
	class InventoryAutoSort
	{
		dir = "InventoryAutoSort";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 1;
		name = "InventoryAutoSort";
		credits = "";
		author = "";
		authorID = "0";
		version = "0.1";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"InventoryAutoSort/scripts/3_Game"};
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
