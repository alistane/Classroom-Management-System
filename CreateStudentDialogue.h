#pragma once
#include <wx/wx.h>
#include <wx/spinctrl.h>

class CreateStudentDialogue : public wxDialog
{
	private:
		wxTextCtrl* name;
		wxTextCtrl* subject;
		wxTextCtrl* id_capture;
		wxSpinCtrl* age;
		wxSpinCtrl* attendance;
		std::string entered_name;
		std::string entered_id;
		int entered_attendance_percent;
		int entered_age;
	public:
		CreateStudentDialogue(const wxString& title);
		void create_object(wxCommandEvent& evt);
		std::string get_enteredname();
		std::string get_enteredid();
		int get_enteredage();
		int get_entered_attendance();



};

