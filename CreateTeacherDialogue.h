#pragma once
#include <wx/wx.h>
#include <wx/spinctrl.h>
class CreateTeacherDialogue : public wxDialog
{
	private:
	wxTextCtrl* name;
	wxTextCtrl* subject;
	wxTextCtrl* id_capture;
	wxSpinCtrl* age;
	std::string entered_name;
	std::string entered_subject;
	std::string entered_id;
	int entered_age;
	public:
		
		CreateTeacherDialogue(const wxString& title);
		void create_object(wxCommandEvent& evt);
		std::string get_enteredname();
		std::string get_subject();
		std::string get_enteredid();
		int get_enteredage();



};

