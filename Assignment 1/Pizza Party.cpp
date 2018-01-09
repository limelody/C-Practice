//Melody Li
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
	int number_pizzas = 0, number_students = 0;
	cout << "Enter the number of pizzas: ";
	cin >> number_pizzas;
	cout << "Enter the number of students in the class: ";
	cin >> number_students;
	float total_surfacearea = (float)number_pizzas * M_PI * pow(17,2);
	cout << "The pizzas have a total surface area of "
		 << total_surfacearea << "cm^2." << endl
		 << "Each student receives " << total_surfacearea / number_students
		 << "cm^2 of pizza."; //assuming all students receive the same amount

	return 0;
}

    /*Enter the number of pizzas: 22
    Enter the number of students in the class: 11
    The pizzas have a total surface area of 19974.2cm^2.
    Each student receives 1815.84cm^2 of pizza. */

    /*Enter the number of pizzas: 5
    Enter the number of students in the class: 9
    The pizzas have a total surface area of 4539.6cm^2.
    Each student receives 504.4cm^2 of pizza. */

    /*Enter the number of pizzas: 6
    Enter the number of students in the class: 0
    The pizzas have a total surface area of 5447.52cm^2.
    Each student receives infcm^2 of pizza. */
