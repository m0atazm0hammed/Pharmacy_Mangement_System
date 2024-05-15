#include "Menu.h"
#include<wx/wx.h>
#include "AddEmployeeFrame.h"
#include "UpdateMedicine.h"
#include "DeleteMedicine.h"
#include "MainFrame.h"
#include "SearchMedicine.h"
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
    addButton->Bind(wxEVT_BUTTON, &Menu::OnAdd, this);
    updateButton->Bind(wxEVT_BUTTON, &Menu::OnUpdate, this);
    deleteButton->Bind(wxEVT_BUTTON, &Menu::OnDelete, this);
    searchButton->Bind(wxEVT_BUTTON, &Menu::OnSearch, this);
    // Center the panel in the frame
    Centre();
	
}

void Menu::OnAdd(wxCommandEvent& event)
{
    auto frame = new AddEmployeeFrame("Add Medicine", wxDefaultPosition, wxSize(300, 200));
    frame->SetClientSize(800, 600);
    frame->Center();
    frame->Show(true);
    Close();
}
void Menu::OnUpdate(wxCommandEvent& event)
{
    auto frame = new UpdateMedicine("Update Medicine");
    frame->SetClientSize(800, 600);
    frame->Center();
    frame->Show(true);
    Close();
}
void Menu::OnDelete(wxCommandEvent& event)
{
    auto frame = new DeleteMedicine("Delete Medicine");
    frame->SetClientSize(800, 600);
    frame->Center();
    frame->Show(true);
    Close();
}

void Menu::OnSearch(wxCommandEvent& event)
{
    auto frame = new SearchMedicine("Search Medicine");
    frame->SetClientSize(800, 600);
    frame->Center();
    frame->Show(true);
    Close();
}