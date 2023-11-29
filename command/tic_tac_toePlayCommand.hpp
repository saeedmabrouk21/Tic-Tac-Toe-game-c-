#include "tic_tac_toeDevice.hpp"
#include "Icommand.hpp"
#include <bits/stdc++.h>
using namespace std;
class playCommand : public Icommand
{
private:
    /* data */
    tic_tac_toeDevice *td;
    vector<char> board;

public:
    playCommand(vector<char> board, tic_tac_toeDevice *td) : board(board), td(td)
    {
    }
    void setBoard(vector<char> newBoard)
    {
        board = newBoard;
    }

    vector<char> excute()
    {
        return td->play(board);
    }
};
