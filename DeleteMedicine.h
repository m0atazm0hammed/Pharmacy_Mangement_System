#pragma once
#include<wx/wx.h>
class DeleteMedicine :public wxFrame

{
	wxTextCtrl *IdTextCtrl;
public:
	void OnDelete(wxCommandEvent &event);
	DeleteMedicine(const wxString& title);
};

