//
// Created by xGogax on 12/3/2024.
//

#include "Parser.h"

#include "Interpreter.h"
#include "../Commands/BuiltInCommands/Prompt.h"

Command * Parser::parse(string input) {
    size_t spacePos = input.find(" ");
    string firstWord;
    string remainingInput;

    if (spacePos != string::npos) {
        firstWord = input.substr(0, spacePos);
        remainingInput = input.substr(spacePos + 1);
    } else {
        firstWord = input;
        remainingInput = "";
    }

    if (firstWord == "echo") {
        if(remainingInput.empty()) {
            remainingInput = Interpreter::getMultipleLines();
        }
        return new Echo(remainingInput);
    } else if (firstWord == "time") {
        return new Time();
    } else if (firstWord == "date") {
        return new Date();
    } else if (firstWord == "touch") {
        return new Touch(remainingInput);
    } else if (firstWord == "wc") {
        string x = remainingInput;
        x = x.substr(2,string::npos);

        if(x.empty()) {
            remainingInput = remainingInput.substr(0,2) + Interpreter::getMultipleLines();
        }

        return new WC(remainingInput);
    } else if(firstWord == "prompt") {
        return new Prompt("\"" + remainingInput + "\"");
    }
    else {
        cerr << "Syntax error" << endl;
        return nullptr;
    }

}

