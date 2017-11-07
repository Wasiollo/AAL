//
// Created by Wasiollo on 07.11.17.
//

#ifndef AAL_GENERATOR_H
#define AAL_GENERATOR_H


#include <string>

class Generator {
public:
    Generator();
    Generator(const Generator& orig);
    virtual ~Generator();

    static std::string generate(int = 10000, int = 4);

private:

};

#endif //AAL_GENERATOR_H
