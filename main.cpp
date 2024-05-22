#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "minesweeper.h"
using namespace std;

//const int n = 5;

int main() {
  int row;
  int col;
  int GameStatus = 1;
  

  srand((unsigned int)time(NULL));
  Minesweeper m;
  m.generateBoard();

  m.printBoard();

  while (GameStatus == 1) {
    cout << "\nEnter row(0-5): ";
    cin >> row;

    cout << "Enter column(0-5): ";
    cin >> col;
    cout << "\n";

    GameStatus = m.revealCell(row, col);
    m.printBoard();
  }
  
  if(GameStatus == 0){
    cout << "\n";
    cout << "--------------------------------------" << endl;
    cout << "Congratulations! You win!" << endl;
    cout << "--------------------------------------" << endl;
  }
  else{
    cout << "\n";
    cout << "--------------------------------------" << endl;
    cout << "Game Over! You stepped on a mine. " << endl;
    cout << "--------------------------------------" << endl;
  }
}