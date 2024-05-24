#include "DeleteEmployee.h"
#include <wx/wx.h>
#include "MainFrame.h"
#include "MyApp.h"
#include "Employee.h"


wxBEGIN_EVENT_TABLE(DeleteEmployee, wxFrame)
    EVT_CLOSE(MyApp::OnClose)
wxEND_EVENT_TABLE()

DeleteEmployee::DeleteEmployee(const wxString& title) : wxFrame(nullptr, wxID_ANY, "Pharmacy Management System - Delete Employee", wxDefaultPosition, wxSize(1280, 720)), boldFont(wxFontInfo(12).Bold())
{
	SetIcon(wxIcon(wxT("icon.ico"), wxBITMAP_TYPE_ICO));

	id = -1;
	panel = new wxPanel(this, wxID_ANY);
	IdLabel = new wxStaticText(panel, wxID_ANY, wxT("Id:"));
	IdLabel->SetFont(boldFont);

	NameLabel = new wxStaticText(panel, wxID_ANY, wxT("Name:"));
	NameLabel->SetFont(boldFont);

	IdTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, -1));   // Larger size
	NameTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, -1)); // Larger size

	IdDelete = new wxButton(panel, wxID_ANY, wxT("Delete by ID"), wxDefaultPosition, wxSize(200, 35)); // Larger size
	IdDelete->SetFont(boldFont);

	NameDelete = new wxButton(panel, wxID_ANY, wxT("Delete by Name"), wxDefaultPosition, wxSize(200, 35)); // Larger size
	NameDelete->SetFont(boldFont);
	wxButton* backButton = new wxButton(panel, wxID_ANY, wxT("Back"), wxPoint(10, 10), wxSize(150, 30));
	backButton->Bind(wxEVT_BUTTON, &DeleteEmployee::OnBack, this);
	sizer = new wxBoxSizer(wxVERTICAL);
	sizer->AddStretchSpacer();
	sizer->Add(IdLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(IdTextCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(IdDelete, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->AddStretchSpacer();
	sizer->Add(NameLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(NameTextCtrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(NameDelete, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->AddStretchSpacer();
	panel->SetSizer(sizer);

	IdDelete->Bind(wxEVT_BUTTON, &DeleteEmployee::OnDeleteByID, this);
	NameDelete->Bind(wxEVT_BUTTON, &DeleteEmployee::OnDeleteByName, this);
	Centre();
}

void DeleteEmployee::OnDeleteByID(wxCommandEvent& event)
{
	wxString wxId = IdTextCtrl->GetValue();
	int ID = std::stoi(wxId.ToStdString());

	Employee employee;
	int tmp = employee.Delete(ID);
	if (tmp)
		wxMessageBox("Employee deleted", "Success", wxOK | wxICON_INFORMATION);
	else
		wxMessageBox("Employee not found");
}

void DeleteEmployee::OnDeleteByName(wxCommandEvent& event)
{
	wxString wxName = NameTextCtrl->GetValue();
	std::string name = wxName.ToStdString();
	Employee employee;
	set<int> offset = employee.ReturnPosition((char*)name.c_str());
	if (offset.empty())
	{
		wxMessageBox("Employee not found");
	}
	else
	{
		
		employee.LogicalFile.open(employee.file_name, ios::in | ios::out | ios::binary);
		IdTextCtrl->Show(false);
		NameTextCtrl->Show(false);
		IdLabel->Show(false);
		NameLabel->Show(false);
		IdDelete->Show(false);
		NameDelete->Show(false);
		sizer->SetOrientation(wxHORIZONTAL);
		sizer->Clear();
		sizer->AddStretchSpacer();

		offsets.assign(offset.begin(), offset.end());
		labels.clear();
		buttons.clear();

		for (int i = 0; i < min(5, (int)offsets.size()); i++)
		{
			wxBoxSizer* tmp = new wxBoxSizer(wxVERTICAL);
			employee.LogicalFile.seekg(employee.ReturnPosition(offsets[i]));
			employee.Read();
			wxString msg = "ID: " + wxString::Format(wxT("%i"), employee.id) +
				"\nName: " + wxString::FromUTF8(employee.name) +
				"\nPhone Num: " + wxString::FromUTF8(employee.phone_num) +
				"\nSalary: " + wxString::Format(wxT("%i"), employee.salary) +
				"\nShift: " + wxString::FromUTF8(employee.shift);
			labels.push_back(new wxStaticText(panel, employee.id, msg));
			labels[i]->SetFont(boldFont);
			tmp->Add(labels[i], 0, wxALIGN_CENTER_VERTICAL | wxALL, 10);

			buttons.push_back(new wxButton(panel, i, wxString("Delete"), wxDefaultPosition, wxSize(200, 35)));
			buttons[i]->SetFont(boldFont);
			tmp->Add(buttons[i], 0, wxALIGN_CENTER_VERTICAL | wxALL, 10);
			buttons[i]->Bind(wxEVT_BUTTON, &DeleteEmployee::OnDeleteEmployeeID, this);
			sizer->Add(tmp, 0, wxALIGN_CENTER_VERTICAL | wxALL, 10);
		}
		sizer->AddStretchSpacer();
		panel->Layout();
	}
}


void DeleteEmployee::OnBack(wxCommandEvent& event)
{
	auto frame = MyApp::frames.top();
	frame->Show(true);
	MyApp::frames.pop();
	MyApp::BackPress = true;
	Close(true);
}

void DeleteEmployee::OnDeleteEmployeeID(wxCommandEvent& event)
{
	int index = event.GetId();
	id = labels[index]->GetId();
	labels[index]->Destroy();
	buttons[index]->Destroy();
	Employee employee;
	int tmp = employee.Delete(id);
	if (tmp)
		wxMessageBox("Employee deleted", "Success", wxOK | wxICON_INFORMATION);
	else
		wxMessageBox("Employee not found");
	id = -1;
}
