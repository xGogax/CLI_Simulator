#include "Time.h"

Time::Time(){
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    tm* localTime = localtime(&currentTime);

    hh = localTime->tm_hour;
    mm = localTime->tm_min;
    ss = localTime->tm_sec;
}

string Time::execute(string _){
    ostringstream oss;
    oss << setfill('0') << setw(2) << hh << ":"
            << setfill('0') << setw(2) << mm << ":"
            << setfill('0') << setw(2) << ss << '\n';
    return oss.str();
}
