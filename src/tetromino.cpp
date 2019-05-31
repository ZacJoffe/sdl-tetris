#include <iostream>
#include "tetromino.hpp"

Tetromino::Tetromino(TetrominoType t) {
    type = t;
    colour = Colour(type);
    x = 4;
    y = -2;
    rotation = 0;
    /*
    switch (type) {
        case I:
            x = 4;
            y = 0;
            break;
        case O:
            x = 4;
            y = 0;
            break;
        case T:
            break;
        case S:
            break;
        case Z:
            break;
        case J:
            break;
        case L:
            break;
    }
    */
}

Tetromino::Tetromino() {}
Tetromino::~Tetromino() {}

void Tetromino::rotateCCW() {
    if (rotation == 3) {
        rotation = 0;
    } else {
        rotation++;
    }
}

void Tetromino::rotateCW() {
    if (rotation == 0) {
        rotation = 3;
    } else {
        rotation--;
    }
}

void Tetromino::move(int dx, int dy) {
    /*
    // handle in collision detection
    if (dx == -1 && x > 0) {
        x += dx;
    }

    if (dx == 1 && x < 9) {
        x += dx;
    }

    if (dy == 1 && y < 20) {
        y += dy;
    }
    */

    x += dx;
    y += dy;
    std::cout << x << " " << y << std::endl; // debugging
}

void Tetromino::draw(SDL_Renderer *renderer) const {
    SDL_SetRenderDrawColor(renderer, colour.getRed(), colour.getGreen(), colour.getBlue(), 255);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (pieces[type][rotation][i][j] == 1) {
                SDL_Rect rect{(x + i) * SCREEN_WIDTH / BOARD_WIDTH, (y + j) * SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT, SCREEN_WIDTH / BOARD_WIDTH, SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT};
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
}

TetrominoType Tetromino::getType() const { return type; }
Colour Tetromino::getColour() const { return colour; }
int Tetromino::getRotation() const { return rotation; }
int Tetromino::getXPos() const { return x; }
int Tetromino::getYPos() const { return y; }

void Tetromino::setColour(Colour c) {
    colour = c;
}