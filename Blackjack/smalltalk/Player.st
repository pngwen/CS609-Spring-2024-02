FileStream fileIn: 'Dealer.st';
           fileIn: 'Hand.st';
           fileIn: 'Menu.st'.

Object subclass: Player [
  | money hand dealer playMenu | 
  Player class >> new: d [
    | r |
    r := super new.
    r init: d.
    ^r
  ]

  init: d [
    "Initialize the fields and the dealer."
    dealer := d.
    playMenu := Menu new.
    playMenu addItem: 'Hit Me';
             addItem: 'I will Stand'.
    money := 0.
  ]

  "Access money and point."
  money [ ^money ]
  point [ ^hand point ]

  "Pay cash into the player."
  cashIn: amount [
    money := money + amount.
  ]

  "Pay cash out from the player."
  cashOut: amount [
    money := money - amount.
    (money < 0) ifTrue: [money := 0].
  ]

  "Display the player."
  displayOn: stream [
    'You: ' displayOn: stream.
    hand displayOn: stream
  ]

  bet [
    | r |
    "Repeat until we have a valid bet."
    [
      "Invite the user to bet"
      'You have $' display.
      money displayNl.
      'The table minimum is $5. Your bet: ' display.
      r := stdin nextLine asInteger.

      "Validate the bet"
      ((r >= 5) & (r <= money)) ifTrue: [
        self cashOut: r.
        ^r
      ].
      'Invalid bet. Please try again.' displayNl.
      
    ] repeat.
  ]

  
  play [
    | done choice|
    "Get Started"
    done := false.
    hand := dealer dealMeIn.
    hand reveal.

    "Continue until we are done"
    [ done ] whileFalse: [
      "Show the current state"
      dealer displayNl.
      self displayNl.

      "Let the player move"
      (playMenu choice) = 1 ifTrue: [
        dealer hitMe: hand.
      ] ifFalse: [
        done := true.
      ].

      (hand point) > 21 ifTrue: [
        done := true.
        'You bust!' displayNl.
      ]
    ].
    
    "Display the final hand."
    self displayNl.
  ]
]