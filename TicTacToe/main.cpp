#include <iostream>
#include "Person.h"
#include "Game.h"
#include "Computer.h"
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);  // Set the console output to UTF-8 to support Polish characters
    Person person;
    Computer computer;
    Game play;

    int checkStart;

    // Initialize a pointer of type Player to null. This will be used to point to either the person or computer.
    Player* ptr = nullptr;

    checkStart = person.whoStart();

    do
    {
        // Determine who is playing this round based on checkStart
        if (checkStart == 0)
            ptr = &person;
        else
            ptr = &computer;

        // Execute the game method for the current player
        ptr->game();

    } while (checkStart); 

}
