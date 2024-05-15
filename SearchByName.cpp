#include "SearchByName.h"
SearchByName::SearchByName(const wxString& title, const wxPoint& pos, const wxSize& size)
    :wxFrame(NULL, wxID_ANY, title, pos, size) {
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Create input text box
    nameTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxT("Name"));

    // Create output text box (read-only)
    outputTextCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY | wxTE_MULTILINE);

    // Create a vertical box sizer to hold the controls
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    // Add controls to the sizer with some padding
    sizer->Add(nameTextCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(outputTextCtrl, 1, wxEXPAND | wxALL, 5);

    // Set the sizer for the panel
    panel->SetSizer(sizer);

    // Center the panel in the frame
    Centre();
}

//// SEARCH FUNCTION<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<>>>>>>>>>>>>>

void SearchByName::OnTextChanged(wxCommandEvent& event) {
    // Get the input name from the text box
    wxString name = nameTextCtrl->GetValue();
    // Process the input name
    std::set<char> result;
    //// result = SEARCHFUNCTION<<>><<>><<>>(name);
    // Clear the output text box
    outputTextCtrl->Clear();

    // Display the result in the output text box
    for (char character : result) {
        outputTextCtrl->AppendText(wxString::Format("%c\n", character));
    }
}
