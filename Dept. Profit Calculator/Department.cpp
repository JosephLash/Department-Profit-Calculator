// Initial statements
#include "Department.h" // Department header file
#include <iomanip> // For setw and setprecision

Department::Department() // Initializing variables
{
	capacity = 0;
	deptName = "";
	productCost = 0.0;
}

void Department::assignManager() // Assign manager function
{
	std::string first;
	std::cout << "\nFirst Name: ";
	std::getline(std::cin, first); // Allows for spaces
	deptMan.setFirstName(first);

	std::string last;
	std::cout << "\nLast Name: ";
	std::getline(std::cin, last); // Allows for spaces
	deptMan.setLastName(last);

	int m, d, y;
	char charDate[20]; //holds date in char array
	Date realDate; // holds date after tokenization
	std::cout << "\nBirthday (mm/dd/yyyy): ";
	std::cin >> charDate;
	//separates month, day, year
	Department::tokenizeDate(charDate, m, d, y);
	realDate.setDate(d, m, y); //sets the date
	deptMan.setBirthday(realDate);

	const int id = 1000; // Default ID for a manager is set as 1000
	std::cout << "\nID: " << id;
	deptMan.setID(id);

	std::cout << "\n\nDate Hired (mm/dd/yyyy): ";
	std::cin >> charDate;
	//separates month, day, year
	Department::tokenizeDate(charDate, m, d, y);
	realDate.setDate(d, m, y); //sets the date
	deptMan.setHiringDate(realDate);
	
	float salary = 0.0;
	std::cout << "\nCurrent Salary: $";
	std::cin >> salary;
	while (std::cin.fail() || salary < 0) // Error check
	{
		std::cin.clear(); // Clears the error state
		std::cin.ignore(10000, '\n'); // Ignores anything else in the input stream
		std::cout << "\nError. Please enter a valid amount: $"; // Reasks statement
		std:: cin >> salary;
	}
	deptMan.setSalary(salary);

	std::string title;
	std::cout << "\nTitle: ";
	std::cin.clear(); // Clear input stream
	std::cin.ignore(10000, '\n'); // Ignore anything else
	std::getline(std::cin, title); // Allows for spaces
	deptMan.setJobTitle(title);

	std::cout << "\nPromotion Date (mm/dd/yyyy): ";
	std::cin >> charDate;
	//separates month, day, year
	Department::tokenizeDate(charDate, m, d, y);
	realDate.setDate(d, m, y); //sets the date
	deptMan.setPromotionDate(realDate);

}

void Department::hireEmployee() // Hire an employee function
{
	Employee temp; // Temporary employee object

	std::string f, l;
	std::cout << "\nFirst Name: ";
	std::getline(std::cin, f); // Allows for spaces
	temp.setFirstName(f); // Sends input to setFirstName in Person class

	std::cout << "\nLast Name: ";
	std::getline(std::cin, l);
	temp.setLastName(l); // Sends input to setLastName in Person class

	int m, d, y;
	char charDate[20]; //holds date in char array
	Date realDate; // holds date after tokenization
	std::cout << "\nBirthday (mm/dd/yyyy): ";
	std::cin >> charDate;
	//separates month, day, year
	Department::tokenizeDate(charDate, m, d, y);
	realDate.setDate(d, m, y); //sets the date
	temp.setBirthday(realDate);

	int id = empObjs.size() + 1;
	temp.setID(id);
	std::cout << "\nID: " << temp.getID();

	std::cout << "\n\nDate Hired (mm/dd/yyyy): ";
	std::cin >> charDate;
	//separates month, day, year
	Department::tokenizeDate(charDate, m, d, y);
	realDate.setDate(d, m, y); //sets the date
	temp.setHiringDate(realDate);

	int miles;
	std::cout << "\nMiles Traveled: ";
	std::cin >> miles;
	while (std::cin.fail() || miles < 0) // Error check for negative numbers
	{
		std::cin.clear(); // Clears the error state
		std::cin.ignore(10000, '\n'); // Ignores anything else in the input stream
		std::cout << "\nError. Please enter a valid number of miles: ";
		std::cin >> miles;
	}
	temp.setMiles(miles);

	float rating;
	std::cout << "\nEmployee Rating from Last Review (1-5): ";
	std::cin >> rating;
	while (std::cin.fail() || rating < 1 || rating > 5) // Error check for input in the range of 1-5
	{
		std::cin.clear(); // Clears the error state
		std::cin.ignore(10000, '\n'); // Ignores anything else in the input stream
		std::cout << "\nError. Please enter a valid review: ";
		std::cin >> rating;
	}
	temp.setEmployeeRating(rating);

	temp.addScores(); // Calls addScores function in the Employee Class

	empObjs.push_back(temp); // All the information gets pushed into the vector
}

