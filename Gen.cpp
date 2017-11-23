//
// Created by Wasiollo on 07.11.17.
//
#include <iostream>

#include "Generator.h"
#include <ctime>

int main(int argc, char** argv) {

    std::string generatedData = Generator::generate(1000000, time(NULL));
    std::cout << generatedData <<std::endl;

    return 0;
}

