Wallet wallet = new Wallet(100.00); // start with $100.00
Shoe shoe = new Shoe(4);

Console.WriteLine("Welcome to Blackjack!");
Console.WriteLine("   Dealer hits on soft 17.");
Console.WriteLine("Please play responsibly!");

do {
    Blackjack.playHand(wallet, shoe);
    Console.WriteLine(String.Format("You have ${0}", wallet.getMoney()));
} while(wallet.getMoney() > 5.0 && Blackjack.getContinue());

Console.WriteLine(); // a blank line to space things out

// print consolation
if(wallet.getMoney() < 5) { 
    Console.WriteLine("Awww.... better luck next time!");
}

Console.WriteLine("Thank you for playing!");
