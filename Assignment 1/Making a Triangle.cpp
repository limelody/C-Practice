//Melody Li
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{

	float side_a = 1, side_b = 1, side_c = 1;
	cout << "Enter the three side lengths (largest side length last): ";
	cin >> side_a >> side_b >> side_c; //assume last side is longest

	if (side_a <= 0 || side_b <= 0 || side_c <= 0 || side_a + side_b <= side_c)
        {
        cout << "These side lengths do not form a triangle. ";
        return EXIT_FAILURE;
        }


	cout << "By the Cosine Law, ";
	double angle_A = 10.1, angle_B = 10.1, angle_C = 10.1;

	angle_A = acos(( pow(side_b, 2) + pow(side_c, 2) - pow(side_a, 2))
			  / (side_b * side_c * 2));

	angle_B = acos(( pow(side_a, 2) + pow(side_c, 2) - pow(side_b, 2))
			  / (side_a * side_c * 2));

	angle_C = acos((pow(side_a, 2) + pow(side_b, 2) - pow(side_c, 2))
			  / (side_a * side_b * 2));

	const double RAD2DEG = 180 / M_PI;

	cout << "the angles are "
         << angle_A * RAD2DEG << ", "
		 << angle_B * RAD2DEG << ", and "
		 << angle_C * RAD2DEG << " degrees." << endl;

	cout << "By the Sine Law, ";

	angle_A = asin(side_a * sin(angle_C) / side_c);
	angle_B = asin(side_b * sin(angle_A) / side_a);
	angle_C = asin(side_c * sin(angle_B) / side_b);

	cout << "the angles are "
         << angle_A * RAD2DEG << ", "
		 << angle_B * RAD2DEG << ", and "
		 << angle_C * RAD2DEG << " degrees." << endl;

	float semi_p = 1;
	semi_p = (side_a + side_b + side_c) / 2;
	cout << "The area of the triangle is " << sqrt(semi_p * (semi_p - side_a)
			* (semi_p - side_b) * (semi_p - side_c)) << " units squared.\n";

	return EXIT_SUCCESS;
}

/*Enter the three side lengths (largest side length last): 3 4 5
By the Cosine Law, the angles are 36.8699, 53.1301, and 90 degrees.
By the Sine Law, the angles are 36.8699, 53.1301, and 90 degrees.
The area of the triangle is 6 units squared.*/

/*Enter the three side lengths (largest side length last): 13 13 24.021
By the Cosine Law, the angles are 22.4992, 22.4992, and 135.002 degrees.
By the Sine Law, the angles are 22.4992, 22.4992, and 44.9985 degrees.
The area of the triangle is 59.7489 units squared.*/

/*There is a difference between the final angle in the (13, 13 24.021) case
because the range of arcsin is between [0, pi/2] . While the cosine law takes
in account the ambiguous case by using the side lengths to calculate the
angles, the sine law is limited by its range to calculate only the acute angle.
*/
