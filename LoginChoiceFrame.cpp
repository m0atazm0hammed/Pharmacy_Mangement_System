#include "LoginChoiceFrame.h"
#include "MainFrame.h"
#include "Menu.h"

LoginChoiceFrame::LoginChoiceFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    :wxFrame(NULL, wxID_ANY, title, pos, size) {
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Define a bold font
    wxFont boldFont(wxFontInfo(12).Bold());

    // Create buttons with bold text
    wxButton* employeeButton = new wxButton(panel, wxID_ANY, wxT("Enter as Employee"), wxDefaultPosition, wxSize(250, 50));
    employeeButton->SetFont(boldFont);
    wxButton* managerButton = new wxButton(panel, wxID_ANY, wxT("Enter as Manager"), wxDefaultPosition, wxSize(250, 50));
    managerButton->SetFont(boldFont);

    managerButton->Bind(wxEVT_BUTTON, &LoginChoiceFrame::OnManagerButton, this);  
    employeeButton->Bind(wxEVT_BUTTON, &LoginChoiceFrame::OnEmployeeButton, this);
    // Create a vertical box sizer to hold the buttons
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    // Add some space above and below the buttons
    sizer->AddStretchSpacer();
    sizer->Add(employeeButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(managerButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->AddStretchSpacer();

    // Set the sizer for the panel
    panel->SetSizer(sizer);

    // Center the panel in the frame
    Centre();
}




void LoginChoiceFrame::OnManagerButton(wxCommandEvent& event) {
    MainFrame* frame = new MainFrame("Manager Login", wxDefaultPosition, wxSize(300, 200));
    frame->SetClientSize(800, 600);
    frame->Center();
    frame->Show(true);
    MyApp::frames.push(this);
    this->Show(false);
}
void LoginChoiceFrame::OnEmployeeButton(wxCommandEvent& event) {
    auto frame = new Menu("Employee Dashboard", false);
    frame->SetClientSize(800, 600);
    frame->Center();
    frame->Show(true);
    Close();
}