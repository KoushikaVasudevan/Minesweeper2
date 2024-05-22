#include <bits/stdc++.h>
#include <iostream>

const int n = 5;

class Minesweeper {
private:
  int noOfMines;
  int grid[n][n]{};
  std::vector<int> revealedRows;
  std::vector<int> revealedCols;

public:
  Minesweeper() { noOfMines = n; }

  void generateBoard() {
    int x;
    int y;
    for (int i = 0; i < noOfMines; i++) {
      x = rand() % n;
      y = rand() % n;

      if (grid[x][y] != -1) {

        grid[x][y] = -1;

      } else {
        i--;
        continue;
      }

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

  int revealCell(int x, int y) {

    revealedRows.push_back(x);
    revealedCols.push_back(y);

    if (grid[x][y] < 0) {
      return -1;
    }
    
    if((revealedRows.size() == n*n) && (revealedCols.size() == n*n)){
      return 0;
    }
      
    else{
      return 1;
    }
  }

  bool isCellRevealed(int row, int col) {

    bool cellRevealed = false;

    for(int i=0; i<revealedRows.size(); i++){
      if(revealedRows[i] == row && revealedCols[i] == col){
        cellRevealed = true;
        break;
      }
    }
    return cellRevealed;
  }

  void printBoard() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {

        char cell;
        bool isCellShown = isCellRevealed(i, j);

        if (!isCellShown) {
          cell = '-';
        } 
        else {
          if (grid[i][j] < 0) {
            cell = 'M';
          } 
          else if (grid[i][j] < 9) {
            std::string a = std::to_string(grid[i][j]);
            cell = a[0];
          } 
          else {
            cell = '0';
          }
        }

        std::cout << cell << " | ";
      }

      std::cout << "\n";
    }
  }
};