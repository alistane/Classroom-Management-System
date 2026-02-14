#pragma once
#include "Person.h"
class Student : protected Person
{
	protected:
		double attendance_percentage;
		std::string roll_no;

	public:
		void create_student(std::string name, std::string age, double attendance_percentage, std::string roll_no);
		std::string give_name();
		std::string  give_age();
		double give_attendance();
		std::string give_roll();


};

