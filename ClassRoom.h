#pragma once
#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include <string>
class ClassRoom
{
private:
	std::string class_name;
	Student students[10];
	Teacher teachers[10];
public:
	std::string get_classname();
	void set_classroom_name(std::string name);
	void create_student(int index, std::string name, int age, int attendance_percent, std::string id);
	void create_teacher(int index, std::string name, int age, std::string subject, std::string entered_id);
	std::string give_teacher_name(int index);
	std::string give_student_name(int index);

	std::string give_student_attendance(int index);
	std::string give_student_roll(int index);
};

