#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    fin.open ("stones.txt");

    if (!fin)
    {
        cout << "Unable to find file";
        return EXIT_FAILURE;
    }

    int n_stones = 0;
    fin >> n_stones;

    ofstream fout;
    fout.open ("shapes.txt");
    fout << "Number of stones: " << n_stones;

    for (int i = 0; i < 9; i++)
    {
        float side_1 = 0, side_2 = 0, angle = 0;
        fin >> side_1 >> side_2 >> angle;
        fout << endl << side_1 << " " << side_2 << " " << angle;
        const double SIDE_TOL = 0.7;
        const double ANGLE_TOL = 0.5;

        if (fabs(side_1 - side_2)<SIDE_TOL && fabs(90 - angle) < ANGLE_TOL)
            fout << " square";

        else if (fabs(side_1 - side_2)<SIDE_TOL && fabs(90 - angle) > ANGLE_TOL)
            fout << " rhombus";

        else if (fabs(side_1 - side_2)>SIDE_TOL && fabs(90 - angle) < ANGLE_TOL)
            fout << " rectangle";

        else
            fout << " parallelogram";
    }

    fin.close();
    fout.close();

     return 0;
}
