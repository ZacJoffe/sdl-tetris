#include <iostream>
#include "board.hpp"

Board::Board() {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            board[i][j] = 0;
        }
    }
    /*
    //board = {{0}};
    for (int x = 0; x < BOARD_WIDTH; x++) {

    }
    */
    score = 0;
}

Board::~Board() {}

void Board::print() {
    for (int y = 0; y < BOARD_VISIBLE_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            std::cout << board[x][y] << " ";
        }

        std::cout << std::endl;
    }
}

void Board::draw(SDL_Renderer *renderer) {
    for (int x = 0; x < BOARD_WIDTH; x++) {
        for (int y = 0; y < BOARD_VISIBLE_HEIGHT; y++) {
            if (board[x][y] == 1) {
                SDL_Rect rect{x * SCREEN_WIDTH / BOARD_WIDTH, y * SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT, SCREEN_WIDTH / BOARD_WIDTH, SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT};

                // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }

    // grid lines
    for (int x = SCREEN_WIDTH / BOARD_WIDTH; x < SCREEN_WIDTH; x += SCREEN_WIDTH / BOARD_WIDTH) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, x, 0, x, SCREEN_HEIGHT);
    }

    for (int y = SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT; y < SCREEN_HEIGHT; y += SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, 0, y, SCREEN_WIDTH, y);
    }
}
    
bool Board::collision(Tetromino t) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (pieces[t.getType()][t.getRotation()][i][j] == 1) {
                int xLocation = t.getXPos() + i;
                int yLocation = t.getYPos() + j;

                std::cout << board[xLocation][yLocation] << " " << t.getXPos() << " " << t.getYPos() << std::endl;

                if (board[xLocation][yLocation] == 1) {
                    return true;
                }

                if (xLocation < 0 || xLocation > 9) {
                    return true;
                }

                if (yLocation > 19) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

bool Board::atFloor(Tetromino t) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (pieces[t.getType()][t.getRotation()][i][j] == 1) {
                int xLocation = t.getXPos() + i;
                int yLocation = t.getYPos() + j;

                //std::cout << board[xLocation][yLocation] << t.getXPos() << t.getYPos() << std::endl;

                if (board[xLocation][yLocation] == 1) {
                    return true;
                }

                if (yLocation > 19) {
                    return true;
                }
            }
        }
    }

    return false;
}

void Board::setBlock(Tetromino t) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (pieces[t.getType()][t.getRotation()][i][j] == 1) {
                int xLocation = t.getXPos() + i;
                int yLocation = t.getYPos() + j;
                board[xLocation][yLocation] = true;
            }
        }
    }
}

void Board::clearPieces() {
    // used for scoring
    int rowsCleared = 0;

    for (int y = 0; y < BOARD_HEIGHT; y++) {
        bool filledRow;
        for (int x = 0; x < BOARD_WIDTH; x++) {
            filledRow = true;
            if (board[x][y] == 0) {
                filledRow = false;
                break;
            }
        }

        if (filledRow) {
            rowsCleared++;
            for (int i = y; i > 0; i--) {
                for (int x = 0; x < BOARD_WIDTH; x++) {
                    board[x][i] = board[x][i - 1];
                }
            }
        }
    }

    switch (rowsCleared) {
        case 1:
            score += 40;
            break;
        case 2:
            score += 100;
            break;
        case 3:
            score += 300;
            break;
        case 4:
            score += 1200;
            break;
        default:
            break;
    }

    std::cout << score << std::endl;
}

bool Board::failureState() {
    for (int x = 0; x < BOARD_WIDTH; x++) {
        if (board[x][0] == 1 || board[x][1] == 1) {
            return true;
        }
    }

    return false;
}

void Board::reset() {
    for (int x = 0; x < BOARD_WIDTH; x++) {
        for (int y = 0; y < BOARD_HEIGHT; y++) {
            board[x][y] = 0;
        }
    }

    score = 0;
}
