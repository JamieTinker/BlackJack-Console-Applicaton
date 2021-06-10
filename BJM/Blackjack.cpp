#include "Deck.h"
#include "Blackjack.h"
using namespace std;

//constructor
blackjack::blackjack() {

}
//destructor
blackjack::~blackjack() {

}

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

//player name, player chip buy-in
void blackjack::playerSetup() {
	cout << endl << "+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_";
	Sleep(500);
	cout << endl << "+_+_+_+_+_+_+_+_+_+  Player Setup +_+_+_+_+_+_+_+_+_+_+_";
	Sleep(500);
	cout << endl << "+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_";
	Sleep(500); 
	cout << endl << endl << "Please enter your name. " << endl;
	string name;
	cout << "Input : ";
	getline(cin, name);  
	player.setName(name);
	cout << endl << "How many chips would you like to buy? \nEnter a number from 10 to 10,000. \n";
	int chips;
	cout << "Input : ";
	cin >> chips;
	while (chips < 10 || chips > 10000) {
		cout << "Please enter a valid number from 10 to 10000 : ";
		cin >> chips;
	}
	player.setChipcount(chips); 
	numOfDecksSelect(); 
}

//used if the player want to purchase more chips from main menu
void blackjack::buyMoreChips() {
	cout << endl << endl << "You currently have " << player.getChipCount() << " chips. " << endl;
	cout << endl << "How many chips would you like to buy? \nEnter a number from 10 to 10,000. \n";
	int chips;
	cout << "Input : ";
	cin >> chips;
	while (chips < 10 || chips > 10000) {
		cout << "Please enter a valid number from 10 to 10000 : ";
		cin >> chips;
	}
	player.setChipcount(player.getChipCount() + chips);
	mainMenu();
}

//select how many decks player wants to have in shoe
void blackjack::numOfDecksSelect() {
	cout << endl << "+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_"; 
	Sleep(500);
	cout << endl << "+_+_+_+_+_+  Select Number of Decks in Shoe +_+_+_+_+_+_"; 
	Sleep(500);
	cout << endl << "+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_"; 
	Sleep(500);
	cout << endl << endl;
	cout << "How many decks would you like to play with? " << endl; 
	cout << "Please Enter a number between 1 and 8. " << endl << "Input : "; //select num of decks
	numOfDecks = 0;
	numOfCards = 0;
	cin >> numOfDecks;
	while (numOfDecks < 1 || numOfDecks > 8) {	//check for valid input
		cout << "Please enter a valid number of decks: "; 
		cin >> numOfDecks;
	}
	shoe.freshSingleDeck(); //revert back to one deck then add the correct amount of decks
	for (int i = 2; i <= numOfDecks; i++) {
		shoe.addDeck(); 
	}
	//clear burn pile
	burnPile.erase(burnPile.begin(), burnPile.end()); 
	numOfCards = numOfDecks * 52; 
	shoe.shuffleDeck(); 
	Sleep(500);
	if (allowedPenetration == 0) { penetrationLevelSelect(); }
	else { mainMenu(); }
}

//select percentage of how deep the cut card would be in the shoe (typical in real casino is ~60% deep)
void blackjack::penetrationLevelSelect() {
	cout << endl << "+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_";
	Sleep(500);
	cout << endl << "+_+_+_+_+_ Select Cut Card Penetration Level _+_+_+_+_+_";
	Sleep(500);
	cout << endl << "+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_";
	Sleep(500);
	allowedPenetration = 0;
	cout << endl << endl;
	cout << "How deep should the cut card be in the shoe after a fresh shuffle? " << endl;
	cout << "Please enter the percentage of penetration from 30 to 80." 
		<< "\n(80 = 80% of shoe will be played before shuffle. )" << endl << "Input : ";
	cin >> allowedPenetration; 
	while (allowedPenetration < 30 || allowedPenetration > 80) {
		cout << "Please enter a valid percentage between 30 and 80 : ";
		cin >> allowedPenetration; 
	}
	Sleep(500);
	mainMenu(); 
}

