#include <wx/wx.h>
class LoginChoiceFrame : public wxFrame {
public:
    LoginChoiceFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void OnManagerButton(wxCommandEvent& event);
};