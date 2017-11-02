/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Worker.h
 * Author: mateusz
 *
 * Created on 2 listopada 2017, 13:17
 */

#ifndef WORKER_H
#define WORKER_H

class Worker {
public:
    Worker();
    Worker(char A, char B);
    Worker(const Worker& orig);
    virtual ~Worker();
    
    void callWorker(char A, char B);
    bool isMyLetter(char other);
private:
    char first;
    char second;

};

#endif /* WORKER_H */