//mainMenu
void blackjack::mainMenu() {
	cout << endl << "+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_";
	Sleep(500);
	cout << endl << "+_+_+_+_+_+_+_+_+_+_+_ Main Menu _+_+_+_+_+_+_+_+_+_+_+_";
	Sleep(500);
	cout << endl << "+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_";
	Sleep(500);
	cout << endl << endl; 
	cout << "What would you like to do? " << endl << endl; 
	Sleep(500);
	cout << "Enter 1 to play a hand. \nEnter 2 to change the number of decks you want to play with. \nEnter 3 to select the penetration level. \nEnter 4 to buy more chips. \nEnter 5 to restart the game. \nEnter 6 to quit. " << endl; 
	cout << "Input : "; 
	int choice; 
	cin >> choice; 
	while (choice < 1 || choice > 6) {
		cout << "Please enter a valid number between 1 and 3: "; 
		cin >> choice; 
	}
	//choice handling
	Sleep(500);
	switch (choice) {
	case 1: { deal(); break; }
	case 2: { numOfDecksSelect(); break; }
	case 3: { penetrationLevelSelect(); break; }
	case 4: { buyMoreChips(); break; }
	case 5: { start(); break;  }
	case 6: { cout << endl << endl << "Thanks for playing! \n \n:"; exit(0); }
	}
}

//deals the initial two cards to player and dealer
void blackjack::deal() {	//deal a hand 
	cout << endl << "+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_";
	Sleep(200);
	cout << endl << "+_+_+_+_+_+_+_+_+_+_+_+_ NEW HAND +_+_+_+_+_+_+_+_+_+_+_";
	Sleep(200);
	cout << endl << "+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_";
	Sleep(200);
	cout << endl << endl;
	//place bet
	cout << "How much would you like to bet? You currently have " << player.getChipCount() << " dollars. " << endl; 
	cout << "Input : ";
	int betAmount; 
	cin >> betAmount; 
 	
	while (betAmount > player.getChipCount() || betAmount < 10) {
		cout << "You cannot bet less than 10 or more than you have. \nPlease choose a number between 10 and " << player.getChipCount() << " : "; 
		cin >> betAmount; 
	}
	player.setBet(betAmount); 
	card d1, d2, p1, p2;
	//deal first 4 cards (one dealer card facedown) 
	d1 = shoe.dealFaceDown();
	p1 = shoe.dealFaceUp();
	d2 = shoe.dealFaceUp();
	p2 = shoe.dealFaceUp();
	player.giveCard(p1);
	player.giveCard(p2);
	dealer.giveCard(d1);
	dealer.giveCard(d2);
	//show cards to player
	Sleep(500);
	cout << endl << "The dealer draws an unknown card.. " << endl;
	Sleep(500);
	cout << "The player is delt a " << p1.name << " of " << p1.suit << ".. " << endl;
	Sleep(500);
	cout << "The dealer is delt a " << d2.name << " of " << d2.suit << ".. " << endl;
	Sleep(500);
	cout << "The player is delt a " << p2.name << " of " << p2.suit << ".. " << endl << endl << endl;
	Sleep(500);
	//sum player hand and deal with aces
	if (p1.rank != 13 && p2.rank != 13) { player.setCurrentHandTotal(p1.value + p2.value); } //zero aces
	else if (p1.rank == 13 && p2.rank != 13 || p2.rank == 13 && p1.rank != 13) { //one ace
		if(p1.rank == 13){
			player.setCurrentHandTotal(p2.value + 11);
			player.setSoftStatus(true);
		}
		else{
			player.setCurrentHandTotal(p1.value + 11);
			player.setSoftStatus(true);
		}
	}
	else { player.setCurrentHandTotal(12); player.setSoftStatus(true); } //two aces
	//sum dealer hand and deal with aces
	if (d1.rank != 13 && d2.rank != 13) { dealer.setCurrentHandTotal(d1.value + d2.value); } //zero aces
	else if (d1.rank == 13 && d2.rank != 13 || d2.rank == 13 && d1.rank != 13) { //one ace
		if (d1.rank == 13) {
			dealer.setCurrentHandTotal(d2.value + 11);
			dealer.setSoftStatus(true);
		}
		else {
			dealer.setCurrentHandTotal(d1.value + 11);
			dealer.setSoftStatus(true);
		}
	}
	else { dealer.setCurrentHandTotal(12); dealer.setSoftStatus(true); } //two aces
	//check for any blackjacks
	if (player.getCurrentHandTotal() == 21 || dealer.getCurrentHandTotal() == 21) {//this is dealer 'peeking' at his facedown card looking for bj 
		if (player.getCurrentHandTotal() == 21) {
			cout << "You have Blackjack! Nice 21." << endl << endl;
			player.setBet((player.getBet() / 2) * 3); //pays 3-2 for blackjack
			handOver("player");
		}
		else if (player.getCurrentHandTotal() == 21 && dealer.getCurrentHandTotal() == 21) {
			cout << "Both you AND the dealer have Blackjack! " << endl << endl;
			handOver("push");
		}
		else {
			cout << "The dealer has Blackjack!" << endl << endl;
			handOver("dealer");
		}
	}
	select(); 
}

