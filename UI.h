#pragma once
#include "service.h"
class UI {
private:
    Service service;
    void displayMenu();
    void uiAddPlayer(string cmd);
    void uiShowAll();
    void uiShowAtPosition(string cmd);
    void uiUpdateByName(string cmd);
    void uiDeleteByName(string cmd);
    void uiSortByNoPG();
    void uiShowNoWins();
public:
    UI();
    UI(Service& service);
    void runUI();
};