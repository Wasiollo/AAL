//
// Created by Wasiollo on 07.11.17.
//
#include <iostream>

#include "Generator.h"
#include "cxxopts.hpp"
#include <ctime>

int main(int argc, char** argv) {

    int n,d;
    n = 0;
    d = time(NULL);

    try
    {
        cxxopts::Options options(argv[0], " - command line options");
        options
                .positional_help("[optional args]")
                .show_positional_help();



        options.add_options("Program")
                ("n, number", "Get number of tasks",cxxopts::value<int>())
                ("d, seed", "Get seed for generator",cxxopts::value<int>())
                ("h, help", "Print help")
                ;


        auto result = options.parse(argc, argv);

        if (result.count("help"))
        {
            std::cout << options.help({"", "Program"}) << std::endl;
            exit(0);
        }

        if(result.count("n"))
        {
            n = result["n"].as<int>();

        }
        if(result.count("d"))
        {
            d = result["d"].as<int>();

        }


    } catch (const cxxopts::OptionException& e)
    {
        std::cout << "error parsing options: " << e.what() << std::endl;
        exit(1);
    }




    std::string generatedData = Generator::generate(n, d);
    std::cout << generatedData <<std::endl;

    return 0;
}

