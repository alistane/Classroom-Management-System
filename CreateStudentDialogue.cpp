#include "CreateStudentDialogue.h"
#include <wx/wx.h>




CreateStudentDialogue::CreateStudentDialogue(const wxString& title)
    : wxDialog(NULL, -1, title, wxDefaultPosition, wxSize(500, 500))
{
    wxPanel* panel = new wxPanel(this, -1);
    wxStaticText* name_label = new wxStaticText(panel, wxID_ANY, "Name: ", wxPoint(50, 25));
    name = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(50, 50));
    
    wxStaticText* attendance_label = new wxStaticText(panel, wxID_ANY, "Attendance: ", wxPoint(300, 25));
    attendance = new wxSpinCtrl(panel, wxID_ANY, "100" , wxPoint(300, 50), wxDefaultSize);
    attendance->SetRange(0, 100);
    
    wxStaticText* id_label = new wxStaticText(panel, wxID_ANY, "ID: ", wxPoint(50, 75));
    id_capture = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(50, 100));

    wxStaticText* age_label = new wxStaticText(panel, wxID_ANY, "Age: ", wxPoint(300, 75));
    age = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(300, 100), wxDefaultSize);
    age->SetRange(18, 100);


    wxButton* create_button = new wxButton(panel, wxID_ANY, "Create", wxPoint(200, 300));
    create_button->Bind(wxEVT_BUTTON, &CreateStudentDialogue::create_object, this);
    ShowModal();


}

void CreateStudentDialogue::create_object(wxCommandEvent& evt)
{
    entered_name = name->GetValue();
    entered_id = id_capture->GetValue();
    entered_age = age->GetValue();
    entered_attendance_percent = attendance->GetValue();

    if (entered_age < 18 || entered_age > 100)
    {
        wxLogError("Incorrect Age value!");
    }

    else
    {
        Destroy();

    }


}

std::string CreateStudentDialogue::get_enteredname()
{
    return entered_name;

}

std::string CreateStudentDialogue::get_enteredid()
{
    return entered_id;

}
int CreateStudentDialogue::get_enteredage()
{
    return entered_age;
}

int CreateStudentDialogue::get_entered_attendance()
{
    return entered_attendance_percent;
}