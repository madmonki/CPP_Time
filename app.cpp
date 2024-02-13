#include <iostream>

#include "time.hpp"

using namespace std;

int main()
{
    Time stime{12, 52, 31};
    Time stime2{13, 05, 59};
    Time stime3{};

    stime3.totalsec(stime2.totalsec() - stime.totalsec());
    stime3.disp();
    
    // stime.disp();
    // cout << stime.hour() << endl
    //      << stime.minute() << endl
    //      << stime.second() << endl
    //      << stime.totalsec() << endl;

    return 0;
}
