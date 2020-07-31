public class Toppings
{
    private String name;
    private Double cost;


    public Toppings(String name,Double cost )
    {
        this.name = name;
        this.cost = cost;
    }


    public String getName()
    {
        return this.name;
    }

    public Double getCost()
    {
        return this.cost;
    }

    @Override
    public String toString()
    {
        return this.name + " : $" + String.format("%.2f",this.cost) + "\n";
    }


}
