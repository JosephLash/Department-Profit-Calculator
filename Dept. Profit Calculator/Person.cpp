#include "Person.h"

Person::Person() // Initializing variables
{
	firstName = "";
	lastName = "";
	ID = 0;
}

void Person::setFirstName(std::string fName)
{
	firstName = fName;
}

std::string Person::getFirstName() const
{
	return firstName;
}

void Person::setLastName(std::string lName)
{
	lastName = lName;
}

std::string Person::getLastName() const
{
	return lastName;
}

void Person::setBirthday(Date bDay)
{
	birthday = bDay;
}

Date Person::getBirthday() const
{
	return birthday;
}

void Person::setID(int id)
{
	ID = id;
}

int Person::getID() const
{
	return ID;
}

void Person::setHiringDate(Date hire)
{
	hiringDate = hire;
}

Date Person::getHiringDate() const
{
	return hiringDate;
}
