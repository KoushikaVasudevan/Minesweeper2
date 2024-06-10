#include "board.h"

class Minesweeper {
private:
  int noOfMines;
  GameBoard board;
  bool firstMove;
  int firstRow, firstCol;

public:
  Minesweeper();
  void revealAdjacent(int x, int y);
  int revealCell(int x, int y);
  void printBoard();
};