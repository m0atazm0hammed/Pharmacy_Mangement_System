#include <wx/wx.h>
#include <string>
#include <set>

class SearchByName : public wxFrame {
public:
    SearchByName(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    wxTextCtrl* nameTextCtrl;
    wxTextCtrl* outputTextCtrl;

    // Function to process the name
///   SEARCHFUNCTION   std::set<char> processName(const wxString& name);
    // Event handler for the text box
    void OnTextChanged(wxCommandEvent& event);
};
