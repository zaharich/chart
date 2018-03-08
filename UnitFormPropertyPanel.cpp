//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <math.h>
#include "UnitFormPropertyPanel.h"
#include "UnitFormPropertyGraphyc.h"
#include "dstring.h"
//#include "MainModulMinimax.h"
#include "UnitForrmArgProperty.h"
//#include "GrafClass.h"
//#include "TablClass.h"
#include "SistemStruct.h"
//#include "FileDatInpClass.h"
//#include "FormatClass.h"
//#include "FileMinimaxGlobalValue.h"
#include "UnitFormParamProperty.h"
#include "UnitFormTxt.h"
#include "UnitFormMessage.h"
#include "FileSort.h"
//#include "FileClassBaza.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma link "PERFGRAP"
#pragma resource "*.dfm"
TFormPropertyPanel *FormPropertyPanel;
//extern FormatClass *PtrFormatClass;
//---------------------------------------------------------------------------
__fastcall TFormPropertyPanel::TFormPropertyPanel(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormPropertyPanel::FormCreate(TObject *Sender)
{
FormPropertyPanel->Width=Screen->Width*0.8;
FormPropertyPanel->Height=(Screen->Height/4)*3;
FormPropertyPanel->Top=Screen->Height-FormPropertyPanel->Height-50;
FormPropertyPanel->Left=Screen->Width*0.2;
FlagChangeTabString=0;
//CheckBox1->Checked=true; CheckBox2->Checked=true; CheckBox3->Checked=true;

}
//---------------------------------------------------------------------------
void __fastcall TFormPropertyPanel::FormClose(TObject *Sender,
      TCloseAction &Action)
{
TablSaveNewNastr();
FormTxtProp->Close();
//FormatPtr=PtrFormatClass->AdresFormatNumberTek;
}
//---------------------------------------------------------------------------

void __fastcall TFormPropertyPanel::SpeedButton5Click(TObject *Sender)
{
//  Кнопка " Свойства " Графики
struct Format *FormatPtr;
struct ScalArg   *ScalArgPtr;
FormatPtr=PtrFormatClass->AdresFormatNumberTek;
if(StringGrid2->Row==0) return;
 if(PageControl1->ActivePage==TabSheet3)
 {
   if(FormatPtr->AdresStructArg->PriznakTime == 0)
   {
   FormArgProperty->Edit6->Visible = false;
   FormArgProperty->Label7->Visible = false;
   }
   else
   {
   FormArgProperty->Edit6->Visible = true;
   FormArgProperty->Label7->Visible = true;
   }
  FormArgProperty->ShowModal();
 }
 else if(PageControl1->ActivePage==TabSheet2) FormPropertyGraphyc->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFormPropertyPanel::SpeedButton2Click(TObject *Sender)
{
struct Format *FormatPtr;
struct Scal *ScalPtr,*ScalPtrTek,*ScalPtrOld;
//struct ScalArg *ScalArgPtr;
//int i,j,NCol,begin_line,color;
int i,j,jj,NCol,color;
//char buf[32],buftek[4];
 NCol=1;
 while(PtrWinSistTab->NPoleNCol[NCol] != 1 ) NCol++;
FormatPtr=PtrFormatClass->AdresFormatNumberTek;
for(j=StringGrid2->Selection.Top; j<=StringGrid2->Selection.Bottom; j++)
{
ScalPtr=FormatPtr->AdresStructScalBegin;
for(i=1; i<j; i++) ScalPtr=ScalPtr->AdresNext;
ScalPtrOld = ScalPtr;
PtrFormatClass->AdresStructScalTek=ScalPtr;
(char *)ScalPtrTek=new char[sizeof(struct Scal)];
for(i=0; i<sizeof(struct Scal); i++) { *((char *)ScalPtrTek+i)='\0'; *((char *)ScalPtrTek+i) = *((char *)ScalPtr+i); }
  i=0;
  while(strcmpi((PtrPasp+i)->Ident,ScalPtrTek->ident) != 0) i++;
  for(jj=0; jj<KSISTEMMAX; jj++)
  {if((PtrPasp+i)->NSis[jj] == FormatPtr->NSis) {ScalPtrTek->NSis = FormatPtr->NSis; break; }}
while(ScalPtr->AdresNext != NULL) ScalPtr=ScalPtr->AdresNext;
ScalPtr->AdresNext=ScalPtrTek;
ScalPtrTek->AdresPred=ScalPtr;
ScalPtrTek->AdresNext=0;
FormatPtr->KParamGraf++;
PtrFormatClass->AdresStructScalTek=ScalPtrTek;
StringGrid2->RowCount=FormatPtr->KParamGraf+1;
StringGrid2->Cells[0][StringGrid2->RowCount-1]=StringGrid2->RowCount-1;
StringGrid2->Cells[1][StringGrid2->RowCount-1]="копия";
StringGrid2->Cells[1][StringGrid2->RowCount-1]=StringGrid2->Cells[1][StringGrid2->RowCount-1] + ScalPtrOld->name;
strcpy(ScalPtrTek->name,StringGrid2->Cells[1][StringGrid2->RowCount-1].c_str());
//StringGrid1->Cells[NCol][j];
}
}
//---------------------------------------------------------------------------
void __fastcall TFormPropertyPanel::SpeedButton1Click(TObject *Sender)
{
  StringGrid2->Row=StringGrid2->Row+1;
  StringGrid2->Col=1;

}
//---------------------------------------------------------------------------
void __fastcall TFormPropertyPanel::SpeedButton3Click(TObject *Sender)
{
//  Кнопка + Графики
struct Format *FormatPtr;
struct Scal *ScalPtr,*ScalPtrTek;
struct ScalArg *ScalArgPtr;
int i,j,jj,NCol,begin_line,color;
//char buf[32],buftek[4];
 NCol=1;
FormatPtr=PtrFormatClass->AdresFormatNumberTek;
begin_line = FormatPtr->LineTek; color = FormatPtr->ColorTek;
for(j=StringGrid1->Selection.Top; j<=StringGrid1->Selection.Bottom; j++)
{
 while(PtrWinSistTab->NPoleNCol[NCol] != 1 ) NCol++;
// if(TabControl1->TabIndex==1)
 if(PageControl1->ActivePage==TabSheet2)
  {
  FormatPtr=PtrFormatClass->AdresFormatNumberTek;
  if(CheckBox11->Checked)
  {
   if( RowDragDrop != 0 )
   {
   ScalPtr=PtrFormatClass->AdresFormatNumberTek->AdresStructScalBegin;
   for(i=1; i<RowDragDrop; i++) ScalPtr=ScalPtr->AdresNext;
   RowDragDrop = 0;
   }
   else  ScalPtr = PtrFormatClass->AdresStructScalTek;
  while(PtrWinSistTab->NPoleNCol[NCol] != 1 ) NCol++;
  strcpy(ScalPtr->ident,StringGrid1->Cells[NCol][RowMouseDown].c_str());
   if(NRazrRK > 0) { ScalPtr->NumberFormat = 'r'; ScalPtr->nr= (unsigned char)NRazrRK; NRazrRK = 0;}
   else                                                                                 // 2008_03_21
   {
   i=0;
   while(strcmpi(ScalPtr->ident,(PtrPasp+i)->Ident) != 0) i++;
   strcpy(ScalPtr->Naimenovanie,(PtrPasp+i)->Name);
   }                                                                       // 2008_03_21
  return;
  }
(char *)ScalPtrTek=new char[sizeof(struct Scal)];
for(i=0; i<sizeof(struct Scal); i++) *((char *)ScalPtrTek+i)='\0';

if(FormatPtr->KParamGraf==NULL)
{
FormatPtr->AdresStructScalBegin=ScalPtrTek;
ScalPtrTek->AdresPred=0; ScalPtrTek->AdresNext=0;
}
else
{
ScalPtr=FormatPtr->AdresStructScalBegin;
 while(ScalPtr->AdresNext != NULL) ScalPtr=ScalPtr->AdresNext;
ScalPtr->AdresNext=ScalPtrTek;
ScalPtrTek->AdresPred=ScalPtr;
ScalPtrTek->AdresNext=0;
}
FormatPtr->KParamGraf++;
PtrFormatClass->AdresStructScalTek=ScalPtrTek;
StringGrid2->RowCount=FormatPtr->KParamGraf+1;
StringGrid2->Cells[0][StringGrid2->RowCount-1]=StringGrid2->RowCount-1;
StringGrid2->Cells[1][StringGrid2->RowCount-1]=StringGrid1->Cells[NCol][j];
strcpy(ScalPtrTek->ident,StringGrid2->Cells[1][StringGrid2->RowCount-1].c_str());
        strcpy(ScalPtrTek->name,ScalPtrTek->ident);
        ScalPtrTek->color = color;
        ScalPtrTek->FlagTablRight = true;
        ScalPtrTek->prizn_grafic = true;
        ScalPtrTek->prizn_scal = true;
        if(RadioButton4->Checked == true) ScalPtrTek->FlagMarker = true;
        else if(RadioButton4->Checked == false) ScalPtrTek->FlagMarker = false;
        ScalPtrTek->begin_value=0;
        ScalPtrTek->k_baz=1;
        ScalPtrTek->begin_line=begin_line;
        ScalPtrTek->step=10;

        ScalPtrTek->nr=0;
        if(NRazrRK > 0) { ScalPtrTek->NumberFormat = 'r'; ScalPtrTek->nr= (unsigned char)NRazrRK; NRazrRK = 0;}
        ScalPtrTek->EditHkala=false;
        i=0;
        while(strcmpi(ScalPtrTek->ident,(PtrPasp+i)->Ident) != 0) i++;
        strcpy(ScalPtrTek->Naimenovanie,(PtrPasp+i)->Name);  // 2007.09.16
//        if((PtrPasp+i)->Tip == 22 || (PtrPasp+i)->Tip == 11)
//        if((PtrPasp+i)->Tip == 22 || (PtrPasp+i)->Tip == 11 && (ListBox1->ItemIndex != -1))  // 2007_12_20
        if(((PtrPasp+i)->Tip == 22 || (PtrPasp+i)->Tip == 11) && (ListBox1->ItemIndex != -1))  // 2008_03_22
        {
         ScalPtrTek->NumberFormat = 'r'; ScalPtrTek->TipGrafRK = 0;
         strcpy(ScalPtrTek->Naimenovanie,ListBox1->Items->Strings[ListBox1->ItemIndex].c_str());  // 2007_09_16
        }
        else
        {
        ScalPtrTek->NumberFormat = 'f';
        strcpy(ScalPtrTek->Format,"%11.2f");
        }
        //        ScalPtr->step=Edit8->Text.ToDouble();
        ScalPtrTek->kznak=2;
        ScalPtrTek->KSimDoPoint=8;
        ScalPtrTek->KSimPoclePoint=ScalPtrTek->kznak;
        ScalPtrTek->WidthLine = 1;
        ScalPtrTek->TipLine = false;
//        if(ScalPtrTek->NSis != 0) ScalPtrTek->NSis = FormatPtr->NSis-1;
//        if(ScalPtrTek->NSis != 0) ScalPtrTek->NSis = FormatPtr->NSis;
        ScalPtrTek->NSis = 1;
  i=0;
  while(strcmpi((PtrPasp+i)->Ident,ScalPtrTek->ident) != 0) i++;
  for(jj=0; jj<KSISTEMMAX; jj++)
  {if((PtrPasp+i)->NSis[jj] == FormatPtr->NSis) {ScalPtrTek->NSis = FormatPtr->NSis; break; }}

 ScalPtrTek->FontScal.Color = ScalPtrTek->color;
 ScalPtrTek->FontScal.Charset = FontDialogGraf->Font->Charset;
 ScalPtrTek->FontScal.Height = FontDialogGraf->Font->Height;
 ScalPtrTek->FontScal.Size = FontDialogGraf->Font->Size;
 ScalPtrTek->FontScal.Style = FontDialogGraf->Font->Style;
 strcpy(ScalPtrTek->FontScal.Name,FontDialogGraf->Font->Name.c_str());

 ScalPtrTek->Marker.Color = ScalPtrTek->color;
 ScalPtrTek->Marker.Charset = FormPropertyGraphyc->FontDialog1->Font->Charset;
 ScalPtrTek->Marker.Height = FormPropertyGraphyc->FontDialog1->Font->Height;
 ScalPtrTek->Marker.Size = FormPropertyGraphyc->FontDialog1->Font->Size;
 ScalPtrTek->Marker.Style = FormPropertyGraphyc->FontDialog1->Font->Style;
 strcpy(ScalPtrTek->Marker.Name,FormPropertyGraphyc->FontDialog1->Font->Name.c_str());
 ScalPtrTek->NumberMarker = NumberMarker; NumberMarker++;
 ScalPtrTek->KMarker = 5; ScalPtrTek->OffsetMarker = 10;
 strcpy(ScalPtrTek->MarkerName,FormPropertyGraphyc->ComboBox3->Items->Strings[ScalPtrTek->NumberMarker].c_str());
}
 begin_line = begin_line + 2;
 if(begin_line >= FormatPtr->KPolocGoriz) begin_line = 0;
 color = color << 8;
// if(color >= 0x0ff00000)
 if(color == 0)  color =0x000000ff;
}
FormatPtr->LineTek = begin_line; FormatPtr->ColorTek = color;

// if(PageControl2->ActivePage->Name=="TabSheet4")
// if(TabControl1->TabIndex==0)
 if(PageControl1->ActivePage==TabSheet3)
  {
     FormatPtr=PtrFormatClass->AdresFormatNumberTek;
     if(FormatPtr->AdresStructArg==0)
     {
     (char *)ScalArgPtr=new char[sizeof(struct ScalArg)];
     for(i=0; i<sizeof(struct ScalArg); i++) *((char *)ScalArgPtr+i)='\0';
     FormatPtr->AdresStructArg=ScalArgPtr;
     }
     else ScalArgPtr=FormatPtr->AdresStructArg;
     StringGrid6->RowCount=2; // StringGrid2->Row=1;
     StringGrid6->Cells[0][1]=1;
StringGrid6->Cells[1][1]=StringGrid5->Cells[NCol][StringGrid5->Row];
strcpy(ScalArgPtr->ident,StringGrid5->Cells[NCol][StringGrid5->Row].c_str());
        strcpy(ScalArgPtr->name,ScalArgPtr->ident);
        ScalArgPtr->step=10;
        ScalArgPtr->step_ocif=4;
        ScalArgPtr->KSimPoclePoint=3;
        i=0;
        while(strcmpi(ScalArgPtr->ident,(PtrPasp+i)->Ident) != 0) i++;
        if((PtrPasp+i)->Tip != 30 )  { ScalArgPtr->PriznakTime = 1; ScalArgPtr->kbaz = 10; ScalArgPtr->X0 = 0;}
     }

}
//---------------------------------------------------------------------------
void __fastcall TFormPropertyPanel::SpeedButton4Click(TObject *Sender)
{
//  Кнопка - Графики
struct Format *FormatPtr;
struct Scal   *ScalPtr,*next,*ScalPtrTek,*ScalPtrTekBegin,*pred;
//struct Scal   *ScalPtr,*next,*ScalPtrTek,*ScalPtrTekBegin,*ScalPtrTekEnd,*pred;
int i;

FormatPtr=PtrFormatClass->AdresFormatNumberTek;
  if(FormatPtr->KParamGraf==0)goto m1;
ScalPtr=FormatPtr->AdresStructScalBegin;
  if(StringGrid2->Selection.Top==1 && StringGrid2->Selection.Bottom == FormatPtr->KParamGraf)
  {
  ScalPtrTek = ScalPtr;
   for(i=StringGrid2->Selection.Top; i<= StringGrid2->Selection.Bottom; i++)
   {
   ScalPtr=ScalPtr->AdresNext;
    if(ScalPtrTek->AdresMasReperRashet != NULL)
    {delete[] ScalPtrTek->AdresMasReperRashet; ScalPtrTek->AdresMasReperRashet = NULL; }
   delete[] ScalPtrTek; ScalPtrTek = ScalPtr;
   }
  FormatPtr->AdresStructScalBegin->AdresNext=0;
  FormatPtr->AdresStructScalBegin->AdresPred=0;
  FormatPtr->AdresStructScalBegin=0;
  FormatPtr->KParamGraf=0;
  StringGrid2->RowCount=1;
  goto m1;
  }
  else
  {
  for(i=1; i<StringGrid2->Selection.Top; i++) ScalPtr=ScalPtr->AdresNext;
  ScalPtrTekBegin=ScalPtr;
  pred=ScalPtr->AdresPred;
  ScalPtr=FormatPtr->AdresStructScalBegin;
  for(i=1; i< StringGrid2->Selection.Bottom; i++) ScalPtr=ScalPtr->AdresNext;
//  ScalPtrTekEnd=ScalPtr;
  next=ScalPtr->AdresNext;
  ScalPtr=ScalPtrTek=ScalPtrTekBegin;
   for(i=StringGrid2->Selection.Top; i<= StringGrid2->Selection.Bottom; i++)
   {
   ScalPtr=ScalPtr->AdresNext;
    if(ScalPtrTek->AdresMasReperRashet != NULL)
    {delete[] ScalPtrTek->AdresMasReperRashet; ScalPtrTek->AdresMasReperRashet = NULL; }
   delete[] ScalPtrTek; ScalPtrTek = ScalPtr;
   }

    if(StringGrid2->Selection.Top==1)
    {
    ScalPtr=next; ScalPtr->AdresPred=0;
    FormatPtr->AdresStructScalBegin=next;
    FormatPtr->AdresStructScalBegin->AdresPred=0;
    ScalPtr=FormatPtr->AdresStructScalBegin;
    }
    else if(StringGrid2->Selection.Bottom==(StringGrid2->RowCount-1))
    {
    ScalPtr=pred;
    ScalPtr->AdresNext=0;
    }
    else
    {
    ScalPtr=next; ScalPtr->AdresPred=pred;
    ScalPtr=pred; ScalPtr->AdresNext=next;
    }
  }
FormatPtr->KParamGraf = FormatPtr->KParamGraf - (StringGrid2->Selection.Bottom - StringGrid2->Selection.Top +1);
ScalPtr=FormatPtr->AdresStructScalBegin;
 for(i=1; i<=FormatPtr->KParamGraf; i++)
 {
 StringGrid2->Cells[0][i]=i;
// StringGrid2->Cells[1][i]=ScalPtr->ident;
 StringGrid2->Cells[1][i]=ScalPtr->name;
   if(i == StringGrid2->Row)
   {
   PtrFormatClass->AdresStructScalTek = ScalPtr;;
   if(i > 1) StringGrid2->Row = 1;
   else if(i == 1 && FormatPtr->KParamGraf > 1) StringGrid2->Row = 2;
   StringGrid2->Row = i;
   }
 ScalPtr=ScalPtr->AdresNext;
 }
StringGrid2->RowCount=FormatPtr->KParamGraf+1;
m1:

}
//---------------------------------------------------------------------------
void __fastcall TFormPropertyPanel::StringGrid2DrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
  if(StringGrid2->Row==1){SpeedButton2->Enabled=false;}
  else {SpeedButton2->Enabled=true;}
    if(StringGrid2->Row==(StringGrid2->RowCount-1)){SpeedButton1->Enabled=false;}
  else {SpeedButton1->Enabled=true;}
// if(PageControl2->ActivePage->Name=="TabSheet4")
// if(TabControl1->TabIndex==0)
 if(PageControl1->ActivePage==TabSheet3)
  {
  SpeedButton2->Enabled=false;
  }

}
//---------------------------------------------------------------------------
void __fastcall TFormPropertyPanel::StringGrid2SelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
struct Format *FormatPtr;
//struct Pasp *PtrPasp;
struct Scal   *ScalPtr;
struct ScalArg   *ScalArgPtr;
int NCol,NStrok,i;
 NCol=1;
SpeedButton2->Enabled=true;
if(ARow>=(StringGrid2->RowCount-1)){SpeedButton1->Enabled=false; ARow=StringGrid2->RowCount-1;}
                              else {SpeedButton1->Enabled=true;}

if((ACol==0) || (ARow==0)){ CanSelect=false; return; } else CanSelect=true;
  while(PtrWinSistTab->NPoleNCol[NCol] !=1 ) NCol++;
 NStrok=1;
 if(PageControl1->ActivePage==TabSheet3)
 {
 SpeedButton2->Enabled=false;
 FormatPtr=PtrFormatClass->AdresFormatNumberTek;
 ScalArgPtr=FormatPtr->AdresStructArg;
 NStrok=1;
  while(stricmp(ScalArgPtr->ident,StringGrid5->Cells[NCol][NStrok].c_str()) != 0 )
  { NStrok++; if(NStrok >= StringGrid5->RowCount) { NStrok = 1; break; } }
 StringGrid5->Col=NCol; StringGrid5->Row=NStrok;
 return;
 }
 if(PageControl1->ActivePage==TabSheet2)
  {
ScalPtr=PtrFormatClass->AdresFormatNumberTek->AdresStructScalBegin;
for(i=1; i<ARow; i++) ScalPtr=ScalPtr->AdresNext;
PtrFormatClass->AdresStructScalTek=ScalPtr;
  }
 NStrok=1;
  while(stricmp(ScalPtr->ident,StringGrid1->Cells[NCol][NStrok].c_str()) != 0 )
  { NStrok++; if(NStrok >= StringGrid1->RowCount) { NStrok = 1; break; } }
 StringGrid1->Col=NCol; StringGrid1->Row=NStrok;
 i=0;
 while(strcmp((PtrPasp+i)->Ident,ScalPtr->ident) != 0)
  { i++; if(i >= PtrSisTable->KPasp) {i = 0; break; } }

  switch((PtrPasp+i)->Tip)
  {
  case 22:
  if(ScalPtr->nr != 0)  ListBox1->ItemIndex = (int)ScalPtr->nr-9; break;
  case 11:
  if(ScalPtr->nr != 0)  ListBox1->ItemIndex = (int)ScalPtr->nr-1; break;
  default :
   i=0;
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormPropertyPanel::StringGrid3SelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
struct Tabl   *TablPtr;
int NCol,NStrok,i;
 NCol=1;
if((ACol==0) || (ARow==0)){ CanSelect=false; return; } else CanSelect=true;
  while(PtrWinSistTab->NPoleNCol[NCol] !=1 ) NCol++;
 NStrok=1;
 TablPtr=PtrFormatClass->AdresFormatNumberTek->AdresStructTablBegin;
for(i=1; i<ARow; i++) TablPtr=TablPtr->AdresNext;
PtrFormatClass->AdresStructTablTek=TablPtr;
  while(stricmp(TablPtr->ident,StringGrid4->Cells[NCol][NStrok].c_str()) != 0 )
  { NStrok++; if(NStrok >= StringGrid4->RowCount) { NStrok = 1; break; } }
 StringGrid4->Col=NCol; StringGrid4->Row=NStrok;
 i=0;
 while(strcmp((PtrPasp+i)->Ident,TablPtr->ident) != 0)       // 2007_12_20
 { i++; if(i >= PtrSisTable->KPasp) return; }                // 2007_12_20
PtrWinSistTab->AdresParamProperty=(void *)TablPtr;
  FormTxtProp->Close();
  FormTxtProp->Close();
  FormTxtProp->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFormPropertyPanel::Edit3Exit(TObject *Sender)
{
/*struct Format *FormatPtr;
PtrFormatClass->KPolocGoriz=atoi(Edit3->Text.c_str());
PtrFormatClass->KPolocVert=atoi(Edit4->Text.c_str());
FormatPtr=PtrFormatClass->AdresFormatNumberTek;
FormatPtr->KPolocGoriz=PtrFormatClass->KPolocGoriz;
FormatPtr->KPolocVert=PtrFormatClass->KPolocVert;
*/
}
//---------------------------------------------------------------------------





void __fastcall TFormPropertyPanel::SpeedButton6Click(TObject *Sender)
{
//  Кнопка + Таблицы
struct Format *FormatPtr;
struct Tabl *TablPtr,*TablPtrTek;
int i,j,jj,NCol;
FormatPtr=PtrFormatClass->AdresFormatNumberTek;
 NCol=1;
//FileNameSave = false;
  FormatPtr=PtrFormatClass->AdresFormatNumberTek;
  if(CheckBox12->Checked)
  {
   if( RowDragDrop != 0 )
   {
   TablPtr=PtrFormatClass->AdresFormatNumberTek->AdresStructTablBegin;
   for(i=1; i<RowDragDrop; i++) TablPtr=TablPtr->AdresNext;
   RowDragDrop = 0;
//   PtrFormatClass->AdresStructScalTek=ScalPtr;
   }
   else  TablPtr = PtrFormatClass->AdresStructTablTek;
  while(PtrWinSistTab->NPoleNCol[NCol] != 1 ) NCol++;
  strcpy(TablPtr->ident,StringGrid4->Cells[NCol][RowMouseDown].c_str());
//  strcpy(TablPtr->ident,StringGrid1->Cells[NCol][StringGrid1->Row].c_str());
  return;
  }

 NCol=1;
for(j=StringGrid4->Selection.Top; j<=StringGrid4->Selection.Bottom; j++)
{
 while(PtrWinSistTab->NPoleNCol[NCol] != 1 ) NCol++;
(char *)TablPtrTek=new char[sizeof(struct Tabl)];
for(i=0; i<sizeof(struct Tabl); i++) *((char *)TablPtrTek+i)='\0';

if(FormatPtr->KParamTabl==NULL)
{
FormatPtr->AdresStructTablBegin=TablPtrTek;
TablPtrTek->AdresPred=0; TablPtrTek->AdresNext=0;
//FormatPtr->KPolei=4;
}
else
{
TablPtr=FormatPtr->AdresStructTablBegin;
 while(TablPtr->AdresNext != NULL) TablPtr=TablPtr->AdresNext;
TablPtr->AdresNext=TablPtrTek;
TablPtrTek->AdresPred=TablPtr;
TablPtrTek->AdresNext=0;
}
FormatPtr->KParamTabl++;
//PtrFormatClass->KParamTabl++;
StringGrid3->RowCount=FormatPtr->KParamTabl+1;
StringGrid3->Cells[0][StringGrid3->RowCount-1]=StringGrid3->RowCount-1;

//strcpy(TablPtrTek->ident,StringGrid4->Cells[2][StringGrid4->Row].c_str());
//strcpy(TablPtrTek->sistema,StringGrid4->Cells[1][StringGrid4->Row].c_str());
//strcpy(TablPtrTek->ident,StringGrid4->Cells[PtrWinSistTab->NColNPole[1]][StringGrid4->Row].c_str());
//strcpy(TablPtrTek->ident,StringGrid4->Cells[PtrFileDatInpClass->MasNPoleNCol[0]+1][StringGrid4->Row].c_str());
//strcpy(TablPtrTek->sistema,StringGrid4->Cells[PtrFileDatInpClass->MasNPoleNCol[1]+1][StringGrid4->Row].c_str());
//StringGrid3->Cells[1][StringGrid3->RowCount-1]=TablPtrTek->ident;
//StringGrid2->Cells[1][StringGrid2->RowCount-1]=StringGrid1->Cells[NCol][j];
//strcpy(TablPtrTek->ident,StringGrid1->Cells[1][StringGrid1->RowCount-1].c_str());

StringGrid3->Cells[1][StringGrid3->RowCount-1]=StringGrid4->Cells[NCol][j];
strcpy(TablPtrTek->ident,StringGrid3->Cells[1][StringGrid3->RowCount-1].c_str());
strcpy(TablPtrTek->name,StringGrid3->Cells[1][StringGrid3->RowCount-1].c_str());
TablPtrTek->FormatKod=FormatPtr->FormatKod;
TablPtrTek->nr=0;
TablPtrTek->nstrok = StringGrid3->RowCount - 2;           // 2008_02_01
TablPtrTek->NumberFormat = 'f';
TablPtrTek->KSimDoPoint = FormatPtr->KSimDoPoint;
TablPtrTek->KSimPoclePoint = FormatPtr->KSimPoclePoint;
strcpy(TablPtrTek->FormatFizika,FormatPtr->FormatFizika);
//if(TablPtrTek->NSis != 0) TablPtrTek->NSis = FormatPtr->NSis -1;
//if(TablPtrTek->NSis == 0) TablPtrTek->NSis = 1;
TablPtrTek->NSis = 1;
//  while(strcmpi((PtrPasp+i)->Ident,TablPtrTek->ident) != 0) i++;
//  strcpy(TablPtrTek->Naimenovanie,(PtrPasp+i)->Name);  // 2007.09.16
 TablPtrTek->nr=0;                                // 2008_03_22
 if(NRazrRK > 0) { TablPtrTek->NumberFormat = 'r'; TablPtrTek->nr= (unsigned char)NRazrRK; NRazrRK = 0;}
 i=0;  // 2008_06_27
 while(strcmpi(TablPtrTek->ident,(PtrPasp+i)->Ident) != 0) i++;
 strcpy(TablPtrTek->Naimenovanie,(PtrPasp+i)->Name);  // 2007.09.16
 if(((PtrPasp+i)->Tip == 22 || (PtrPasp+i)->Tip == 11) && (ListBox1->ItemIndex != -1))  // 2008_03_22
  {
  TablPtrTek->NumberFormat = 'r';   TablPtrTek->KRazr = 1;
  strcpy(TablPtrTek->Naimenovanie,ListBox1->Items->Strings[ListBox1->ItemIndex].c_str());  // 2007.09.16
  } // 2008_03_22
  for(jj=0; jj<KSISTEMMAX; jj++)
  {if((PtrPasp+i)->NSis[jj] == FormatPtr->NSis) {TablPtrTek->NSis = FormatPtr->NSis; break; }}
}
}
//---------------------------------------------------------------------------

void __fastcall TFormPropertyPanel::SpeedButton7Click(TObject *Sender)
{
//  Кнопка - Таблицы
struct Format *FormatPtr;
//struct Tabl   *TablPtr,*next,*TablPtrTek,*TablPtrTekBegin,*TablPtrTekEnd,*pred;
struct Tabl   *TablPtr,*next,*TablPtrTek,*TablPtrTekBegin,*pred;
int i;

FormatPtr=PtrFormatClass->AdresFormatNumberTek;
  if(FormatPtr->KParamTabl==0)goto m1;
TablPtr=FormatPtr->AdresStructTablBegin;
  if(StringGrid3->Selection.Top==1 && StringGrid3->Selection.Bottom == FormatPtr->KParamTabl)
  {
  TablPtrTek = TablPtr;
  for(i=StringGrid3->Selection.Top; i<= StringGrid3->Selection.Bottom; i++)
  {
   TablPtr=TablPtr->AdresNext;
   if(TablPtrTek->AdresMasReperRashet != NULL)
   {delete[] TablPtrTek->AdresMasReperRashet; TablPtrTek->AdresMasReperRashet = NULL; }
  delete[] TablPtrTek; TablPtrTek = TablPtr;
  }
  FormatPtr->AdresStructTablBegin->AdresNext=0;
  FormatPtr->AdresStructTablBegin->AdresPred=0;
  FormatPtr->AdresStructTablBegin=0;
  FormatPtr->KParamTabl=0;
  StringGrid3->RowCount=1;
  goto m1;
  }
  else
  {
  for(i=1; i<StringGrid3->Selection.Top; i++) TablPtr=TablPtr->AdresNext;
  TablPtrTekBegin=TablPtr;
  pred=TablPtr->AdresPred;
  TablPtr=FormatPtr->AdresStructTablBegin;
  for(i=1; i< StringGrid3->Selection.Bottom; i++) TablPtr=TablPtr->AdresNext;
//  TablPtrTekEnd=TablPtr;
  next=TablPtr->AdresNext;
  TablPtr=TablPtrTek=TablPtrTekBegin;
  for(i=StringGrid3->Selection.Top; i<= StringGrid3->Selection.Bottom; i++)
  {
   TablPtr=TablPtr->AdresNext;
   if(TablPtrTek->AdresMasReperRashet != NULL)
   {delete[] TablPtrTek->AdresMasReperRashet; TablPtrTek->AdresMasReperRashet = NULL; }
   delete[] TablPtrTek; TablPtrTek = TablPtr;
  }

    if(StringGrid3->Selection.Top==1)
    {
    TablPtr=next; TablPtr->AdresPred=0;
    FormatPtr->AdresStructTablBegin=next;
    FormatPtr->AdresStructTablBegin->AdresPred=0;
    TablPtr=FormatPtr->AdresStructTablBegin;
    }
    else if(StringGrid3->Selection.Bottom==(StringGrid3->RowCount-1))
    {
    TablPtr=pred;
    TablPtr->AdresNext=0;
    }
    else
    {
    TablPtr=next; TablPtr->AdresPred=pred;
    TablPtr=pred; TablPtr->AdresNext=next;
    }
  }
FormatPtr->KParamTabl = FormatPtr->KParamTabl - (StringGrid3->Selection.Bottom - StringGrid3->Selection.Top +1);
TablPtr=FormatPtr->AdresStructTablBegin;
 for(i=1; i<=FormatPtr->KParamTabl; i++)
 {
 StringGrid3->Cells[0][i]=i;
// StringGrid3->Cells[1][i]=TablPtr->ident;
 StringGrid3->Cells[1][i]=TablPtr->name;
   if(i == StringGrid3->Row)
   {
   PtrFormatClass->AdresStructTablTek = TablPtr;;
   if(i > 1) StringGrid3->Row = 1;
   else if(i == 1 && FormatPtr->KParamTabl > 1) StringGrid3->Row = 2;
   StringGrid3->Row = i;
   }
// if(i == StringGrid3->Row) PtrFormatClass->AdresStructTablTek = TablPtr;
 TablPtr=TablPtr->AdresNext;
 }
StringGrid3->RowCount=FormatPtr->KParamTabl+1;
m1:

}
//---------------------------------------------------------------------------

void TFormPropertyPanel::SortPolei(TStringGrid *StringGrid100)
{
short int i,j,k;
//short int *PtrMas;
int KPolei,NPole,ngr,NSis;
KPolei=0;

 KPolei=PtrWinSistTab->KPoleiTablParam;
  for(i=1; i<KPolei; i++)
  {
  StringGrid100->Cells[i][0]=PtrWinSistTab->NPoleNamePole[PtrWinSistTab->NPoleNCol[i]];
//  if(PtrWinSistTab->NPoleNamePole[PtrWinSistTab->NPoleNCol[i]]=="Имя")  // 2008_03_12
//  StringGrid100->ColWidths[i]=StringGrid100->Font->Size*64;             // 2008_03_12
//  WidthOld = StringGrid100->Width;
//  DeltaWidth = StringGrid100->Width - WidthOld;
//  FormPropertyPanel->Width = FormPropertyPanel->Width + DeltaWidth;
//  Panel3->Width = StringGrid100->Width +3;
  }
NPole=PtrWinSistTab->NPoleNCol[1];
FunSort(NPole);

 StringGrid100->ColCount=KPolei;
 StringGrid100->RowCount=KPaspReal+1;
// StringGrid100->RowCount=PtrSisTable->KPasp+1;
// StringGrid100->Row=1;  // 2008_06_20
 StringGrid100->Cells[0][0]=" N ";
/* switch(NPole)
 {
 case 1:
 case 4:
 case 5:
 case 6:
 case 11:
 case 7: PtrMas=PtrWinSistTab->MasNstrNPasp; break;
 case 10: PtrMas=PtrWinSistTab->MasNstrNRazdelNPasp; break;
 case 3: PtrMas=PtrWinSistTab->MasNstrNPotokNPasp; break;
 case 2: PtrMas=PtrWinSistTab->MasNstrNPaspZamer; break;
 } */

     for (i=1; i<=KPaspReal; i++)
    {
    StringGrid100->Cells[0][i]=IntToStr(i);
     for(j=1; j<KPolei; j++)
     {
      switch(PtrWinSistTab->NPoleNCol[j])
      {
      case 1:
      StringGrid100->Cells[j][i]=(PtrPasp+MasIdent[i-1])->Ident;   break;
      case 10:
      StringGrid100->Cells[j][i]= (PtrRazdel + MasRazdel[i-1])->Razdel;
      break;
      case 3:
      StringGrid100->Cells[j][i]=(PtrPotok+MasPotok[i-1])->Potok;
      break;
      case 4:
      StringGrid100->Cells[j][i]=(PtrPasp+MasIdent[i-1])->Adrec8;   break;
      case 5:
      StringGrid100->Cells[j][i]=(PtrPasp+MasIdent[i-1])->Tip;   break;
      case 6:
      int ngr;
//      ngr=(int)pow((double)2,(double)(PtrPasp+PtrMas[i-1])->ngr)*PtrIntegrator->KKadr;
//      ngr=(int)pow((double)2,(double)(PtrPasp+PtrMas[i-1])->Ngr)*PtrWinSistTab->KKadrSek;
      ngr=(PtrPasp+MasIdent[i-1])->F;
      StringGrid100->Cells[j][i]=ngr;
      break;
//      StringGrid1->Cells[j][i]=(PtrPasp+PtrMas[i-1])->ngr;   break;
    case 7:
      StringGrid100->ColWidths[j]=StringGrid100->Font->Size*64;
      StringGrid100->Cells[j][i]= (PtrPasp+MasIdent[i-1])->Name;
      break;
//      StringGrid1->Cells[j][i]=PtrBlok_tar+(PtrPasp+PtrMas[i-1])->index_tar;   break;
//      StringGrid1->Cells[j][i]=(PtrPasp+PtrMas[i-1])->name;   break;
      case 2:
      StringGrid100->Cells[j][i]=(PtrPasp+MasZamer[i-1])->Zamer;   break;
      case 11:
      for(k=0; k<KSISTEMMAX; k++)
      {
      NSis = (PtrPasp+MasIdent[i-1])->NSis[k];
      if(NSis == 0) continue;
      if(k == 0) StringGrid100->Cells[j][i] = " ";
      else if(k != 0) StringGrid100->Cells[j][i] = StringGrid100->Cells[j][i] + ",";
      StringGrid100->Cells[j][i] = StringGrid100->Cells[j][i] + IntToStr(NSis);
      }
      break;
      case 12:
      StringGrid100->Cells[j][i]=(PtrNakopitel+MasNakop[i-1])->NameNak;
      break;
    }
     }
    }



// PtrMas=PtrWinSistTab->MasNstrNPasp;
 StringGrid100->Row=1;  // 2008_06_20
//TabControlCh();
}


void __fastcall TFormPropertyPanel::TabControl1Change(TObject *Sender)
{
 struct Format *FormatPtr;       //2007_10_24
PtrFormatClass = PtrFormatClassM[PtrFlagPotokVizual->NumberClassFormat];
if(FormatPtr->KParamGraf == 0) SpeedButton21->Visible = false;   // 2007_10_24
else SpeedButton21->Visible = true;   // 2007_10_24
if((TFormPropertyPanel *)Sender == FormPropertyPanel) FlagChangeTabString=0;
{ NumberMarker = 0; TabControlCh(); }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TFormPropertyPanel::TabControlCh()
{
// struct SB2 *ptrTF;
// struct ParamBaza *ptrBaza;
 struct Format *FormatPtr;
 struct Scal   *ScalPtr;
 struct ScalArg   *ScalArgPtr;
 struct Tabl *TablPtr;
 struct Message *MessagePtr;
// struct Pasp *PtrPaspTek;
 AnsiString S;
 int i,KparamTek,NCol,NStrok;
// short int KPolei;
 if(PageControl1->ActivePage==TabSheet2)   //Графики
 {
// Panel3->Width = BitBtn1->Left - Panel3->Left -10;
 // if(!(FlagChangeTabString & 1 )) SortPolei(StringGrid1);
// FlagChangeTabString=FlagChangeTabString | 1;
 if(FlagChangeTabString != 1 ) SortPolei(StringGrid1);
 FlagChangeTabString= 1;
// SortPolei(StringGrid1);
 FormatPtr=PtrFormatClass->AdresFormatNumberTek;
 StringGrid2->Cells[0][0]=" N ";

 StringGrid2->RowCount=FormatPtr->KParamGraf+1;
 KparamTek=FormatPtr->KParamGraf;
 ScalPtr=FormatPtr->AdresStructScalBegin;
 FormatPtr->LineTek =0; FormatPtr->ColorTek =0x000000ff;
     if(FormatPtr->AdresStructScalBegin != NULL)
     {
    for(i=1; i<=KparamTek; i++)
    {
//    StringGrid2->Cells[1][i]=ScalPtr->ident;
//    ScalPtr->nstrok = i;
    StringGrid2->Cells[1][i]=ScalPtr->name;
    StringGrid2->Cells[0][i]=i;
    ScalPtr=ScalPtr->AdresNext;
    }
     }
   FormPropertyPanel->StringGrid2->Cells[1][0]=" Графики ";
   SpeedButton1->Enabled=true;
   SpeedButton2->Enabled=true;
   SpeedButton4->Enabled=true;

   Edit1->Enabled=true;
   Edit1->Color=clWindow;
//   StringGrid100->Color=clWindow ;
   StringGrid2->Color=clBtnFace;

    if(StringGrid2->RowCount == 1) StringGrid2->Row=0;
    else
    {
     StringGrid2->Row=1;
     PtrFormatClass->AdresStructScalTek=FormatPtr->AdresStructScalBegin;
     NCol = 1;
     while(PtrWinSistTab->NPoleNCol[NCol] !=1 ) NCol++;
     NStrok=1;
     ScalPtr=FormatPtr->AdresStructScalBegin;
  while(stricmp(ScalPtr->ident,StringGrid1->Cells[NCol][NStrok].c_str()) != 0 )
  { NStrok++; if(NStrok >= StringGrid1->RowCount) { NStrok = 1; break; } }
 StringGrid1->Col=NCol; StringGrid1->Row=NStrok;
     }
   }//Конец if(PageControl2->ActivePage->Name=="TabSheet2")

 else if(PageControl1->ActivePage==TabSheet3)   //Аргумент
 {
 if(FlagChangeTabString != 3 ) SortPolei(StringGrid5);
 FlagChangeTabString= 3;
// SortPolei(StringGrid1);
 FormatPtr=PtrFormatClass->AdresFormatNumberTek;
 if(SpeedButton21->Visible == false) return;   // 2007_10_24
 if(FormatPtr->AdresStructArg==NULL)
 {
     (char *)ScalArgPtr=new char[sizeof(struct ScalArg)];
     for(i=0; i<sizeof(struct ScalArg); i++) *((char *)ScalArgPtr+i)='\0';
     FormatPtr->AdresStructArg=ScalArgPtr;
//     strcpy(ScalArgPtr->ident,"tkadr"); strcpy(ScalArgPtr->name,"Время");
     strcpy(ScalArgPtr->ident,(PtrPasp + PtrSisTable->NPaspTime[0])->Ident);
     strcpy(ScalArgPtr->name,"Время");
     ScalArgPtr->step_ocif=4;
     ScalArgPtr->step=10;
//     ScalArgPtr->color=clBlack;
// ScalArgPtr=PtrFormatClass->AdresFormatNumberTek->AdresStructArg;
 ScalArgPtr->color = FormArgProperty->FontDialogArg->Font->Color;
 ScalArgPtr->FontArg.Color = FormArgProperty->FontDialogArg->Font->Color;
 ScalArgPtr->FontArg.Charset = FormArgProperty->FontDialogArg->Font->Charset;
 ScalArgPtr->FontArg.Height = FormArgProperty->FontDialogArg->Font->Height;
 ScalArgPtr->FontArg.Size = FormArgProperty->FontDialogArg->Font->Size;
 ScalArgPtr->FontArg.Style = FormArgProperty->FontDialogArg->Font->Style;
 strcpy(ScalArgPtr->FontArg.Name,FormArgProperty->FontDialogArg->Font->Name.c_str());
 ScalArgPtr->NumberFormat = 's';
 ScalArgPtr->KSimPoclePoint = 3;
 FormatPtr->ColorBrush = ColorDialogBrush->Color;
 FormatPtr->ColorSetka = ColorDialogSetka->Color;
/*   switch(ScalArgPtr->NumberFormat)
 {
 case 'f': S = "Вещественный"; break;
 case 's': S = "час:мин:сек"; break;
 case 'm': S = "час:мин:сек:млсек"; break;
 case 'g': S = "град:мин:сек"; break;
 }
 i=0;
 while(S != ComboBox1->Items->Strings[i]) i++;
 ComboBox1->ItemIndex = i;
  */
 }
 StringGrid6->Cells[0][0]=" N ";
    StringGrid6->ColCount=2;
    StringGrid6->RowCount=2;
    StringGrid6->Row=1;
    StringGrid6->Cells[1][0]=" Аргумент ";
    ScalArgPtr=FormatPtr->AdresStructArg;
//    StringGrid2->Cells[1][1]=ScalArgPtr->ident;
    StringGrid6->Cells[1][1]=ScalArgPtr->name;
    StringGrid6->Cells[0][1]=1;
   SpeedButton17->Enabled=false;
   SpeedButton19->Enabled=false;
   SpeedButton20->Enabled=false;

//   Edit15->Enabled=false;
//   Edit15->Color=clBtnFace;
//   StringGrid100->Color=clBtnFace;
//   StringGrid2->Color=clWindow;
   StringGrid6->Color=clBtnFace;
  NCol = 1;
  while(PtrWinSistTab->NPoleNCol[NCol] !=1 ) NCol++;
  NStrok=1;
  while(stricmp(ScalArgPtr->ident,StringGrid5->Cells[NCol][NStrok].c_str()) != 0 ) NStrok++;
  StringGrid5->Col=NCol; StringGrid5->Row=NStrok;
   }//Конец if(PageControl1->ActivePage==TabSheet3)   //Аргумент

//   if(PageControl1->ActivePage->Name=="TabSheet3")
//   else if((PageControl1->ActivePage==TabSheet3) || (PageControl3->ActivePage==TabSheet7))
//   else if((PageControl1->ActivePage==TabSheet3) && (PageControl3->ActivePage==TabSheet7))
   else if(PageControl1->ActivePage==TabSheet4)  //Таблицы
{
// if(!(FlagChangeTabString & 2 )) SortPolei(StringGrid4);
// FlagChangeTabString=FlagChangeTabString | 2;
// Panel6->Width = BitBtn6->Left - Panel3->Left -10;
 if(FlagChangeTabString != 2 ) SortPolei(StringGrid4);
 FlagChangeTabString= 2;
 FormatPtr=PtrFormatClass->AdresFormatNumberTek;
// KPolei=FormatPtr->KPolei;
 StringGrid3->RowCount=FormatPtr->KParamTabl+1;
// StringGrid3->ColCount=KPolei;
 if(FormatPtr->KParamTabl==0)StringGrid3->RowCount=1;
  StringGrid3->Cells[0][0]=" N ";
  StringGrid3->Cells[1][0]=" Параметр ";
  KparamTek=FormatPtr->KParamTabl;
 TablPtr=FormatPtr->AdresStructTablBegin;
     if(FormatPtr->AdresStructTablBegin != NULL)
     {
    for(i=1; i<=KparamTek; i++)
    {
//    StringGrid3->Cells[1][i]=TablPtr->ident;
    if(TablPtr->name[0]=='\0') StringGrid3->Cells[1][i]=TablPtr->ident;
    else StringGrid3->Cells[1][i]=TablPtr->name;
    StringGrid3->Cells[0][i]=i;
    TablPtr=TablPtr->AdresNext;
    }
     }
     //   StringGrid100->Color=clWindow ;
   StringGrid3->Color=clBtnFace;
    if(StringGrid3->RowCount == 1) StringGrid3->Row=0;
    else
    {
    NCol = 1;
    while(PtrWinSistTab->NPoleNCol[NCol] !=1 ) NCol++;
    NStrok=1;
    TablPtr=FormatPtr->AdresStructTablBegin;
     while(stricmp(TablPtr->ident,StringGrid4->Cells[NCol][NStrok].c_str()) != 0 )
    { NStrok++; if(NStrok >= StringGrid4->RowCount) { NStrok = 1; break; } }
    StringGrid4->Col=NCol; StringGrid4->Row=NStrok;
    PtrWinSistTab->AdresParamProperty = (void *)TablPtr;
    }
   }//Конец if(PageControl2->ActivePage->Name=="TabSheet3")
   TablOpenOldNastr();
}

void TFormPropertyPanel::TablSaveNewNastr()
{
// Запомнить новую настройку
struct Format *FormatPtr;
struct Format *PtrF;
struct Scal *PtrS;
struct Tabl *PtrTabl;
struct ScalArg   *ScalArgPtr;
//struct Tabl *PtrTabl,*PtrT;
//struct Tabl *PtrT;
short int FormatKod;
char FormatFizika[8],buf[4];
int i,j,KSim;
short int KPolei;
unsigned char KSimDoPoint;
unsigned char KSimPoclePoint;
   KPolei=1;
   FormatPtr=PtrFormatClass->AdresFormatNumberTek;
// if(FormatPtr->KParamTabl != 0 )
// {
//   for(i=1; i<KPOLEIMAX; i++) { FormatPtr->NPoleNCol[i]=0; FormatPtr->NColNPole[i]=0; }
   for(i=0; i<KPOLEIMAX; i++) { FormatPtr->NPoleNCol[i]=0; FormatPtr->NColNPole[i]=0; } // 2007_12_20
      if(CheckBox1->Checked==true)
      {
      FormatPtr->NPoleNCol[CSpinEdit1->Value]=1;
      FormatPtr->NColNPole[1]=CSpinEdit1->Value; KPolei++;
      }
      if(CheckBox2->Checked==true)
      {
      FormatPtr->NPoleNCol[CSpinEdit2->Value]=2;
      FormatPtr->NColNPole[2]=CSpinEdit2->Value; KPolei++;
      }
      if(CheckBox3->Checked==true)
      {
      FormatPtr->NPoleNCol[CSpinEdit3->Value]=3;
      FormatPtr->NColNPole[3]=CSpinEdit3->Value; KPolei++;
      }
      if(CheckBox4->Checked==true)
      {
      FormatPtr->NPoleNCol[CSpinEdit4->Value]=4;
      FormatPtr->NColNPole[4]=CSpinEdit4->Value; KPolei++;
      }
      if(CheckBox5->Checked==true)
      {
      FormatPtr->NPoleNCol[CSpinEdit5->Value]=5;
      FormatPtr->NColNPole[5]=CSpinEdit5->Value; KPolei++;
      }
      if(CheckBox6->Checked==true)
      {
      FormatPtr->NPoleNCol[CSpinEdit6->Value]=6;
      FormatPtr->NColNPole[6]=CSpinEdit6->Value; KPolei++;
      }
      if(CheckBox7->Checked==true)
      {
      FormatPtr->NPoleNCol[CSpinEdit7->Value]=7;
      FormatPtr->NColNPole[7]=CSpinEdit7->Value; KPolei++;
      }
      if(CheckBox8->Checked==true)
      {
      FormatPtr->NPoleNCol[CSpinEdit8->Value]=8;
      FormatPtr->NColNPole[8]=CSpinEdit8->Value; KPolei++;
      }
      if(CheckBox9->Checked==true)
      {
      FormatPtr->NPoleNCol[CSpinEdit9->Value]=9;
      FormatPtr->NColNPole[9]=CSpinEdit9->Value; KPolei++;
      }
      if(CheckBox10->Checked==true)
      {
      FormatPtr->NPoleNCol[CSpinEdit10->Value]=10;
      FormatPtr->NColNPole[10]=CSpinEdit10->Value; KPolei++;
      }
      if(CheckBox13->Checked==true)
      {
      FormatPtr->NPoleNCol[CSpinEdit11->Value]=11;
      FormatPtr->NColNPole[11]=CSpinEdit11->Value; KPolei++;
      }
  FormatPtr->KPolei=KPolei;
  FormatKod = (short int)StrToInt(ComboBox2->Items->Strings[ComboBox2->ItemIndex]);
strcpy(FormatFizika,"%");
FormatPtr->KSimDoPoint = KSimDoPoint = (unsigned char)StrToInt(Edit5->Text);
FormatPtr->KSimPoclePoint = KSimPoclePoint = (unsigned char)StrToInt(Edit6->Text);
KSim= KSimDoPoint + KSimPoclePoint+1;
strcat(FormatFizika,itoa(KSim,buf,10));
strcat(FormatFizika,"."); strcat(FormatFizika,Edit6->Text.c_str());
strcat(FormatFizika,"f");
FormatPtr->FormatKod=FormatKod;
strcpy(FormatPtr->FormatFizika,FormatFizika);
//}
 if(CheckBoxFormatAll->Checked == true) FormatPtr->FlagFormatAll = true;
 else if(CheckBoxFormatAll->Checked == false) FormatPtr->FlagFormatAll = false;
 if(FormatPtr->KParamTabl != 0 && FormatPtr->FlagFormatAll == true)
 {
 PtrTabl =  FormatPtr->AdresStructTablBegin;
  for(;;)
  {
  PtrTabl->FormatKod = FormatPtr->FormatKod;  PtrTabl->NumberFormat = 'f';
  PtrTabl->nr = 0;
  strcpy(PtrTabl->FormatFizika,FormatPtr->FormatFizika);
  PtrTabl->KSimDoPoint = FormatPtr->KSimDoPoint;
  PtrTabl->KSimPoclePoint = FormatPtr->KSimPoclePoint;
  if(PtrTabl->AdresNext == NULL) break;
  PtrTabl = PtrTabl->AdresNext;
  }
 CheckBoxFormatAll->Checked = false; FormatPtr->FlagFormatAll = false;
 }

 FormatPtr->FontGraf.Color = FontDialogGraf->Font->Color;
 FormatPtr->FontGraf.Charset = FontDialogGraf->Font->Charset;
 FormatPtr->FontGraf.Height = FontDialogGraf->Font->Height;
 FormatPtr->FontGraf.Size = FontDialogGraf->Font->Size;
 FormatPtr->FontGraf.Style = FontDialogGraf->Font->Style;
// Ptr->Font.Style = FontDialogGraf->Font->Style;
 strcpy(FormatPtr->FontGraf.Name,FontDialogGraf->Font->Name.c_str());
 FormatPtr->ColorBrush = ColorDialogBrush->Color;
 FormatPtr->ColorSetka = ColorDialogSetka->Color;

 FormatPtr->FontTabl.Color = FontDialogTabl->Font->Color;
 FormatPtr->FontTabl.Charset = FontDialogTabl->Font->Charset;
 FormatPtr->FontTabl.Height = FontDialogTabl->Font->Height;
 FormatPtr->FontTabl.Size = FontDialogTabl->Font->Size;
 FormatPtr->FontTabl.Style = FontDialogTabl->Font->Style;
// Ptr->Font.Style = FontDialogTabl->Font->Style;
 strcpy(FormatPtr->FontTabl.Name,FontDialogTabl->Font->Name.c_str());

  PtrFormatClass->KPolocGoriz=FormatPtr->KPolocGoriz=StrToInt(Edit3->Text);
  PtrFormatClass->KPolocVert=FormatPtr->KPolocVert=StrToInt(Edit4->Text);

 PtrF = PtrFormatClass->AdresFormatNumberTek;
 if(RadioButton1->Checked == true && FormatPtr->KParamGraf != 0)
 {
 PtrS = PtrF->AdresStructScalBegin;
  for(i = 0; i < PtrF->KParamGraf; i++)
  {
  PtrS->FontScal.Charset = PtrF->FontGraf.Charset;
  PtrS->FontScal.Height = PtrF->FontGraf.Height;
  PtrS->FontScal.Size = PtrF->FontGraf.Size;
  PtrS->FontScal.Style = PtrF->FontGraf.Style;
  strcpy(PtrS->FontScal.Name,PtrF->FontGraf.Name);
  if( i < PtrF->KParamGraf -1) PtrS = PtrS->AdresNext;
  }
 }

 FormatPtr->NSis = (unsigned char)StrToInt(ComboBox3->Text);
 if(RadioButton5->Checked == true) FormatPtr->FlagNSisAll = true;
 else if(RadioButton5->Checked == false) FormatPtr->FlagNSisAll = false;
 if(FormatPtr->KParamGraf != 0 && FormatPtr->FlagNSisAll == true)
 {
 PtrS =  FormatPtr->AdresStructScalBegin;
  for(;;)
  {
//  if(PtrS->NSis != 0) PtrS->NSis = FormatPtr->NSis-1;
  i=0;
  while(strcmpi((PtrPasp+i)->Ident,PtrS->ident) != 0) i++;
  for(j=0; j<KSISTEMMAX; j++)
  {if((PtrPasp+i)->NSis[j] == FormatPtr->NSis) {PtrS->NSis = FormatPtr->NSis; break; }}
//  if(PtrS->NSis != 0) PtrS->NSis = FormatPtr->NSis;
  if(PtrS->AdresNext == NULL) break;
  PtrS = PtrS->AdresNext;
  }
 }

 if(FormatPtr->KParamTabl != 0 && FormatPtr->FlagNSisAll == true)
 {
 PtrTabl =  FormatPtr->AdresStructTablBegin;
  for(;;)
  {
//  if(PtrTabl->NSis != 0) PtrTabl->NSis = FormatPtr->NSis-1;
  i=0;
  while(strcmpi((PtrPasp+i)->Ident,PtrTabl->ident) != 0) i++;
  for(j=0; j<KSISTEMMAX; j++)
  {if((PtrPasp+i)->NSis[j] == FormatPtr->NSis) {PtrTabl->NSis = FormatPtr->NSis; break; }}
//  if(PtrTabl->NSis != 0) PtrTabl->NSis = FormatPtr->NSis;
  if(PtrTabl->AdresNext == NULL) break;
  PtrTabl = PtrTabl->AdresNext;
  }
 }
 if(RadioButton7->Checked == true) PtrFormatClass->FlagIntervalGlobal = true;
 else if(RadioButton7->Checked == false) PtrFormatClass->FlagIntervalGlobal = false;
 if(RadioButton12->Checked == true) PtrFormatClass->TipOcifrTime = true;            // 2007_12_04
 else if(RadioButton12->Checked == false) PtrFormatClass->TipOcifrTime = false;     // 2007_12_04
 if(RadioButton9->Checked == true) PtrFormatClass->FlagOcifrTime = true;
 else if(RadioButton9->Checked == false) PtrFormatClass->FlagOcifrTime = false;     // 2007_12_04

 if(FormatPtr->KParamGraf == 0) { FormatPtr->AdresStructArg = NULL; return; } // 2007_10_24
 if(FormatPtr->AdresStructArg==NULL)
 {
 (char *)ScalArgPtr=new char[sizeof(struct ScalArg)];
 for(i=0; i<sizeof(struct ScalArg); i++) *((char *)ScalArgPtr+i)='\0';
 FormatPtr->AdresStructArg=ScalArgPtr;
 strcpy(ScalArgPtr->ident,"tkadr"); strcpy(ScalArgPtr->name,"Время");
 ScalArgPtr->step_ocif=4;
 ScalArgPtr->step=10;
 ScalArgPtr->color = FormArgProperty->FontDialogArg->Font->Color;
 ScalArgPtr->FontArg.Color = FormArgProperty->FontDialogArg->Font->Color;
 ScalArgPtr->FontArg.Charset = FormArgProperty->FontDialogArg->Font->Charset;
 ScalArgPtr->FontArg.Height = FormArgProperty->FontDialogArg->Font->Height;
 ScalArgPtr->FontArg.Size = FormArgProperty->FontDialogArg->Font->Size;
 ScalArgPtr->FontArg.Style = FormArgProperty->FontDialogArg->Font->Style;
 strcpy(ScalArgPtr->FontArg.Name,FormArgProperty->FontDialogArg->Font->Name.c_str());
 ScalArgPtr->NumberFormat = 's';
 ScalArgPtr->KSimPoclePoint = 3;
 FormatPtr->ColorBrush = ColorDialogBrush->Color;
 FormatPtr->ColorSetka = ColorDialogSetka->Color;
 }

}
//----------------------------------------------------------------------------
void TFormPropertyPanel::TablOpenOldNastr()
{
// Открыть старую настройку
struct Format *FormatPtr;
int i;
FormatPtr=PtrFormatClass->AdresFormatNumberTek;
   CSpinEdit1->Value=0; CheckBox1->Checked=false;
   CSpinEdit2->Value=0; CheckBox2->Checked=false;
   CSpinEdit3->Value=0; CheckBox3->Checked=false;
   CSpinEdit4->Value=0; CheckBox4->Checked=false;
   CSpinEdit5->Value=0; CheckBox5->Checked=false;
   CSpinEdit6->Value=0; CheckBox6->Checked=false;
   CSpinEdit7->Value=0; CheckBox7->Checked=false;
   CSpinEdit8->Value=0; CheckBox8->Checked=false;
   CSpinEdit9->Value=0; CheckBox9->Checked=false;
   CSpinEdit10->Value=0; CheckBox10->Checked=false;
   CSpinEdit11->Value=0; CheckBox13->Checked=false;
i=0;
while(StrToInt(ComboBox2->Items->Strings[i]) != (int)FormatPtr->FormatKod) i++;
ComboBox2->ItemIndex = i;
i=0;
while(StrToInt(ComboBox3->Items->Strings[i]) != (int)FormatPtr->NSis) i++;
ComboBox3->ItemIndex = i;
 FormatPtr->NSis = (unsigned char)StrToInt(ComboBox3->Text);
 if(FormatPtr->FlagNSisAll == true) RadioButton5->Checked = true;
 else RadioButton6->Checked = true;
 if(PtrFormatClass->FlagIntervalGlobal == true) RadioButton7->Checked = true;
 else if(PtrFormatClass->FlagIntervalGlobal == false) RadioButton7->Checked = false;
 if(PtrFormatClass->FlagOcifrTime == true) RadioButton9->Checked = true;
 else if(PtrFormatClass->FlagOcifrTime == false) RadioButton9->Checked = false;  // 2007_12_04
 if(PtrFormatClass->TipOcifrTime == true) RadioButton12->Checked = true;         // 2007_12_04
 else if(PtrFormatClass->TipOcifrTime == false) RadioButton12->Checked = false;  // 2007_12_04
//FormatPtr->FormatFizika;
//UpDown3->Position=8; UpDown4->Position=2;
// if(FormatPtr->KParamTabl == 0 ) CheckBoxFormatAll->Checked = true;
// { FormatPtr->KSimDoPoint = 5; FormatPtr->KSimPoclePoint = 2; CheckBoxFormatAll->Checked = true;}
Edit5->Text = IntToStr((int)FormatPtr->KSimDoPoint);
Edit6->Text = IntToStr((int)FormatPtr->KSimPoclePoint);
   for(i=1; i<KPOLEIMAX; i++)
  {
    if(FormatPtr->NPoleNCol[i] != 0)
    {
     switch(FormatPtr->NPoleNCol[i])
     {
     case 1:      CheckBox1->Checked=true; CSpinEdit1->Value=i; break;
     case 2:      CheckBox2->Checked=true; CSpinEdit2->Value=i; break;
     case 3:      CheckBox3->Checked=true; CSpinEdit3->Value=i; break;
     case 4:      CheckBox4->Checked=true; CSpinEdit4->Value=i; break;
     case 5:      CheckBox5->Checked=true; CSpinEdit5->Value=i; break;
     case 6:      CheckBox6->Checked=true; CSpinEdit6->Value=i; break;
     case 7:      CheckBox7->Checked=true; CSpinEdit7->Value=i; break;
     case 8:      CheckBox8->Checked=true; CSpinEdit8->Value=i; break;
     case 9:      CheckBox9->Checked=true; CSpinEdit9->Value=i; break;
     case 10:     CheckBox10->Checked=true; CSpinEdit10->Value=i; break;
     case 11:     CheckBox13->Checked=true; CSpinEdit11->Value=i; break;
     }
    }
  }
 Edit3->Text=PtrFormatClass->KPolocGoriz;
 Edit4->Text=PtrFormatClass->KPolocVert;

 if(FormatPtr->KParamGraf != 0 )
 {
 Edit3->Text=FormatPtr->KPolocGoriz;
 Edit4->Text=FormatPtr->KPolocVert;
 ColorDialogBrush->Color = (TColor)FormatPtr->ColorBrush;
 ColorDialogSetka->Color = (TColor)FormatPtr->ColorSetka;
 }
 Edit9->Color=ColorDialogBrush->Color; Edit10->Color=ColorDialogSetka->Color;
 if(FormatPtr->KParamTabl != 0 )
 {
 FontDialogTabl->Font->Color = (TColor)FormatPtr->FontTabl.Color;
 FontDialogTabl->Font->Charset = FormatPtr->FontTabl.Charset;
 FontDialogTabl->Font->Height = FormatPtr->FontTabl.Height;
 FontDialogTabl->Font->Size = FormatPtr->FontTabl.Size;
 FontDialogTabl->Font->Style = FormatPtr->FontTabl.Style;
// Ptr->Font.Style = FontDialogTabl->Font->Style;
 FontDialogTabl->Font->Name = FormatPtr->FontTabl.Name;
 }
 if(FormatPtr->KParamGraf == 0) FormatPtr->AdresStructArg = NULL;   // 2007_10_24
}

void __fastcall TFormPropertyPanel::BitBtn10Click(TObject *Sender)
{
TablOpenOldNastr();
}
//---------------------------------------------------------------------------

void __fastcall TFormPropertyPanel::BitBtn6Click(TObject *Sender)
{
TablSaveNewNastr();
}
//---------------------------------------------------------------------------



void __fastcall TFormPropertyPanel::Edit2Change(TObject *Sender)
{
int i,NCol;
TEdit *EditTek;
TStringGrid *StringGridTek;
       if(Sender==Edit2) {StringGridTek=StringGrid1; EditTek=Edit2; }
 else  if(Sender==Edit7) {StringGridTek=StringGrid4; EditTek=Edit7; }
 else  if(Sender==Edit1) {StringGridTek=StringGrid2; EditTek=Edit1; }
 else  if(Sender==Edit8) {StringGridTek=StringGrid3; EditTek=Edit8; }
 else  if(Sender==Edit16) {StringGridTek=StringGrid5; EditTek=Edit16; }
  NCol=StringGridTek->Col;
  if(EditTek->Text.Length()==0) return;
  for(i=0; i < StringGridTek->RowCount; i++)
  {
  if(EditTek->Text ==  (StringGridTek->Cells[NCol][i]).SubString(1,(EditTek->Text).Length()))
  { StringGridTek->Row=i; break; }
  }
EditTek->SetFocus();  // 2008_03_21
//  if(Edit1->Text==StringGrid1->Cells[1][i])  StringGrid1->Row=i;  // AnsiString

}
//---------------------------------------------------------------------------


void __fastcall TFormPropertyPanel::StringGrid4ColumnMoved(TObject *Sender,
      int FromIndex, int ToIndex)
{
short int FromNPole,k;
 int i;
 FromNPole=PtrWinSistTab->NPoleNCol[FromIndex];
 i=FromIndex;
if(FromIndex > ToIndex)
{
 for(k=0; k<(FromIndex-ToIndex); k++)
 {
 PtrWinSistTab->NPoleNCol[i]=PtrWinSistTab->NPoleNCol[i-1];
 i--;
 }
}
else if(FromIndex < ToIndex)
{
 for(k=0; k<(ToIndex-FromIndex); k++)
 {
 PtrWinSistTab->NPoleNCol[i]=PtrWinSistTab->NPoleNCol[i+1];
 i++;
 }
}
 PtrWinSistTab->NPoleNCol[ToIndex]=FromNPole;
// PtrWinSistTab->NColNPole[FromNPole]=ToIndex;
if((ToIndex == 1) || (FromIndex == 1)) SortPolei((TStringGrid *)Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFormPropertyPanel::StringGrid1Click(TObject *Sender)
{
/*char Ident[64];
int i;
AnsiString S;
Ident[0] = '\0';
//strcpy(Ident,StringGrid1->Cells[1][StringGrid1->Row].c_str());
S= StringGrid1->Cells[1][StringGrid1->Row];
strcpy(Ident,S.c_str());
 while(strcmp((PtrPasp+i)->ident,Ident) != 0) i++;
PtrWinSistTab->AdresParamProperty=(void *)(PtrPasp+i);
FormParamProperty->ShowModal();
*/
}
//---------------------------------------------------------------------------


void __fastcall TFormPropertyPanel::StringGrid1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
TStringGrid *StringGridTek;
       if(Sender==StringGrid1) StringGridTek=StringGrid1;
       else if(Sender==StringGrid4) StringGridTek=StringGrid4;
       else if(Sender==StringGrid2) StringGridTek=StringGrid2;
       else if(Sender==StringGrid3) StringGridTek=StringGrid3;
 if((Sender == StringGrid1) || (Sender == StringGrid4))
 {
  if(Shift.Contains(ssLeft) && X<=StringGridTek->Left+StringGridTek->ColWidths[0] && FlagMove == false)
  {
  FlagMove = true;
  StringGridTek->BeginDrag(false,5);
  }
  if(!Shift.Contains(ssLeft)) { FlagMove = false; RowMouseDown = 0; }
  if(RowMouseDown == 0) RowMouseDown = StringGridTek->Row;
 }
 else if(Sender == StringGrid2 || Sender == StringGrid3)
 {
//   if(Shift.Contains(ssLeft) && FlagMoveLeft == false)
   if(Shift.Contains(ssLeft))
   {
//   FlagMoveLeft = true;
   StringGridTek->BeginDrag(false,5);
//   BeginRowStringGridLeft = StringGrid2->Row;
   }
 }
}
//---------------------------------------------------------------------------

void __fastcall TFormPropertyPanel::StringGrid3DragOver(TObject *Sender,
      TObject *Source, int X, int Y, TDragState State, bool &Accept)
{
TStringGrid *StringGridTek;
int KParam;
       if(Sender==StringGrid2)
       { StringGridTek=StringGrid2;  KParam = PtrFormatClass->AdresFormatNumberTek->KParamGraf; }
       else if(Sender==StringGrid3)
       { StringGridTek=StringGrid3;  KParam = PtrFormatClass->AdresFormatNumberTek->KParamTabl; }
//if(Sender != Source) Accept = true;
//else Accept = false;
Accept = true;
  if((Sender==StringGrid2 && Source == StringGrid2) ||
   (Sender==StringGrid3 && Source == StringGrid3))
  {
  RowEnd = StringGridTek->TopRow + Y/StringGridTek->RowHeights[0] - 1;
  if(RowEnd < 1) RowEnd = 1;
  if(RowEnd >= StringGridTek->RowCount)
   RowEnd = StringGridTek->RowCount - 1;
  if((StringGridTek->TopRow > 1) && (Y <= (StringGridTek->RowHeights[0]+2)))
   { StringGridTek->TopRow--;  RowEnd = StringGridTek->TopRow; }
  else if(Y >= (StringGridTek->Height -StringGridTek->RowHeights[0]/2))
   {
    if((StringGridTek->TopRow + StringGridTek->VisibleRowCount - 1) < KParam)
    {StringGridTek->TopRow++; }
   }
  }
}
//---------------------------------------------------------------------------
// Сортировка параметров в левой таблице согласно расположению шкал
void __fastcall TFormPropertyPanel::SpeedButton12Click(TObject *Sender)
{
int i,j,k,ii;
i=0;
//char *PtrNew,*PtrOld;
struct Scal *PtrPred,*PtrNew,*PtrBegin,*PtrEnd,*ScalPtr;
bool Prizn;
Prizn = false;
//ScalPtr=PtrFormatClass->AdresFormatNumberTek->AdresStructScalBegin;
k=PtrFormatClass->AdresFormatNumberTek->KPolocGoriz-1;
  for(j=0; j<PtrFormatClass->AdresFormatNumberTek->KPolocGoriz; j++)
  {
  ScalPtr=PtrFormatClass->AdresFormatNumberTek->AdresStructScalBegin;
     for(i=0; i<PtrFormatClass->AdresFormatNumberTek->KParamGraf; i++)
     {
        if(ScalPtr->begin_line == k)
        {
        PtrNew = new struct Scal;  for(ii=0; ii<sizeof(struct Scal); ii++)
        *((char *)PtrNew +ii) = *((char*)ScalPtr+ii);
        if(Prizn == true) { PtrNew->AdresPred = PtrPred; PtrPred->AdresNext = PtrNew; PtrEnd = PtrNew;}
        else { PtrBegin =  PtrNew; PtrNew->AdresPred = NULL; }
        PtrPred = PtrNew;
        Prizn = true;
        }
     if(ScalPtr->AdresNext != NULL) ScalPtr=ScalPtr->AdresNext;
     }
  k--;
  }
ScalPtr=PtrFormatClass->AdresFormatNumberTek->AdresStructScalBegin;
 for(i=0; i<PtrFormatClass->AdresFormatNumberTek->KParamGraf; i++)
 {
 PtrNew = ScalPtr;
 if(ScalPtr->AdresNext != NULL) ScalPtr=ScalPtr->AdresNext;
 delete PtrNew;
 }
PtrFormatClass->AdresFormatNumberTek->AdresStructScalBegin = PtrBegin;
PtrFormatClass->AdresStructScalBegin = PtrBegin;
PtrFormatClass->AdresStructScalEnd = PtrEnd;
PtrFormatClass->AdresStructScalTek = PtrBegin;
ScalPtr = PtrFormatClass->AdresFormatNumberTek->AdresStructScalBegin;
 for(i=0; i<PtrFormatClass->AdresFormatNumberTek->KParamGraf; i++)
 {
 StringGrid2->Cells[1][i+1] = ScalPtr->name;
 if(ScalPtr->AdresNext != NULL) ScalPtr=ScalPtr->AdresNext;
 }
 StringGrid2->Row = 1;
}
//---------------------------------------------------------------------------

void __fastcall TFormPropertyPanel::StringGrid3DragDrop(TObject *Sender,
      TObject *Source, int X, int Y)
{
TStringGrid *StringGridTek;
struct Scal *ScalPtr,*ScalPtrOld,*pred,*next;
struct Tabl *TablPtr,*TablPtrOld,*predt,*nextt;
int i,RowDragDropLeft,Count;
FlagMove = false;
       if(Sender==StringGrid2) StringGridTek=StringGrid2;
       else if(Sender==StringGrid3) StringGridTek=StringGrid3;

       if(Sender==StringGrid3 && Source == StringGrid4)
       {
       RowDragDrop =  Y/StringGridTek->RowHeights[0];
        SpeedButton6Click(this);
       }
       if(Sender==StringGrid2 && Source == StringGrid1)
       {
       RowDragDrop =  Y/StringGridTek->RowHeights[0];
       SpeedButton3Click(this);
       }

       if(Sender==StringGrid2 && Source == StringGrid2)
       {
       ScalPtrOld = PtrFormatClass->AdresStructScalTek;
       pred = ScalPtrOld->AdresPred; next = ScalPtrOld->AdresNext;
//       RowDragDropLeft =  Y/StringGridTek->RowHeights[0];
       if(pred != NULL) pred->AdresNext = next;
       else if(pred == NULL) PtrFormatClass->AdresFormatNumberTek->AdresStructScalBegin = next;
       if(next != NULL) next->AdresPred = pred;
       ScalPtr=PtrFormatClass->AdresFormatNumberTek->AdresStructScalBegin;
//       if( RowDragDropLeft >= StringGridTek->RowCount-1) RowDragDropLeft = RowDragDropLeft -2;
//       for(i=1; i<RowDragDropLeft; i++) ScalPtr=ScalPtr->AdresNext;
       if(RowEnd < StringGrid2->Row) Count = RowEnd;
       else Count = RowEnd -1;
       for(i=1; i<Count; i++) ScalPtr=ScalPtr->AdresNext;

       pred = ScalPtr->AdresPred; //next = ScalPtr->AdresNext;
       if(pred != NULL) pred->AdresNext = ScalPtrOld;
       ScalPtrOld->AdresNext = ScalPtr;
       ScalPtrOld->AdresPred = pred;
       ScalPtr->AdresPred =  ScalPtrOld;
//       if(RowDragDropLeft == 1) PtrFormatClass->AdresFormatNumberTek->AdresStructScalBegin = ScalPtrOld;
       if(RowEnd == 1) PtrFormatClass->AdresFormatNumberTek->AdresStructScalBegin = ScalPtrOld;
       ScalPtr = PtrFormatClass->AdresFormatNumberTek->AdresStructScalBegin;
       for(i=0; i<PtrFormatClass->AdresFormatNumberTek->KParamGraf; i++)
       {
//       StringGridTek->Row = i+1;
//       StringGridTek->Cells[1][StringGridTek->Row] = ScalPtr->name;
       StringGridTek->Cells[1][i+1] = ScalPtr->name;
       ScalPtr=ScalPtr->AdresNext;
       }
       StringGridTek->Row = RowEnd;
//       FlagMoveLeft = false;
//       RowDragDropLeft = 0;
        return;
       }

       if(Sender==StringGrid3 && Source == StringGrid3)
       {
       TablPtrOld = PtrFormatClass->AdresStructTablTek;
       predt = TablPtrOld->AdresPred; nextt = TablPtrOld->AdresNext;
//       RowDragDropLeft =  Y/StringGridTek->RowHeights[0];
       if(predt != NULL) predt->AdresNext = nextt;
       else if(predt == NULL) PtrFormatClass->AdresFormatNumberTek->AdresStructTablBegin = nextt;
       if(nextt != NULL) nextt->AdresPred = predt;
       TablPtr=PtrFormatClass->AdresFormatNumberTek->AdresStructTablBegin;
//       if( RowDragDropLeft >= StringGridTek->RowCount-1) RowDragDropLeft = RowDragDropLeft -2;
       if(RowEnd < StringGrid3->Row) Count = RowEnd;
       else Count = RowEnd -1;
       for(i=1; i<Count; i++)  TablPtr=TablPtr->AdresNext;
//       for(i=1; i<RowDragDropLeft; i++) TablPtr=TablPtr->AdresNext;

       predt = TablPtr->AdresPred; //nextt = TablPtr->AdresNext;
       if(predt != NULL) predt->AdresNext = TablPtrOld;
       TablPtrOld->AdresNext = TablPtr;
       TablPtrOld->AdresPred = predt;
       TablPtr->AdresPred =  TablPtrOld;
//       if(RowDragDropLeft == 1) PtrFormatClass->AdresFormatNumberTek->AdresStructTablBegin = TablPtrOld;
       if(RowEnd == 1) PtrFormatClass->AdresFormatNumberTek->AdresStructTablBegin = TablPtrOld;
       TablPtr = PtrFormatClass->AdresFormatNumberTek->AdresStructTablBegin;
       for(i=0; i<PtrFormatClass->AdresFormatNumberTek->KParamTabl; i++)
       {
//       StringGridTek->Row = i+1;
//       StringGridTek->Cells[1][StringGridTek->Row] = TablPtr->name;
       StringGridTek->Cells[1][i+1] = TablPtr->name;
       TablPtr=TablPtr->AdresNext;
       }
       StringGridTek->Row = RowEnd;
//       FlagMoveLeft = false;
       //BeginRowStringGridLeft = 0;
//       RowDragDropLeft = 0;
        return;
       }

}
//---------------------------------------------------------------------------


void __fastcall TFormPropertyPanel::ComboBox2Change(TObject *Sender)
{
/*struct Format *FormatPtr;
struct Tabl *TablPtr;
FormatPtr=PtrFormatClass->AdresFormatNumberTek;
TablPtr=FormatPtr->AdresStructTablBegin;
 while(TablPtr->AdresNext != NULL)
 { TablPtr->FormatKod = (short int)StrToInt(ComboBox2->Text); TablPtr=TablPtr->AdresNext; }
 */
}
//---------------------------------------------------------------------------



void __fastcall TFormPropertyPanel::Button1Click(TObject *Sender)
{
TablSaveNewNastr();
}
//---------------------------------------------------------------------------


void __fastcall TFormPropertyPanel::SpeedButton8Click(TObject *Sender)
{
if(StringGrid3->Row==0) return;
  FormTxtProp->Close();
  FormTxtProp->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormPropertyPanel::Button2Click(TObject *Sender)
{
struct Format *Ptr;
Ptr=PtrFormatClass->AdresFormatNumberTek;
 if(FontDialogGraf->Execute())
 {
 Ptr->FontGraf.Color = FontDialogGraf->Font->Color;
 Ptr->FontGraf.Charset = FontDialogGraf->Font->Charset;
 Ptr->FontGraf.Height = FontDialogGraf->Font->Height;
 Ptr->FontGraf.Size = FontDialogGraf->Font->Size;
 Ptr->FontGraf.Style = FontDialogGraf->Font->Style;
// Ptr->Font.Style = FontDialogGraf->Font->Style;
 strcpy(Ptr->FontGraf.Name,FontDialogGraf->Font->Name.c_str());
 }

}
//---------------------------------------------------------------------------

void __fastcall TFormPropertyPanel::SpeedButton9Click(TObject *Sender)
{
struct Format *Ptr;
Ptr=PtrFormatClass->AdresFormatNumberTek;
 if(ColorDialogBrush->Execute())
 { Ptr->ColorBrush = ColorDialogBrush->Color;  Edit9->Color=ColorDialogBrush->Color; }

}
//---------------------------------------------------------------------------

void __fastcall TFormPropertyPanel::SpeedButton10Click(TObject *Sender)
{
struct Format *Ptr;
Ptr=PtrFormatClass->AdresFormatNumberTek;
 if(ColorDialogSetka->Execute())
 { Ptr->ColorSetka = ColorDialogSetka->Color; Edit10->Color=ColorDialogSetka->Color; }

}
//---------------------------------------------------------------------------

void __fastcall TFormPropertyPanel::Button3Click(TObject *Sender)
{
struct Format *Ptr;
Ptr=PtrFormatClass->AdresFormatNumberTek;
 if(FontDialogTabl->Execute())
 {
 Ptr->FontTabl.Color = FontDialogTabl->Font->Color;
 Ptr->FontTabl.Charset = FontDialogTabl->Font->Charset;
 Ptr->FontTabl.Height = FontDialogTabl->Font->Height;
 Ptr->FontTabl.Size = FontDialogTabl->Font->Size;
 Ptr->FontTabl.Style = FontDialogTabl->Font->Style;
// Ptr->Font.Style = FontDialogTabl->Font->Style;
 strcpy(Ptr->FontTabl.Name,FontDialogTabl->Font->Name.c_str());
 }


}
//---------------------------------------------------------------------------

void __fastcall TFormPropertyPanel::Edit52Change(TObject *Sender)
{
/*int i,NCol;
TEdit *EditTek;
TStringGrid *StringGridTek;
  if(Sender==Edit57) {StringGridTek=StringGrid54; EditTek=Edit57; }
  else  if(Sender==Edit58) {StringGridTek=StringGrid53; EditTek=Edit58; }
  NCol=StringGridTek->Col;
  if(EditTek->Text.Length()==0) return;
  for(i=0; i < StringGridTek->RowCount; i++)
  {
  if(EditTek->Text ==  (StringGridTek->Cells[NCol][i]).SubString(1,(EditTek->Text).Length()))
  { StringGridTek->Row=i; break; }
  }
  */
}


void __fastcall TFormPropertyPanel::SpeedButton51Click(TObject *Sender)
{
/* if(strcmp(PtrIni->TipDataOut,"Тем. Файл Avionix TF2") == 0)
 {
  if(SaveDialog1->Execute())
  {
  strcpy(PtrSpisokClass->FileNameSpisok,SaveDialog1->FileName.c_str());
  FileNameSave = true;
  }
 }
 else if(strcmp(PtrIni->TipDataOut,"Текстовый Файл") == 0)
 {
  if(SaveDialog2Txt->Execute())
  {
  strcpy(PtrSpisokClass->FileNameSpisok,SaveDialog2Txt->FileName.c_str());
  FileNameSave = true;
  }
 }*/
}
//---------------------------------------------------------------------------
void __fastcall TFormPropertyPanel::SpeedButton52Click(TObject *Sender)
{
//if(OpenDialog2Data->Execute()) strcpy(PtrSpisokClass->FileNameSpisok,OpenDialog2Data->FileName.c_str());

}
//---------------------------------------------------------------------------
void __fastcall TFormPropertyPanel::SpeedButton56Click2(TObject *Sender)
{
//  Кнопка + Списка
//struct Format *FormatPtr;
/*struct Format *FormatPtr;
struct Message *SpisokPtr,*SpisokPtrTek;
int i,j,NCol;
 NCol=1;
FormatPtr=PtrFormatClass->AdresFormatNumberTek;
for(j=StringGrid54->Selection.Top; j<=StringGrid54->Selection.Bottom; j++)
{
 while(PtrWinSistTab->NPoleNCol[NCol] != 1 ) NCol++;
(char *)SpisokPtrTek=new char[sizeof(struct Message)];
for(i=0; i<sizeof(struct Message); i++) *((char *)SpisokPtrTek+i)='\0';

if(FormatPtr->KParamMessage == 0)
{
FormatPtr->AdresStructMessageBegin=SpisokPtrTek;
SpisokPtrTek->AdresPred=0; SpisokPtrTek->AdresNext=0;
}
else
{
SpisokPtr=FormatPtr->AdresStructMessageBegin;
 while(SpisokPtr->AdresNext != NULL) SpisokPtr=SpisokPtr->AdresNext;
SpisokPtr->AdresNext=SpisokPtrTek;
SpisokPtrTek->AdresPred=SpisokPtr;
SpisokPtrTek->AdresNext=0;
}
FormatPtr->KParamMessage++;
StringGrid53->RowCount=FormatPtr->KParamMessage+1;
StringGrid53->Cells[0][StringGrid53->RowCount-1]=StringGrid53->RowCount-1;
StringGrid53->Cells[1][StringGrid53->RowCount-1]=StringGrid54->Cells[NCol][j];
strcpy(SpisokPtrTek->ident,StringGrid53->Cells[1][StringGrid53->RowCount-1].c_str());
strcpy(SpisokPtrTek->name,SpisokPtrTek->ident);
i=0;
} */
}
//-------------------------------------------------------------------------
void __fastcall TFormPropertyPanel::SpeedButton57Click(TObject *Sender)
{
//  Кнопка - Списка
/*struct Format *FormatPtr;
struct Message *SpisokPtr,*next,*SpisokPtrTek,*SpisokPtrTekBegin,*pred;
//struct Message *SpisokPtr,*next,*SpisokPtrTek,*SpisokPtrTekBegin,*SpisokPtrTekEnd,*pred;
//struct Message *SpisokPtr,*next,*SpisokPtrTek,*SpisokPtrTekBegin,*pred;
int i;
FormatPtr=PtrFormatClass->AdresFormatNumberTek;
//  FileNameSave = false;
if(FormatPtr->KParamMessage == 0)  goto m1;
//if(FormatPtr->KParamMessage==0) goto m1;
SpisokPtr=FormatPtr->AdresStructMessageBegin;

//  if(FormatPtr->KParamMessage==1)
  if(StringGrid53->Selection.Top==1 && StringGrid53->Selection.Bottom == FormatPtr->KParamMessage)
  {
  SpisokPtrTek = SpisokPtr;
  for(i=StringGrid53->Selection.Top; i<= StringGrid53->Selection.Bottom; i++)
  { SpisokPtr=SpisokPtr->AdresNext; delete[] SpisokPtrTek; SpisokPtrTek = SpisokPtr;}
  FormatPtr->AdresStructMessageBegin->AdresNext=0;
  FormatPtr->AdresStructMessageBegin->AdresPred=0;
  FormatPtr->AdresStructMessageBegin=0;
  FormatPtr->KParamMessage=0;
  StringGrid53->RowCount=1;
  goto m1;
  }
  else
  {
  for(i=1; i< StringGrid53->Selection.Top; i++)
  SpisokPtr=SpisokPtr->AdresNext;
  SpisokPtrTekBegin=SpisokPtr;
  pred=SpisokPtr->AdresPred;
  SpisokPtr=FormatPtr->AdresStructMessageBegin;
  for(i=1; i< StringGrid53->Selection.Bottom; i++) SpisokPtr=SpisokPtr->AdresNext;
//  SpisokPtrTekEnd=SpisokPtr;
  next=SpisokPtr->AdresNext;
  SpisokPtr=SpisokPtrTek=SpisokPtrTekBegin;
  for(i=StringGrid53->Selection.Top; i<= StringGrid53->Selection.Bottom; i++)
  { SpisokPtr=SpisokPtr->AdresNext; delete[] SpisokPtrTek; SpisokPtrTek = SpisokPtr;}

    if(StringGrid53->Selection.Top==1)
    {
    SpisokPtr=next; SpisokPtr->AdresPred=0;
    FormatPtr->AdresStructMessageBegin=next;
    FormatPtr->AdresStructMessageBegin->AdresPred=0;
    SpisokPtr=FormatPtr->AdresStructMessageBegin;
    }
    else if(StringGrid53->Selection.Bottom == (StringGrid53->RowCount-1))
    {
    SpisokPtr=pred;
    SpisokPtr->AdresNext=0;
    }
    else
    {
    SpisokPtr=next; SpisokPtr->AdresPred=pred;
    SpisokPtr=pred; SpisokPtr->AdresNext=next;
    }
  }
FormatPtr->KParamMessage = FormatPtr->KParamMessage - (StringGrid53->Selection.Bottom - StringGrid53->Selection.Top +1);
SpisokPtr=FormatPtr->AdresStructMessageBegin;
 for(i=1; i<=FormatPtr->KParamMessage; i++)
 {
 StringGrid53->Cells[0][i]=i;
 StringGrid53->Cells[1][i]=SpisokPtr->ident;
 SpisokPtr=SpisokPtr->AdresNext;
 }
StringGrid53->RowCount=FormatPtr->KParamMessage+1;
m1:

*/
}
//---------------------------------------------------------------------------
void __fastcall TFormPropertyPanel::SpeedButton58Click(TObject *Sender)
{
/*struct Format *FormatPtr;
struct Message   *SpisokPtr;
int i;
FormatPtr=PtrFormatClass->AdresFormatNumberTek;
 if(StringGrid53->RowCount > 1)
 {
//  FileNameSave = false;
 SpisokPtr=FormatPtr->AdresStructMessageBegin;
 for(i=1; i<StringGrid53->Row; i++)
 SpisokPtr=SpisokPtr->AdresNext;
// PtrSpisokClass->AdresStructSpisokTek = SpisokPtr;
 PtrWinSistTab->AdresParamProperty=(void *)SpisokPtr;
  FormMessage->Close();
  FormMessage->Show();
 }*/
}
//---------------------------------------------------------------------------
void __fastcall TFormPropertyPanel::StringGrid53DragDrop(TObject *Sender,
      TObject *Source, int X, int Y)
{
//SpeedButton6Click(this);
//FlagMove = false;
/*SpeedButton56Click2(this);*/
}
//---------------------------------------------------------------------------
void __fastcall TFormPropertyPanel::StringGrid53DragOver(TObject *Sender,
      TObject *Source, int X, int Y, TDragState State, bool &Accept)
{
/*if(Sender != Source) Accept = true;
else Accept = false;
*/
}
//---------------------------------------------------------------------------
void __fastcall TFormPropertyPanel::StringGrid53SelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
/*struct Format *FormatPtr;
struct Message   *SpisokPtr;
int NCol,NStrok,i;
 NCol=1;
//if(ARow==1){SpeedButton2->Enabled=false;}  else {SpeedButton2->Enabled=true;}
//if(ARow>=(StringGrid2->RowCount-1)){SpeedButton1->Enabled=false; ARow=StringGrid2->RowCount-1;}
//                              else {SpeedButton1->Enabled=true;}

FormatPtr=PtrFormatClass->AdresFormatNumberTek;
if((ACol==0) || (ARow==0)){ CanSelect=false; return; } else CanSelect=true;
  while(PtrWinSistTab->NPoleNCol[NCol] !=1 ) NCol++;
 NStrok=1;
  while(StringGrid53->Cells[1][ARow] != StringGrid54->Cells[NCol][NStrok] )
  {
  NStrok++;
   if( NStrok == StringGrid54->RowCount ) { MessageBox(NULL,"Параметр отсутствует в Базе ","Список ",MB_ICONINFORMATION); return; }

  }
 StringGrid54->Col=NCol; StringGrid54->Row=NStrok;

 SpisokPtr=FormatPtr->AdresStructMessageBegin;
for(i=1; i<ARow; i++)
SpisokPtr=SpisokPtr->AdresNext;
//PtrSpisokClass->AdresStructSpisokTek = SpisokPtr;
  PtrWinSistTab->AdresParamProperty=(void *)SpisokPtr;
  FormMessage->Close();
  FormMessage->Show();
  */
}
//-----------------------------------------------------------------------

void __fastcall TFormPropertyPanel::Edit52Change2(TObject *Sender)
{
/*int i,NCol;
TEdit *EditTek;
TStringGrid *StringGridTek;
 if(Sender==Edit57) {StringGridTek=StringGrid54; EditTek=Edit57; }
 else  if(Sender==Edit58) {StringGridTek=StringGrid53; EditTek=Edit58; }
  NCol=StringGridTek->Col;
  if(EditTek->Text.Length()==0) return;
  for(i=0; i < StringGridTek->RowCount; i++)
  {
  if(EditTek->Text ==  (StringGridTek->Cells[NCol][i]).SubString(1,(EditTek->Text).Length()))
  { StringGridTek->Row=i; break; }
  }
//  if(Edit1->Text==StringGrid1->Cells[1][i])  StringGrid1->Row=i;  // AnsiString
  */
}
//---------------------------------------------------------------------------
void __fastcall TFormPropertyPanel::SpeedButton56Click22(TObject *Sender)
{
//  Кнопка + Списка
/*struct Format *FormatPtr;
struct Message *SpisokPtr,*SpisokPtrTek;
int i,j,NCol;
//TGridRect MyRect;
//MyRect = StringGrid54->Selection;
//FormatPtr=PtrFormatClass->AdresFormatNumberTek;
 NCol=1;
FormatPtr=PtrFormatClass->AdresFormatNumberTek;
//FileNameSave = false;
for(j=StringGrid54->Selection.Top; j<=StringGrid54->Selection.Bottom; j++)
{
 while(PtrWinSistTab->NPoleNCol[NCol] != 1 ) NCol++;
(char *)SpisokPtrTek=new char[sizeof(struct Message)];
for(i=0; i<sizeof(struct Message); i++) *((char *)SpisokPtrTek+i)='\0';

if(FormatPtr->KParamMessage==NULL)
{
FormatPtr->AdresStructMessageBegin=SpisokPtrTek;
SpisokPtrTek->AdresPred=0; SpisokPtrTek->AdresNext=0;
}
else
{
SpisokPtr=FormatPtr->AdresStructMessageBegin;
 while(SpisokPtr->AdresNext != NULL) SpisokPtr=SpisokPtr->AdresNext;
SpisokPtr->AdresNext=SpisokPtrTek;
SpisokPtrTek->AdresPred=SpisokPtr;
SpisokPtrTek->AdresNext=0;
}
FormatPtr->KParamMessage++;
//PtrFormatClass->KParamSpisok++;
StringGrid53->RowCount=FormatPtr->KParamMessage+1;
StringGrid53->Cells[0][StringGrid53->RowCount-1]=StringGrid53->RowCount-1;

//strcpy(SpisokPtrTek->ident,StringGrid54->Cells[2][StringGrid54->Row].c_str());
//strcpy(SpisokPtrTek->sistema,StringGrid54->Cells[1][StringGrid54->Row].c_str());
//strcpy(SpisokPtrTek->ident,StringGrid54->Cells[PtrWinSistTab->NColNPole[1]][StringGrid54->Row].c_str());
//strcpy(SpisokPtrTek->ident,StringGrid54->Cells[PtrFileDatInpClass->MasNPoleNCol[0]+1][StringGrid54->Row].c_str());
//strcpy(SpisokPtrTek->sistema,StringGrid54->Cells[PtrFileDatInpClass->MasNPoleNCol[1]+1][StringGrid54->Row].c_str());
//StringGrid53->Cells[1][StringGrid53->RowCount-1]=SpisokPtrTek->ident;

StringGrid53->Cells[1][StringGrid53->RowCount-1]=StringGrid54->Cells[NCol][j];
strcpy(SpisokPtrTek->ident,StringGrid53->Cells[1][StringGrid53->RowCount-1].c_str());
//StringGrid53->Cells[1][StringGrid53->RowCount-1]=StringGrid54->Cells[NCol][StringGrid54->Row];
//strcpy(SpisokPtrTek->ident,StringGrid54->Cells[NCol][StringGrid54->Row].c_str());
strcpy(SpisokPtrTek->name,SpisokPtrTek->ident);
i=0;
} */
}
//-------------------------------------------------------------------------
void __fastcall TFormPropertyPanel::StringGrid54ColumnMoved(TObject *Sender,
      int FromIndex, int ToIndex)
{
/*short int FromNPole,k;
int i;
 FromNPole=PtrWinSistTab->NPoleNCol[FromIndex];
 i=FromIndex;
if(FromIndex > ToIndex)
{
 for(k=0; k<(FromIndex-ToIndex); k++)
 {
 PtrWinSistTab->NPoleNCol[i]=PtrWinSistTab->NPoleNCol[i-1];
 i--;
 }
}
else if(FromIndex < ToIndex)
{
 for(k=0; k<(ToIndex-FromIndex); k++)
 {
 PtrWinSistTab->NPoleNCol[i]=PtrWinSistTab->NPoleNCol[i+1];
 i++;
 }
}
 PtrWinSistTab->NPoleNCol[ToIndex]=FromNPole;
// PtrWinSistTab->NColNPole[FromNPole]=ToIndex;
if((ToIndex == 1) || (FromIndex == 1)) SortPolei((TStringGrid *)Sender);
*/
}
//---------------------------------------------------------------------------
void __fastcall TFormPropertyPanel::StringGrid54MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
/*//TGridRect MyRect;
//if((Button == mbLeft) && Shift.Contains(ssAlt))
if(Shift.Contains(ssLeft) && X<=StringGrid54->Left+StringGrid54->ColWidths[0] && FlagMove == false)
{
FlagMove = true;
StringGrid54->BeginDrag(false,5);
//MyRect = StringGrid54->Selection;
}
  */
}
//-----------------------------------------------------------------------


void __fastcall TFormPropertyPanel::StringGrid2MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
//int i;
//i=0;
/*TStringGrid *StringGridTek;
       if(Sender==StringGrid1) StringGridTek=StringGrid1;
       else if(Sender==StringGrid4) StringGridTek=StringGrid4;
//if(Shift.Contains(ssLeft) && FlagMove == false)
if(Shift.Contains(ssLeft) && X<=StringGridTek->Left+StringGridTek->ColWidths[0] && FlagMove == false)
{
FlagMove = true;
StringGridTek->BeginDrag(false,5);
}
if(!Shift.Contains(ssLeft)) { FlagMove = false; RowMouseDown = 0; }
//else  FlagMove = false;
if(RowMouseDown == 0) RowMouseDown = StringGridTek->Row;
  */
}
//---------------------------------------------------------------------------


void __fastcall TFormPropertyPanel::SpeedButton11Click(TObject *Sender)
{
struct Format *FormatPtr;
struct Tabl *TablPtr,*TablPtrTek,*TablPtrOld;
//struct TablArg *ScalArgPtr;
int i,j,jj,NCol;
 NCol=1;
 while(PtrWinSistTab->NPoleNCol[NCol] != 1 ) NCol++;
FormatPtr=PtrFormatClass->AdresFormatNumberTek;
for(j=StringGrid3->Selection.Top; j<=StringGrid3->Selection.Bottom; j++)
{
TablPtr=FormatPtr->AdresStructTablBegin;
for(i=1; i<j; i++) TablPtr=TablPtr->AdresNext;
TablPtrOld = TablPtr;
PtrFormatClass->AdresStructTablTek=TablPtr;
(char *)TablPtrTek=new char[sizeof(struct Tabl)];
for(i=0; i<sizeof(struct Tabl); i++) { *((char *)TablPtrTek+i)='\0'; *((char *)TablPtrTek+i) = *((char *)TablPtr+i); }
  i=0;
  while(strcmpi((PtrPasp+i)->Ident,TablPtrTek->ident) != 0) i++;
  for(jj=0; jj<KSISTEMMAX; jj++)
  {if((PtrPasp+i)->NSis[jj] == FormatPtr->NSis) {TablPtrTek->NSis = FormatPtr->NSis; break; }}
while(TablPtr->AdresNext != NULL) TablPtr=TablPtr->AdresNext;
TablPtr->AdresNext=TablPtrTek;
TablPtrTek->AdresPred=TablPtr;
TablPtrTek->AdresNext=0;
FormatPtr->KParamTabl++;
PtrFormatClass->AdresStructTablTek=TablPtrTek;
StringGrid3->RowCount=FormatPtr->KParamTabl+1;
StringGrid3->Cells[0][StringGrid3->RowCount-1]=StringGrid2->RowCount-1;
StringGrid3->Cells[1][StringGrid3->RowCount-1]="копия";
StringGrid3->Cells[1][StringGrid3->RowCount-1]=StringGrid3->Cells[1][StringGrid3->RowCount-1] + TablPtrOld->name;
strcpy(TablPtrTek->name,StringGrid2->Cells[1][StringGrid3->RowCount-1].c_str());
StringGrid3->Cells[NCol][j];
}

}
//---------------------------------------------------------------------------




void __fastcall TFormPropertyPanel::StringGrid1SelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
struct RK *PtrArincRK;
struct RK *PtrRK;
//char *Ident,*Adr,buf_tek[16];
char *Adr;
int i,j,NCol;
AnsiString S;
TStringGrid *StringGridTek;           // 2008_03_22
StringGridTek = (TStringGrid *)Sender;              // 2008_03_22
if(StringGridTek == StringGrid1) ListBox1->Parent = Panel13;     // 2008_03_22
else if(StringGridTek == StringGrid4) ListBox1->Parent = Panel21; // 2008_03_22
ListBox1->Left = StringGridTek->Width/4; ListBox1->Top = StringGridTek->Height/4; // 2008_03_22
 i=0; NCol = 1;
  while(PtrWinSistTab->NPoleNCol[NCol] !=1 ) NCol++;
 while(strcmp((PtrPasp+i)->Ident,StringGridTek->Cells[NCol][ARow].c_str()) != 0) i++;           // 2008_03_22
// while(strcmp((PtrPasp+i)->Ident,StringGrid1->Cells[NCol][ARow].c_str()) != 0) i++;
  switch((PtrPasp+i)->Tip)
  {
  case 22:
  ListBox1->ItemIndex = -1; //ListBox1->Text ="\0";
  PtrArincRK = &PtrBlokRK[(PtrPasp+i)->NRK1];
  ListBox1->Items->Clear();
  for(j=0; j<24; j++) ListBox1->Items->Add(j+9);
  for(j=0; j<(PtrPasp+i)->KRK; j++)
   {
  Adr = PtrArincRK->Name;
  ListBox1->Items->Strings[PtrArincRK->NRazRK-9] = ListBox1->Items->Strings[PtrArincRK->NRazRK-9]+"  " +Adr;
//  PtrArincRK++;    // 2009_12_12
   if(j < ((PtrPasp+i)->KRK - 1)) PtrArincRK = &PtrBlokRK[PtrArincRK->NRK_SL];     // 2009_12_12
   }
  ListBox1->Height = ListBox1->Font->Size*25*2;
  ListBox1->Width = ListBox1->Font->Size*64;
  TipRK = 22; ListBox1->Visible = true;                   // TString
  break;
  case 11:
  ListBox1->ItemIndex = -1; //ListBox1->Text ="\0";
//  ListBox1->Count=12; //ComboBox1->Width=Width1*2;
  PtrRK = &PtrBlokRK[(PtrPasp+i)->NRK1];
//  PtrRK = (struct RK *)&PtrBlok_tar[(PtrPasp+i)->index_tar];
  ListBox1->Items->Clear();
  for(j=0; j<12; j++) ListBox1->Items->Add(j+1);
//  for(j=0; j<PtrRK->KRK; j++)
  for(j=0; j<(PtrPasp+i)->KRK; j++)
   {
  if(PtrRK->NRazRK < 1 || PtrRK->NRazRK > 12) { PtrRK++; continue; }
  Adr = PtrRK->Name;
  ListBox1->Items->Strings[PtrRK->NRazRK-1] = ListBox1->Items->Strings[PtrRK->NRazRK-1]+"  " +Adr;
//  PtrRK++;       // 2009_12_12
   if(j < ((PtrPasp+i)->KRK - 1)) PtrRK = &PtrBlokRK[PtrRK->NRK_SL];     // 2009_12_12
   }
  ListBox1->Height = ListBox1->Font->Size*13*2;
  ListBox1->Width = ListBox1->Font->Size*64;
  TipRK = 11;  ListBox1->Visible = true;
  break;
  default :
  NRazrRK = 0; ListBox1->Visible = false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormPropertyPanel::ListBox1DblClick(TObject *Sender)
{
 if(ListBox1->ItemIndex != -1)
 {
 if(TipRK == 22)  NRazrRK = ListBox1->ItemIndex + 9;
 else if(TipRK == 11)  NRazrRK = ListBox1->ItemIndex + 1;
 else   NRazrRK = 0;
 if(PageControl1->ActivePage==TabSheet2)       SpeedButton3Click(this);   //Графики   // 2008_03_22
 else if(PageControl1->ActivePage==TabSheet4)  SpeedButton6Click(this); //Таблицы      // 2008_03_22                    // 2008_03_22
// SpeedButton3Click(this);
 }
}
//---------------------------------------------------------------------------




void __fastcall TFormPropertyPanel::FormKeyPress(TObject *Sender,
      char &Key)
{
 if(PageControl1->ActivePage==TabSheet2)          //Графики   // 2008_03_22
  {if(Key == VK_ESCAPE && ListBox1->Visible == true) {StringGrid1->SetFocus();ListBox1->SetFocus(); ListBox1->Visible = false;}}
 else if(PageControl1->ActivePage==TabSheet4)   //Таблицы      // 2008_03_22
  {if(Key == VK_ESCAPE && ListBox1->Visible == true) {StringGrid4->SetFocus();ListBox1->SetFocus(); ListBox1->Visible = false;}}
//if(Key == VK_ESCAPE && ListBox1->Visible == true) {StringGrid1->SetFocus();ListBox1->SetFocus(); ListBox1->Visible = false;}

}
//---------------------------------------------------------------------------

void __fastcall TFormPropertyPanel::FormActivate(TObject *Sender)
{
//PtrFormatClass = PtrFormatClassM[PtrFlagPotokVizual->NumberClassFormat];

}
//---------------------------------------------------------------------------
void __fastcall TFormPropertyPanel::RadioButton11Click(TObject *Sender)
{
if(RadioButton12->Checked == true) Edit4->Enabled = false;      // 2007_12_04

}
//---------------------------------------------------------------------------

void __fastcall TFormPropertyPanel::RadioButton12Click(TObject *Sender)
{
if(RadioButton11->Checked == true) Edit4->Enabled = true; // 2007_12_04

}
//---------------------------------------------------------------------------

