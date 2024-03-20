// Board.h
#pragma once

#include <vector>
#include <iostream>

// Declaration of the Board class
class Board {
public:
    // Constructor initializes the gameBoard with numbers 1 to 9
    std::vector<char> gameBoard{ '1','2','3','4','5','6','7','8','9' };

    // Friend declaration for the insertion stream operator
    // Allows non-member function to access private members of Board
    friend std::ostream& operator<<(std::ostream& out, const Board& board);

    // Overloads the subscript operator to provide read-write access to gameBoard elements
    char& operator[](int index) {
        return gameBoard[index];
    }

    // Overloads the subscript operator for const objects to provide read-only access to gameBoard elements
    const char& operator[](int index) const {
        return gameBoard[index];
    }
};