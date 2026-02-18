#include "CreateTeacherDialogue.h"


CreateTeacherDialogue::CreateTeacherDialogue(const wxString& title)
    : wxDialog(NULL, -1, title, wxDefaultPosition, wxSize(500, 500))
{
    wxPanel* panel = new wxPanel(this, -1);
    wxStaticText* name_label = new wxStaticText(panel, wxID_ANY, "Name: ", wxPoint(50,25));
    name = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(50,50));
    
    wxStaticText* subject_label = new wxStaticText(panel, wxID_ANY, "Subject: ", wxPoint(300, 25));
    subject = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(300, 50));

    wxStaticText* id_label = new wxStaticText(panel, wxID_ANY, "ID: ", wxPoint(50, 75));
    id_capture = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(50, 100));

    wxStaticText* age_label = new wxStaticText(panel, wxID_ANY, "Age: ", wxPoint(300, 75));
    age = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(300, 100), wxDefaultSize);
    age->SetRange(18, 100);


    wxButton* create_button = new wxButton(panel, wxID_ANY, "Create", wxPoint(200, 300));
    create_button->Bind(wxEVT_BUTTON, &CreateTeacherDialogue::create_object, this);
    ShowModal();


}

void CreateTeacherDialogue :: create_object(wxCommandEvent& evt)
{
    entered_name = name->GetValue();
    entered_subject = subject->GetValue();
    entered_id = id_capture->GetValue();
    entered_age = age->GetValue();

    if (entered_age < 18 || entered_age > 100)
    {
        wxLogError("Incorrect Age value!");
    }

    else
    {
        Destroy();

    }


    //wxString str = wxString::Format("Age : %d", entered_age);

    //wxLogMessage(str);

}

std::string CreateTeacherDialogue::get_enteredname()
{
    return entered_name;

}
std::string CreateTeacherDialogue::get_subject()
{
    return entered_subject;

}
std::string CreateTeacherDialogue::get_enteredid()
{
    return entered_id;

}
int CreateTeacherDialogue::get_enteredage()
{
    return entered_age;
}