#pragma once

#include <SDL2/SDL.h>
#include "colour.hpp"
#include "tetromino.hpp"


class Dashboard{
private:
    TetrominoType next;
    TetrominoType held;

    int score;
    int level;

    void drawNext(SDL_Renderer *renderer);
    void drawHeld(SDL_Renderer *renderer);
    void drawScore(SDL_Renderer *renderer);
    void drawLevel(SDL_Renderer *renderer);
public:
    // Dashboard(TetrominoType next, TetrominoType held, int score, int level);
    Dashboard();
    ~Dashboard();

    void update(TetrominoType next, TetrominoType held, int score, int level);

    void draw(SDL_Renderer *renderer);
};