FileStream fileIn: 'Shoe.st';
           fileIn: 'Hand.st'.

Object subclass: Dealer [
  | shoe hand | 
  Dealer class >> new: decks [
    | r |
    r := super new.
    r init: decks.
    ^r
  ]

  Dealer class >> new [
    ^self new: 1
  ]

  init: decks [
    "Initialize with the given number of decks."
    shoe := Shoe new: decks.
    self newHand.
  ]

  displayOn: stream [
    "Print the dealer's hand."
    'Dealer: ' displayOn: stream.
    hand displayOn: stream
  ]

  dealCard [
    "Reshuffle as needed."
    (shoe isEmpty) ifTrue: [
      '*** Reshuffling! ***' displayNl.
      shoe shuffle
    ].

    "Deal a card from the shoe."
    ^shoe deal.
  ]

  dealMeIn [
    "Create a new hand and return it."
    ^Hand new: (self dealCard) down: (self dealCard).
  ]

  hitMe: h [
    "Add a card to the hand."
    h hit: (self dealCard)
  ]

  point [
    "Return the dealer's points."
    ^hand point
  ]

  newHand [
    "Reset the dealer's hand."
    hand := self dealMeIn
  ]

  play [
    "Play the dealer's hand"

    "Show the hand."
    hand reveal.
    self displayNl.
    
    [((hand point) <= 17) | ((hand soft) = 17)] whileTrue: [
      "We must hit, so do it!"
      'Dealer hits.' displayNl.
      self hitMe: hand.
      self displayNl
    ].

    "Handle busting or standing messages."
    ((hand point) > 21) ifTrue: [
      'Dealer Busts!' displayNl
    ] ifFalse: [
      'Dealer stands.' displayNl
    ].

    "Show our final hand."
    self displayNl.
  ]
]