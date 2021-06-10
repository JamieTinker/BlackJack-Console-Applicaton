#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <string> 

class card {
public: 
	card(); 
	~card(); 
	std::string name;	//i.e. king, jack , etc.
	std::string suit;
	int value;			//black jack value
	bool faceUp;
	int rank; 

private: 

};



#endif // !CARD_H_