void Department::fireEmployee() // Fire an employee function
{
	Employee obj; // Temporary Employee object
	int i; // 
	std::cout << "\nPlease Enter the ID Number of the Employee You Want to Erase: ";
	std::cin >> i;
	while (std::cin.fail() || i <= 0 || i > empObjs.size()) // Error Checks if the ID number is out of range
	{
		std::cin.clear(); // Clears the error state
		std::cin.ignore(10000, '\n'); // Ignores anything else in the input stream
		std::cout << "\nError. Please enter a valid ID: ";
		std::cin >> i;
	}

		std::cout << "\nEmployee #" << i << " has been removed." << std::endl;
		i -= 1; // The vector indexes start at 0 so we need to go back one number
		empObjs.erase(empObjs.begin() + i); // Erase the vector at a given position. Idea from https://www.tutorialspoint.com/cplusplus-program-to-remove-items-from-a-given-vector
	

}

void Department::sortEmployee()
{
	// I honestly could not figure out how to do this
}

void Department::tokenizeDate(char* c, int& mon, int& day, int& year) { // Tokenize the date
	char seps[] = "/";
	char* token = NULL;
	char* next_token = NULL;
	token = NULL;
	next_token = NULL;
	// Establish string and get the tokens:
	token = strtok_s(c, seps, &next_token);
	mon = atoi(token);
	token = strtok_s(NULL, seps, &next_token);
	day = atoi(token);
	token = strtok_s(NULL, seps, &next_token);
	year = atoi(token);
}

void Department::setCapacity(int c)
{
	capacity = c;
}

int Department::getCapacity() const
{
	return capacity;
}

void Department::setDeptName(std::string dN)
{
	deptName = dN;
}

std::string Department::getDeptName() const
{
	return deptName;
}

void Department::setProductCost(float pC)
{
	productCost = pC;
}

float Department::getProductCost() const
{
	return productCost;
}

float Department::costOfTravel() // Calculating the cost of Travel
{
	float total = 0.0;
	for (float i = 0; i < empObjs.size(); i++) // Goes through every room in the vector
	{
		total += empObjs[i].getMiles(); // Gets sum of coats
	}
	return total;
}

float Department::avgRating() // Calculating the average rating
{
	float avg = 0.0;
	float total = 0.0;
	float size = empObjs.size();
	for (float i = 0; i < empObjs.size(); i++) // Goes through every room in the vector
	{
		total += empObjs[i].getEmployeeRating(); // Gets sum of ratings
	}
	avg = total / size;

	return avg;
}

float Department::sumScores() // Calculating the sum of all job incomes
{
	float sum = 0.0;
	for (float i = 0; i < empObjs.size(); i++) // Goes through every room in the vector
	{
		sum += empObjs[i].getSumOfScores(); // Gets sum of job incomes
	}
	return sum; // Returns the sum
}

void Department::listDeptInfo() // Function for listing department info
{
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Department Information for " << getDeptName() << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Capacity: " << getCapacity() << std::endl;
	std::cout << "Product Cost: $" << getProductCost() << std::endl;
	std::cout << "\nManager: " << deptMan.getFirstName() << " " << deptMan.getLastName() << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << deptMan;
	std::cout << "\n\n------------------------------------------" << std::endl;
	if (empObjs.size() > 0) { // No employee info outputted if there are no employees entered
		std::cout << "\nCurrent Employees:" << std::endl;
		for (int i = 0; i < empObjs.size(); i++)
		{
			std::cout << "\n------------------------------------------" << std::endl;
			std::cout << empObjs[i];
		}
	}
	else {
		// Nothing here
	}
}

void Department::printFinalProfit() // Function for printing the final profit
{
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << std::setw(27) << getDeptName() << std::endl;
	std::cout << " Department Profit Calculation for " << getDeptName() << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "Manager: " << std::setw(26) << deptMan.getFirstName() << " " << deptMan.getLastName() << std::endl;
	std::cout << "Total Income: " << std::setw(20) << "$" << std::setprecision(2) << std::fixed << sumScores() << std::endl;
	std::cout << "Cost of Products: " << std::setw(16) << "$" << std::setprecision(2) << std::fixed << getProductCost() << std::endl;
	std::cout << "Cost of Labor: " << std::setw(19) << "$" << std::setprecision(2) << std::fixed << empObjs.size() * 15 + deptMan.getSalary() << std::endl; // Calculates the cost of labor
	std::cout << "Cost of Travel: " << std::setw(18) << "$" << std::setprecision(2) << std::fixed << costOfTravel() * 0.87 << std::endl;
	std::cout << "Average Employee Rating: " << std::setw(11) << std::setprecision(1) << std::fixed << avgRating() << std::endl;
	std::cout << "Final Profit: " << std::setw(20) << "$" << std::setprecision(2) << std::fixed << sumScores() - (costOfTravel() * 0.87 + empObjs.size() * 15 + getProductCost()) << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
}


