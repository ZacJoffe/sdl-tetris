#include <iostream>
#include "tetromino.hpp"

Tetromino::Tetromino(TetrominoType t) {
    this->type = t;
    this->colour = Colour(this->type);
    this->x = 4;
    this->y = -2;
    this->rotation = 0;
    /*
    switch (this->type) {
        case I:
            this->x = 4;
            this->y = 0;
            break;
        case O:
            this->x = 4;
            this->y = 0;
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

Tetromino::Tetromino() {
    this->type = NONE; // used for check in HoldStack::isHeld() function
}

Tetromino::~Tetromino() {}

void Tetromino::rotateCCW() {
    if (this->rotation == 3) {
        this->rotation = 0;
    } else {
        this->rotation++;
    }
}

void Tetromino::rotateCW() {
    if (this->rotation == 0) {
        this->rotation = 3;
    } else {
        this->rotation--;
    }
}

void Tetromino::move(int dx, int dy) {
    this->x += dx;
    this->y += dy;
    // std::cout << x << " " << y << std::endl; // debugging
}

void Tetromino::reset() {
    this->x = 4;
    this->y = -2;
    this->rotation = 0;
}

void Tetromino::draw(SDL_Renderer *renderer) const {
    SDL_SetRenderDrawColor(renderer, this->colour.getRed(), this->colour.getGreen(), this->colour.getBlue(), 255);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (pieces[this->type][this->rotation][i][j] == 1) {
                SDL_Rect rect{(this->x + i) * SCREEN_WIDTH_BOARD / BOARD_WIDTH, (this->y + j) * SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT, SCREEN_WIDTH_BOARD / BOARD_WIDTH, SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT};
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
}

TetrominoType Tetromino::getType() const { return this->type; }
Colour Tetromino::getColour() const { return this->colour; }
int Tetromino::getRotation() const { return this->rotation; }
int Tetromino::getXPos() const { return this->x; }
int Tetromino::getYPos() const { return this->y; }

void Tetromino::setColour(Colour c) {
    this->colour = c;
}