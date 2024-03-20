#include "Game.h"
#include <string>

using namespace std;

/*
* This method is responsible for allowing a player to place their mark ('X' for human players)
* on the game board and ensures the input data is validated. The method checks if the chosen
* position is within the acceptable range and not already occupied. If the input is valid,
* the mark is placed on the board; otherwise, the user is prompted to try again.
*
* @param putX - the character 'X' to be placed on the game board by the human player.
*/

void Game::putOnBoard(char putX) {
    bool error = false;
    do {
        cout << gameBoard;
        error = false;

        cout << "Gdzie chcesz swój znak? ";
        cin >> mark;
        cout << endl;

        if (mark < 0 || mark>9 || gameBoard[mark - 1] == 'X' || gameBoard[mark - 1] == 'O') {
            error = true;
            cout << "Nie możesz postawić znaku w tym miejscu" << endl;
            cout << "Spróbuj jeszcze raz" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            gameBoard[mark - 1] = 'X';
            cout << endl << endl;
        }
    } while (error);

    system("cls");
}

/*
* This method checks for a win condition by examining all possible winning combinations.
* It checks rows, columns, and diagonals to determine if any line contains three 'O's,
* which would mean a win for the computer. If no available moves are left on the board
* and no winner has been declared, the result is a draw.
*/

void Game::checkForWin() {
    //checking horizontally and vertically for wins
    if (gameBoard[0] == 'O' && gameBoard[1] == 'O' && gameBoard[2] == 'O' || gameBoard[3] == 'O' && gameBoard[4] == 'O' && gameBoard[5] == 'O'
        || gameBoard[6] == 'O' && gameBoard[7] == 'O' && gameBoard[8] == 'O' || gameBoard[0] == 'O' && gameBoard[3] == 'O' && gameBoard[6] == 'O'
        || gameBoard[1] == 'O' && gameBoard[4] == 'O' && gameBoard[7] == 'O' || gameBoard[2] == 'O' && gameBoard[5] == 'O' && gameBoard[8] == 'O')
    {
        cout << "Komputer wygrał!!!!" << endl;
        cout << gameBoard << endl;
        exit(0);
    }
    //checking in the diagonal for winnings
    else if (gameBoard[0] == 'O' && gameBoard[4] == 'O' && gameBoard[8] == 'O' || gameBoard[6] == 'O' && gameBoard[4] == 'O' && gameBoard[2] == 'O')
    {
        cout << "Komputer wygrał!!!" << endl;
        cout << gameBoard << endl;
        exit(0);

    }
    //checking that none of the numbers on the board is a number from 1 to 9
    else if (gameBoard[0] != '1' && gameBoard[1] != '2' && gameBoard[2] != '3' && gameBoard[3] != '4' && gameBoard[4] != '5' && gameBoard[5] != '6'
        && gameBoard[6] != '7' && gameBoard[7] != '8' && gameBoard[8] != '9')
    {
        cout << "Remis!!!" << endl;
        cout << gameBoard << endl;
        exit(0);
    }
}

/*
* The method is part of the computer's defensive strategy. It scans rows, columns, and diagonals
* to find any two 'X's without a third, blocking these lines by placing an 'O'. This prevents the
* human player from winning on their next move and positions the computer to potentially win.
*/

void Game::defense() {
    //checking the first line
    if (gameBoard[0] == 'X' && gameBoard[1] == 'X')
    {
        gameBoard[2] = 'O';
    }
    else if (gameBoard[0] == 'X' && gameBoard[2] == 'X')
    {
        gameBoard[1] = 'O';
    }
    else if (gameBoard[1] == 'X' && gameBoard[2] == 'X')
    {
        gameBoard[0] = 'O';
    }

    //checking second line
    else if (gameBoard[3] == 'X' && gameBoard[4] == 'X')
    {
        gameBoard[5] = 'O';
    }
    else if (gameBoard[3] == 'X' && gameBoard[5] == 'X')
    {
        gameBoard[4] = 'O';
    }
    else if (gameBoard[4] == 'X' && gameBoard[5] == 'X')
    {
        gameBoard[3] = 'O';
    }

    //checking the third line
    else if (gameBoard[6] == 'X' && gameBoard[7] == 'X')
    {
        gameBoard[8] = 'O';
    }
    else if (gameBoard[6] == 'X' && gameBoard[8] == 'X')
    {
        gameBoard[7] = 'O';
    }
    else if (gameBoard[7] == 'X' && gameBoard[8] == 'X')
    {
        gameBoard[6] = 'O';
    }

    //checking the first column
    if (gameBoard[0] == 'X' && gameBoard[3] == 'X')
    {
        gameBoard[6] = 'O';
    }
    else if (gameBoard[0] == 'X' && gameBoard[6] == 'X')
    {
        gameBoard[3] = 'O';
    }
    else if (gameBoard[3] == 'X' && gameBoard[6] == 'X')
    {
        gameBoard[0] = 'O';
    }

    //checking second column
    else if (gameBoard[1] == 'X' && gameBoard[4] == 'X')
    {
        gameBoard[7] = 'O';
    }
    else if (gameBoard[1] == 'X' && gameBoard[7] == 'X')
    {
        gameBoard[4] = 'O';
    }
    else if (gameBoard[4] == 'X' && gameBoard[7] == 'X')
    {
        gameBoard[1] = 'O';
    }

    //checking the third column
    else if (gameBoard[2] == 'X' && gameBoard[5] == 'X')
    {
        gameBoard[8] = 'O';
    }
    else if (gameBoard[2] == 'X' && gameBoard[8] == 'X')
    {
        gameBoard[5] = 'O';
    }
    else if (gameBoard[5] == 'X' && gameBoard[8] == 'X')
    {
        gameBoard[2] = 'O';
    }


    //checking the first diagonal
    if (gameBoard[0] == 'X' && gameBoard[4] == 'X')
    {
        gameBoard[8] = 'O';
    }
    else if (gameBoard[0] == 'X' && gameBoard[8] == 'X')
    {
        gameBoard[4] = 'O';
    }
    else if (gameBoard[4] == 'X' && gameBoard[8] == 'X')
    {
        gameBoard[0] = 'O';
    }

    //checking the second diagonal
    else if (gameBoard[2] == 'X' && gameBoard[4] == 'X')
    {
        gameBoard[6] = 'O';
    }
    else if (gameBoard[2] == 'X' && gameBoard[6] == 'X')
    {
        gameBoard[4] = 'O';
    }
    else if (gameBoard[4] == 'X' && gameBoard[6] == 'X')
    {
        gameBoard[2] = 'O';
    }

}


