#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream fin;
    fin.open ("taxi.txt");

  	ofstream fout;
    fout.open ("report.txt");

    if (!fin)
        cout << "Unable to open file";

    fout << setw(15) << "Trip Number" << setw(15) << "Return Trip" << setw(20)
         << "Number of Stops" << setw(15) << "Distance" << setw(10)
         << "Cost" << setw(15) << "Cumulative" << setw(15) << "Cumulative"
         << endl << setw(90) << "Distance" << setw(15) << "Cost" << endl;

    int trip_Number = 0;
    bool returnTrip = 0;
    double culm_distance = 0;
    double culm_cost = 0;
    double max_tripdistance = 0;
    double min_tripcost = 4000; //ensures that a minimum is found

    while (fin >> returnTrip)
    {
      trip_Number++;

      int n_Stops = 0;
      fin >> n_Stops;

      double total_distance_travelled = 0;
      double distance_travelled = 0;
      double x1 = 0, y1 = 0; //coordinates before the next one
      double x2 = 0, y2 = 0; //coordinates that will be inputed from text

      for (int leg = 0; leg < n_Stops; leg++)
      {
          fin >> x2 >> y2;
          distance_travelled = sqrt(pow(x2-x1, 2) + pow(y2-y1,2));
          total_distance_travelled += distance_travelled;
          x1 = x2;
          y1 = y2;
      }

      if (returnTrip == 1)
        total_distance_travelled += sqrt(pow(x2,2)+pow(y2,2));

      if (total_distance_travelled > max_tripdistance)
        max_tripdistance = total_distance_travelled;

      double const RATE_EACHSTOP = 11.00;
      double const RATE_KM = 2.70;

      double cost = 0;
      cost = (RATE_EACHSTOP * n_Stops) + (RATE_KM * total_distance_travelled);

      if (cost < min_tripcost)
        min_tripcost = cost;

      culm_distance += total_distance_travelled;

      culm_cost += cost;

      if (trip_Number <= 5 || trip_Number%5==0 && trip_Number%10!=0)
      {
        fout << setw(15) << trip_Number;

        fout << setw(15) << returnTrip;

        fout << setw(20) << n_Stops;

        fout << fixed << setprecision(2) << setw(15)
             << total_distance_travelled;

        fout << fixed << setprecision(2) << setw(10)
             << cost;

        fout << fixed << setprecision(2) << setw(15)
             << culm_distance;

        fout << fixed << setprecision(2) << setw(15)
             << culm_cost << endl;
      }
    }

    fout << endl << "Cumulative distance for all of August: " << culm_distance;
    fout << endl << "Cumulative amount collected: " << culm_cost;
    fout << endl << "Longest trip: " << max_tripdistance;
    fout << endl << "Least expensive trip: " << min_tripcost;

    return 0;
}

