#include "Date.h"

Date::Date() {
    shouldReadFromFile = false;

    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    tm* localTime = localtime(&currentTime);

    dd = localTime->tm_mday;
    mm = localTime->tm_mon + 1;
    yy = localTime->tm_year + 1900;
}

string Date::execute(string _){
    ostringstream oss;
    oss << setfill('0') << setw(2) << dd << "."
            << setfill('0') << std::setw(2) << mm << "."
            << yy << '\n';
    return oss.str();
}
