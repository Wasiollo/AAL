/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InputOutput.h
 * Author: mateusz
 *
 * Created on 27 października 2017, 00:03
 */

#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H

#include <string>
#include <iostream>
#include <vector>

class InputOutput {
public:
    InputOutput();
    InputOutput(const InputOutput& orig);
    virtual ~InputOutput();
    
    static std::vector<char> getInput();
    
private:

};

#endif /* INPUTOUTPUT_H */

