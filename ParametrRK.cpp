//---------------------------------------------------------------------------


#pragma hdrstop

#include "ParametrRK.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------
//   constructor 1
//---------------------------------------------------------------------------
ParameterRK::ParameterRK(const int nPasp, TChart* chart, const int nRK)
     : Parametr(nPasp, chart)
{
 Series = new TAreaSeries(chart);
 Series->ParentChart = chart;
 Series->CustomVertAxis = Axis;
 Series->XValues->DateTime = true;
 chart->AddSeries(Series);

 Series->SeriesColor = Axis->Axis->Color;
 Series->Title = Axis->Title->Caption;
 Series->Tag = 1;

 SetMinMaxAxis();
 afterComma = "0";

 NRK = nRK;
 NStructRK = FlyingFile::Instance().findNStructRKByIdentNRK(Series->Title, NRK);
 if(NStructRK < 0)
 {
    this->~ParameterRK();    // TODO this is very bad
    return;
 }
 NameRK = (FlyingFile::Instance().getPtrRKChart() + NStructRK)->NameRK;
}


//--------------------------------------------------------------------------
//   constructor 2
//--------------------------------------------------------------------------
ParameterRK::ParameterRK(TChart* chart, int itemSeries)
   : Parametr(chart, itemSeries)
{
 Series = (TAreaSeries*)chart->SeriesList->Items[itemSeries + 1];               // + 1 because first series always exist for grid
 LoadSeriesTitle();
 NPasp = FlyingFile::Instance().findPaspByIdent(Series->Title);
 if(NPasp >= 0)
 {
    KolSis = CountOfSystem();
    tekPaspChart = FlyingFile::Instance().getPtrPaspChart() + NPasp;
 }else
 {
    ShowMessage("Не возможно инициализировать параметр. Обратитесь к разработчику.(NPasp < 0, constructor 2)");
    return;
 }   // if npasp  = -1, all the same parameter is build
     // must be flag-validate parameter
}


//--------------------------------------------------------------------------
//  copy constructor
//--------------------------------------------------------------------------
ParameterRK::ParameterRK(const ParameterRK &P)
  : Parametr(P)
{
 Series = new TAreaSeries(P.Series->ParentChart);
 Series->ParentChart = P.Series->ParentChart;
 Series->CustomVertAxis = Axis;
 Series->XValues->DateTime = true;
 NStructRK = P.NStructRK;
 NRK = P.NRK;
 NameRK = P.NameRK;
};


//--------------------------------------------------------------------------
//   assignment operator
//--------------------------------------------------------------------------
const ParameterRK& ParameterRK::operator = (const ParameterRK& P)
{
 if(&P == this)
    return *this;
 Parametr::operator = (P);
 NStructRK = P.NStructRK;
 NRK = P.NRK;
 NameRK = P.NameRK;
 if(Series) delete Series;           // why delete?
 Series = new TAreaSeries(P.Series);
 return *this;
}


//---------------------------------------------------------------------------
//   установить min, max, increment оси
//---------------------------------------------------------------------------
void ParameterRK::SetMinMaxAxis()
{
 Axis->SetMinMax(0, 1);
 Axis->Increment = 1;
}


//---------------------------------------------------------------------------
/*  Series->Title имеет вид:  "Title NSis MarkerSymbol AfterComma Visible"
    фцнкция разбивает строчку Title на параметры
-----------------------------------------------------------------------------*/
void ParameterRK::LoadSeriesTitle()
{
   AnsiString s = Series->Title;

   //---  титл
   int n = s.Pos(" ");
   Series->Title = s.SubString(1, n-1);

   //---  номер системы
   NSis = StrToInt(s.SubString(n+1, 1));

   //---  символ маркера
   s = s.SubString((n+1)+2, 255);
   MarkerSymbol = s.SubString(0, 1);

   //---  разовая команда
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

   //---  кол-во знаков после запятой в виде строчки
   s = s.SubString(3, 255);
   n = s.Pos(" ");
   afterComma = s.SubString(1, n-1);

   //--- видимый/невидимый
   Axis->Visible = s.SubString(n+1, 255).ToInt();
   Series->Visible = Axis->Visible;
}


//--------------------------------------------------------------------------
//   собрать в Title нужные нам параметры
//--------------------------------------------------------------------------
void ParameterRK::SaveSeriesTitle()
{
 // sometimes string with settings may write several times
 int pos = Series->Title.Pos(" ");
 if(pos)
    Series->Title = Series->Title.SubString(1, pos - 1);
 Series->Title = Series->Title + " " + IntToStr(NSis) + " " + MarkerSymbol + " "
 + IntToStr(NStructRK) + " " + afterComma + " " + IntToStr(Axis->Visible);
}


void ParameterRK::showInfo()
{
 int x = Axis->PosAxis + 15;
 int y = Axis->IStartPos + 15;
 Axis->ParentChart->Canvas->Brush->Color = clInfoBk;
 Axis->ParentChart->Canvas->TextOutA(x, y, NameRK);
}


