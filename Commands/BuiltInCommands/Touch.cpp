#include "Touch.h"

string Touch::execute(string filename) {
    // Proveri da li fajl postoji
    ifstream fileCheck(filename);
    if (fileCheck.good()) {
        // Fajl postoji
        cout << "File \"" << filename << "\" already exists." << endl;
    } else {
        // Fajl ne postoji - kreiraj ga
        ofstream newFile(filename);
        if (newFile.is_open()) {
            newFile.close();
        } else {
            cerr << "Error: Unable to create file \"" << filename << "\"." << endl;
        }
    }

    return "";
}
