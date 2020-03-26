
#pragma once

#ifndef SERVICE_H
#define SERVICE_H
#include <iostream>
#include <string.h>
#include "repo.h"
#include "player.h"

using namespace std;

class Service
{
private:
	Repo repo;
public:
	/*
	Description: The following is a default constructor
	Input: -
	Output: -
	*/
	Service();
	/*
	Description: The following is a constructor with parameters
	Input: r - Repo, the repository class
	Output: -
	*/
	Service(Repo r);
	/*
	Description: The following is a copy constructor
	Input: e - const class, the Service class object
	Output: -
	*/
	Service(const Service& s);
	/*
	Description: The following is a destructor "~"
	Input: -
	Output: -
	*/
	~Service();
	/*
	Description: Creates an element
	Input: -
	Output: -
	*/
	void createItem(char* nume, int noPG, int noWins);
	/*
	Description: Reads an element
	Input: -
	Output: -
	void readElement();
	*/
	/*
	Description: Updates an element
	Input: e - Expense, the Expense class object
		   newDay - int, the new day index
		   newSum - int, the new sum
		   newType - char*, the new type
	Output: -
	*/
	void updateItem(Player& p, char* newName, int newNoPG, int newNoWins);
	/*
	Description: Deletes an element
	Input: e - Expense, the Expense class object
	Output: -
	*/
	void deleteItem(Player& p);
	/*
	Description: Reads the repo
	Input: -
	Output: -
	*/
	Repo readRepo();
};
#endif
