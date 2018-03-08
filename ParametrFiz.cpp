//---------------------------------------------------------------------------


#pragma hdrstop

#include "ParametrFiz.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

//--------------------------------------------------------------------------
//   constructor 1
//--------------------------------------------------------------------------
ParameterFiz::ParameterFiz(const int NPasp, TChart* chart)
     : Parametr(NPasp, chart)
{
 Series = new TFastLineSeries(chart);
 Series->ParentChart = chart;
 Series->CustomVertAxis = Axis;
 Series->XValues->DateTime = true;
 chart->AddSeries(Series);

 Series->SeriesColor = Axis->Axis->Color;
 Series->Title = Axis->Title->Caption;
 Series->Tag = 0;

 SetMinMaxAxis();
 afterComma = "0.0";
};


//--------------------------------------------------------------------------
//   constructor 2
//--------------------------------------------------------------------------
ParameterFiz::ParameterFiz(TChart* chart, int itemSeries)
   : Parametr(chart, itemSeries)
{
 Series = (TFastLineSeries*)chart->SeriesList->Items[itemSeries + 1];           // + 1 because first series always exist for grid
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
//   copy constructor
//--------------------------------------------------------------------------
ParameterFiz::ParameterFiz(const ParameterFiz& P)
  : Parametr(P)
{
 Series = new TFastLineSeries(P.Series->ParentChart);
 Series->ParentChart = P.Series->ParentChart;
 Series->CustomVertAxis = Axis;
 Series->XValues->DateTime = true;
}

//--------------------------------------------------------------------------
//   assignment operator
//--------------------------------------------------------------------------
const ParameterFiz& ParameterFiz::operator = (const ParameterFiz& P)
{
 if(&P == this)
    return *this;
 Parametr::operator = (P);
 if(Series) delete Series;                 // why delete?
 Series = new TFastLineSeries(P.Series);
 return *this;
}


//---------------------------------------------------------------------------
//   установить min, max, increment оси
//---------------------------------------------------------------------------
void ParameterFiz::SetMinMaxAxis()
{
 Axis->SetMinMax(tekPaspChart->Min, tekPaspChart->Max);
 Axis->Increment = Axis->Maximum - Axis->Minimum;
 Axis->MinimumRound = 1;
 Axis->MaximumRound = 1;
}


/*  Series->Title имеет вид:  "Title NSis MarkerSymbol AfterComma Visible"
    фцнкция разбивает строчку Title на параметры
-----------------------------------------------------------------------------*/
void ParameterFiz::LoadSeriesTitle()
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
void ParameterFiz::SaveSeriesTitle()
{
 // sometimes string with settings may write several times
 int pos = Series->Title.Pos(" ");
 if(pos)
    Series->Title = Series->Title.SubString(1, pos - 1);

 Series->Title = Series->Title + " " + IntToStr(NSis) + " " + MarkerSymbol + " "
 + afterComma + " " + IntToStr(Axis->Visible);
}


//--------------------------------------------------------------------------
//   showInfo
//--------------------------------------------------------------------------
void ParameterFiz::showInfo()
{
 int x = Axis->PosAxis + 15;
 int y = Axis->IStartPos + 15;
 Axis->ParentChart->Canvas->Brush->Color = clInfoBk;
 Axis->ParentChart->Canvas->TextOutA(x, y, String(tekPaspChart->Name));
}


//------------------------------------------------------------------------------
//     findParBySeriesTitle
//------------------------------------------------------------------------------
/*ParameterFiz* ParameterFiz::findParBySeriesTitle(std::list<Parametr*> list, String& title)
{
 for(std::list<Parametr*>::iterator b = list.begin(), e = list.end(); b != e; ++b)
 {
    if( (*b)->Series->Title == title)
       return dynamic_cast<ParameterFiz*>(*b);
 }
 return NULL;
};  */


