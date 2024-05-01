// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() :first(nullptr) {}

void Train::addCage(bool light) {
    Cage* newCage = new Cage();
    newCage->light = light;
    if (first == nullptr) {
        newCage->next = newCage;
        newCage->prev = newCage;
        first = newCage;
    } else {
        Cage* lastCage = first->prev;
        newCage->next = first;
        newCage->prev = lastCage;
        first->prev = newCage;
        lastCage->next = newCage;
    }
}

int Train::getLength() {
    int length = 0;
    if (first != nullptr) {
        length = 1;
        Cage* currentCage = first->next;
        while (currentCage != first) {
            length++;
            currentCage = currentCage->next;
        }
        countOp = length + length * length
    }
    return length;
}

int Train::getOpCount() {
    return countOp;
}
