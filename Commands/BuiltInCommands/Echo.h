#ifndef ECHO_H
#define ECHO_H

#include <string>

#include "../Command.h"

using namespace std;

class Echo : public Command {
public:
    Echo(string text) : Command(text) {}

protected:
    virtual string execute(string argument);
};

#endif
