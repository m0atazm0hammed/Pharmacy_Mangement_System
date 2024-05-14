#pragma once
#include<wx/wx.h>


enum
{
	BUTTON_Hello = wxID_HIGHEST + 1 // declares an id which will be used to call our button
};
class Home : public wxFrame
{
public:
	Home(const wxString& title);
	
	
};

