//#ifndef  TicTacToe_Board_hpp
/*#define  TicTacToe_Board_hpp

#include <iostream>
#include <vector>

using namespace std;

*//*
*Klasa Board
*//*

class Board
{
public:
    vector<char> gameBoard = { '1','2','3','4','5','6','7','8','9' };//wektor wypełniony znakami od 1 do 9
    friend ostream& operator<<(ostream& , const Board& );
};
#endif*/
