#include "SearchEmployee.h"
#include <wx/wx.h>
#include "MainFrame.h"
#include "Employee.h"
#include "MyApp.h"


wxBEGIN_EVENT_TABLE(SearchEmployee, wxFrame)
    EVT_CLOSE(MyApp::OnClose)
wxEND_EVENT_TABLE()

SearchEmployee::SearchEmployee(const wxString& title) : wxFrame(nullptr, wxID_ANY, "Pharmacy Management System - Search Employee"), boldFont(wxFontInfo(12).Bold())
{
	SetIcon(wxIcon(wxT("icon.ico"), wxBITMAP_TYPE_ICO));

	panel = new wxPanel(this);

	NameLabel = new wxStaticText(panel, wxID_ANY, "Search by Name : ", wxPoint(343, 150));
	NameLabel->SetFont(boldFont);

	NameCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 190), wxSize(200, -1));
	searchByName = new wxButton(panel, wxID_ANY, "Search", wxPoint(350, 220), wxSize(100, 30));
	searchByName->SetFont(boldFont);
	IdLabel = new wxStaticText(panel, wxID_ANY, "Search by ID : ", wxPoint(343, 250));
	IdLabel->SetFont(boldFont);

	IdCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 290), wxSize(200, -1));
	searchById = new wxButton(panel, wxID_ANY, "Search", wxPoint(350, 320), wxSize(100, 30));
	searchById->SetFont(boldFont);

	searchById->Bind(wxEVT_BUTTON, &SearchEmployee::OnSearchById, this);
	searchByName->Bind(wxEVT_BUTTON, &SearchEmployee::OnSearchByName, this);
	wxButton* backButton = new wxButton(panel, wxID_ANY, wxT("Back"), wxPoint(10, 10), wxSize(150, 30));
	backButton->Bind(wxEVT_BUTTON, &SearchEmployee::OnBack, this);
	sizer = new wxBoxSizer(wxVERTICAL);
	sizer->AddStretchSpacer();
	sizer->Add(NameLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(NameCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(searchByName, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->AddStretchSpacer();
	sizer->Add(IdLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(IdCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(searchById, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->AddStretchSpacer();
	panel->SetSizer(sizer);

	Centre();
}

void SearchEmployee::OnSearchById(wxCommandEvent& event)
{
	wxString wxId = IdCtrl->GetValue();
	int id = wxAtoi(wxId);
	Employee employee;
	int offset = employee.ReturnPosition(id);
	if (offset == -1)
	{
		wxMessageBox("Employee not found", "Error", wxOK | wxICON_ERROR);
	}
	else
	{
		employee.LogicalFile.open(employee.file_name, ios::in | ios::binary);
		employee.LogicalFile.seekg(offset);
		employee.Read();
		wxString msg = "ID: " + wxString::Format(wxT("%i"), employee.id) + 
			"\nName: " + wxString::FromUTF8(employee.name) +
			"\nPhone Num: " + wxString::FromUTF8(employee.phone_num) +
			"\nSalary: " + wxString::Format(wxT("%i"), employee.salary) +
			"\nShift: " + wxString::FromUTF8(employee.shift);
 		wxMessageBox("Employee found!!!\n" + msg, "Success", wxOK | wxICON_INFORMATION);
		employee.LogicalFile.close();
	}
}

void SearchEmployee::OnSearchByName(wxCommandEvent& event)
{
	wxString wxName = NameCtrl->GetValue();
	std::string name = wxName.ToStdString();
	Employee employee;
	set<int> offset = employee.ReturnPosition((char*)name.c_str());
	if (offset.empty())
	{
		wxMessageBox("Employee not found", "Error", wxOK | wxICON_ERROR);
	}
	else
	{
		std::vector<int> offsets(offset.begin(), offset.end());
		std::vector<wxStaticText*> labels;
		std::vector<wxButton*> buttons;
		employee.LogicalFile.open(employee.file_name, ios::in | ios::out | ios::binary);
		IdCtrl->Show(false);
		NameCtrl->Show(false);
		IdLabel->Show(false);
		NameLabel->Show(false);
		searchById->Show(false);
		searchByName->Show(false);
		sizer->SetOrientation(wxHORIZONTAL);
		sizer->Clear();
		sizer->AddStretchSpacer();
		this->SetClientSize(1280, 720);
		for (int i = 0; i < min(5, (int)offsets.size()); i++)
		{
			wxBoxSizer* tmp = new wxBoxSizer(wxVERTICAL);
			employee.LogicalFile.seekg(employee.ReturnPosition(offsets[i]));
			employee.Read();
			wxString msg = 
				"ID: " + wxString::Format(wxT("%i"), employee.id) +
				"\nName: " + wxString::FromUTF8(employee.name) +
				"\nPhone Num: " + wxString::FromUTF8(employee.phone_num) +
				"\nSalary: " + wxString::Format(wxT("%i"), employee.salary) +
				"\nShift: " + wxString::FromUTF8(employee.shift);
			labels.push_back(new wxStaticText(panel, wxID_ANY, msg));
			labels[i]->SetFont(boldFont);
			tmp->Add(labels[i], 0, wxALIGN_CENTER_VERTICAL | wxALL, 10);
			sizer->Add(tmp, 0, wxALIGN_CENTER_VERTICAL | wxALL, 10);
		}
		sizer->AddStretchSpacer();
		panel->Layout();
	}
}


void SearchEmployee::OnBack(wxCommandEvent& event)
{
	auto frame = MyApp::frames.top();
	frame->Show(true);
	MyApp::frames.pop();
	MyApp::BackPress = true;
	Close(true);
}