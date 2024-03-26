FileStream fileIn: 'ArrayList.st';
           fileIn: 'Card.st'.


Object subclass: Hand [
  | cards hard soft revealed |
  Hand class >> new: up down: down [
    | r |
    r := super new.
    r init: up down: down.
    ^r
  ]

  init: up down: down [
    "Initialize the fields."
    cards := ArrayList new.
    hard := 0.
    soft := 0.
    revealed := false.

    "Add the first two cards."
    self hit: up; hit: down
  ]

  hit: card [
    "Add a card to the hand and compute points."
    | vs vnum |
    cards append: card.

    "Get the card value and attempt to convert it to a number."
    vs := card value.
    vnum := vs asInteger.

    (vnum = 0) ifTrue: [
      "Handle face cards."
      (vs = 'A') ifTrue: [vnum := 1]
                 ifFalse: [vnum := 10]
    ].

    "Add to our hard score."
    hard := hard + vnum.

    "Handle the soft score."
    ((soft ~= 0) | (vnum = 1)) ifTrue: [ soft := hard + 10].
    (soft > 21) ifTrue: [soft := 0]
  ]

  point [
    "Return our best point value."
    (soft=0) ifTrue: [ ^hard ].
    ^soft
  ]

  "Access hard and soft scores."
  hard [^hard]
  soft [^soft]

  "Reveal the hand."
  reveal [ revealed := true ]

  "Display the hand."
  displayOn: stream [
    (cards at: 1) displayOn: stream.
    2 to: (cards size) do: [ :i | 
      ' ' displayOn: stream.
      (revealed) ifTrue: [
        (cards at: i) displayOn: stream
      ] ifFalse: [
        '##' displayOn: stream
      ]
    ].
    
    revealed ifTrue: [
      ' (' displayOn: stream.
      hard displayOn: stream.
      (soft > 0) ifTrue: [
        ' / ' displayOn: stream.
        soft displayOn: stream
      ].
      ')' displayOn: stream
    ]
  ]
]