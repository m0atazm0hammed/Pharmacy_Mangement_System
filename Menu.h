#pragma once
#include<wx/wx.h>

class Menu : public wxFrame
{
public:
	Menu(const wxString& title, bool manager);
	void OnAdd(wxCommandEvent& event);
	void OnUpdate(wxCommandEvent& event);
	void OnDelete(wxCommandEvent& event);
	void OnSearch(wxCommandEvent& event);
};
