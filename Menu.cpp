#include "Menu.h"
#include<wx/wx.h>
#include "AddEmployeeFrame.h"
#include "UpdateMedicine.h"
#include "DeleteMedicine.h"
#include "MainFrame.h"
#include "SearchMedicine.h"
#include "UpdateEmployeeFrame.h"
#include "MyApp.h"
#include "AddMedicine.h"


wxBEGIN_EVENT_TABLE(Menu, wxFrame)
    EVT_CLOSE(MyApp::OnClose)
wxEND_EVENT_TABLE()

Menu::Menu(const wxString& title, bool manager) :wxFrame(nullptr, wxID_ANY, title,
	wxPoint(30, 30), wxSize(1280, 720))
{
	wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Define a bold font
    wxFont boldFont(wxFontInfo(12).Bold());

    // Create buttons with bold text
    wxButton* addButton = new wxButton(panel, wxID_ANY, wxT("Add"), wxDefaultPosition, wxSize(250, 50));
    addButton->SetFont(boldFont);
    wxButton* updateButton = new wxButton(panel, wxID_ANY, wxT("Update"), wxDefaultPosition, wxSize(250, 50));
    updateButton->SetFont(boldFont);
	wxButton* deleteButton = new wxButton(panel, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxSize(250, 50));
	deleteButton->SetFont(boldFont);
    wxButton* searchButton = new wxButton(panel, wxID_ANY, wxT("Search"), wxDefaultPosition, wxSize(250, 50));
    searchButton->SetFont(boldFont);
    wxButton* backButton = new wxButton(panel, wxID_ANY, wxT("Logout"), wxPoint(10, 10), wxSize(150, 30));
    
    // Create a vertical box sizer to hold the buttons
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    // Add some space above and below the buttons
    sizer->AddStretchSpacer();
    sizer->Add(addButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(updateButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(deleteButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->Add(searchButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
    sizer->AddStretchSpacer();

    // Set the sizer for the panel
    panel->SetSizer(sizer);
    backButton->Bind(wxEVT_BUTTON, &Menu::OnBack, this);
    addButton->Bind(wxEVT_BUTTON, manager ? &Menu::OnAddEmployee : &Menu::OnAddProduct, this);
    updateButton->Bind(wxEVT_BUTTON, manager ? &Menu::OnUpdateEmployee : &Menu::OnUpdateProduct, this);
    deleteButton->Bind(wxEVT_BUTTON, manager ? &Menu::OnDeleteEmployee : &Menu::OnDeleteProduct, this);
    searchButton->Bind(wxEVT_BUTTON, manager ? &Menu::OnSearchEmployee : &Menu::OnSearchProduct, this);
    // Center the panel in the frame
    Centre();
	
}

void Menu::OnAddProduct(wxCommandEvent& event)
{
    auto frame = new AddMedicine("Add Medicine");//, wxPoint(30, 30), wxSize(800, 600));
    frame->SetClientSize(800, 600);
    frame->Center();
    frame->Show(true);
    MyApp::frames.push(this);
    Show(false);
}
void Menu::OnUpdateProduct(wxCommandEvent& event)
{
    auto frame = new UpdateMedicine("Update Medicine");
    frame->SetClientSize(800, 600);
    frame->Center();
    frame->Show(true);
    MyApp::frames.push(this);
    Show(false);
}
void Menu::OnDeleteProduct(wxCommandEvent& event)
{
    auto frame = new DeleteMedicine("Delete Medicine");
    frame->SetClientSize(1280, 720);
    frame->Center();
    frame->Show(true);
    MyApp::frames.push(this);
    Show(false);
}

void Menu::OnSearchProduct(wxCommandEvent& event)
{
    auto frame = new SearchMedicine("Search Medicine");
    frame->SetClientSize(800, 600);
    frame->Center();
    frame->Show(true);
    MyApp::frames.push(this);
    Show(false);
}


void Menu::OnAddEmployee(wxCommandEvent& event)
{
    auto frame = new AddEmployeeFrame("Add Employee", wxPoint(30, 30), wxSize(800, 600));
    frame->SetClientSize(800, 600);
    frame->Center();
    frame->Show(true);
    MyApp::frames.push(this);
    Show(false);
}
void Menu::OnUpdateEmployee(wxCommandEvent& event)
{
    auto frame = new UpdateEmployeeFrame("Update Employee", wxPoint(30, 30), wxSize(800, 600));
    frame->SetClientSize(800, 600);
    frame->Center();
    frame->Show(true);
    MyApp::frames.push(this);
    Show(false);
}
void Menu::OnDeleteEmployee(wxCommandEvent& event)
{
    auto frame = new DeleteMedicine("Delete Employee");
    frame->SetClientSize(800, 600);
    frame->Center();
    frame->Show(true);
    MyApp::frames.push(this);
    Show(false);
}

void Menu::OnSearchEmployee(wxCommandEvent& event)
{
    auto frame = new SearchMedicine("Search Employee");
    frame->SetClientSize(800, 600);
    frame->Center();
    frame->Show(true);
    MyApp::frames.push(this);
    Show(false);

}

void Menu::OnBack(wxCommandEvent& event)
{
    auto frame = MyApp::frames.top();
    frame->Show(true);
    MyApp::frames.pop();
    Close();
}