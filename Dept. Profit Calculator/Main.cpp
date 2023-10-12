// Department Profit Calculator.cpp

#include <iostream> // For inputs
#include <string> // For getline
#include "Department.h" // Department header file

using namespace std; // Using namespace std

int main()
{
    Department obj; // Class object
    string name;
    float cost = 0.0;
    int cap = 0;
    cout << "Please enter the department name: ";
    getline(cin, name); // Allows for spaces in the input
    obj.setDeptName(name); // Sends name to the setDeptName function
    cout << "\nPlease enter the dollar amount of products this department has used: $";
    cin >> cost;
    while (cin.fail() || cost < 0) // Error checks the cost
    {
        cin.clear(); // Clears the error state
        cin.ignore(10000, '\n'); // Ignores anything else in the input stream
        cout << "\nError. Please enter a valid amount: $"; // Reask statement
        cin >> cost;
    }
    obj.setProductCost(cost); // Sends the cost of products to the setProductCost in the Department class
    cout << "\nPlease enter the total capacity (max number of employees) for the given depament (max. 50): ";
    cin >> cap;
    while (cin.fail() || cap > 50 || cap < 0) // Error check to see if the input is in the capacity range
    {
        cin.clear(); // Clears the error state
        cin.ignore(10000, '\n'); // Ignores anything else in the input stream
        cout << "\nError. Please enter a valid number of employees (up to 50): "; // Reasks statement
        cin >> cap;
    }
    obj.setCapacity(cap); // Sends the total capacity to the setCapacity function in the Department class
    int eCounter = 0; // Employee counter
    int mCounter = 0; // Manager counter
    char option;
    do // Do-while loop
    {
        system("CLS"); // clears the screen
        // Main Menu
        cout << "Main Menu" << endl;
        cout << "M -- Add Manager" << endl;
        cout << "A -- Add Employee" << endl;
        cout << "R -- Remove Employee" << endl;
        cout << "L -- List Dept. Info" << endl;
        cout << "P -- Print Final Profit" << endl;
        cout << "Please Enter the Desired Operation: " << endl;
        cin >> option;
        option = toupper(option); // Capitalizes the option
        cin.ignore(1, '\n'); // Reads only the first character in the input
        switch (option) // Switch statement
        {
        case 'M': // If 'M' is chosen
        {
            if (mCounter == 0) // Checks if there is already a manager inputted
            {
                system("CLS"); // Clears the screen
                cout << "Creating a New Manager" << endl << endl;
                obj.assignManager();
                mCounter++; // Adds 1 to the manager counter
            }
            else // If there is already a manager
            {
                cout << "There is already a manager. Press Enter and Try Something Else. " << endl;
                system("pause"); // Allows the user to read the message
            }
            break; // Breaks out of switch
        }
        case 'A':
        {
            if (eCounter <= cap) // If the number of employees is less than the capacity
            {
                system("CLS");
                cout << "Creating a New Employee"<< endl << endl;
                obj.hireEmployee(); // Calls the hireEmployee function in the Department class
                eCounter++; // Adds one to the employee counter
            }
            else
            {
                cout << "The max number of employees has been reached. Press Enter and Try Something Else." << endl;
                system("pause"); // Allows user to read the message
            }
            break; // Breaks out of switch
        }
        case 'R':
        {
            if (eCounter == 0) // 
            {
                cout << "There are no employees to be erased. Press Enter and Try Something Else." << endl;
                system("pause"); // Allows user to read the message
            }
            else
            {
            eCounter--; // The employee counter goes down by 1
            system("CLS"); // Clears the screen
            obj.fireEmployee(); // Calls fireEmployee function in the Department class
            }
            break; // Breaks out of switch
        }
        case 'L':
        {
            system("CLS"); // Clears the screen
            obj.listDeptInfo(); // Calls listDeptInfo function in the Department class
            system("pause"); // Allows user to read the department information
            break; // Breaks out of switch
        }
        case 'P':
        {
            system("CLS"); // Clears the screen
            obj.printFinalProfit(); // Calls printFinalProfit function in the Department class
            system("pause"); // Allows user to read the final profit
            break; // Breaks out of switch
        }
        default: // If an input is given that is not one of the options
        {
            // Nothing Here
        }

        } // End of Switch Statement

    } while (option != 'P'); // Continues the loop until a 'P' is enterd

    return 0; // End Program
}
