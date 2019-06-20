#pragma once

#include <stdlib.h>
#include <cstdint>

enum TetrominoType { I, O, T, S, Z, J, L, NONE };

typedef uint8_t Uint8;

class Colour {
private:
    Uint8 red;
    Uint8 green;
    Uint8 blue;
public:
    Colour(TetrominoType t);
    Colour();
    ~Colour();

    Uint8 getRed() const;
    Uint8 getGreen() const;
    Uint8 getBlue() const;
};