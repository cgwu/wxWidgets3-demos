/***************************************************************
 * Name:      HelloWxMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2018-09-21
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef HELLOWXMAIN_H
#define HELLOWXMAIN_H

//(*Headers(HelloWxDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/tglbtn.h>
//*)

class HelloWxDialog: public wxDialog
{
    public:

        HelloWxDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~HelloWxDialog();

    private:

        //(*Handlers(HelloWxDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(HelloWxDialog)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON1;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_TOGGLEBUTTON1;
        static const long ID_TEXTCTRL1;
        //*)

        //(*Declarations(HelloWxDialog)
        wxBoxSizer* BoxSizer1;
        wxBoxSizer* BoxSizer2;
        wxButton* Button1;
        wxButton* Button2;
        wxStaticLine* StaticLine1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxToggleButton* ToggleButton1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // HELLOWXMAIN_H
