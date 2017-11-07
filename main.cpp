#include <cstdlib>
#include <iostream>

#include "InputOutput.h"
#include "Worker.h"
#include "Alghoritms.h"
#include "Generator.h"


int main(int argc, char** argv) {

    std::vector<char> buffer;
    Worker worker('A','B');
    std::list<std::string> arguments = InputOutput::parseArguments(argc,argv);

    arguments.pop_front();
    if (arguments.size() >= 1) {
        if (arguments.front() == "-m1") {
            try {

                buffer = InputOutput::getInput();

                Alghoritms::brutalAlgoritm(buffer);
                Alghoritms::myAlghoritm(buffer);

            }
            catch (std::string e) {
                std::cout << e << std::endl;
                return -1;
            }
        }

        if (arguments.front() == "-m2") {

            std::string generatedData = Generator::generate(12, 5);

            buffer = InputOutput::getInput(generatedData);

            Alghoritms::brutalAlgoritm(buffer);
            Alghoritms::myAlghoritm(buffer);


        }
    }


    return 0;
}

