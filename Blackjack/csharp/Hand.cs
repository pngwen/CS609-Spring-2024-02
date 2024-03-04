using System;
using System.Collections.Generic;

public class Hand
{
    private List<Card> cards;
    private int hard;
    private int soft;
    private bool revealed;

    // construct the hand using two cards
    public Hand(Card down, Card up) {
        // create the cards list
        cards = new List<Card>();

        // initialize the scores
        hard = 0;
        soft = 0;
        revealed = false;

        // add the cards
        hit(down);
        hit(up);
    }


    // Accessor for revealed status
    public bool getRevealed() {
        return revealed;
    }


    // Mutator for revealed status
    public void setRevealed(bool revealed) {
        this.revealed = revealed;
    }


    // Acessor for the best point value
    public int getPoint() {
        if(soft != 0) {
            return soft;
        }

        return hard;
    }


    // get the hard value (with aces 1)
    public int getHard() {
        return hard;
    }


    // get soft value (zero if soft busts or no ace) 
    public int getSoft() {
        return soft;
    }


    // receive a hit
    public void hit(Card card) {
        int value; // numeric value of the current card

        // add the card to the 
        cards.Add(card);

        // get the card's value
        switch(card.getValue()) {
            case "A":
                value = 1;
                break;
            case "J":
            case "Q":
            case "K":
                value = 10;
                break;
            default:
                value = int.Parse(card.getValue());
                break;
        }

        // add to the hard score
        hard += value;

        // handle the soft score
        if(soft != 0 || value == 1) {
            soft = hard + 10;
        }

        // reset a busted soft
        if(soft > 21) {
            soft = 0;
        }
    }


    // enumerate the cards in the hand
    public IEnumerable<Card> getCards() {
        foreach(Card card in cards) {
            yield return card;
        }
    }


    // convert the hand to a string for printing
    public override string ToString() {
        string result = "";
        bool first = true;

        foreach(Card card in getCards()) {
            if(!first || getRevealed()) {
                result += String.Format("{0} ", card);
            } else {
                result += "### ";
            }

            // toggle first off and move on
            first = false; 
        }

        if(getRevealed()) {
            result += "(";
            result += getHard();
            int soft = getSoft();
            if(soft != 0) {
                result += " / " + soft;
            }
            result += ")";
        }

        return result;
    }
}
