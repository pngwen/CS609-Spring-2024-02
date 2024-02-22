class Card
  # A card is initialized with a given suit and value
  def initialize(value, suit)
    # store the class variables, convert to string
    @value = value.to_s
    @suit = suit.to_s
  end


  # Convert the card to a string suitable for printing
  def to_s
    return "%2s%s"%[value, suit]
  end


  # read only accessors
  attr_reader :value
  attr_reader :suit
end
