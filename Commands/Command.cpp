#include "Command.h"

string Command::parse() {
    if (command.find('"') != string::npos) {
        int index1 = command.find('"') + 1;
        int index2 = command.rfind('"');
        argument = command.substr(index1, index2 - index1);
    } else if(shouldReadFromFile == true){
        argument = Command::readFile(command);
    } else {
        argument = command;
    }

    string output = execute(argument);

    return output;
}

string Command::readFile(string filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        cout << "ERROR: Unable to open file" << endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    file.close();

    return buffer.str();
}