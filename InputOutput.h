//
// Created by Wasiollo on 07.11.17.
//

#ifndef AAL_INPUTOUTPUT_H
#define AAL_INPUTOUTPUT_H

#include <string>
#include <iostream>
#include <vector>
#include <list>

class InputOutput {
public:
    InputOutput();
    InputOutput(const InputOutput& orig);
    virtual ~InputOutput();

    static std::vector<char> getInput();
    static std::vector<char> getInput(std::string generated);
    static std::list<std::string> parseArguments(int argc, char* argv[]);



};


#endif //AAL_INPUTOUTPUT_H
