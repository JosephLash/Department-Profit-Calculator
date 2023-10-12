#pragma once
#include "Person.h" // Person header file

class Manager : public Person // Inheritance
{
	friend std::ostream& operator<<(std::ostream&, const Manager&); // Overloaded << operator

public:
	Manager(); // Default constructor
	
	~Manager() {} // Destructor

	// Set and Get Functions
	void setPromotionDate(Date pD);
	Date getPromotionDate() const;

	void setSalary(float s);
	float getSalary() const;

	void setJobTitle(std::string jT);
	std::string getJobTitle() const;

private: // Private variables
	Date promotionDate;
	float salary;
	std::string jobTitle;
};