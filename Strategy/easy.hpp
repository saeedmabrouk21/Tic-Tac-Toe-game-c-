#include "./diffucltyLevel.hpp"
#include <bits/stdc++.h>
#include <ctime>
using namespace std;
class easy : public diffucltyLevel
{
private:
public:
    virtual vector<char> play(vector<char> board)
    {
        int numofX = 0;
        int numofO = 0;
        int next = -1;

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
            else if (next == -1)
            {
                next = i;
            }
        }
        board[next] = numofX > numofO ? 'o' : 'x';
        return board;
    }
    // ~Sharm();
};
