#include "UpdateMedicine.h"
#include<wx/spinctrl.h>
#include<wx/wx.h>
#include "MainFrame.h"
#include "Product.h"
UpdateMedicine::UpdateMedicine(const wxString& title) :wxFrame(nullptr, wxID_ANY, "Pharmacy Management System - Update Medicine") {
	wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxFont boldFont(wxFontInfo(12).Bold());
    wxStaticText* IdLabel = new wxStaticText(panel, wxID_ANY, wxT("Id:"));
    IdLabel->SetFont(boldFont);
    wxStaticText* PriceLabel = new wxStaticText(panel, wxID_ANY, wxT("Price:"));
    PriceLabel->SetFont(boldFont);
    wxStaticText* StockLabel = new wxStaticText(panel, wxID_ANY, wxT("Stock:"));
    StockLabel->SetFont(boldFont);
    wxStaticText* SizeLabel = new wxStaticText(panel, wxID_ANY, wxT("Size:"));
    SizeLabel->SetFont(boldFont);
    IdTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 30)); // Larger size
    PriceTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 30)); // Larger size
    StockTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 30)); // Larger size
    SizeTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 30)); // Larger size
    wxButton* UpdateButton = new wxButton(panel, wxID_ANY, wxT("Update"), wxDefaultPosition, wxSize(200, 50)); // Larger size
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    wxButton* backButton = new wxButton(panel, wxID_ANY, wxT("Back"), wxPoint(10, 10), wxSize(150, 30));
    backButton->Bind(wxEVT_BUTTON, &UpdateMedicine::OnBack, this);
    
    sizer->Add(IdLabel, 0, wxEXPAND | wxALL, 5);
    sizer->Add(IdTextCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(PriceLabel, 0, wxEXPAND | wxALL, 5);
    sizer->Add(PriceTextCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(StockLabel, 0, wxEXPAND | wxALL, 5);
    sizer->Add(StockTextCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(SizeLabel, 0, wxEXPAND | wxALL, 5);
    sizer->Add(SizeTextCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(UpdateButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    panel->SetSizer(sizer);

    UpdateButton->Bind(wxEVT_BUTTON, &UpdateMedicine::OnUpdate, this);  
    Centre();
}

void UpdateMedicine::OnUpdate(wxCommandEvent &event)
{
	wxString wxId = IdTextCtrl->GetValue();
	int id = std::stoi(wxId.ToStdString());
	wxString wxPrice = PriceTextCtrl->GetValue();
	int price = std::stoi(wxPrice.ToStdString());
	wxString wxStock = StockTextCtrl->GetValue();
	int stock = std::stoi(wxPrice.ToStdString());
	wxString wxSize = SizeTextCtrl->GetValue();
	int size = std::stoi(wxSize.ToStdString());

	Product product;
	product.id = id;
	product.price = price;
	product.stock = stock;
	product.size = size;
	int ret = product.Update(id, price, stock, size);
	if (ret)
        wxMessageBox("Updated Seccessfully");
    else
        wxMessageBox("Update Failed");
}


void UpdateMedicine::OnBack(wxCommandEvent& event)
{
    auto frame = MyApp::frames.top();
    frame->Show(true);
    MyApp::frames.pop();
    Close(true);
}