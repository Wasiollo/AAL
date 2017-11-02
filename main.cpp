/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mateusz
 *
 * Created on 22 października 2017, 14:38
 */

#include <cstdlib>
#include <iostream>

#include "InputOutput.h"
#include "Worker.h"



/*
 * 
 */
int main(int argc, char** argv) {
    
    std::vector<char> buffer;
    Worker worker('A','B');
    int count, i;
    
    try
    {
        buffer = InputOutput::getInput();
                 
        for (int i=0 ; i < argc ; i++)
	{
            std::cout << " argv[" << i << "] = " << argv[i] << "\n" ; 		
        }	
        
        
        count = i = 0;
        while (i<buffer.size())
        {
            if(worker.isMyLetter(buffer.at(i)))
            {
                std::cout <<buffer.at(i)<<std::endl;
                count+=5;
                ++i;
            }
            else 
            {
                if ((i+1)<buffer.size() ){
                if(!worker.isMyLetter(buffer.at(i+1)))
                {
                    std::cout <<buffer.at(i)<<buffer.at(i+1)<<std::endl;
                    count+=15;
                    worker.callWorker(buffer.at(i), buffer.at(i+1));
                    std::cout<<"Wolam: "<<buffer.at(i)<<buffer.at(i+1)<< " gdy i = " << i << " count  = " <<count <<std::endl ;
                    i+=2;
                }
                else
                {
                    if((i+3)<buffer.size()){
                        
                    std::cout <<buffer.at(i)<<buffer.at(i+1)<<buffer.at(i+2)<<buffer.at(i+3)<<std::endl;
                    if(worker.isMyLetter(buffer.at(i+2)) && worker.isMyLetter(buffer.at(i+3)))
                    {
                        std::cout <<buffer.at(i)<<buffer.at(i+1)<<buffer.at(i+2)<<buffer.at(i+3)<<std::endl;
                        count+=25;
                        i+=4;
                    }
                    else
                    {
                        count+=15;
                        worker.callWorker(buffer.at(i), buffer.at(i+1));
                        std::cout<<"Wolam: "<<buffer.at(i)<<buffer.at(i+1)<< " gdy i = " << i << " count  = " <<count <<std::endl ;
                        i+=2;
                    }
                    }
                    else{
                        std::cout<< "nie ma 4 elementow na koniec"<<std::endl;
                        break;
                    }                        
                }
            }
                
            else{
                std::cout << "nie ma 2 elementów na koniec"<<std::endl;
                break;
            }
            }
           
        }
    
    }
    catch(std::string e)
    {
        std::cout << e << std::endl;
        return -1;
    }
    
    std::cout <<"count "<<count<<std::endl;
    
    return 0;
}

