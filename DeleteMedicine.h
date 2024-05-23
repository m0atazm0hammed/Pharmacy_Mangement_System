#pragma once
#include <wx/wx.h>
class DeleteMedicine : public wxFrame

{
	wxFont boldFont;
	wxPanel *panel;
	wxTextCtrl *IdTextCtrl;
	wxTextCtrl *NameTextCtrl;

	wxStaticText *IdLabel;
	wxStaticText *NameLabel;

	wxButton *IdDelete, *NameDelete;
	wxBoxSizer *sizer;

public:
	void OnDeleteByID(wxCommandEvent &event);
	void OnDeleteByName(wxCommandEvent &event);
	DeleteMedicine(const wxString &title);
};
