#include "holdStack.hpp"

HoldStack::HoldStack(Tetromino t) {
    this->t = t;
}

HoldStack::HoldStack() {
    this->t = Tetromino(); // empty Tetromino object
}

HoldStack::~HoldStack() {}

bool HoldStack::isHeld() const {
    return ((this->t).getType() != NONE);
}

void HoldStack::push(const Tetromino &t) {
    this->t = t;
}

void HoldStack::swap(Tetromino &t) {
    Tetromino temp = this->t;
    this->t = t;
    t = temp;

    t.reset();
}