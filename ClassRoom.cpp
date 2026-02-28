#include "ClassRoom.h"

std::string ClassRoom::get_classname()
{
	return this->class_name;
}
void ClassRoom::set_classroom_name(std::string name)
{
	this->class_name = name;
}

std::string ClassRoom::give_teacher_subject(int index)
{
	return teachers[index].give_subject();
}
std::string ClassRoom::get_class_term()
{
	return this->academic_term;
}

void ClassRoom::set_classroom_term(std::string name)
{
	this->academic_term = name;
}

void ClassRoom::create_teacher(int index, std::string name, int age , std::string subject, std::string entered_id)
{
	teachers[index].set_name(name);
	teachers[index].set_id(entered_id);
	teachers[index].set_subject(subject);
	teachers[index].set_age(age);
}

void ClassRoom::create_student(int index, std::string name, int age, int attendance_percent, std::string id)
{
	students[index].set_name(name);
	students[index].set_id(id);
	students[index].set_attendance(attendance_percent);
	students[index].set_age(age);
}


std::string ClassRoom::give_teacher_name(int index)
{
	return teachers[index].give_name();
}

std::string ClassRoom::give_student_name(int index)
{
	return students[index].give_name();
}

std::string ClassRoom::give_student_attendance(int index)
{
	
	return std::to_string((students[index].give_attendance()));
}
std::string ClassRoom::give_student_roll(int index)
{
	return students[index].give_roll();
}


std::string ClassRoom::give_teacher_id(int index)
{
	return teachers[index].give_id();
}


