import java.util.ArrayList;

public class BramptonMenu
{
    private Burger selectedBurger;
    private ArrayList<Toppings> selectedToppings = new ArrayList<>();
    private ArrayList<Burger> allBurgers = new ArrayList<>();


    public Restaurant()
    {
        Burger basicBurger = new BasicBurger();
        Burger healthyBurger = new HealthyBurger();
        Burger deluxeBurger = new DeluxeBurger();

        Toppings tomato = new Toppings("Tomato",0.27);

    }





    public void DisplayMenu()
    {



    }


}
