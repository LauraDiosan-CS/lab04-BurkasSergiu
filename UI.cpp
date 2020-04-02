#include "UI.h"
#include <iostream>
#include <string>
#include <string.h>


using namespace std;

UI::UI()
{
}

UI::UI(Service& service)
{
	this->service = service;
}

void UI::displayMenu()
{
	cout << "1. Scrie \"add {{nume}} {{nr jocuri jucate}} {{nr jocuri castigate}}\" pentru a adauga un player\n";
	cout << "2. Scrie \"show\" pentru a afisa toti jucatorii\n";
	cout << "3. Scrie \"pos {{i}}\" pentru a afisa jucatorul de pe pozitia i\n";
	cout << "4. Scrie \"update {{oldName}} {{newName}} {{newNoPG}} {{newNoWins}}\" pentru a updata playerul cu numele {{oldName}}\n";
	cout << "5. Scrie \"delete {{name}}\" pentru a sterge jucatorul cu numele {{name}}\n";
	cout << "6. Scrie \"sort\" pentru a afisa toti jucatori in functie de numarul de jocuri jucate\n";
	cout << "7. Scrie \"filterNoWins\" pentru a afisa toti jucatori care nu castigat niciodata\n";
	cout << "x. Scrie \"exit\" pentru a inchide aplicatia\n";
	cout << "\nGive option: \n";
}

void UI::uiAddPlayer(string cmd)
{
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* name = new char[token.length() + 1];
	strcpy_s(name, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int noPG = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int noWins = stoi(token);

	this->service.addItem(name, noPG, noWins);
}

void UI::uiShowAll()
{
	vector <Player> playeri = this->service.getAll();
	int size = playeri.size();
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << playeri[i] << "\n";
	}
	cout << endl;
}

void UI::uiShowAtPosition(string cmd)
{
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());
	int position = stoi(cmd);
	cout << this->service.getItemAtPosition(position) << endl;
}

void UI::uiUpdateByName(string cmd)
{
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* oldName = new char[token.length() + 1];
	strcpy_s(oldName, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* newName = new char[token.length() + 1];
	strcpy_s(newName, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int newNoPG = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int newNoWins = stoi(token);

	this->service.updateItemByName(oldName, newName, newNoPG, newNoWins);
}

void UI::uiDeleteByName(string cmd)
{
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* name = new char[token.length() + 1];
	strcpy_s(name, token.length() + 1, token.c_str());

	this->service.deleteItemByName(name);
}

/*void UI::uiDeleteAtPos(string cmd)
{
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int position = stoi(cmd);

	this->service.deleteStudentByPosition(position);
}*/
void UI::uiSortByNoPG()
{
	vector <Player> playeri = this->service.getAll();
	int size = playeri.size();
	vector <Player> ordPlayers=this->service.sortByPG(playeri, size);
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << ordPlayers[i] << "\n";
	}
	cout << endl;
}	

void UI::uiShowNoWins()
{
	Player playeri[1001];
	int length = 0;
	service.showNoWins(playeri, length);
	cout << endl;
	for (int i = 1; i <= length; i++)
	{
		cout << playeri[i] << "\n";
	}
	cout << endl;
}
void UI::runUI()
{
	bool shouldRun = true;
	string cmd;
	while (shouldRun)
	{
		this->displayMenu();
		getline(cin, cmd);
		if (cmd.find("add") != string::npos)  //string::npos = -1
		{
			this->uiAddPlayer(cmd);
		}
		if (cmd.find("show") != string::npos)
		{
			this->uiShowAll();
		}
		if (cmd.find("pos") != string::npos)
		{
			this->uiShowAtPosition(cmd);
		}
		if (cmd.find("update") != string::npos)
		{
			this->uiUpdateByName(cmd);
		}
		if (cmd.find("delete") != string::npos)
		{
			this->uiDeleteByName(cmd);
		}
		if (cmd.find("sort") != string::npos)
		{
			this->uiSortByNoPG();
		}
		if (cmd.find("filterNoWins") != string::npos)
		{
			this->uiShowNoWins();
		}
		if (cmd.find("exit") != string::npos)
		{
			shouldRun = false;
		}
	}
}


