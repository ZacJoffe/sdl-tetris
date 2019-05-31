#pragma once

#include <SDL2/SDL.h>
#include "tetromino.hpp"
#include "data.hpp"

class Board {
private:
    // int board[BOARD_WIDTH][BOARD_HEIGHT];
    Data board[BOARD_WIDTH][BOARD_HEIGHT];
    int score;

    void drawShadow(SDL_Renderer *renderer, const Tetromino &t);
public:
    Board();
    ~Board();

    void print() const;
    void draw(SDL_Renderer *renderer, const Tetromino &t) const;

    bool collision(const Tetromino &t) const;
    bool atFloor(const Tetromino &t) const;

    void setBlock(Tetromino t);

    void clearPieces();

    bool failureState() const;

    void reset();
};
