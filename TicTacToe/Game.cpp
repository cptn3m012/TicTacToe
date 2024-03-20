#include "Game.h"
#include <string>

using namespace std;

/*
* Metoda polega na wstawieniu znaku gracza na plansze i walidacji danych.
* Metoda sprawdza czy putX wynosi X, ponieważ człowiek zawsze gra jako X.
* Jeżeli jest to X to w terminalu pojawia się pytanie o to, gdzie chcę
* się wstawić znak. Miejsce zostaje wczytane do zmiennej i później
* podstawione jako miejsce na planszy, która jest drukowana na początku gry.
 * Dzięki walidacji osoba nie może wpisać znaku w pole, które jest już
 * zajęte oraz jeśli będzie poza zasięgiem planszy.
*
* @param putX - wstawia krzyżyk na planszę
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
* Metoda polega na sprawdzeniu każdej możliwej wygranej przez komputer.
* Metoda sprawdza wiersze, kolumny i wiersze sprawdzając czy w jedenj linii
* nie znajdują się 3 pola zajęte przez komputer, dzięi czemu wiadomo czy komputer
* wygrał. Natomiast gdy metoda nie znajduję żadnego znaku na planszy, oznacza to,
* że na planszy nie ma już żadnego możliwego ruchu, czyli nastąpił remis.
*/

void Game::checkForWin() {
    //sprawdzenie w poziomie i pionie czy nie ma wygranej
    if (gameBoard[0] == 'O' && gameBoard[1] == 'O' && gameBoard[2] == 'O' || gameBoard[3] == 'O' && gameBoard[4] == 'O' && gameBoard[5] == 'O'
        || gameBoard[6] == 'O' && gameBoard[7] == 'O' && gameBoard[8] == 'O' || gameBoard[0] == 'O' && gameBoard[3] == 'O' && gameBoard[6] == 'O'
        || gameBoard[1] == 'O' && gameBoard[4] == 'O' && gameBoard[7] == 'O' || gameBoard[2] == 'O' && gameBoard[5] == 'O' && gameBoard[8] == 'O')
    {
        cout << "Komputer wygrał!!!!" << endl;
        cout << gameBoard << endl;
        exit(0);
    }
    //sprawdzenie w ukosie czy nie ma wygranej
    else if (gameBoard[0] == 'O' && gameBoard[4] == 'O' && gameBoard[8] == 'O' || gameBoard[6] == 'O' && gameBoard[4] == 'O' && gameBoard[2] == 'O')
    {
        cout << "Komputer wygrał!!!" << endl;
        cout << gameBoard << endl;
        exit(0);

    }
    //sprawdzenie czy na planszy żadna z liczb nie jest liczbą od 1 do 9
    else if (gameBoard[0] != '1' && gameBoard[1] != '2' && gameBoard[2] != '3' && gameBoard[3] != '4' && gameBoard[4] != '5' && gameBoard[5] != '6'
        && gameBoard[6] != '7' && gameBoard[7] != '8' && gameBoard[8] != '9')
    {
        cout << "Remis!!!" << endl;
        cout << gameBoard << endl;
        exit(0);
    }


}

/*
* Metoda polega na bronieniu się przez komputer, dzięki czemu zablokuje on każdy zagrożony ruch.
* Metoda po kolei sprawdza wiersze, kolumny oraz przękątne i gdy dwa pole są zajęte X-em przez osobę
* to w 3 polu w jednej linii komputer broni się i wstawia O.
*/

void Game::defense() {
    //sprawdzenie pierwszego wiersza
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

    // sprawdzenie drugiego wiersza
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

    //sprawdzenie trzeciego wiersza
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

    //sprawdzenie pierwszej kolumny
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

    //sprawdzenie drugiej kolumny
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

    //sprawdzenie trzeciej kolumny
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


    //sprawdzenie pierwszej przekątnej
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

    //sprawdzenie drugiej przekątnej
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
* Metoda polega na wykonywaniu ostatniego ruchu do wygrania przez komputer.
* Metoda po kolei sprawdza wiersze, kolumny i wiersze i w momencie gdy dwa pola na planszy
* w jednej linii są zajęte przez komputer, a trzecie nie jest zajęte przez człowieka to
* komputer stawia w to miejsce O, dzięki czemu ma pewną wygraną.
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
