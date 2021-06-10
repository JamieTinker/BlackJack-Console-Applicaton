#include "Deck.h"
#include "Card.h"

using namespace std;

#ifndef _DECK_CPP_
#define _DECK_CPP_

//generates an unshuffled 52 card standard deck
deck::deck() {
	for (int i = (int)suits::clubs; i <= (int)suits::spades; i++) {
		for (int j = (int)cardNames::two; j <= (int)cardNames::ace; j++) {
			card c; 
			c.suit = suitEnumToString((suits)i); 
			c.name = cardNameEnumToString((cardNames)j); 
			c.rank = (j + 1); 
			if (c.name == "jack" || c.name == "queen" || c.name == "king") {
				c.value = 10; 
			}
			else if (c.name == "ace") { c.value = 11; }
			else { c.value = (j + 2); }
			shoe.push_back(c);
		}
	}
}

//destructior 
deck::~deck() {
	cout << endl << "Destructor called. \n"; 
}

//enum to string (suit name) (I tried to use unicode here but its quite complicated)
string deck::suitEnumToString(suits s) {
	switch (s) {
	case clubs: return "clubs";
	case spades: return "spades"; 
	case hearts: return "hearts"; 
	case diamonds: return "diamonds"; 
	default: return "Invalid suit name.";
	}
}

//enum to string (card name) 
string deck::cardNameEnumToString(cardNames c) {
	switch (c) {
	case two: return "two";
	case three: return "three";
	case four: return "four"; 
	case five: return "five"; 
	case six: return "six"; 
	case seven: return "seven"; 
	case eight: return "eight"; 
	case nine: return "nine"; 
	case ten: return "ten"; 
	case jack: return "jack"; 
	case queen: return "queen"; 
	case king: return "king"; 
	case ace: return "ace"; 
	default: return "Invalid card name.";
	}
}

//copy deck
vector<card> deck::copyDeck() {
	vector<card> vec(shoe); 
	return vec;
}

//print deck
void deck::printDeck(){
	for (auto x : shoe) {
		cout << x.name << " " << x.suit << " " << x.value << " " << x.rank << " " << x.faceUp << endl; 
	}
}

//shuffle deck using time based seed for rng
void deck::shuffleDeck() {
	// get a time-based seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(shoe.begin(), shoe.end(), default_random_engine(seed)); 
}

//cut deck 
void deck::cutDeck() {
	for (int i = 0; i < (shoe.size() / 2); i++) {
		shoe.push_back(shoe[0]); 
		shoe.erase(shoe.begin()); 
	}
}

//add another 52 card fresh deck to the current 'shoe', values are set up for blackjack
void deck::addDeck() {
	for (int i = (int)suits::clubs; i <= (int)suits::spades; i++) {
		for (int j = (int)cardNames::two; j <= (int)cardNames::ace; j++) {
			card c;
			c.suit = suitEnumToString((suits)i); //convert to strings
			c.name = cardNameEnumToString((cardNames)j); //convert to strings
			c.rank = (j + 1); //rank from 1 to 13 (two is 1, ace is 13)
			if (c.name == "jack" || c.name == "queen" || c.name == "king") { 
				c.value = 10;
			}
			else if (c.name == "ace") { c.value = 11; }
			else { c.value = (j + 2); }
			shoe.push_back(c);
		}
	}
}

//clear deck vector then fill with new unshuffled fresh deck
void deck::freshSingleDeck() {
	shoe.erase(shoe.begin(), shoe.end()); 
	addDeck(); 
}

//add card to shoe
void deck::addCard(card c) {
	shoe.push_back(c); 
}

//size
int deck::shoeSize() {
	return shoe.size(); 
}

//empty
bool deck::isEmpty() {
	if (shoe.size() == 0) { return true;  }
	else { return false;  }
}

//deal a card, remove it from deck and change face up to true
card deck::dealFaceUp() {
	card temp = shoe.back(); 
	shoe.pop_back(); 
	temp.faceUp = true; 
	return temp; 
}

//deal a card, remove it from deck and change face up to false
card deck::dealFaceDown() {
	card temp = shoe.back();
	shoe.pop_back();
	temp.faceUp = false;
	return temp;
}

#endif // !_DECK_CPP_