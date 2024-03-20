#ifndef TicTacToe_Player_hpp
#define TicTacToe_Player_hpp

#include "Game.h"

using namespace std;

/*
* Klasa Person
*/
class Person : public Player
{
public:
    int whoStart();
    void game() override;//przesłoniona metoda
};
#endif
