#include "colour.hpp"

Colour::Colour(TetrominoType t) {
    switch (t) {
        case I:
            // #00FFFF
            this->red = 0;
            this->green = 255; 
            this->blue = 255;
            break;
        case O:
            // #FFFF00
            this->red = 255;
            this->green = 255;
            this->blue = 0;
            break;
        case T:
            // #9900CC
            this->red = 153;
            this->green = 0;
            this->blue = 204;
            break;
        case S:
            // #00FF00
            this->red = 0;
            this->green = 255;
            this->blue = 0;
            break;
        case Z:
            // #FF0000
            this->red = 255;
            this->green = 0;
            this->blue = 0;
            break;
        case J:
            // #0000FF
            this->red = 0;
            this->green = 0;
            this->blue = 255;
            break;
        case L:
            // #FF7F00
            this->red = 255;
            this->green = 127;
            this->blue = 0;
            break;
        case NONE:
            this->red = 180;
            this->green = 180;
            this->blue = 180;
            break;
    }
}

Colour::Colour() {}
Colour::~Colour() {}

Uint8 Colour::getRed() const { return this->red; }
Uint8 Colour::getGreen() const { return this->green; }
Uint8 Colour::getBlue() const { return this->blue; }
