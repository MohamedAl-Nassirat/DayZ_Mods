class CraftZombieJacketRecipe extends RecipeBase
{
    override void Init()
    {
        m_Name = "Craft Zombie Jacket";
        m_IsInstaRecipe = false;
        m_AnimationLength = 2.5;
        m_Specialty = 0.05;


		//conditions
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = -1;//-1 = disable check
		
		m_MinQuantityIngredient[0] = -1;//-1 = disable check
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check
		
		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = -1;//-1 = disable check
		
		m_MinQuantityIngredient[1] = -1;//-1 = disable check
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check



        // Ingredient 1: Zombie Pelts
        InsertIngredient(0, "ZombiePelt");
        m_MinQuantityIngredient[0] = 5; // Minimum of 5 pelts required
        m_MaxQuantityIngredient[0] = 5; // Maximum of 5 pelts allowed
        m_IngredientAddHealth[0] = -10; // Decrease health by 10
        m_IngredientAddQuantity[0] = -5; // Use up 5 pelts
        m_IngredientDestroy[0] = false; // Do not destroy the ingredient
        m_IngredientUseSoftSkills[0] = false; // Do not use soft skills

        // Ingredient 2: Leather Sewing Kit
        InsertIngredient(1, "LeatherSewingKit");
        m_MinQuantityIngredient[1] = 1; // At least 1 kit required
        m_MaxQuantityIngredient[1] = -1; // No maximum limit
        m_IngredientAddHealth[1] = -10; // Decrease health by 10
        m_IngredientAddQuantity[1] = 0; // Do not change quantity
        m_IngredientDestroy[1] = false; // Do not destroy the ingredient
        m_IngredientUseSoftSkills[1] = false; // Do not use soft skills

        // Result: Zombie Jacket
        AddResult("ZombieJacket");
        m_ResultSetFullQuantity[0] = false; // Do not set full quantity
        m_ResultSetQuantity[0] = -1; // Do not set specific quantity
        m_ResultSetHealth[0] = 100; // Set health to 100
        m_ResultInheritsHealth[0] = -1; // Do not inherit health
        m_ResultInheritsColor[0] = -1; // Do not inherit color
        m_ResultToInventory[0] = -2; // Place in player's inventory
        m_ResultUseSoftSkills[0] = false; // Do not use soft skills
        m_ResultReplacesIngredient[0] = -1; // Do not replace ingredient
    }
};
