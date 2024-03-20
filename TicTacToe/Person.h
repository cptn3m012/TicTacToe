#ifndef TicTacToe_Player_hpp
#define TicTacToe_Player_hpp

#include "Game.h"

using namespace std;

/*
 * Class Person
 *
 * This class represents the human player in the Tic-Tac-Toe game. It inherits from the Game class,
 * indicating that it must implement the virtual game method defined in the base class. The Person class
 * provides specific implementations for a human player, including deciding who starts the game and making
 * moves on the game board.
 */
class Person : public Player
{
public:
    int whoStart();         // Determines who starts the game - the human player or the computer.
    void game() override;   // Contains the logic for the human player's moves during the game.
};
#endif
