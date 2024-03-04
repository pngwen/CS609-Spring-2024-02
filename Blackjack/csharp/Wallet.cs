// This is really a wrapper around our money so we can pass it by 
// reference (since C# lacks that direct ability)
public class Wallet
{
    private double money;

    // create a player with the given amount of money
    public Wallet(double money) {
        this.money = money;
    }


    // access the money
    public double getMoney() {
        return money;
    }


    // change the money
    public void addMoney(double increment) {
        setMoney(getMoney() + increment);
    }


    // set the money amount
    public void setMoney(double money) {
        this.money = money;
    }
}
