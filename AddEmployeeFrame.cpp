#include "AddEmployeeFrame.h"
#include "Employee.h"

AddEmployeeFrame::AddEmployeeFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    :wxFrame(NULL, wxID_ANY, title, pos, size) {
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxFont boldFont(wxFontInfo(12).Bold());
    wxStaticText* IdLabel = new wxStaticText(panel, wxID_ANY, wxT("Id:"));
    IdLabel->SetFont(boldFont);
    wxStaticText* nameLabel = new wxStaticText(panel, wxID_ANY, wxT("Employee Name:"));
    nameLabel->SetFont(boldFont);
    wxStaticText* phoneLabel = new wxStaticText(panel, wxID_ANY, wxT("Phone Number:"));
    phoneLabel->SetFont(boldFont);
    wxStaticText* salaryLabel = new wxStaticText(panel, wxID_ANY, wxT("Salary:"));
    salaryLabel->SetFont(boldFont);
    wxStaticText* shiftLabel = new wxStaticText(panel, wxID_ANY, wxT("Shift:"));
    shiftLabel->SetFont(boldFont);
    IdTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 30)); // Larger size
    nameTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 30)); // Larger size
    phoneTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 30)); // Larger size
    salaryTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 30)); // Larger size
    shiftTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 30)); // Larger size
    wxButton* AddButton = new wxButton(panel, wxID_ANY, wxT("Add"), wxDefaultPosition, wxSize(200, 50)); // Larger size
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(IdLabel, 0, wxEXPAND | wxALL, 5);
    sizer->Add(IdTextCtrl, 0, wxEXPAND | wxALL, 5);
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

    AddButton->Bind(wxEVT_BUTTON, &AddEmployeeFrame::OnAdd, this);  
    Centre();
}

void AddEmployeeFrame::OnAdd(wxCommandEvent& event) {
    char name[20];
    std::cerr<< "1" << '\n';
    strcpy(name, nameTextCtrl->GetValue().ToStdString().c_str());
    std::cerr<< "1" << '\n';
    char phone [20];
    strcpy(phone,phoneTextCtrl->GetValue().ToStdString().c_str());
    std::cerr<< "1" << '\n';
    std::string salary = salaryTextCtrl->GetValue().ToStdString();
    char shiftt[20] ;
    std::cerr<< "1" << '\n';
    strcpy(shiftt,  shiftTextCtrl->GetValue().ToStdString().c_str());
    std::cerr<< "1" << '\n';
    Employee emp;
    std::cerr<< "1" << '\n';
	wxString wxId = IdTextCtrl->GetValue();
    std::cerr<< "1" << '\n';
	int id = std::stoi(wxId.ToStdString());
    int sal = std::stoi(salary);
    emp.Id(id);
    emp.Name(name);
    emp.Phone_num(phone);
    emp.Salary(sal);
    emp.Shift(shiftt);
    emp.Add();
    wxMessageBox("Added Seccessfully");
}
