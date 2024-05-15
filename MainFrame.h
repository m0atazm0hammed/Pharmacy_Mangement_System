#pragma once
#include "wx/wx.h"
class MainFrame : public wxFrame {
public:
    MainFrame(const wxString&, const wxPoint&, const wxSize&);
private:
    wxTextCtrl* userText;
    wxTextCtrl* passText;   
};