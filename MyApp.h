#include"wx/wx.h"
#include <stack>
class MyApp : public wxApp {
public:
    stack<wxFrame*> frames;
    bool OnInit() ;
};
