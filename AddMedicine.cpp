#include "AddMedicine.h"
#include<wx/wx.h>
#include "MainFrame.h"
#include "Product.h"
AddMedicine::AddMedicine(const wxString& title):wxFrame(nullptr, wxID_ANY, "Pharmacy Management System - Add Medicine") {
	SetFont(GetFont().Scale(1.5));
	wxPanel* panel = new wxPanel(this);

	//wxCheckBox* checkBox = new wxCheckBox(panel,wxID_ANY,"Vitamin C",wxPoint(550,55));
	wxStaticText* statictext = new wxStaticText(panel, wxID_ANY, " Enter Name : ", wxPoint(343, 150));
	 textctrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 190), wxSize(200, -1));
	wxStaticText* statictext1 = new wxStaticText(panel, wxID_ANY, " Enter ID : ", wxPoint(343, 250));
	textctrl1 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 290), wxSize(200, -1));
	wxButton* button = new wxButton(panel, wxID_ANY, "Add", wxPoint(300, 390), wxSize(200, -1));
	
	
	button->Bind(wxEVT_BUTTON, &AddMedicine::OnAdd, this);
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->AddStretchSpacer();
	sizer->Add(statictext, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(textctrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(statictext1, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(textctrl1, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(button, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->AddStretchSpacer();
	panel->SetSizer(sizer);
	Centre();

}

void AddMedicine::OnAdd(wxCommandEvent& event)
{
	wxString wxName = textctrl->GetValue();
	std::string name = wxName.ToStdString();
	wxString wxId = textctrl1->GetValue();
	int id = wxAtoi(wxId);
	Product product;
	product.id = id;
	strcpy(product.name, name.c_str());
	product.price = 0;
	product.stock = 0;
	product.size = 0;
	strcpy(product.exp_date, "15-05-2025");
	product.Add();
	wxMessageBox("Medicine added", "Success", wxOK | wxICON_INFORMATION);
}