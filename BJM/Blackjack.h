#ifndef BLACKJACK_H_
#define BLACKJACK_H_

#include "Card.h"
#include "Deck.h"
#include "BlackjackPlayer.h"
#include <vector>
#include <string>
#include <Windows.h>//chrono
#include <stdlib.h> //exit()


class blackjack {
public:
	blackjack(); 
	~blackjack(); 
	void start();			//start game
	void playerSetup();		//player setup
	void buyMoreChips();
	void numOfDecksSelect();//select num of decks (1 - 8)
	void penetrationLevelSelect(); //select amount of penetration (cut card depth in shoe)
	void mainMenu();		//main menu
	void select();			//make gameplay decisions
	void deal();			//deal a hand 
	void hit(blackjackPlayer&, bool);	//hit
	void stand();			//stand
	void doubleDown();		//double down
	void split();			//split
	void surrender();		//surrender
	void shuffle();			//reset shuffle after penetration level hit 
	void handOver(std::string);//the hand is complete and results are posted/recorded
	void dealersTurn(bool);		//dealer plays according to standard casino rules (hit soft 17) 
	
private:
	int currentPenetration;
	int allowedPenetration;
	int numOfCards; 
	int numOfDecks; 
	std::vector<card> burnPile; 
	deck shoe; 
	blackjackPlayer player; 
	blackjackPlayer dealer; 
};

#endif // !BLACKJACK_H_