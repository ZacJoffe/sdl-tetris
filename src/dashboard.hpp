#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "colour.hpp"
#include "tetromino.hpp"


class Dashboard {
private:
    TetrominoType next;
    TetrominoType held;

    int score;
    int level;

    void drawNext(SDL_Renderer *renderer);
    void drawHeld(SDL_Renderer *renderer, TTF_Font *font);
    void drawScore(SDL_Renderer *renderer, TTF_Font *font);
    void drawLevel(SDL_Renderer *renderer, TTF_Font *font);
public:
    // Dashboard(TetrominoType next, TetrominoType held, int score, int level);
    Dashboard(TetrominoType next);
    Dashboard();
    ~Dashboard();

    void update(TetrominoType next, TetrominoType held, int score, int level);

    void draw(SDL_Renderer *renderer, TTF_Font *font);
};