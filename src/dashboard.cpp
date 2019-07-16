#include <string>
#include "dashboard.hpp"

void Dashboard::drawNext(SDL_Renderer *renderer, TTF_Font *font) {
    // render font
    SDL_Color colourWhite = { 255, 255, 255, 255 };
    SDL_Surface *surface = nullptr;
    SDL_Texture *texture = nullptr;

    std::string strScore = "Next";

    surface = TTF_RenderText_Solid(font, strScore.c_str(), colourWhite);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    int textureWidth = 0;
    int textureHeight = 0;
    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
    SDL_Rect dstrect = { (3.0 / 2.0) * SCREEN_WIDTH_BOARD + SCREEN_WIDTH_BOARD / 4 - textureWidth / 2, 0, textureWidth, textureHeight };

    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_DestroyTexture(texture);

    for (int piece = 0; piece < this->nextSet.size(); piece++) {
        Colour c(this->nextSet[piece]);
        SDL_SetRenderDrawColor(renderer, c.getRed(), c.getGreen(), c.getBlue(), 255);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (pieces[this->nextSet[piece]][0][i][j] == 1) {
                    // SDL_Rect rect{ (this->x + i) * SCREEN_WIDTH_BOARD / BOARD_WIDTH, (this->y + j) * SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT, SCREEN_WIDTH_BOARD / BOARD_WIDTH, SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT };
                    SDL_Rect rect{ (3.0 / 2.0) * SCREEN_WIDTH_BOARD + i * SCREEN_WIDTH_BOARD / BOARD_WIDTH, (piece * 4 * SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT) + textureHeight + j * SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT, SCREEN_WIDTH_BOARD / BOARD_WIDTH, SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT };
                    SDL_RenderFillRect(renderer, &rect);
                }
            }
        }
    }
    /*
    Colour c(this->next);
    SDL_SetRenderDrawColor(renderer, c.getRed(), c.getGreen(), c.getBlue(), 255);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (pieces[this->next][0][i][j] == 1) {
                // SDL_Rect rect{ (this->x + i) * SCREEN_WIDTH_BOARD / BOARD_WIDTH, (this->y + j) * SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT, SCREEN_WIDTH_BOARD / BOARD_WIDTH, SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT };
                SDL_Rect rect{ (3.0 / 2.0) * SCREEN_WIDTH_BOARD + i * SCREEN_WIDTH_BOARD / BOARD_WIDTH, textureHeight + j * SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT, SCREEN_WIDTH_BOARD / BOARD_WIDTH, SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT };
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
    */
}

void Dashboard::drawHeld(SDL_Renderer *renderer, TTF_Font *font) {
    // render font
    SDL_Color colourWhite = { 255, 255, 255, 255 };
    SDL_Surface *surface = nullptr;
    SDL_Texture *texture = nullptr;

    std::string strScore = "Held";

    surface = TTF_RenderText_Solid(font, strScore.c_str(), colourWhite);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    int textureWidth = 0;
    int textureHeight = 0;
    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
    SDL_Rect dstrect = { SCREEN_WIDTH_BOARD / 4 - textureWidth / 2, 0, textureWidth, textureHeight };

    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_DestroyTexture(texture);


    Colour c(this->held);
    SDL_SetRenderDrawColor(renderer, c.getRed(), c.getGreen(), c.getBlue(), 255);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (pieces[this->held][0][i][j] == 1) {
                // SDL_Rect rect{ (this->x + i) * SCREEN_WIDTH_BOARD / BOARD_WIDTH, (this->y + j) * SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT, SCREEN_WIDTH_BOARD / BOARD_WIDTH, SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT };
                SDL_Rect rect{ i * SCREEN_WIDTH_BOARD / BOARD_WIDTH, textureHeight + j * SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT, SCREEN_WIDTH_BOARD / BOARD_WIDTH, SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT };
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }

    /*
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // SDL_Rect heldOutlineRect = { SCREEN_WIDTH_BOARD / BOARD_WIDTH, textureHeight, 100, 100 };
    SDL_Rect heldOutlineRect = { SCREEN_WIDTH_BOARD / BOARD_WIDTH, textureHeight, 4 * SCREEN_WIDTH_BOARD / BOARD_WIDTH, 4 * SCREEN_WIDTH_BOARD / BOARD_WIDTH };
    SDL_RenderDrawRect(renderer, &heldOutlineRect);
    */
}

