#include <wx/wx.h>
#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) {
    // Panel to hold the controls
    SetFont(GetFont().Scale(1.5));
    Center();
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Username
    wxStaticText* userLabel = new wxStaticText(panel, wxID_ANY, wxT("Username:"));
    userText = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(250, -1)); // Width set to 250 pixels

    // Password
    wxStaticText* passLabel = new wxStaticText(panel, wxID_ANY, wxT("Password:"));
    passText = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(250, -1), wxTE_PASSWORD); // Width set to 250 pixels

    // Login button
    wxButton* loginButton = new wxButton(panel, wxID_ANY, wxT("Login"), wxPoint(50, 10), wxSize(150, 30));

    // Sizer to arrange the controls vertically
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->AddStretchSpacer(); // Add space to the top
    sizer->Add(userLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5); // Center align username label
    sizer->Add(userText, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5); // Center align username text control
    sizer->Add(passLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5); // Center align password label
    sizer->Add(passText, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5); // Center align password text control
    sizer->AddSpacer(5); // Add a small spacer
    sizer->Add(loginButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5); // Center align login button
    sizer->AddStretchSpacer(); // Add space to the bottom
    panel->SetSizer(sizer);

    // Set the size of the frame
    sizer->Fit(this);
}
