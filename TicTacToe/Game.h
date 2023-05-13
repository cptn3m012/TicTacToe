#ifndef TicTacToe_Game_hpp
#define TicTacToe_Game_hpp
#include <iostream>
#include <vector>

using namespace std;

/*
* Klasa Game
*/

class Game{
public:
    vector<char> gameBoard = { '1','2','3','4','5','6','7','8','9' };//wektor wypełniony znakami od 1 do 9
    friend ostream& operator<<(ostream& ,const Game& );
    int mark;
    void putOnBoard(char);
    void checkForWin();
    void defense();
    void lastMove();

};

/*
 * Klasa Abstrakcyjna
 */
class Virtual : public Game{
public:
    virtual void game() = 0;
    virtual ~Virtual() = default;
};

#endif
