#include <cstdlib>
#include <iostream>

#include "InputOutput.h"
#include "Alghoritms.h"
#include "Generator.h"
#include "cxxopts.hpp"
#include <chrono>
#include <ctime>
#include <iomanip>

void firstMode() {
    std::vector<char> buffer;

    try {

        buffer = InputOutput::getInput();
        std::cout << "bugfix";

        Alghoritms alg;
        std::cout << "Kupa" << std::endl;
        alg.dynamicProgramming(buffer);
        std::cout << "koniec kupy" << std::endl;

        std::cout << "Alternative alghoritm = " << Alghoritms::alternativeAlghoritm(buffer) << std::endl;

        std::cout << "Brutal alghorim = " << Alghoritms::brutalAlgoritm(buffer) << std::endl;


    }
    catch (std::string e) {
        std::cout << e << std::endl;
        return;
    }
}

void secondMode(int n, int d) {

    std::vector<char> buffer;

    std::string generatedData = Generator::generate(n, d);
    buffer = InputOutput::getInput(generatedData);

    std::cout << "Alternative alghoritm = " << Alghoritms::alternativeAlghoritm(buffer) << std::endl;
    std::cout << "Brutal alghorim = " << Alghoritms::brutalAlgoritm(buffer) << std::endl;
}

void thirdMode(int n, int s, int k, int r) {
    // k tyle różnych r tyle instancji s taki skok
    double avgTime = 0, c = 4.0 / 100000, tempTime = 0;
    std::vector<double> results;
    std::vector<char> buffer;

    std::cout << " ________________________________" << std::endl;
    std::cout << "| ";
    std::cout << std::setw(8) << "n" << " | ";
    std::cout << std::setw(8) << "t(n)[ms]" << " | ";
    std::cout << std::setw(8) << "q(n)" << " |" << std::endl;
    for (int i = 0; i < k; ++i, n += s) {
        for (int j = 0; j < r; j++) {
            double d = i + j;
            std::string generatedData = Generator::generate(n, d);
            buffer = InputOutput::getInput(generatedData);
            auto start = std::chrono::system_clock::now();

            Alghoritms::alternativeAlghoritm(buffer);

            auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now() - start);
            tempTime = milliseconds.count();
            avgTime += tempTime;
        }

        avgTime /= r;
        results.push_back(avgTime);


        std::cout << "| ";
        std::cout << std::setw(8) << n << " | ";
        std::cout << std::fixed << std::setprecision(3) << std::setw(8) << avgTime << " | ";
        std::cout << std::fixed << std::setprecision(6) << std::setw(8) << avgTime / (n * c) << " |" << std::endl;
    }

}

int main(int argc, char **argv) {

    int m, n, k, s, r, d;
    d = m = n = k = s = r = 0;
    d = time(NULL);

    try {
        cxxopts::Options options(argv[0], " - command line options");
        options
                .positional_help("[optional args]")
                .show_positional_help();


        options.add_options("Program")
                ("m1", "Mode with reading from I/O")
                ("m2", "Mode with generation of data, -n option is obligatory")
                ("m3", "Full test mode, -n, -k, -s, -r options are obligatory")
                ("n, number", "Get number of tasks", cxxopts::value<int>())
                ("d, seed", "Get seed for generator", cxxopts::value<int>())
                ("s, step", "Get step of tasks in next iterations", cxxopts::value<int>())
                ("k, kproblem", "Get number of problems", cxxopts::value<int>())
                ("r, rinstance", "Get number of problem instantions", cxxopts::value<int>())
                ("h, help", "Print help");


        auto result = options.parse(argc, argv);

        if (result.count("help")) {
            std::cout << options.help({"", "Program"}) << std::endl;
            exit(0);
        }


        if (result.count("m1")) {
            m = 1;
            std::cout << "mode 1 runned" << std::endl;
        }

        if (result.count("m2")) {
            m = 2;
            std::cout << "mode 2 runned" << std::endl;
        }

        if (result.count("m3")) {
            m = 3;
            std::cout << "mode 3 runned" << std::endl;
        }

        if (result.count("n")) {
            n = result["n"].as<int>();
            std::cout << "n -> " << n << std::endl;
        }

        if (result.count("s")) {
            s = result["s"].as<int>();
            std::cout << "step -> " << s << std::endl;
        }

        if (result.count("k")) {
            k = result["k"].as<int>();
            std::cout << "k -> " << k << std::endl;
        }

        if (result.count("r")) {
            r = result["r"].as<int>();
            std::cout << "r -> " << r << std::endl;
        }
        if (result.count("d")) {
            d = result["d"].as<int>();
            std::cout << "d -> " << d << std::endl;
        }


    } catch (const cxxopts::OptionException &e) {
        std::cout << "error parsing options: " << e.what() << std::endl;
        exit(1);
    }

    switch (m) {
        case 1:
            firstMode();
            break;
        case 2:
            secondMode(n, d);
            break;
        case 3:
            thirdMode(n, s, k, r);
            break;
    }


    return 0;
}

