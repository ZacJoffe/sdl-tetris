#include <SDL2/SDL.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
//#include <string>

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 640

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 22
#define BOARD_VISIBLE_HEIGHT 20

#define NUM_PIECES 7
#define NUM_ORIENTATIONS 4

enum TetrominoType { I, O, T, S, Z, J, L };

const int pieces[NUM_PIECES][NUM_ORIENTATIONS][4][4] {
    {
        // I
        { // starting orientation
            {0, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
        },
        { // cw rotation 90 degrees
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0},
        },
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 0},
        },
        {
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0},
        }
    },
    {
        // O
        {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0},
        },
        {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0},
        },
        {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0},
        },
        {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0},
        }
    },
    {
        // T
        {
            {0, 0, 0, 0},
            {0, 1, 0, 0},
            {1, 1, 1, 0},
            {0, 0, 0, 0},
        },
        {
            {0, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 0, 0},
        },
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {1, 1, 1, 0},
            {0, 1, 0, 0},
        },
        {
            {0, 0, 0, 0},
            {0, 1, 0, 0},
            {1, 1, 0, 0},
            {0, 1, 0, 0},
        }       
    },
    {
        // S
        {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0},
        },
        {
            {0, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 1, 0},
        },
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {1, 1, 0, 0},
        },
        {
            {0, 0, 0, 0},
            {1, 0, 0, 0},
            {1, 1, 0, 0},
            {0, 1, 0, 0},
        }
    },
    {
        // Z
        {
            {0, 0, 0, 0},
            {1, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0},
        },
        {
            {0, 0, 0, 0},
            {0, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 1, 0, 0},
        },
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {1, 1, 0, 0},
            {0, 1, 1, 0},
        },
        {
            {0, 0, 0, 0},
            {0, 1, 0, 0},
            {1, 1, 0, 0},
            {1, 0, 0, 0},
        }
    },
    {
        // J
        {
            {0, 0, 0, 0},
            {1, 0, 0, 0},
            {1, 1, 1, 0},
            {0, 0, 0, 0},
        },
        {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0},
        },
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {1, 1, 1, 0},
            {0, 0, 1, 0},
        },
        {
            {0, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {1, 1, 0, 0},
        }
    },
    {
        // L
        {
            {0, 0, 0, 0},
            {0, 0, 1, 0},
            {1, 1, 1, 0},
            {0, 0, 0, 0},
        },
        {
            {0, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 1, 0},
        },
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {1, 1, 1, 0},
            {1, 0, 0, 0},
        },
        {
            {0, 0, 0, 0},
            {1, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0},
        }
    }
};

class Colour {
public:
    Colour() {} // needed?
    Colour(TetrominoType t) {
        switch (t) {
            case I:
                // #00FFFF
                //red = 66;
                red = 0;
                blue = 255;
                green = 255; 
                break;
            case O:
                // #FFFF00
                red = 255;
                blue = 0;
                green = 255;
                break;
            case T:
                // #9900CC
                red = 153;
                blue = 204;
                green = 0;
                break;
            case S:
                // #00FF00
                red = 0;
                blue = 0;
                green = 255;
                break;
            case Z:
                // #FF0000
                red = 255;
                blue = 0;
                green = 0;
                break;
            case J:
                // #0000FF
                red = 0;
                blue = 255;
                green = 0;
                break;
            case L:
                // #FF7F00
                red = 255;
                blue = 0;
                green = 127;
                break;
        }
    }

    ~Colour() {

    }

    Uint8 getRed() const { return red; }
    Uint8 getGreen() const { return green; }
    Uint8 getBlue() const { return blue; }
private:
    Uint8 red;
    Uint8 green;
    Uint8 blue;
};

class Tetromino {
public:
    Tetromino() {}
    Tetromino(TetrominoType t) {
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

    ~Tetromino() {
        //delete colour;
    }

    void rotateCCW() {
        if (rotation == 3) {
            rotation = 0;
        } else {
            rotation++;
        }
    }

    void rotateCW() {
        if (rotation == 0) {
            rotation = 3;
        } else {
            rotation--;
        }
    }

    void move(int dx, int dy) {
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

    void draw(SDL_Renderer *renderer) {
        SDL_SetRenderDrawColor(renderer, colour.getRed(), colour.getGreen(), colour.getBlue(), 0xff);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (pieces[type][rotation][i][j] == 1) {
                    SDL_Rect rect{(x + i) * SCREEN_WIDTH / BOARD_WIDTH, (y + j) * SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT, SCREEN_WIDTH / BOARD_WIDTH, SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT};
                    SDL_RenderFillRect(renderer, &rect);
                }
            }
        }
    }

    TetrominoType getType() const { return type; }
    int getRotation() const { return rotation; }
    int getXPos() const { return x; }
    int getYPos() const { return y; }
private:
    TetrominoType type;
    Colour colour;
    int x;
    int y;
    int rotation; // index of rotation in pieces array, must be between 0 and 3
};

