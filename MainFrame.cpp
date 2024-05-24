#include <wx/wx.h>
#include "MainFrame.h"
#include "MyApp.h"
#include "Menu.h"
#include "MyApp.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_CLOSE(MyApp::OnClose)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString&title, const wxPoint&pos, const wxSize& size):wxFrame(nullptr, wxID_ANY, title, pos, size)
{
    SetIcon(wxIcon(wxT("icon.ico"), wxBITMAP_TYPE_ICO));

    SetFont(GetFont().Scale(1.5));
    Center();
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Username
    wxStaticText* userLabel = new wxStaticText(panel, wxID_ANY, wxT("Username:"));
    userText = new wxTextCtrl(panel, wxID_ANY, wxT("admin"), wxDefaultPosition, wxSize(250, -1)); // Width set to 250 pixels

    // Password
    wxStaticText* passLabel = new wxStaticText(panel, wxID_ANY, wxT("Password:"));
    passText = new wxTextCtrl(panel, wxID_ANY, wxT("admin"), wxDefaultPosition, wxSize(250, -1), wxTE_PASSWORD); // Width set to 250 pixels

    // Login button
    wxButton* loginButton = new wxButton(panel, wxID_ANY, wxT("Login"), wxPoint(50, 10), wxSize(150, 30));
    wxButton* backButton = new wxButton(panel, wxID_ANY, wxT("Back"), wxPoint(10, 10), wxSize(150, 30));
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

    backButton->Bind(wxEVT_BUTTON, &MainFrame::OnBack, this);
    loginButton->Bind(wxEVT_BUTTON, &MainFrame::Login, this);
    // Set the size of the frame
    sizer->Fit(this);
}

void MainFrame::Login(wxCommandEvent& event)
{
	std::string user = userText->GetValue().ToStdString();
	std::string pass = passText->GetValue().ToStdString();

	if (user == "admin" && pass == "admin")
	{
		auto frame = new Menu("Manager Dashboard", true);
		frame->SetClientSize(1280, 720);
		frame->Center();
		frame->Show(true);
        MyApp::frames.push(this);
        Show(false);
	}
	else
	{
		wxMessageBox("Invalid username or password");
	}
}

void MainFrame::OnBack(wxCommandEvent& event)
{
    auto frame = MyApp::frames.top();
    frame->Show(true);
    MyApp::frames.pop();
	MyApp::BackPress = true;
    Close();
}