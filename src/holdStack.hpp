#pragma once

#include "tetromino.hpp"

class HoldStack {
private:
    Tetromino t;
public:
    HoldStack(Tetromino t);
    HoldStack();
    ~HoldStack();

    void push(const Tetromino &t);

    // returns true if this->t has a value
    bool isHeld() const;

    void swap(Tetromino *t);
};