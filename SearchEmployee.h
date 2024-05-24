#pragma once
#include <wx/wx.h>
class SearchEmployee : public wxFrame
{
	
private:
	wxPanel *panel;
	wxStaticText *NameLabel;
	wxTextCtrl *NameCtrl;
	wxStaticText *IdLabel;
	wxTextCtrl *IdCtrl;
	wxButton *searchById;
	wxButton *searchByName;
	wxFont boldFont;
	wxBoxSizer* sizer;
public:
	SearchEmployee(const wxString &title);
	void OnSearchById(wxCommandEvent &event);
    void OnBack(wxCommandEvent &event);
	void OnSearchByName(wxCommandEvent &event);
    wxDECLARE_EVENT_TABLE();
};