//game play decisions
void blackjack::select() {
	card p1, p2, d1;
	p1 = player.getCardAtIndex(0); 
	p2 = player.getCardAtIndex(1); 
	d1 = dealer.getCardAtIndex(1);
	cout << "Player Hand: " << p1.name << " of " << p1.suit << ", " << p2.name << " of " << p2.suit << ".. " << "against a dealer " << d1.name << ".." << endl << endl; 
	cout << "You have " << player.getCurrentHandTotal() << ". " << endl << endl;
	Sleep(500);
	cout << "What would you like to do? " << endl << endl; 
	cout << "Enter 1 to hit. \nEnter 2 to stand. \nEnter 3 to double down. \nEnter 4 to split. \nEnter 5 to surrender. " << endl; 
	cout << "Input : "; 
	int choice; 
	cin >> choice; 
	while (choice < 1 || choice > 5) {
		cout << "Please enter a valid number from 1 to 5: "; 
		cin >> choice; 
	}
	//decision handling 
	switch (choice) {
	case 1: { hit(player, false); break;  }
	case 2: { stand(); break;  }
	case 3: { doubleDown(); break;  }
	case 4: { split(); break;  }
	case 5: { surrender(); }
	}
}

//hit function
void blackjack::hit(blackjackPlayer& who, bool dd) {
	card c = shoe.dealFaceUp(); //get card from shoe
	who.giveCard(c); //give it to players hand vector
	int currentTotal = who.getCurrentHandTotal(); 
	if (c.rank == 13) { //the hit is an ace
		currentTotal += 11; 
		if (currentTotal > 21) { //determine set hard or soft
			currentTotal -= 10;
			who.setCurrentHandTotal(currentTotal); 
		}
		else {
			who.setCurrentHandTotal(currentTotal); 
			who.setSoftStatus(true); 
		}
	}
	else {
		currentTotal += c.value; //not delt an ace
		who.setCurrentHandTotal(currentTotal); 
	}
	bool soft = who.getSoftStatus(); 
	if (currentTotal > 21 && soft == true) { //are there other aces already in players hand?
		who.setCurrentHandTotal(currentTotal -= 10); 
		who.setSoftStatus(false);  
	}
	Sleep(500);
	//tell user what happened after hit
	cout << endl << endl << who.getName() << " is delt a " << c.name << " of " << c.suit << ".." << endl << endl;
	Sleep(500);
	if (currentTotal > 21 && who.getName() != "The Dealer" ) { //player busted
		cout << who.getName() << " has busted at " << who.getCurrentHandTotal() << ". Please try again." << endl << endl;
		handOver("dealer");
	}
	else if (currentTotal > 21 && who.getName() == "The Dealer") { //dealer busted
		cout << "The Dealer has busted at " << who.getCurrentHandTotal() << "." << endl << endl;
		handOver("player");
	}
	else if (who.getName() != "The Dealer" && dd == false) { //player hit and didn't bust - choose hit or stand
		cout << who.getName() << " now has a " << who.getCurrentHandTotal() << ". What would you like to do?" << endl << endl; 
		cout << "Enter 1 to hit again, or 2 to stand. \nInput : ";
		int choice;
		cin >> choice;
		while (choice < 1 || choice > 2) {
			cout << "Please enter a valid number, either 1 or 2 : ";
			cin >> choice;
		}
		if (choice == 1) { hit(player, false); }
		else { dealersTurn(false); }
	}
	else if ((who.getName() != "The Dealer" && dd == true)) { //player doubled down and didn't bust
		cout << who.getName() << " now has a " << who.getCurrentHandTotal() << ". Lets see what the dealer can do.." << endl << endl; 
		dealersTurn(false); 
	}
	else { //dealer hits and doesn't bust
		cout << "The Dealer now has a " << who.getCurrentHandTotal() << "."  << endl << endl;
	}
}

