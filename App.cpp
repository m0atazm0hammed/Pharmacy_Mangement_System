#include "App.h"
 
wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	MainFrame *frame = new MainFrame("test");
	frame->Show();
	return true;
}
