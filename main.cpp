/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mateusz
 *
 * Created on 22 października 2017, 14:38
 */

#include <cstdlib>
#include <iostream>

#include "InputOutput.h"
#include "Worker.h"
#include "Alghoritms.h"



/*
 * 
 */
int main(int argc, char** argv) {
    
    std::vector<char> buffer;
    Worker worker('A','B');
    std::list<std::string> arguments = InputOutput::parseArguments(argc,argv);
    
    try
    {
        buffer = InputOutput::getInput();

        Alghoritms::myAlghoritm(buffer);
    
    }
    catch(std::string e)
    {
        std::cout << e << std::endl;
        return -1;
    }
    
    
    return 0;
}

