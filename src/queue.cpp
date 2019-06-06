#include <iostream>
#include <time.h>

#include "queue.hpp"

void Queue::fillQueue(TetrominoType t[]) {
    // generate random seed
    srand(time(NULL));

    for (int i = 0; i < QUEUESIZE; i++) {
        TetrominoType newType = static_cast<TetrominoType>(rand() % 7);
        while (contains(t, newType)) {
            newType = static_cast<TetrominoType>(rand() % 7);
        }

        t[i] = newType;
    }
}

bool Queue::contains(TetrominoType t[], TetrominoType type) const {
    for (int i = 0; i < QUEUESIZE; i++) {
        if (t[i] == type) {
            return true;
        }
    }

    return false;
}

void Queue::enqueue(TetrominoType t) {
    this->currQueue[QUEUESIZE - 1] = t;
}

/*
void Queue::fillNext() {

}
*/

/*
int Queue::getNextLength() const {
    for (int i = 0; i < QUEUESIZE; i++) {
        if (nextQueue[i] == NONE) {
            return i;
        }
    }

    return QUEUESIZE;
}
*/

bool Queue::isNextEmpty() const {
    /*
    int count = 0;
    for (int i = 0; i < QUEUESIZE; i++) {
        if (this->nextQueue[i] == NONE) {
            count++;
        }
    }

    return count == QUEUESIZE;
    */

    return this->nextQueue[0] == NONE;
}

Queue::Queue() {
    for (int i = 0; i < QUEUESIZE; i++) {
        this->currQueue[i] = NONE;
        this->nextQueue[i] = NONE;
    }
    // fill values of both arrays
    this->fillQueue(this->currQueue);
    this->fillQueue(this->nextQueue);
}

Queue::~Queue() {}

TetrominoType Queue::dequeue() {
    // get first value, shift all in array left and enqueue the first val of the next array
    // if the array is not filled
    TetrominoType t = this->currQueue[0];

    for (int i = 0; i < QUEUESIZE - 1; i++) {
        // shift all pieces left one index
        this->currQueue[i] = this->currQueue[i + 1];
    }

    if (this->isNextEmpty()) {
        this->fillQueue(this->nextQueue);
    } else {
        this->currQueue[QUEUESIZE - 1] = this->nextQueue[0];

        for (int i = 0; i < QUEUESIZE - 1; i++) {
            // shift all pieces left one index
            this->nextQueue[i] = this->nextQueue[i + 1];
        }

        this->nextQueue[QUEUESIZE - 1] = NONE;
    }

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