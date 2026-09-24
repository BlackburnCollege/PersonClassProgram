#include <iostream>
#include <fstream>
#include <vector>
#include "Person.h"

int main()
{
	int choice = 0;
	Person tempPerson;
	std::string first, last, phone;
	std::vector<Person> people;
	std::ifstream namesFile("names.txt");

	if (!namesFile)
	{
		std::cerr << "Error opening file." << std::endl;
		return 1;
	}

	while (!namesFile.eof())
	{

		namesFile >> first;
		namesFile >> last;
		namesFile >> phone;

		tempPerson.setFirstName(first);
		tempPerson.setLastName(last);
		tempPerson.setPhoneNumber(phone);

		people.push_back(tempPerson);
	}

	while (choice != 3)
	{
		std::cout << "****** List of People ******" << std::endl;
		std::cout << "\nSelect from the list below by entering the corresponding number." << std::endl;
		std::cout << "1) Print people first name, last name, phone number." << std::endl;
		std::cout << "2) Print people last name, first name." << std::endl;
		std::cout << "3) Exit." << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		std::cout << std::endl;

		switch (choice)
		{
			case 1:
				for (int index = 0; index < people.size(); index++)
				{
					std::cout << people[index].getFirstName() << " " << people[index].getLastName() << " " << people[index].getPhoneNumber() << std::endl;
				}
				break;
			case 2:
				for (int index = 0; index < people.size(); index++)
				{
					std::cout << people[index].getLastName() << ", " << people[index].getFirstName() << std::endl;
				}
				break;
			case 3:
				std::cout << "Exiting..." << std::endl;
				break;
			default:
				std::cout << "Invalid choice. Please try again." << std::endl;
		}
		std::cout << std::endl;
	}
}