class Board {
private:
    int board[BOARD_WIDTH][BOARD_HEIGHT];
public:
    Board() {
        for (int i = 0; i < BOARD_WIDTH; i++) {
            for (int j = 0; j < BOARD_HEIGHT; j++) {
                board[i][j] = 0;
            }
        }
        //board = {{0}};
        for (int x = 0; x < BOARD_WIDTH; x++) {

        }
    }

    ~Board() {

    }

    // debugging function
    void print() {
        for (int y = 0; y < BOARD_VISIBLE_HEIGHT; y++) {
            for (int x = 0; x < BOARD_WIDTH; x++) {
                std::cout << board[x][y] << " ";
            }

            std::cout << std::endl;
        }
    }

    void draw(SDL_Renderer *renderer) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            for (int y = 0; y < BOARD_VISIBLE_HEIGHT; y++) {
                if (board[x][y] == 1) {
                    SDL_Rect rect{x * SCREEN_WIDTH / BOARD_WIDTH, y * SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT, SCREEN_WIDTH / BOARD_WIDTH, SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT};
                    SDL_RenderFillRect(renderer, &rect);
                }
            }
        }

        for (int x = SCREEN_WIDTH / BOARD_WIDTH; x < SCREEN_WIDTH; x += SCREEN_WIDTH / BOARD_WIDTH) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0xff);
            SDL_RenderDrawLine(renderer, x, 0, x, SCREEN_HEIGHT);
        }

        for (int y = SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT; y < SCREEN_HEIGHT; y += SCREEN_HEIGHT / BOARD_VISIBLE_HEIGHT) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0xff);
            SDL_RenderDrawLine(renderer, 0, y, SCREEN_WIDTH, y);
        }
    }

    bool collision(Tetromino t) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (pieces[t.getType()][t.getRotation()][i][j] == 1) {
                    int xLocation = t.getXPos() + i;
                    int yLocation = t.getYPos() + j;

                    std::cout << board[xLocation][yLocation] << " " << t.getXPos() << " " << t.getYPos() << std::endl;

                    if (board[xLocation][yLocation] == 1) {
                        return true;
                    }

                    if (xLocation < 0 || xLocation > 8) {
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

    bool atFloor(Tetromino t) {
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

    void setBlock(Tetromino t) {
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

    void clearPieces() {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            for (int y = 0; y < BOARD_HEIGHT; y++) {
                
            }
        }
    }
};

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

// if any sdl call fails, returns false and logs error, otherwise return true for success
bool init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (window == NULL) {
        std::cout << "Window could be not created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, NULL); // enable hardware acceleration flag?
    if (renderer == NULL) {
        std::cout << "Rendered could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void close() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main() {
    if (!init()) {
        return 1;
    }

    srand(time(NULL));

    SDL_Event e;
    bool quit = false;
    Tetromino t(static_cast<TetrominoType>(rand() % 7));
    Tetromino collisionTest;
    Board b;
    
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
                break;
            }

            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        collisionTest = t;
                        collisionTest.move(-1, 0);
                        if (!b.collision(collisionTest)) {
                            t.move(-1, 0);
                        }
                        // move piece left
                        break;
                    case SDLK_RIGHT:
                        collisionTest = t;
                        collisionTest.move(1, 0);
                        if (!b.collision(collisionTest)) {
                            t.move(1, 0);
                        }
                        //t.move(1, 0);
                        // move piece right
                        break;
                    case SDLK_UP:
                        collisionTest = t;
                        collisionTest.rotateCW();
                        if (!b.collision(collisionTest)) {
                            t.rotateCW();
                        }
                        // rotate
                        break;
                    case SDLK_z:
                        collisionTest = t;
                        collisionTest.rotateCW();
                        if (!b.collision(collisionTest)) {
                            t.rotateCW();
                        }
                        // rotate
                        break;
                    case SDLK_x:
                        collisionTest = t;
                        collisionTest.rotateCCW();
                        if (!b.collision(collisionTest)) {
                            t.rotateCCW();
                        }
                        // t.rotateCCW();
                        break;
                    case SDLK_DOWN:
                        collisionTest = t;
                        collisionTest.move(0, 1);
                        if (!b.collision(collisionTest)) {
                            t.move(0, 1);
                        } else if (b.atFloor(collisionTest)) {
                            b.setBlock(t);
                            t = Tetromino(static_cast<TetrominoType>(rand() % 7));
                        } else {
                            t.move(0, 1);
                        }
                        // move piece down
                        break;
                    case SDLK_SPACE:
                        b.print();
                        // hard drop
                        break;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
        SDL_RenderClear(renderer);

        //Tetromino t(O);
        t.draw(renderer);
        b.draw(renderer);
        SDL_RenderPresent(renderer);
        
    }

    close();

    return 0;
}