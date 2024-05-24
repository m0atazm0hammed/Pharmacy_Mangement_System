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
std::stack<wxFrame*> MyApp::frames;




void MyApp::OnClose(wxCloseEvent& event)
{
    std::cerr << "closed" << std::endl;
    while (!MyApp::frames.empty())
    {
        auto frame = MyApp::frames.top();
        MyApp::frames.pop();
        frame->Close();
    }
    event.Skip();
}