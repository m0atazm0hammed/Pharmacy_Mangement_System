#include "SearchMedicine.h"
#include <wx/wx.h>
#include "MainFrame.h"
#include "Product.h"
SearchMedicine::SearchMedicine(const wxString &title) : wxFrame(nullptr, wxID_ANY, "Pharmacy Management System - Search Medicine"), boldFont(wxFontInfo(12).Bold())
{
	wxPanel *panel = new wxPanel(this);

	statictext = new wxStaticText(panel, wxID_ANY, "Search by Name : ", wxPoint(343, 150));
	statictext->SetFont(boldFont);

	textctrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 190), wxSize(200, -1));
	searchByName = new wxButton(panel, wxID_ANY, "Search", wxPoint(350, 220), wxSize(100, 30));
	searchByName->SetFont(boldFont);
	statictext1 = new wxStaticText(panel, wxID_ANY, "Search by ID : ", wxPoint(343, 250));
	statictext1->SetFont(boldFont);

	textctrl1 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 290), wxSize(200, -1));
	searchById = new wxButton(panel, wxID_ANY, "Search", wxPoint(350, 320), wxSize(100, 30));
	searchById->SetFont(boldFont);

	searchById->Bind(wxEVT_BUTTON, &SearchMedicine::OnSearchById, this);
	searchByName->Bind(wxEVT_BUTTON, &SearchMedicine::OnSearchByName, this);

	wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
	sizer->AddStretchSpacer();
	sizer->Add(statictext, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(textctrl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(searchByName, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->AddStretchSpacer();
	sizer->Add(statictext1, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(textctrl1, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->Add(searchById, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
	sizer->AddStretchSpacer();
	panel->SetSizer(sizer);

	Centre();
}

void SearchMedicine::OnSearchById(wxCommandEvent &event)
{
	wxString wxId = textctrl1->GetValue();
	int id = wxAtoi(wxId);
	Product product;
	int offset = product.ReturnPosition(id);
	if (offset == -1)
	{
		wxMessageBox("Medicine not found", "Error", wxOK | wxICON_ERROR);
	}
	else
	{
		product.LogicalFile.open(product.file_name, ios::in | ios::binary);
		product.LogicalFile.seekg(offset);
		product.Read();
		wxString msg = "ID: " + wxString::Format(wxT("%i"), product.id) + "\nName: " + wxString::FromUTF8(product.name) + "\nPrice: " + wxString::Format(wxT("%i"), product.price) + "\nStock: " + wxString::Format(wxT("%i"), product.stock) + "\nSize: " + wxString::Format(wxT("%i"), product.size) + "\nExpiry Date: " + wxString::FromUTF8(product.exp_date);
		wxMessageBox("Medicine found", "Success", wxOK | wxICON_INFORMATION);
		product.LogicalFile.close();
	}
}

void SearchMedicine::OnSearchByName(wxCommandEvent &event)
{
	wxString wxName = textctrl->GetValue();
	std::string name = wxName.ToStdString();
	Product product;
	set<int> offset = product.ReturnPosition((char *)name.c_str());
	if (offset.empty())
	{
		wxMessageBox("Medicine not found", "Error", wxOK | wxICON_ERROR);
	}
	else
	{
		product.LogicalFile.open(product.file_name, ios::in | ios::binary);
		int cnt = 0;
		for (auto i = offset.begin(); i != offset.end() && cnt < 5; i++, cnt++)
		{
			product.LogicalFile.seekg(product.ReturnPosition(*i));
			product.Read();
			wxString msg = "Medicine found\nID: " + wxString::Format(wxT("%i"), product.id) + "\nName: " + wxString::FromUTF8(product.name) + "\nPrice: " + wxString::Format(wxT("%i"), product.price) + "\nStock: " + wxString::Format(wxT("%i"), product.stock) + "\nSize: " + wxString::Format(wxT("%i"), product.size) + "\nExpiry Date: " + wxString::FromUTF8(product.exp_date);
			wxMessageBox(msg, "Success", wxOK | wxICON_INFORMATION);
		}
		product.LogicalFile.close();
	}
}