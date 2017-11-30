//
// Created by Wasiollo on 07.11.17.
//

#include "Alghoritms.h"

#include <iostream>

Alghoritms::Alghoritms() {
}

Alghoritms::Alghoritms(const Alghoritms& orig) {
}

Alghoritms::~Alghoritms() {
}

int Alghoritms::brutalAlgoritm(std::vector<char> buffer) {
    Worker worker('A','B');
    int i = 0;
    int countA,countB,countC,countD, minCount;
    countA = fourTreeChange(buffer,i,worker,'A');
    countB = fourTreeChange(buffer,i,worker,'B');
    countC = fourTreeChange(buffer,i,worker,'C');
    countD = fourTreeChange(buffer,i,worker,'D');
    minCount =std::min(std::min(std::min(countA,countB),countC),countD);
    return minCount;
}


int Alghoritms::fourTreeChange(std::vector<char> buffer, int i, Worker worker, char letter) {


    int count,countA,countB,countC,countD;

    count = countA = countB = countC = countD = 0;

    while(i<buffer.size()){
        if (worker.isMyLetter(buffer.at(i))) {
            count += 5;
            ++i;
            continue;
        }

        count+=10;
        ++i;
        if(buffer.at(i-1)!=letter) {
            worker.callWorker(buffer.at(i - 1), letter);
        }
        countA = fourTreeChange(buffer,i, worker,'A');
        countB = fourTreeChange(buffer,i, worker,'B');
        countC = fourTreeChange(buffer,i, worker,'C');
        countD = fourTreeChange(buffer,i, worker,'D');

        count+=std::min(std::min(std::min(countA,countB),countC),countD);
        return count;
    }
    return count;
}

int Alghoritms::alternativeAlghoritm(std::vector<char> buffer) {

    Worker worker('A','B');
    int i,count, no,j;
    char firstMyLetter, firstNotMyLetter;
    count = i = 0;
    while (i<buffer.size())
    {
        if(worker.isMyLetter(buffer.at(i)))
        {
            count+=5;
            ++i;

            continue;
        }
        no = 0;
        if(i+1<buffer.size())
        if(!worker.isMyLetter(buffer.at(i+1)))
        {

            count+=10;
            firstNotMyLetter = buffer.at(i);
            ++i;

            while(buffer.at(i)==firstNotMyLetter)
            {
                ++no;
                ++i;
                if(i>=buffer.size())
                {
                    count+=no*5;
                    return count ;
                }
            }
            count+=no*5;

            worker.callWorker(firstNotMyLetter, buffer.at(i));
            continue;
        }

        if(i+1>=buffer.size())
        {
            count+=10;
            break;
        }

        firstNotMyLetter = buffer.at(i);
        firstMyLetter = buffer.at(i+1);

        count += 15;
        no = 0;
        i+=2;

        if(i < buffer.size()) {
            while (buffer.at(i) == firstMyLetter) {
                ++no;
                ++i;
                if (i >= buffer.size()) {
                    count+=no*5;
                    return count ;
                }
            }
        }
        else
        {
            break;
        }

        count += no*5;

        if(worker.isMyLetter(buffer.at(i)))
            continue;

        if(buffer.at(i) == firstNotMyLetter)
            worker.callWorker(firstMyLetter, firstNotMyLetter);
        else {
            j = 1;

            while (i+j<buffer.size()) {
                if(buffer.at(i+j)==firstMyLetter) {
                    ++j;
                    continue;
                }
                if(buffer.at(i+j)==firstNotMyLetter) {
                    worker.callWorker(firstMyLetter, firstNotMyLetter);
                    break;
                }
                if(!worker.isMyLetter(buffer.at(i+j)))
                    break;
                if (worker.isMyLetter(buffer.at(i+1)) && buffer.at(i)!=firstMyLetter)
                    break;
            }


        }

    }
    return count;

}
