#include <wx/wx.h>
class AddEmployeeFrame : public wxFrame {
public:
    AddEmployeeFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    wxTextCtrl* nameTextCtrl;
    wxTextCtrl* phoneTextCtrl;
    wxTextCtrl* salaryTextCtrl;
    wxTextCtrl* shiftTextCtrl;
};

