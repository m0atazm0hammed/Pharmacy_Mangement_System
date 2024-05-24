#include "AddEmployeeFrame.h"
#include "Employee.h"
#include "MyApp.h"

wxBEGIN_EVENT_TABLE(AddEmployeeFrame, wxFrame)
    EVT_CLOSE(MyApp::OnClose)
        wxEND_EVENT_TABLE()

            AddEmployeeFrame::AddEmployeeFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxPanel *panel = new wxPanel(this, wxID_ANY);
    wxFont boldFont(wxFontInfo(12).Bold());
    wxStaticText *IdLabel = new wxStaticText(panel, wxID_ANY, wxT("Id:"));
    IdLabel->SetFont(boldFont);
    wxStaticText *nameLabel = new wxStaticText(panel, wxID_ANY, wxT("Employee Name:"));
    nameLabel->SetFont(boldFont);
    wxStaticText *phoneLabel = new wxStaticText(panel, wxID_ANY, wxT("Phone Number:"));
    phoneLabel->SetFont(boldFont);
    wxStaticText *salaryLabel = new wxStaticText(panel, wxID_ANY, wxT("Salary:"));
    salaryLabel->SetFont(boldFont);
    wxStaticText *shiftLabel = new wxStaticText(panel, wxID_ANY, wxT("Shift:"));
    shiftLabel->SetFont(boldFont);
    IdTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(343, 150), wxSize(200, -1));     // Larger size
    nameTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(343, 190), wxSize(200, -1));   // Larger size
    phoneTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(343, 250), wxSize(200, -1));  // Larger size
    salaryTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(343, 290), wxSize(200, -1)); // Larger size
    shiftTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(343, 350), wxSize(200, -1));  // Larger size
    wxButton *AddButton = new wxButton(panel, wxID_ANY, wxT("Add"), wxPoint(343, 390), wxSize(200, -1)); // Larger size
    AddButton->SetFont(boldFont);
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    wxButton *backButton = new wxButton(panel, wxID_ANY, wxT("Back"), wxPoint(10, 10), wxSize(150, 30));
    backButton->Bind(wxEVT_BUTTON, &AddEmployeeFrame::OnBack, this);
    sizer->AddStretchSpacer();
    sizer->Add(IdLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(IdTextCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(nameLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(nameTextCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(phoneLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(phoneTextCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(salaryLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(salaryTextCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(shiftLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(shiftTextCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(AddButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->AddStretchSpacer();
    panel->SetSizer(sizer);


    AddButton->Bind(wxEVT_BUTTON, &AddEmployeeFrame::OnAdd, this);
    Centre();
}

void AddEmployeeFrame::OnAdd(wxCommandEvent &event)
{
    Employee emp;
    wxString wxName = nameTextCtrl->GetValue();
    std::string name = wxName.ToStdString();
    strcpy(emp.name, name.c_str());
    wxString wxPhone = phoneTextCtrl->GetValue();
    std::string phone = wxPhone.ToStdString();
    strcpy(emp.phone_num, phone.c_str());
    std::string salary = salaryTextCtrl->GetValue().ToStdString();
    char shiftt[20];
    strcpy(shiftt, shiftTextCtrl->GetValue().ToStdString().c_str());
    wxString wxId = IdTextCtrl->GetValue();
    int id = std::stoi(wxId.ToStdString());
    int sal = std::stoi(salary);
    emp.id = id;
    emp.Salary(sal);
    emp.Shift(shiftt);
    emp.Add();
    wxMessageBox("Added Seccessfully");
}

void AddEmployeeFrame::OnBack(wxCommandEvent &event)
{
    auto frame = MyApp::frames.top();
    frame->Show(true);
    MyApp::frames.pop();
    MyApp::BackPress = true;
    Close(true);
}
