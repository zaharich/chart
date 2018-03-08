//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
                                                                             
#include "Maint.h"
#include "Chart.h"                    // Хромцов 2013_07_15
#include "Unit_Properties.h"
#include "UnitSettingsAxis.h"
#include "Parametr.h"
#include "UnitAbout.h"
#include "UnitFormRashet.h"
#include "FileClassRashetParam.h"
#include "LibraryFile.h"


#include <stdio.h>
#include <dir.h>
#include <stdlib.h>
#include <shellapi.hpp>
#include "TeeAbout.hpp"
#include "teestore.hpp"
#include <string>
#include <math.h>
#include "teeprevi.hpp"
#include "Teengine.hpp"
#include "Inset.h"
#include <iostream.h>
#include <fstream.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TeeComma"
#pragma link "TeeScroB"
#pragma link "TeeChartGrid"
#pragma link "TeePageNumTool"
#pragma link "TeeTools"
#pragma link "CSPIN"
#pragma link "TeeEdit"
#pragma link "TeeChartActions"
#pragma link "CGAUGES"
#pragma link "TeeOpenGL"
#pragma resource "*.dfm"
 struct IndexBlocFileDatXX IndexBlocFileDatXX; // Хромцов 2013_07)15
 struct Razdel *PtrRazdel;                     // Хромцов 2013_07)15
 struct PaspChart *PtrPaspChart;               // Хромцов 2013_07)15
 //struct Chart_Ini Chart_Ini;                   //  2013_10_11
 struct RKChart *PtrRKChart;                   //  2013_10_11
 struct ParamXX *PtrParamXXChart;              //  2013_10_11
 struct TimXX TimXX;                           //  2013_10_11
 struct GlobalFlagChart GlobalFlagChart, *PtrGlobalFlagChart;   // Хромцов 2013_07_15
 struct Global Global = {0, -1, true, NULL};                      // Захарчук 2013_10_23
 
 TForm1 *Form1;
 Parametr *Par[MKSERIES];
 bool showForm = 0;

 AnsiString CustomIniFile::dataDir = "C:\\";
 AnsiString CustomIniFile::formatDir = "C:\\";
 AnsiString CustomIniFile::iniDir = "C:\\";
 AnsiString CustomIniFile::libDir = "C:\\";


//---- сужает график по оси Х(по максимальной длине серии), чтобы не было пустых зон
void GripeChart()
{
 double max = 0, min = 1;
 for(int i=1; i<Form1->Chart1->SeriesCount(); i++)
 {
    TChartSeries *Series = Form1->Chart1->SeriesList->Items[i];
    double a = Series->MinXValue(), b = Series->MaxXValue();
    min = (min < a) ? min : a;
    max = (max > b) ? max : b;
 }
 if( max < min )
 {
    max = Form1->SourseMaxTime*SEC;
    min = Form1->SourseMinTime*SEC;
 }
 Form1->Chart1->BottomAxis->SetMinMax(min, max);
 Form1->Chart1->BottomAxis->Increment = (max - min)/Form1->countMainVertLine;
}


// переводит время (hh:mm:ss) в количество секунд ---------------------------
int TimeToInt(const AnsiString& S)
{
   int n = S.Pos(":");
   if(!n)
      return -1;
   AnsiString s1 = S.SubString(0, n-1);
   int hou = StrToInt(s1);

   AnsiString s2 = S.SubString(n+1, 255);
   n = s2.Pos(":");
   if(!n)
      return -1;
   s1 = s2.SubString(0, n-1);
   int min = StrToInt(s1);
   s2 = s2.SubString(n+1, 255);

   int sec = StrToInt(s2);

   return (hou*3600 + min*60 + sec);
}


//============================================================================
void ChartInit(TChart& Chart)
{
   Chart.Align = alClient;
   Chart.BottomAxis->DateTimeFormat = "HH:mm:ss";
   Chart.BottomAxis->Axis->Width = 1;
   Chart.BottomAxis->Automatic = false;
   Chart.BottomAxis->SetMinMax(Form1->SourseMinTime*SEC, Form1->SourseMaxTime*SEC);
   Chart.BottomAxis->Increment = (Form1->SourseMaxTime - Form1->SourseMinTime)*
                                                  SEC/Form1->countMainVertLine;
   Chart.BottomAxis->RoundFirstLabel = false;
   Chart.BottomAxis->LabelsSize = 1;

   Chart.LeftAxis->Axis->Width = 1;
   Chart.LeftAxis->Automatic = false;
   Chart.LeftAxis->SetMinMax(0, LEFTAXIS);
   Chart.LeftAxis->Increment = 5;
   Chart.LeftAxis->LabelsFont->Color = Form1->Chart1->Color;

   Chart.MarginTop = 2; Form1->Chart1->MarginBottom = 3;
   Chart.MarginRight = 3; Form1->Chart1->MarginLeft = 10;

   Chart.View3D = false;
}


//---------------------------------------------------------------------------
void TForm1::LinkToGrid(TChartAxis *Axis)
{
   double delta = Chart1->LeftAxis->Increment;
   double LengthAxisInProcent = Axis->EndPosition - Axis->StartPosition;
   int a = (Axis->StartPosition + 0.5 * delta) / delta;
   Axis->StartPosition = a * delta;
   Axis->EndPosition = a * delta + LengthAxisInProcent;
}


//---------------------------------------------------------------------------
void TForm1::LoadEdit()
{
   if(Chart1->Title->Text->Strings[0] == "TChart")
      return;
   for(int i = 0; i < 3; ++i)
   {
      label[i] = new TLabel(Chart1);
      label[i]->Parent      = Chart1;
      label[i]->OnMouseDown = LabelExample->OnMouseDown;
      label[i]->OnMouseMove = LabelExample->OnMouseMove;
      label[i]->OnMouseUp   = LabelExample->OnMouseUp;
      label[i]->OnDblClick  = LabelExample->OnDblClick;
      label[i]->PopupMenu   = LabelPopupMenu;
      AnsiString st = Chart1->Title->Text->Strings[i];

      int pos1 = st.Pos("$")-1;        //  позиция первого разделителя $; -1 чтобы не захватывать $ разделитель
      AnsiString buff_st = st.SubString(0, pos1);
      label[i]->Visible = buff_st.ToInt();    // Visible
      st = st.SubString(pos1+2, 255);                 // +2 чтобы не захватывать разделитель $

      pos1 = st.Pos("$")-1;
      buff_st = st.SubString(0, pos1);
      label[i]->Caption = buff_st;            // Text
      st = st.SubString(pos1+2, 255);

      pos1 = st.Pos(" ")-1;
      buff_st = st.SubString(0, pos1);
      label[i]->Left = buff_st.ToInt();       // Left
      st = st.SubString(pos1+2, 255);

      label[i]->Top = st.ToInt();             // Top
   }

   // вытаскиваем время из subTitle
   String str = Chart1->SubTitle->Text->Strings[0];
   int pos1 = str.Pos("$") - 1;
   double min = StrToFloat(str.SubString(0, pos1));
   double max = StrToFloat(str.SubString(pos1 + 2, 255));

   if(min < SourseMinTime*SEC || max > SourseMaxTime*SEC)
   {
      Chart1->BottomAxis->SetMinMax(SourseMinTime * SEC, SourseMaxTime * SEC);
      //Chart1->BottomAxis->Increment = ((SourseMaxTime - SourseMinTime) * SEC) /
                                                        countMainVertLine;
   }
   else
   {
      Chart1->BottomAxis->SetMinMax(min, max);
      //Chart1->BottomAxis->Increment = (max - min) / countMainVertLine;
   }

   // пропорционально времени ставим бар снизу
   SetTimeBar(min / SEC, max / SEC);
}


//---------------------------------------------------------------------------
void TForm1::DrawEndIdents()
{
   /*for(int i=0; i<Form1->KolSeries; i++){
      Line[i] = (TFastLineSeries *)Form1->Chart1->SeriesList->Items[i+1];
      if(! Line[i]->Count())
         return;
      Axis[i] = Form1->Chart1->CustomAxes->Items[i];
      if(Button){
         //Form1->Chart1->Canvas->Font->PixelsPerInch = (Form1->Edit2->Text).ToInt();
         //Form1->Chart1->Canvas->Font->Size = (Form1->Edit5->Text).ToInt();
         //Form1->Chart1->Canvas->Font->Height = (Form1->Edit7->Text).ToInt();
      }
      double YValue = Line[i]->CalcYPos(Line[i]->LastDisplayedIndex());
      double XValue = Line[i]->CalcXPos(Line[i]->LastDisplayedIndex());
      Form1->Chart1->Canvas->Font->Color = Line[i]->Pen->Color;
      Form1->Chart1->Canvas->TextOut(XValue+10, YValue-10, Axis[i]->Title->Caption);
   }  */
}


//---------------------------------------------------------------------------
void TForm1::DeleteParametr(int& n)
{
   // если серия еще не построна
   if(Par[n]->Series->Count() < 1)
      --Form1->knp;

   delete Par[n];
   Par[n] = NULL;

   --Global.KolSeries;
   Global.NumTekPar = -1;
}


//---------------------------------------------------------------------------
void TForm1::DeleteAllParameters()
{
 for(int i = 0; i < MKSERIES; ++i)
     if(Par[i] != NULL)
        DeleteParametr(i);
}


//---------------------------------------------------------------------------
void TForm1::CreateParametr(int numPasp)
{
  //---- подбор NUM
  int NUM = -1;
  for(int i = 0; i < MKSERIES + 1; ++i)
     if(Par[i] == NULL)
     {
        NUM = i;
        break;
     }
  if(NUM == -1)
  {
     ShowMessage("Ошибка в подборе номера классу Par");
     return;
  }

  Par[NUM] = new Parametr(NUM, numPasp);
  if(Par[NUM]->KolSis > 1)
     Par[NUM]->Axis->Title->Caption = Par[NUM]->Axis->Title->Caption + " "
                                                + StrToInt(Par[NUM]->NSis);

  Chart1->AddSeries(Par[NUM]->Series);
  ++Global.KolSeries;
  ++knp;
}


//---------------------------------------------------------------------------
void TForm1::OpenChartFromFile(const AnsiString& TeeName)
{
 if( !FileExists(iniFile->DataFile) || iniFile->DataFile == "")
 {
     ShowMessage("Полетного файла " + iniFile->DataFile + " не существует!");
     return;
 }

 if( !FileExists(TeeName))
 {
     ShowMessage("Файла " + TeeName + " не существует! Проверьте правильность ввода");
     return;
 }

 LoadChartFromFile(dynamic_cast<TCustomChart*>(Chart1), TeeName);               // загрузка файла *.tee

 Form1->PanelStart->Width = Form1->PanelStart->Constraints->MinWidth;
 Form1->PanelEnd->Width = Form1->PanelEnd->Constraints->MinWidth;

 LoadEdit();
 knp = Chart1->SeriesList->Count - 1;                                           // Series1 не является
 Global.KolSeries = knp;                                                        // серией с параметром
 int falseKnp = 0;

 for(int i = 0; i < knp; ++i)
 {
     Par[i] = new Parametr();
     Par[i]->Series = (TFastLineSeries*)Chart1->SeriesList->Items[i+1];
     Par[i]->Axis = Chart1->CustomAxes->Items[i];
     Par[i]->BuildSeries = ( Par[i]->Series->Count() ) ? true : false;
     if(Par[i]->Series->Count())                                                // если серия построена
         ++falseKnp;                                                            // то позже редактируем Кнп с помощью falseKnp
     Par[i]->CreateMemo(i, Chart1->CustomAxes->Items[i]->Axis->Color,
                            Chart1->CustomAxes->Items[i]->Title->Caption);
     Par[i]->LoadSeriesTitle();
     Par[i]->Axis->Title->Visible = false;                                      // 25-04-14 zakharchuk
     Par[i]->NPasp = Par[i]->GetNPasp(Par[i]->Series->Title,
                                          IndexBlocFileDatXX.KStructPaspChart);
     // нужно заполнять количество систем
     Par[i]->KolSis = 0;
     for(int j = 0; j < 4; ++j)
         if((PtrPaspChart + Par[i]->NPasp)->NSis[j] != -1)
             ++Par[i]->KolSis;
 }

 knp = knp - falseKnp;
 Global.NumTekPar = -1;

 if(Chart1->SubTitle->Text->Strings[1].SubString(1, 1) == 1)
 {
     if(Chart1->SubTitle->Text->Strings[1].SubString(2, 1) == 0)
         FastBuilt();
     else
         Built();
 }
}


