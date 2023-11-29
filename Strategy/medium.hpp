#include "diffucltyLevel.hpp"
#include <bits/stdc++.h>
#include "../minMaxAlgorithm/algorithm.hpp"

using namespace std;

class medium : public diffucltyLevel
{
private:
public:
    virtual vector<char> play(vector<char> board)
    {

        int numofX = 0;
        int numofO = 0;

        for (int i = 0; i < 8; i++)
        {
            if (board[i] == 'x')
            {
                numofX++;
            }
            else if (board[i] == 'o')
            {
                numofO++;
            }
        }

        score ss;
        min_max mm(4);

        board[mm.decision(board, numofX > numofO ? 'o' : 'x')] = numofX > numofO ? 'o' : 'x';
        return board;
    }
};
