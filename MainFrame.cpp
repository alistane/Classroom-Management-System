#include "MainFrame.h"
#include "Teacher.h"
#include "CreateTeacherDialogue.h"
#include "CreateStudentDialogue.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)     
{
	
	MainFrame::create_panels();
	MainFrame::create_left_panel();
	MainFrame::create_upper_panel();

	CreateStatusBar();

	// Student 
	create_student = new wxButton(right_panel, wxID_ANY, "Create Student", wxPoint(800, 50), wxSize(200,85));
	create_student->SetFont(button_font);
	create_student->SetOwnForegroundColour(wxColor(*wxWHITE));
	create_student->SetOwnBackgroundColour(wxColor(67, 124, 206));
	create_student->Refresh();
	create_student->SetWindowStyle(wxBORDER_NONE);


	students_display = new wxListCtrl(center_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_SINGLE_SEL | wxLB_NEEDED_SB);
	
	

	wxString student_count = wxString::Format("Students : %d", students_created);
	wxStaticText* student_count_label = new wxStaticText(left_panel, wxID_ANY, student_count);
	students_display->InsertColumn(0, "Student Name", wxLIST_FORMAT_LEFT, 200);
	students_display->InsertColumn(1, "Attendance %", wxLIST_FORMAT_LEFT, 120);
	students_display->InsertColumn(2, "Registeration Number", wxLIST_FORMAT_LEFT, 130);
	create_student->Bind(wxEVT_BUTTON, &MainFrame::create_s_dialogue, this);
	
	leftsizer->Add(student_count_label);
	
	// Teacher
	wxButton* create_teacher = new wxButton(right_panel, wxID_ANY, "Create Teacher", wxDefaultPosition,wxSize(200, 85));
	create_teacher->SetBackgroundColour(wxColor(*wxWHITE));
	create_teacher->SetFont(button_font);
	create_teacher->SetOwnForegroundColour(wxColor(*wxWHITE));
	create_teacher->SetOwnBackgroundColour(wxColor(67, 124, 206));
	create_teacher->Refresh();
	create_teacher->SetWindowStyle(wxBORDER_NONE);
	
	wxBoxSizer* rightsizer = new wxBoxSizer(wxVERTICAL);
	rightsizer->Add(create_student, 0,  wxALL, 10);
	rightsizer->Add(create_teacher, 0,  wxALL, 10);
		
	right_panel->SetSizer(rightsizer);


	create_teacher->Bind(wxEVT_BUTTON, &MainFrame::create_t_dialogue, this);

	wxString teachers_count_ = wxString::Format("Teachers : %d", teachers_created);
	wxStaticText* teacher_count_label = new wxStaticText(left_panel, wxID_ANY, teachers_count_);
	//teachers_display = new wxListBox(left_panel, wxID_ANY, wxPoint(40, 100), wxSize(200, 600), teacher_names, wxLB_NEEDED_SB);
	teachers_display = new wxListCtrl(center_panel, wxID_ANY, wxDefaultPosition, wxSize(460, 800), wxLC_REPORT | wxLC_SINGLE_SEL | wxLB_NEEDED_SB);
	teachers_display->InsertColumn(0, "Teacher's Name", wxLIST_FORMAT_LEFT, 200);
	teachers_display->InsertColumn(1, "Subject", wxLIST_FORMAT_LEFT, 120);
	teachers_display->InsertColumn(2, "ID", wxLIST_FORMAT_LEFT, 130);
	teachers_display->Hide();
	leftsizer->Add(teacher_count_label);

	//misc
	wxBoxSizer* center_sizer = new wxBoxSizer(wxVERTICAL);
	center_sizer->Add(students_display, 1, wxEXPAND | wxALL, 20);
	center_sizer->Add(teachers_display, 1, wxEXPAND | wxALL, 20);
	center_panel->SetSizer(center_sizer);
	

	wxBoxSizer* mainsizer = new wxBoxSizer(wxVERTICAL);
	mainsizer->Add(upper_panel, 0, wxEXPAND);
	mainsizer->Add(content_sizer, 1, wxEXPAND);
	SetSizer(mainsizer);
	
}

void MainFrame::create_panels()
{
	// other stuff
	panel->SetBackgroundColour(wxColor(239, 241, 245));
	center_panel = new wxPanel(this, wxID_ANY);
	left_panel = new wxPanel(this, wxID_ANY);
	left_panel->SetMinSize(wxSize(250, -1));
	left_panel->SetBackgroundColour(wxColor(246, 236, 237));
	upper_panel = new wxPanel(this, wxID_ANY);
	right_panel = new wxPanel(this, wxID_ANY);
	right_panel->SetMinSize(wxSize(250, -1));
	right_panel->SetBackgroundColour(wxColor(239, 241, 245));
	content_sizer = new wxBoxSizer(wxHORIZONTAL);
	content_sizer->Add(left_panel, 0, wxEXPAND);
	content_sizer->Add(center_panel, 1, wxEXPAND);
	content_sizer->Add(right_panel, 0, wxEXPAND);
	upper_panel->SetBackgroundColour(wxColor(252, 252, 253));
}

