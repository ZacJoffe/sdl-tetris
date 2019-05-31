#include "colour.hpp"

Colour::Colour(TetrominoType t) {
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
        case NONE:
            red = 180;
            blue = 180;
            green = 180;
            break;
    }
}

Colour::Colour() {}
Colour::~Colour() {}

Uint8 Colour::getRed() const { return red; }
Uint8 Colour::getGreen() const { return green; }
Uint8 Colour::getBlue() const { return blue; }
