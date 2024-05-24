#include "DeleteMedicine.h"
#include <wx/wx.h>
#include "MainFrame.h"
#include "MyApp.h"
#include "Product.h"
DeleteMedicine::DeleteMedicine(const wxString &title) : wxFrame(nullptr, wxID_ANY, "Pharmacy Management System - Delete Medicine", wxDefaultPosition, wxSize(1280, 720)), boldFont(wxFontInfo(12).Bold())
{
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
    backButton->Bind(wxEVT_BUTTON, &DeleteMedicine::OnBack, this);
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

	IdDelete->Bind(wxEVT_BUTTON, &DeleteMedicine::OnDeleteByID, this);
	NameDelete->Bind(wxEVT_BUTTON, &DeleteMedicine::OnDeleteByName, this);
	Centre();
}

void DeleteMedicine::OnDeleteByID(wxCommandEvent &event)
{
    wxString wxId = IdTextCtrl->GetValue();
    int id = std::stoi(wxId.ToStdString());

	Product product;
	int tmp = product.Delete(id);
	if (tmp)
		wxMessageBox("Medicine deleted", "Success", wxOK | wxICON_INFORMATION);
	else
		wxMessageBox("Medicine not found");
}

void DeleteMedicine::OnDeleteByName(wxCommandEvent &event)
{
	wxString wxName = NameTextCtrl->GetValue();
	std::string name = wxName.ToStdString();
	Product product;
	set<int> offset = product.ReturnPosition((char *)name.c_str());
	if (offset.empty())
	{
		wxMessageBox("Medicine not found");
	}
	else
	{
		std::vector<int> offsets(offset.begin(), offset.end());
		std::vector<wxStaticText *> labels;
		std::vector<wxButton *> buttons;
		product.LogicalFile.open(product.file_name, ios::in | ios::out | ios::binary);
		IdTextCtrl->Show(false);
		NameTextCtrl->Show(false);
		IdLabel->Show(false);
		NameLabel->Show(false);
		IdDelete->Show(false);
		NameDelete->Show(false);
		sizer->SetOrientation(wxHORIZONTAL);
		sizer->Clear();
		sizer->AddStretchSpacer();
		for (int i = 0; i < min(5, (int) offsets.size()); i++)
		{
			wxBoxSizer* tmp = new wxBoxSizer(wxVERTICAL);
			product.LogicalFile.seekg(product.ReturnPosition(offsets[i]));
			product.Read();
			wxString msg = "ID: " + wxString::Format(wxT("%i"), product.id) + "\nName: " + wxString::FromUTF8(product.name) + "\nPrice: " + wxString::Format(wxT("%i"), product.price) + "\nStock: " + wxString::Format(wxT("%i"), product.stock) + "\nSize: " + wxString::Format(wxT("%i"), product.size) + "\nExpiry Date: " + wxString::FromUTF8(product.exp_date);	
			labels.push_back(new wxStaticText(panel, wxID_ANY, msg));
			labels[i]->SetFont(boldFont);
			tmp->Add(labels[i], 0, wxALIGN_CENTER_VERTICAL | wxALL, 10);

			buttons.push_back(new wxButton(panel, wxID_ANY, wxString("Delete"), wxDefaultPosition, wxSize(200, 35)));
			buttons[i]->SetFont(boldFont);
			tmp ->Add(buttons[i], 0, wxALIGN_CENTER_VERTICAL | wxALL, 10);
			id = product.id;
			buttons[i]->Bind(wxEVT_BUTTON, &DeleteMedicine::OnDeleteMedicineID, this);
			sizer->Add(tmp, 0, wxALIGN_CENTER_VERTICAL | wxALL, 10);
		}
		sizer->AddStretchSpacer();
		panel->Layout();
	}
	id = -1;
}


void DeleteMedicine::OnBack(wxCommandEvent& event)
{
    auto frame = MyApp::frames.top();
    frame->Show(true);
    MyApp::frames.pop();
    Close(true);
}

void DeleteMedicine::OnDeleteMedicineID(wxCommandEvent& event)
{
	Product product;
	int tmp = product.Delete(id);
	if (tmp)
		wxMessageBox("Medicine deleted", "Success", wxOK | wxICON_INFORMATION);
	else
		wxMessageBox("Medicine not found");
	id = -1;
}