Object subclass: ArrayList [
  | size capacity ar |

  ArrayList class >> new [
    | r |
    r := super new.
    r init.
    ^r.
  ]

  init [
    "Default is an empty list with a capacity of 64."
    size := 0.
    capacity := 64.
    ar := Array new: capacity.
  ]

  grow [
    | nar |
    "Double the capacity and copy the contents over."
    capacity := capacity * 2.
    nar := Array new: capacity.
    1 to: ar size do: [ :i | nar at: i put: ar at: i. ].
    ar := nar.
  ]

  append: item [
    "Append an item to the end of the list, growing if necessary."
    size := size + 1.
    size > capacity ifTrue: [ self grow ].
    ar at: size put: item.
  ]

  size [ ^size. ]

  boundErrorCheck: i [
    "Trigger an error if i is out of bounds."
    (i < 1) | (i > size) ifTrue: [ 
      ^self error: 'Index out of bounds.'.
    ].
  ]

  at: i [
    "Check the bounds and return the item."
    self boundErrorCheck: i.
    ^ar at: i.
  ]

  at: i put: item [
    "Check the bounds and write the item."
    self boundErrorCheck: i.
    self has: i ifFalse: [ ^ self error: 'Index out of bounds,' ].
    ^ar at: i put: item.
  ]

  do: aBlock [
    "Iterate through the list."
    1 to: size do: [ :i | aBlock value: self at: i. ].
  ]
]
