FileStream fileIn: 'ArrayList.st'.

Object subclass: Menu [
  | items title |
  Menu class >> new [
    | r |
    r := super new.
    r init.
    ^r.
  ]

  init [
    "Initialize the records."
    items := ArrayList new.
    title := ''.
  ]

  "Set the title"
  title: t [ title := t. ]

  "Add an item to the list."
  addItem: item [ items append: item. ]

  choice [ 
    | choice |
    "We keep going until we get a valid choice"
    [
      "Show the menu"
      title displayNl.
      1 to: (items size) do: [ :i |
        i display.
        '.) ' display.
        (items at: i) displayNl. 
      ].
      '' displayNl.

      "Get the choice."
      'Choice? ' display.
      choice := stdin nextLine asInteger.
      ((choice < 1) | (choice > (items size))) ifTrue: [
        'Invalid selection. Please try again' displayNl.
      ] ifFalse: [
        "Return the valid choice."
        ^choice.
      ]
    ] repeat.
  ]
]