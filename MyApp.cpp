#include"wx/wx.h"
#include"MainFrame.h"
#include"MyApp.h"
#include"LoginChoiceFrame.h"
#include"AddEmployeeFrame.h"
wxIMPLEMENT_APP(MyApp); 

bool MyApp::OnInit() {
    auto choiceFrame = new LoginChoiceFrame("Choose Login Type", wxDefaultPosition, wxSize(300, 200));
    choiceFrame->SetClientSize(800, 600);
    choiceFrame->Center();
    choiceFrame->Show(true);
    return true;
}
MyApp::~MyApp()
{
	while (!frames.empty())
	{
		auto frame = frames.top();
		frames.pop();
		frame->Destroy();
	}
}
std::stack<wxFrame*> MyApp::frames;