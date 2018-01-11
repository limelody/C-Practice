#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
	cout << "Please enter interger value with magnitude of less than " <<
	"1,000,000: ";
	int numb = 0;
	// I assume that all inputs will be numerical values
	cin >> numb;
	
	if(not (abs(numb) < 1000000))
		cout << "Invalid Input" << endl;
	else if(abs(numb) >= 1000) {
		int firstHalf = numb / 1000;
		int secondHalf = abs(numb % 1000);
		if(secondHalf >= 100)
			cout << firstHalf << "," << secondHalf << endl;
		else if(secondHalf >= 10)
			cout << firstHalf << ",0" << secondHalf << endl;
		else if(secondHalf >= 1)
			cout << firstHalf << ",00" << secondHalf << endl;
		else
			cout << firstHalf << ",000" << endl;
	}
	else
		cout << numb << endl;
		
	return EXIT_SUCCESS;
}	

/*
Test Case 1

Please enter interger value with magnitude of less than 1,000,000: 910197
910,197
--------------------------------
Test Case 2

Please enter interger value with magnitude of less than 1,000,000: -98174
-98,174
--------------------------------
Test Case 3

Please enter interger value with magnitude of less than 1,000,000: 3002
3,002
--------------------------------
Test Case 4

Please enter interger value with magnitude of less than 1,000,000: 034
34

--------------------------------
Test Case 5

Please enter interger value with magnitude of less than 1,000,000: -1000000
Invalid Input

--------------------------------
*/
