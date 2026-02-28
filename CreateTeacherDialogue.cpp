#include "CreateTeacherDialogue.h"


CreateTeacherDialogue::CreateTeacherDialogue(const wxString& title)
    : wxDialog(NULL, -1, title, wxDefaultPosition, wxSize(500, 500))
{
    wxPanel* panel = new wxPanel(this, -1);
    wxStaticText* name_label = new wxStaticText(panel, wxID_ANY, "Name: ", wxPoint(50,25));
    name = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(50,50));
    
   

    wxStaticText* id_label = new wxStaticText(panel, wxID_ANY, "ID: ", wxPoint(50, 100));
    id_capture = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(50, 125));

    wxStaticText* age_label = new wxStaticText(panel, wxID_ANY, "Age: ", wxPoint(300, 165));
    age = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(300, 190), wxDefaultSize);
    age->SetRange(18, 100);

    // populating subject_options array.
    for (int i = 0; i < 5; i++)
    {
        subject_options.Add(dummy.courses[i]);
    }
    
    wxStaticText* subject_label = new wxStaticText(panel, wxID_ANY, "Subject: ", wxPoint(200, 25));

    subject_list = new wxListBox(panel, wxID_ANY, wxPoint(200, 50), wxSize(200, 100), subject_options, wxLB_NEEDED_SB);

    wxButton* create_button = new wxButton(panel, wxID_ANY, "Create", wxPoint(200, 300));
    create_button->Bind(wxEVT_BUTTON, &CreateTeacherDialogue::create_object, this);
    ShowModal();


}

void CreateTeacherDialogue :: create_object(wxCommandEvent& evt)
{
    entered_name = name->GetValue();
    entered_subject = dummy.courses[subject_list->GetSelection()];
    entered_id = id_capture->GetValue();
    entered_age = age->GetValue();

    

    if (entered_name == "")
    {
        wxLogError("Enter a Name!");
    }
    if (entered_subject == "")
    {
        wxLogError("Choose a subject!");
    }
    if (entered_id == "")
    {
        wxLogError("Enter a ID!");
    }
    
    if(entered_name != "" && entered_subject != "" && entered_id != "")
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