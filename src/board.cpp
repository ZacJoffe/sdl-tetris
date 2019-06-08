#include <iostream>
#include "board.hpp"

void Board::drawShadow(SDL_Renderer *renderer, const Tetromino &t) const {
    Tetromino collisionTest = t;
    int moveCount = 0;
    while (!this->atFloor(collisionTest)) {
        collisionTest.move(0, 1);
        moveCount++;
    }

    collisionTest.move(0, -1);
    collisionTest.setColour(Colour(NONE));

    collisionTest.draw(renderer);
}

void Board::setLevel() {
    if (this->linesCleared <= 0) {
        this->level = 1;
    } else if (this->linesCleared <= 90) {
        this->level = 1 + ((this->linesCleared - 1) / 10);
    } else {
        this->level = 10;
    }
}

Board::Board() {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            this->board[i][j] = Data();
        }
    }

    this->score = 0;
    this->linesCleared = 0;
    this->level = 1;
}

Board::~Board() {}

void Board::print() const {
    for (int y = 0; y < BOARD_VISIBLE_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            std::cout << this->board[x][y].getState() << " ";
        }

        std::cout << std::endl;
    }
}

void Board::draw(SDL_Renderer *renderer, const Tetromino &t) const {
    // board
    for (int x = 0; x < BOARD_WIDTH; x++) {
        for (int y = 0; y < BOARD_VISIBLE_HEIGHT; y++) {
            if (this->board[x][y].getState() == 1) {
                SDL_Rect rect{x * SCREEN_WIDTH_BOARD / BOARD_WIDTH, y * SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT, SCREEN_WIDTH_BOARD / BOARD_WIDTH, SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT};

                Colour c = this->board[x][y].getColour();
                // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_SetRenderDrawColor(renderer, c.getRed(), c.getGreen(), c.getBlue(), 255);
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }

    // tetromino shadow (render first so tetromino will overlap piece)
    this->drawShadow(renderer, t);

    // tetromino 
    t.draw(renderer);

    // grid lines
    for (int x = SCREEN_WIDTH_BOARD / BOARD_WIDTH; x <= SCREEN_WIDTH_BOARD; x += SCREEN_WIDTH_BOARD / BOARD_WIDTH) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, x, 0, x, SCREEN_HEIGHT);
    }

    for (int y = SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT; y < SCREEN_HEIGHT; y += SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, 0, y, SCREEN_WIDTH_BOARD, y);
    }
}

bool Board::collision(const Tetromino &t) const {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (pieces[t.getType()][t.getRotation()][i][j] == 1) {
                int xLocation = t.getXPos() + i;
                int yLocation = t.getYPos() + j;

                // std::cout << board[xLocation][yLocation].getState() << " " << t.getXPos() << " " << t.getYPos() << std::endl;

                if (this->board[xLocation][yLocation].getState() == 1) {
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

bool Board::atFloor(const Tetromino &t) const {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (pieces[t.getType()][t.getRotation()][i][j] == 1) {
                int xLocation = t.getXPos() + i;
                int yLocation = t.getYPos() + j;

                //std::cout << board[xLocation][yLocation] << t.getXPos() << t.getYPos() << std::endl;

                if (this->board[xLocation][yLocation].getState() == 1) {
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

                // board[xLocation][yLocation].setState(1);
                this->board[xLocation][yLocation] = Data(1, t.getColour());
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
            if (this->board[x][y].getState() == 0) {
                filledRow = false;
                break;
            }
        }

        if (filledRow) {
            rowsCleared++;
            for (int i = y; i > 0; i--) {
                for (int x = 0; x < BOARD_WIDTH; x++) {
                    // board[x][i] = board[x][i - 1];
                    this->board[x][i].setState(this->board[x][i - 1].getState());
                }
            }
        }
    }

    switch (rowsCleared) {
        case 1:
            this->score += 40;
            break;
        case 2:
            this->score += 100;
            break;
        case 3:
            this->score += 300;
            break;
        case 4:
            this->score += 1200;
            break;
        default:
            break;
    }

    this->linesCleared += rowsCleared;
    this->setLevel();

    std::cout << this->score << std::endl;
}

bool Board::failureState() const {
    for (int x = 0; x < BOARD_WIDTH; x++) {
        if (board[x][0].getState() == 1 || board[x][1].getState() == 1) {
            return true;
        }
    }

    return false;
}

void Board::reset() {
    // set all board values to default
    for (int x = 0; x < BOARD_WIDTH; x++) {
        for (int y = 0; y < BOARD_HEIGHT; y++) {
            this->board[x][y] = Data();
        }
    }

    // reset scoring vars
    this->score = 0;
    this->linesCleared = 0;
    this->level = 1;
}

int Board::getScore() const { return this->score; }
int Board::getLinesCleared() const { return this->linesCleared; }
int Board::getLevel() const { return this->level; }