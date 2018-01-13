#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

int hours(int time_hhmmss)
{
    return (time_hhmmss - time_hhmmss%10000)/10000;
}

int minutes(int time_hhmmss)
{
    return (time_hhmmss%10000 - time_hhmmss%100)/100;
}

int seconds(int time_hhmmss)
{
    return time_hhmmss%100;
}

double xcoordinate(double heading, double distance)
{
    return distance * cos(heading * M_PI / 180);
}

double ycoordinate(double heading, double distance)
{
    return distance * sin(heading * M_PI / 180);
}

int get_duration(int start_hours, int start_minutes, int start_seconds,
                 int end_hours, int end_minutes, int end_seconds)
{
    if (end_hours != 0 || end_hours == 0 && start_hours == 0)
        return (end_hours - start_hours) * 3600 +
               (end_minutes - start_minutes) * 60 +
               (end_seconds - start_seconds);

    /*do not need conditions for negative values of end - start because the
    previous subtraction accounts for them*/

    else if (start_hours == 23 && end_hours == 0)
        return (24 - start_hours) * 3600 +
               (end_minutes - start_minutes) * 60 +
               (end_seconds - start_seconds);
}

int main()
{
    ifstream fin ;
    fin.open ("wascally_wabbits.txt");

    if (!fin)
        cout << "Unable to open file";

    int last_Rabbit_Number = 0;
    int current_Rabbit_Number = 0;
    int launch_Time = 0;
    double angle_Heading = 0;
    double distance_Rabbit = 0;
    int cul_Time = 0;
    int start_hours = 0, start_minutes = 0, start_seconds = 0,
          end_hours = 0,   end_minutes = 0,   end_seconds = 0;


    cout << setw(6) << "Rabbit" << setw(12) << "Time" << setw(17)
         << "Coordinates" << setw(15) << "Last Launch" << endl;


    while(fin >> current_Rabbit_Number)
    {

        fin >> launch_Time >> angle_Heading >> distance_Rabbit;

        end_hours = hours(launch_Time);
        end_minutes = minutes(launch_Time);
        end_seconds = seconds(launch_Time);

        cout << setw(6) << current_Rabbit_Number << "    "
			 << setfill ('0') << setw(2) << end_hours << ":"
        	 << setw(2) << end_minutes << ":"
        	 << setw(2) << end_seconds << fixed << setprecision(2)
        	 << setfill (' ') << setw(4) << "(" << setw(5)
        	 << xcoordinate(angle_Heading, distance_Rabbit) << "," << setw(6)
        	 << ycoordinate(angle_Heading, distance_Rabbit) << ")";

        if (last_Rabbit_Number == current_Rabbit_Number)
        {

            cout << setw(15) << get_duration(start_hours, start_minutes,
                                start_seconds, end_hours, end_minutes,
                                end_seconds) << endl;
        }

		else
		{
			last_Rabbit_Number = current_Rabbit_Number;
			cout << setw(15) << "0" << endl;
		}

        start_hours = end_hours;
        start_minutes = end_minutes;
        start_seconds = end_seconds;
    }

    return 0;
}
