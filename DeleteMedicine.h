#pragma once
#include <wx/wx.h>
class DeleteMedicine : public wxFrame

{
	wxFont boldFont;
	wxPanel* panel;
	wxTextCtrl *IdTextCtrl;
	wxTextCtrl* NameTextCtrl;

	wxStaticText* IdLabel;
	wxStaticText* NameLabel;
	wxButton* backButton;

	wxButton* IdDelete, *NameDelete;
	wxBoxSizer* sizer;

	int id;


public:
	void OnDeleteByID(wxCommandEvent &event);
	void OnDeleteByName(wxCommandEvent& event);
    void OnBack(wxCommandEvent& event);
	void OnDeleteMedicineID(wxCommandEvent& event);
	DeleteMedicine(const wxString& title);
    wxDECLARE_EVENT_TABLE();
};