void MainFrame::create_left_panel()
{
	Dash = new wxButton(left_panel, wxID_ANY, "Dashboard", wxDefaultPosition, wxSize(200, 85));
	Dash->SetFont(button_font);
	Dash->SetOwnForegroundColour(wxColor(*wxWHITE));
	Dash->SetOwnBackgroundColour(wxColor(67, 124, 206));
	Dash->Refresh();
	Dash->SetWindowStyle(wxBORDER_NONE);

	teachers = new wxButton(left_panel, wxID_ANY, "Teachers", wxDefaultPosition, wxSize(200, 85));
	Dash->Bind(wxEVT_BUTTON, &MainFrame::show_dashboard, this);
	teachers->Bind(wxEVT_BUTTON, &MainFrame::show_teacher_panel, this);
	teachers->SetFont(button_font);
	teachers->SetOwnForegroundColour(wxColor(*wxWHITE));
	teachers->SetOwnBackgroundColour(wxColor(67, 124, 206));
	teachers->Refresh();
	teachers->SetWindowStyle(wxBORDER_NONE);
	leftsizer = new wxBoxSizer(wxVERTICAL);
	leftsizer->Add(Dash, 0, wxEXPAND | wxALL, 10);
	leftsizer->Add(teachers, 0, wxEXPAND | wxALL, 10);
	leftsizer->AddStretchSpacer();
	left_panel->SetSizer(leftsizer);
}


// this function creates teacher and dialogue menu.
void MainFrame::create_t_dialogue(wxCommandEvent& evt)
{
	CreateTeacherDialogue* dialogue = new CreateTeacherDialogue("Create Teacher");
	dialogue->Show(true);


	classroom.create_teacher(teachers_pos, dialogue->get_enteredname(), dialogue->get_enteredage(), dialogue->get_subject(), dialogue->get_enteredid());


	//teachers[teachers_pos].create_teacher(dialogue->get_enteredname(), dialogue->get_enteredage(), dialogue->get_subject(), dialogue->get_enteredid());

	//wxString str = wxString::Format("Teacher created with name : %s, Age : %d, Subject : %s ", classroom.give_teacher_name(teachers_created), teachers[teachers_pos].give_age(), teachers[teachers_pos].give_subject());
	wxString str = wxString::Format("Teacher created with name : %s, Subject : %s", classroom.give_teacher_name(teachers_pos), classroom.give_teacher_subject(teachers_pos));;
	wxLogStatus(str);

	/*
	 this block is responsible for UI, teacher_names array is for choices in the wxlist,
	teachers created keeps track of how many teachers have been created so far.
	teachers_pos is a variable used for creating next teacher. it moves to next position of the teachers array declared.
	*/ 

	teacher_names.Add(classroom.give_teacher_name(teachers_pos));
	wxString name = classroom.give_teacher_name(teachers_pos);

	long index = teachers_display->InsertItem(teachers_pos, name);
	teachers_display->SetItem(index, 1, classroom.give_teacher_subject(teachers_pos));
	teachers_display->SetItem(index, 2, classroom.give_teacher_id(teachers_pos));

	teachers_created++;
	teachers_pos++;
	//teacher_count_text->SetLabel(std::to_string(teachers_created));

	
}

void MainFrame::create_s_dialogue(wxCommandEvent& evt)
{
	CreateStudentDialogue* dialogue = new CreateStudentDialogue("Create Student");
	dialogue->Show(true);


	classroom.create_student(students_pos, dialogue->get_enteredname(), dialogue->get_enteredage(), dialogue->get_entered_attendance(), dialogue->get_enteredid());

	//students[students_pos].create_student(dialogue->get_enteredname(), dialogue->get_enteredage(), dialogue->get_entered_attendance(), dialogue->get_enteredid());

	//wxString str = wxString::Format("Student created with name : %s, Age : %d ", students[students_pos].give_name(), students[students_pos].give_age());
	
	wxString str = wxString::Format("Student created with name : %s", classroom.give_student_name(students_pos));
	wxLogStatus(str);

	/*
	 this block is responsible for UI, teacher_names array is for choices in the wxlist,
	teachers created keeps track of how many teachers have been created so far.
	teachers_pos is a variable used for creating next teacher. it moves to next position of the teachers array declared.
	*/
	student_names.Add(classroom.give_student_name(students_pos));
	wxString name = classroom.give_student_name(students_pos);

	

	long index = students_display->InsertItem(students_pos, name);
	students_display->SetItem(index, 1, classroom.give_student_attendance(students_pos));
	students_display->SetItem(index, 2, classroom.give_student_roll(students_pos));
	//students_display->Append(name);
	students_created++;
	students_pos++;
	//student_count_text->SetLabel(std::to_string(students_created));

}


void MainFrame::show_dashboard(wxCommandEvent& evt)
{
	teachers_display->Hide();
	students_display->Show();
}

void MainFrame::show_teacher_panel(wxCommandEvent& evt)
{
	students_display->Hide();
	teachers_display->Show();
	
}


void MainFrame::create_upper_panel()
{
	classroom.set_classroom_name("Object Oriented Programming");
	classroom.set_classroom_term("Spring-2026");
	class_term = new wxStaticText(upper_panel, wxID_ANY, classroom.get_class_term(), wxDefaultPosition);
	class_term->SetFont(heading_font);
	class_label = new wxStaticText(upper_panel, wxID_ANY, classroom.get_classname(), wxDefaultPosition, wxSize(450, 50));
	class_label->SetFont(heading_font);
	class_settings = new wxButton(upper_panel, wxID_ANY, "Class Settings", wxDefaultPosition, wxSize(100, 10));
	uppersizer = new wxBoxSizer(wxHORIZONTAL);
	uppersizer->AddSpacer(20);
	uppersizer->Add(class_term, 0, wxEXPAND | wxTOP, 20);
	uppersizer->AddSpacer(20);
	uppersizer->Add(class_label, 0, wxEXPAND | wxTOP | wxLeft, 20);
	uppersizer->AddStretchSpacer();
	uppersizer->Add(class_settings, 0, wxEXPAND | wxRight, 20);
	uppersizer->AddSpacer(20);
	upper_panel->SetSizer(uppersizer);
}
