
#include "repo.h"
#include<fstream>


Repo::Repo() {
	this->fileNameIn = NULL;
	this->fileNameOut = NULL;
}

Repo::~Repo() {
	this->playeri.clear();
}

Repo::Repo(const char* fileNameIn, const char* fileNameOut)
{
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
	this->loadFromFile();
}

void Repo::setFileNameIn(const char* fileNameIn)
{
	if (this->fileNameIn != NULL)
	{
		delete[]this->fileNameIn;
	}
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
}

void Repo::setFileNameOut(const char* fileNameOut)
{
	if (this->fileNameOut != NULL)
	{
		delete[]this->fileNameOut;
	}
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
}

void Repo::addItem(Player p) {
	this->playeri.push_back(p);
	this->saveToFile();
}


vector<Player> Repo::getAll() {
	return this->playeri;
}

int Repo::getSize()
{
	return this->playeri.size();
}

Player Repo::getItemAtPosition(int pos) {
	if (pos < 0 || pos > this->playeri.size() - 1)
	{
		char emptyName[] = "nu exista";
		return Player(emptyName, 0, 0);
	}
	return this->playeri[pos];
}


void Repo::updateItem(Player& oldPlayer, Player& newPlayer) {
	
	vector<Player>::iterator it;

	it = find(this->playeri.begin(), this->playeri.end(), oldPlayer);
	if (!(it == this->playeri.end()))
	{
		*it = newPlayer;
	}
	this->saveToFile();
}

void Repo::deleteItem(Player& p) {
	vector<Player>::iterator it;

	it = find(this->playeri.begin(), this->playeri.end(), p);
	if (!(it == this->playeri.end()))
	{
		this->playeri.erase(it);
	}
	this->saveToFile();
}

void Repo::loadFromFile()
{
	if (this->fileNameIn != NULL)
	{
		this->playeri.clear();
		ifstream f(this->fileNameIn);
		char* nume = new char[20];
		int noPG;
		int noWins;
		while (!f.eof())
		{
			f >> nume >> noPG >> noWins;
			if (strlen(nume) > 0)
			{
				this->addItem(Player(nume, noPG, noWins));
			}
		}
		delete[] nume;
		f.close();
	}
}

void Repo::saveToFile()
{
	if (this->fileNameOut != NULL)
	{
		ofstream f(this->fileNameIn);
		for (int i = 0; i < this->playeri.size(); i++)
		{
			f << this->playeri[i] << endl;
		}
		f.close();
	}
	if (this->fileNameOut != NULL)
	{
		ofstream f(this->fileNameOut);
		for (int i = 0; i < this->playeri.size(); i++)
		{
			f << this->playeri[i] << endl;
		}
		f.close();
	}
}