//player done making decisions, now dealers turn 
void blackjack::dealersTurn(bool split) { 
	card c = dealer.getCardAtIndex(0);
	card d = dealer.getCardAtIndex(1);
	cout << endl << endl;
	Sleep(500);
	cout << "The dealer flips his 2nd card and shows a " << c.name << " of " << c.suit << ".." << endl << endl; 
	Sleep(500);
	cout << "Dealers Hand: " << d.name << " of " << d.suit << ", " << c.name << " of " << c.suit << ".. " << endl << endl;
	Sleep(500);
	cout << "He has a " << dealer.getCurrentHandTotal() << ". "  << endl;
	//dealer has over 17 but less than 22
	if (dealer.getCurrentHandTotal() > 17 && dealer.getCurrentHandTotal() < 22) {
		if (dealer.getCurrentHandTotal() > player.getCurrentHandTotal()) { handOver("dealer"); } // dealer wins
		else if (dealer.getCurrentHandTotal() < player.getCurrentHandTotal()) { handOver("player"); }//player wins
		else { handOver("push"); } //push
	}
	//dealer has hard 17
	if (dealer.getCurrentHandTotal() == 17 && dealer.getSoftStatus() == false) {
		if (dealer.getCurrentHandTotal() > player.getCurrentHandTotal()) { handOver("dealer"); } // dealer wins
		else if (dealer.getCurrentHandTotal() < player.getCurrentHandTotal()) { handOver("player"); }//player wins
		else { handOver("push"); } //push
	}
	while (dealer.getCurrentHandTotal() <= 17) {
		//dealer has soft 17 (always hit)
		if (dealer.getCurrentHandTotal() == 17 && dealer.getSoftStatus() == true) {
			hit(dealer, false);
		}
		//dealer has less than 17 (soft) (always hit)
		else if (dealer.getCurrentHandTotal() < 17 && dealer.getSoftStatus() == true) {
			hit(dealer, false); 
		}

		//dealer has less than 17 (hard) (always hit)
		else if (dealer.getCurrentHandTotal() < 17 && dealer.getSoftStatus() == false)  {
			hit(dealer, false);
		}
		//check if dealer busted, won, pushed, or lossed
		//dealer done hitting but no bust
		if (dealer.getCurrentHandTotal() > 17 && dealer.getCurrentHandTotal() < 22) {
			if (dealer.getCurrentHandTotal() > player.getCurrentHandTotal()) { handOver("dealer"); } // dealer wins
			else if (dealer.getCurrentHandTotal() < player.getCurrentHandTotal()) { handOver("player"); }//player wins
			else { handOver("push"); }
		}
		//dealer has hard 17, done but no bust (if soft 17, loop again)
		else if (dealer.getCurrentHandTotal() == 17 && dealer.getSoftStatus() == false) {
			if (dealer.getCurrentHandTotal() > player.getCurrentHandTotal()) { handOver("dealer"); } // dealer wins
			else if (dealer.getCurrentHandTotal() < player.getCurrentHandTotal()) { handOver("player"); }//player wins
			else { handOver("push"); } //push
		}
		//dealer has hard hand over 21 (bust)
		if (dealer.getCurrentHandTotal() > 21 && dealer.getSoftStatus() == false) {
			handOver("player"); 
		}
	}	
}

//standing just calls dealersTurn()
void blackjack::stand() {
	dealersTurn(false);
}

//player gets one hit and doubles their bet 
void blackjack::doubleDown() {
	Sleep(500);
	cout << endl << endl << "Double Down: "; 
	if ((player.getBet() * 2) > player.getChipCount()) {
		cout << "You don't have enough money to double down. \nPlease enter 1 to hit, 2 to stand, or 3 to surrender.  " << endl << "Input : "; 
		int choice; 
		cin >> choice; 
		while (choice < 1 || choice > 3) {
			cout << "Please enter a valid choice of 1, 2 or 3 : "; 
			cin >> choice; 
		}
		if (choice == 1) {
			hit(player, false); 
		}
		else if (choice == 3) {
			surrender(); 
		}
		else { stand(); }
	}
	player.setBet(player.getBet() * 2);
	hit(player, true);  
}

