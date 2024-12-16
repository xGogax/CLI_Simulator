#include "Interpreter.h"

string Interpreter::prompt = "$";

string Interpreter::getMultipleLines() {
    string input = "";
    string line;

    if (cin.eof()) {
        cin.clear();
    }

    while (getline(cin, line)) {
        if (!input.empty()) {
            input += "\n";
        }
        input += line;
    }

    return "\"" + input + "\"";
}

string Interpreter::getNextLine() {
    char input[513];

    int i;
    for (i = 0; i < 512; i++) {
        input[i] = getchar();
        if (input[i] == '\n') {
            break;
        }
    }

    if(input[i] == '\n') {
        input[i] = '\0';
        return string(input);
    }

    input[i] = '\0';
    while (getchar() != '\n');

    return string(input);
}

void Interpreter::removeMultipleSpaces(string &input) {
    string output;
    bool inSpace = false;
    bool inQuotes = false;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ' && inQuotes == false) {
            if (!inSpace) {
                output += ' ';
                inSpace = true;
            }
        } else {
            output += input[i];
            inSpace = false;
        }

        if(input[i] == '"') {
            inQuotes = !inQuotes;
        }
    }
    input = output;
}
