#include "WC.h"

string WC::parse() {
    if (command.find('"') != string::npos) {
        int index1 = command.find('"') + 1;
        int index2 = command.rfind('"');
        argument = command.substr(index1, index2 - index1);
    } else {
        int index = command.rfind(' ');
        argument = command.substr(index + 1, string::npos - index);
        argument = readFile(argument);
    }

    if(command.find("-w") != string::npos) {
        return to_string(executeWord(argument)) + "\n";
    } else if(command.find("-c") != string::npos) {
        return to_string(executeChar(argument)) + "\n";
    }

    return "ERROR";
}

string WC::execute(string text) {
    return "";
}

int WC::executeWord(string text) {
    int wordCount = 0;
    bool inWord = false;

    for (char ch : text) {
        if (isspace(ch)) {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            wordCount++;
        }
    }

    return wordCount;
}

int WC::executeChar(string text) {
    int charCount = 0;

    for (char ch : text) {
        if (!std::isspace(ch)) {
            charCount++;
        }
    }

    return charCount;
}

