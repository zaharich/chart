//---------------------------------------------------------------------------
/*   Definition of class Parametr                                          */
/*   Zakharchuk Andrew                                                     */
//---------------------------------------------------------------------------
#include "Parametr.h"

#pragma package(smart_init)

//---------------------------------------------------------------------------
//  возвращает число систем параметра
//---------------------------------------------------------------------------
int Parametr::CountOfSystem()
{
 int count = 0;
 for(int i = 0; i < 4; ++i)
    if((FlyingFile::Instance().getPtrPaspChart() + paspNumber)->NSis[i] != -1)
       count++;
 return count;
}


//---------------------------------------------------------------------------
Parametr::~Parametr()
{
 //delete Series;
 delete Axis;
}


//---------------------------------------------------------------------------
//  установить номер системы в наименование
//---------------------------------------------------------------------------
void Parametr::SetNSisInTitle(int ns)
{
 systemNumber = ns;
 Axis->Title->Caption = Axis->Title->Caption + " " + IntToStr(systemNumber);
}


//--------------------------------------------------------------------------
//   выбор системы (дл€ нового параметра)
//--------------------------------------------------------------------------
int Parametr::ChoiseSistem()
{
   /*int n = 0;
   bool mass[4] = {0, 0, 0, 0};
   for(int i=0; i<MKSERIES; i++)
   {
      if(Par[i] != NULL)
         if(Par[i]->Series->Title == S)
         {
            int j = Par[i]->systemNumber;
            mass[j-1] = 1;
         }
   }
   while(mass[n])
      n++;
   if((n+1) > SistemCounter(paspNumber))
      return n;
   return n+1;   */
   return 1;
}


//--------------------------------------------------------------------------
int Parametr::FindPosition()
{
   /*int c = 0;
   for(int i=0; i<MKSERIES; i++)
   {
      if(Par[i] != NULL)
            c++;
   }
   return c;  */
   return 0;
}


//------------------------------------------------------------------------------
//     constructor 1
//------------------------------------------------------------------------------
Parametr::Parametr(const int NumPasp, TChart* chart)
{
 // additional values
 paspNumber = NumPasp;
 tekPaspChart = FlyingFile::Instance().getPtrPaspChart() + paspNumber;
 String ident = tekPaspChart->Ident;
 int N = chart->SeriesCount() - 1;

 // create axis and series
 //Series = new TCustomLineSeries(chart);
 //Series->ParentChart = chart;
 Axis = new TChartAxis(chart);
 //Series->CustomVertAxis = Axis;
 Axis->Automatic = false;
 //Series->XValues->DateTime = true;
 //chart->AddSeries(Series);

 // Axis position, edit position
 int posaxis = -4;
 axisSizeInCell = 1;
 Axis->EndPosition = 100 - (N % 7) * 2 * chart->LeftAxis->Increment;
 Axis->StartPosition = (Axis->EndPosition) - (axisSizeInCell*chart->LeftAxis->Increment);
 Axis->PositionPercent = (N / 7)*posaxis + posaxis;

 // Color
 TColor color[] = {clBlue, clGreen, clRed, clFuchsia, clBlack, clOlive, clTeal, clGray};
 Axis->Axis->Color = color[N % 8];
 //Series->SeriesColor = color[N % 8];
 currentColor = color[N % 8];

 // Separation and grid
 Axis->RoundFirstLabel = false;
 Axis->Grid->Visible = false;

 // Ticks
 Axis->TickLength = 7;
 Axis->MinorTicks->Visible = true;        // ƒл€ увеличени€ площади оси(захват мыши)
 Axis->MinorTickLength = 12;
 Axis->MinorTickCount = 0;
 Axis->Ticks->Color = color[N % 8];

 // Title
 Axis->Title->Angle = 90;
 Axis->Title->Caption = ident;
 //Series->Title = ident;
 systemNumber = ChoiseSistem();
 Axis->Title->Visible = false;
 countSys = CountOfSystem();

 // символ маркера по умолчанию - 2-ой символ в идентификаторе
 markerSymbol = Axis->Title->Caption.SubString(2, 1);
}


