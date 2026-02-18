#pragma once
#include<wx/wx.h>
#include "Student.h"
#include "Teacher.h"


class MainFrame : public wxFrame
{
private:
	
	wxPanel* panel = new wxPanel(this, wxID_ANY);
	
	//Teachers
	int teachers_created{ 0 }; // just keeps track of how many teachers have been created so far.
	int teachers_pos{ 0 }; // this will be used for object creation.
	wxStaticText* teacher_count_text;
	wxListBox* teachers_display;
	wxArrayString teacher_names; // names of teachers.
	
	//Students
	wxArrayString student_names; // names of students.
	wxListBox* students_display;
	wxStaticText* student_count_text;
	int students_created{ 0 };
	int students_pos{ 0 };

protected:
	wxStaticText* teacher_name;
	Student students[10];
	Teacher teachers[10];
	
public:
	MainFrame(const wxString& title);
	void create_t_dialogue(wxCommandEvent& evt);
	void create_s_dialogue(wxCommandEvent& evt);
};