//player can split if both delt cards have same name (suit doesn't matter) 
void blackjack::split() {
	if (player.getSizeOfHand() > 2 || player.getCardAtIndex(0).name != player.getCardAtIndex(1).name) {
		cout << "You can only split when both cards have the same name (pair). " << endl; 
		cout << endl << "What would you like to do? \n \nEnter 1 to hit. \nEnter 2 to stand. \nEnter 3 to double down. \nEnter 4 to surrender. \nInput : "; 
		int choice; 
		cin >> choice; 
		while(choice < 1 || choice > 4) {
			cout << "Please enter a valid number from 1 to 4 : "; 
			cin >> choice; 
		}
		switch (choice) {
		case 1: { hit(player, false); break; }
		case 2: { stand(); break; }
		case 3: { doubleDown(); break; }
		case 4: { surrender(); }
		}
	}

	int currentTotal1, currentTotal2; 

	if (player.getCardAtIndex(0).rank == 13) {	//player split aces - one hit per hand - respliting aces not allowed
		card c = shoe.dealFaceUp(); 
		player.giveCard(c);
		card d = shoe.dealFaceUp(); 
		player.giveCard(d); 
		
		currentTotal1 = 11;
		currentTotal2 = 11;  
		currentTotal1 += c.value; 
		currentTotal2 += d.value; 

		if (currentTotal1 > 21) { currentTotal1 -= 10; }
		if (currentTotal2 > 21) { currentTotal2 -= 10; }

		player.setSplitHandTotals(currentTotal1);
		player.setSplitHandTotals(currentTotal2);
		
		//tell player what happened
		cout << "Splitting Aces: You will be given one hit per hand, resplitting aces is not permitted. " << endl << endl; 
		cout << "First hand with Ace is delt a " << c.name << " of " << c.suit << ".. your first hand total is " << currentTotal1 << endl << endl; 
		cout << "Sencond hand with Ace is delt a " << d.name << " of " << d.suit << ".. your second hand total is " << currentTotal2 << endl << endl; 

		dealersTurn(true); 
	}
	else { //splitting something other than aces
		int splitFirstCardIndex = 0; 

		cout << endl << "Splitting: You have split " << player.getCardAtIndex(0).name << "s.. " << endl << endl; 

		for (int i = 0; i < 2; i++) {
			currentTotal1 = player.getCardAtIndex(splitFirstCardIndex).value;
			card c = shoe.dealFaceUp(); 
			player.giveCard(c);

			//tell player about hit
			if (splitFirstCardIndex = 0) {
				cout << "First Hand: You have a " << player.getCardAtIndex(splitFirstCardIndex).name << " and have been delt a " << c.name << ".. " << endl << endl; 
			}
			else if (splitFirstCardIndex = 1) {
				cout << "Second Hand: You have a " << player.getCardAtIndex(splitFirstCardIndex).name << " and have been delt a " << c.name << ".. " << endl << endl;
			}
			else if (splitFirstCardIndex = 3) {
				cout << "Third Hand: You have a " << player.getCardAtIndex(player.getSizeOfHand() - 2).name << " and have been delt a " << c.name << ".. " << endl << endl;
			}
			else {
				cout << "You have a " << player.getCardAtIndex(player.getSizeOfHand() - 2).name << " and have been delt a " << c.name << ".. " << endl << endl;
			}
			
			if (currentTotal1 = c.value) {
				//hit is same as other card in hand - offer to split again
				if (player.getChipCount() < player.getBet() * 2) { //can't split - not enough chips
					cout << "You don't have enough chips to split again. Would you like to hit or stand? \nEnter 1 to hit and 2 to stand. \nInput : "; 
					int choice; 
					cin >> choice; 
					while (choice < 1 || choice > 2) {
						cout << "Please enter a 1 or a 2 : "; 
						cin >> choice; 
					}
					while (choice == 1 || currentTotal1 < 21) {

						card d = shoe.dealFaceUp();
						currentTotal1 += d.value; 
						player.giveCard(d); 
						cout << endl << endl << player.getName() << " is delt a " << d.name << " of " << d.suit << "s.." << endl << endl; 
						cout << "This split hand total is " << currentTotal1 << endl << endl; 
						player.setSplitHandTotals(currentTotal1); 
					
						cout << "What would you like to do? Enter 1 to hit again or 2 to stand. \nInput : "; 
						cin >> choice;
						while (choice < 1 || choice > 2) {
							cout << "Please enter a 1 or a 2 : ";
							cin >> choice;
						}
					}

				}
				else { //can split, has enough chips
					//offer choice to split
					cout << "You can split again if you want. What would you like to do? " << endl; 
					cout << "Enter 1 if you would like to split again or 2 if you would like to keep what you have.. \nInput : "; 
					int splitChoice; 
					cin >> splitChoice; 
					while (splitChoice < 1 || splitChoice > 2) {
						cout << "Please enter either 1 or 2 : "; 
						cin >> splitChoice; 
					}
					//takes offer to split again
					if (splitChoice == 1) {
						i -= 1; //loop one more time 
						cout << "Splitting again: You have split " << player.getCardAtIndex(0).name << "s.. " << endl << endl;
						cout << "Would you like to hit or stand ? \nEnter 1 to hit and 2 to stand. \nInput : "; 
						int choice;
						cin >> choice;
						while (choice < 1 || choice > 2) {
							cout << "Please enter a 1 or a 2 : ";
							cin >> choice;
						}
						while (choice == 1 || currentTotal1 < 21) {

							card d = shoe.dealFaceUp();
							currentTotal1 += d.value;
							player.giveCard(d);
							cout << endl << endl << player.getName() << " is delt a " << d.name << " of " << d.suit << "s.." << endl << endl;
							cout << "This split hand total is " << currentTotal1 << endl << endl;
							player.setSplitHandTotals(currentTotal1);

							cout << "What would you like to do? Enter 1 to hit again or 2 to stand. \nInput : ";
							cin >> choice;
							while (choice < 1 || choice > 2) {
								cout << "Please enter a 1 or a 2 : ";
								cin >> choice;
							}
						}
					}
					//doesn't split again
					else {

					}
					

				}
				
				


			}
			//hit card differs from split cards, no more splitting, give hit and prompt
			else { 
				currentTotal1 += c.value; //check for softness
				if (c.rank == 13 && currentTotal1 > 21) {
					currentTotal1 -= 10;
				}
				//tell player new total
				cout << "Your hand total for this split hand is " << currentTotal1 << endl << endl; 

				//prompt decision
				cout << "What would you like to do? Enter 1 to hit and 2 to stand. \nInput : "; 
				int choice;
				cin >> choice;
				while (choice < 1 || choice > 2) {
					cout << "Please enter a 1 or a 2 : ";
					cin >> choice;
				}
				while (choice == 1 || currentTotal1 < 21) {

					card d = shoe.dealFaceUp();
					currentTotal1 += d.value;
					player.giveCard(d);
					cout << endl << endl << player.getName() << " is delt a " << d.name << " of " << d.suit << "s.." << endl << endl;
					cout << "This split hand total is " << currentTotal1 << endl << endl;
					player.setSplitHandTotals(currentTotal1);

					cout << "What would you like to do? Enter 1 to hit again or 2 to stand. \nInput : ";
					cin >> choice;
					while (choice < 1 || choice > 2) {
						cout << "Please enter a 1 or a 2 : ";
						cin >> choice;
					}
				}

			}

			splitFirstCardIndex++; //0 first time, 1 second time, playerhandVector size - 1 after that
			if (splitFirstCardIndex > 1) {
				splitFirstCardIndex = player.getSizeOfHand() - 1; 
			}
		}
		 




	}
		



	


	

}

