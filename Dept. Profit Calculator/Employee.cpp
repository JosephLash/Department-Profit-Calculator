#include "Employee.h" // Employee header file
#include <iostream> // For cout
#include <algorithm> // For sort function
#include <iomanip> // For setw and setprecision


Employee::Employee() // For initializing variables
{
	miles = 0;
	employeeRating = 0;
	totalJobs = 0.0;
}

void Employee::setMiles(int m)
{
	miles = m;
}

int Employee::getMiles() const
{
	return miles;
}

void Employee::setEmployeeRating(float eR)
{
	employeeRating = eR;
}

float Employee::getEmployeeRating() const
{
	return employeeRating;
}

void Employee::sortEmployee() // Sort Employee Function
{
	// Could not figure this out
}

void Employee::addScores() // Adding job incomes
{
	float job;
	do {
		std::cout << "\nPlease Enter a Revenue Amount for a Job Completed by the Employee. Enter -1 to Quit: $";
		std::cin >> job;
		while (std::cin.fail()) // Error check
		{
			std::cin.clear(); // Clears the error state
			std::cin.ignore(10000, '\n'); // Ignores anything else in the input stream
			std::cout << "\nError. Please enter a valid amount: $"; // Reasks statement
			std::cin >> job;
		}
		if (job != -1) // If the number entered is not -1
		{
			vecJobs.push_back(job); // 
		}
		else {
			// Nothing here
		}
	} while(job != -1); // Loops exits when a -1 is entered

	for (int i = 0; i < vecJobs.size(); i++) // For-loop adds all incomes in the vector of jobs
	{
		totalJobs += vecJobs[i]; // Holds the total income of all the jobs
	}
}

float Employee::getSumOfScores() const // Returns the total income of all the jobs
{
	return totalJobs;
}

bool Employee::operator<(const Employee& employee) const // Overloaded < operator
{
	return getLastName() < employee.getLastName();
}

std::ostream& operator<<(std::ostream& osObject, const Employee& employeeInfo) // Overloaded << operator used to output the info of an employee
{
	osObject << "\nName:" << std::setw(27) << employeeInfo.getFirstName() << " " << employeeInfo.getLastName();
	osObject << "\nEmployeeID:" << std::setw(19) << employeeInfo.getID();
	osObject << "\nBirth Date:" << std::setw(20) << employeeInfo.getBirthday();
	osObject << "\nDate Hired:" << std::setw(20) << employeeInfo.getHiringDate();
	osObject << "\nMiles Traveled:" << std::setw(16) << employeeInfo.getMiles();
	osObject << "\nEmployee Rating:" << std::setprecision(1) << std:: fixed << std::setw(16) << employeeInfo.getEmployeeRating();
	osObject << "\nCompleted Job Revenue:" << std::endl;
	for (auto i : employeeInfo.vecJobs) // Outputs all the jobs in the vector
		osObject << std::setw(30) << std::setprecision(2) << std::fixed << "$" << i << std::endl;
	return osObject;
}