
#pragma hdrstop
#include "myLabel.h"

//---------------------------------------------------------------------------
myLabel* myLabel::currentLabel;
int myLabel::labelId = 0;

#pragma package(smart_init)
__fastcall myLabel::myLabel(Classes::TComponent* AOwner)
        :TLabel(AOwner)
{
 this->Parent = dynamic_cast<TChart*>(AOwner);
 this->Caption = "Текст";
 id = labelId++ ;

 // events assign
 this->OnMouseDown = labelMouseDown;
 this->OnDblClick = labelDblClick;
 this->OnMouseMove = labelMouseMove;
 this->OnMouseUp = labelMouseUp;

 // create PopupMenu
 this->PopupMenu = new TPopupMenu(this);
 menuItem = new TMenuItem(this->PopupMenu);
 menuItem->Caption = "Удалить";
 this->PopupMenu->Items->Add(menuItem);

 // create edit
 edit = new TEdit(this->Parent);  //отвечает ли this->Parent за удаление edit?
 edit->Parent = this->Parent;
 edit->OnKeyDown = editKeyDown;
 edit->Constraints->MinWidth = 50;
 edit->BorderStyle = bsNone;
 edit->Visible = false;

 writeToLog("Create myLabel № " + IntToStr(id));
};


__fastcall myLabel::~myLabel(){
  writeToLog("destroy myLabel № " + IntToStr(id));
};


//---------------------------------------------------------------------------
//        Двойной клик - возможность редактирования надписи
//---------------------------------------------------------------------------
void __fastcall myLabel::labelDblClick(TObject *Sender)
{
 edit->Left = dynamic_cast<TControl*>(Sender)->Left;
 edit->Top = dynamic_cast<TControl*>(Sender)->Top;
 edit->Text = dynamic_cast<TLabel*>(Sender)->Caption;
 dynamic_cast<TLabel*>(Sender)->Visible = false;
 edit->Width = (dynamic_cast<TLabel*>(Sender)->Caption).Length() * 9;
 edit->Visible = true;
 edit->SetFocus();
}


//---------------------------------------------------------------------------
//           Перенос Label  мышкой
//---------------------------------------------------------------------------
void __fastcall myLabel::labelMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 if(Button != mbLeft)
    return;
 X0 = X;
 Y0 = Y;
 mouseDown = true;
}
//---------------------------------------------------------------------------
void __fastcall myLabel::labelMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
 if(mouseDown){
    this->Left += X - X0;
    this->Top += Y - Y0;
 }
}
//---------------------------------------------------------------------------
void __fastcall myLabel::labelMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
 mouseDown = false;
 currentLabel = dynamic_cast<myLabel*>(Sender);
}


//---------------------------------------------------------------------------
//         изменение длины Edit при редактировании
//---------------------------------------------------------------------------
void __fastcall myLabel::editKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift){
  if(Key == 13){
    this->Caption = edit->Text;
    this->Visible = true;
    edit->Visible = false;
  }
  else
    edit->Width = (edit->Text).Length() * 9;
};


//---------------------------------------------------------------------------
//        log
//---------------------------------------------------------------------------
void myLabel::writeToLog(AnsiString& str){
  Log::instance().Write(str.c_str());
};


