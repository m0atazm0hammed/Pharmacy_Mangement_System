#include "Home.h"
#include<wx/wx.h>
#include "MainFrame.h"

Home::Home(const wxString& title) :wxFrame(nullptr, wxID_ANY, "Pharmacy Management System - Login")
{
	SetFont(GetFont().Scale(1.5));
	wxPanel* panel = new wxPanel(this);

	panel->SetBackgroundColour(wxColour(240, 240, 240));


	wxStaticText* statictext = new wxStaticText(panel, wxID_ANY, " - UserName ", wxPoint(345, 50));
	wxTextCtrl* textctrl = new wxTextCtrl(panel, wxID_ANY, "Enter Your User Name ", wxPoint(290, 90), wxSize(200, -1));
	statictext->SetBackgroundColour(*wxLIGHT_GREY);


	wxStaticText* statictext1 = new wxStaticText(panel, wxID_ANY, " - Email ", wxPoint(348, 150));
	wxTextCtrl* textctrl1 = new wxTextCtrl(panel, wxID_ANY, "Enter Your Email", wxPoint(290, 190), wxSize(200, -1));
	statictext1->SetBackgroundColour(*wxLIGHT_GREY);


	wxStaticText* statictext2 = new wxStaticText(panel, wxID_ANY, " - Password ", wxPoint(348, 250));
	wxTextCtrl* textctrl2 = new wxTextCtrl(panel, wxID_ANY, "Enter Your Password", wxPoint(290, 290), wxSize(200, -1));
	statictext2->SetBackgroundColour(*wxLIGHT_GREY);



	wxStaticText* statictext3 = new wxStaticText(panel, wxID_ANY, " - Choose ", wxPoint(348, 350));
	wxArrayString choices;
	choices.Add("Employee");
	choices.Add("Manager");
	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(290, 390), wxSize(200, -1), choices);
	choice->Select(1);
	statictext3->SetBackgroundColour(*wxLIGHT_GREY);
	
	
}





