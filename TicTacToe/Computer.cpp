#include "Computer.h"
#include <vector>


using namespace std;

/*
* The computer's artificial intelligence is strategically designed to initiate the game from a corner position.
* This initial placement allows the AI to observe and respond to the human player's subsequent move,
* facilitating an opportunity to evaluate and execute a counter-strategy. The AI anticipates sequences that
* lead to a potential victory and capitalizes on these moments by deploying the lastMove method.
* Following each move, the AI conducts a win check to ascertain if the recent move has culminated in victory.
*
*  Sources from which some possible cobinations of Tic Tac Toe were taken::
* https://www.youtube.com/watch?v=OmC07DvEayY&t=83s
* https://sites.google.com/a/g2.nctu.edu.tw/unimath/2018-02/win?tmpl=%2Fsystem%2Fapp%2Ftemplates%2Fprint%2F&showPrintDialog=1
*/

void Computer::game()
{
    gameBoard[8] = 'O';
    Game::putOnBoard('X');
    system("cls");
    if (mark == 5)
    {
        gameBoard[0] = 'O';
        Game::putOnBoard('X');

        if (mark == 7)
        {
            gameBoard[2] = 'O';
            Game::putOnBoard('X');
            Game::lastMove();
            Game::checkForWin();
        }
        else if (mark == 3)
        {
            gameBoard[6] = 'O';
            Game::putOnBoard('X');
            Game::lastMove();
            Game::checkForWin();
        }
        else
        {
            Game::defense();
            Game::putOnBoard('X');
            Game::lastMove();
            Game::checkForWin();
            Game::defense();
            Game::putOnBoard('X');
            Game::defense();
            Game::checkForWin();
        }
    }
    else if (mark == 3)
    {
        gameBoard[6] = 'O';
        Game::putOnBoard('X');
        Game::lastMove();
        Game::checkForWin();

        if (mark == 8)
        {
            gameBoard[0] = 'O';
            Game::putOnBoard('X');
            Game::lastMove();
            Game::checkForWin();
        }
    }
    else if (mark == 1)
    {
        gameBoard[2] = 'O';
        Game::putOnBoard('X');

        if (mark == 6)
        {
            gameBoard[6] = 'O';
            Game::putOnBoard('X');
            Game::lastMove();
            Game::checkForWin();
        }
        else
        {
            Game::lastMove();
            Game::checkForWin();
        }
    }
    else if (mark == 7)
    {
        gameBoard[2] = 'O';
        Game::putOnBoard('X');

        if (mark == 6)
        {
            gameBoard[0] = 'O';
            Game::putOnBoard('X');
            Game::lastMove();
            Game::checkForWin();
        }
        else
        {
            Game::lastMove();
            Game::checkForWin();
        }
    }
    else if (mark == 4 || mark == 6)
    {
        gameBoard[4] = 'O';
        Game::putOnBoard('X');

        if (mark == 1)
        {
            gameBoard[6] = 'O';
            Game::putOnBoard('X');
            Game::lastMove();
            Game::checkForWin();
        }
        else
        {
            Game::lastMove();
            Game::checkForWin();
        }
    }
    else if (mark == 2 || mark == 8)
    {
        gameBoard[4] = 'O';
        Game::putOnBoard('X');

        if (mark == 1)
        {
            gameBoard[2] = 'O';
            Game::putOnBoard('X');
            Game::lastMove();
            Game::checkForWin();
        }
        else
        {
            Game::lastMove();
            Game::checkForWin();
        }
    }


}
