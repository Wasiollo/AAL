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

void Alghoritms::myAlghoritm(std::vector<char> buffer)
{
    Worker worker('A','B');
    int i,count;
    count = i = 0;
    while (i<buffer.size())
    {
        if(worker.isMyLetter(buffer.at(i)))
        {
            //std::cout <<buffer.at(i)<<std::endl;
            count+=5;
            ++i;
        }
        else
        {
            if ((i+1)<buffer.size() ){
                if(!worker.isMyLetter(buffer.at(i+1)))
                {
                    //std::cout <<buffer.at(i)<<buffer.at(i+1)<<std::endl;
                    count+=15;
                    worker.callWorker(buffer.at(i), buffer.at(i+1));
                    //std::cout<<"Wolam: "<<buffer.at(i)<<buffer.at(i+1)<< " gdy i = " << i << " count  = " <<count <<std::endl ;
                    i+=2;
                }
                else
                {
                    if((i+3)<buffer.size()){

                        //std::cout <<buffer.at(i)<<buffer.at(i+1)<<buffer.at(i+2)<<buffer.at(i+3)<<std::endl;
                        if(worker.isMyLetter(buffer.at(i+2)) && worker.isMyLetter(buffer.at(i+3)))
                        {
                            //std::cout <<buffer.at(i)<<buffer.at(i+1)<<buffer.at(i+2)<<buffer.at(i+3)<<std::endl;
                            count+=25;
                            i+=4;
                        }
                        else
                        {
                            count+=15;
                            worker.callWorker(buffer.at(i), buffer.at(i+1));
                            //std::cout<<"Wolam: "<<buffer.at(i)<<buffer.at(i+1)<< " gdy i = " << i << " count  = " <<count <<std::endl ;
                            i+=2;
                        }
                    }
                    else{
                        std::cout<< "nie ma 4 elementow na koniec"<<std::endl;
                        if((i+3)>buffer.size())
                        {
                            //std::cout << "2 elementy na koniec"<<std::endl;
                            //std::cout<<buffer.at(i)<<buffer.at(i+1)<<std::endl;
                            count+=15;
                            i+=2;
                            break;
                        }
                        std::cout <<buffer.at(i)<<buffer.at(i+1)<<buffer.at(i+2)<<std::endl;
                        if(worker.isMyLetter(buffer.at(i+2)))
                        {
                            count+=20;
                            i+=3;
                        }
                        else if(buffer.at(i+2)==buffer.at(i))
                        {
                            count+=20;
                            worker.callWorker(buffer.at(i), buffer.at(i+1));
                            i+=3;
                        }
                        else
                        {
                            count+=25;
                            i+=3;
                        }
                    }
                }
            }

            else{
                //std::cout << buffer.at(i)<<std::endl;
                count+=10;
                ++i;
            }
        }

    }
    std::cout <<"my Alghoritm count = "<<count <<std::endl ;
}

void Alghoritms::brutalAlgoritm(std::vector<char> buffer) {
    Worker worker('A','B');
    int i = 0;
    int countA,countB,countC,countD;
    countA = fourTreeChange(buffer,i,worker,'A');
    countB = fourTreeChange(buffer,i,worker,'B');
    countC = fourTreeChange(buffer,i,worker,'C');
    countD = fourTreeChange(buffer,i,worker,'D');
    std::cout<<std::endl << "brutal count = " <<std::min(std::min(std::min(countA,countB),countC),countD)<<std::endl;
}

int Alghoritms::fourTreeChange(std::vector<char> buffer, int i, Worker worker, char letter) {


    int count,countA,countB,countC,countD;
    while(i<buffer.size()){
        if (worker.isMyLetter(buffer.at(i))) {
            count += 5;
    //        std::cout <<buffer.at(i)<<" "<<count<< " ";

            ++i;
            continue;
        }
      //  std::cout <<std::endl<<count<<std::endl;

        count+=10;
    //    std::cout <<"Letter " << buffer.at(i)<<"is not my letter, tree letter:"<< letter <<std::endl;
        ++i;
        if(buffer.at(i-1)!=letter) {
            worker.callWorker(buffer.at(i - 1), letter);
     //       std::cout <<"Called worker with letters: "<<buffer.at(i - 1)<< letter<<std::endl;
        }
        /*else {
            continue;
        }*/
        countA = fourTreeChange(buffer,i, worker,'A');
     //   std::cout <<"countA" << countA << std::endl;
        countB = fourTreeChange(buffer,i, worker,'B');
     //   std::cout <<"countB" << countB << std::endl;
        countC = fourTreeChange(buffer,i, worker,'C');
     //   std::cout <<"countC" << countC << std::endl;
        countD = fourTreeChange(buffer,i, worker,'D');
     //   std::cout <<"countD" << countD << std::endl;
     //   printf("coutA: %d, coutB: %d, coutC: %d, coutD: %d \n",countA,countB,countC,countD);
        count+=std::min(std::min(std::min(countA,countB),countC),countD);
     //   std::cout << "count + cuntMin " << count <<std::endl;
        return count;
    }
    return count;
}
