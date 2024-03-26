FileStream fileIn: 'Card.st'.

Object subclass: Shoe [
  | cards top |
  Shoe class >> new [
    |r|
    r := self new: 1.
    ^r
  ]

  Shoe class >> new: decks [
    |r|
    r := super new.
    r init: decks.
    ^r
  ]
  
  init: count [
    "Initialize the shoew ith count number of decks."
    cards := Array new: (52 * count).
    1 to: cards size by: 52 do: [ :i | self addDeck: i].
    self shuffle
  ]

  addDeck: start [ | i |
    "Add a deck of cards at the starting position."
    i := start.
    #('S' 'C' 'H' 'D') do: [ :suit |
      #('A' '2' '3' '4' '5' '6' '7' '8' '9' '10' 'J' 'Q' 'K') do: [ :face |
        cards at: i put: (Card new: face of: suit).
        i := i + 1
      ]
    ]
  ]

  shuffle [
    | r j temp rng |
    "Shuffle the cards by random swaps."
    r := cards size - 1.
    rng := Random new.
    1 to: (cards size) do: [ :i |
      j := ((rng next) * r + 1) floor.
      temp := cards at: i.
      cards at: i put: (cards at: j).
      cards at: j put: temp.
    ].

    "Set the new top of the deck."
    top := 1.
  ]

  deal [ | c |
    "If the deck is empty, throw an error."
    self isEmpty ifTrue: [ self error: 'The shoe is empty.'].

    "Return the top card and remove it from consideration."
    c := cards at: top.
    top := top + 1.
    ^c
  ]

  "Indicate whether the shoe is empty."
  isEmpty [ ^top > (cards size) ]

  "Display the shoe."
  displayOn: stream [ cards displayOn: stream ]
]
