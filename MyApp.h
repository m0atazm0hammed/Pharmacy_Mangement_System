#include"wx/wx.h"
#include <stack>
class MyApp : public wxApp {
public:
    static std::stack<wxFrame*> frames;
    bool OnInit() ;
    void OnClose(wxCloseEvent& event);
};
