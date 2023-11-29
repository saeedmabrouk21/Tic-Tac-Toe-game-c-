#include <bits/stdc++.h>
#include "../command/invoker.hpp"
#include "../command/Icommand.hpp"
#include "../command/tic_tac_toeDevice.hpp"
#include "../command/tic_tac_toePlayCommand.hpp"
#include "../command/tic_tac_toeResetCommand.hpp"
#include "../command/tic_tac_toeSaveCommand.hpp"
#include "../command/tic_tac_toeLoadCommand.hpp"
#include <conio.h>
#include <iostream>

using namespace std;
class frontEnd
{
private:
  tic_tac_toeDevice td;
  vector<char> board = {'1', '2', '3',
                        '4', '5', '6',
                        '7', '8', '9'};

  playCommand pc{board, &td};
  resetCommand rc{board, &td};
  saveCommand sc{board, &td};
  loadCommand lc{board, &td};
  invoker tic_tac_toeInvoker;
  bool turn; // true => x true , false => o turn
  void drawBoard(void);
  bool whoseTurn(vector<char>);

public:
  void startGame(void);
};

void frontEnd::drawBoard()
{

  system("color 0c");
  std::cout << "-------" << endl;
  std::cout << "|" << board[0] << "|" << board[1] << "|" << board[2] << "|" << endl;
  std::cout << "-------" << endl;
  std::cout << "|" << board[3] << "|" << board[4] << "|" << board[5] << "|" << endl;
  std::cout << "-------" << endl;
  std::cout << "|" << board[6] << "|" << board[7] << "|" << board[8] << "|" << endl;
  std::cout << "-------" << endl;
  turn ? std::cout << "x turn" << endl : std::cout << "o turn" << endl;
  std::cout << "-------" << endl;
}
bool frontEnd::whoseTurn(vector<char> board)
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

  return numofO == numofX;
}

void frontEnd::startGame(void)
{
  while (true)
  {
    board = {'1', '2', '3',
             '4', '5', '6',
             '7', '8', '9'};
    short order_1;
    system("cls");
    std::cout << "Enter 1 or 2" << endl
              << "1.Start New Game" << endl
              << "2.Load Game" << endl
              << "3.Exit Game" << endl;
    cin >> order_1;
    while (!(order_1 == 1 || order_1 == 2 || order_1 == 3))
    {

      std::cout << "Enter a valid number : ";
      cin >> order_1;
    }
    // start new game
    if (order_1 == 1)
    {
      system("cls");
      std::cout << "Enter 1, 2 or 3" << endl
                << "1.Easy" << endl
                << "2.Medium" << endl
                << "3.Hard" << endl;
      short order_2;
      cin >> order_2;
      while (!(order_2 == 1 || order_2 == 2 || order_2 == 3))
      {
        std::cout << "Enter a valid number : ";
        cin >> order_2;
      }
      if (order_2 == 1)
      {
        td.setDiffucltyLevel('e');
      }
      else if (order_2 == 2)
      {
        td.setDiffucltyLevel('m');
      }
      else if (order_2 == 3)
      {
        td.setDiffucltyLevel('h');
      }
      system("cls");
      std::cout << "Enter 1 or 2" << endl
                << "1.X" << endl
                << "2.O" << endl;
      short order_3;
      cin >> order_3;
      while (!(order_3 == 1 || order_3 == 2))
      {
        std::cout << "Enter a valid number : ";
        cin >> order_3;
      }
      if (order_3 == 1)
      {
        turn = true;
      }
      else if (order_3 == 2)
      {
        turn = false;
        pc.setBoard(board);
        system("cls");
        drawBoard();
        board = tic_tac_toeInvoker.excuteCommand(&pc);
      }
    }
    // load game
    else if (order_1 == 2)
    {

      system("cls");
      std::cout << "Enter game number : ";
      short gamenumber;
      std::cin >> gamenumber;
      lc.setBoard({(char)gamenumber});
      board = tic_tac_toeInvoker.excuteCommand(&lc);
      turn = whoseTurn(board);
    }
    else if (order_1 == 3)
    {
      break;
    }
    string position;
    while (board.size() == 9)
    {
      system("cls");
      std::cout << "Main Menu enter 0" << endl;
      drawBoard();
      std::cout << "Enter the number : ";

      cin >> position;
      if (position == "0")
      {
        int option;
        system("cls");
        std::cout << "Enter 1,2 or 3" << endl
                  << "1.reset" << endl
                  << "2.Load Game" << endl
                  << "3.Save Game" << endl
                  << "4.Back to Game" << endl;
        short order_4;
        cin >> order_4;
        while (!(order_4 == 1 || order_4 == 2 || order_4 == 3 || order_4 == 4))
        {
          std::cout << "Enter a valid number : ";
          cin >> order_4;
        }
        if (order_4 == 1)
        {
          board = tic_tac_toeInvoker.excuteCommand(&rc);
        }
        else if (order_4 == 2)
        {
          system("cls");
          std::cout << "Enter game number : ";
          short gamenumber;
          std::cin >> gamenumber;
          lc.setBoard({(char)gamenumber});
          board = tic_tac_toeInvoker.excuteCommand(&lc);
          turn = whoseTurn(board);
        }
        else if (order_4 == 3)
        {
          sc.setBoard(board);
          tic_tac_toeInvoker.excuteCommand(&sc);
        }
        else if (order_4 == 4)
        {
        }
      }
      else
      {
        while (!(position[0] >= '1' && position[0] <= '9') || board[position[0] - '0' - 1] == 'x' || board[position[0] - '0' - 1] == 'o')
        {
          std::cout << "Enter a valid number : ";
          cin >> position;
        }
        board[position[0] - '0' - 1] = 'x';
        pc.setBoard(board);
        system("cls");
        drawBoard();
        board = tic_tac_toeInvoker.excuteCommand(&pc);
      }
    }
    if (board[0] == 'x')
    {
      std::cout << "X wins" << endl;
    }
    else if (board[0] == 'o')
    {
      std::cout << "O wins" << endl;
    }
    else
    {
      std::cout << "No Wins :\(" << endl;
    }
    cout << "Click any key to continue ..";
    while (getchar() != '\n')
      ;
    while (getchar() != '\n')
      ;
  }
}