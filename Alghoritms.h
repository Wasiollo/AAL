/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alghoritms.h
 * Author: mateusz
 *
 * Created on 3 listopada 2017, 00:06
 */

#ifndef ALGHORITMS_H
#define ALGHORITMS_H

#include <vector>

class Alghoritms {
public:
    Alghoritms();
    Alghoritms(const Alghoritms& orig);
    virtual ~Alghoritms();
    
    static void myAlghoritm(std::vector<char> buffer); // first designed Alghoritm still to add when there is no 4 on the end
private:

};

#endif /* ALGHORITMS_H */

