#include "DeleteMedicine.h"
#include<wx/wx.h>
#include "MainFrame.h"
#include "Product.h"
DeleteMedicine::DeleteMedicine(const wxString& title) :wxFrame(nullptr, wxID_ANY, "Pharmacy Management System - Delete Medicine") {
	wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxFont boldFont(wxFontInfo(12).Bold());
    wxStaticText* IdLabel = new wxStaticText(panel, wxID_ANY, wxT("Id:"));
    IdLabel->SetFont(boldFont);
    
    IdTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 30)); // Larger size
    wxButton* DeleteButton = new wxButton(panel, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxSize(200, 50)); // Larger size
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(IdLabel, 0, wxEXPAND | wxALL, 5);
    sizer->Add(IdTextCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(DeleteButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    panel->SetSizer(sizer);

    DeleteButton->Bind(wxEVT_BUTTON, &DeleteMedicine::OnDelete, this);  
    Centre();
}

void DeleteMedicine::OnDelete(wxCommandEvent &event)
{
	wxString wxId = IdTextCtrl->GetValue();
	int id = std::stoi(wxId.ToStdString());

	Product product;
	product.Delete(id);
	wxMessageBox("Medicine deleted", "Success", wxOK | wxICON_INFORMATION);
}