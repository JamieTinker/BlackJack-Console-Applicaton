
/*
#include "Deck.h"
#include "Blackjack.h"
using namespace std;

//constructor
blackjack::blackjack() {

}
//destructor
blackjack::~blackjack() {

}


/*
BLACKJACK GAME CONTROL FLOW
	- START SCREEN / WELCOME
	- PLAYER SETUP
		- NAME
		- CHIP STACK PURCHASE
	- NUMBER OF DECKS SELECT 
	- PENETRATION PERCENTAGE SELECT
	- MAIN MENU
		- PLAY HAND
		- CHANGE NUM OF DECKS
		- CHANGE PENETRATION
		- RESTART WITH FRESHLY SHUFFLED DECKS
		- QUIT
	- DEAL IS TRIGGERED BY PLAY HAND SELECTION
		- PLAYER INPUT BET AMOUNT 
		- DEAL 2 CARDS TO PLAYER AND DEALER
		- TELL PLAYER ABOUT DEALER FACE UP CARD AND PLAYER'S CARDS
	- GAME DECISION FUNCTION (bool isDealer)
		- IF isDealer == true
			- DEALERS TURN, FOLLOWS CASINO RULES
		- ELSE 
			- HIT (STANDALONE FUNC) (BLACKJACKPLAYER& PLAYER)
			- STAND	
			- DOUBLE DOWN (STANDALONE FUNC) (NO PARAM NEEDED BECAUSE ONLY PLAYER CAN DO THIS)
			- SPLIT	(STANDALONE FUNCTION) (NO PARAM NEEDED BECAUSE ONLY PLAYER CAN DO THIS)
			- SURRENDER (STANDALONE FUNCTION) (NO PARAM NEEDED BECAUSE ONLY PLAYER CAN DO THIS)
	- HAND OVER 
		- CLEAR ALL HANDS TO BURN PILE
		- RESET ALL NEEDED THINGS
		- CALCULATE PENETRATION 
		- OFFER TO PLAY AGAIN OR MAIN MENU
//




//game start - welcome message
void blackjack::start() {
	cout << endl << "+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_";
	cout << endl << "+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_";
	Sleep(100);
	cout << endl << "+_+_+_+_+_+_+_+_ Welcome to BlackJack! _+_+_+_+_+_+_+_+_";
	Sleep(100);
	cout << endl << "+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_";
	cout << endl << "+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_" << endl << endl;
	Sleep(500);
	allowedPenetration = 0;
	dealer.setName("The Dealer");
	playerSetup();
}
*/