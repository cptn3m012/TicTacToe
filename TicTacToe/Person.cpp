#include "Person.h"
#include <iostream>

using namespace std;

/*
* Metoda polega na przywitaniu gracza oraz spytania się czy człowiek chciałby rozpocząć grę.
* Metoda jest tak skonstrułowana, że, gdy człowiek chcę rozpocząc grę staje się X-em, lecz
* gdy nie chcę jej rozpocząć to komputer ją zaczyna jako O.
*
*/

int Person::whoStart() {
    int check = 2;
    do {
        char answer;
        cout << "Witaj w Grze Kółko i Krzyżyk" << endl;
        cout << "Czy chciałbyś rozpocząć grę?" << endl;
        cout << "Gracz-X		Komputer-O" << endl;
        cout << "Wpisz T lub N w konsoli: ";
        cin >> answer;
        if (answer == 'T' || answer == 't')
            check = 0;
        else if (answer == 'N' || answer == 'n')
            check = 1;
        system("cls");
    } while (check == 2);
    return check;
}


/*
* Sztuczna inteligencja dla człowieka została zrobiona tak, że człowiek zaczyna grę gdzie chcę.
* Komputer na te ruchy odpowiada dzięki schematow i broni się na nie w większości remisujać
* lub przez głupi ruch człowieka sprawd i metodzie sprawdzającej możliwe ruchy wygranej
* zakańcza gre jak najszybcie.
*
* Źródła z których niektóre możliwe kobinacje kółka i krzyżyk zostały zaczerpnięte:
* https://www.youtube.com/watch?v=OmC07DvEayY&t=83s
* https://sites.google.com/a/g2.nctu.edu.tw/unimath/2018-02/win?tmpl=%2Fsystem%2Fapp%2Ftemplates%2Fprint%2F&showPrintDialog=1
*/

void Person::game()
{
    Game::putOnBoard('X');

    if (mark == 1 || mark == 9)
    {
        gameBoard[4] = 'O';
        Game::putOnBoard('X');
        if (mark == 9 || mark == 1)
        {
            gameBoard[5] = 'O';
            Game::putOnBoard('X');
            Game::lastMove();
            Game::checkForWin();
            Game::defense();
            Game::putOnBoard('X');
            Game::lastMove();
            Game::checkForWin();
            Game::defense();
            Game::putOnBoard('X');
            Game::lastMove();
            Game::checkForWin();

        }
        else if (mark == 6 || mark == 8)
        {
            gameBoard[8] = 'O';
            Game::putOnBoard('X');
            Game::defense();
            Game::putOnBoard('X');
            Game::lastMove();
            Game::checkForWin();
            Game::defense();
            Game::putOnBoard('X');
            Game::checkForWin();
        }
        else if (mark == 3)
        {
            Game::defense();
            Game::putOnBoard('X');
            Game::lastMove();
            Game::checkForWin();
            if (mark == 8)
            {
                gameBoard[8] = 'O';
                Game::putOnBoard('X');
                if (mark == 6)
                {
                    gameBoard[6] = 'O';
                    Game::putOnBoard('X');
                    Game::checkForWin();

                }
                else
                {
                    Game::defense();
                    Game::putOnBoard('X');
                    Game::lastMove();
                    Game::checkForWin();
                }
            }
        }
        else if (mark == 4)
        {
            Game::defense();
            Game::putOnBoard('X');
            Game::lastMove();
            Game::checkForWin();
            Game::defense();
            Game::putOnBoard('X');
            if (mark == 8)
            {
                gameBoard[5] = 'O';
                Game::putOnBoard('X');
                Game::checkForWin();

            }
        }
        else
        {
            Game::defense();
            Game::putOnBoard('X');
            Game::lastMove();
            Game::checkForWin();
            Game::defense();
            Game::putOnBoard('X');
            Game::lastMove();
            Game::checkForWin();
            Game::defense();
            Game::putOnBoard('X');
            Game::lastMove();
            Game::checkForWin();

        }

    }
    else if (mark == 7 || mark == 3)
    {
        gameBoard[4] = 'O';
        Game::putOnBoard('X');

        if (mark == 7 || mark == 3)
        {
            gameBoard[3] = 'O';
            Game::putOnBoard('X');
            Game::lastMove();
            Game::defense();
            Game::checkForWin();
            Game::putOnBoard('X');
            Game::lastMove();
            Game::defense();
            Game::checkForWin();
            Game::putOnBoard('X');
            Game::lastMove();
            Game::defense();
            Game::checkForWin();
        }
        else
        {
            for (int i = 0; i <= 3; i++)
            {
                Game::defense();
                Game::putOnBoard('X');
                Game::lastMove();
                Game::checkForWin();
            }
        }

    }
    else if (mark == 5)
    {
        gameBoard[0] = 'O';
        Game::putOnBoard('X');

        if (mark == 3)
        {
            Game::defense();
            Game::putOnBoard('X');
            Game::lastMove();
            Game::defense();
            Game::checkForWin();
            Game::putOnBoard('X');
            Game::lastMove();
            Game::defense();
            Game::checkForWin();
            Game::putOnBoard('X');
            Game::lastMove();
            Game::defense();
            Game::checkForWin();
        }
        else
        {
            for (int i = 0; i <= 3; i++)
            {
                Game::defense();
                Game::putOnBoard('X');
                Game::lastMove();
                Game::checkForWin();
            }
        }

    }
    else if (mark == 2 || mark == 8)
    {
        gameBoard[4] = 'O';
        Game::putOnBoard('X');

        if (mark == 2 || mark == 8)
        {
            gameBoard[2] = 'O';
            Game::putOnBoard('X');
            Game::defense();
            Game::checkForWin();
            Game::putOnBoard('X');
            Game::lastMove();
            Game::checkForWin();
            Game::defense();
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
            Game::lastMove();
            Game::checkForWin();

        }

    }
    else if (mark == 4 || mark == 6)
    {
        gameBoard[4] = 'O';
        Game::putOnBoard('X');

        if (mark == 4 || mark == 6)
        {
            gameBoard[2] = 'O';
            Game::putOnBoard('X');
            Game::lastMove();
            Game::defense();
            Game::checkForWin();
            Game::putOnBoard('X');
            Game::lastMove();
            Game::checkForWin();
            Game::defense();
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
            Game::lastMove();
            Game::checkForWin();

        }

    }



}
