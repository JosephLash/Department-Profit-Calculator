#pragma once
#include <string>
#include "Date.h"

class Person
{
public:
	Person(); // Default constructor

	~Person() {} // Destructor

	// Set and get functions
	void setFirstName(std::string fName);
	std::string getFirstName() const;

	void setLastName(std::string lName);
	std::string getLastName() const;

	void setBirthday(Date bDay);
	Date getBirthday() const;

	void setID(int id);
	int getID() const;

	void setHiringDate(Date hire);
	Date getHiringDate() const;

private:
	// The overlapping variables that appear in both the employee and manager classes
	std::string firstName;
	std::string lastName;
	Date birthday;
	int ID;
	Date hiringDate;

};
