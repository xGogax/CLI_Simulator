#ifndef RM_H
#define RM_H

#include "../Command.h"
#include <cstdio>

class RM : public Command{
public:
    RM(string filename) : Command(filename) {
        shouldReadFromFile = false;
    }
protected:
    virtual string execute(string filename) {
        if (std::remove(filename.c_str()) != 0) {
            cerr << "Error: Unable to delete file " << filename << endl;
            return "";
        }

        return "";
    }
};

#endif
