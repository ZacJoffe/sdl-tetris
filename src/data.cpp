#include "data.hpp"

Data::Data(int state, Colour c) {
    this->state = state;
    this->c = c;
}

Data::Data(int state) {
    this->state = state;
}

Data::Data() {
    this->state = 0;
    this->c = Colour();
}

Data::~Data() {}

void Data::setState(int state) {
    this->state = state;
}

void Data::setColour(Colour c) {
    this->c = c;
}

int Data::getState() { return this->state; }
Colour Data::getColour() { return this->c; }
