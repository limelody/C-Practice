#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    cout << "Think of a number between 1 and 7 inclusive. "
         << "Type ok when you are ready." << endl; //assume typed correctly

    string confirmation = "some text";
    cin >> confirmation;

    if (confirmation == "ok")
    {
        string instructions =
        "Enter y if yes, h if number is higher, l if number is lower";
        //assume they will type this correctly every time

        cout << "Is the number 4?" << endl << instructions << endl;
        string answer = "y";
        cin >> answer;

        if (answer == "l")
        {
            cout << "Is the number 2?" << endl << instructions << endl;
            cin >> answer;

            if (answer == "l")
            {
                cout << "Is the number 1?" << endl << instructions << endl;
                cin >> answer;

                if (answer == "l" || answer == "h")
                {
                    cout << "You have lied in the instructions.";
                    return EXIT_FAILURE;
                }

                else if (answer == "y")
                {
                    cout << "Your secret number was 1!";
                    return EXIT_SUCCESS;
                }
            }
                      
            else if (answer == "h")
            {
                cout << "Is the number 3?" << endl << instructions<< endl;
                cin >> answer;

                if (answer == "l" || answer == "h")
                {
                    cout << "You have lied in the instructions.";
                    return EXIT_FAILURE;
                }

                else if (answer == "y")
                {
                    cout << "Your secret number was 3!";
                    return EXIT_SUCCESS;
                }
            }
            else if (answer == "y")
            {
                cout << "Your secret number was 2!";
                return EXIT_SUCCESS;
            }
        }

        else if (answer == "h")
        {
            cout << "Is the number 6?" << endl << instructions << endl;
            cin >> answer;

            if (answer == "l")
            {
                cout << "Is the number 5?" << endl << instructions << endl;
                cin >> answer;

                if (answer == "l" || answer == "h")
                {
                    cout << "You have lied in the instructions.";
                    return EXIT_FAILURE;
                }

                else if (answer == "y")
                {
                    cout << "Your secret number was 5!";
                    return EXIT_SUCCESS;
                }
            }
            
            else if (answer == "h")
            {
                cout << "Is the number 7?" << endl << instructions << endl;
                cin >> answer;

                if (answer == "l" || answer == "h")
                {
                    cout << "You have lied in the instructions.";
                    return EXIT_FAILURE;
                }

                else if (answer == "y")
                {
                    cout << "Your secret number was 7!";
                    return EXIT_SUCCESS;
                }
            }

            else if (answer == "y")
            {
                cout << "Your secret number was 6!";
                return EXIT_SUCCESS;
            }
        }

        else if (answer == "y")
        {
            cout << "Your secret number was 4!";
            return EXIT_SUCCESS;
        }
    }
    return EXIT_SUCCESS;
}

/*
Think of a number between 1 and 7 inclusive. Type ok when you are ready.
ok
Is the number 4?
Enter y if yes, h if number is higher, l if number is lower
h
Is the number 6?
Enter y if yes, h if number is higher, l if number is lower
y
Your secret number was 6!
Process returned 0 (0x0)   execution time : 6.711 s
Press any key to continue.
------------------------------------------------------------------------------
Think of a number between 1 and 7 inclusive. Type ok when you are ready.
ok
Is the number 4?
Enter y if yes, h if number is higher, l if number is lower
h
Is the number 6?
Enter y if yes, h if number is higher, l if number is lower
l
Is the number 5?
Enter y if yes, h if number is higher, l if number is lower
y
Your secret number was 5!
Process returned 0 (0x0)   execution time : 10.975 s
Press any key to continue.
------------------------------------------------------------------------------
Think of a number between 1 and 7 inclusive. Type ok when you are ready.
ok
Is the number 4?
Enter y if yes, h if number is higher, l if number is lower
l
Is the number 2?
Enter y if yes, h if number is higher, l if number is lower
l
Is the number 1?
Enter y if yes, h if number is higher, l if number is lower
h
You have lied in the instructions.
Process returned 1 (0x1)   execution time : 9.700 s
Press any key to continue.
------------------------------------------------------------------------------
*/

