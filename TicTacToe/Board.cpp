/*#include "Board.h"
#include <iostream>

using namespace std;

*//*
* Metoda, dzięki, której rysowana jest plansza do gry.
* W danej metodzie operator << został przeciążony.
*//*

ostream& operator<< (ostream& out, const Board& obj){
    out << "    " << 0 << "    " << 1 << "    " << 2;
    for (int i = 0; i < 9; i++)
    {
        if (i == 0)
            out << endl << "0 ";
        if (i == 3)
            out << endl << "1 ";
        if (i == 6)
            out << endl << "2 ";

        out << "| " << obj.gameBoard.at(i) << " |";
    }
    out << endl << endl;
    return out;
}*/
