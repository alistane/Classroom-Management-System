#include "MainFrame.h"
#include "Teacher.h"
#include "CreateTeacherDialogue.h"
#include "CreateStudentDialogue.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)     
{
	// Student 
	wxButton* create_student = new wxButton(panel, wxID_ANY, "Create Student", wxPoint(800, 50));
	students_display = new wxListBox(panel, wxID_ANY, wxPoint(500, 100), wxSize(200, 600), student_names);
	student_count_text = new wxStaticText(panel, wxID_ANY, std::to_string(teachers_created), wxPoint(500, 50));

	create_student->Bind(wxEVT_BUTTON, &MainFrame::create_s_dialogue, this);

	// Teacher
	wxButton* create_teacher = new wxButton(panel, wxID_ANY, "Create Teacher", wxPoint(905, 50));
	create_teacher->Bind(wxEVT_BUTTON, &MainFrame::create_t_dialogue, this);
	teacher_count_text = new wxStaticText(panel, wxID_ANY, std::to_string(teachers_created), wxPoint(100, 50));
	wxStaticText* teacher_count_label = new wxStaticText(panel, wxID_ANY, "Teachers : ", wxPoint(40, 50));
	teachers_display = new wxListBox(panel, wxID_ANY, wxPoint(40, 100), wxSize(200, 600), teacher_names);


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

	//for (int i = 0; i < teachers_created; i++)
	//{
	//	wxString name = teachers[i].give_name();
	//	teacher_names.Add(name);
	//	teachers_display->Append(name);
	//}

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
	students_display->Append(name);
	students_created++;
	students_pos++;
	student_count_text->SetLabel(std::to_string(students_created));
}


