
#include "service.h"
#include "player.h"

Service::Service() {
}

Service::Service(Repo &repo) {
	this->repo=repo;
}

Service::~Service() {
	
}

void Service::setRepo(Repo repo)
{
	this->repo = repo;
}

void Service::addItem(const char* nume, int noPG, int noWins) {
	this->repo.addItem(Player(nume, noPG, noWins));
}

vector<Player> Service::getAll()
{
	return this->repo.getAll();
}

Player Service::getItemAtPosition(int pos)
{
	return this->repo.getItemAtPosition(pos);
}

void Service::updateItemByName(const char* name,const char* newName, int newNoPG, int newNoWins) {
	vector<Player> playeri = this->repo.getAll();
	Player newPlayer(newName, newNoPG, newNoWins);
	for (int i = 0; i < this->repo.getSize(); i++)
	{
		if (strcmp(playeri[i].getName(), name) == 0)
		{
			Player oldPlayer(name, playeri[i].getNoPG(), playeri[i].getNoWins());
			this->repo.updateItem(oldPlayer, newPlayer);
			return;
		}
	}
}

void Service::deleteItemByName(const char* name) {
	vector<Player> playeri = this->repo.getAll();
	for (int i = 0; i < this->repo.getSize(); i++)
	{
		if (strcmp(playeri[i].getName(), name) == 0)
		{
			Player studentToDelete(name, playeri[i].getNoPG(), playeri[i].getNoWins());
			this->repo.deleteItem(studentToDelete);
			return;
		}
	}
}

vector<Player> Service::sortByPG(vector <Player> playeri,int size)
{
	Player aux;
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (playeri[j].getNoPG() < playeri[j + 1].getNoPG())
			{
				aux = playeri[j];
				playeri[j] = playeri[j + 1];
				playeri[j + 1] = aux;
			}
	return playeri;
}

void Service::showNoWins(Player playeri[], int &size)
{
	for (int i = 0; i < repo.getSize(); i++)
	{
		if (repo.getItemAtPosition(i).getNoWins() == 0)
		{
			playeri[++size] = repo.getItemAtPosition(i);
		}
	}
}

