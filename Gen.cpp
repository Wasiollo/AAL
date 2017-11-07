//
// Created by Wasiollo on 07.11.17.
//
#include <iostream>

#include "Generator.h"


int main(int argc, char** argv) {

    std::string generatedData = Generator::generate();
    std::cout <<generatedData <<std::endl;

    return 0;
}

