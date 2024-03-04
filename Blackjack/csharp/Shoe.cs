using System;
using System.Collections.Generic;
using System.Linq;


public class Shoe
{
    private List<Card> contents;  // contents of the shoe
    private int top;              // the top card of the shoe

    // create a shoe of n decks
    public Shoe(int n) {
        char[] cardSuits = {'S', 'C', 'D', 'H'};
        string[] cardFaces = {"A", "2", "3", "4", "5",
                              "6", "7", "8", "9", "10", 
                              "J", "Q", "K"};

        // initialize the contents
        contents = new List<Card>();

        // put the decsk in in order
        for(int i=0; i<n; i++) {
            foreach(char suit in cardSuits) {
                foreach(string face in cardFaces) {
                    contents.Add(new Card(face, suit));
                }
            }
        }

        // shuffle them
        contents = contents.OrderBy(x=> Random.Shared.Next()).ToList();

        // start with the first card
        top = 0;
    }


    // take the top card from the shoe.
    public Card deal() {
        return contents[top++];
    }
    

    // count the remaining cards in the shoe
    public int getRemaining() {
        return contents.Count - top;
    }
}
