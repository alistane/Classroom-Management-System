#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);
bool App::OnInit()
{
	MainFrame* mainframe = new MainFrame("Classroom Management System");
	mainframe->SetClientSize(1920, 1080);
	mainframe->ShowFullScreen(true);
	//mainframe->Center();
	mainframe->Show();
	return true;
}
