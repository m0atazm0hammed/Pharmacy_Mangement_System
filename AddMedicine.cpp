#include "AddMedicine.h"
#include<wx/wx.h>
#include "MainFrame.h"
AddMedicine::AddMedicine(const wxString& title):wxFrame(nullptr, wxID_ANY, "Pharmacy Management System - Add Medicine") {
	SetFont(GetFont().Scale(1.5));
	wxPanel* panel = new wxPanel(this);

	//wxCheckBox* checkBox = new wxCheckBox(panel,wxID_ANY,"Vitamin C",wxPoint(550,55));
	wxStaticText* statictext = new wxStaticText(panel, wxID_ANY, " Enter Name : ", wxPoint(343, 150));
	wxTextCtrl* textctrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 190), wxSize(200, -1));
	wxStaticText* statictext1 = new wxStaticText(panel, wxID_ANY, " Enter ID : ", wxPoint(343, 250));
	wxTextCtrl* textctrl1 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 290), wxSize(200, -1));
	wxButton* button = new wxButton(panel, wxID_ANY, "Add", wxPoint(300, 390), wxSize(200, -1));
	
	

	
	/*wxBoxSizer* boxsizer = new wxBoxSizer(wxHORIZONTAL);
	SetSizerAndFit(boxsizer);*/
	// Create a button styled as "medicine"
	//wxButton* medicineButton = new wxButton(panel, wxID_ANY, "Add Medicine", wxPoint(330, 150), wxSize(150, 50));

	// Set the background color and font
	//medicineButton->SetBackgroundColour(wxColour(128, 128, 128)); // Green background color
	//medicineButton->SetForegroundColour(*wxWHITE); // White text color
	//medicineButton->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
}