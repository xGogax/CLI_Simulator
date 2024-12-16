//
// Created by xGogax on 12/16/2024.
//

#include "Prompt.h"

string Prompt::execute(string argument) {
    if(argument.empty()) {
        return "Error: No prompt specified.\n";
    }
    Interpreter::prompt = argument;
    return "";
}
