#include "Employee.h"
#include <iostream>

using namespace std;

Employee::Employee(string n, int i, int a, string j, int y) {
	name = n;
	id = i;
	age = a;
	job = j;
	year = y;
}

int Employee::getID() {
	return id;
}

//Print everything
void Employee::printState() {
	cout << "FOUND: Name: " << name <<
		", Age: " << age <<
		", Job: " << job <<
		", Hired: " << year << endl;
}

bool Employee::operator>(const Employee& other) {
	return id > other.id;
}

bool Employee::operator<(const Employee& other) {
	return id < other.id;
}

bool Employee::operator>=(const Employee& other) {
	return id >= other.id;
}
bool Employee::operator<=(const Employee& other) {
	return id <= other.id;
}
bool Employee::operator==(const Employee& other) {
	return id == other.id;
}
bool Employee::operator!=(const Employee& other) {
	return id != other.id;
}