#ifndef  TicTacToe_Computer_hpp
#define  TicTacToe_Computer_hpp
#include "Game.h"
#include <vector>

using namespace std;

/*
* Class Computer
*
* This class represents the computer player in the game. It inherits from the Game class,
* which contains virtual methods that the Computer class must override, such as the game method.
* This setup allows for polymorphic behavior when interacting with instances of Computer as Player.
*/

class Computer : public Player
{
public:
    // Override the game method to provide the specific AI logic for the computer player.
    void game() override; 
};
#endif