/*
* This method is used by the computer to perform the final move for a win. It checks rows,
* columns, and diagonals, and when it finds two 'O's in line, with the third space not
* occupied by an 'X', the computer places an 'O' to secure the win.
*/

void Game::lastMove() {
    if (gameBoard[0] == 'O' && gameBoard[1] == 'O' && gameBoard[2] != 'X')
    {
        gameBoard[2] = 'O';
    }
    else if (gameBoard[3] == 'O' && gameBoard[4] == 'O' && gameBoard[5] != 'X')
    {
        gameBoard[5] = 'O';
    }
    else if (gameBoard[6] == 'O' && gameBoard[7] == 'O' && gameBoard[8] != 'X')
    {
        gameBoard[8] = 'O';
    }
    else if (gameBoard[1] == 'O' && gameBoard[2] == 'O' && gameBoard[0] != 'X')
    {
        gameBoard[0] = 'O';
    }
    else if (gameBoard[4] == 'O' && gameBoard[5] == 'O' && gameBoard[3] != 'X')
    {
        gameBoard[3] = 'O';
    }
    else if (gameBoard[7] == 'O' && gameBoard[8] == 'O' && gameBoard[6] != 'X')
    {
        gameBoard[6] = 'O';
    }
    else if (gameBoard[0] == 'O' && gameBoard[2] == 'O' && gameBoard[1] != 'X')
    {
        gameBoard[1] = 'O';
    }
    else if (gameBoard[3] == 'O' && gameBoard[5] == 'O' && gameBoard[4] != 'X')
    {
        gameBoard[4] = 'O';
    }
    else if (gameBoard[6] == 'O' && gameBoard[8] == 'O' && gameBoard[7] != 'X')
    {
        gameBoard[7] = 'O';
    }
    else if (gameBoard[0] == 'O' && gameBoard[3] == 'O' && gameBoard[6] != 'X')
    {
        gameBoard[6] = 'O';
    }
    else if (gameBoard[1] == 'O' && gameBoard[4] == 'O' && gameBoard[7] != 'X')
    {
        gameBoard[7] = 'O';
    }
    else if (gameBoard[2] == 'O' && gameBoard[5] == 'O' && gameBoard[8] != 'X')
    {
        gameBoard[8] = 'O';
    }
    else if (gameBoard[6] == 'O' && gameBoard[3] == 'O' && gameBoard[0] != 'X')
    {
        gameBoard[0] = 'O';
    }
    else if (gameBoard[7] == 'O' && gameBoard[4] == 'O' && gameBoard[1] != 'X')
    {
        gameBoard[1] = 'O';
    }
    else if (gameBoard[8] == 'O' && gameBoard[5] == 'O' && gameBoard[2] != 'X')
    {
        gameBoard[2] = 'O';
    }
    else if (gameBoard[6] == 'O' && gameBoard[0] == 'O' && gameBoard[3] != 'X')
    {
        gameBoard[3] = 'O';
    }
    else if (gameBoard[7] == 'O' && gameBoard[1] == 'O' && gameBoard[4] != 'X')
    {
        gameBoard[4] = 'O';
    }
    else if (gameBoard[2] == 'O' && gameBoard[8] == 'O' && gameBoard[5] != 'X')
    {
        gameBoard[5] = 'O';
    }
    else if (gameBoard[0] == 'O' && gameBoard[8] == 'O' && gameBoard[4] != 'X')
    {
        gameBoard[4] = 'O';
    }
    else if (gameBoard[6] == 'O' && gameBoard[2] == 'O' && gameBoard[4] != 'X')
    {
        gameBoard[4] = 'O';
    }
    else if (gameBoard[0] == 'O' && gameBoard[4] == 'O' && gameBoard[8] != 'X')
    {
        gameBoard[8] = 'O';
    }
    else if (gameBoard[6] == 'O' && gameBoard[4] == 'O' && gameBoard[2] != 'X')
    {
        gameBoard[2] = 'O';
    }
    else if (gameBoard[8] == 'O' && gameBoard[4] == 'O' && gameBoard[0] != 'X')
    {
        gameBoard[0] = 'O';
    }
    else if (gameBoard[2] == 'O' && gameBoard[4] == 'O' && gameBoard[6] != 'X')
    {
        gameBoard[6] = 'O';
    }

}
