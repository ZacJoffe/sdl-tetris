#include <SDL2/SDL.h>
#include <iostream>
//#include <string>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define BOARD_WIDTH 22
#define BOARD_HEIGHT 10

#define NUM_PIECES 7
#define NUM_ORIENTATIONS 4

enum TetrominoType { I, O, T, S, Z, J, L };
//enum BlockColour { cyan, yellow, purple, green, red, blue, orange };

/*
static const int pieces[NUM_PIECES][NUM_ORIENTATIONS];

pieces[I] = {
    
}
*/

// 4d array creating all possible pieces and orientations
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

/*
const int pieceI[4][4][4] {
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
};

const int pieceO[4][4][4] {
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
};

const int pieceT[4][4][4] {
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
};
 
const int pieceS[4][4][4] {
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
};

const int pieceZ[4][4][4] {
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
};

const int pieceJ[4][4][4] {
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
};

const int pieceL[4][4][4] {
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
};
*/

class Colour {
public:
    //Colour() {} // needed?
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

    /*
    // remove?
    BlockColour getColour() {
        return colour;
    }
    */

    Uint8 getRed() const { return red; }
    Uint8 getGreen() const { return green; }
    Uint8 getBlue() const { return blue; }
private:
    //BlockColour colour;
    Uint8 red;
    Uint8 green;
    Uint8 blue;
};

class Tetromino {
public:
    Tetromino(TetrominoType t) {
        type = t;
        colour = new Colour(type);
        x = 5;
        y = 0;
        rotation = 0;
        /*
        switch (type) {
            case I:
                break;
            case O:
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
        //x = 5;
        //y = 0;
        

    }

    ~Tetromino() {
        delete colour;
    }

    void rotate() {

    }

    void move() {

    }

    void draw(SDL_Renderer *renderer) {
        SDL_SetRenderDrawColor(renderer, colour->getRed(), colour->getGreen(), colour->getBlue(), 0xff);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (pieces[type][rotation][i][j] == 1) {
                    SDL_Rect rect{(x + i) * 30, (y + j) * 30, 30, 30};
                    SDL_RenderFillRect(renderer, &rect);
                }
            }
        }
    }
private:
    TetrominoType type;
    Colour *colour;
    int x;
    int y;
    int rotation; // index of rotation in pieces array
};

class Board {
private:
    int board[BOARD_WIDTH][BOARD_HEIGHT];
    //Piece piece;

public:
    Board() {
        
    }

    ~Board() {

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

    SDL_Event e;
    bool quit = false;
    
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
                break;
            }

            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        // move piece left
                        break;
                    case SDLK_RIGHT:
                        // move piece right
                        break;
                    case SDLK_UP:
                        // rotate
                        break;
                    case SDLK_DOWN:
                        // move piece down
                        break;
                    case SDLK_SPACE:
                        // hard drop
                        break;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
        SDL_RenderClear(renderer);

        Tetromino t(L);
        t.draw(renderer);
        SDL_RenderPresent(renderer);
        
    }

    close();

    return 0;
}