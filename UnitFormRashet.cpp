//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormRashet.h"
#include "Chart.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormRashet *FormRashet;
//extern AnsiString NameFileRashetTxt;                // Переменная определена в файле UnitMain_Chart.cpp, необходимо определить ее в глобальном файле #include как extern package
//---------------------------------------------------------------------------
__fastcall TFormRashet::TFormRashet(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormRashet::BitBtn5Click(TObject *Sender)   //  Сохранить как
{
AnsiString  NameFileRashet;
  if(SaveDialogFileRashet->Execute())
  {
  Memo1->Lines->SaveToFile(SaveDialogFileRashet->FileName);
  strcpy(PtrGlobalFlagChart->NameFileRashetTxt,SaveDialogFileRashet->FileName.c_str());
  }

}
//---------------------------------------------------------------------------
void __fastcall TFormRashet::BitBtn4Click(TObject *Sender)    //  Сохранить
{
  Memo1->Lines->SaveToFile(PtrGlobalFlagChart->NameFileRashetTxt);

}
//---------------------------------------------------------------------------

void __fastcall TFormRashet::FormCreate(TObject *Sender)
{
Memo1->Clear();
Memo1->Visible = true;
}
//---------------------------------------------------------------------------

