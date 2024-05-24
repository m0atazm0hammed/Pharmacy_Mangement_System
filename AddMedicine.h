#pragma once
#include<wx/wx.h>
class AddMedicine :public wxFrame

{
public:
wxTextCtrl* textctrl;
wxTextCtrl* textctrl1;
	AddMedicine(const wxString& title);
    void OnBack(wxCommandEvent& event);
	void OnAdd(wxCommandEvent& event);
};

