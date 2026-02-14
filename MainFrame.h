#pragma once
#include<wx/wx.h>
#include "Student.h"
#include "Teacher.h"


class MainFrame : public wxFrame
{
private:
	wxPanel* panel = new wxPanel(this, wxID_ANY);
protected:
	wxStaticText* teacher_name;
	Student students[10];
	Teacher teachers[10];
	int array[10];
public:
	MainFrame(const wxString& title);


};

