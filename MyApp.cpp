#include"wx/wx.h"
#include"MainFrame.h"
#include"MyApp.h"
#include"LoginChoiceFrame.h"
#include"AddEmployeeFrame.h"
wxIMPLEMENT_APP(MyApp); 



bool MyApp::OnInit() {
    auto choiceFrame = new LoginChoiceFrame("Choose Login Type", wxDefaultPosition, wxSize(300, 200));
    choiceFrame->SetClientSize(1280, 720);
    choiceFrame->Center();
    wxSizerFlags::DisableConsistencyChecks();
    choiceFrame->Show(true);
    return true;
}
std::stack<wxFrame*> MyApp::frames;
bool MyApp::BackPress = false;



void MyApp::OnClose(wxCloseEvent& event)
{
    if (!BackPress)
    {
        while (!MyApp::frames.empty())
        {
            auto frame = MyApp::frames.top();
            MyApp::frames.pop();
            frame->Close();
        }
    }
    else
        BackPress = false;
    event.Skip();
}
