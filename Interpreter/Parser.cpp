#include "Parser.h"

#include "Interpreter.h"
#include "../Commands/BuiltInCommands/Head.h"

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
    } else if(firstWord == "truncate") {
        return new Truncate(remainingInput);
    } else if(firstWord == "rm") {
        return new RM(remainingInput);
    } else if(firstWord == "tr") {
        stringstream ss(remainingInput);

        string filename, what, with;

        ss >> filename;
        ss >> what;
        ss >> with;

        return new TR(filename,what,with);
    } else if(firstWord == "head") {
        stringstream ss(remainingInput);

        string number, filename;

        ss >> number;
        ss >> filename;

        return new Head(stoi(number), filename);
    }
    else {
        cerr << "Syntax error" << endl;
        return nullptr;
    }

}

