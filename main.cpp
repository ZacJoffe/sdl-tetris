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
                blue = 255;
                green = 0;
                break;
            case T:
                // #9900CC
                red = 153;
                blue = 0;
                green = 204;
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
                blue = 153;
                green = 0;
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