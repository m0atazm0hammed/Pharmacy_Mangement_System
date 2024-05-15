#include "AddEmployeeFrame.h"

AddEmployeeFrame::AddEmployeeFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    :wxFrame(NULL, wxID_ANY, title, pos, size) {
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxFont boldFont(wxFontInfo(12).Bold());
    wxStaticText* nameLabel = new wxStaticText(panel, wxID_ANY, wxT("Employee Name:"));
    nameLabel->SetFont(boldFont);
    wxStaticText* phoneLabel = new wxStaticText(panel, wxID_ANY, wxT("Phone Number:"));
    phoneLabel->SetFont(boldFont);
    wxStaticText* salaryLabel = new wxStaticText(panel, wxID_ANY, wxT("Salary:"));
    salaryLabel->SetFont(boldFont);
    wxStaticText* shiftLabel = new wxStaticText(panel, wxID_ANY, wxT("Shift:"));
    shiftLabel->SetFont(boldFont);
    nameTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 30)); // Larger size
    phoneTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 30)); // Larger size
    salaryTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 30)); // Larger size
    shiftTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 30)); // Larger size
    wxButton* AddButton = new wxButton(panel, wxID_ANY, wxT("Add"), wxDefaultPosition, wxSize(200, 50)); // Larger size
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(nameLabel, 0, wxEXPAND | wxALL, 5);
    sizer->Add(nameTextCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(phoneLabel, 0, wxEXPAND | wxALL, 5);
    sizer->Add(phoneTextCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(salaryLabel, 0, wxEXPAND | wxALL, 5);
    sizer->Add(salaryTextCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(shiftLabel, 0, wxEXPAND | wxALL, 5);
    sizer->Add(shiftTextCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(AddButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    panel->SetSizer(sizer);
    Centre();
}
