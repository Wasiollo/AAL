//
// Created by Wasiollo on 27.10.17.
//

#include "InputOutput.h"


InputOutput::InputOutput() {
}

InputOutput::InputOutput(const InputOutput& orig) {
}

InputOutput::~InputOutput() {
}

std::vector<char> InputOutput::getInput()
{
    std::string error = "Input ERROR : Letter not from scope";

    std::vector<char> result;
    int i=0;

    char c = getchar();
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

std::list<std::string> InputOutput::parseArguments(int argc, char* argv[])
{
    std::list<std::string> result;
    for (int i=0 ; i < argc ; i++)
    {
        result.push_back(argv[i]);
    }

    return result;

}

std::vector<char> InputOutput::getInput(std::string generated) {
    std::vector<char> result;
    for(int i=0; i< generated.length(); ++i){
        result.push_back(generated.at(i));
    }
    return result;
}
