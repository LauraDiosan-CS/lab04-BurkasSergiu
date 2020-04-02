#pragma once
#include "player.h"
#include <vector>


class Repo {
private:
	vector<Player> playeri;
	char* fileNameIn;
	char* fileNameOut;
public:
	Repo();
	Repo(const char* fileNameIn, const char* fileNameOut);
	~Repo();

	void setFileNameIn(const char* fileNameIn);
	void setFileNameOut(const char* fileNameIOut);

	void addItem(Player p);
	
	vector<Player> getAll();

	int getSize();
	Player getItemAtPosition(int pos);

	void updateItem(Player& oldPlayer, Player& newPlayer);
	
	void deleteItem(Player& p);
	
	void loadFromFile();
	
	void saveToFile();
};