//---------------------------------------------------------------------------
void TForm1::ChartToFile(const AnsiString& pathToTeeFile, bool includeData, bool textFormat)
{
 //---  SaveEdit ----
 Chart1->Title->Clear();
 for(int i = 0; i < 3; ++i)
     Chart1->Title->Text->Add(AnsiString(IntToStr(label[i]->Visible) + "$" +
     label[i]->Caption + "$" + label[i]->Left + " " + label[i]->Top));
 delete [] label;
 Chart1->SubTitle->Text->Strings[0] = FloatToStr(Chart1->BottomAxis->Minimum)
                                + "$" + FloatToStr(Chart1->BottomAxis->Maximum);
 //------------------

 for(int i = 0; i < MKSERIES; ++i)        // перед сохранением NSis ставим в Title
 {
    if(Par[i] != NULL)
       Par[i]->SaveSeriesTitle();
 }
 SaveChartToFile(Chart1, pathToTeeFile, includeData, textFormat);
}


//---------------------------------------------------------------------------
void TForm1::LoadFlyingFile(const AnsiString& PathToFlyingFile)
{
   //---  Загрузка полетных данных из файла *.48ХХ
   Global.strData = fopen(PathToFlyingFile.c_str(), "rb");
   if(Global.strData == NULL)
   {
      ShowMessage("Полетного файла " + PathToFlyingFile + " не найдено!");
      return;
   }
   iniFile->DataFile = PathToFlyingFile;

   fread(&IndexBlocFileDatXX, sizeof(IndexBlocFileDatXX), 1, Global.strData);

   PtrRazdel = new struct Razdel[IndexBlocFileDatXX.KStructRazdel];
   fread(PtrRazdel, sizeof(Razdel),IndexBlocFileDatXX.KStructRazdel, Global.strData);

   PtrPaspChart = new struct PaspChart[IndexBlocFileDatXX.KStructPaspChart];
   fread(PtrPaspChart, sizeof(PaspChart),IndexBlocFileDatXX.KStructPaspChart, Global.strData);

   PtrRKChart = new struct RKChart[IndexBlocFileDatXX.KStructRKChart];
   fread(PtrRKChart, sizeof(RKChart), IndexBlocFileDatXX.KStructRKChart, Global.strData);

   SourseMinTime = IndexBlocFileDatXX.TimeBegin;
   SourseMaxTime = IndexBlocFileDatXX.TimeEnd;

   if(iniFile->Format == "")
      Form1->knp = 0;

   FileListBox1->Directory = SourseDir + "\\Режимы\\";
   LabelStartTime->Caption = ((TDateTime)Chart1->BottomAxis->Minimum).TimeString();
   LabelEndTime->Caption = ((TDateTime)Chart1->BottomAxis->Maximum).TimeString();
   iniFile->DataFile = PathToFlyingFile;
   Caption = "ChartPro   " + PathToFlyingFile;

   CreateSmallFile();
}




//==========  enter in programm  =========================================


//-------------------------------------------------------------------------
//                 Перед созданием главной формы
//-------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
        , countMainVertLine(10)
        , SourseWidth(PanelScroll->Width)
{
 char tmp[255];
 GetCurrentDirectory(255, tmp);
 SourseDir = tmp;

 Global.KolSeries = 0;

 Series1 = new TFastLineSeries(Form1->Chart1);        // без Series1 не будет
 Series1->ParentChart = this->Chart1;                 // горизонтальных линий
 this->Chart1->AddSeries(Series1);                    // сетки
 Series1->XValues->DateTime = true;                   //

 Chart1->Title->Clear();                                                         // need create class customEdit
 for(int i = 0; i < 3; ++i)
 {                                             // создание Edit-ов для надписей
    label[i] = new TLabel(Chart1);             // на диаграмме
    label[i]->Parent = Chart1;
    label[i]->Visible = false;
    label[i]->Caption = "Текст " + IntToStr(i);
    label[i]->OnMouseDown = LabelExample->OnMouseDown;
    label[i]->OnMouseMove = LabelExample->OnMouseMove;
    label[i]->OnMouseUp = LabelExample->OnMouseUp;
    label[i]->OnDblClick = LabelExample->OnDblClick;
    Chart1->Title->Text->Add(IntToStr(0) + "$" + "Текст" + "$" +
                                              IntToStr(0) + " " + IntToStr(0));
 }

 Chart1->SubTitle->Text->Add(0);
 Chart1->SubTitle->Text->Add(0);
}

//-----------------------------------------------------------------------------
//  После активации формы
//-----------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender)
{
 static bool flag = false;                                                      // флаг нужен чтобы код сработал
 if(flag)                                                                       // только при 1-ом запуске программы
     return;
 PtrGlobalFlagChart = &GlobalFlagChart;
 WindowState = wsMaximized;
 Global.canResize = true;

 iniFileNameMain = SourseDir + "\\Chart.ini";
 iniFileMain = new TIniFile(iniFileNameMain);

 AnsiString iniFileNameAny = iniFileMain->ReadString("Files", "LastFileIni", "");
 //*** создать iniFile необходимо в любом случае, т.к. программа пойзже ***//
 // обращается к этому файлу !                                          ***//

 if(FileExists(iniFileNameAny))
 {
     iniFile = new CustomIniFile(iniFileNameAny);
     if(iniFile->fileError)
     {
         ChartInit(*Chart1);
         AddTab(SourseDir + "\\Temp\\Новая_вкладка.tee");
     }
     else
     {
         LoadFlyingFile(iniFile->DataFile);
         OpenFormat(iniFile->Format);
     }
 }

 else  // Используется файл по умолчанию
 {
     AnsiString iniFileDefault = SourseDir + "\\INI\\iniFileDefault.ini";
     if(! FileExists(iniFileDefault))
     {
         FILE* F;
         if((F = fopen(iniFileDefault.c_str(), "w+")) == NULL)
         {
             ShowMessage("Невозможно создать файл настройки по умолчанию. Попробуйте перезапустить программу");
             fclose(F);
             Application->Terminate();
         }
         fclose(F);
     }

     iniFile = new CustomIniFile(iniFileDefault);
     ChartInit(*Chart1);
     AddTab(SourseDir + "\\Temp\\Новая_вкладка.tee");
 }
 flag = true;
 
 // set grid settings
 int a = LEFTAXIS/Chart1->LeftAxis->Increment + 0.5;
 EditKolHorizLines->Text = a;
 a = (SourseMaxTime - SourseMinTime)*SEC / (Chart1->BottomAxis->Increment);
 EditKolVertLines->Text = a;
}


//---------------------------------------------------------------------------
//                     нажатие на ось
//---------------------------------------------------------------------------
void __fastcall TForm1::Chart1ClickAxis(TCustomChart *Sender,
      TChartAxis *Axis, TMouseButton Button, TShiftState Shift, int X,
      int Y)
{
 static int NumPar;
 for(Global.NumTekPar = 0; Global.NumTekPar < MKSERIES+1; ++Global.NumTekPar)
 {
    if(Global.NumTekPar >= MKSERIES)             // -Если перебрали все параметры и не нашли
       { Global.NumTekPar = -1; return; }        // нужной оси, то выходим из ClickAxis
    if(Par[Global.NumTekPar] == NULL)            // -Если указатель на параметра пуст, то
       continue;                          // делаем след. итерацию
    if(Axis == Par[Global.NumTekPar]->Axis)      // -Проверка на нужную ось
       break;                             //
 }

 if(Global.NumTekPar != NumPar)
    stretch = 0;
 NumPar = Global.NumTekPar;

 //---- применить настройки к оси
 /*if(CheckBoxApplyByAxis->Checked){
    Par[Global.NumTekPar]->Axis->Axis->Width = ComboBoxLineWidth->ItemIndex;
    Par[Global.NumTekPar]->Series->LinePen->Style = ComboBoxLineType->Canvas->Pen->Style;
    Par[Global.NumTekPar]->Axis->Axis->Color = ColorBoxLine->Selected;
    Par[Global.NumTekPar]->Axis->Ticks->Color = ColorBoxLine->Selected;
    Par[Global.NumTekPar]->Series->Color = ColorBoxLine->Selected;
 }    */

 //---- управление мышью
 if(! CheckBoxMouse->Checked)
 {
    if(SpeedButtonDelete->Down)
    {
       DeleteParametr(Global.NumTekPar);
       return;
    }
    if(SpeedButtonMaxMin->Down)
    {
       EditMax->Visible = true;
       EditMax->Parent = Chart1;
       EditMax->Left = X - EditMax->Width - 7;
       EditMax->Top = Chart1->CustomAxes->Items[Global.NumTekPar]->IStartPos - EditMax->Height/2;
       EditMax->Text = Chart1->CustomAxes->Items[Global.NumTekPar]->Maximum;

       EditMin->Visible = true;
       EditMin->Parent = Chart1;
       EditMin->Left = X - EditMin->Width - 7;
       EditMin->Top = Chart1->CustomAxes->Items[Global.NumTekPar]->IEndPos - EditMin->Height/2;
       EditMin->Text = Chart1->CustomAxes->Items[Global.NumTekPar]->Minimum;

       ButtonMinMaxOk->Visible = true;
       ButtonMinMaxOk->Parent = Chart1;
       ButtonMinMaxOk->Left = EditMin->Left + EditMin->Width;
       ButtonMinMaxOk->Top = EditMin->Top;

       //Global.NumTekPar = -1;
       return;
    }
 }

 Chart1->PopupMenu = PopupMenuAxis;

 // запоминание начальных и конечных позиций оси
 AxisIncrement = Axis->Increment;
 AxisMax = Axis->Maximum;
 AxisMin = Axis->Minimum;

 if(stretch == 0)
    stretch = 1;
 SelectAxis = true;
 UpHalfAxis = (Y < (Axis->IStartPos)+(Axis->IAxisSize)/2) ? true : false;    // запоминаем по какой из частей оси кликнули
}


//---------------------------------------------------------------------------
//                     Mouse Down
//---------------------------------------------------------------------------
void __fastcall TForm1::Chart1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 if(Global.NumTekPar != -1)
 {
    Par[Global.NumTekPar]->Axis->Axis->Width = 2;           //  клик на пустое место
    Par[Global.NumTekPar]->Axis->Ticks->Width = 1;          //  AxisTek освобождается
    Par[Global.NumTekPar]->Axis->LabelsFont->Size = 8;
    Par[Global.NumTekPar]->Axis->Title->Font->Size = 8;
    Par[Global.NumTekPar]->Axis->LabelsFont->Name = "Arial";
    Global.NumTekPar = -1;
 }

 X0 = X;  Y0 = Y;

 if(Button == mbLeft && Chart1->ChartRect.Left < X   &&    // выделение мышью
                        X < Chart1->ChartRect.Right  &&    // временного отрезка
                        ! buttonReperLine->Down      &&    //
                        Chart1->ChartRect.Top < Y    &&    // обрамление черным
                        Y < Chart1->ChartRect.Bottom &&    // цветом
                        Chart1->SeriesCount() > 1      )   //
 {
    double no;
    Chart1->SeriesList->Items[1]->GetCursorValues(CutX0, no);  // все равно к какой серии применять GetCursorValues
    Chart1->Canvas->Pen->Mode = pmNotXor;                      // потому что все привязаны к нижней оси, а второй
    Chart1->Canvas->Brush->Style = bsClear;                    // параметр не нужен
    Chart1->Canvas->Brush->Color = clBlack;

    Label1->Parent = Chart1;
    Label2->Parent = Chart1;
    Label1->Visible = true;
    Label1->Top = Chart1->LeftAxis->IEndPos + 6;
    Label1->Left = X;
    Label1->Caption = ((TDateTime)CutX0).TimeString();
 }
 else
 {
     Chart1->Canvas->Pen->Mode = pmCopy;
     Chart1->Canvas->Brush->Color = clWhite;
 }

 if(Button == mbRight)
    if(buttonZoomIn->Down)
       Chart1->PopupMenu = NULL;
    else
       Chart1->PopupMenu = PopupMenu1;

 buttonCut->Enabled = false;
 Mouse_Down = true;
}

// ---------  перенос оси мышью -----------//
void AxisMove(double dy, double dx, int i)
{
 Par[i]->Axis->StartPosition += dy;
 Par[i]->Axis->EndPosition += dy;
 Par[i]->Axis->PositionPercent += dx;
}

//----------  растягивание оси -----------//
void AxisStretch(int PixelInCell, int y1, int i)
{
 TChartAxis *Axis = Par[i]->Axis;
 int v;
 if((Form1->Y0 - y1) > PixelInCell)
 {
    Form1->Y0 = y1;
    v = floor((Form1->AxisMax - Form1->AxisMin) / Axis->Increment + 1 + 0.5);
    Axis->Increment = (Axis->Maximum - Axis->Minimum) / v;
    Axis->StartPosition = Axis->StartPosition - Form1->Chart1->LeftAxis->Increment;
 }
 if((Form1->Y0 - y1) < -PixelInCell)
 {
    if((Axis->Maximum - Axis->Increment) <= Axis->Minimum) return;
    Form1->Y0 = y1;
    v = floor((Form1->AxisMax - Form1->AxisMin) / Axis->Increment - 1 + 0.5);
    Axis->Increment = (Axis->Maximum - Axis->Minimum) / v;
    Axis->StartPosition = Axis->StartPosition + Form1->Chart1->LeftAxis->Increment;
 }
}

