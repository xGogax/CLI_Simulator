#ifndef TOUCH_H
#define TOUCH_H

#include <string>
#include <fstream>
#include <iostream>

#include "../Command.h"

using namespace std;

class Touch : public Command {
public:
    Touch(string filename) : Command(filename) {
        shouldReadFromFile = false;
    }

private:
    virtual string execute(string filename);
};

#endif