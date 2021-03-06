#pragma once

#include<string>
#include<vector>
#include<iostream>
#include<map>
#include"Card.h"

//using namespace std;
//predefine the classed
class Card;
class Deck;

class Hand {
public:
	Hand();
	Hand(const Hand& hand);// a copy constructor
	~Hand(); //deconstructor because of vector instace variable
	std::vector<Card>* getHand();
	void setHand(std::vector<Card>* toSet);// set a vector to hand
	void add(Card& card); // add a card to hand
private:
	std::vector<Card>* hand; // instance varibale to store cards
	friend std::ostream& operator<<(std::ostream&, const Hand&);
};