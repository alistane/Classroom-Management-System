#pragma once
#include <iostream>
#include "Person.h"
// baad me if needed protected inheritance karvana...
class Teacher : protected Person
{
	protected:
		std::string subject;
		std::string id_no;
	public:
		Teacher() = default;
		Teacher(std::string name, int age, std::string subject, std::string id_no);
		void create_teacher(std::string name, int age, std::string subject, std::string id_no);
		void print_info();
		std::string give_name();
		int give_age();
		std::string give_subject();
		std::string give_id();

		//setters
		void set_name(std::string value);
		void set_subject(std::string value);
		void set_id(std::string value);
		void set_age(int value);
};



