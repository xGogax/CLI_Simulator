#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include <iostream>
#include <sstream>

#include "Parser.h"

#include "../Commands/BuiltInCommands/Echo.h"
#include "../Commands/BuiltInCommands/Time.h"
#include "../Commands/BuiltInCommands/Date.h"
#include "../Commands/BuiltInCommands/Touch.h"
#include "../Commands/BuiltInCommands/WC.h"
#include "../Commands/BuiltInCommands/Prompt.h"
#include "../Commands/BuiltInCommands/RM.h"
#include "../Commands/BuiltInCommands/Truncate.h"
#include "../Commands/BuiltInCommands/TR.h"
#include "../Commands/BuiltInCommands/Batch.h"
#include "../Commands/BuiltInCommands/Head.h"

using namespace std;

class Interpreter {
public:
    static string prompt;

    void start() {
        Command* command = nullptr;
        while(true) {
            cout << prompt;

            string input = getNextLine();
            if(input == "exit") {
                break;
            }
            removeMultipleSpaces(input);

            command = Parser::parse(input);

            cout << command->parse();
        }
        delete command;
    };

    static string getMultipleLines();
private:
    static string getNextLine();
    static void removeMultipleSpaces(string &input);
};

#endif
