#include <iostream>
#include <cstring>
#include "player.h"

using namespace std;

int Player::getNoPG() {
	return this->noPG;
}

void Player::setNoPG(int newnoPG) {
	this->noPG = newnoPG;
}

Player::Player(int nrPG) {
	noPG = nrPG;
}
Player::Player(const Player& p) {
	noPG = p.noPG;
}
Player::Player() {
	//default constructor
	this->noPG = 0;

}

Player::~Player() {
	//deconstructor
	if (this->noPG)
		this->noPG = 0;
}

bool Player::compare(Player& p) {
	return ((this->noPG == p.noPG));
}
Player& Player::operator=(const Player& p) {
	this->setNoPG(p.noPG);
	return *this;
}