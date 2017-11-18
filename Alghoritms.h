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
    Alghoritms(const Alghoritms& orig);
    virtual ~Alghoritms();

    static int myAlghoritm(std::vector<char> ); // first designed Alghoritm still to add when there is no 4 on the end
    static int brutalAlgoritm(std::vector<char>); // brutal alternative Alghoritm - works not so long for short queues
    static int alternativeAlghoritm(std::vector<char>);

private:
    static int fourTreeChange(std::vector<char>, int, Worker, char);

};

#endif //AAL_ALGHORITMS_H
