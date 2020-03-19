#pragma once

#ifndef REPO_H
#define REPO_H
#include "player.h"

using namespace std;

class Repo {
private:
	Player playeri[100];
	int noPlayer;
public:
	/*
	Description: The following is a default constructor
	Input: -
	Output: -
	*/
	Repo();
	/*
	Description: The following is a destructor
	Input: -
	Output: -
	*/
	~Repo();
	/*
	Description: Adds an elements to the repository
	Input: &e - class, the Expense class object with reference
	Output: -
	*/
	void addItem(Player& e);
	/*
	Description: Returns the element at a specified position
	Input: pos - int, the position
	Output: expenses[pos] - class, the Expense class object at the specified position
	*/
	Player getItemFromPos(int pos);
	
	Player* getAll();
	/*
	Description: Returns the size of the repository
	Input: -
	Output: noExpenses - int, the number of elements in the repository
	*/
	int getSize();
};
#endif#pragma once