//----------  Увеличение/уменьшение оси -------------//
void MoveMaxMinAxis(const int PixelInCell, int y, const int i, const bool UpHalfAxis)
{
 TChartAxis *Axis = Par[i]->Axis;
 if(UpHalfAxis)
 {
    if((Form1->Y0 - y) > PixelInCell)
    {
       Form1->Y0 = y;
       Axis->Maximum = Axis->Maximum + Form1->AxisIncrement;
       Axis->StartPosition = Axis->StartPosition - Form1->Chart1->LeftAxis->Increment;
    }
    if((Form1->Y0 - y) < -PixelInCell)
    {
       if((Axis->Maximum - Axis->Increment) <= Axis->Minimum)
          return;
       Form1->Y0 = y;
       Axis->Maximum = Axis->Maximum - Form1->AxisIncrement;
       Axis->StartPosition = Axis->StartPosition + Form1->Chart1->LeftAxis->Increment;
    }
 }
 else
 {
    if((Form1->Y0 - y) > PixelInCell)
    {
       if((Axis->Minimum + Axis->Increment) >= Axis->Maximum)
          return;
       Form1->Y0 = y;
       Axis->Minimum = Axis->Minimum + Form1->AxisIncrement;
       Axis->EndPosition = Axis->EndPosition - Form1->Chart1->LeftAxis->Increment;
    }
    if((Form1->Y0 - y) < -PixelInCell)
    {
       Form1->Y0 = y;
       Axis->Minimum = Axis->Minimum - Form1->AxisIncrement;
       Axis->EndPosition = Axis->EndPosition + Form1->Chart1->LeftAxis->Increment;
    }
 }
}

//---------------------------------------------------------------------------
//                       MouseMove
//---------------------------------------------------------------------------
void __fastcall TForm1::Chart1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
 // рисуется прямоугольник обрамляющий область для ZOOM
 if(buttonZoomIn->Down)
 {
    Chart1->Repaint();
    int deltaH = ScrollBox1->Width / 4;
    int deltaV = ScrollBox1->Height / 4;
    Chart1->Canvas->Brush->Style = bsClear;
    Chart1->Canvas->Rectangle(X - deltaH, Y - deltaV, X + deltaH, Y + deltaV);
    return;
 }

 // при наведении курсора на ось, она выделяется. Остальные становятся обычными
 for(int i = 0; i < Global.KolSeries; ++i)
 {
    if(Chart1->CustomAxes->Items[i]->Clicked(X, Y))
    {
       Chart1->CustomAxes->Items[i]->Axis->Width = 3;
       Chart1->CustomAxes->Items[i]->Ticks->Width = 2 ;
       Chart1->CustomAxes->Items[i]->LabelsFont->Size = 9;
       Chart1->CustomAxes->Items[i]->Title->Font->Size = 9;
       Chart1->CustomAxes->Items[i]->LabelsFont->Name = "Arial Black";
    }
    else
    {
       if(i == Global.NumTekPar)
          continue;
       Chart1->CustomAxes->Items[i]->Axis->Width = 2;
       Chart1->CustomAxes->Items[i]->Ticks->Width = 1;
       Chart1->CustomAxes->Items[i]->LabelsFont->Size = 8;
       Chart1->CustomAxes->Items[i]->Title->Font->Size = 8;
       Chart1->CustomAxes->Items[i]->LabelsFont->Name = "Arial";
    }
 }

 // курсор в поле графиков
 if(Chart1->ChartRect.Left<X && X<Chart1->ChartRect.Right  &&
    Chart1->ChartRect.Top<Y  && Y<Chart1->ChartRect.Bottom &&
                                     Chart1->SeriesCount() > 1)
 {

    if(Mouse_Down && X0 != X)
    {
       if(! buttonReperLine->Down)
       {
          Chart1->Refresh();
          Chart1->Canvas->Rectangle(X0, Chart1->LeftAxis->IStartPos, X,
                                                     Chart1->LeftAxis->IEndPos);
          double y;
          Chart1->SeriesList->Items[1]->GetCursorValues(CutX1, y);

          Label2->Visible = true;
          Label2->Top = Chart1->LeftAxis->IEndPos + 6;
          Label2->Left = X;
          Label2->Caption = ((TDateTime)CutX1).TimeString();

          buttonCut->Enabled = true;
          return;
       }
       else   // реперная линия
       {
          double x, y;
          Chart1->SeriesList->Items[1]->GetCursorValues(x, y);
          Chart1->Refresh();
          Chart1->Canvas->Pen->Color = clBlack;
          Chart1->Canvas->MoveTo(X, Chart1->LeftAxis->IStartPos);
          Chart1->Canvas->LineTo(X, Chart1->LeftAxis->IEndPos);

          Label1->Visible = true;
          Label1->Parent = Chart1;
          Label1->Caption = ((TDateTime)x).TimeString();
          Label1->Top = Chart1->LeftAxis->IEndPos + 6;
          Label1->Left = X;

          for(int i = 0; i < MKSERIES; ++i)
          {
             if(Par[i] != NULL)
                if(Par[i]->BuildSeries)
                {
                   int ct = Par[i]->Series->Count();
                   float pr = (x - Par[i]->Series->MinXValue()) / (float(Par[i]->Series->MaxXValue()) - (float)Par[i]->Series->MinXValue());
                   float y7 = Par[i]->Series->YValue[pr*ct];
                   Chart1->Canvas->Pen->Color = clWhite;
                   Chart1->Canvas->TextOutA(X, Par[i]->Series->CalcYPos(pr * ct), FormatFloat("0.00", y7));
                }
          }
          return;
       }
    }
    else
    {        //    тонкая реперная линия ВСЕГДА
      /* if(Chart1->SeriesCount() > 1 && ! ButtonReperLine->Down && (Global.KolSeries-knp) && !SpeedButton_Cut->Enabled && !GraphIsBuilting){  // если нет серий
          double x, y;
          Chart1->SeriesList->Items[1]->GetCursorValues(x, y);
          Chart1->Refresh();
          Chart1->Canvas->Pen->Color = clGray;
          Chart1->Canvas->MoveTo(X, Chart1->LeftAxis->IStartPos);
          Chart1->Canvas->LineTo(X, Chart1->LeftAxis->IEndPos);
          for(int i=0; i<MKSERIES; i++)
          {
             if(Par[i] != NULL && Par[i]->BuildSeries)
                {
                   int ct = Par[i]->Series->Count();                                 // кол-во точек графика
                   float pr = (x - Par[i]->Series->MinXValue())/( float(Par[i]->Series->MaxXValue()) - (float)Par[i]->Series->MinXValue() );
                   float y7 = Par[i]->Series->YValue[pr*ct];                         // Возвращает значение функции точки
                   Par[i]->Memo->Lines->Strings[1] = FormatFloat("0.00", y7);        // с указанным индексом Index
                }
          }
          return;
       }  */
    }
 }

 // выбрана ось
 if(SelectAxis)
 {
    double dy = (LEFTAXIS / Chart1->LeftAxis->IAxisSize) * (Y - Y0),
           dx = (LEFTAXIS / Chart1->BottomAxis->IAxisSize) * (X - X0);
    int PixelInCell = Chart1->LeftAxis->IAxisSize / (LEFTAXIS / Chart1->LeftAxis->Increment);

    if(SpeedButtonStretch->Down)   // растяжка оси одинакова в двух режимах
       AxisStretch(PixelInCell, Y, Global.NumTekPar);
    else
    {
               //- УПРАВЛЕНИЕ КНОПКАМИ -//
       if(! CheckBoxMouse->Checked)
       {
          if(SpeedButtonMove->Down)
          {
              AxisMove(dy, dx, Global.NumTekPar);
              X0 = X; Y0 =Y;
          }
          if(SpeedButtonAddInc->Down)
              MoveMaxMinAxis(PixelInCell, Y, Global.NumTekPar, UpHalfAxis);
       }
              //- УПРАВЛЕНИЕ ТОЛЬКО МЫШЬЮ -//
       else
       {
          if(stretch != 3)
          {
             AxisMove(dy, dx, Global.NumTekPar);
             X0 = X; Y0 =Y;
          }
          else
             MoveMaxMinAxis(PixelInCell, Y, Global.NumTekPar, UpHalfAxis);
       }
    }
    if(stretch == 1)
       stretch = 2;                                                                                                                                     //                                                                           //
 }
}

//--------------------------------------------------------------------------
//                            MouseUp
//---------------------------------------------------------------------------
void __fastcall TForm1::Chart1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
 Label1->Parent = Panel2;  Label1->Visible = false;
 Label2->Parent = Panel2;  Label2->Visible = false;

 if(SelectAxis)
 {
    if(buttonLinkingGrid->Down)
       LinkToGrid(Par[Global.NumTekPar]->Axis);
    if(stretch == 2 || stretch == 3)
        stretch = 0;
    if(stretch == 1)
        stretch = 3;
 }

 Mouse_Down = false;
 SelectAxis = false;

 //     ZOOM - ZOOM
 static int m = 0;              // для того чтобы использовать Zoom несколько раз подряд
 if(buttonZoomIn->Down)
 {
    if(Button == mbLeft && m < 3)
    {
       ++m;
       Chart1->Align = alNone;
       Chart1->Width *= 2;
       Chart1->Height *= 2;
       ScrollBox1->HorzScrollBar->Position = 2*X - Chart1->Width / (4*m);
       ScrollBox1->VertScrollBar->Position = 2*Y - Chart1->Height / (4*m);
    }
    if(Button == mbRight && m > 0)
    {
       --m;
       Chart1->Width /= 2;
       Chart1->Height /= 2;
    }
    TabControl1->PopupMenu = NULL;

    Chart1->Canvas->Pen->Color = clBlack;
    //Chart1->Canvas->Brush->Style = bsClear;

    return;
 }
    //  Edit Label
 if(EditExample->Parent == Chart1)
 {
    label[EditExample->Tag]->Caption = EditExample->Text;
    EditExample->Parent = Panel11;
    EditExample->Visible = false;
 }
}



//--------------------------------------------------------------------------
//             загрузить график из файлa
//---------------------------------------------------------------------------
void __fastcall TForm1::buttonLoadChartClick(TObject *Sender)
{
 OpenDialogFormat->InitialDir = SourseDir + "//Форматки//";
 if(OpenDialogFormat->Execute())
    OpenChartFromFile(OpenDialogFormat->FileName);
}

//---------------------------------------------------------------------------
//           при передаче управления Form1                                           
//---------------------------------------------------------------------------
void __fastcall TForm1::FormActivate(TObject *Sender)
{
 stretch = 0;
 CheckBoxEndIdent->Checked = false;
 Chart1->Repaint();                               //   !!!  don't understand
 CheckBoxEndIdent->Checked = true;
 if(CheckBoxEndIdent->Checked) 
    void DrawEndIdents();
 WindowState = wsMaximized;
}

//---------------------------------------------------------------------------
//                      SpeedButton_Cut
//---------------------------------------------------------------------------
void __fastcall TForm1::buttonCutClick(TObject *Sender)
{
 if(CutX0 >= CutX1)
    return;
 double min0 = Chart1->BottomAxis->Minimum;
 double max0 = Chart1->BottomAxis->Maximum;

 Chart1->BottomAxis->SetMinMax(CutX0, CutX1);
 Chart1->BottomAxis->Increment = (CutX1 - CutX0) / countMainVertLine;

 float ResizeInProcent = (CutX0 - min0) / ((SourseMaxTime - SourseMinTime)*SEC);   // меняем положение PanelStart
 float Change = SourseWidth * ResizeInProcent;
 Form1->PanelStart->Width += Change;

 ResizeInProcent = (max0 - CutX1) / ((SourseMaxTime - SourseMinTime)*SEC);         // меняем положение PanelEnd и PanelScroll
 Change = SourseWidth * ResizeInProcent;
 Form1->PanelEnd->Width += Change;
 Form1->PanelScroll->Width -= Change;
 buttonCut->Enabled = false;
}

//---------------------------------------------------------------------------
//                         Доп. Меню Оси
//---------------------------------------------------------------------------
void __fastcall TForm1::SettingsClick(TObject *Sender)
{
 FormSettingsAxis->Show();
}

//---------------------------------------------------------------------------
//                  SpeedButtonSaveChart
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButtonSaveChartClick(TObject *Sender)
{
 /*if(SaveDialogChart->Execute()){
    if(ReferLine)  DeleteReferLine();
    // здесь SaveSeriesTitle
    ChartToFile(SaveDialogChart->FileName, 0, 0);
    strcpy(Chart_Ini.pathToFormatka, SaveDialogChart->FileName.c_str());
    strcpy(Chart_Ini.pathToFormatka, SaveDialogChart->FileName.c_str());
    // здесь обратно LoatSeriesTitle
    for(int i=0; i<MKSERIES; i++){     // загружаем NSis
       if(Par[i] != NULL)
          Par[i]->LoatSeriesTitle();
    }
 } */
}

