#pragma once

#include "tetromino.hpp"

class HoldStack {
private:
    Tetromino t;
public:
    HoldStack(Tetromino t);
    HoldStack();
    ~HoldStack();

    // returns true if this->t has a value
    bool isHeld() const;

    void push(const Tetromino &t);
    void swap(Tetromino &t);

    Tetromino getHeld();
};