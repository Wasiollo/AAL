/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Worker.h
 * Author: mateusz
 *
 * Created on 22 października 2017, 14:39
 */

#ifndef WORKER_H
#define WORKER_H

class Worker {
public:
    Worker();
    Worker(char, char);
    Worker(const Worker& orig);
    virtual ~Worker();
    
    char getSpec();
    bool getStatus();
    

private:

    char spec[2] ;
    bool status;

		

};

#endif /* WORKER_H */

