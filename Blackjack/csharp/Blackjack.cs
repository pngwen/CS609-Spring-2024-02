// A class of static methods to support the blackjack application
public class Blackjack
{
    public static void playHand(Wallet wallet, Shoe shoe) {
        double bet = getBet(wallet);
        bool done = false;
        Hand player = new Hand(shoe.deal(), shoe.deal());
        Hand dealer = new Hand(shoe.deal(), shoe.deal());

        // The player can see their own cards
        player.setRevealed(true);

        // Let the player build their hand.
        while(!done) {
            // print out the hands
            Console.WriteLine(String.Format("Dealer: {0}", dealer));
            Console.WriteLine(String.Format("You: {0}", player));

            // check for bust
            if(player.getPoint() >= 21) {
                done = true;
            } else if(getHit()) {
                player.hit(shoe.deal());
            } else {
                done = true;
            }
        }

        // reveal the dealer
        dealer.setRevealed(true);
        Console.WriteLine("Dealer: {0}", dealer);

        // check for bust
        if(player.getPoint() > 21) {
            Console.WriteLine("You Bust");
            wallet.addMoney(-bet);
        }  else { 
            // Let the dealer build their hand
            dealerHand(dealer, shoe);

            if(dealer.getPoint() > 21) {
                Console.WriteLine("Dealer Busts! You Win!");
            } else if(dealer.getPoint() < player.getPoint()) {
                if(player.getPoint() == 21) {
                    Console.WriteLine("You have Blackjack!");
                } 
                Console.WriteLine("You Win!");
                wallet.addMoney(bet);
            } else if(dealer.getPoint() == player.getPoint()) {
                Console.WriteLine("Push");
            } else {
                Console.WriteLine("You Lose.");
                wallet.addMoney(-bet);
            }
        }
    }


    public static void dealerHand(Hand hand, Shoe shoe) {
        Console.WriteLine(); // blank line to space things out a little

        while(hand.getPoint() < 17 || hand.getSoft() == 17) {
            Console.WriteLine("Dealer Hits");
            hand.hit(shoe.deal());
            Console.WriteLine(String.Format("Dealer: {0}", hand));
        }

        if(hand.getPoint() < 21) {
            Console.WriteLine("Dealer Stands");
        } else if(hand.getPoint() == 21) {
            Console.WriteLine("Dealer Has Blackjack!");
        }
    }


    public static double getBet(Wallet wallet) 
    {
        double bet;
        bool done = false;
        Console.WriteLine(); // blank line to space things out a little
                             
        do {
            // read the bet
            Console.Write(String.Format("You have ${0} Enter bet (Minimum $5.00): ", wallet.getMoney()));
            bet = Convert.ToDouble(Console.ReadLine());

            //validate input
            if(bet < 5 || bet > wallet.getMoney()) {
                Console.WriteLine("Invalid Bet, Please try again.");
            } else {
                done = true;
            }
        } while(!done);

        return bet;
    }

    
    public static bool getHit()
    {
        bool done = false;
        string choice;

        Console.WriteLine(); // blank line to space things out a little
        
        do {
            Console.Write("Do you want to (S)tand or (H)it? ");
            choice = Console.ReadLine();
            choice = choice.ToUpper();

            if(choice != "S" && choice != "H") {
                Console.WriteLine("Invalid Selection, please try again.");
            } else {
                done = true;
            }
        } while(!done);

        return choice == "H";
    }


    public static bool getContinue()
    {
        bool done = false;
        string choice;

        Console.WriteLine(); // blank line to space things out a little
        
        do {
            Console.Write("Do you want to play again (Y/N)? ");
            choice = Console.ReadLine();
            choice = choice.ToUpper();

            if(choice != "Y" && choice != "N") {
                Console.WriteLine("Invalid Selection, please try again.");
            } else {
                done = true;
            }
        } while(!done);

        return choice == "Y";
    }
}
