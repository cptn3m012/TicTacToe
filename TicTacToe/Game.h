#pragma once

#include "Board.h" // Dołącz nową klasę Board
#include <iostream>

/*
* Klasa Game
*/

class Game {
public:
    Board gameBoard;

    int mark{};
    void putOnBoard(char);
    void checkForWin();
    void defense();
    void lastMove();

};

/*
 * Klasa Abstrakcyjna
 */
class Player : public Game {
public:
    virtual void game() = 0;
    virtual ~Player() = default;
};

