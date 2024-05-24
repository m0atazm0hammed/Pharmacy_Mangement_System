#include "UpdateMedicine.h"
#include <wx/spinctrl.h>
#include <wx/wx.h>
#include "MainFrame.h"
#include "MyApp.h"
#include "Product.h"

wxBEGIN_EVENT_TABLE(UpdateMedicine, wxFrame)
    EVT_CLOSE(MyApp::OnClose)
        wxEND_EVENT_TABLE()

            UpdateMedicine::UpdateMedicine(const wxString &title) : wxFrame(nullptr, wxID_ANY, "Pharmacy Management System - Update Medicine")
{
    SetIcon(wxIcon(wxT("icon.ico"), wxBITMAP_TYPE_ICO));

    wxPanel *panel = new wxPanel(this, wxID_ANY);
    wxFont boldFont(wxFontInfo(12).Bold());
    wxStaticText *IdLabel = new wxStaticText(panel, wxID_ANY, wxT("Id:"));
    IdLabel->SetFont(boldFont);
    wxStaticText *PriceLabel = new wxStaticText(panel, wxID_ANY, wxT("Price:"));
    PriceLabel->SetFont(boldFont);
    wxStaticText *StockLabel = new wxStaticText(panel, wxID_ANY, wxT("Stock:"));
    StockLabel->SetFont(boldFont);
    IdTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(343, 150), wxSize(200, -1));           // Larger size
    PriceTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(343, 190), wxSize(200, -1));        // Larger size
    StockTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(343, 250), wxSize(200, -1));        // Larger size
    wxButton *UpdateButton = new wxButton(panel, wxID_ANY, wxT("Update"), wxPoint(343, 350), wxSize(200, -1)); // Larger size
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    wxButton *backButton = new wxButton(panel, wxID_ANY, wxT("Back"), wxPoint(10, 10), wxSize(150, 30));
    UpdateButton->SetFont(boldFont);
    backButton->Bind(wxEVT_BUTTON, &UpdateMedicine::OnBack, this);
    sizer->AddStretchSpacer();
    sizer->Add(IdLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(IdTextCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(PriceLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(PriceTextCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(StockLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(StockTextCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(UpdateButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->AddStretchSpacer();
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

    Product product;
    product.id = id;
    product.price = price;
    product.stock = stock;
    int ret = product.Update(id, price, stock);
    if (ret)
        wxMessageBox("Updated Seccessfully");
    else
        wxMessageBox("Update Failed");
}

void UpdateMedicine::OnBack(wxCommandEvent &event)
{
    auto frame = MyApp::frames.top();
    frame->Show(true);
    MyApp::frames.pop();
    MyApp::BackPress = true;
    Close(true);
}