#pragma once
#include "Person.h" // Person header file
#include <vector> // For vectors
class Employee : public Person // Inheritance
{
	friend std::ostream& operator<<(std::ostream&, const Employee&); // Overloaded << Operator

public:
	Employee(); // Default constructor

	~Employee() {} // Destructor

	// Set and get functions
	void setMiles(int m);
	int getMiles() const;

	void setEmployeeRating(float eR);
	float getEmployeeRating() const;

	void sortEmployee(); // Sort employee function

	void addScores(); // Function to add the income of a job for an employee
	float getSumOfScores() const; // Get the total income of all jobs

	bool operator<(const Employee&) const; // Overloaded < operator

private: // Private variables
	int miles;
	float employeeRating;
	std::vector<float>vecJobs;
	float totalJobs;

};