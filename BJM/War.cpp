//classic war card game by Jamie Tinker
//uses a card class for cards which are organized using a deck class into a deck
//5-11-21
//used to test deck and card classes and have some fun
//planning for how to implement blackjack and other card games later 
//

#include "Deck.h"
#include "War.h"

using namespace std; 


//begins the game, deals a deck evenly between players
void war::deal(deck d) {
	//reload origional deck for restarts before shuffle and deal
	if (playerCards.size() > 0 || dealerCards.size() > 0) {
		while (playerCards.size() > 0) { d.addCard(playerCards.back()); playerCards.pop_back(); }
		while (dealerCards.size() > 0) { d.addCard(dealerCards.back()); dealerCards.pop_back(); }
	}
	d.shuffleDeck(); //shuffle
	while (d.shoeSize() > 1) { //deal
		playerCards.push_back(d.dealFaceDown());
		dealerCards.push_back(d.dealFaceDown()); 
	}
	//game intro
	cout << endl << endl;
	cout << "_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_" << endl 
		<< "_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_" << endl; 
	cout << endl << "Welcome to WAR! " << endl << endl;
	cout << "_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_" << endl
		<< "_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_" << endl;
	cout << endl << "The cards have been shuffled and delt. " << endl; 
	cout << "Player one has " << playerCards.size() << " cards, and player two has " << dealerCards.size() << " cards!" << endl; 
	cout << "Beat your opponent by taking all their cards. " << endl << endl; 
	select(d); //call selection menu
}


//when players tie, a "war" is triggered to break tie using this function.
void war::warTrigger(vector<card> warCards, deck d) {
	cout << endl << endl << "CARDS ARE EQUAL VALUE" << endl << endl; 
	cout << "WAR!! " << endl << endl; 
	cout << "Both players lay three more cards face down" << endl << endl; 

	cout << "BOOM BOOM BOOM ........ SLAM! " << endl << endl; 

	card c = warCards[warCards.size() - 2];
	card v = warCards[warCards.size() - 1];
	
	cout << endl << "Player one has " << c.name << " of " << c.suit << "s!";
	cout << endl << "Player two has " << v.name << " of " << v.suit << "s!";

	//temp vector warCards store all the cards that are up for grabs this round
	if (c.rank > v.rank) {
		cout << endl << endl << "Player one wins this round and keeps ALL cards! " << endl;
		for (auto x : warCards) {
			playerCards.push_back(x); //give winner all cards 
		}
	}
	else if (c.rank < v.rank){
		cout << endl << endl << "Player two wins this round and keeps ALL cards! " << endl;
		for (auto x : warCards) {
			dealerCards.push_back(x); //give winner all cards
		}
	}
	else { 
		cout << endl << endl << "WAR AGAIN!!!!?!?!?!?" << endl << endl;
		cout << "LETS GOO!!!" << endl << endl; 

		if (playerCards.size() <= 4 || dealerCards.size() <= 4) {

			if (playerCards.size() <= 4) { gameOver(d, "Player two"); }
			else { gameOver(d, "Player one"); }
		}
	}
	//erase temp warCard vector
	warCards.erase(warCards.begin(), warCards.end()); 
	//show score
	cout << endl << "Player one now has " << playerCards.size() << " cards and player two has " << dealerCards.size() << " cards." << endl;
	//back to selection menu
	select(d); 
}


//main play function for the game. decides winner of round or triggers war. 
void war::play(deck d) {
	card one = playerCards.front(); 
	card two = dealerCards.front(); 
	//show plays
	cout << endl << "Player one has " << one.name << " of " << one.suit << "s!"; 
	cout << endl << "Player two has " << two.name << " of " << two.suit << "s!"; 
	//decide winner or tie
	if (one.rank > two.rank) {
		cout << endl << endl << "Player one wins this round and keeps both cards! " << endl; 

		playerCards.push_back(one); 
		playerCards.push_back(two); 
		
		playerCards.erase(playerCards.begin()); 
		dealerCards.erase(dealerCards.begin()); 
		if (playerCards.size() == 0 || dealerCards.size() == 0) {
			if (playerCards.size() == 0) { gameOver(d, "Player two"); }
			else { gameOver(d, "Player one"); }
		}
	}
	else if (one.rank < two.rank) {
		cout << endl << endl << "Player two wins this round and keeps both cards! " << endl;
		dealerCards.push_back(one);
		dealerCards.push_back(two);
		playerCards.erase(playerCards.begin());
		dealerCards.erase(dealerCards.begin());
		if (playerCards.size() == 0 || dealerCards.size() == 0) {
			if (playerCards.size() == 0) { gameOver(d, "Player two"); }
			else { gameOver(d, "Player one"); }
		}
	}
	else {
		if (playerCards.size() <= 4 || dealerCards.size() <= 4) {
			//show plays
			cout << endl << "Player one has " << one.name << " of " << one.suit << "s!";
			cout << endl << "Player two has " << two.name << " of " << two.suit << "s!";
			cout << endl << endl << "WAR HAS BEEN TRIGGERED AND SOMEONE DOESN'T HAVE ENOUGH CARDS!" << endl << endl; 
			if (playerCards.size() <= 4) { gameOver(d, "Player two"); }
				
			else { gameOver(d, "Player one"); }
		}

		vector<card> warCards;
		for (int i = 0; i < 5; i++) {
			warCards.push_back(playerCards[i]); 
			warCards.push_back(dealerCards[i]); 
		}
		playerCards.erase(playerCards.begin(), playerCards.begin() + 5);
		dealerCards.erase(dealerCards.begin(), dealerCards.begin() + 5);
		warTrigger(warCards, d); 
	}
	//show score if no tie
	cout << endl << "Player one now has " << playerCards.size() << " and player two has " << dealerCards.size() << endl << endl; 
	//selection menu
	select(d); 
}


//player decides what they want to do 
void war::select(deck d) {
	cout << endl << endl << "+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_" << endl << endl; 
	//input
	int choice; 
	cout << endl << "What would you like to do?" << endl << endl; 
	cout << "Enter 1 to play a hand. \nEnter 2 to restart. \nEnter 3 to quit. " << endl; 
	cout << endl << "Input: "; 
	cin >> choice; 
	while (choice < 1 || choice > 3) { 
		cout << "Please enter a valid selection: "; 
		cin >> choice; 
	}
	//choice handling 
	switch (choice) {
	case 1: { play(d); break;  }
	case 2: { deal(d);  break;  }
	case 3: { cout << "\nGOODBYE!" << endl; return;  }
	}
}


//someone has won, back to selection screen
void war::gameOver(deck d, string winner) {
	cout << endl << endl << "+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_" << endl
		<<					"+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_" << endl <<
							"+_+_+_+_+_+_+_+_+ " << winner << " is the Winner!!!!!!!!!!!!! " << "+_+_+_+_+_+_+_" << endl <<
							"+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_" << endl <<
							"+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_" << endl << endl << endl;
	select(d);


}

