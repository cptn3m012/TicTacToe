#pragma once

#include "Board.h" 
#include <iostream>

/**
 * The Game class
 *
 * This class represents the game logic for Tic-Tac-Toe. It includes methods
 * for making moves on the board, checking for wins, implementing defensive
 * strategies, and determining the last move. The game board itself is an instance
 * of the Board class, which manages the grid state.
 */

class Game {
public:
    Board gameBoard;        // Instance of Board to manage the game's board state.

    int mark{};             // Variable to track the current player's mark position on the board.
    void putOnBoard(char);  // Method for placing a mark ('X' or 'O') on the board and validating the input.
    void checkForWin();     // Method to check if there's a winning condition on the board.
    void defense();         // Method for the computer to defend against the player's moves.
    void lastMove();        // Method to perform the computer's last move to win the game or block the player.

};

/**
 * Abstract Class: Player
 *
 * This class serves as a base class for different types of players (human or computer)
 * in the Tic-Tac-Toe game. It declares the game method as virtual and pure (0), making
 * Player an abstract class. Derived classes are required to implement the game method.
 */
class Player : public Game {
public:
    virtual void game() = 0;      // Pure virtual function to be implemented by derived classes
    virtual ~Player() = default;  // Virtual destructor for safe polymorphic deletions.
};

