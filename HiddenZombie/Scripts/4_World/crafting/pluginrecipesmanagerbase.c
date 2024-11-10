modded class PluginRecipesManager 
{
	override void RegisterRecipies()
    {
        super.RegisterRecipies();				
        RegisterRecipe(new CraftZombieHoodRecipe);
        RegisterRecipe(new CraftZombieJacketRecipe);
    }
}