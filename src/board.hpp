#pragma once

#include <SDL2/SDL.h>
#include "tetromino.hpp"

class Board {
private:
    int board[BOARD_WIDTH][BOARD_HEIGHT];
    int score;
public:
    Board();
    ~Board();

    void print() const;
    void draw(SDL_Renderer *renderer) const;

    bool collision(const Tetromino &t) const;
    bool atFloor(const Tetromino &t) const;

    void setBlock(Tetromino t);

    void clearPieces();

    bool failureState() const;

    void reset();
};
