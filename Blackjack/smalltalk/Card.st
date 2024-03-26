Object subclass: Card [
  | value suit |

  Card class >> new: v of: s [
    | r |
    r := super new.
    r init: v of: s.
    ^r
  ]

  init: v of: s [ 
     "Initialize with value and suit."
     value := v.
     suit := s
  ]

  "Display the playing card."
  displayOn: stream [ value displayOn: stream. suit displayOn: stream]

  "Access the fields."
  value [ ^value ]
  suit [ ^suit ]
]
