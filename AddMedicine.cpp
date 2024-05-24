#include "AddMedicine.h"
#include<wx/wx.h>
#include "MainFrame.h"
#include "Product.h"
#include "MyApp.h"
AddMedicine::AddMedicine(const wxString& title):wxFrame(nullptr, wxID_ANY, "Pharmacy Management System - Add Medicine") {
	SetFont(GetFont().Scale(1.5));
	 panel = new wxPanel(this);

	//wxCheckBox* checkBox = new wxCheckBox(panel,wxID_ANY,"Vitamin C",wxPoint(550,55));
	NameLabel = new wxStaticText(panel, wxID_ANY, " Enter Name : ", wxPoint(343, 150));
	NameCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 190), wxSize(200, -1));
	IdLabel = new wxStaticText(panel, wxID_ANY, " Enter ID : ", wxPoint(343, 250));
	IdCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 290), wxSize(200, -1));
	PriceLabel = new wxStaticText(panel, wxID_ANY, " Enter Price : ", wxPoint(343, 350));
	PriceCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 390), wxSize(200, -1));
	StockLabel = new wxStaticText(panel, wxID_ANY, " Enter Stock : ", wxPoint(343, 450));
	StockCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 490), wxSize(200, -1));
	Exp_dateLabel = new wxStaticText(panel, wxID_ANY, " Enter Exp_date : ", wxPoint(343, 550));
	Exp_dateCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 590), wxSize(200, -1));

	button = new wxButton(panel, wxID_ANY, "Add", wxPoint(300, 390), wxSize(200, -1));
	
	wxButton* backButton = new wxButton(panel, wxID_ANY, wxT("Back"), wxPoint(10, 10), wxSize(150, 30));
    backButton->Bind(wxEVT_BUTTON, &AddMedicine::OnBack, this);
	button->Bind(wxEVT_BUTTON, &AddMedicine::OnAdd, this);
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->AddStretchSpacer();
	sizer->Add(NameLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(NameCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(IdLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(IdCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(PriceLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(PriceCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(StockLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(StockCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(Exp_dateLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(Exp_dateCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(button, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->AddStretchSpacer();
	panel->SetSizer(sizer);
	Centre();

}

void AddMedicine::OnAdd(wxCommandEvent& event)
{
	Product product;
	product.id = wxAtoi(IdCtrl->GetValue());
	strcpy(product.name, NameCtrl->GetValue().c_str());
	product.price = wxAtoi(PriceCtrl->GetValue());
	product.stock = wxAtoi(StockCtrl->GetValue());
	strcpy(product.exp_date, Exp_dateCtrl->GetValue().c_str());
	product.Add();
	wxMessageBox("Medicine added", "Success", wxOK | wxICON_INFORMATION);
}

void AddMedicine::OnBack(wxCommandEvent& event)
{
    auto frame = MyApp::frames.top();
    frame->Show(true);
    MyApp::frames.pop();
    Close();
}