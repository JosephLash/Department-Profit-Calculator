#include "Manager.h" // Manager header file
#include <iomanip> // For setw and setprecision

Manager::Manager() // Initialize variables
{
	salary = 0.0;
	jobTitle = "";
}

void Manager::setPromotionDate(Date pD)
{
	promotionDate = pD; 
}

Date Manager::getPromotionDate() const
{
	return promotionDate;
}

void Manager::setSalary(float s)
{
	salary = s;
}

float Manager::getSalary() const
{
	return salary;
}

void Manager::setJobTitle(std::string jT)
{
	jobTitle = jT;
}

std::string Manager::getJobTitle() const
{
	return jobTitle;
}

std::ostream& operator<<(std::ostream& osObject, const Manager& managerInfo) // Overloaded << operator used to output the info of an employee
{
	osObject << "\nName: " << std::setw(26) << managerInfo.getFirstName() << " " << managerInfo.getLastName();
	osObject << "\nTitle: " << std::setw(30) << managerInfo.getJobTitle();
	osObject << "\nEmployee ID: " << std::setw(20) << managerInfo.getID();
	osObject << "\nBirth Date: " << std::setw(19) << managerInfo.getBirthday();
	osObject << "\nDate Hired: " << std::setw(19) << managerInfo.getHiringDate();
	osObject << "\nPromotion Date: " << std::setw(15) << managerInfo.getPromotionDate();
	osObject << "\nSalary: " << std::setw(22) << "$" << std::setprecision(2) << std::fixed << managerInfo.getSalary();
	return osObject;
}
