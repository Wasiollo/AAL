//
// Created by Wasiollo on 07.11.17.
//

#ifndef AAL_ALGHORITMS_H
#define AAL_ALGHORITMS_H


#include <vector>
#include "Worker.h"

class Alghoritms {
public:
    static int brutalAlgoritm(std::vector<char>); // brutal alternative Alghoritm - works not so long for short queues
    static int alternativeAlghoritm(std::vector<char>);

private:
    static int fourTreeChange(std::vector<char>, int, Worker, char);
    static int min (int, int);

};

#endif //AAL_ALGHORITMS_H
