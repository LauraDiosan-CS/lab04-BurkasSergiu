#pragma once

#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class Player {
private:
	int noPG;

public:
	/*
	Description: Returns the number of the apartment
	Input: -
	Output: apartmentNr - int, the number of the apartment
	*/
	int getNoPG();
	/*
	Description: Sets the number of the apartment
	Input: newApartmentNr - int, the new apartment number
	Output: -
	*/
	void setNoPG(int newnoPG);
	/*
	Description: The following is a default constructor
	Input: -
	Output: -
	*/
	Player();
	/*
	Description: The following is a constructor with parameters
	Input: apNr - int, the number of the apartment
		   s - int, the sum
		   t - char*, the type
	Output: -
	*/
	Player(int noPG);
	/*
	Description: The following is a copy constructor
	Input: e - const class, the Player class object
	Output: -
	*/
	Player(const Player& e);
	/*
	Description: The following is a destructor "~"
	Input: -
	Output: -
	*/
	~Player();   //deconstructor !!!!!!!!!!
	/*
	Description: The following is the comparation between to objects
	Input: e - class, the Player class object
	Output: -
	*/
	bool compare(Player& e);
	/*
	Description: create a new Expense (equal to a given Expense e)
	Input: e - class, the Expense class object
	Output: a new expense (equal to e)
	*/
	Player& operator=(const Player& e);
};

#endif
