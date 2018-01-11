#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{

	cout << "Conducting Computation........" << endl;
	double x = 0;
	double root = 0;
	const double TOL = 10e-4;

	for(double x = -5.0; x <= 5.0; x+=0.0001)
	{

		if(fabs(3*pow(x,5)+11*pow(x,4)+12*pow(x,3)-7*x+5)<=TOL)
		{
			root = x;
			cout << "The root of the equation is : " << root << endl;
		}
	}

	return EXIT_SUCCESS;
}


/* TEST CASE

Conducting Computation........
The root of the equation is : -2.0993

--------------------------------
Process exited after 0.2184 seconds with return value 0
Press any key to continue . . .

*/
