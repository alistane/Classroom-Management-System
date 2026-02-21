#include "MainFrame.h"
#include "Teacher.h"
#include "CreateTeacherDialogue.h"
#include "CreateStudentDialogue.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)     
{
	// Student 
	wxButton* create_student = new wxButton(panel, wxID_ANY, "Create Student", wxPoint(800, 50));
	students_display = new wxListCtrl(panel, wxID_ANY, wxPoint(300, 100), wxSize(450, 600), wxLC_REPORT | wxLC_SINGLE_SEL | wxLB_NEEDED_SB);
	student_count_text = new wxStaticText(panel, wxID_ANY, std::to_string(teachers_created), wxPoint(100, 75));
	wxStaticText* student_count_label = new wxStaticText(panel, wxID_ANY, "Students: ", wxPoint(40, 75));
	students_display->InsertColumn(0, "Student Name", wxLIST_FORMAT_LEFT, 200);
	students_display->InsertColumn(1, "Attendance %", wxLIST_FORMAT_LEFT, 120);
	students_display->InsertColumn(2, "Registeration Number", wxLIST_FORMAT_LEFT, 130);
	create_student->Bind(wxEVT_BUTTON, &MainFrame::create_s_dialogue, this);

	

	// Teacher
	wxButton* create_teacher = new wxButton(panel, wxID_ANY, "Create Teacher", wxPoint(905, 50));
	create_teacher->Bind(wxEVT_BUTTON, &MainFrame::create_t_dialogue, this);
	teacher_count_text = new wxStaticText(panel, wxID_ANY, std::to_string(teachers_created), wxPoint(100, 50));
	wxStaticText* teacher_count_label = new wxStaticText(panel, wxID_ANY, "Teachers : ", wxPoint(40, 50));
	teachers_display = new wxListBox(panel, wxID_ANY, wxPoint(40, 100), wxSize(200, 600), teacher_names, wxLB_NEEDED_SB);

	// other stuff
	classroom.set_classroom_name("Spring-2026 Object Oriented Programming");
	wxStaticText* class_label = new wxStaticText(panel, wxID_ANY, classroom.get_classname(), wxPoint(320, 25), wxSize(100, 50));
	class_label->SetFont(heading_font);
	wxButton* class_settings = new wxButton(panel, wxID_ANY, "Class Settings", wxPoint(800, 100));

	CreateStatusBar();
}


// this function creates teacher and dialogue menu.
void MainFrame::create_t_dialogue(wxCommandEvent& evt)
{
	CreateTeacherDialogue* dialogue = new CreateTeacherDialogue("Create Teacher");
	dialogue->Show(true);

	teachers[teachers_pos].create_teacher(dialogue->get_enteredname(), dialogue->get_enteredage(), dialogue->get_subject(), dialogue->get_enteredid());

	wxString str = wxString::Format("Teacher created with name : %s, Age : %d, Subject : %s ", teachers[teachers_pos].give_name(), teachers[teachers_pos].give_age(), teachers[teachers_pos].give_subject());
	wxLogStatus(str);

	/*
	 this block is responsible for UI, teacher_names array is for choices in the wxlist,
	teachers created keeps track of how many teachers have been created so far.
	teachers_pos is a variable used for creating next teacher. it moves to next position of the teachers array declared.
	*/ 
	teacher_names.Add(teachers[teachers_pos].give_name());
	wxString name = teachers[teachers_pos].give_name();
	teachers_display->Append(name);
	teachers_created++;
	teachers_pos++;
	teacher_count_text->SetLabel(std::to_string(teachers_created));

	
}

void MainFrame::create_s_dialogue(wxCommandEvent& evt)
{
	CreateStudentDialogue* dialogue = new CreateStudentDialogue("Create Student");
	dialogue->Show(true);

	students[students_pos].create_student(dialogue->get_enteredname(), dialogue->get_enteredage(), dialogue->get_entered_attendance(), dialogue->get_enteredid());

	wxString str = wxString::Format("Student created with name : %s, Age : %d ", students[students_pos].give_name(), students[students_pos].give_age());
	wxLogStatus(str);

	/*
	 this block is responsible for UI, teacher_names array is for choices in the wxlist,
	teachers created keeps track of how many teachers have been created so far.
	teachers_pos is a variable used for creating next teacher. it moves to next position of the teachers array declared.
	*/
	student_names.Add(students[students_pos].give_name());
	wxString name = students[students_pos].give_name();

	

	long index = students_display->InsertItem(students_pos, name);
	students_display->SetItem(index, 1, std::to_string(students[students_pos].give_attendance()));
	students_display->SetItem(index, 2, students[students_pos].give_roll());
	//students_display->Append(name);
	students_created++;
	students_pos++;
	student_count_text->SetLabel(std::to_string(students_created));
}


