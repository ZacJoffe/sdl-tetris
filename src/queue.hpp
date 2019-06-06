#pragma once

#include "colour.hpp"

#define QUEUESIZE 7

class Queue {
private:
    TetrominoType currQueue[QUEUESIZE];
    TetrominoType nextQueue[QUEUESIZE];

    void fillQueue(TetrominoType t[]);
    bool contains(TetrominoType t[], TetrominoType type) const;

    void enqueue(TetrominoType t);
    // void fillNext();
    
    // int getNextLength() const;
    bool isNextEmpty() const;
public:
    Queue();
    ~Queue();

    TetrominoType dequeue();

    void print() const;
};