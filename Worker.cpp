/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Worker.cpp
 * Author: mateusz
 * 
 * Created on 22 października 2017, 14:39
 */

#include "Worker.h"

Worker::Worker() {
        this->spec[0] = 'A';
	this->spec[1] = 'B';
        this->status = false;
}

Worker::Worker(const Worker& orig) {
}

Worker::~Worker() {
}

Worker::Worker(char a, char b)
{
	this->spec[0] = a;
	this->spec[1] = b;
        this->status = false;
}

bool Worker::getStatus()
{
    return this->status;
}

void Worker::setSatus(bool status)
{
    this->status = status;
}

char * Worker::getSpec()
{
    return this->spec;
}

void Worker::setSpec(char a, char b)
{
    this->spec[0] = a;
    this->spec[1] = b;
}
