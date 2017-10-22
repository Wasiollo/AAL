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

#include "Worker.h"

/*
 * 
 */
int main(int argc, char** argv) {

    for (int i=0 ; i < argc ; i++)
	{
		std::cout << " argv[" << i << "] = " << argv[i] << "\n" ; 		
	}	

	Worker tom('A','B') ;
        tom.setSatus(true);
        char * currentSpec = tom.getSpec();
        std::cout << "Status toma " << tom.getStatus() << " spec " << 
                currentSpec[0] << currentSpec[1] << std::endl;
    
    return 0;
}

