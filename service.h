
#pragma once

#include "repo.h"


class Service
{
private:
	Repo repo;
public:
	
	Service();
	
	Service(Repo &repo);
	
	~Service();

	void setRepo(Repo repo);
	
	void addItem(const char* nume, int noPG, int noWins);
	
	vector<Player> getAll();
	
	Player getItemAtPosition(int pos);

	void updateItemByName(const char* name,const char* newName, int newNoPG, int newNoWins);
	
	void deleteItemByName(const char* name);

	vector<Player>sortByPG(vector <Player> playeri, int size);

	void showNoWins(Player playeri[], int &size);

};
