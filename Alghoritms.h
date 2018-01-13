//
// Created by Wasiollo on 07.11.17.
//

#ifndef AAL_ALGHORITMS_H
#define AAL_ALGHORITMS_H


#include <vector>
#include "Worker.h"
class Alghoritms {
public:
    Alghoritms();

    static int brutalAlgoritm(std::vector<char>); // brutal alternative Alghoritm - works not so long for short queues

    static int alternativeAlghoritm(std::vector<char>);

    static bool isWorkerLetter(int i, char letter);

    void dynamicProgramming(std::vector<char> buffer);

private:
    static int fourTreeChange(std::vector<char>, int, Worker, char);

    static int min(int, int);


};

#endif //AAL_ALGHORITMS_H
