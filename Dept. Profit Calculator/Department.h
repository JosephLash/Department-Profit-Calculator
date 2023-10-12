#pragma once
#include "Date.h" // Date header file
#include "Employee.h" // Employee header file
#include "Manager.h" // Manager header file
#include "Person.h" // Manager header file

class Department // Class declaration
{
public:

	Department(); // Default constructor
	
	~Department() {} // Destructor

	// Functions
	void assignManager();
	void hireEmployee();
	void fireEmployee();
	void sortEmployee();

	void tokenizeDate(char* c, int& mon, int& day, int& year); // Tokenization function


	// Set and get functions
	void setCapacity(int c);
	int getCapacity() const;

	void setDeptName(std::string dN);
	std::string getDeptName() const;

	void setProductCost(float pC);
	float getProductCost() const;

	// 
	float costOfTravel();
	float avgRating();
	float sumScores();

	void listDeptInfo();

	void printFinalProfit();

private: // Private variables
	int capacity;
	std::string deptName;
	float productCost;
	Manager deptMan; // Composition
	std::vector<Employee>empObjs; // Composition; vector of Employees
};

// Vector of employees has a vector of jobs