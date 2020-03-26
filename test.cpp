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

	Repo repo;

	char* nume1 = new char[10];
	strcpy_s(nume1, 4, "Lea");
	char* nume2 = new char[10];
	strcpy_s(nume2, 5, "John");

	Player p1(nume1,66,77);
	Player p2(nume2,88,99);

	repo.addItem(p1);
	repo.addItem(p2);

	assert(repo.getSize() == 2);

	assert(repo.getAll()[0].getNoPG() == p1.getNoPG());
	assert(repo.getAll()[1].getNoPG() == p2.getNoPG());

	assert(repo.getAll()[0].getNoWins() == p1.getNoWins());
	assert(repo.getAll()[1].getNoWins() == p2.getNoWins());

	//assert(strcmp(repo.getAll()[0].getName(), nume1 == 0));

}

void testService() {

	Repo repo;
	Service service(repo);

	char* nume1 = new char[10];
	strcpy_s(nume1, strlen("Lea") + 1, "Lea");
	char* nume2 = new char[10];
	strcpy_s(nume2, strlen("John") + 1, "John");

	service.createItem(nume1, 66,77);
	service.createItem(nume2, 88,99);

	assert(service.readRepo().getSize() == 2);

	Player p1 = service.readRepo().getItemFromPos(0);
	Player p2 = service.readRepo().getItemFromPos(1);


	service.updateItem(p1, nume2,66,77);

	p1 = service.readRepo().getItemFromPos(0);
	p2 = service.readRepo().getItemFromPos(1);

	assert(p1 == p2);

	service.deleteItem(p2);
	assert(service.readRepo().getSize() == 1);
}
