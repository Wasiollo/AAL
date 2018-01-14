//
// Created by Wasiollo on 07.11.17.
//

#ifndef AAL_ALGORITHMS_H
#define AAL_ALGORITHMS_H


#include <vector>
#include <unordered_map>
#include "Worker.h"

using Edges = std::unordered_map<int, int>;
using Graph = std::vector<Edges>;

class Algorithms {

public:

    Algorithms();

    int brutalAlgorithm(std::vector<char>);

    int alternativeAlgorithm(std::vector<char>);

    int dynamicProgramming(std::vector<char>);

private:

    bool isWorkerLetter(int, char);

    int fourTreeChange(std::vector<char>, int, Worker, char);

    int min(int, int);

    Graph generateGraph(std::vector<char>);

};

#endif //AAL_ALGORITHMS_H
