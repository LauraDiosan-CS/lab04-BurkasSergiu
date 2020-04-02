#pragma once


#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class Player {
private:
	char* name;
	int noPG;
	int noWins;

public:
	char* getName();
	int getNoPG();
	int getNoWins();

	void setName(const char* newName);
	void setNoPG(int newNoPG);
	void setNoWins(int newNoWins);

	Player();

	Player(const char* n,int noPlayedGames,int noWin);

	Player(const Player& p);
	
	~Player();   //deconstructor !!!!!!!!!!
	
	bool operator==(const Player& p);

	Player& operator=(const Player& p);

	friend ostream& operator<<(ostream& os, const Player& p);
};
#endif
