#include <iostream>
#include <cstring>
#include <assert.h>
#include "player.h"
#include "repo.h"
#include "service.h"

void testPlayer() {

	char* nume1 = new char[10];
	strcpy_s(nume1, 4, "Lea");

	Player p(nume1,66,77);

	assert(strcmp(p.getName(), nume1) == 0);
	assert(p.getNoPG() == 66);
	assert(p.getNoWins() == 77);

	Player p1 = p;
	assert(p1.getNoPG() == p.getNoPG());
	assert(strcmp(p.getName(), p1.getName()) == 0);

	char* nume2 = new char[10];
	strcpy_s(nume1, 5, "John");

	p.setNoPG(30);
	assert(p.getNoPG() == 30);

	p.setNoWins(40);
	assert(p.getNoWins() == 40);

	p.setName(nume2);
	assert(strcmp(p.getName(), nume2) == 0);
}

void testRepo() {
	Repo repo("TestPlayersIn.txt", "TestPlayersOut.txt");
	Player p1("Silviu", 40, 40);
	repo.addItem(p1);
	int initialLen = repo.getSize();
	Player p2("John", 20, 20);
	repo.addItem(p2);

	vector<Player>playeri = repo.getAll();

	assert(repo.getSize() == initialLen+1);

	Player test("Victor", 15, 15);
	repo.updateItem(playeri[1], test);
	assert(repo.getItemAtPosition(1).getNoPG() == 15);

	vector<Player>newPlayers = repo.getAll();

	for (int i = 0; i < newPlayers.size(); i++)
		repo.deleteItem(newPlayers[i]);
	int currLen = repo.getSize();
	assert(currLen == 0);
}

void testService() {

	Repo repo;
	Service service;
	service.setRepo(repo);
	
	char* nume1 = new char[10];
	strcpy_s(nume1, strlen("Lea") + 1, "Lea");
	char* nume2 = new char[10];
	strcpy_s(nume2, strlen("John") + 1, "John");

	service.addItem(nume1, 66,77);
	service.addItem(nume2, 88,99);

	vector<Player> playeri = service.getAll();

	assert(playeri.size() == 2);

	char emptyName[] = "nu exista";
	Player emptyPlayer(emptyName, 0, 0);
	assert(service.getItemAtPosition(-1).getNoPG() == emptyPlayer.getNoPG());

	service.updateItemByName(nume2, nume2, 5, 2);
	assert(service.getItemAtPosition(1).getNoPG() == 5);

	service.deleteItemByName(nume2);
	playeri = service.getAll();
	assert(playeri.size() == 1);
}