//--------------------------------------------------------------------------
//                   Удаление оси из меню PopupMenuAxis
//--------------------------------------------------------------------------
void __fastcall TForm1::DeleteClick(TObject *Sender)
{
 DeleteParametr(Global.NumTekPar);
 Global.NumTekPar = -1;
}

//---------------------------------------------------------------------------
//                    ButtonGridEnabled
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButtonGridEnableClick(TObject *Sender)
{
 bool autogrid = false;
 if(SpeedButtonGridEnable->Down)
 {
    autogrid = true;
    EditKolVertLines->Text = (SourseMaxTime - SourseMinTime)*SEC /
                                                (Chart1->BottomAxis->Increment);
    EditKolHorizLines->Text = (Chart1->LeftAxis->Maximum -
                       Chart1->LeftAxis->Minimum)/(Chart1->LeftAxis->Increment);
    CSpinEditLeft->Text = Chart1->MarginLeft;
    CSpinEditTop->Text = Chart1->MarginTop;
    CSpinEditRight->Text = Chart1->MarginRight;
    CSpinEditBottom->Text = Chart1->MarginBottom;
 }
 EditKolVertLines->Enabled = autogrid;
 EditMinorCount->Enabled = autogrid;
 EditKolHorizLines->Enabled = autogrid;
 CSpinEditLeft->Enabled = autogrid;
 CSpinEditTop->Enabled = autogrid;
 CSpinEditRight->Enabled = autogrid;
 CSpinEditBottom->Enabled = autogrid;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditMinorCountChange(TObject *Sender)
{
 if(EditMinorCount->Text == "")
    return;
 Chart1->BottomAxis->MinorTickCount = StrToFloat(EditMinorCount->Text);
}



//---------------------------------------------------------------------------
//               Перемещение сплиттеров панельки
//--------------------------------------------------------------------------- Левый сплиттер
void __fastcall TForm1::SplitterStartCanResize(TObject *Sender, int &NewSize,
      bool &Accept)
{
 LabelStartTime->Caption = ((TDateTime)Chart1->BottomAxis->Minimum).TimeString();
 LabelEndTime->Caption = ((TDateTime)Chart1->BottomAxis->Maximum).TimeString();

 float DecreaseInProcent = ((double)PanelScroll->Left - StartPanel) / SourseWidth;
 float ChangeMin = (SourseMaxTime - SourseMinTime) * DecreaseInProcent*SEC;
 Chart1->BottomAxis->Minimum = SourseMinTime*SEC + ChangeMin;

 if(Chart1->BottomAxis->Minimum >= Chart1->BottomAxis->Maximum)
    return;
 Chart1->BottomAxis->Increment =
 (Chart1->BottomAxis->Maximum - Chart1->BottomAxis->Minimum) / countMainVertLine;
}

//--------------------------------------------------------------------------- Правый сплиттер
void __fastcall TForm1::SplitterEndCanResize(TObject *Sender, int &NewSize,
      bool &Accept)
{
 if(Chart1->BottomAxis->Minimum >= Chart1->BottomAxis->Maximum)
    return;
 LabelEndTime->Caption = ((TDateTime)Chart1->BottomAxis->Maximum).TimeString();
 LabelStartTime->Caption = ((TDateTime)Chart1->BottomAxis->Minimum).TimeString();

 float DecreaseInProcent = (EndPanel - ((double)PanelScroll->Left + (double)PanelScroll->Width)) / SourseWidth;
 float ChangeMin = (SourseMaxTime - SourseMinTime)*DecreaseInProcent*SEC;
 Chart1->BottomAxis->Maximum = SourseMaxTime*SEC - ChangeMin;

 Chart1->BottomAxis->Increment =
 (Chart1->BottomAxis->Maximum - Chart1->BottomAxis->Minimum) / countMainVertLine;
}

//---------------------------------------------------------------------------
//                  PanelScrollMouseDown
//---------------------------------------------------------------------------
void __fastcall TForm1::PanelScrollMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 if(Button == mbLeft && !Mouse_Down)
 {
    Mouse_Down = true;
    X0 = X;
 }
}

//---------------------------------------------------------------------------
//              Перемещение Скрольной панели мышью    MouseMove
//---------------------------------------------------------------------------
void __fastcall TForm1::PanelScrollMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
 if(! Mouse_Down)
    return;
 //SplitterMoved = true;
 int DeltaX = X - X0;
 if( ((PanelEnd->Width - DeltaX) >= PanelEnd->Constraints->MinWidth) &&
     ((PanelStart->Width + DeltaX) >= PanelStart->Constraints->MinWidth))
 {
    PanelEnd->Width -= DeltaX;
    PanelStart->Width += DeltaX;
    PanelScroll->Constraints->MinWidth = PanelScroll->Width;

    float deltaminmax = Chart1->BottomAxis->Maximum - Chart1->BottomAxis->Minimum;
    float DecreaseInProcent = ((double)PanelScroll->Left - StartPanel) / SourseWidth;
    float ChangeMin = (SourseMaxTime - SourseMinTime)*DecreaseInProcent*SEC;
    Chart1->BottomAxis->SetMinMax(SourseMinTime*SEC + ChangeMin, SourseMinTime*SEC + ChangeMin + deltaminmax);

    LabelStartTime->Caption = ((TDateTime)Chart1->BottomAxis->Minimum).TimeString();
    LabelEndTime->Caption = ((TDateTime)Chart1->BottomAxis->Maximum).TimeString();
 }
}

//---------------------------------------------------------------------------
//                PanelScrollMouseUp
//---------------------------------------------------------------------------
void __fastcall TForm1::PanelScrollMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
 Mouse_Down = false;
 PanelScroll->Constraints->MinWidth = 0;
}

//---------------------------------------------------------------------------
//         запрещаем менять размеры формы и панели
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
 /*if(SplitterStart->Dragging() || SplitterEnd->Dragging())
    Resize = false;

 if(PanelStart->Width != PanelStart->Constraints->MinWidth ||
    PanelEnd->Width   != PanelEnd->Constraints->MinWidth   ||
                                  SplitterStart->Dragging()||
                                    SplitterEnd->Dragging() )
 {
    Resize = false;
 }   */

 /*static int i = 0;
 if(i < 5)
     Resize = true;
 ++i;*/
 Resize = Global.canResize;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel1CanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
  if(SplitterStart->Dragging())
    Resize = false;
}

// при перемещении сплиттера
void __fastcall TForm1::SplitterStartMoved(TObject *Sender)
{
  //SplitterMoved = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SplitterEndMoved(TObject *Sender)
{
  //SplitterMoved = false;
}




//---------------------------------------------------------------------------
//              загрузка форматки двойным щелчком по правой панели
//---------------------------------------------------------------------------
void __fastcall TForm1::FileListBox1DblClick(TObject *Sender)
{
 OpenChartFromFile(FileListBox1->FileName);
}

//---------------------------------------------------------------------------
//               Изменение размера формы
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
 StartPanel = PanelScroll->Left;
 EndPanel = StartPanel + PanelScroll->Width;
 SourseWidth = PanelScroll->Width;
 Global.canResize = false;
}

//---------------------------------------------------------------------------
//                      Добавить/удалить Реферную линию
//---------------------------------------------------------------------------
void __fastcall TForm1::buttonReperLineClick(TObject *Sender)
{
 if(buttonReperLine->Down)
 {
    // установить начальное положение реперной линии
    Chart1->Canvas->Pen->Color = clBlack;
    Chart1->Canvas->MoveTo(Chart1->BottomAxis->IStartPos + 20, Chart1->LeftAxis->IStartPos);
    Chart1->Canvas->LineTo(Chart1->BottomAxis->IStartPos + 20, Chart1->LeftAxis->IEndPos);
    Chart1->Canvas->Pen->Mode = pmCopy;
    Chart1->Canvas->Pen->Color = clWhite;
 }
 Chart1->Refresh();
}

//---------------------------------------------------------------------------
//             Перерисовка канвы
//---------------------------------------------------------------------------
void __fastcall TForm1::Chart1AfterDraw(TObject *Sender)
{
 for(int i = 0; i < MKSERIES; ++i)           // перебор всех 60 параметров
 {
    if(Par[i] != NULL)                       // если параметр существует
       Par[i]->DrawTitle();
 }

 if(GraphIsBuilting)
    return;
 //if(CheckBoxEndIdent->Checked)
 //   DrawEndIdents();

 /*//---- Маркеры
 if(CheckBoxMarks->Checked){
    for(int i=0; i<MKSERIES; i++){
       if(Par[i] != NULL){
          if(Par[i]->BuildSeries && Par[i]->Series->Count()){
             int a = Par[i]->Series->Count()/5;
             Chart1->Canvas->Font->Name = "wingdings";
             if(Button)
                Chart1->Canvas->Font->Size = -2;
             else
                Chart1->Canvas->Font->Size = -12;
             Chart1->Canvas->Font->Color = Par[i]->Series->Color;
             for(int j=0; j<6; j++)
                Chart1->Canvas->TextOut(Par[i]->Series->CalcXPos(j*a+1), Par[i]->Series->CalcYPos(j*a+1)-15, Par[i]->MarkerSymbol);
          }
       }
    }
 }   */

 //---- Печать
 if(Button)
    for(int i = 0; i < 3; ++i)
    {
      Chart1->Canvas->Font->Name = "Times New Roman";
      Chart1->Canvas->Font->PixelsPerInch = 96;         //(Edit2->Text).ToInt();
      //Chart1->Canvas->Font->Size = 8;                 //(Edit5->Text).ToInt();
      Chart1->Canvas->Font->Height = -2;                // (Edit7->Text).ToInt();
      Chart1->Canvas->TextOut(label[i]->Left, label[i]->Top, label[i]->Caption);
    }
}

//---------------------------------------------------------------------------
//                Закрытие главной формы
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
 if(iniFileMain != NULL)
    delete iniFileMain;
 if(PtrPaspChart != NULL)
    delete[] PtrPaspChart;
 if(PtrRKChart != NULL)
    delete[] PtrRKChart;
}

//--------------------------------------------------------------------------
//       Прорисовка Типов линии
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBoxLineTypeDrawItem(TWinControl *Control, int Index,
      TRect &Rect, TOwnerDrawState State)
{
 ComboBoxLineType->Canvas->FillRect(Rect);
 switch(Index)
 {
    case 0:  ComboBoxLineType->Canvas->Pen->Style = psSolid;       break;
    case 1:  ComboBoxLineType->Canvas->Pen->Style = psDash;        break;
    case 2:  ComboBoxLineType->Canvas->Pen->Style = psDot;         break;
    case 3:  ComboBoxLineType->Canvas->Pen->Style = psDashDot;     break;
    case 4:  ComboBoxLineType->Canvas->Pen->Style = psDashDotDot;  break;
    case 5:  ComboBoxLineType->Canvas->Pen->Style = psClear;       break;
    case 6:  ComboBoxLineType->Canvas->Pen->Style = psInsideFrame; break;
    default: ShowMessage("Mistake in TForm1::ComboBoxLineTypeDrawItem");
 }
 ComboBoxLineType->Canvas->MoveTo(Rect.Left + 5, Rect.Top + 5);
 ComboBoxLineType->Canvas->LineTo(Rect.Right - 5, Rect.Top + 5);
}

//---------------------------------------------------------------------------
//                      Открыть диалог выбора Шрифта
//---------------------------------------------------------------------------
void __fastcall TForm1::BottonFontClick(TObject *Sender)
{
 FontDialog1->Execute();
}

//--------------------------------------------------------------------------
//          Изменение полей Chart
//--------------------------------------------------------------------------
void __fastcall TForm1::CSpinEditRightChange(TObject *Sender)
{
 if(CSpinEditRight->Text == "") return;
 Chart1->MarginRight = StrToInt(CSpinEditRight->Text);
}
void __fastcall TForm1::CSpinEditTopChange(TObject *Sender)
{
 if(CSpinEditTop->Text == "") return;
 Chart1->MarginTop = StrToInt(CSpinEditTop->Text);
}
void __fastcall TForm1::CSpinEditBottomChange(TObject *Sender)
{
 if(CSpinEditBottom->Text == "") return;
 Chart1->MarginBottom = StrToInt(CSpinEditBottom->Text);
}
void __fastcall TForm1::CSpinEditLeftChange(TObject *Sender)
{
 if(CSpinEditLeft->Text == "") return;
 Chart1->MarginLeft = StrToInt(CSpinEditLeft->Text);
}

//---------------------------------------------------------------------------
//               Идентификаторы в конце убрать/поставить
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBoxEndIdentClick(TObject *Sender)
{
 Chart1->Repaint();
}

//---------------------------------------------------------------------------
//            Изменение в поле EditMinorCount
//---------------------------------------------------------------------------
void __fastcall TForm1::CSpinEditMinorCountChange(TObject *Sender)
{
 if(EditMinorCount->Text == "")
 {
    EditMinorCount->Text = 0;
    return;
 }
 Chart1->BottomAxis->MinorTickCount = EditMinorCount->Text.ToInt();
}

