#pragma once
#include "wx/wx.h"
class MainFrame : public wxFrame {
public:
    MainFrame(const wxString&, const wxPoint&, const wxSize&);
	void Login(wxCommandEvent& event);
    void OnBack(wxCommandEvent& event);
private:
    wxTextCtrl* userText;
    wxTextCtrl* passText;   
};