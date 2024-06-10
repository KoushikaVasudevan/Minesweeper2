#include "tile.h"

Tile::Tile() : value(EMPTY), state(NOT_REVEALED), number(0) {}

TileValue Tile::getValue() const { return value; }

void Tile::setValue(TileValue val) { value = val; }

bool Tile::isRevealed() const { return state == REVEALED; }

void Tile::reveal() { state = REVEALED; }

void Tile::incrementNumber() {
  if (value != MINE) {
    number++;
    if (number > 0) {
      value = NOT_EMPTY;
    }
  }
}

bool Tile::isMine() const { return value == MINE; }

void Tile::placeMine() { value = MINE; }

int Tile::getNumber() const { return number; }

TileState Tile::getState() const { return state; }