#include <iostream>
#include "Person.h"
#include "Game.h"
#include "Computer.h"
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Person person;
    Computer computer;
    Game play;
    int checkStart;

    Player* ptr = nullptr; //zerowanie wskaźnika

    checkStart = person.whoStart();

    do
    {
        if (checkStart == 0)
            ptr = &person;
        else
            ptr = &computer;

        ptr->game();

    } while (checkStart);

}
