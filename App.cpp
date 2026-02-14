#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);
bool App::OnInit()
{
	MainFrame* mainframe = new MainFrame("Classroom Management System");
	mainframe->SetClientSize(1024, 768);
	//mainframe->ShowFullScreen(true);
	mainframe->Center();
	mainframe->Show();
	return true;
}
