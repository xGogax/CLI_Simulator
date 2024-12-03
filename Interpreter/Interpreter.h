#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include <iostream>

#include "Parser.h"
#include "../Commands/BuiltInCommands/Echo.h"
#include "../Commands/BuiltInCommands/Time.h"
#include "../Commands/BuiltInCommands/Date.h"
#include "../Commands/BuiltInCommands/Touch.h"
#include "../Commands/BuiltInCommands/WC.h"

using namespace std;

class Interpreter {
public:
    void start() {
        while(true) {
            cout << "$";
            string input = getNextLine();
            removeMultipleSpaces(input);

            Command* command = Parser::parse(input);
            cout << command->parse();
        }
    };
private:

    static string getNextLine();
    static void removeMultipleSpaces(string &input);
};

#endif
