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
/*
int Alghoritms::myAlghoritm(
        std::vector<char> buffer) // still not implemented calling worker when next two letters to call are the same
{
    //TODO implement calling worker when next calling letters are the same
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
                    while(buffer.at(i) == buffer.at(i+1))
                    {
                        ++i;
                        count+=5;
                        if(i>=buffer.size())
                            return count ;
                    }
                    worker.callWorker(buffer.at(i), buffer.at(i+1));
                    //std::cout<<"Wolam: "<<buffer.at(i)<<buffer.at(i+1)<< " gdy ii = " << i << " count  = " <<count <<std::endl ;
                    i+=2;
                }
                else
                {
                    if((i+3)<buffer.size()){

                        std::cout <<buffer.at(i)<<buffer.at(i+1)<<buffer.at(i+2)<<buffer.at(i+3)<<std::endl;
                        if((worker.isMyLetter(buffer.at(i+2)) && worker.isMyLetter(buffer.at(i+3))))
                        {
                        //    std::cout <<buffer.at(i)<<buffer.at(i+1)<<buffer.at(i+2)<<buffer.at(i+3);
                        //    std::cout << "nie wolam niczego"<<std::endl;
                            count+=25;
                            i+=4;
                        }
                        else
                        {
                            if((worker.isMyLetter(buffer.at(i+4)) && (worker.isMyLetter(buffer.at(i+2)) || worker.isMyLetter(buffer.at(i+3)))))
                            {
                                //std::cout <<buffer.at(i)<<buffer.at(i+1)<<buffer.at(i+2)<<buffer.at(i+3);
                                //std::cout << "nie wolam niczego"<<std::endl;
                                count+=30;
                                i+=4;
                            }
                            else {
                                count += 15;
                                while (buffer.at(i) == buffer.at(i + 1)) {
                                    ++i;
                                    count += 5;
                                    if(i>=buffer.size())
                                        return count ;
                                }
                                worker.callWorker(buffer.at(i), buffer.at(i + 1));
                                //std::cout << "Wolam: " << buffer.at(i) << buffer.at(i + 1) << " gdy i = " << i
                                  //        << " count  = " << count << std::endl;
                                i += 2;
                            }
                        }
                    }
                    else{
                        std::cout<< "nie ma 4 elementow na koniec"<<std::endl;
                        if((i+3)>buffer.size())
                        {
                           // std::cout << "2 elementy na koniec"<<std::endl;
                            //std::cout<<buffer.at(i)<<buffer.at(i+1)<<std::endl;
                            count+=15;
                            i+=2;
                            break;
                        }
                        //std::cout <<buffer.at(i)<<buffer.at(i+1)<<buffer.at(i+2)<<std::endl;
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
    return count ;
}
*/

int Alghoritms::brutalAlgoritm(std::vector<char> buffer) {
    Worker worker('A','B');
    int i = 0;
    int countA,countB,countC,countD, minCount;
    countA = fourTreeChange(buffer,i,worker,'A');
    countB = fourTreeChange(buffer,i,worker,'B');
    countC = fourTreeChange(buffer,i,worker,'C');
    countD = fourTreeChange(buffer,i,worker,'D');
    minCount =std::min(std::min(std::min(countA,countB),countC),countD);
    //std::cout<<std::endl << "brutal count = " <<minCount<<std::endl;
    return minCount;
}


