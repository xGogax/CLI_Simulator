#ifndef PARSER_H
#define PARSER_H

#include "../Commands/BuiltInCommands/Echo.h"
#include "../Commands/BuiltInCommands/Time.h"
#include "../Commands/BuiltInCommands/Date.h"
#include "../Commands/BuiltInCommands/Touch.h"
#include "../Commands/BuiltInCommands/WC.h"

#include <string>

using namespace std;

class Parser {
public:
    static Command* parse(string input);
private:
};

#endif
