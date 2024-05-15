#include "UpdateMedicine.h"
#include<wx/spinctrl.h>
#include<wx/wx.h>
#include "MainFrame.h"
UpdateMedicine::UpdateMedicine(const wxString& title) :wxFrame(nullptr, wxID_ANY, "Pharmacy Management System - Update Medicine") {
	SetFont(GetFont().Scale(1.5));
	wxPanel* panel = new wxPanel(this);


	wxStaticText* statictext = new wxStaticText(panel, wxID_ANY, " Enter Name : ", wxPoint(343, 150));
	wxTextCtrl* textctrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 190), wxSize(200, -1));
	wxStaticText* statictext1 = new wxStaticText(panel, wxID_ANY, " Enter ID : ", wxPoint(343, 250));
	wxTextCtrl* textctrl1 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 290), wxSize(200, -1));
	wxStaticText* statictext2 = new wxStaticText(panel, wxID_ANY, " Quantity : ", wxPoint(343, 350));
	wxSpinCtrl* spinctrl = new wxSpinCtrl(panel, wxID_ANY,"", wxPoint(300, 390), wxSize(200, -1));	//Quantity
	wxButton* button = new wxButton(panel, wxID_ANY, "Update", wxPoint(300, 490), wxSize(200, -1));

		
}