int Alghoritms::fourTreeChange(std::vector<char> buffer, int i, Worker worker, char letter) {


    int count,countA,countB,countC,countD;

    count = countA = countB = countC = countD = 0;

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

int Alghoritms::alternativeAlghoritm(std::vector<char> buffer) {

    Worker worker('A','B');
    int i,count, no,j;
    char firstMyLetter, firstNotMyLetter;
    count = i = 0;
    //j = 1;
    //std::cout <<buffer.size();
    while (i<buffer.size())
    {
        if(worker.isMyLetter(buffer.at(i)))
        {
            //std::cout <<buffer.at(i)<<std::endl;
            count+=5;
            ++i;
            //std::cout << "actual count = "<<count <<std::endl;
            continue;
        }
        no = 0;
        if(i+1<buffer.size())
        if(!worker.isMyLetter(buffer.at(i+1)))
        {
            //std::cout<<"both first and second letter is not myLetter"<<std::endl;
            count+=10;
            firstNotMyLetter = buffer.at(i);
            ++i;
            //if(i+1<buffer.size())
            while(buffer.at(i)==firstNotMyLetter)
            {
                //std::cout<<"Letter i+1 = i"<<std::endl;
                ++no;
                ++i;
                if(i>=buffer.size())
                {
                  //  std::cout << "same letters till the end "<<buffer.at(i-1) << std::endl;
                    count+=no*5;
 //                   std::cout <<std::endl<<"alter Alghoritm count = "<<count <<std::endl ;
                    return count ;
                }
            }
            count+=no*5;

            worker.callWorker(firstNotMyLetter, buffer.at(i));
            //std::cout << "Called worker with letters: " << firstNotMyLetter <<buffer.at(i) << std::endl;
            //std::cout << "actual count = "<<count <<std::endl;
            continue;
        }

        if(i+1>=buffer.size())
        {
            count+=10;
            break;
        }

        //std::cout << "first is not  my letter, second is my letter lets check out rest"<< std::endl;
        firstNotMyLetter = buffer.at(i);
        firstMyLetter = buffer.at(i+1);
        //std::cout << "first not my letter :"<<buffer.at(i) <<std::endl;
        //std::cout << "first my letter : " << buffer.at(i+1) <<std::endl;
        count += 15; // bo nie ważne czy zawołamy czy nie za pierwszą nie naszą 10 i za drugą naszą 5
        // slee
        //std::cout <<"count += 15  bo nie ważne czy zawołamy czy nie za pierwszą nie naszą 10 i za drugą naszą 5"<<std::endl;
        no = 0;
        i+=2;
        //std::cout << "i = " << i <<std::endl;
        //std::cout << "iii"<<std::endl;
        if(i < buffer.size()) {
            //std::cout << "i < buffer.size()"<<std::endl;

            //std::cout << "buffer.at(i) "<<buffer.at(i)<<std::endl;
            while (buffer.at(i) == firstMyLetter) {
              //  std::cout << "aktualna litera jest taka sama jak moja pierwsza litera" << std::endl;
                //slee
                ++no;
                ++i;
                if (i >= buffer.size()) {
                //    std::cout << "litera jest taka sama do końca" << buffer.at(i-1) << std::endl;
                    count+=no*5;
//                    std::cout <<std::endl<<"alter Alghoritm count = "<<count <<std::endl ;
                    return count ;
                }
            }
        }
        else
        {
            //std::cout << "nie mieszczę się już w buforze" <<std::endl;
            break;
        }

        //std::cout<<"count+=no*5 ; no = " <<no<<std::endl;
        count += no*5;

        if(worker.isMyLetter(buffer.at(i)))
        {
            //std::cout <<"Moja druga litera worker niezawołany, aktualna litera : " << buffer.at(i)<<std::endl;
            continue;
        }
        if(buffer.at(i) == firstNotMyLetter)
        {
            //std::cout <<"worker zawolany bo znalazlem firstNotMyLetter" <<std::endl;
            worker.callWorker(firstMyLetter, firstNotMyLetter);
        }
        else {
            j = 1;
            //std::cout << "This letter is not my letter and its not firstNotMyLetter"<<std::endl;
            //std::cout <<"Buffer before choose"<<buffer.at(i)<<std::endl;
            //std::cout <<"Next buffer : "<<buffer.at(i+1)<<std::endl;
            //std::cout <<"j = "<<j <<std::endl;

           // sleep(1);
            /*if(i+1>=buffer.size()) {
                std::cout <<"alter Alghoritm count = "<<count <<std::endl ;
                return count;
            }*/
            while (i+j<buffer.size()) {
                //sleep(1);
                //std::cout <<buffer.at(i+j)<<std::endl;
                if(buffer.at(i+j)==firstMyLetter) {
                    ++j;
                    continue;
                }
                if(buffer.at(i+j)==firstNotMyLetter) {
                  //  std::cout << "worker zawolany inny przypadek ssss- test, aktualna litera : " << buffer.at(i)
                    //          << std::endl;
                    worker.callWorker(firstMyLetter, firstNotMyLetter);
                    break;
                }
                if(!worker.isMyLetter(buffer.at(i+j))) {
                    //std::cout << "Worker nie wołamy, bo nast litera jest inna litera"<<std::endl;
                    break;
                }
                if (worker.isMyLetter(buffer.at(i+1)) && buffer.at(i)!=firstMyLetter) {
                    //std::cout << "Worker nie zawołany, bo następna litera jest moją literą" << std::endl;
                    break;
                }
            }


        }

    }
//    std::cout <<"alter Alghoritm count = "<<count <<std::endl ;
    return count;

}