void Dashboard::drawScore(SDL_Renderer *renderer, TTF_Font *font) {
    SDL_Color c = { 255, 255, 255, 255 };
    SDL_Surface *surface = nullptr;
    SDL_Texture *texture = nullptr;

    std::string strScore = "Score: " + std::to_string(this->score);

    surface = TTF_RenderText_Solid(font, strScore.c_str(), c);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    int textureWidth = 0;
    int textureHeight = 0;
    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
    SDL_Rect dstrect = { (3.0 / 2.0) * SCREEN_WIDTH_BOARD + SCREEN_WIDTH_BOARD / 4 - textureWidth / 2, SCREEN_HEIGHT - textureHeight, textureWidth, textureHeight };


    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    // SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
    // SDL_RenderPresent(renderer);
    SDL_DestroyTexture(texture);
}

void Dashboard::drawLevel(SDL_Renderer *renderer, TTF_Font *font) {
    SDL_Color c = { 255, 255, 255, 255 };
    SDL_Surface *surface = nullptr;
    SDL_Texture *texture = nullptr;

    std::string strLevel = "Level: " + std::to_string(this->level);

    surface = TTF_RenderText_Solid(font, strLevel.c_str(), c);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    int textureWidth = 0;
    int textureHeight = 0;
    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
    SDL_Rect dstrect = { SCREEN_WIDTH_BOARD / 4 - textureWidth / 2, SCREEN_HEIGHT - textureHeight, textureWidth, textureHeight };
    // SDL_Rect dstrect = { 0, 0, textureWidth, textureHeight };



    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    // SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
    // SDL_RenderPresent(renderer);
    SDL_DestroyTexture(texture);
}

void Dashboard::drawGameOver(SDL_Renderer *renderer, TTF_Font *font) {
    SDL_Color c = { 255, 255, 255, 255 };
    SDL_Surface *surface = nullptr;
    SDL_Texture *texture = nullptr;

    // std::string strLevel = "Level: " + std::to_string(this->level);
    std::string gameOverText = "Level: " + std::to_string(this->level);

    surface = TTF_RenderText_Solid(font, strLevel.c_str(), c);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    int textureWidth = 0;
    int textureHeight = 0;
    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
    SDL_Rect dstrect = { SCREEN_WIDTH_BOARD / 4 - textureWidth / 2, SCREEN_HEIGHT - textureHeight, textureWidth, textureHeight };
    // SDL_Rect dstrect = { 0, 0, textureWidth, textureHeight };



    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    // SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
    // SDL_RenderPresent(renderer);
    SDL_DestroyTexture(texture);
}

/*
Dashboard::Dashboard(TetrominoType next, TetrominoType held, int score, int level) {
    this->next = next;
    this->held = held;
    this->score = score;
    this->level = level;
}
*/

/*
Dashboard::Dashboard(TetrominoType next) {
    this->next = next;
    this->held = NONE;
    this->score = 0;
    this->level = 0;
}

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
}
*/

Dashboard::Dashboard(std::vector<TetrominoType> nextSet) {
    this->nextSet = nextSet;
    this->held = NONE;
    this->score = 0;
    this->level = 0;
}

Dashboard::Dashboard() {
    this->nextSet.push_back(NONE);
    this->held = NONE;
    this->score = 0;
    this->level = 0;
}

Dashboard::~Dashboard() {}


void Dashboard::update(std::vector<TetrominoType> nextSet, TetrominoType held, int score, int level) {
    this->nextSet = nextSet;
    this->held = held;
    this->score = score;
    this->level = level;
}
 

void Dashboard::draw(SDL_Renderer *renderer, TTF_Font *font, bool isOver) {
    // call all private draw functions
    if (isOver) {
        this->drawGameOver(renderer, font);
    } else {
        this->drawNext(renderer, font);
        this->drawHeld(renderer, font);
        this->drawScore(renderer, font);
        this->drawLevel(renderer, font);
    }
}