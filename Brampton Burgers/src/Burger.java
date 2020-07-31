import java.util.ArrayList;

public class Burger
{
    private String burgerName;
    private Double burgerCost;
    private Integer maxNumberOfToppings;
    private String burgerRoll;
    private String burgerMeat;



    public Burger(String burgerName, Double burgerCost,String burgerRoll,Integer maxNumberOfToppings,String burgerMeat)
    {
        this.burgerName = burgerName;
        this.burgerCost = burgerCost;
        this.burgerRoll = burgerRoll;
        this.burgerMeat = burgerMeat;
        this.maxNumberOfToppings = maxNumberOfToppings;
    }

    private ArrayList<Toppings> toppings = new ArrayList<>();


    public String getBurgerName()
    {
        return this.burgerName;
    }

    public void setBurgerName(String burgerName)
    {
        this.burgerName = burgerName;
    }

    public double getBurgerCost()
    {
        return this.burgerCost;
    }

    public void setBurgerCost(Double burgerCost)
    {
        this.burgerCost = burgerCost;
    }

    public String getRoll()
    {
        return burgerRoll;
    }

    public void setBurgerRoll(String burgerRoll)
    {
        this.burgerRoll = burgerRoll;
    }

    public void setBurgerMeat(String burgerMeat)
    {
        this.burgerMeat = burgerMeat;
    }

    public String getBurgerMeat()
    {
        return burgerMeat;
    }

    public void setMaxNumberOfToppings(Integer maxNumberOfToppings)
    {
        this.maxNumberOfToppings = maxNumberOfToppings;
    }

    public void setToppings(Toppings topping)
    {
        this.toppings.add(topping);
    }

    @Override
    public String toString()
    {
        return this.burgerName + " with " + this.burgerMeat + "with" + this.burgerRoll + "\n\t Cost: $" + String.format("%.2f",burgerCost)
                + "\n\t Maximum number of Toppings: " + this.maxNumberOfToppings;
    }

}







