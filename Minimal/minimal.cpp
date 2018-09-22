#include "wx/wx.h"

class MyApp: public wxApp
{
public:
    virtual bool OnInit();  //启动时被调用
};

class MyFrame: public wxFrame
{
public:
    MyFrame(const wxString& title);

    // events
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

private:
    DECLARE_EVENT_TABLE()
};

// 有了这一行就可以使用 MyApp& wxGetApp() 了.
DECLARE_APP(MyApp)

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(_T("Minimal wxWidgets App中国"));    // _T <==> wxT
    frame->Show(true);
    return true;
}

// 事件表
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    EVT_MENU(wxID_EXIT, MyFrame::OnQuit)
END_EVENT_TABLE()

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg;
    msg.Printf(wxT("喂,关于程序Hello and welcome to %s"), wxVERSION_STRING);
    wxMessageBox(msg, wxT("Abount Minimal"),
                 wxOK | wxICON_INFORMATION, this);
}

void MyFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

#include "qiang.xpm"

MyFrame::MyFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title)
{
    SetIcon(wxIcon(qiang_xpm));
    wxMenu* fileMenu = new wxMenu;
    fileMenu->Append(wxID_EXIT, wxT("E&xit\tAlt-X"),
                     wxT("Quit this program"));

    wxMenu* helpMenu = new wxMenu;
    helpMenu->Append(wxID_ABOUT, wxT("&About...\tF1"),
                     wxT("Show about dialog"));


    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(fileMenu, wxT("&File"));
    menuBar->Append(helpMenu,wxT("&Help"));

    SetMenuBar(menuBar);
    CreateStatusBar(3);
    SetStatusText(_T("欢迎来到wxWidgets! Welcome to wxWidgets!"));
}
