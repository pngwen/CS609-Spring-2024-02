FileStream fileIn: 'Dealer.st';
           fileIn: 'Player.st';
           fileIn: 'Menu.st'.

"Define the bet menu"
betMenu := Menu new.
betMenu addItem: 'Bet';
        addItem: 'Cash Out'.

"Create the player and the dealer."
dealer := Dealer new.
player := Player new: dealer.

"Display a welcome message."
'Welcome to Blackjack!' displayNl.
'   Dealer hits on soft 17.' displayNl.
'Please play responsibly!' displayNl.

"Let the player buy in to the game."
"Let the player cash in."
'Cash in amount? ' display.
player cashIn: stdin nextLine asInteger.

"The Game Loop"
done := false.
[done] whileFalse: [
  "Let the player bet and assemble their hand"
  bet := player bet.
  player play.

  "The dealer moves if the player has not busted."
  p := player point.
  (p <= 21) ifTrue: [
    "Let the dealer assemble their hand."
    dealer play.

    "Display the final state"
    '' displayNl.
    player displayNl.
    dealer displayNl.

    "Determine the winner."
    d := dealer point.
    ((d > 21) | (d < p)) ifTrue: [
      'You win!' displayNl.
      player cashIn: bet*2.
    ] ifFalse: [
      (p = d) ifTrue: [
        'Push!' displayNl.
        player cashIn: bet.
      ] ifFalse: [
        'You lose.' displayNl.
      ]
    ]
  ].

  "Display the remaining money"
  'You have $' display.
  player money displayNl.
  
  ((player money) < 5) ifTrue: [
    "No money, no play!"
    done := true.
    'Awww.... better luck next time!' displayNl.
  ] ifFalse: [
    done := (betMenu choice) = 2
  ].

  "Play another hand if we are not done."
  done ifFalse: [dealer newHand].
]

"Thank the user."
'Thank you for playing!' displayNl.
