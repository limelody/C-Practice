#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    int time1 = 0;
    int time2 = 0;

    do
    {
        cout << "Enter earlier time (hhmm): ";
        cin >> time1;
    }
    while (time1 > 2400 || time1 < 0 || time1 % 1 != 0 || time1 % 100 >= 60);

    do
    {
        cout << "Enter later time (hhmm): ";
        cin >> time2;
    }
    while (time2 > 2400 || time2 < 0 || time2 % 1 != 0 || time2 % 100 >= 60);
    //assume the user will enter the the earlier time first

    int hour1 = time1/100,
        hour2 = time2/100,
        minute1 = time1%100,
        minute2 = time2%100;

    int d_time = 0;

    if (hour2 == hour1)
        d_time = (time2 - time1);

    else if (minute2 == minute1)
        d_time = (time2 - time1)*6/10 ;

    else if (minute2 > minute1)
        d_time = (hour2 - hour1)*60 + (minute2 - minute1);

    else
        d_time = (minute2 + 60 - minute1) + (hour2 - 1 - hour1)*60;

    cout << "There are " << d_time << " minutes between them.";

    return 0;
}
