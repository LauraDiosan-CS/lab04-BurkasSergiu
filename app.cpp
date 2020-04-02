#include <iostream>
#include "test.h"
#include "player.h"
#include "repo.h"
#include "service.h"
#include "UI.h"

using namespace std;

int main()
{
	testPlayer();
	testRepo();
	testService();
	Repo repo("PlayersIn.txt", "PlayersOut.txt");
	Service service(repo);
	UI ui(service);
	ui.runUI();
	//system("pause");
	return 0;
}