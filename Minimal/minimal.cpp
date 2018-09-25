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
    void OnSize(wxSizeEvent& event);
    void OnButtonOK(wxCommandEvent& event);

private:
    //DECLARE_EVENT_TABLE()
};

// 有了这一行就可以使用 MyApp& wxGetApp() 了.
DECLARE_APP(MyApp)

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(_T("Minimal wxWidgets App中国"));    // _T <==> wxT
    frame->SetExtraStyle(wxNO_BORDER);
    //动态事件映射
    frame->Connect(wxID_EXIT,
                  wxEVT_COMMAND_MENU_SELECTED,
                  wxCommandEventHandler(MyFrame::OnQuit));

    frame->Connect(wxID_ABOUT,
                  wxEVT_COMMAND_MENU_SELECTED,
                  wxCommandEventHandler(MyFrame::OnAbout));


/*
    // 取消用Disconnect
    frame->Disconnect(wxID_ABOUT,
                  wxEVT_COMMAND_MENU_SELECTED,
                  wxCommandEventHandler(MyFrame::OnAbout));
*/

    //wxLogMessage(_T("wxLogMessage: 这是输出信息!"));
    wxLogDebug(_T("wxLogMessage: 这是输出信息! Great! %d,%f"),520,3.141592f);
    //wxLogTrace(_T("foo"), _T("wxLogMessage: 这是输出信息! Great!"));

    frame->Show(true);
    return true;
}

// 事件表
/*
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    EVT_MENU(wxID_EXIT, MyFrame::OnQuit)
    EVT_SIZE(MyFrame::OnSize)
    EVT_BUTTON(wxID_OK, MyFrame::OnButtonOK)
END_EVENT_TABLE()
*/

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
void MyFrame::OnButtonOK(wxCommandEvent& event)
{
    wxMessageBox(_T("按钮ButtonOK clicked."), wxT("OnButtonOK"),
                 wxOK | wxICON_INFORMATION, this);
}
void MyFrame::OnSize(wxSizeEvent& e)
{
    wxBell();   //发出bell声音wxLogDebug(_T("wxLogMessage: 这是输出信息! Great!"));
    e.Skip();   //调用事件的Skip方法，而不是显示直接调用父类对应函数，来实现对特殊事件的过滤。
}


#include "qiang.xpm"

MyFrame::MyFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title)
{
    SetIcon(wxIcon(qiang_xpm));
    wxMenu* fileMenu = new wxMenu;
    fileMenu->Append(wxID_EXIT, wxT("E&xit退出\tAlt-X"),
                     wxT("Quit this program"));

    wxMenu* helpMenu = new wxMenu;
    helpMenu->Append(wxID_ABOUT, wxT("&About...\tF1"),
                     wxT("Show about dialog"));


    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(fileMenu, wxT("&File"));
    menuBar->Append(helpMenu,wxT("&Help"));

    wxButton* button =  new wxButton(this,wxID_OK, _T("OK"), wxPoint(200,200));

    SetMenuBar(menuBar);
    CreateStatusBar(3);
    SetStatusText(_T("欢迎来到wxWidgets! Welcome to wxWidgets!"));

    //wxPuts(_T("打印的信息A wxWidgets console application"));   // 不起作用



}
