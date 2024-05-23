#include"wx/wx.h"
#include <stack>
class MyApp : public wxApp {
public:
    static stack<wxFrame*> frames;
    bool OnInit() ;
};
