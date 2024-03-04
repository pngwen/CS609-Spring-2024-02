public class Card
{
    private char suit;
    private string value;

    // Construct a card with a given suit and value
    public Card(string value, char suit) {
        this.suit = suit;
        this.value = value;
    }


    // Retrieve the value
    public string getValue() {
        return value;
    }


    // Retrieve the suit
    public char getSuit() {
        return suit;
    }


    // Convert the card to a string for easy printing
    public override string ToString() {
        return String.Format("{0,2}{1}", getValue(), getSuit());
    }
}
