//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Main.cpp", Form1);
USEFORM("UnitSettings.cpp", FormSettings);
USEFORM("UnitAbout.cpp", FormAbout);
USEFORM("UnitFormRashet.cpp", FormRashet);
USEFORM("startLog.cpp", startLogForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TForm1), &Form1);
     Application->CreateForm(__classid(TFormSettings), &FormSettings);
     Application->CreateForm(__classid(TFormRashet), &FormRashet);
     Application->CreateForm(__classid(TFormAbout), &FormAbout);
     Application->CreateForm(__classid(TstartLogForm), &startLogForm);
     Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
