#include "Computer.h"
#include <vector>


using namespace std;

/*
* Sztuczna inteligencja dla komputera została zrobiona tak, że komputer zaczyyna grę zawsze od jednego
* rogu, i oczekuje na ruch człowieka, dzięki czemu może on sprawdzić możliwości kolejnego ruchu,
* który wykonuje i w ruchach, gdzie możliwa jest już wygrana komputera wykonuje swój ostatni ruch,
* dzięki metodzie lastMove, a następnie sprawdza czy komputer już sięgnął po wygraną.
*
* Źródła z których niektóre możliwe kobinacje kółka i krzyżyk zostały zaczerpnięte:
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