//------------------------------------------------------------------------------
//     constructor 2
//------------------------------------------------------------------------------
Parametr::Parametr(TChart* chart, int itemSeries)
{
 //Series = (TCustomLineSeries*)chart->SeriesList->Items[itemSeries + 1];
 Axis = chart->CustomAxes->Items[itemSeries];
 axisSizeInCell = (Axis->EndPosition - Axis->StartPosition + 0.5) / chart->LeftAxis->Increment;
 //LoadSeriesTitle();
 /*paspNumber = FlyingFile::Instance().getStrData() ? StrToInt(FlyingFile::Instance().findPaspByIdent(Series->Title)) : -1;
 if(paspNumber >= 0)
 {
    countSys = CountOfSystem();
    tekPaspChart = FlyingFile::Instance().getPtrPaspChart() + paspNumber;
 }else
 {
    ShowMessage("Ќе возможно инициализировать параметр. ќбратитесь к разработчику.(paspNumber < 0, constructor 2)");
    return;
 } */
}


//---------------------------------------------------------------------------
//     default constructor
//---------------------------------------------------------------------------
Parametr::Parametr()
{
 Axis = 0;
 //Series = 0;
 systemNumber = 0;
 countSys = 0;
 paspNumber = 0;
 markerSymbol = "a";
 afterComma = "0.0";
}


//---------------------------------------------------------------------------
//    copy constructor
//---------------------------------------------------------------------------
Parametr::Parametr(const Parametr &P)
{
 // у Axis и Series  отсутствует конструктор копировани€
 //Series = new TCustomLineSeries(P.Series->ParentChart);
 //Series->ParentChart = P.Series->ParentChart;
 Axis = new TChartAxis(P.Axis->ParentChart);
 //Series->CustomVertAxis = Axis;
 Axis->Automatic = false;
 //Series->XValues->DateTime = true;

 systemNumber = P.systemNumber;
 countSys = P.countSys;
 paspNumber = P.paspNumber;
 markerSymbol = P.markerSymbol;
 afterComma = P.afterComma;
}

//------------------------------------------------------------------------------
//     assignment operation
//------------------------------------------------------------------------------
const Parametr& Parametr::operator=(const Parametr &P)
{
 if(this == &P) return *this;

 int test = 0;
 //if(Series) delete Series;
 //Series = new TCustomLineSeries(P.Series);
 if(Axis) delete Axis;
 Axis = new TChartAxis(*P.Axis);

 systemNumber = P.systemNumber;
 countSys = P.countSys;
 paspNumber = P.paspNumber;
 markerSymbol = P.markerSymbol;
 afterComma = P.afterComma;
 return *this;
}


//==============================================================================
//       DrawTitle
//==============================================================================
void Parametr::DrawTitle(bool printing, int kzoom)
{
 int x = Axis->PosAxis - 15;
 int y = Axis->IStartPos - 25;
 if(printing){
     Axis->ParentChart->Canvas->Font->PixelsPerInch = 96;
     Axis->ParentChart->Canvas->Font->Height = -2;
 }

 if(kzoom){
     Axis->ParentChart->Canvas->Font->Size = (kzoom + 1)*8;
     Axis->LabelsFont->Size = (kzoom + 1)*8;
 }
 else{
     Axis->ParentChart->Canvas->Font->Size = 8;
     Axis->LabelsFont->Size = 8;
 }

 if(Axis->Visible){
     Axis->ParentChart->Canvas->Font->Color = Axis->Title->Font->Color;
     Axis->ParentChart->Canvas->TextOutA(x, y, Axis->Title->Caption);
 }
}


//------------------------------------------------------------------------------
//     fulAxis
//------------------------------------------------------------------------------
void Parametr::FullAxis()
{
 Axis->Axis->Width = 3;
 Axis->Ticks->Width = 2 ;
 Axis->LabelsFont->Size = 9;
 Axis->Title->Font->Size = 9;
 Axis->LabelsFont->Name = "Arial Black";
}

