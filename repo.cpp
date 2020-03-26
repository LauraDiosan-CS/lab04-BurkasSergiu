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

void Repo::updateItem(Player& p, char* newName, int newPG, int newWon) {
	for (int index = 0; index < noPlayer; index++) {
		if (p == playeri[index]) {
			playeri[index].setName(newName);
			playeri[index].setNoPG(newPG);
			playeri[index].setNoWins(newWon);
		}
	}
}

void Repo::deleteItem(Player& p) {
	for (int index = 0; index < noPlayer; index++) {
		Player element = playeri[index];
		if (p == element) {
			for (int index2 = index; index2 < noPlayer - 1; index2++)
				playeri[index2] = playeri[index2 + 1];
			noPlayer--;
			index--;
		}
	}
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

