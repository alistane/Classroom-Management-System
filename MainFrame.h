#pragma once
#include<wx/wx.h>
#include "Student.h"
#include "Teacher.h"
#include <wx/listctrl.h>
#include "ClassRoom.h"
#include <wx/font.h>
class MainFrame : public wxFrame
{
private:
	// extra stuff
	wxPanel* panel = new wxPanel(this, wxID_ANY);
	ClassRoom classroom;
	wxFont heading_font = wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

	//Teachers
	int teachers_created{ 0 }; // just keeps track of how many teachers have been created so far.
	int teachers_pos{ 0 }; // this will be used for object creation.
	wxStaticText* teacher_count_text;
	wxListBox* teachers_display;
	wxArrayString teacher_names; // names of teachers.
	
	//Students
	wxArrayString student_names; // names of students.
	wxListCtrl* students_display;
	wxStaticText* student_count_text;
	int students_created{ 0 };
	int students_pos{ 0 };

protected:
	
	//Student students[10];
	//Teacher teachers[10];
	
public:
	MainFrame(const wxString& title);
	void create_t_dialogue(wxCommandEvent& evt);
	void create_s_dialogue(wxCommandEvent& evt);
};

