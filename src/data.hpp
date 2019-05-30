#pragma once

#include "colour.hpp"

class Data {
private:
    int state;
    Colour c;
public:
    Data(int state, Colour c);
    Data(int state);
    Data();
    ~Data();

    void setState(int state);
    void setColour(Colour c);

    int getState() const;
    Colour getColour() const;
};
