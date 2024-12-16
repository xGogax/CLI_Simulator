#ifndef TR_H
#define TR_H
#include "../Command.h"
#include <fstream>

class TR : public Command {
public:
    TR(string filename, string what, string with) : Command(filename){
        this->what = what;
        this->with = with;
        this->filename = filename;
    }

protected:
    virtual string execute(string argument) {
        size_t pos = 0;

        while((pos = argument.find(what, pos)) != string::npos) {
            argument.replace(pos, what.length(), with);
            pos += with.length();
        }

        ofstream outputFile(filename);
        if (outputFile.is_open()) {
            outputFile << argument;
            outputFile.close();
        } else {
            cerr << "Error: Could not open file for writing." << endl;
        }

        return "";
    }
private:
    string filename;
    string what;
    string with;
};

#endif //TR_H
