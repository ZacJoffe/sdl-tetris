#pragma once

#include <SDL2/SDL.h>
#include "tetromino.hpp"
#include "data.hpp"

class Board {
private:
    // int board[BOARD_WIDTH][BOARD_HEIGHT];
    Data board[BOARD_WIDTH][BOARD_HEIGHT];
    int score;
    int linesCleared;
    int level;

    void drawShadow(SDL_Renderer *renderer, const Tetromino &t) const;
    void setLevel();
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

    int getScore() const;
    int getLinesCleared() const;
    int getLevel() const;
};
