//
// Created by Wasiollo on 07.11.17.
//

#ifndef AAL_WORKER_H
#define AAL_WORKER_H


class Worker {
public:
    Worker();

    Worker(char A, char B);

    Worker(const Worker &orig);

    virtual ~Worker();

    void callWorker(char A, char B);

    bool isMyLetter(char other);

private:
    char first;
    char second;

};

#endif //AAL_WORKER_H