//---------------------------------------------------------------------------
//                 убрать   Min Max с осей
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButtonMoveMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 EditMax->Visible = false;
 EditMin->Visible = false;
 EditMax->Parent = GroupBoxFlags;
 EditMin->Parent = GroupBoxFlags;
 ButtonMinMaxOk->Parent = GroupBoxFlags;
 ButtonMinMaxOk->Visible = false;
}

//---------------------------------------------------------------------------
//                   Перетаскивание Memo
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 if(Button != mbLeft) return;
 X0 = X;
 Y0 = Y;
 Mouse_Down = true;
 ((TControl*)Sender)->BringToFront();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
 if(Mouse_Down)
 {
    TMemo *M = (TMemo*)Sender;
    M->SetBounds(M->Left + X - X0, M->Top + Y - Y0, M->Width, M->Height);
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
 Mouse_Down = false;
}

//---------------------------------------------------------------------------
//        При выборе типа линии - не засвечивается выбор
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBoxLineTypeSelect(TObject *Sender)
{
 ComboBoxLineType->Enabled = false;
 ComboBoxLineType->Enabled = true;
}

//---------------------------------------------------------------------------
//            Меняем кол-во вертикальных полос
//---------------------------------------------------------------------------
void __fastcall TForm1::EditKolVertLinesChange(TObject *Sender)
{
 if(EditKolVertLines->Text == "" || EditKolVertLines->Text == "0" || !EditKolVertLines->Enabled)
    return;
 //int a = StrToFloat()
 Chart1->BottomAxis->Increment = (SourseMaxTime-SourseMinTime)*SEC/EditKolVertLines->Text.ToDouble();
 /*double inc;
 if(S == "")
    return;
 if(S.Length() == 7)
    inc = EncodeTime((S.SubString(0,1)).ToInt(), S.SubString(3,4).ToInt(), S.SubString(6,7).ToInt(), 0);
 if(S.Length() == 6)
    inc = EncodeTime(S.SubString(0,0).ToInt(), S.SubString(2,3).ToInt(), S.SubString(5,6).ToInt(), 0);
 Chart1->BottomAxis->Increment = inc; */
}

//---------------------------------------------------------------------------
//             Меняем кол-во горизонтальных полос
//---------------------------------------------------------------------------
void __fastcall TForm1::EditKolHorizLinesChange(TObject *Sender)
{
 if(EditKolHorizLines->Text == "" || EditKolHorizLines->Text == "0")
     return;
 double k0 = LEFTAXIS / Chart1->LeftAxis->Increment;           // начальное кол-во отрезков
 double k1 = StrToInt(EditKolHorizLines->Text);                // новое кол-во отрезков
 if(k1 == k0)
     return;
 float k = k0 / k1;
 Chart1->LeftAxis->Increment = LEFTAXIS / k1;

 for(int i = 0; i < Global.KolSeries; ++i)
 {
    TChartAxis *ax = Chart1->CustomAxes->Items[i];
    int KolStep = (ax->Maximum - ax->Minimum) / ax->Increment;
    ax->StartPosition = 100 - k*(100 - ax->StartPosition);
    ax->EndPosition = ax->StartPosition + KolStep*(Chart1->LeftAxis->Increment);
 }
}


//---------------------------------------------------------------------------
void __fastcall TForm1::EditKolVertLinesKeyPress(TObject *Sender,
      char &Key)
{
 FormSettingsAxis->OnlyNumbers(Key, 0);
}

void __fastcall TForm1::buttonZoomInClick(TObject *Sender)
{
 Chart1->Refresh();
 Chart1->Canvas->Pen->Color = clBlack;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ButtonCreateStringClick(TObject *Sender)
{
 int i = 0;
 while(label[i]->Visible)
 {
    ++i;
    if(i > 2)
       return;
 }
 label[i]->Visible = true;
}

//---------------------------------------------------------------------------
//           Перенос Label  мышкой
//---------------------------------------------------------------------------
void __fastcall TForm1::LabelExampleMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 if(Button != mbLeft)
    return;
 X0 = X;
 Y0 = Y;
 Mouse_Down = true;
 ((TControl*)Sender)->BringToFront();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LabelExampleMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
 if(Mouse_Down)
 {
    TEdit *E = (TEdit*)Sender;
    E->SetBounds(E->Left + X-X0, E->Top + Y-Y0, E->Width, E->Height);
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LabelExampleMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
 Mouse_Down = false;
 TekLabel = Sender;
}

//---------------------------------------------------------------------------
//        Двойной клик - возможность редактирования надписи
//---------------------------------------------------------------------------
void __fastcall TForm1::LabelExampleDblClick(TObject *Sender)
{
 EditExample->Parent = Chart1;
 EditExample->Visible = true;
 EditExample->Left = ((TControl*)Sender)->Left;
 EditExample->Top = ((TControl*)Sender)->Top;
 EditExample->Text = ((TLabel*)Sender)->Caption;
 EditExample->Width = (((TLabel*)Sender)->Caption).Length() *7;
 for(int i = 0; i < 3; ++i)
 {
    if(Sender == label[i])
    {
       EditExample->Tag = i;
       return;
    }
 }
}

//---------------------------------------------------------------------------
//         изменение длины Edit при редактировании
//---------------------------------------------------------------------------
void __fastcall TForm1::EditExampleKeyPress(TObject *Sender, char &Key)
{
 EditExample->Width = (EditExample->Text).Length() * 8;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
 for(int i = 0; i < 3; ++i)
 {
    tit[i] = new TChartTitle(Chart1);
    tit[i]->ParentChart = Chart1;
    tit[i]->CustomPosition = true;
    tit[i]->Caption = "Heeeellllooooo";
    tit[i]->Top = i*10;
    tit[i]->Left = i*20;
    tit[i]->Visible = true;
 }
}

//---------------------------------------------------------------------------
//        прорисовка всех точек графика вкл/выкл
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
 for(int i = 0; i < MKSERIES; ++i)
    if(Par[i] != NULL && Par[i]->BuildSeries)
       Par[i]->Series->DrawAllPoints = CheckBox1->Checked;
}


//---------------------------------------------------------------------------
//  Action   OpenFlyingFile
//---------------------------------------------------------------------------
void __fastcall TForm1::AOpenFlyingFileExecute(TObject *Sender)
{
 OpenDialogData->InitialDir = iniFile->dataDir;
 if(! OpenDialogData->Execute())
    return;
 LoadFlyingFile(OpenDialogData->FileName);

 iniFile->DataFile = OpenDialogData->FileName;
 iniFile->dataDir = OpenDialogData->
 FileName.SubString(0, LastDelimiter("\\", OpenDialogData->FileName));

 Chart1->BottomAxis->SetMinMax(SourseMinTime * SEC, SourseMaxTime * SEC);
 Chart1->BottomAxis->Increment = ((SourseMaxTime - SourseMinTime) * SEC) /
                                                        countMainVertLine;
}

//---------------------------------------------------------------------------
//   Action   OpenINI
//---------------------------------------------------------------------------
void __fastcall TForm1::AOpenINIExecute(TObject *Sender)
{
 OpenDialogIni->InitialDir = iniFile->iniDir;
 if(! OpenDialogIni->Execute())
     return;

 iniFile->iniDir = OpenDialogIni->
            FileName.SubString(0, LastDelimiter("\\", OpenDialogIni->FileName));

 iniFile->openIni(OpenDialogIni->FileName);

 LoadFlyingFile(iniFile->DataFile);
 OpenFormat(iniFile->Format);
}


//---------------------------------------------------------------------------
//  Action   SaveINI
//---------------------------------------------------------------------------
void __fastcall TForm1::ASaveINIExecute(TObject *Sender)
{
 SaveINI();
}


//---------------------------------------------------------------------------
//  Action   Print
//---------------------------------------------------------------------------
void __fastcall TForm1::ChartActionPrint1Execute(TObject *Sender)
{
 int FontPixelPerInch = Chart1->Canvas->Font->PixelsPerInch;
 int FontSize = Chart1->Canvas->Font->Size;
 int FontHeight = Chart1->Canvas->Font->Height;

 Button = true;
 Chart1->Canvas->Font->Name = "Times New Roman";
 Chart1->Canvas->Font->PixelsPerInch = (Edit2->Text).ToInt();
 Chart1->Canvas->Font->Size = (Edit5->Text).ToInt();
 Chart1->Canvas->Font->Height = (Edit7->Text).ToInt();
 for(int i = 0; i < 3; ++i)
    Chart1->Canvas->TextOutA(label[i]->Left, label[i]->Top, label[i]->Caption);
 TeePreview(Form1, Chart1);
 Button = false;

 Chart1->Canvas->Font->PixelsPerInch = FontPixelPerInch;
 Chart1->Canvas->Font->Size = FontSize;
 Chart1->Canvas->Font->Height = FontHeight;
}


//---------------------------------------------------------------------------
//  Action   Info
//---------------------------------------------------------------------------
void __fastcall TForm1::AInfoExecute(TObject *Sender)
{
 //FormInfo->Visible = true;

 FormVievParameters->PageControl1->ActivePageIndex=2;
 FormVievParameters->ShowModal();
}


//---------------------------------------------------------------------------
//                  Play
//---------------------------------------------------------------------------
void __fastcall TForm1::buttonSlowBuiltClick(TObject *Sender)
{
 Built();
}

