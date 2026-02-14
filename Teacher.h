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
		std::string give_age();
		std::string give_subject();
		std::string give_id();
};



