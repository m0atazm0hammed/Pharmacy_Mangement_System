#include "DeleteMedicine.h"
#include <wx/wx.h>
#include "MainFrame.h"
#include "Product.h"
DeleteMedicine::DeleteMedicine(const wxString &title) : wxFrame(nullptr, wxID_ANY, "Pharmacy Management System - Delete Medicine"), boldFont(wxFontInfo(12).Bold())
{
    panel = new wxPanel(this, wxID_ANY);
    IdLabel = new wxStaticText(panel, wxID_ANY, wxT("Id:"));
    IdLabel->SetFont(boldFont);

    NameLabel = new wxStaticText(panel, wxID_ANY, wxT("Name:"));
    NameLabel->SetFont(boldFont);

    IdTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, -1));   // Larger size
    NameTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, -1)); // Larger size

    IdDelete = new wxButton(panel, wxID_ANY, wxT("Delete by ID"), wxDefaultPosition, wxSize(200, 35)); // Larger size
    IdDelete->SetFont(boldFont);

    NameDelete = new wxButton(panel, wxID_ANY, wxT("Delete by Name"), wxDefaultPosition, wxSize(200, 35)); // Larger size
    NameDelete->SetFont(boldFont);

    sizer = new wxBoxSizer(wxVERTICAL);
    sizer->AddStretchSpacer();
    sizer->Add(IdLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(IdTextCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(IdDelete, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->AddStretchSpacer();
    sizer->Add(NameLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(NameTextCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(NameDelete, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->AddStretchSpacer();
    panel->SetSizer(sizer);

    IdDelete->Bind(wxEVT_BUTTON, &DeleteMedicine::OnDeleteByID, this);
    NameDelete->Bind(wxEVT_BUTTON, &DeleteMedicine::OnDeleteByName, this);
    Centre();
}

void DeleteMedicine::OnDeleteByID(wxCommandEvent &event)
{
    wxString wxId = IdTextCtrl->GetValue();
    int id = std::stoi(wxId.ToStdString());

    Product product;
    int tmp = product.Delete(id);
    if (tmp)
        wxMessageBox("Medicine deleted", "Success", wxOK | wxICON_INFORMATION);
    else
        wxMessageBox("Medicine not found");
}

void DeleteMedicine::OnDeleteByName(wxCommandEvent &event)
{
    wxMessageBox("Medicine not found");
}