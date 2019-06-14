#pragma once

#include "colour.hpp"

#define QUEUESIZE 7

class Queue {
private:
    TetrominoType currQueue[QUEUESIZE];
    TetrominoType nextQueue[QUEUESIZE];

    void fillQueue(TetrominoType t[]);
    bool contains(const TetrominoType t[], const TetrominoType type) const;

    bool isNextEmpty() const;
public:
    Queue();
    ~Queue();

    TetrominoType dequeue();

    TetrominoType getNext();

    void print() const;

};