//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "startLog.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TstartLogForm *startLogForm;
//---------------------------------------------------------------------------
__fastcall TstartLogForm::TstartLogForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TstartLogForm::Timer1Timer(TObject *Sender)
{
 Close();        
}
//---------------------------------------------------------------------------

void __fastcall TstartLogForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
 Action = caFree;        
}
//---------------------------------------------------------------------------

