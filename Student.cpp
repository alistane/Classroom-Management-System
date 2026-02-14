#include "Student.h"

void Student::create_student(std::string name, std::string age, double attendance_percentage, std::string roll_no)
{
	this->name = name;
	this->age = age;
	this->attendance_percentage = attendance_percentage;
	this->roll_no = roll_no;
}

std::string Student::give_name()
{
	return this->name;
}
std::string Student::give_age()
{
	return this->age;
}

std::string Student::give_roll()
{
	return this->roll_no;
}

double Student::give_attendance()
{
	return this->attendance_percentage;
}

