#include "Employee.h"

std::string Employee::getName()
{
    return this->name;
}

std::string Employee::getSurname()
{
    return this->surname;
}

int Employee::getAge()
{
    return this->age;
}

float Employee::getSalary()
{
    return this->salary;
}

void Employee::setName(std::string name)
{
    this->name = name;
}

void Employee::setSurname(std::string surname)
{
    this->surname = surname;
}

void Employee::setAge(int age)
{
    this->age = age;
}

void Employee::setSalary(float salary)
{
    this->salary = salary;
}

Employee& Employee::operator+(float increaseSalary)
{
    float increase = (increaseSalary / 100) * this->salary;
    this->salary = this->salary + (int)increase;
    return*this;
}

Employee& Employee::operator-(float decreaseSalary)
{
    float decrease = (decreaseSalary / 100) * this->salary;
    this->salary = this->salary - (int)decrease;
    return*this;
}
