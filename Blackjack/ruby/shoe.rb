require "./card.rb"

class Shoe
  def initialize(n=1)
    # start at the first card
    @top = 0
    @cards = []

    # create the suits and the faces
    suits = ['S', 'C', 'D', 'H']
    faces = ['A'] + (2..10).to_a + ['J', 'Q', 'K']

    # create the cards in order
    (1..n).each do |counter|
      suits.each do | suit |
        faces.each do | face |
          @cards.append(Card.new(face, suit))
        end
      end
    end

    # shuffle the shoe
    @cards = @cards.shuffle
  end

  def deal
    card = @cards[@top]
    @top+=1
    return card
  end

  def remaining
    return @cards.length - @top
  end
end
