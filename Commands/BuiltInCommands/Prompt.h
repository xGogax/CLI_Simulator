#ifndef PROMPT_H
#define PROMPT_H

#include "../Command.h"
#include "../../Interpreter/Interpreter.h"

class Prompt : public Command {
public:
    Prompt(string argument) : Command(argument) {}
protected:
    virtual string execute(string argument);;
};

#endif
