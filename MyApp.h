#pragma once
#include"wx/wx.h"
#include <stack>
class MyApp : public wxApp {
public:
    static std::stack<wxFrame*> frames;
    static bool BackPress;
    bool OnInit() ;
    void OnClose(wxCloseEvent& event);
};

