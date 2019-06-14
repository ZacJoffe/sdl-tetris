#include "dashboard.hpp"

void Dashboard::drawNext(SDL_Renderer *renderer) {
    Colour c(this->next);
    SDL_SetRenderDrawColor(renderer, c.getRed(), c.getGreen(), c.getBlue(), 255);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (pieces[this->next][0][i][j] == 1) {
                // SDL_Rect rect{(this->x + i) * SCREEN_WIDTH_BOARD / BOARD_WIDTH, (this->y + j) * SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT, SCREEN_WIDTH_BOARD / BOARD_WIDTH, SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT};
                SDL_Rect rect{(i) * SCREEN_WIDTH_BOARD / BOARD_WIDTH, (j) * SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT, SCREEN_WIDTH_BOARD / BOARD_WIDTH, SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT};
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
}

void Dashboard::drawHeld(SDL_Renderer *renderer) {
    Colour c(this->held);
    SDL_SetRenderDrawColor(renderer, c.getRed(), c.getGreen(), c.getBlue(), 255);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (pieces[this->held][0][i][j] == 1) {
                // SDL_Rect rect{(this->x + i) * SCREEN_WIDTH_BOARD / BOARD_WIDTH, (this->y + j) * SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT, SCREEN_WIDTH_BOARD / BOARD_WIDTH, SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT};
                SDL_Rect rect{(i) * SCREEN_WIDTH_BOARD / BOARD_WIDTH, (j) * SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT, SCREEN_WIDTH_BOARD / BOARD_WIDTH, SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT};
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
}

void Dashboard::drawScore(SDL_Renderer *renderer) {

}

void Dashboard::drawLevel(SDL_Renderer *renderer) {

}

/*
Dashboard::Dashboard(TetrominoType next, TetrominoType held, int score, int level) {
    this->next = next;
    this->held = held;
    this->score = score;
    this->level = level;
}
*/

Dashboard::Dashboard() {
    this->next = NONE;
    this->held = NONE;
    this->score = 0;
    this->level = 0;
}

Dashboard::~Dashboard() {}


void Dashboard::update(TetrominoType next, TetrominoType held, int score, int level) {
    this->next = next;
    this->held = held;
    this->score = score;
    this->level = level;

    // ???
    // this->draw(renderer); 
}
 

void Dashboard::draw(SDL_Renderer *renderer) {

}