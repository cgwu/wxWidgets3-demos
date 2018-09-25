/***************************************************************
 * Name:      HelloWxApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2018-09-21
 * Copyright:  ()
 * License:
 **************************************************************/

#include "HelloWxApp.h"

//(*AppHeaders
#include "HelloWxMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(HelloWxApp);

bool HelloWxApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	HelloWxDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
