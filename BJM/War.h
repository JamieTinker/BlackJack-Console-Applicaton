#ifndef WAR_H_
#define WAR_H_

#include "Card.h"
#include "Deck.h"
#include <vector>
#include <string>


class war {
public:
	void deal(deck); 
	void play(deck);
	void warTrigger(std::vector<card> warCards, deck d); 
	void select(deck); 
	void gameOver(deck, std::string);

private: 
	std::vector<card> dealerCards; 
	std::vector<card> playerCards;
	std::vector<card> freshDeck; 
	int score; 


};



#endif // !WAR_H_

