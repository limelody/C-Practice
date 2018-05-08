//Melody Li Assignment 9 Question 2
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

int numberSearch(int start, int ending, int & counter)
{
    if (ending - start < 0)
    {
        cout << "Lie in the instructions!";
        return -1;
    }

    int midpoint = (ending + start)/2;
    char answer = 'n';

    cout << "Is the number " << midpoint << "? "
         << "Enter (y)es, (l)ower, (h)igher: ";
    cin >> answer;


    if (answer == 'y')
    {
        cout << "Your secret number is " << midpoint << ". I guessed in "
             << counter << " guesses." << endl;
        return midpoint;
    }


    else if (answer == 'l')
    {
        ending = midpoint - 1;
        counter++;
        return numberSearch(start, ending, counter);
    }

    else if (answer == 'h')
    {
        start = midpoint + 1;
        counter++;
        return numberSearch(start, ending, counter);
    }
}

int main()
{
    cout << "Enter a start and end number: ";
    int start_num = 0, ending_num = 0, counter = 1;
    cin >> start_num >> ending_num;
    int secret_num = numberSearch(start_num, ending_num, counter);

    return EXIT_SUCCESS;
}

/*
Enter a start and end number: 1 49
Is the number 25? Enter (y)es, (l)ower, (h)igher: h
Is the number 37? Enter (y)es, (l)ower, (h)igher: h
Is the number 43? Enter (y)es, (l)ower, (h)igher: l
Is the number 40? Enter (y)es, (l)ower, (h)igher: l
Is the number 38? Enter (y)es, (l)ower, (h)igher: y
Your secret number is 38. I guessed in 5 guesses.

Process returned 0 (0x0)   execution time : 10.454 s
Press any key to continue.

*****************************************************************************

Enter a start and end number: 1 14
Is the number 7? Enter (y)es, (l)ower, (h)igher: h
Is the number 11? Enter (y)es, (l)ower, (h)igher: l
Is the number 9? Enter (y)es, (l)ower, (h)igher: h
Is the number 10? Enter (y)es, (l)ower, (h)igher: l
Lie in the instructions!
Process returned 0 (0x0)   execution time : 10.289 s
Press any key to continue.

*/
