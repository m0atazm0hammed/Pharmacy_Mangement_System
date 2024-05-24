#pragma once
#include<wx/wx.h>
class AddMedicine :public wxFrame

{

public:
	wxTextCtrl* NameCtrl,* IdCtrl, *PriceCtrl, *StockCtrl, *Exp_dateCtrl;
	wxPanel* panel;
	wxStaticText* NameLabel, *IdLabel, *PriceLabel, *StockLabel, *Exp_dateLabel;
	wxButton* button;

	AddMedicine(const wxString& title);
    void OnBack(wxCommandEvent& event);
	void OnAdd(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};
