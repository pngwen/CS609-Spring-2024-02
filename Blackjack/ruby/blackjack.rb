require "./card.rb"
require "./shoe.rb"
require "./hand.rb"

# money and shoe are global things
$money = 100.00 # start with $100.00
$shoe = Shoe.new(4)

# methods
def play_hand
  # get everthing set up for this hand
  bet = get_bet
  player = Hand.new($shoe.deal, $shoe.deal)
  dealer = Hand.new($shoe.deal, $shoe.deal)
  done = false

  # The player can see their own cards
  player.revealed = true

  # Let the player build their hand
  while not done do
    puts "Dealer: #{dealer.to_s}"
    puts "You: #{player.to_s}"

    if player.point >= 21
     done = true
    elsif get_hit
      player.hit($shoe.deal)
    else
      done = true
    end
  end

  # reveal the dealer
  dealer.revealed = true

  # check for a bust
  if player.point > 21 
    puts "You Bust"
    $money -= bet
  else
    # Let the dealer build their hand
    dealer_hand(dealer)

    # get the outcome
    if dealer.point() > 21
      puts "Dealer Busts! You win!"
      $money += bet
    elsif dealer.point < player.point 
      if player.point == 21
        puts "You have Blackjack!"
      end
      puts "You Win!"
      $money += bet
    elsif dealer.point == player.point
      puts "Push"
    else
      puts "You Lose."
      $money -= bet
    end
  end
end

def dealer_hand(hand)
  # blank line for space
  puts

  while hand.point < 17 or hand.soft == 17
    puts "Dealer Hits"
    hand.hit($shoe.deal)
    puts "Dealer: #{hand}"
  end

  if hand.point < 21
    puts "Dealer Stands"
  elsif hand.point == 21
    puts "Dealer Has Blackjack!"
  end
end


def get_bet
  bet = 0

  # blank line for space
  puts

  loop do
    # get the bet
    print "You have $%.02f Enter bet (Minimum $5.00): "%[$money]
    bet = gets.to_f

    if bet < 5 or bet > $money 
      puts "Invalid Bet, Please try again."
    else
      break
    end
  end

  return bet
end


def get_hit
  c = ''
  loop do
    # get the user choice
    print "Do you want to (S)tand or (H)it? "
    c = gets.chomp.upcase

    if not 'SH'.include? c
      puts "Invalid Selection, please try again."
    else
      break
    end
  end

  return c == 'H'
end


def get_continue
  c = ''

  loop do
    # get the user choice
    print "Do you want to play again (Y/N)? "
    c = gets.chomp.upcase

    if not 'YN'.include? c
      puts "Invalid Selection, please try again."
    else
      break
    end
  end

  return c == 'Y'
end


# the entry point of the program
puts "Welcome to Blackjack!"
puts "   Dealer hits on soft 17."
puts "Please play responsibly!"

# A post condition loop can be made using the loop do structure
loop do
  play_hand
  puts "You have $%.02f"%[$money]
  break if $money < 5.0 or not get_continue
end

# blank line for spacing
puts

# print consolation
if $money < 5
  puts "Awww.... better luck next time!"
end

puts "Thank you for playing!"
