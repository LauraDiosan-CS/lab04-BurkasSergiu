#include <iostream>
#include <cstring>
#include "player.h"

using namespace std;

char* Player::getName() {
	return this->name;
}

int Player::getNoPG() {
	return this->noPG;
}

int Player::getNoWins() {
	return this->noWins;
}

void Player::setName(char* newName) {
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(newName) + 1];
	strcpy_s(this->name, strlen(newName) + 1, newName);
}

void Player::setNoPG(int newNoPG) {
	this->noPG = newNoPG;
}

void Player::setNoWins(int newNoWins) {
	this->noWins = newNoWins;
}

Player::Player() {
	//default constructor
	this->name = NULL;
	this->noPG = 0;
	this->noWins = 0;

}

Player::Player(char *nume,int noPlayedGames,int noWin) {
	
	name = new char[strlen(nume) + 1];
	strcpy_s(name, strlen(nume)+1, nume);
	
	noPG = noPlayedGames;

	noWins = noWin;
}


Player::Player(const Player& p) {

	name = new char[strlen(p.name) + 1];
	strcpy_s(name, strlen(p.name)+1, p.name);

	noPG = p.noPG;
	
	noWins=p.noWins;
}


Player::~Player() {
	//deconstructor
	if (this->noPG)
		this->noPG = 0;
	if(this->noWins)
		this->noWins = 0;
	if (name != NULL) {
		delete[] name;
		name = NULL;
	}
}

bool Player::operator==(Player& p) {
	return ((this->noPG == p.noPG) && (this->noWins = p.noWins) && (strcmp(this->name, p.name) == 0));
}
Player& Player::operator=(const Player& p) {
	this->setNoPG(p.noPG);
	this->setNoWins(p.noWins);
	this->setName(p.name);
	return *this;
}