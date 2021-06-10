#ifndef DECK_H_
#define DECK_H_

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>
#include <random>
#include "Card.h"

class deck {
public: 
	enum suits { clubs, diamonds, hearts, spades };
	enum cardNames { two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };

	deck();  
	~deck();
	std::string suitEnumToString(suits);		//convert enums to strings
	std::string cardNameEnumToString(cardNames);//convert enums to strings
	std::vector<card> copyDeck();	//create a copy of current deck
	void printDeck();				//print all cards in deck
	void shuffleDeck();				//shuffle cards in deck (using random time-based seed) 
	void cutDeck();					//switch top half and bottom half of deck
	void addDeck();					//add full card decks to the existing deck
	void freshSingleDeck();			//revert back to a single, unshuffled fresh card deck
	void addCard(card c);			//add a card to the deck
	int shoeSize();					//get number of cards in deck
	bool isEmpty();					//check if deck is empty
	card dealFaceUp();				//deal card with faceUp bool as true
	card dealFaceDown();			//deal card with faceUp bool as false

private: 
	std::vector<card> shoe;			//vector of cards 

};
#endif // !DECK_H_
