#include "MainFrame.h"
#include "Teacher.h"
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)     
{
	//Teacher t1;
	//t1.create_teacher("Ali Nauman", 20, "Computer Science", "0065");
	//wxStaticText* t1name = new wxStaticText(panel, wxID_ANY, t1.give_subject(), wxPoint(450, 100));
	//wxStaticText* t1sub = new wxStaticText(panel, wxID_ANY, t1.give_name(), wxPoint(350, 100));
	//
	//Teacher t2;
	//t2.create_teacher("Ayesha Monkey", 19, "Computer Science", "0160");
	//wxStaticText* t2name = new wxStaticText(panel, wxID_ANY, t2.give_subject(), wxPoint(450, 200));
	//wxStaticText* t2sub = new wxStaticText(panel, wxID_ANY, t2.give_name(), wxPoint(350, 200));

	wxButton* create_teacher = new wxButton(panel, wxID_ANY, "Create Teacher", wxPoint(905, 50));
	wxButton* create_student = new wxButton(panel, wxID_ANY, "Create Student", wxPoint(800, 50));

}