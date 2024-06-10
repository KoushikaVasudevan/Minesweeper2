enum TileState { NOT_REVEALED, REVEALED };

enum TileValue { EMPTY, NOT_EMPTY, MINE };

class Tile {
private:
  TileValue value;
  TileState state;
  int number;

public:
  Tile();
  TileValue getValue() const;
  void setValue(TileValue val);
  bool isRevealed() const;
  void reveal();
  void incrementNumber();
  bool isMine() const;
  void placeMine();
  int getNumber() const;
  TileState getState() const;
};