#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int n = 5;

class Minesweeper {
private:
    int noOfMines;
    int grid[n][n]{};
    set<pair<int, int>> revealedCells;
    bool firstMove;
    int firstRow, firstCol;

public:
    Minesweeper() : noOfMines(n), firstMove(true) {}

    void generateBoard() {
        int x, y;
        for (int i = 0; i < noOfMines; i++) {
            do {
                x = rand() % n;
                y = rand() % n;
            } while ((x == firstRow && y == firstCol) || grid[x][y] == -1);

            grid[x][y] = -1;

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

    void incrementCells(int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= n) {
            return;
        }
        if (grid[x][y] < 0) {
            return;
        } else if (grid[x][y] < 9) {
            grid[x][y] += 1;
        } else {
            grid[x][y] = 1;
        }
    }

    void revealAdjacent(int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= n || isCellRevealed(x, y)) {
            return;
        }

        revealedCells.insert({x, y});

        if (grid[x][y] == 0) {
            revealAdjacent(x - 1, y);
            revealAdjacent(x + 1, y);
            revealAdjacent(x, y - 1);
            revealAdjacent(x, y + 1);
            revealAdjacent(x - 1, y - 1);
            revealAdjacent(x - 1, y + 1);
            revealAdjacent(x + 1, y - 1);
            revealAdjacent(x + 1, y + 1);
        }
    }

    int revealCell(int x, int y) {
        if (firstMove) {
            firstRow = x;
            firstCol = y;
            generateBoard();
            firstMove = false;
        }

        revealAdjacent(x, y);

        if (grid[x][y] < 0) {
            return -1;
        }

        if (revealedCells.size() == n * n - noOfMines) {
            return 0;
        } else {
            return 1;
        }
    }

    bool isCellRevealed(int row, int col) {
        return revealedCells.find({row, col}) != revealedCells.end();
    }

    void printBoard() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char cell;
                if (!isCellRevealed(i, j)) {
                    cell = '-';
                } else {
                    if (grid[i][j] < 0) {
                        cell = 'M';
                    } else {
                        cell = grid[i][j] + '0';
                    }
                }
                cout << cell << " | ";
            }
            cout << "\n";
        }
    }
};