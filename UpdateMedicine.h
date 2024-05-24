#pragma once
#include<wx/wx.h>
class UpdateMedicine :public wxFrame

{
	
wxTextCtrl* IdTextCtrl, *PriceTextCtrl, *StockTextCtrl, *SizeTextCtrl;
public:
	UpdateMedicine(const wxString& title);
	void OnUpdate(wxCommandEvent &event);
    void OnBack(wxCommandEvent& event);
};