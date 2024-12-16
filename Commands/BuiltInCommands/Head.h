#ifndef HEAD_H
#define HEAD_H
#include "../Command.h"

class Head : public Command{
public:
    Head(int n, string filename) : Command(filename) {
        this->n = n;
    };
protected:
    virtual string execute(string argument) override {
        stringstream ss(argument);
        string line;
        int count = 0;

        // Čitaj prvih n linija
        while (getline(ss, line) && count < n) {
            cout << line << endl;
            count++;
        }

        return "";
    }

private:
    int n;
};

#endif //HEAD_H
