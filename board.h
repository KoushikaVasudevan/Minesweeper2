#include "tile.h"

const int n = 9;

class GameBoard {
private:
  Tile grid[n][n];

public:
  GameBoard();
  void generateBoard(int firstRow, int firstCol, int noOfMines);
  void incrementCells(int x, int y);
  Tile &getTile(int x, int y);
  void revealTile(int x, int y);
  void printBoard() const;
};