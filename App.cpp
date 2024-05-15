#include "App.h"
#include "Manager.h"
 
wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	auto *frame = new Manager("test");
	frame->Show();
	return true;
}
