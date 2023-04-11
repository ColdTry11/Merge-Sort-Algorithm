#pragma once
#include <string>

using namespace std;

class Employee
{
private:
	string name;
	int id;
	int age;
	string job;
	int year;

public:
	Employee(string, int, int, string, int);
	int getID();
	void printState();
	bool operator>(const Employee&);
	bool operator<(const Employee&);
	bool operator>=(const Employee&);
	bool operator<=(const Employee&);
	bool operator==(const Employee&);
	bool operator!=(const Employee&);
};

