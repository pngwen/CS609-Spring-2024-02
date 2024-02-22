class Hand
  #initialize the hand with two cards
  def initialize(down, up)
    # point values start at zero
    @hard = 0
    @soft = 0

    # create our hand, and hide it by default
    @cards = []
    @revealed = false

    # add the cards
    hit(down)
    hit(up)
  end


  #get the best point value
  def point
    if @soft != 0
      return @soft
    else
      return @hard
    end
  end


  # receive a hit
  def hit(card)
    # add the card to the hand
    @cards.append(card)

    # get the numeric value of the card
    case card.value
    when "A"
      value = 1
    when "J"
      value = 10
    when "Q"
      value = 10
    when "K"
      value = 10
    else
      value = card.value.to_i
    end

    # add to the hard score
    @hard += value

    #handle the soft score
    if @soft != 0 or value == 1
      @soft = @hard + 10
    end

    # reset a busted soft
    if @soft > 21
      @soft = 0
    end

    return nil
  end


  # convert to a string suitable for printing
  def to_s
    # get our enumerator
    enum = to_enum

    # initialize the output
    show=revealed
    result =""

    # handle the rest of the cards
    enum.each do |card|
      if show
        result += "%s " % [card.to_s]
      else
        result += "### "
      end

      # show all subseqent cards
      show = true
    end

    # add in the point value
    if revealed
      if soft != 0 
        result += "(#{@hard} / #{@soft})"
      else
        result += "(#{@hard})"
      end
    end

    return result
  end

  
  # provide a method to enumerate the hand
  def to_enum
    @cards.to_enum
  end


  # accessors
  attr_accessor :revealed
  attr_reader :hard
  attr_reader :soft
end
