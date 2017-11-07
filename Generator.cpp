//
// Created by Wasiollo on 07.11.17.
//

#include "Generator.h"

#include <iostream>


Generator::Generator() {
}

Generator::Generator(const Generator& orig) {
}

Generator::~Generator() {
}


std::string Generator::generate(int count , int seed){
    srand(seed);
    std::string result;
    int x ;
    int n = count;
    for(int i= 0; i<n; ++i)
    {
        x = std::rand()%4;
        x+=65;
        result+=(char)x;
    }
    return result ;
}