void TForm1::Built()
{
 Form1->TabControl1->Enabled = false;
 char *Buf = new char[1000 *6];
 int i = 0, j = 0, KolParInFaza = 0, count = 0, k = 0;
 unsigned top = 0, start = 0, end = 0;
 struct ParamXXChart  *PtrParamXXChartTek;

 EditInfo->Parent = Chart1;
 EditInfo->Visible = true;
 EditInfo->Left = Chart1->Width / 4;
 EditInfo->Top = Chart1->Height / 2;

 // заполнение индивидуальных структур для каждого параметра
 Arrays *arr[MKSERIES];
 for(i = 0; i < MKSERIES; ++i)           // перебор всех 60 параметров
 {
    if(Par[i] != NULL)                   // если параметр существует
    {
       Par[i]->Series->Clear();          // удаляем предыдущее построение
       arr[k] = new Arrays();
       arr[k]->NS = Par[i]->NSis;
       arr[k]->MasNumberPasp = Par[i]->NPasp;
       arr[k]->NPar = i;
       ++k;                               // количество новых параметров
    }
 }

 buttonSlowBuilt->Enabled = false;
 buttonFastBuilt->Enabled = false;
 GraphIsBuilting = true;

 //---- для интервала времени
 if(CheckBoxWithTime->Checked)
 {
    start = TimeToInt(EditStartTime->Text);     // начальное время интервала
    end   = TimeToInt(EditEndTime->Text);       // hh:mm:ss
    if(end == -1 || start == -1)
    {
       ShowMessage("Неправильно задан формат времени. Необходимо чч:мм:сс");
       return;
    }
    Chart1->BottomAxis->SetMinMax(start * SEC, end * SEC);
    Chart1->BottomAxis->Increment = (end - start) * SEC / countMainVertLine;
 }
 else
 {
    start = Chart1->BottomAxis->Minimum / SEC + 1;
    end   = Chart1->BottomAxis->Maximum / SEC;
 }

 //-------------------------------------------------------------
 DWORD         bytefact;             // typedef unsigned long DWORD
 LARGE_INTEGER FilePoz;

 fclose(Global.strData);
 Global.hFileData = CreateFile(iniFile->DataFile.c_str(), GENERIC_READ, 0,
                              NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
 int n = IndexBlocFileDatXX.LGif / sizeof(struct Gif);         // кол-во структур быстрого поиска= 86400 = кол-во сек в сутках
 struct Gif *Buff = new struct Gif[n];

 FilePoz.QuadPart = IndexBlocFileDatXX.IndexStructGif;
 SetFilePointer(Global.hFileData, FilePoz.LowPart, &FilePoz.HighPart, FILE_BEGIN);

 ReadFile(Global.hFileData, Buff, sizeof(struct Gif) * n, &bytefact, 0);

 bool find = 0;
 for(i = 0; i < n; ++i)
 {
    if(Buff[i].Time == start)
    {
       FilePoz.LowPart = Buff[i].Poz;
       FilePoz.HighPart = Buff[i].TimeHAE;
       SetFilePointer(Global.hFileData, FilePoz.LowPart, &FilePoz.HighPart, FILE_BEGIN);

       find = true;
       break;
    }
 }
 //-------------------------------------------------------------

 delete[] Buff;
 if(! find)
    ShowMessage("начальное время не найдено!");

 GetAsyncKeyState('Q');

 if(Form1->CheckBoxWithTime->Checked)
    SetTimeBar(start, end);

 for(;;)                                              // 2014_03_13
 {
    ReadFile(Global.hFileData, &TimXX, sizeof(TimXX), &bytefact, 0);
    if(bytefact == 0)
       break;
    KolParInFaza = TimXX.KParFaz / sizeof(struct ParamXXChart);

    top = TimXX.TInt;                                   // время фазы в мс
    if( top == end * 1000 )
       break;
    short hh = top / 3600000;
    short mm = (top % 3600000) / 60000;
    short ss = (top % 3600000) % 60000 / 1000;
    short ms = (top % 3600000) % 60000 % 1000;
    double Yt = EncodeTime(hh, mm, ss, ms);

    ReadFile(Global.hFileData, Buf, sizeof(struct ParamXXChart) * KolParInFaza,&bytefact,0);             // 2014_03_13
    if(bytefact == 0)
       break;                                 // 2014_03_13
    PtrParamXXChartTek = (struct ParamXXChart*)Buf;

    for(j = 0; j < KolParInFaza; ++j)
    {
       for(i = 0; i < k; ++i)         //knp
       {
          if(PtrParamXXChartTek->NPasp == arr[i]->MasNumberPasp &&
             PtrParamXXChartTek->NSisNClov == arr[i]->NS)
             switch((PtrPaspChart + arr[i]->MasNumberPasp)->Tip)
             {
                case 0:            // разовые команды
                case 1:
                {
                   if(Par[arr[i]->NPar]->NRK < 0)
                   {
                      ShowMessage("Не выбрано ни одной разовой команды");
                      return;
                   }
                   int rk = ((PtrParamXXChartTek->KodFizika.L) >> (Par[arr[i]->NPar]->NRK)) & 1;
                   Par[arr[i]->NPar]->Series->AddXY(Yt, float(rk));
                   break;
                }
                case 2:            // физика
                {
                   Par[arr[i]->NPar]->Series->AddXY(Yt, PtrParamXXChartTek->KodFizika.F);
                   break;
                }
                default: ShowMessage("Ошибка определения типа для строящегося параметра");
             }
          Par[arr[i]->NPar]->BuildSeries = true;
       }
       ++PtrParamXXChartTek;
    }
    //---- Для визуализации построения графиков
    if(! (count % 50000))
        Application->ProcessMessages();

    ++count;

    //---- при нажатии на кнопку Q процесс построения останавливается
    if ((GetAsyncKeyState(int('Q')) & 1) != 0 || !GraphIsBuilting)
    {
         EditInfo->Parent = GroupBoxFlags;
         EditInfo->Visible = false;
         Form1->TabControl1->Enabled = true;
         break;
    }
 }

 EditInfo->Parent = GroupBoxFlags;
 EditInfo->Visible = false;

 CloseHandle(Global.hFileData);    // 2014_03_13
 delete[] Buf;
 for(int i = 0; i < 0; --i)
    delete arr[k];
 knp = 0;

 GraphIsBuilting = false;
 buttonSlowBuilt->Enabled = true;
 buttonFastBuilt->Enabled = true;

 if(Chart1->SubTitle->Text->Count == 1)
    Chart1->SubTitle->Text->Add("");
 Chart1->SubTitle->Text->Strings[1] = "11";

 Form1->TabControl1->Enabled = true;
}

//---------------------------------------------------------------------------
//                  Новая вкладка
//---------------------------------------------------------------------------
void __fastcall TForm1::NNewListClick(TObject *Sender)
{
 OpenDialogFormat->InitialDir = SourseDir + "\\Форматки\\";
 OpenDialogFormat->FilterIndex = 2;

 if(OpenDialogFormat->Execute())
 {
     AddTab(OpenDialogFormat->FileName);
 }
 OpenDialogFormat->FilterIndex = 1;
}



//---------------------------------------------------------------------------
//                TabControlChange        После переключения форматки
//---------------------------------------------------------------------------
void __fastcall TForm1::TabControl1Change(TObject *Sender)
{
 for(unsigned i = 0; i < numMode.size(); ++i)
 {
    if(numMode[i] == TabControl1->TabIndex)
    {
       OpenChartFromFile(pathMode[i]);
       return;
    }
 }
 
 // загрузить новую форматку -  она должна быть в папке Temp
 String name = TabControl1->Tabs->Strings[TabControl1->TabIndex];
 if( !FileExists(SourseDir + "\\Temp\\" + name + ".tee"))
     DeleteAllParameters();
 else
     OpenChartFromFile(SourseDir + "\\Temp\\" + name + ".tee");
}


//---------------------------------------------------------------------------
//                До переключения форматки
//---------------------------------------------------------------------------
void __fastcall TForm1::TabControl1Changing(TObject *Sender,
      bool &AllowChange)
{
 if(GraphIsBuilting)
 {
     EditInfo->Visible = false;
     EditInfo->Parent = GroupBoxFlags;
     GraphIsBuilting = false;
 }

 if(ButtonMinMaxOk->Visible)
 {
    EditMax->Visible = false;
    EditMin->Visible = false;
    ButtonMinMaxOk->Visible = false;
    EditMax->Parent = GroupBoxFlags;
    EditMin->Parent = GroupBoxFlags;
    ButtonMinMaxOk->Parent = GroupBoxFlags;
    SpeedButtonMove->Down = true;
 }

 // сохранение текущей вкладки в файл *.tee без данных в папку "Temp"
 // а если режим то сохраняем с данными в указанную в pathMode директорию
 bool find = false;
 int i = -1;
 for(i = 0; i < numMode.size(); ++i)
 {
    if(numMode[i] == TabControl1->TabIndex)
    {
       find = true;
       break;
    }
 }

 if(find)
    ChartToFile(pathMode[i], 1, 0);
 else
    SaveCurrentTab(SourseDir + "\\Temp\\");

 DeleteAllParameters();
}

//---------------------------------------------------------------------------
//       Пункты Меню
//---------------------------------------------------------------------------
void __fastcall TForm1::MParametrsClick(TObject *Sender)
{
 // в FormVievParameters->StringGrid1 помещаются те параметры, которые уже есть на графике
 FormVievParameters->StringGrid1->RowCount = 0;
 int c = 0;
 for(int i = 0; i < MKSERIES; ++i)
 {
    if(Par[i] != NULL)
    {
         ++FormVievParameters->StringGrid1->RowCount;
         ++c;
         FormVievParameters->StringGrid1->Cells[0][c] = c;
         FormVievParameters->StringGrid1->Cells[1][c] = Par[i]->Axis->Title->Caption;
    }
 }

 int left = Form1->Left + Chart1->BottomAxis->IStartPos + 20;
 int top  = Form1->Top  + 20 + TabControl1->Top;
 int height = Chart1->Height;
 int width  = Chart1->Width - Chart1->BottomAxis->IStartPos;

 FormVievParameters->Left = left;
 FormVievParameters->Top  = top;
 FormVievParameters->Height = height;
 FormVievParameters->Width = width;

 FormVievParameters->PageControl1->ActivePageIndex = 1;
 FormVievParameters->Show();
}

//---------------------------------------------------------------------------
//   нажатие кнопок меню
void __fastcall TForm1::MEditClick(TObject *Sender)
{
 ToolBar1->Visible = false;
 Panel2->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MmanagementClick(TObject *Sender)
{
 ToolBar1->Visible = true;
 Panel2->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::NAboutClick(TObject *Sender)
{
 FormAbout->ShowModal();
}





//---------------------------------------------------------------------------
//     Action   SaveAll
//---------------------------------------------------------------------------
void __fastcall TForm1::ASaveAllExecute(TObject *Sender)
{
 SaveDialogIni->InitialDir = iniFile->iniDir;
 if(! SaveDialogIni->Execute())
    return;

 iniFile->formatDir = SaveDialogIni->
 FileName.SubString(0, LastDelimiter("\\", SaveDialogIni->FileName));

 iniFile->saveIniAs(SaveDialogIni->FileName);
}


//---------------------------------------------------------------------------
//  Action   SaveINIAs
//---------------------------------------------------------------------------
void __fastcall TForm1::ASaveINIAsExecute(TObject *Sender)
{
 SaveDialogIni->InitialDir = iniFile->iniDir;
 if(! SaveDialogIni->Execute())
    return;

 iniFile->iniDir = SaveDialogIni->
            FileName.SubString(0, LastDelimiter("\\", SaveDialogIni->FileName));

 iniFile->saveIniAs(SaveDialogIni->FileName);
 iniFileMain->WriteString("Files", "LastFileIni", iniFile->iniFileName);
}

//----------------------------------------------------------------------------
//                   SaveINI
//----------------------------------------------------------------------------
void TForm1::SaveINI()
{
 SaveDialogIni->InitialDir = iniFile->iniDir;
 if(! FileExists(iniFile->iniFileName))        // если на данный момент не выбрана настройка,
 {
    SaveDialogIni->InitialDir = iniFile->iniDir;
    if(! SaveDialogIni->Execute())
        return;

    iniFile->iniDir = SaveDialogIni->
    FileName.SubString(0, LastDelimiter("\\", SaveDialogIni->FileName));
    iniFile->iniFileName = SaveDialogIni->FileName;
 }

 if(! SaveDialogIni->Execute())
    return;

 iniFile->iniDir = SaveDialogIni->
 FileName.SubString(0, LastDelimiter("\\", SaveDialogIni->FileName));

 iniFile->saveIniAs(SaveDialogIni->FileName);
}


//---------------------------------------------------------------------------
//       ButtonMinMaxOk                                                              // Error ! если при нажатии на кнопку
//---------------------------------------------------------------------------        // ОК, ось не выделенна.
void __fastcall TForm1::ButtonMinMaxOkClick(TObject *Sender)
{
 // выставляем мин мах на выбранную ось
 int inc = (Par[Global.NumTekPar]->Axis->Maximum -
 Par[Global.NumTekPar]->Axis->Minimum) / Par[Global.NumTekPar]->Axis->Increment;

 if(FormSettingsAxis->TrueSeparator(EditMin->Text).ToDouble() >
                      FormSettingsAxis->TrueSeparator(EditMax->Text).ToDouble())
 {
    ShowMessage("Значение Min оси должно быть меньше значения Max оси!");
    return;
 }
 if(EditMin->Text == EditMax->Text)
 {
    ShowMessage("Значения Min, Max оси должны различаться");
    return;
 }
 Par[Global.NumTekPar]->Axis->SetMinMax(FormSettingsAxis->TrueSeparator(EditMin->Text).ToDouble(),
                                        FormSettingsAxis->TrueSeparator(EditMax->Text).ToDouble());
 Par[Global.NumTekPar]->Axis->Increment =
 (Par[Global.NumTekPar]->Axis->Maximum-Par[Global.NumTekPar]->Axis->Minimum)/inc;

 // убираем мин мах 
 EditMax->Visible = false;           EditMin->Visible = false;
 EditMax->Parent = GroupBoxFlags;    EditMin->Parent = GroupBoxFlags;
 ButtonMinMaxOk->Parent = GroupBoxFlags;
 ButtonMinMaxOk->Visible = false;
}



 //---- МАРКЕРЫ
 /* вариант 1
 /* выводить на канву текст( букву) шрифтом Wingdings
 /* проблемы: настройка перед печатью, обновление канвы каждый раз после перерисовки */
 /*int a = Par[1]->Series->Count()/5;
 Chart1->Canvas->Font->Name = "webdings";
 Chart1->Canvas->Font->Color = Par[1]->Series->Color;
 Chart1->Canvas->Font->Size = Chart1->Canvas->Font->Size + 10;
 for(int i=0; i<5; i++)
   Chart1->Canvas->TextOut(Par[1]->Series->CalcXPos(i*a+1), Par[1]->Series->CalcYPos(i*a+1), "a");       */


 // вариант 2
 /* ставить рисунки, которые содержатся в папке */
 /*Par[1]->Series->Marks->DrawEvery = 40000;
 Par[1]->Series->Marks->Visible = true;
 Par[1]->Series->Marks->Style = smsSeriesTitle;
 Par[1]->Series->Marks->Picture->LoadFromFile("Path");    */

void __fastcall TForm1::N6Click(TObject *Sender)       // 2013_07_15    Хромцов   Создать или Редактировать файл расчетных параметров
{
int i;
 ToolBar1->Visible = false;
 Panel2->Visible = false;
 FormRashet->Memo1->Visible = false;
// NameFileRashetTxt = "123";
// i=NameFileRashetTxt.AnsiPos("\0");
 i=NameFileRashetTxt.AnsiCompare("\0");
 if(i != 0)   FormRashet->Memo1->Lines->LoadFromFile(NameFileRashetTxt);
 else FormRashet->Memo1->Clear();
 FormRashet->Memo1->Visible = true;
 FormRashet->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N7Click(TObject *Sender)       // 2013_07_15    Хромцов  Подключить  расчетные параметры
{
int ret;
// TStringList *TextFile;
// TextFile = new  TStringList();

  if(OpenDialogFileRashet->Execute())
  {
//  if(NameFileRashetTxt[1] != '\0') NameFileRashetTxt[1] = '\0';
  FormRashet->Memo1->Visible = false;
  NameFileRashetTxt = OpenDialogFileRashet->FileName;
//  FormRashet->Memo1->Lines->LoadFromFile(NameFileRashetTxt);
  if(PtrClassRashetParam != NULL) { delete PtrClassRashetParam; PtrClassRashetParam = NULL; }
  PtrClassRashetParam = new ClassRashetParam(NameFileRashetTxt);
   //  Анализ текстового файла расчетных параметров,
   //  Создание символьного файла библиотеки DLL,
   //  Компиляция, создание библиотеки DLL,

 ret = FunLibrery(PtrGlobalFlagChart->NameDllRashetLibrary);  //  Подключение библиотеки
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N8Click(TObject *Sender)      // 2013_07_15    Хромцов   Отключить расчетные параметры
{
NameFileRashetTxt = '\0';
   // Отключить  библиотеку
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
TForm1::FunLibrery(char Name[])           // Хромцов 2013_07_15
{
int ret;
char txt[256];

 if(PtrGlobalFlagChart->RashetLibrary == true ) { FunLibraryDeInitOutGlobalValue(); FunCloseLibrary(); }
 ret = FunOpenLibrary(Name);  // 2007_09_18
  if(ret == -1)
 {
  strcpy(txt,"Файл библиотеки  "); strcat(txt,Name);
  strcat(txt,"   не найден");
  MessageBox(NULL,txt,"Info",MB_ICONINFORMATION);
  PtrGlobalFlagChart->RashetLibrary = false;
  PtrGlobalFlagChart->NameDllRashetLibrary[0] = '\0';
  return(-1);
 }
  FunLibraryInitOutGlobalValue();
  PtrGlobalFlagChart->RashetLibrary = true;
//  ret = OpenBaza(PtrFlagPotokVizual->FileNameBaza,0);                              // Необходимо доработать подсоединение расчетных паспортов
// if(ret != 0) { FunLibraryDeInitOutGlobalValue();    FunCloseLibrary(); return(-1);}
// InitAdresAPISistemStruct((void *)PtrFlagPotokVizual,(void *)PtrWinSistTab,(void *)PtrSisTable,(void *)PtrPasp,(void *)PtrPotok,
// (void *)PtrTipPar,(void *)PtrBlokRK);
 InitAdresAPIInp();
  if( PriznakNoParDll == true)
   {
//   MessageBox(NULL,BufParNo,"Входные Параметры библиотеки ",MB_ICONINFORMATION);     // ДОРАБОТАТЬ   ????????????????????????????????
//   delete[] BufParNo; BufParNo = NULL; PriznakNoParDll = false;                      // ДОРАБОТАТЬ   ????????????????????????????????
   FunLibraryDeInitOutGlobalValue();    FunCloseLibrary();
   PtrGlobalFlagChart->RashetLibrary = false;
   return(-1);
   }
 return(0);
}  // Хромцов 2013_07_15


//--------------------------------------------------------------------------
//    Button 100%
//--------------------------------------------------------------------------
void __fastcall TForm1::buttonFullTimeClick(TObject *Sender)
{
 if(buttonZoomIn->Down)
    { Chart1->Align = alClient;  return; }
 Chart1->BottomAxis->SetMinMax(SourseMinTime*SEC, SourseMaxTime*SEC);
 Chart1->BottomAxis->Increment = (Chart1->BottomAxis->Maximum - Chart1->BottomAxis->Minimum) / countMainVertLine;

 PanelStart->Width = PanelStart->Constraints->MinWidth;
 PanelEnd->Width = PanelEnd->Constraints->MinWidth;
 LabelEndTime->Top = PanelScroll->Top + PanelScroll->Height - 20;
 LabelEndTime->Left = PanelScroll->Width - 50;
 LabelEndTime->Caption = (TDateTime(SourseMaxTime*SEC)).TimeString();
 LabelStartTime->Caption = (TDateTime(SourseMinTime*SEC)).TimeString();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::buttonLinkingGridClick(TObject *Sender)
{
 for(int i = 0; i < Global.KolSeries; ++i)
    LinkToGrid(Chart1->AxesList->Items[i+6]);        
}


//---------------------------------------------------------------------------
//   Открытие окна для ввода диапазона
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBoxWithTimeClick(TObject *Sender)
{
 if(CheckBoxWithTime->Checked)
    while(Panel10->Width < 249)
       ++Panel10->Width;
 else
 {
    while(Panel10->Width > 71)
       --Panel10->Width;
    return;
 }
 // заполнение окон диапазона
 if(TimeToInt(EditStartTime->Text) == -1 || TimeToInt(EditEndTime->Text) == -1)
 {
    EditStartTime->Text = EncodeTime(SourseMinTime / 3600,
                  (SourseMinTime % 3600) / 60, (SourseMinTime % 3600) % 60, 0);
    EditEndTime->Text = EncodeTime(SourseMaxTime / 3600,
                  (SourseMaxTime % 3600) / 60, (SourseMaxTime % 3600) % 60, 0);
 }
}


//---------------------------------------------------------------------------
void TForm1::CreateSmallFile()
{
 struct TimXX TimXX;
 struct ParamXXChart *PtrParamXXChartTek;
 struct MinMax *PtrMinMax;

 int i = 0;

 fseek(Global.strData, IndexBlocFileDatXX.IndexBeginPackData, SEEK_SET);

 Global.strPack = fopen( (SourseDir + "\\" + "output_128.dat").c_str(), "wb");

 PtrMinMax = new struct MinMax[KSISTEM * IndexBlocFileDatXX.KStructPaspChart];

 for(i = 0; i < IndexBlocFileDatXX.KRealSecPackData; ++i)
 {
     fread(&TimXX.TInt, sizeof(int), 1, Global.strData);
     fread(PtrMinMax, sizeof(struct MinMax),
               (KSISTEM * IndexBlocFileDatXX.KStructPaspChart), Global.strData);
     fwrite(&TimXX.TInt, sizeof(int), 1, Global.strPack);
     fwrite(PtrMinMax, sizeof(struct MinMax),
               (KSISTEM * IndexBlocFileDatXX.KStructPaspChart), Global.strPack);
 }

 fclose(Global.strPack);
 fclose(Global.strData);

 delete[]  PtrMinMax;
 PtrMinMax = NULL;
}


//---------------------------------------------------------------------------
//    Удаление содержимого папки Temp
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
 SaveCurrentTab(SourseDir + "\\Temp\\");

 AnsiString dirName = SourseDir + "\\Temp\\";
 TSearchRec sr;

 if ( !FindFirst(dirName + "\\*.*", faAnyFile, sr))
 {
    do
    {
       if (!(sr.Name=="." || sr.Name==".."))        // это не удаляем
       {
          FileSetAttr(dirName + "\\" + sr.Name, 0);
          DeleteFile(dirName + "\\" + sr.Name);         // удаляем файл
       }
    }
    while ( !FindNext(sr));                     
 }
 FindClose(sr);
}


//--------------------------------------------------------------------------
//       Кнопка Выбор цвета
//--------------------------------------------------------------------------
void __fastcall TForm1::buttonColorClick(TObject *Sender)
{
 if(buttonSelectColor->Down )
 {
  while(PanelColor->Width < 73)
     ++PanelColor->Width;
 }

 else
 {
  while(PanelColor->Width > 31)
     --PanelColor->Width;
 }
}


//---------------------------------------------------------------------------
//   Запрещаем вводить не числовые символы
//---------------------------------------------------------------------------
void __fastcall TForm1::EditMaxKeyPress(TObject *Sender, char &Key)
{
 FormSettingsAxis->OnlyNumbers(Key, 1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LabelDeleteMenuClick(TObject *Sender)
{
 ((TLabel*)TekLabel)->Visible = false;
 ((TLabel*)TekLabel)->Caption = "Текст";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBoxLineWidthClick(TObject *Sender)
{
 Label18->Caption = Sender->ClassName();

 SpeedButtonMove->Down = false;
 SpeedButtonMaxMin->Down = false;
 SpeedButtonAddInc->Down = false;
 SpeedButtonStretch->Down = false;
 SpeedButtonDelete->Down = false;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ComboBoxLineWidthBeginEdit(TObject *Sender)
{
 TComboBoxEx* box = dynamic_cast<TComboBoxEx*>(Sender);
 box->Color = clWhite;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::buttonFastBuiltClick(TObject *Sender)
{
 FastBuilt();
}


//---------------------------------------------------------------------------
//   Построение короткого файла
//---------------------------------------------------------------------------
void TForm1::FastBuilt()
{
 int k = 0, top = 0, top2 = 0, j = 0, i = 0;
 struct ParamXXChart  *PtrParamXXChartTek;

 Arrays *arr[MKSERIES];
 struct MinMax *PtrMinMax,*PtrMinMaxTek;
 struct TimXX TimXX;

 //---- заполнение индивидуальных структур для каждого параметра
 for(i = 0; i < MKSERIES; ++i)           // перебор всех 60 параметров
 {
    if(Par[i] != NULL)                   // если параметр существует
    {
       Par[i]->Series->Clear();
       arr[k] = new Arrays();
       arr[k]->NS = Par[i]->NSis;
       arr[k]->MasNumberPasp = Par[i]->NPasp;
       arr[k]->NPar = i;
       ++k;                           // количество новых параметров
    }
 }

 Global.strPack = fopen( (SourseDir + "\\" + "output_128.dat").c_str(), "rb");

 PtrMinMax = new struct MinMax[KSISTEM * IndexBlocFileDatXX.KStructPaspChart];

 if(Global.strPack != NULL)  // если вдруг файла "output_128.dat" нет
 {
    int kr = 0;
    for(j = 0, kr = IndexBlocFileDatXX.KRealSecPackData; j < kr; ++j)
    {
       fread(&TimXX.TInt, sizeof(int), 1, Global.strPack);
       fread(PtrMinMax, sizeof(struct MinMax),
            (KSISTEM * IndexBlocFileDatXX.KStructPaspChart),Global.strPack);

       top = TimXX.TInt;
       top2 = top + IndexBlocFileDatXX.KSecPiksel * 1000/2;
       double Yt = EncodeTime(top/3600000, (top%3600000)/60000,
                          (top%3600000)%60000/1000, (top%3600000)%60000%1000);
       double Yt2 = EncodeTime(top2/3600000, (top2%3600000)/60000,
                           (top2%3600000)%60000/1000, (top2%3600000)%60000%1000);

       for(int i = 0; i < k; ++i)        //knp
       {
          PtrMinMaxTek = PtrMinMax + (arr[i]->NS-1) *
          IndexBlocFileDatXX.KStructPaspChart + arr[i]->MasNumberPasp;

          Par[arr[i]->NPar]->Series->AddXY(Yt, PtrMinMaxTek->Max.F);
          Par[arr[i]->NPar]->Series->AddXY(Yt2, PtrMinMaxTek->Min.F);
          Par[arr[i]->NPar]->BuildSeries = true;
       }
    }
 }

 fclose(Global.strPack);
 delete[] PtrMinMax;
 PtrMinMax = NULL;
 for(int i = k; i < 0; --i)
    delete arr[k];
 knp = 0;

 if(Chart1->SubTitle->Text->Count == 1)
     Chart1->SubTitle->Text->Add("");
 Chart1->SubTitle->Text->Strings[1] = "10";


 //---- для интервала времени
 if(CheckBoxWithTime->Checked)
 {
    int start = TimeToInt(EditStartTime->Text);     // начальное время интервала
    int end   = TimeToInt(EditEndTime->Text);       // hh:mm:ss
    if(end == -1 || start == -1)
    {
       ShowMessage("Неправильно задан формат времени. Необходимо чч:мм:сс");
       return;
    }
    Chart1->BottomAxis->SetMinMax(start * SEC, end * SEC);
    Chart1->BottomAxis->Increment = (end - start) * SEC / countMainVertLine;
 }

}



//---------------------------------------------------------------------------
//  Удаление текущей вкладки
//---------------------------------------------------------------------------
void __fastcall TForm1::NDeleteTabClick(TObject *Sender)
{
 DeleteCurrentTab(0);
}


//---------------------------------------------------------------------------
//     SaveFormatAs...               Menu
//---------------------------------------------------------------------------
void __fastcall TForm1::NFormatSaveAsClick(TObject *Sender)
{
 SaveCurrentTab(SourseDir + "\\Temp\\");
 SaveDialogFormat->InitialDir = iniFile->formatDir;
 SaveDialogFormat->Execute();
 iniFile->formatDir = SaveDialogFormat->
         FileName.SubString(1, LastDelimiter("\\", SaveDialogFormat->FileName));
 SaveFormat(SaveDialogFormat->FileName);
}


//---------------------------------------------------------------------------
//      NewFormat
//---------------------------------------------------------------------------
void TForm1::NewFormat()
{
 String path = SourseDir + "\\Temp\\Новая_вкладка.fmt";
 FILE* fout = fopen(path.c_str(), "w");

 if(fout)
 {
     String dirName = SourseDir + "\\Temp\\Новая_вкладка\\";
     CreateDir(dirName);
     fprintf(fout, "%s", dirName.c_str());

     iniFile->Format = path;
     fclose(fout);
 }
}


//---------------------------------------------------------------------------
//     OpenFormat                    Menu
//---------------------------------------------------------------------------
void __fastcall TForm1::NFormatOpenClick(TObject *Sender)
{
 OpenDialogFormat->InitialDir = iniFile->formatDir;
 if(! OpenDialogFormat->Execute())
    return;

 DeleteAllParameters();

 while(TabControl1->Tabs->Count)
    TabControl1->Tabs->Delete(0);

 String path = OpenDialogFormat->FileName;
 path = path.SubString(1, path.Length() - 4) + "\\";        // path.tee -> path//

 iniFile->formatDir = OpenDialogFormat->
         FileName.SubString(0, LastDelimiter("\\", OpenDialogFormat->FileName));

 OpenFormat(path);
 iniFile->Format = path;
}


//---------------------------------------------------------------------------
//    OpenFormat
//---------------------------------------------------------------------------
void TForm1::OpenFormat(const String& pathToFormatka)
{
 String path = pathToFormatka;

 //Проверка на существование файла
 String fileName = path.SubString(0, path.Length() - 1) + ".fmt";
 if( !FileExists(fileName))
 {
     ShowMessage("Не удалось загрузить форматку " + fileName);
     return;
 }

 //delete all tabs
 while(TabControl1->Tabs->Count)
    DeleteCurrentTab(1);

 //        C://...// *.tee    copy to    C://...//Temp//*.tee
 TSearchRec sr;
 if ( !FindFirst(path + "*.*", faAnyFile, sr))
 {
    do
    {
       if ( !(sr.Name=="." || sr.Name==".."))
       {
           CopyFile( (path + sr.Name).c_str(),
                     (SourseDir + "\\Temp\\" + sr.Name).c_str(), 0);

           AddTab(SourseDir + "\\Temp\\" + sr.Name);
       }
    }
    while ( !FindNext(sr));     // ищем пока не найдем все

    FindClose(sr);
 }
}



//---------------------------------------------------------------------------
//      SaveFormat
//---------------------------------------------------------------------------
void TForm1::SaveFormat(const String& nameFormatka)
{
 String dir = nameFormatka.SubString(1, nameFormatka.Length() - 4) + "\\";

 FILE* fout = fopen(nameFormatka.c_str(), "w");
 if(fout)
 {
     //------------ удаление прежних файлов в папке --------------------------
     if( DirectoryExists(dir) )
     {
         TSearchRec sr;
         if ( !FindFirst(dir + "*.*", faAnyFile, sr))
         {
             do
             {
                 if ( !(sr.Name=="." || sr.Name==".."))
                     DeleteFile(dir + sr.Name);
             }
             while ( !FindNext(sr));     // ищем пока не найдем все
         }
     }
     //----------------------------------------------------------------------

     CreateDir(dir);
     fprintf(fout, "%s", dir.c_str());                                          // в будущем нужно писать в этот файл порядок загрузки вкладок
     iniFile->Format = nameFormatka;

     //--------------- copy from Temp  ->  dirName  -------------------------
     TSearchRec sr;
     String tmpName = SourseDir + "\\Temp\\";
     if ( !FindFirst(tmpName + "\\*.*", faAnyFile, sr))
     {
         do
         {
             if (!(sr.Name=="." || sr.Name==".."))        // не копируем . & ..
                 CopyFile((tmpName + sr.Name).c_str(), (dir + sr.Name).c_str(), 0);
         }
         while ( !FindNext(sr));     // ищем пока не найдем все
     }
     FindClose(sr);
     //----------------------------------------------------------------------

     ShowMessage("Сохранено в " + (String)iniFile->Format);
 }
 else
    ShowMessage("Не удалось сохранить форматку!");
 fclose(fout);
}




//---------------------------------------------------------------------------
//     AddTab
//---------------------------------------------------------------------------
void TForm1::AddTab(const String& pathToTeeFile)
{
 if(TabControl1->TabIndex == -1)        // если вкладка первая
    OpenChartFromFile(pathToTeeFile);

 String name = ExtractFileName(pathToTeeFile);
 TabControl1->Tabs->Add(name.SubString(1, name.Length() - 4)); // чтобы убрать .tee
}


//---------------------------------------------------------------------------
//     SaveCurrentTab
//---------------------------------------------------------------------------
void TForm1::SaveCurrentTab(const String& pathToFormatDir)
{
 int n = TabControl1->TabIndex;
 String name = pathToFormatDir + TabControl1->Tabs->Strings[n] + ".tee";
 ChartToFile(name, 0, 1);
}


//---------------------------------------------------------------------------
//     DeleteCurrentTab
//---------------------------------------------------------------------------
void TForm1::DeleteCurrentTab(const bool loadAnotherChart)
{
 int newIndex = TabControl1->TabIndex - 1;
 if(newIndex < 0 || newIndex > TabControl1->Tabs->Count)
    newIndex = 0;

 DeleteFile(SourseDir + "\\Temp\\" +
                    TabControl1->Tabs->Strings[TabControl1->TabIndex] + ".tee");
 TabControl1->Tabs->Delete(TabControl1->TabIndex);

 DeleteAllParameters();
 TabControl1->TabIndex = newIndex;

 if(loadAnotherChart)
    return;

 if( !TabControl1->Tabs->Count)
 {
     TabControl1->Tabs->Add("Новая_вкладка.tee");
     return;
 }
 String name = TabControl1->Tabs->Strings[newIndex];
 OpenChartFromFile(SourseDir + "\\Temp\\" + name + ".tee");
}


//--------------------------------------------------------------------------- объединить с RepeatTabName
//      RenameTab                                                            т.к. используется всего один раз
//---------------------------------------------------------------------------
void TForm1::RenameTab(const String& name)
{
 int n = TabControl1->TabIndex;
 String oldName = TabControl1->Tabs->Strings[n];
 String newName = name;

 int c = RepeatTabName(name);
 if(c)
    newName = name + "(" + IntToStr(c) + ")";

 TabControl1->Tabs->Strings[n] = newName;
 RenameFile(SourseDir + "\\Temp\\" + oldName + ".tee",
            SourseDir + "\\Temp\\" + newName + ".tee");
}


//----------------------------------------------------------------------------  переделать!
//   потому что после двух вкладок функция не работает  name - name(1) - name(1)
//----------------------------------------------------------------------------
int TForm1::RepeatTabName(const String& name)
{
 TSearchRec sr;
 String fullName = name + ".tee";
 int n = 0;
 if ( !FindFirst(SourseDir + "\\Temp\\" + "\\*.*", faAnyFile, sr))
 {
    do
    {
       if (sr.Name == fullName)
          ++n;
    }
    while ( !FindNext(sr));
 }
 return n;
}

//---------------------------------------------------------------------------
//    RenameTabClick
//---------------------------------------------------------------------------
void __fastcall TForm1::NRenameTabClick(TObject *Sender)
{
 PanelRenameTab->Parent = Chart1;
 PanelRenameTab->Visible = true;
 PanelRenameTab->Top = 20;
 PanelRenameTab->Left = Chart1->Width / 2;

 Edit9->Text = TabControl1->Tabs->Strings[TabControl1->TabIndex];
 Edit10->Text = "новая_вкладка";
}




//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonOKRenameClick(TObject *Sender)
{
 RenameTab(Edit10->Text);

 PanelRenameTab->Visible = false;
 PanelRenameTab->Parent = Panel11;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonExitRenameClick(TObject *Sender)
{
 PanelRenameTab->Visible = false;
 PanelRenameTab->Parent = Panel11;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::TabControl1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 TabControl1->PopupMenu = PopupMenuTab;        
}

//---------------------------------------------------------------------------
//   Открыть режим
//---------------------------------------------------------------------------
void __fastcall TForm1::NOpenRegimClick(TObject *Sender)
{
 OpenDialogMode->InitialDir = SourseDir + "\\Режимы\\";
 if(! OpenDialogMode->Execute())
    return;

 numMode.push_back(TabControl1->Tabs->Count);
 pathMode.push_back(OpenDialogMode->FileName);
 AddTab(OpenDialogMode->FileName);
}

//---------------------------------------------------------------------------
//    Сохранить режим как...
//---------------------------------------------------------------------------
void __fastcall TForm1::NSaveAsClick(TObject *Sender)
{
 SaveDialogMode->InitialDir = SourseDir + "\\Режимы\\";
 if(! SaveDialogMode->Execute())
    return;
 ChartToFile(SaveDialogMode->FileName, 1, 0);
}

//-----------------------------------------------------------------------------
// устанавливаем границы нижнего бара в соответсвии с временным отрезком
//-----------------------------------------------------------------------------
void TForm1::SetTimeBar(const float CurrStart, const float CurrEnd)
{
 LabelStartTime->Caption = ((TDateTime)Chart1->BottomAxis->Minimum).TimeString();
 LabelEndTime->Caption = ((TDateTime)Chart1->BottomAxis->Maximum).TimeString();

 float StartProcent = (CurrStart - SourseMinTime) / (SourseMaxTime - SourseMinTime);
 float EndProcent   = (SourseMaxTime - CurrEnd  ) / (SourseMaxTime - SourseMinTime);

 PanelStart->Width += (EndPanel - StartPanel) * StartProcent;
 PanelEnd->Width += (EndPanel - StartPanel) * EndProcent;

 int beta = 123;
}





void CutString(AnsiString** Mass, AnsiString& S, int i)
{
 int b = 0;                          // number of word
 int length = S.Length();
 while(length > 0)
 {
    int n = 1;
    while(AnsiString(S[n]) == " ")  // find first number symbol not NUll
    {
       n++;
       if(n >= length)
          return;
    }

    int s = n;                       // word started with symbol number n...
    while(AnsiString(S[s]) != " ")
    {
       s++;
       if(s >= length)
          break;
    }                                // ...and ended with symbol nymber s

    if( !i)
       Mass[b] = new AnsiString[50];

    Mass[b][i] = AnsiString(S.SubString(n, s-n));
    S = S.SubString(s, length);
    length = S.Length();
    b++;
 }
 return;
}

void testTxt(AnsiString** Mass)
{
 FILE* test;
 test = fopen("D:\Резервное_копирование\2014.02.04\_test.txt", "w+");
}


//----------------------------------------------------------------------------
//   Open Txt file                                                               !!! Work work work
//----------------------------------------------------------------------------
void __fastcall TForm1::NOpenTxtClick(TObject *Sender)
{
 OpenDialogTxt->Execute();
 
 char Buf[1024];
 AnsiString **strMass = new AnsiString*[50];

 FILE* file;
 file = fopen(OpenDialogTxt->FileName.c_str(), "r+");
 if(! file)
 {
     ShowMessage("Txt file isn't open");
     return;
 }

 AnsiString S;
 int c = 0;

 while(! feof(file))
 {
    if( fgets(Buf, 2048, file) == NULL )
    {
        ShowMessage("Can not read first string in text file " + OpenDialogTxt->FileName);
        return;
    }
    int poz = ftell(file);
    S = AnsiString(Buf);
    S = S.SubString(1, poz - 2);   // убираем символ \n
    CutString(strMass, S, c);
    ++c;
 }
 int dsaf = 0;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::PanelEndClick(TObject *Sender)
{
 LabelStartTime->Caption = ((TDateTime)Chart1->BottomAxis->Minimum).TimeString();
 LabelEndTime->Caption = ((TDateTime)Chart1->BottomAxis->Maximum).TimeString();

 float StartProcent = 0.1;
 float EndProcent   = 0.1;

 PanelStart->Width += (EndPanel - StartPanel) * StartProcent;
 PanelEnd->Width += (EndPanel - StartPanel) * EndProcent;
}


//---------------------------------------------------------------------------
//    вопрос перед выходом из программы
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
 int res = Application->MessageBoxA(
                        "Документ не сохранен. \n \n"
                        "Сохранить документ? \n \n"
                        "(Отмена - продолжение работы)",
                        "Подтвердите завершение работы",
                        MB_YESNOCANCEL + MB_ICONQUESTION);
 switch(res)
 {
     case IDYES:
                  SaveAllSettings();
                  break;
     case IDCANCEL:
                  CanClose = false;
 }
}


//---------------------------------------------------------------------------
//   сохранение настроек, форматок
//---------------------------------------------------------------------------
void TForm1::SaveAllSettings()
{
 iniFile->writeIniFile();
 iniFileMain->WriteString("Files", "LastFileIni", iniFile->iniFileName);

 SaveCurrentTab(SourseDir + "\\Temp\\");
 SaveFormat(iniFile->Format.SubString(1, iniFile->Format.Length() - 1) + ".fmt");

 //SaveINI();
}


//---------------------------------------------------------------------------
void __fastcall TForm1::NExitClick(TObject *Sender)
{
 Close();
}












void __fastcall TForm1::NnewTab2Click(TObject *Sender)
{
 OpenDialogFormat->InitialDir = iniFile->formatDir;
 OpenDialogFormat->FilterIndex = 2;

 if(OpenDialogFormat->Execute())
     AddTab(OpenDialogFormat->FileName);

 OpenDialogFormat->FilterIndex = 1;
}
//---------------------------------------------------------------------------

