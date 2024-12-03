#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

#include "../Command.h"

using namespace std;

class Date : public Command {
public:
    Date();

protected:
    int dd;
    int mm;
    int yy;

    virtual string execute(string _);
};

#endif