#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Command {
public:
    Command(string command) : command(command) {};

    //delegirajuci konstruktor
    Command() : Command("") {}

    ~Command() = default;

    virtual string parse();

protected:
    string command;
    string argument;

    static string readFile(string filename);
    virtual string execute(string argument) = 0;
};

#endif
