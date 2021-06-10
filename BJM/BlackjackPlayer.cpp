#ifndef _BLACKJACKPLAYER_CPP_
#define _BLACKJACKPLAYER_CPP_

#include "Card.h"
#include "Deck.h"
#include "BlackjackPlayer.h"

using namespace std;

//constructor
blackjackPlayer::blackjackPlayer() {
	name = ""; 
	bet = 0;
	chipCount = 0; 
	currentHandTotal = 0; 
	hasSoftHand = false; 
}

//destructor
blackjackPlayer::~blackjackPlayer() {
}

//set name
void blackjackPlayer::setName(string n) {
	name = n; 
}

//set bet amount
void blackjackPlayer::setBet(int b) {
	bet = b;
}

//get bet amount
int blackjackPlayer::getBet() {
	return bet; 
}

//set chip count
void blackjackPlayer::setChipcount(int c) {
	chipCount = c;
}

//give player a card
void blackjackPlayer::giveCard(card c) {
	hand.push_back(c); 
}

//remove a card at given index of hand vector
void blackjackPlayer::removeCard(int index) {
	if (hand.size() > index) { hand.erase(hand.begin() + index); }
	else { cout << endl << "The card doesn't exist. " << endl; }
}

//return card in back of hand vector and pop it from hand vector
card blackjackPlayer::getAndPopLastCard() {
	if (hand.size() == 0) {
		cout << endl << "(getAndPopLastCard ERROR: The player doesn't have any cards. " << endl;
		card blank;
		return blank; 
	}
	else { 
		card c = hand.back(); 
		hand.pop_back(); 
		return c;   
	}
}

//get hand vector size
int blackjackPlayer::getSizeOfHand() {
	return hand.size(); 
}


//set hand total
void blackjackPlayer::setCurrentHandTotal(int total) {
	currentHandTotal = total; 
}

//set soft status
void blackjackPlayer::setSoftStatus(bool soft) {
	hasSoftHand = soft; 
}

//get player chip count
int blackjackPlayer::getChipCount() {
	return chipCount; 
}

//get current hand total
int blackjackPlayer::getCurrentHandTotal() {
	return currentHandTotal;
}

//see if player has soft hand
bool blackjackPlayer::getSoftStatus() {
	return hasSoftHand;
}

//access any card by index
card blackjackPlayer::getCardAtIndex(int index) {
	if (hand.size() < index) {
		cout << "getCardAtIndex: ERROR: no card exits at the provided index. \n \n"; 
		card c; 
		return c; 
	}
	else {
		return hand[index]; 
	}
}

//get player name
string blackjackPlayer::getName() {
	return name; 
}

//used for splitting, multiple hand totals
void blackjackPlayer::setSplitHandTotals(int i) {
	splitHandTotals.push_back(i); 
}

//access element in splithandtotals vec
int blackjackPlayer::getSplitHandTotals(int i) {
	if (splitHandTotals.size() < i ) {
		return splitHandTotals[i];
	}
	else {
		cout << "getSplitHandTotals(" << i << ") ERROR: Element doesn't exist! \n \n"; 
		return -1; 
	}
}

//return size of splithandtotal vec
int blackjackPlayer::getSplitHandTotalSize() {
	return splitHandTotals.size(); 
}

//erase elements in splithandtotal vec
void blackjackPlayer::clearSplitHandTotals() {
	splitHandTotals.erase(splitHandTotals.begin(), splitHandTotals.end()); 
}

#endif // !_BLACKJACKPLAYER_CPP_