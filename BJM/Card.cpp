#ifndef _CARD_CPP_
#define _CARD_CPP_

#include "Card.h"
#include "Deck.h"

using namespace std;

card::card() {
	name = ""; 
	suit = ""; 
	value = -1;
	faceUp = false; 
	rank = 0; 
}

card::~card() {

}


#endif // !_CARD_CPP_
