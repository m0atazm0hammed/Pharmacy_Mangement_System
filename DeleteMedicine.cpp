#include "DeleteMedicine.h"
#include<wx/wx.h>
#include "MainFrame.h"
DeleteMedicine::DeleteMedicine(const wxString& title) :wxFrame(nullptr, wxID_ANY, "Pharmacy Management System - Delete Medicine") {
	SetFont(GetFont().Scale(1.5));
	wxPanel* panel = new wxPanel(this);

	//wxCheckBox* checkBox = new wxCheckBox(panel,wxID_ANY,"Vitamin C",wxPoint(550,55));
	wxStaticText* statictext = new wxStaticText(panel, wxID_ANY, " Enter Name : ", wxPoint(343, 150));
	wxTextCtrl* textctrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 190), wxSize(200, -1));
	wxStaticText* statictext1 = new wxStaticText(panel, wxID_ANY, " Enter ID : ", wxPoint(343, 250));
	wxTextCtrl* textctrl1 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 290), wxSize(200, -1));
}