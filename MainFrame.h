#pragma once
#include <wx/wx.h>
#include "MyApp.h"
class MainFrame : public wxFrame {
public:
    MainFrame(const wxString&, const wxPoint&, const wxSize&);
	void Login(wxCommandEvent& event);
    void OnBack(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
private:
    wxTextCtrl* userText;
    wxTextCtrl* passText;   
};