#include "minesweeper.h"
#include <iostream>
using namespace std;

Minesweeper::Minesweeper() : noOfMines(n), firstMove(true) {}

void Minesweeper::revealAdjacent(int x, int y) {
  if (x < 0 || y < 0 || x >= n || y >= n || board.getTile(x, y).isRevealed()) {
    return;
  }

  board.revealTile(x, y);

  if (board.getTile(x, y).getValue() == EMPTY) {
    revealAdjacent(x - 1, y);
    revealAdjacent(x + 1, y);
    revealAdjacent(x, (y - 1));
    revealAdjacent(x, (y + 1));
    revealAdjacent(x - 1, (y - 1));
    revealAdjacent(x - 1, (y + 1));
    revealAdjacent(x + 1, (y - 1));
    revealAdjacent(x + 1, (y + 1));
  }
}

int Minesweeper::revealCell(int x, int y) {
  if (firstMove) {
    firstRow = x;
    firstCol = y;
    board.generateBoard(firstRow, firstCol, noOfMines);
    firstMove = false;
  }

  revealAdjacent(x, y);

  if (board.getTile(x, y).isMine()) {
    return -1;
  }

  int revealedCount = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board.getTile(i, j).isRevealed()) {
        revealedCount++;
      }
    }
  }

  if (revealedCount == n * n - noOfMines) {
    return 0;
  } else {
    return 1;
  }
}

void Minesweeper::printBoard() { board.printBoard(); }