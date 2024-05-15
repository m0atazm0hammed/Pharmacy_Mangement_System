#include "Manager.h"
#include<wx/wx.h>
#include "MainFrame.h"
Manager::Manager(const wxString& title) :wxFrame(nullptr, wxID_ANY, "Pharmacy Management System - Manager",
	wxPoint(30, 30), wxSize(1280, 720))
{
	SetFont(GetFont().Scale(1.5));
	wxPanel* panel = new wxPanel(this);
	
	wxArrayString choices;
	choices.Add("Product");
	choices.Add("Employee");
	choices.Add("Customer");
	wxStaticText* statictext = new wxStaticText(panel, wxID_ANY, " Update : ", wxPoint(370,60 ));

	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(200, 100), wxSize(400, -1), choices);

	wxArrayString choices1;
	wxStaticText* statictext1 = new wxStaticText(panel, wxID_ANY, " Add : ", wxPoint(370, 200));

	wxChoice* choice1 = new wxChoice(panel, wxID_ANY, wxPoint(200, 240), wxSize(400, -1), choices);
	choices1.Add("Product");
	choices1.Add("Employee");
	choices1.Add("Customer");

	wxStaticText* statictext2 = new wxStaticText(panel, wxID_ANY, " Delete : ", wxPoint(370, 350));
	wxButton* button = new wxButton(panel, wxID_ANY, "Employee", wxPoint(200, 390), wxSize(400, -1));


	
}
