# BlackJack-Console-Applicaton

Created using Visual Studio 2019

This is a single player heads-up blackjack simulation game that supports betting, doubling down, splitting, doubling down after splitting, and surrendering. 

Rules: (Set up to mirror real blackjack table games commonly found in American casinos)
 - The Dealer must hit on soft 17. 
 - The Dealer peeks for blackjack after the initial cards are delt, before allowing the player to make gameplay decisions. 
 - When splitting aces, each ace is automatically given only one hit. Resplitting aces is not allowed. 
 - Doubling down and surrendering is allowed after splitting non-aces.
 - Resplitting non-aces is allowed.
 - Black Jack pays 3-2. 
 - Surrendering returns half of the bet amount back to the player. 
 
The number of decks in the shoe and amount of penetration can be customized. (Penetration is the percentage of cards that are delt from the shoe before a new shuffle 
is automatically triggered. The number of decks in the shoe can range from double deck up to 8 decks and penetration can be set from 30% to 80%).

This game adds cards to a 'burn pile' after they have been used in play. Shuffling is done by clearing the burn pile and reinitializing an unshuffled shoe of the selected 
size, then randomizing the cards using a time based seed. There is no option to simulate gameplay where a continuous shuffle machine is used, but that may be added later.  

This program uses the following classes: 
 - Card Class (card.h).
 - Deck class (deck.h - for the deck/decks in shoe). 
 - player class (blackjackPlayer.h).
 - blackjack game class (blackjack.h).

ToDo: 
 - Add a card counting feature that keeps track of the running count of the shoe. 
 - Add a feature that will give win probability based on player decisons. For instance, after the initial cards are delt, if the player has enabled this 
feature, there will be a percentage displayed of how likely it is that the player will win if he/she hits, stands, doubles, splits, etc. 
 - Add a feature that can teach the player basic strategy by warning when they make a decision that is not optimal.
 - Add option to simulate the use of a continuous shuffle machine on 6 or 8 deck games?

The control flow of this program will likely change as I add more functions and try to reduce the amount of repetitive code. 

Thanks for taking a look at this fun little project and please download it and give it a try! 

