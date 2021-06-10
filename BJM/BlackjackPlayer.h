#ifndef BLACKJACKPLAYER_H_
#define BLACKJACKPLAYER_H_

#include <string>
#include "Card.h"
#include "Deck.h"

class blackjackPlayer {
public:
	blackjackPlayer();			//constructor
	~blackjackPlayer();			//destructor
	void setName(std::string);	//set name
	void setBet(int);			//set bet amount
	int getBet(); 
	void setChipcount(int);		//set chip count
	void giveCard(card);		//give player a card
	card getAndPopLastCard();	//remove the card at back of vector and return it
	int getSizeOfHand();		//get size of hand vector
	void removeCard(int);		//remove a card at given index of hand vector
	void setCurrentHandTotal(int); //set hand total
	void setSoftStatus(bool);	//set soft status
	int getChipCount();			//get player chip count
	int getCurrentHandTotal();	//get current hand total
	bool getSoftStatus();		//see if player has soft hand
	card getCardAtIndex(int);	//get any card from hand vector using index
	std::string getName();		//get name of player 
	void setSplitHandTotals(int); //used for multiple hand totals when splitting 
	int getSplitHandTotals(int);
	int getSplitHandTotalSize(); 
	void clearSplitHandTotals(); 

private:
	std::string name;			//player name
	int bet;					//bet amount
	int chipCount;				//current chip count
	int currentHandTotal;		//current hand total (blackjack) 
	bool hasSoftHand;			//are aces contained in the hand using blackjack value 11
	std::vector<card> hand;		//hand vector
	std::vector<int> splitHandTotals; 
};



#endif // !PLAYER_H_

