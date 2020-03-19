#include <iostream>
#include "repo.h"

Repo::Repo() {
	this->noPlayer = 0;
}

Repo::~Repo() {
	this->noPlayer = 0;
}

void Repo::addItem(Player& e) {
	this->playeri[this->noPlayer++] = e;
}

Player Repo::getItemFromPos(int pos) {
	return this->playeri[pos];
}

Player* Repo::getAll() {
	return this->playeri;
}

int Repo::getSize() {
	return this->noPlayer;
}