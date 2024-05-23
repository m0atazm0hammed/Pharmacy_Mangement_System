#pragma once
#include<wx/wx.h>

class Menu : public wxFrame
{
public:
	Menu(const wxString& title, bool manager);
	void OnAddProduct(wxCommandEvent& event);
	void OnAddEmployee(wxCommandEvent& event);
	void OnUpdateProduct(wxCommandEvent& event);
	void OnUpdateEmployee(wxCommandEvent& event);
	void OnDeleteProduct(wxCommandEvent& event);
	void OnDeleteEmployee(wxCommandEvent& event);
	void OnSearchProduct(wxCommandEvent& event);
	void OnSearchEmployee(wxCommandEvent& event);
};
