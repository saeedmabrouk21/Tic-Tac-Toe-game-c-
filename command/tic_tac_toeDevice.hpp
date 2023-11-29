#ifndef sl
#define sl
#include <bits/stdc++.h>
#include "../Strategy/diffucltyLevel.hpp"
#include "../Strategy/easy.hpp"
#include "../Strategy/medium.hpp"
#include "../Strategy/hard.hpp"
using namespace std;

class tic_tac_toeDevice
{
public:
    void setDiffucltyLevel(char diffuclt);
    vector<char> play(vector<char> board);
    vector<char> reset(vector<char> board);
    vector<char> save(vector<char> board);
    vector<char> load(vector<char> board);
    tic_tac_toeDevice(void)
    {

        std::ifstream inFile("maxnumber.txt");

        if (inFile.is_open())
        {
            inFile >> gameNumber;
            inFile.close();
        }
    }

private:
    int gameNumber;
    easy e;
    medium m;
    hard h;
    diffucltyLevel *dl;
    vector<char> whoWin(vector<char>);
    vector<vector<short>> winPositions = {{0, 1, 2},
                                          {3, 4, 5},
                                          {6, 7, 8},
                                          {0, 4, 8},
                                          {2, 4, 6},
                                          {0, 3, 6},
                                          {1, 4, 7},
                                          {2, 5, 8}};
};

void tic_tac_toeDevice::setDiffucltyLevel(char diffuclt)
{

    if (diffuclt == 'e' || diffuclt == 'E')
    {
        dl = &e;
    }
    if (diffuclt == 'm' || diffuclt == 'M')
    {
        dl = &m;
    }
    if (diffuclt == 'h' || diffuclt == 'H')
    {
        dl = &h;
    }
}

vector<char> tic_tac_toeDevice::play(vector<char> board)
{
    vector<char> res = whoWin(board);
    if (res == board)
    {
        board = dl->play(board);
        res = whoWin(board);
    }
    return res;
}
vector<char> tic_tac_toeDevice::reset(vector<char> board)
{
    return {'1', '2', '3',
            '4', '5', '6',
            '7', '8', '9'};
}

vector<char> tic_tac_toeDevice::save(vector<char> board)
{
    gameNumber++;
    fstream file;
    file.open("game.txt", std::ios::app);
    string str(board.begin(), board.end());
    file << "g" << gameNumber << " " << str << endl;
    file.close();
    std::ofstream outFile("maxnumber.txt");
    if (outFile.is_open())
    {
        outFile << gameNumber << std::endl;
        outFile.close();
    }

    return {0};
}

vector<char> tic_tac_toeDevice::load(vector<char> board)
{
    int gameNumber = board[0];
    board = vector<char>(9);
    ifstream cin("game.txt");
    string str;

    for (int i = 1; i <= gameNumber; i++)
    {
        getline(cin, str);

        if (str[2] == ' ' && str[1] - '0' == gameNumber)
        {

            break;
        }
        else if (str[3] == ' ' && stoi(str.substr(1, 2)) == gameNumber)
        {
            break;
        }
    }
    int offset;
    if (gameNumber > 9)
    {
        offset = 4;
    }
    else
    {
        offset = 3;
    }
    for (int j = 0; j < 9; j++)
    {
        board[j] = str[j + offset];
    }
    return board;
}

// checks if x or o wins or equal
// if x wins returns {x}
// if o wins returns {o}
// if equals returns {e}
vector<char> tic_tac_toeDevice::whoWin(vector<char> board)
{
    for (int i = 0; i < 8; i++)
    {
        if (board[winPositions[i][0]] == board[winPositions[i][1]] && board[winPositions[i][0]] == board[winPositions[i][2]])
        {
            if (board[winPositions[i][0]] == 'x')
            {
                return {'x'};
            }
            else
            {
                return {'o'};
            }
        }
    }
    // check no empty positions
    for (auto x : board)
    {
        if (x != 'x' && x != 'o')
        {
            return board;
        }
    }
    return {'e'};
}
#endif
