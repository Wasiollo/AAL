//
// Created by Wasiollo on 27.10.17.
//

#include "InputOutput.h"


std::vector<char> InputOutput::getInput() {
    std::string error = "Input ERROR : Letter not from scope";

    std::vector<char> result;
    int i = 0;

    char c = getchar();
    while (c != '\n') {
        c = toupper(c);
        if (c != 'A' && c != 'B' && c != 'C' && c != 'D' && c != '\n')
            throw error;

        result.push_back(c);

        c = getchar();
    }
    return result;
}


std::vector<char> InputOutput::getInput(std::string generated) {
    std::vector<char> result;
    for (char i : generated) {
        result.push_back(i);
    }
    return result;
}
