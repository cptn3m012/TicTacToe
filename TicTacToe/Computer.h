#ifndef  TicTacToe_Computer_hpp
#define  TicTacToe_Computer_hpp
#include "Game.h"
#include <vector>

using namespace std;

/*
* Klasa Computer
*/

class Computer : public Player
{
public:
    void game() override; //przesłoniona metoda
};
#endif
