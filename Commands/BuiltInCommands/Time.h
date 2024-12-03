#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <chrono>
#include <ctime>

#include "../Command.h"

using namespace std;

class Time : public Command {
public:
    Time();

protected:
    int hh;
    int mm;
    int ss;

    virtual string execute(string _);
};

#endif //TIME_H
