#include "board.h"
#include <iostream>
using namespace std;

GameBoard::GameBoard() {}

void GameBoard::generateBoard(int firstRow, int firstCol, int noOfMines) {
    int x, y;
    for (int i = 0; i < noOfMines; i++) {
        do {
            x = rand() % n;
            y = rand() % n;
        } while ((x == firstRow && y == firstCol) || grid[x][y].isMine());

        grid[x][y].placeMine();

        incrementCells((x - 1), y);
        incrementCells((x + 1), y);
        incrementCells(x, (y - 1));
        incrementCells(x, (y + 1));
        incrementCells((x - 1), (y - 1));
        incrementCells((x - 1), (y + 1));
        incrementCells((x + 1), (y - 1));
        incrementCells((x + 1), (y + 1));
    }
}

void GameBoard::incrementCells(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) {
        return;
    }
    grid[x][y].incrementNumber();
}

Tile& GameBoard::getTile(int x, int y) {
    return grid[x][y];
}

void GameBoard::revealTile(int x, int y) {
    grid[x][y].reveal();
}

void GameBoard::printBoard() const {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char cell;
            if (!grid[i][j].isRevealed()) {
                cell = '-';
            } else {
                if (grid[i][j].isMine()) {
                    cell = 'M';
                } else if (grid[i][j].getValue() == EMPTY) {
                    cell = '0';
                } else {
                    cell = grid[i][j].getNumber() + '0';
                }
            }
            cout << cell << " | ";
        }
        cout << "\n";
    }
}