//surrender - player loses but keeps half their bet
void blackjack::surrender() { 
	handOver("surrender"); 
}

//auto shuffle function for when cut card is reached 
void blackjack::shuffle() {
	shoe.freshSingleDeck(); //revert back to one deck then add the correct amount of decks
	for (int i = 2; i <= numOfDecks; i++) { //add correct num of decks
		shoe.addDeck();
	}
	burnPile.erase(burnPile.begin(), burnPile.end());
	currentPenetration = 0; 
	shoe.shuffleDeck(); //shuffle
	cout << endl << "The cut card was drawn during the last hand and the cards must be shuffled. " << endl << endl; 
	Sleep(200); 
	cout << endl << "+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_";
	Sleep(1200);
	cout << endl << "+_+_+_+_+_+_+_+_+_+ SHUFFLING DECK _+_+_+_+_+_+_+_+_+_+_";
	Sleep(1200);
	cout << endl << "+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_";
	Sleep(1200);
	cout << endl << endl;
	cout << "The cards have been shuffled and play can resume. " << endl << endl; 
	Sleep(500); //prompt player
	cout << "Would you like to play another hand? " << endl << endl;
	cout << "Enter 1 for yes, or 2 to go back to the main menu. \nInput : ";
	int choice;
	cin >> choice;
	while (choice < 1 || choice > 2) {
		cout << "Please enter a valid number, either 1 or 2 : ";
		cin >> choice;
	}
	if (choice == 1) { deal(); }
	else { mainMenu(); }
}

