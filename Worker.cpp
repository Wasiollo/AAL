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
}

Worker::Worker(const Worker& orig) {
}

Worker::~Worker() {
}

Worker::Worker(char a, char b)
{
	this->spec[1] = a;
	this->spec[2] = b;
}

