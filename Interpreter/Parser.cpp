//
// Created by xGogax on 12/3/2024.
//

#include "Parser.h"

Command * Parser::parse(string input) {
    string firstWord = input.substr(0, input.find(" "));
    if(input.find(" ") != string::npos) {
        input = input.substr(input.find(" ") + 1, string::npos - firstWord.length());
    }
    if (firstWord == "echo") {
        return new Echo(input);
    } else if (firstWord == "time") {
        return new Time();
    } else if (firstWord == "date") {
        return new Date();
    } else if (firstWord == "touch") {
        return new Touch(input);
    } else if (firstWord == "wc") {
        return new WC(input);
    } else {
        cerr << "Syntax error" << endl;
        return nullptr;
    }

}
