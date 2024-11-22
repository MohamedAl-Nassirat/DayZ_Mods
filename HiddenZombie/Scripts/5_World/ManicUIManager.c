class ManicUIManager
{
    private Widget hudRoot;
    private TextWidget manicTextWidget;

    void ManicUIManager()
    {
        hudRoot = GetGame().GetWorkspace().CreateWidgets("HiddenZombie/manic_rating.layout");
        if (hudRoot)
        {
            manicTextWidget = TextWidget.Cast(hudRoot.FindAnyWidget("ManicRatingText"));
            hudRoot.Show(false); 
        }
        else
        {
            Print("Error: Failed to load manic_rating.layout.");
        }
    }

    void ShowUI(bool state)
    {
        if (hudRoot)
            hudRoot.Show(state);
    }

    void UpdateManicRatingUI(int manicRating)
    {
        if (manicTextWidget)
        {
            string message = string.Format("Manic Rating: %1", manicRating);
            manicTextWidget.SetText(message);
        }
    }
}
