#pragma once
#include<wx/wx.h>
class AddMedicine :public wxFrame

{
public:
wxTextCtrl* textctrl;
wxTextCtrl* textctrl1;
	AddMedicine(const wxString& title);
	void OnAdd(wxCommandEvent& event);
};

