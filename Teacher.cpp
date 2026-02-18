#include "Teacher.h"
#include<wx/wx.h>
#include "MainFrame.h"
#include<iostream>


Teacher ::Teacher(std::string name, int age, std::string subject, std::string id_no)
{

}


void Teacher::create_teacher(std::string name, int age, std::string subject, std::string id_no)
{
	this->name = name;
	this->age = age;
	this->subject = subject; 
	this->id_no = id_no;
}

void Teacher::print_info()
{
	//std::cout << "NAME : " << name << std::endl;
	//std::cout << "AGE : " << age << std::endl;
	//std::cout << "SUBJECT : " << subject << std::endl;
	//std::cout << "ID: " << id_no << std::endl;

	//teacher_name = new wxStaticText(this, wxID_ANY, this->name);



}



int Teacher::give_age()
{
	return this->age;
}


std::string Teacher::give_name()
{
	return this->name;
}

std::string Teacher::give_id()
{
	return this->id_no;
}

std::string Teacher::give_subject()
{
	return this->subject;
}


// setter section 

void Teacher::set_name(std::string value)
{
	this->name = value;
}
void Teacher::set_subject(std::string value)
{
	this->subject = value;
}
void Teacher::set_id(std::string value)
{
	this->id_no = value;
}
void Teacher::set_age(int value)
{
	this->age = value;
}