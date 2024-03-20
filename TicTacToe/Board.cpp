#include "Board.h"
#include <iostream>

//Method by which the game board is drawn.

// Definition of the overloaded insertion (<<) operator
// This function is used to print the game board to an output stream
std::ostream& operator<<(std::ostream& out, const Board& board) {
    // Print the column headers
    out << "    " << 0 << "    " << 1 << "    " << 2;

    // Loop through each element in the gameBoard to print the board state
    for (int i = 0; i < 9; i++)
    {
        // At the start of each row, print the row number
        if (i == 0)
            out << std::endl << "0 ";
        if (i == 3)
            out << std::endl << "1 ";
        if (i == 6)
            out << std::endl << "2 ";

        // Print each cell with a border
        out << "| " << board[i] << " |";  // Uses the overloaded subscript operator to access gameBoard elements
    }
    out << std::endl << std::endl;

    return out;
}

