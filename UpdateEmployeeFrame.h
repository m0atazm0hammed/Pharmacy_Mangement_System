#include <wx/wx.h>
class UpdateEmployeeFrame : public wxFrame {
public:
    UpdateEmployeeFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    void OnUpdate(wxCommandEvent& event);
	void OnBack(wxCommandEvent& event);
private:
    wxTextCtrl* phoneTextCtrl;
    wxTextCtrl* salaryTextCtrl;
    wxTextCtrl* shiftTextCtrl;
    wxTextCtrl* IdTextCtrl;
};

