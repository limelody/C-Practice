// Melody Li
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    double side_length = 0;

    cout << "Enter the length of each side (in cm): ";

    cin >> side_length;

    cout << "The area of a square of side length " << side_length
         << "cm is " << side_length * side_length << "cm^2" << endl;
    cout << "The volume of a cube of side length " << side_length
         << "cm is " <<  side_length * side_length * side_length << "cm^3"
		 << endl;
    cout << "The area of a pentagon of side length " << side_length << "cm is "
		 <<  0.25 * sqrt(5 * (5 + 2 * sqrt(5))) * side_length * side_length
		 << "cm^3" << endl;

    return EXIT_SUCCESS;
}

/*

Enter the length of each side (in cm): 8
The area of a square of side length 8cm is 64cm^2
The volume of a cube of side length 8cm is 512cm^3
The area of a pentagon of side length 8cm is 110.111cm^3

*/
