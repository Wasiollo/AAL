#include <cstdlib>
#include <iostream>

#include "InputOutput.h"
#include "Alghoritms.h"
#include "Generator.h"
#include "cxxopts.hpp"

void firstMode(){
    std::vector<char> buffer;

    try {

        buffer = InputOutput::getInput();

        Alghoritms::alternativeAlghoritm(buffer);

        Alghoritms::brutalAlgoritm(buffer);


    }
    catch (std::string e) {
        std::cout << e << std::endl;
        return ;
    }
}

void secondMode(int n, int d){

    std::vector<char> buffer;

    std::string generatedData = Generator::generate(n,d);
    buffer = InputOutput::getInput(generatedData);

    Alghoritms::alternativeAlghoritm(buffer);
    Alghoritms::brutalAlgoritm(buffer);
}

void thirdMode(int n,int s,int k,int r, int d){
    std::cout << "Third mode still not implemented"<<std::endl;
}

int main(int argc, char** argv) {

    int m,n,k,s,r,d;
    m = n = k = s = r = 0;
    d = time(NULL);

    try
    {
        cxxopts::Options options(argv[0], " - command line options");
        options
                .positional_help("[optional args]")
                .show_positional_help();



        options.add_options("Program")
                ("m1", "Mode with reading from I/O")
                ("m2", "Mode with generation of data, -n option is obligatory")
                ("m3", "Full test mode, -n, -k, -s, -r options are obligatory")
                ("n, number", "Get number of tasks",cxxopts::value<int>())
                ("d, seed", "Get seed for generator",cxxopts::value<int>())
                ("s, step", "Get step of tasks in next iterations",cxxopts::value<int>())
                ("k, kproblem", "Get number of problems",cxxopts::value<int>())
                ("r, rinstance", "Get number of problem instantions",cxxopts::value<int>())
                ("h, help", "Print help")
                ;


        auto result = options.parse(argc, argv);

        if (result.count("help"))
        {
            std::cout << options.help({"", "Program"}) << std::endl;
            exit(0);
        }


        if(result.count("m1"))
        {
            m = 1;
            std::cout << "mode 1 runned" << std::endl;
        }

        if(result.count("m2"))
        {
            m = 2;
            std::cout << "mode 2 runned" << std::endl;
        }

        if(result.count("m3"))
        {
            m = 3;
            std::cout << "mode 3 runned" << std::endl;
        }

        if(result.count("n"))
        {
            n = result["n"].as<int>();
            std::cout << "n -> " << n <<std::endl;
        }

        if(result.count("s"))
        {
            s = result["s"].as<int>();
            std::cout << "step -> " << s << std::endl;
        }

        if(result.count("k"))
        {
            k = result["k"].as<int>();
            std::cout << "k -> " << k << std::endl;
        }

        if(result.count("r"))
        {
            r = result["r"].as<int>();
            std::cout << "r -> " << r << std::endl;
        }
        if(result.count("d"))
        {
            d = result["d"].as<int>();
            std::cout << "d -> " << d << std::endl;
        }


    } catch (const cxxopts::OptionException& e)
    {
        std::cout << "error parsing options: " << e.what() << std::endl;
        exit(1);
    }

    switch (m) {
        case 1:
            firstMode();
            break;
        case 2:
            secondMode(n,d);
            break;
        case 3:
            thirdMode(n,s,k,r,d);
            break;
    }


    return 0;
}

