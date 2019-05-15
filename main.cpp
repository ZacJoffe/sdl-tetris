#include <SDL2/SDL.h>
//#include <string>

#define WIDTH 22
#define HEIGHT 10

enum TetrominoType { I, O, T, S, Z, J, L };
//enum BlockColour { cyan, yellow, purple, green, red, blue, orange };

class Colour {
public:
    //enum BlockColour { cyan, yellow, purple, green, red, blue, orange };

    Colour(TetrominoType t) {
        // set colour type 
        switch (t) {
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
    }

    ~Colour() {

    }

    /*
    // remove?
    BlockColour getColour() {
        return colour;
    }
    */

    Uint8 getRed() { return red; }
    Uint8 getGreen() { return green; }
    Uint8 getBlue() { return blue; }
private:
    //BlockColour colour;
    Uint8 red;
    Uint8 green;
    Uint8 blue;
};

class Tetromino {
public:
    Tetromino(TetrominoType t) {
        switch (type) {
            case I:
                
            }
    }

    ~Tetromino() {

    }

    void rotate() {

    }

    void move() {

    }

    void draw() {

    }
private:
    TetrominoType type;
    Colour colour;
    int x;
    int y;
    int rotation;
};

class Board {
private:
    int board[WIDTH][HEIGHT];
    //Piece piece;

public:
    Board() {
        
    }

    ~Board() {

    }
};