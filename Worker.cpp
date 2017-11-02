/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Worker.cpp
 * Author: mateusz
 * 
 * Created on 2 listopada 2017, 13:17
 */

#include "Worker.h"

Worker::Worker() {
}

Worker::Worker(const Worker& orig) {
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
