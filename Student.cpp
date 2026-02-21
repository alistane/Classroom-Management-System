#include "Student.h"

void Student::create_student(std::string name, int age, double attendance_percentage, std::string roll_no)
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
int  Student::give_age()
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

void Student::set_name(std::string name)
{
	this->name = name;
}
void Student::set_id(std::string rollnum)
{
	this->roll_no = rollnum;
}
void Student::set_age(int age)
{
	this->age = age;
}
void Student::set_attendance(double attendance_per)
{
	this->attendance_percentage = attendance_per;
}