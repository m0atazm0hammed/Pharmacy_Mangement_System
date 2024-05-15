#pragma once
#include <wx/wx.h>
class SearchMedicine : public wxFrame

{

private:
	wxPanel *panel;
	wxStaticText *statictext;
	wxTextCtrl *textctrl;
	wxStaticText *statictext1;
	wxTextCtrl *textctrl1;
	wxButton *searchById;
	wxButton *searchByName;

public:
	SearchMedicine(const wxString &title);
	void OnSearchById(wxCommandEvent &event);
	void OnSearchByName(wxCommandEvent &event);
};