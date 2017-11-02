/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InputOutput.cpp
 * Author: mateusz
 * 
 * Created on 27 października 2017, 00:03
 */

#include "InputOutput.h"
#include <cerrno>
#include <cstdio>


InputOutput::InputOutput() {
}

InputOutput::InputOutput(const InputOutput& orig) {
}

InputOutput::~InputOutput() {
}

std::vector<char> InputOutput::getInput()
{
    std::vector<char> result;
    int i=0;
    char c = getchar();
    std::string error = "Input ERROR : Letter not from scope";
    while (c != '\n')
    {
        c = toupper(c);
        if(c != 'A' && c !='B' && c != 'C' && c != 'D' && c != '\n')
            throw error;
        
        result.push_back(c) ;
        
        c = getchar();
    }
        return result;
}