/*You have your own firm. You have a list of employees with their name, surname, age and salary. You can raise or reduce their salary, you can
sort them by their name and find out who is making the most money in your firm.*/

#include<iostream>
#include "Employee.h"
#include<vector>
#include<fstream>

void readData(std::string& name, std::string& surname, int& age, float& salary, std::vector<Employee>& employeesFirm, int& nrEmployees)
{
	std::ifstream fin("date.in");

	fin >> nrEmployees;

	for (int index = 0; index < nrEmployees; index++)
	{
		fin >> name;
		fin >> surname;
		fin >> age;
		fin >> salary;

		Employee employee(name, surname, age, salary);
		employeesFirm.push_back(employee);
	}
}

void alphabeticalSortingByName(std::vector<Employee>& employeesFirm)
{
	int ok = 1;

	for (int index1 = 0; index1 < employeesFirm.size() - 1; index1++)
	{
		for (int index2 = index1 + 1; index2 < employeesFirm.size(); index2++)
		{
			ok = employeesFirm[index1].getName().compare(employeesFirm[index2].getName());
			if (ok > 0)
			{
				std::swap(employeesFirm[index1], employeesFirm[index2]);
			}
		}
	}
}

void biggestSalary(std::vector<Employee>employeesFirm)
{
	float max = -1, theOneWhoMakesTheMost = 0;

	for (int index = 0; index < employeesFirm.size(); index++)
	{
		if (employeesFirm[index].getSalary() > max)
		{
			max = employeesFirm[index].getSalary();
			theOneWhoMakesTheMost = index;
		}
	}

	std::cout << "The employee that has the biggest salary is : " << employeesFirm[theOneWhoMakesTheMost].getName() << ' ' << employeesFirm[theOneWhoMakesTheMost].getSurname() << std::endl;
}

void printEmployees(std::vector<Employee>employeesFirm)
{
	for (int index = 0; index < employeesFirm.size(); index++)
	{
		std::cout << "Employee " << index + 1 << " : " << std::endl;
		std::cout << "Name : " << employeesFirm[index].getName() << std::endl;
		std::cout << "Surname : " << employeesFirm[index].getSurname() << std::endl;
		std::cout << "Age : " << employeesFirm[index].getAge() << std::endl;
		std::cout << "Salary : " << employeesFirm[index].getSalary() << std::endl;
		std::cout << std::endl;
	}
}

void printOnlyOneEmployee(std::vector<Employee>employeesFirm)
{
	int index;
	std::cout << "Press the index of the employee you want to see : "; 	std::cin >> index;
	std::cout << std::endl;

	std::cout << "Employee " << index + 1 << " : " << std::endl;
	std::cout << "Name : " << employeesFirm[index].getName() << std::endl;
	std::cout << "Surname : " << employeesFirm[index].getSurname() << std::endl;
	std::cout << "Age : " << employeesFirm[index].getAge() << std::endl;
	std::cout << "Salary : " << employeesFirm[index].getSalary() << std::endl;
	std::cout << std::endl;
}

void whatToPress()
{
	std::cout << "If you want to print the details about all your employees, press 1." << std::endl;
	std::cout << "If you want to print the details about only one employee, press 2." << std::endl;
	std::cout << "If you want to sort you employees in alphabetical order by their name, press 3." << std::endl;
	std::cout << "If you want to increase someones salary, press 4." << std::endl;
	std::cout << "If you want to decrease someones salary, press 5." << std::endl;
	std::cout << "If you want to see who is having the biggest salary, press 6." << std::endl;
	std::cout << "If you want to shut down the program, press 0." << std::endl;
	std::cout << std::endl;
}

int main()
{
	std::string name, surname;
	int age, nrEmployees;
	float salary;

	std::vector<Employee>employeesFirm;

	readData(name, surname, age, salary, employeesFirm, nrEmployees);

	bool condition = true;
	int instructionNumber;

	while (condition == true)
	{
		whatToPress();
		std::cout << "You want to do the instruction number : "; std::cin >> instructionNumber;
		std::cout << std::endl;

		switch (instructionNumber)
		{
		case 1 :
			system("cls");
			printEmployees(employeesFirm);
			break;

		case 2 :
			system("cls");
			printOnlyOneEmployee(employeesFirm);
			break;

		case 3 :
			system("cls");
			alphabeticalSortingByName(employeesFirm);
			printEmployees(employeesFirm);
			break;

		case 4 :
			int index;
			float raise;
			system("cls");
			std::cout << "Who do you want to increase his/her salary ? Press his/her index : ";
			std::cin >> index;
			std::cout << "With what percentage do you want to increase his/her salary? Press a prercentage : ";
			std::cin >> raise;
			employeesFirm[index] + raise;
			std::cout << std::endl << "Name : " << employeesFirm[index].getName() << std::endl << "Surname : " << employeesFirm[index].getSurname() << std::endl;
			std::cout << "Age : " << employeesFirm[index].getAge() << std::endl << "Salary : " << employeesFirm[index].getSalary() << std::endl;
			break;

		case 5 :

			int indexDecrease;
			float decrease;
			system("cls");
			std::cout << "Who do you want to decrease his/her salary ? Press his/her index : ";
			std::cin >> indexDecrease;
			std::cout << "With what percentage do you want to decrease his/her salary? Press a prercentage : ";
			std::cin >> decrease;
			employeesFirm[indexDecrease] - decrease;
			std::cout << std::endl << "Name : " << employeesFirm[indexDecrease].getName() << std::endl << "Surname : " << employeesFirm[indexDecrease].getSurname() << std::endl;
			std::cout << "Age : " << employeesFirm[indexDecrease].getAge() << std::endl << "Salary : " << employeesFirm[indexDecrease].getSalary() << std::endl;
			break;

		case 6 :
			system("cls");
			biggestSalary(employeesFirm);
			std::cout << std::endl << std::endl;
			break;

		case 0 :
			system("cls");
			std::cout << "You shuted down the program." << std::endl;
			condition = false;
			break;

		default :
			std::cout << "This is not a valid command." << std::endl;
		}
	}
	return 0;
}