//resets vectors and variables for a new hand, displays winner/loser outcome message, calculate penetration, payout bets. 
void blackjack::handOver(string winner) {
	//clear player hand vectors and add cards to burn pile
	int sizeOfPlayerHand = player.getSizeOfHand(); 
	int sizeOfDealerHand = dealer.getSizeOfHand(); 
	for (int i = 0; i < sizeOfPlayerHand; i++) {
		burnPile.push_back(player.getAndPopLastCard()); 
	}
	for (int i = 0; i < sizeOfDealerHand; i++) {
		burnPile.push_back(dealer.getAndPopLastCard());
	}
	player.setCurrentHandTotal(0);	//reset soft flags and hand totals
	dealer.setCurrentHandTotal(0); 
	player.setSoftStatus(false); 
	dealer.setSoftStatus(false); 
	Sleep(500);
	if (winner == "player") { //display winner/loser/push/surrender messages
		cout << endl << "Congradulations to the Player. Please play again!" << endl << endl;
		player.setChipcount(player.getChipCount() + player.getBet()); 
		cout << "You have won " << player.getBet() << " and now have " << player.getChipCount() << " chips." << endl << endl;
	}
	else if (winner == "dealer") {
		cout << endl << "The dealer got you this time. Try again!" << endl << endl; 
		player.setChipcount(player.getChipCount() - player.getBet());
		cout << "You have lost " << player.getBet() << " and now have " << player.getChipCount()  << " chips." << endl << endl;
	}
	else if (winner == "surrender") {
		cout << endl << "Surrendering has cost you " << (player.getBet() / 2) << ". Better luck next time. " << endl << endl;
		player.setChipcount(player.getChipCount() - (player.getBet() / 2)); 
		cout << "You now have " << player.getChipCount() << " chips." << endl << endl;
	}
	else {
		cout << endl << "Push. No winner. Try Again!" << endl << endl; 
		cout << "You have " << player.getChipCount() << " chips." << endl << endl;
	}
	player.setBet(0); //reset bet amount
	Sleep(200);
	int burn = burnPile.size();  //calculate penetration 
	currentPenetration = (burnPile.size() * 100 / numOfCards); 
	if (currentPenetration > allowedPenetration) { //trigger shuffle if cut card reached
		shuffle(); 
	}
	else {
		cout << endl << "*You notice that about " << currentPenetration << " percent of the cards have been used so far this shoe.* " << endl << endl << endl;
	}
	Sleep(500); //prompt player
	if (player.getChipCount() < 10) {
		cout << "You're running low on chips, would you like to buy some more now? (You can also buy more in the Main Menu). " << endl; 
		cout << "Enter 1 to buy more chips, or 2 to go to the Main Menu. \nInput : "; 
		int choice; 
		cin >> choice; 
		while (choice < 1 || choice > 2) {
			cout << "Please enter a valid number, either 1 or 2 : ";
			cin >> choice;
		}
		if (choice == 1) { buyMoreChips(); }
		else { mainMenu(); }
	}

	cout << "Would you like to play another hand? " << endl << endl;
	cout << "Enter 1 for yes, or 2 to go back to the main menu. \nInput : "; 
	int choice; 
	cin >> choice; 
	while (choice < 1 || choice > 2) {
		cout << "Please enter a valid number, either 1 or 2 : "; 
		cin >> choice; 
	}
	if (choice == 1) { deal(); }
	else { mainMenu(); }
}