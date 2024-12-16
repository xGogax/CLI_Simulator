//
// Created by xGogax on 12/16/2024.
//

#include "Truncate.h"

string Truncate::execute(string filename) {
    ofstream file(filename, ios::trunc);

    if (!file) {
        cerr << "Error: Unable to open file " + filename << endl;
    }

    file.close();
    return "";
}
