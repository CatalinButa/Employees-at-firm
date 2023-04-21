#pragma once
#include<iostream>
class Employee
{
	std::string name;
	std::string surname;
	int age;
	float salary;

public :

	Employee(std::string name, std::string surname, int age, float salary)
	{
		setName(name);
		setSurname(surname);
		setAge(age);
		setSalary(salary);
	}

	std::string getName();
	std::string getSurname();
	int getAge();
	float getSalary();

	void setName(std::string name);
	void setSurname(std::string surname);
	void setAge(int age);
	void setSalary(float salary);

	Employee& operator+(float increaseSalary);
	Employee& operator-(float decreaseSalary);
};

