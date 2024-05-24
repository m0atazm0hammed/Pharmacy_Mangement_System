#include "UpdateEmployeeFrame.h"
#include "Employee.h"
#include "MyApp.h"

wxBEGIN_EVENT_TABLE(UpdateEmployeeFrame, wxFrame)
    EVT_CLOSE(MyApp::OnClose)
        wxEND_EVENT_TABLE()

            UpdateEmployeeFrame::UpdateEmployeeFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    SetIcon(wxIcon(wxT("icon.ico"), wxBITMAP_TYPE_ICO));

    wxPanel *panel = new wxPanel(this, wxID_ANY);
    wxFont boldFont(wxFontInfo(12).Bold());
    wxStaticText *IdLabel = new wxStaticText(panel, wxID_ANY, wxT("ID:"));
    IdLabel->SetFont(boldFont);
    wxStaticText *phoneLabel = new wxStaticText(panel, wxID_ANY, wxT("Phone Number:"));
    phoneLabel->SetFont(boldFont);
    wxStaticText *salaryLabel = new wxStaticText(panel, wxID_ANY, wxT("Salary:"));
    salaryLabel->SetFont(boldFont);
    wxStaticText *shiftLabel = new wxStaticText(panel, wxID_ANY, wxT("Shift:"));
    shiftLabel->SetFont(boldFont);
    IdTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(343, 150), wxSize(200, -1));        // Larger size
    phoneTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(343, 190), wxSize(200, -1));     // Larger size
    salaryTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(343, 250), wxSize(200, -1));    // Larger size
    shiftTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(343, 290), wxSize(200, -1));     // Larger size
    wxButton *AddButton = new wxButton(panel, wxID_ANY, wxT("Update"), wxPoint(343, 350), wxSize(200, -1)); // Larger size
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    AddButton->SetFont(boldFont);

    wxButton *BackButton = new wxButton(panel, wxID_ANY, wxT("Back"), wxPoint(10, 10), wxSize(150, 30));
    sizer->AddStretchSpacer();
    sizer->Add(IdLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(IdTextCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(phoneLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(phoneTextCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(salaryLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(salaryTextCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(shiftLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(shiftTextCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(AddButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->AddStretchSpacer();
    panel->SetSizer(sizer);

    AddButton->Bind(wxEVT_BUTTON, &UpdateEmployeeFrame::OnUpdate, this);
    BackButton->Bind(wxEVT_BUTTON, &UpdateEmployeeFrame::OnBack, this);
    Centre();
}

void UpdateEmployeeFrame::OnUpdate(wxCommandEvent &event)
{

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

void UpdateEmployeeFrame::OnBack(wxCommandEvent &event)
{
    auto frame = MyApp::frames.top();
    frame->Show(true);
    MyApp::frames.pop();
    MyApp::BackPress = true;
    Close(true);
}
