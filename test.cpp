#include <iostream>
#include <assert.h>
#include "player.h"
#include "repo.h"

void testPlayer() {

	Player p(66);
	assert(p.getNoPG() == 66);
	Player p1 = p;
	assert(p1.getNoPG() == p.getNoPG());
	p.setNoPG(30);
	assert(p.getNoPG() == 30);
}

void testRepo() {
	Repo repo;
	Player p1(66);
	Player p2(77);
	repo.addItem(p1);
	repo.addItem(p2);
	assert(repo.getSize() == 2);
	assert(repo.getAll()[0].getNoPG() == p1.getNoPG());
	assert(repo.getAll()[1].getNoPG() == p2.getNoPG());

}
