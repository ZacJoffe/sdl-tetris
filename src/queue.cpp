#include <iostream>
#include <time.h>

#include "queue.hpp"

// fills given array with one of each tetromino type in a random order
void Queue::fillQueue(TetrominoType t[]) {
    for (int i = 0; i < QUEUESIZE; i++) {
        TetrominoType newType = static_cast<TetrominoType>(rand() % 7);
        while (contains(t, newType)) {
            newType = static_cast<TetrominoType>(rand() % 7);
        }

        t[i] = newType;
    }
}

// returns true if the array contains a given tetromino type
bool Queue::contains(const TetrominoType t[], const TetrominoType type) const {
    for (int i = 0; i < QUEUESIZE; i++) {
        if (t[i] == type) {
            return true;
        }
    }

    return false;
}

/*
void Queue::enqueue(TetrominoType t) {
    this->currQueue[QUEUESIZE - 1] = t;
}
*/


// returns true if nextQueue array is empty (if the value at the first index is NONE)
bool Queue::isNextEmpty() const { return this->nextQueue[0] == NONE; }

Queue::Queue() {
    // generate random seed
    srand(time(NULL));

    // set the initial values of both queue arrays to NONE
    for (int i = 0; i < QUEUESIZE; i++) {
        this->currQueue[i] = NONE;
        this->nextQueue[i] = NONE;
    }

    // fill values with actual data
    this->fillQueue(this->currQueue);
    this->fillQueue(this->nextQueue);
}

Queue::~Queue() {}

// return first TetrominoType in queue, shifts all the values in the queue left
TetrominoType Queue::dequeue() {
    // store value to dequeue, return at the end of the function
    TetrominoType t = this->currQueue[0];

    if (this->isNextEmpty()) {
        // fill up queue
        this->fillQueue(this->nextQueue);
    } 

    for (int i = 0; i < QUEUESIZE - 1; i++) {
        // shift all pieces in current queue left one index
        this->currQueue[i] = this->currQueue[i + 1];
    }

    this->currQueue[QUEUESIZE - 1] = this->nextQueue[0];

    for (int i = 0; i < QUEUESIZE - 1; i++) {
        // shift all pieces in next queue left one index
        this->nextQueue[i] = this->nextQueue[i + 1];
    }

    // set last value as NONE
    this->nextQueue[QUEUESIZE - 1] = NONE;

    return t;
}

void Queue::print() const {
    std::cout << "Current: ";
    for (int i = 0; i < QUEUESIZE; i++) {
        std::cout << this->currQueue[i] << " ";
    }

    std::cout << std::endl;

    std::cout << "Next: ";

    for (int i = 0; i < QUEUESIZE; i++) {
        std::cout << this->nextQueue[i] << " ";
    }

    std::cout << std::endl;
}