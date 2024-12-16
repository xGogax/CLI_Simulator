#ifndef TRUNCATE_H
#define TRUNCATE_H

#include "../Command.h"
#include <iostream>
using namespace std;

class Truncate : public Command {
public:
    Truncate(string filename) : Command(filename) {
        shouldReadFromFile = false;
    }
private:
    virtual string execute(string filename) override;
};

#endif