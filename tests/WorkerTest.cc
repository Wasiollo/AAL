/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WorkerTest.cc
 * Author: mateusz
 *
 * Created on 22 października 2017, 15:35
 */

#include <stdlib.h>
#include <iostream>
#include "Worker.h"

/*
 * Simple C++ Test Suite
 */

void testGetStatus() {
    Worker worker;
    bool result = worker.getStatus();
    if (result) {
        std::cout << "%TEST_FAILED% time=0 testname=testGetStatus (WorkerTest) message=error message sample" << std::endl;
    }
}

void testSetSatus() {
    bool status;
    Worker worker;
    worker.setSatus(true);
    bool result = worker.getStatus();
    if (!result) {
        std::cout << "%TEST_FAILED% time=0 testname=testSetSatus (WorkerTest) message=error message sample" << std::endl;
    }
}

void testGetSpec() {
    Worker worker;
    char* result = worker.getSpec();
    if (result[0] != 'A' || result[1]!= 'B') {
        std::cout << "%TEST_FAILED% time=0 testname=testGetSpec (WorkerTest) message=error message sample" << std::endl;
    }
}

void testSetSpec() {
    char p0 = 'C';
    char p1 = 'D';
    Worker worker;
    worker.setSpec(p0, p1);
    char* result = worker.getSpec();
    if (result[0] != 'C' || result[1]!= 'D') {
        std::cout << "%TEST_FAILED% time=0 testname=testSetSpec (WorkerTest) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% WorkerTest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testGetStatus (WorkerTest)" << std::endl;
    testGetStatus();
    std::cout << "%TEST_FINISHED% time=0 testGetStatus (WorkerTest)" << std::endl;

    std::cout << "%TEST_STARTED% testSetSatus (WorkerTest)" << std::endl;
    testSetSatus();
    std::cout << "%TEST_FINISHED% time=0 testSetSatus (WorkerTest)" << std::endl;

    std::cout << "%TEST_STARTED% testGetSpec (WorkerTest)" << std::endl;
    testGetSpec();
    std::cout << "%TEST_FINISHED% time=0 testGetSpec (WorkerTest)" << std::endl;

    std::cout << "%TEST_STARTED% testSetSpec (WorkerTest)" << std::endl;
    testSetSpec();
    std::cout << "%TEST_FINISHED% time=0 testSetSpec (WorkerTest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

