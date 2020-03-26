#include <iostream>
#include "repo.h"
#include "player.h"
#include "service.h"

using namespace std;

Service::Service() {
	//cout << "This is a default constructor" << endl;
}

Service::Service(Repo r) {
	//cout << "This is an implicit constructor with parameters" << endl;
	repo = r;
}

Service::Service(const Service& s) {
	//cout << "This is a copy constructor" << endl;
	repo = s.repo;
}

Service::~Service() {
	//cout << "This is a destructor" << endl;
}

void Service::createItem(char* nume, int noPG, int noWins) {
	Player p(nume, noPG, noWins);
	repo.addItem(p);
}

void Service::updateItem(Player& p, char* newName, int newNoPG, int newNoWins) {
	repo.updateItem(p, newName, newNoPG, newNoWins);
}

void Service::deleteItem(Player& p) {
	repo.deleteItem(p);
}

//Repo e pentru ca returnez repo, iar Service
Repo Service::readRepo() {
	return this->repo;
}