//------------------------------------------------------------------------------
//     slimAxis
//------------------------------------------------------------------------------
void Parametr::SlimAxis()
{
 Axis->Axis->Width = 2;
 Axis->Ticks->Width = 1;
 Axis->LabelsFont->Size = 8;
 Axis->Title->Font->Size = 8;
 Axis->LabelsFont->Name = "Arial";
}


//------------------------------------------------------------------------------
//     findParBySeriesTitle
//------------------------------------------------------------------------------
/*Parametr* Parametr::findParBySeriesTitle(std::list<Parametr*> list, String& title)
{
    for(std::list<Parametr*>::iterator i = list.begin(); i != list.end(); ++i)
        if( (*i)->Series->Title == title)
            return reinterpret_cast<Parametr*>(*i);
    return NULL;
}; */

//------------------------------------------------------------------------------
//     findParByAxisTitle
//------------------------------------------------------------------------------
Parametr* Parametr::findParByAxisTitle(std::list<Parametr*> list, String& title)
{
    for(std::list<Parametr*>::iterator i = list.begin(); i != list.end(); ++i)
        if( (*i)->Axis->Title->Caption == title)
            return reinterpret_cast<Parametr*>(*i);
    return NULL;
};











//---------------------------------------------------------------------------
//  возвращает номер структуры RK ?where? по идентификатору
//---------------------------------------------------------------------------
/*int Parametr::GetNStructRK(int NumberRK, int max)
{
   String Ident = Series->Title;

   for(int i=0; i<max; i++){
      if(! strcmp((FlyingFile::Instance().getPtrRKChart() + i)->Ident, Ident.c_str())){
         if( (FlyingFile::Instance().getPtrRKChart() + i)->NRazRK == NumberRK)
            return i;
      }
   }
   ShowMessage("–азова€ команда " + Ident + " не найдена!");
   return 2606;
};     */


/*void Parametr::ShowInfo()
{
 // Canvas
 int x = Axis->PosAxis + 15;
 int y = Axis->IStartPos + 15;
 Axis->ParentChart->Canvas->Brush->Color = clInfoBk;

 if(NStructRK >= 0)
    Axis->ParentChart->Canvas->TextOutA(x, y, NameRK);
 else
    Axis->ParentChart->Canvas->TextOutA(x, y, String(tekPaspChart->Name));
}   */


/*void Parametr::LinkAxisToGrid(TChart* chart, TChartAxis* axis)
{
 float procentInCell = chart->LeftAxis->Increment;
 float lenghtAxis = procentInCell * axisSizeInCell;
{  */


//---------------------------------------------------------------------------
/*  Series->Title имеет вид:  "Title systemNumber markerSymbol NStructRK AfterComma"
    фцнкци€ разбивает Title на параметры
-----------------------------------------------------------------------------*/
/*void Parametr::LoadSeriesTitle()
{
   String s = Series->Title;
   int n = s.Pos(" ");
   //---  титл
   Series->Title = s.SubString(1, n-1);
   //---  номер системы
   systemNumber = StrToInt(s.SubString(n+1, 1));
   //---  символ маркера
   s = s.SubString((n+1)+2, 255);
   markerSymbol = s.SubString(0, 1);

   //---  разова€ команда
   s = s.SubString(3, 255);
   n = s.Pos(" ");
   NStructRK = (s.SubString(1, n-1)).ToInt();       // must be -1 or >=0
   if( NStructRK >= 0 ){
      NRK = (FlyingFile::Instance().getPtrRKChart() + NStructRK)->NRazRK;
      NameRK = (FlyingFile::Instance().getPtrRKChart() + NStructRK)->NameRK;
   }
   else{
      NRK = -1;
      NameRK = "";
   }

   //---  кол-во знаков после зап€той в виде строчки
   s = s.SubString(n+1, 255);
   n = s.Pos(" ");
   afterComma = s.SubString(1, n-1);
   //--- видимый/невидимый
   Axis->Visible = s.SubString(n+1, 255).ToInt();
   Series->Visible = Axis->Visible;
}   */



