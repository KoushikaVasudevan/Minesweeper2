#include <cstdlib>
#include <ctime>
#include "minesweeper.h"
#include <iostream>
using namespace std;

int main() {
  Minesweeper game;
  game.printBoard();

  int row, col, result = 1;

  srand((unsigned int)time(NULL));
    
  while (true) {
      cout << "Enter row and column to reveal: ";
      cin >> row >> col;

      result = game.revealCell(row, col);

      game.printBoard();

      if(result == -2){
        cout << "Invalid input. Please try again.\n";
        continue;
      }
      
      else if (result == -1) {
        cout << "Game Over! You hit a mine." << endl;
        break;
      } else if (result == 0) {
        cout << "Congratulations! You cleared the board." << endl;
        break;
      }
  }
  return 0;
}