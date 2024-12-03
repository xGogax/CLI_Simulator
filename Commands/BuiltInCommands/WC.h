#ifndef WC_H
#define WC_H

#include <string>

#include "../Command.h"

using namespace std;

class WC : public Command{
public:
    WC(string text) : Command(text){}

    string parse() override;

protected:
    virtual string execute(string text);

    int executeWord(string text);
    int executeChar(string text);
};

#endif //WC_H
