//
// Created by Wasiollo on 07.11.17.
//

#include "Worker.h"


Worker::Worker() {
    this->first = 'A';
    this->second = 'B';
}

Worker::Worker(const Worker& orig) {
    this->first = orig.first;
    this->second = orig.second;
}

Worker::~Worker() {
}

Worker::Worker(char A, char B){
    this->first = A;
    this->second = B;
}
void Worker::callWorker(char A, char B){
    this->first = A;
    this->second = B;
}
bool Worker::isMyLetter(char other){
    if (other == this->first || other == this->second)
        return true;
    return false;
}