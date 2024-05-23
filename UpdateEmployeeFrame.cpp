#include "UpdateEmployeeFrame.h"
#include "Employee.h"

UpdateEmployeeFrame::UpdateEmployeeFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    :wxFrame(NULL, wxID_ANY, title, pos, size) {
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxFont boldFont(wxFontInfo(12).Bold());
    wxStaticText* IdLabel = new wxStaticText(panel, wxID_ANY, wxT("Id:"));
    IdLabel->SetFont(boldFont);
    wxStaticText* phoneLabel = new wxStaticText(panel, wxID_ANY, wxT("Phone Number:"));
    phoneLabel->SetFont(boldFont);
    wxStaticText* salaryLabel = new wxStaticText(panel, wxID_ANY, wxT("Salary:"));
    salaryLabel->SetFont(boldFont);
    wxStaticText* shiftLabel = new wxStaticText(panel, wxID_ANY, wxT("Shift:"));
    shiftLabel->SetFont(boldFont);
    IdTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 30)); // Larger size
    phoneTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 30)); // Larger size
    salaryTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 30)); // Larger size
    shiftTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 30)); // Larger size
    wxButton* AddButton = new wxButton(panel, wxID_ANY, wxT("Add"), wxDefaultPosition, wxSize(200, 50)); // Larger size
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(IdLabel, 0, wxEXPAND | wxALL, 5);
    sizer->Add(IdTextCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(phoneLabel, 0, wxEXPAND | wxALL, 5);
    sizer->Add(phoneTextCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(salaryLabel, 0, wxEXPAND | wxALL, 5);
    sizer->Add(salaryTextCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(shiftLabel, 0, wxEXPAND | wxALL, 5);
    sizer->Add(shiftTextCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(AddButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    panel->SetSizer(sizer);

    AddButton->Bind(wxEVT_BUTTON, &UpdateEmployeeFrame::OnUpdate, this);  
    Centre();
}

void UpdateEmployeeFrame::OnUpdate(wxCommandEvent& event) {

    wxString wxPhone = phoneTextCtrl->GetValue();
    std::string phone = wxPhone.ToStdString();
    std::string salary = salaryTextCtrl->GetValue().ToStdString();
	wxString wxId = IdTextCtrl->GetValue();
	int id = std::stoi(wxId.ToStdString());
    int sal = std::stoi(salary);
    wxString wxShift = shiftTextCtrl->GetValue();
    std::string shift = wxShift.ToStdString();
    Employee emp;
    char ph[20], shf[20];
    strcpy_s(ph, phone.c_str());
    strcpy_s(shf, shift.c_str());
    int ret = emp.Update(id, ph, sal, shf);
    if (ret)
        wxMessageBox("Updated Seccessfully");
    else
        wxMessageBox("Update Failed");
}
