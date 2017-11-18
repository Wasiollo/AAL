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
    /*
    if (arguments.size() >= 1) {
        if (arguments.front() == "-m1") {
            try {

                buffer = InputOutput::getInput();

                Alghoritms::brutalAlgoritm(buffer);
                Alghoritms::alternativeAlghoritm(buffer);

            }
            catch (std::string e) {
                std::cout << e << std::endl;
                return -1;
            }
        }

        if (arguments.front() == "-m2") {

            //std::string generatedData = Generator::generate(12, time(NULL));
*/
    int x, y, z, counter;
    counter = 0 ;
    for(unsigned i = 0 ; i <10000 ; ++i) {

        std::string generatedData = Generator::generate(12, time(NULL));
        buffer = InputOutput::getInput(generatedData);

        x = Alghoritms::alternativeAlghoritm(buffer);
        y = Alghoritms::brutalAlgoritm(buffer);


        if (x != y) {
            z = Alghoritms::myAlghoritm(buffer);
            std::cout << "error at i = " << i << "x , y ,z : " << x <<" "<< y <<" "<< z << " bufor : " ;
            ++counter;
            for(unsigned j = 0; j<buffer.size(); ++j)
                std::cout << buffer.at(j);
            if(z!=y)
                break;
        }

    }
    std::cout << "Counter" << counter <<std::endl;
        //}
    //}


    return 0;
}

