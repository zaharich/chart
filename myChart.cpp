//---------------------------------------------------------------------------


#pragma hdrstop                                      

#include "myChart.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
typedef std::list<Parametr*>::iterator list_it;

const int myChart::MAXCOUNTSERIES = 50;
const double myChart::LEFTAXISLENGHT = 100;
const double myChart::SEC = 1.0/86400;


//==============================================================================
//             myChart
//==============================================================================
myChart::myChart(TScrollBox* container, TStringGrid* sg, TPopupMenu* contexMenu, TPopupMenu* axisMenu)
    : currentPar(NULL)
    , stringGrid(sg)
    , zoomButton(false)
    , referButton(false)
    , cutIntervalButton(false)
    , SelectAxis(false)
    , mouseDown(false)
    , printing(false)
    , building(false)
    , countHorizLine(20)
    , countVertLine(10)
    , build(NO_BUILD)
    , button(0)
{
  chart = new TChart(container);
  chart->Parent = container;
  chart->Align = alClient;
  chart->View3D = false;

  Series1 = new TFastLineSeries(chart);          // без Series1 не будет
  Series1->ParentChart = chart;                  // горизонтальных линий
  chart->AddSeries(Series1);                     // сетки
  Series1->XValues->DateTime = true;

  chart->Title->Clear();
  chart->SubTitle->Text->Add(0);
  chart->SubTitle->Text->Add(0);

  _contexMenu = contexMenu;
  _axisMenu = axisMenu;
  chart->PopupMenu = _contexMenu;

  chart->OnClickAxis = chartClickAxis;
  chart->OnMouseDown = chartMouseDown;
  chart->OnMouseMove = chartMouseMove;
  chart->OnMouseUp = chartMouseUp;
  chart->OnAfterDraw = chartAfterDraw;
};


//==============================================================================
//         ~myChart
//==============================================================================
myChart::~myChart()
{
  delete Series1;
  delete chart;
};


//==============================================================================
//               chartInit
//==============================================================================
void myChart::chartInit()
{
  chart->BottomAxis->DateTimeFormat = "HH:mm:ss";
  chart->BottomAxis->Axis->Width = 1;
  chart->BottomAxis->Automatic = false;
  chart->BottomAxis->SetMinMax(0., 1.);
  chart->BottomAxis->Increment = 1. / (countVertLine + 1);
  chart->BottomAxis->MinorTickCount = 0;
  chart->BottomAxis->RoundFirstLabel = false;
  chart->BottomAxis->LabelsSize = 1;
  chart->BottomAxis->LabelsSeparation = 0;      // чтобы показывались все линии
  chart->BottomAxis->PositionUnits = muPercent;

  chart->LeftAxis->Axis->Width = 1;
  chart->LeftAxis->Automatic = false;
  chart->LeftAxis->SetMinMax(0, LEFTAXISLENGHT);
  chart->LeftAxis->Increment = 5;
  chart->LeftAxis->LabelsSeparation = 0;        // чтобы показывались все линии
  chart->Color = clAqua;
  chart->LeftAxis->LabelsFont->Color = chart->Color;

  chart->MarginTop = 2;
  chart->MarginBottom = 3;
  chart->MarginRight = 3;
  chart->MarginLeft = 10;

  chart->Zoom->Allow = false;
  chart->Legend->Visible = false;
  chart->Title->Visible = false;
  chart->SubTitle->Visible = false;

  stretch = 0;
  button = MOVE;
  int t = button;
};


//==============================================================================
//           loadEdit
//==============================================================================
void myChart::loadEdit()
{
 //AnsiString str, bufStr;         // todo          values for this function or two different functions
 //int pos = 0;
 for(int i = 0; i < chart->Title->Text->Count; ++i){
     AnsiString str = chart->Title->Text->Strings[i];
     int pos = str.Pos("$") - 1;
     AnsiString buffStr = str.SubString(0, pos);
     bool visible = buffStr.ToInt();
     str = str.SubString(pos + 2, 255);      // +2 чтобы не захватывать разделитель $

     pos = str.Pos("$") - 1;
     buffStr = str.SubString(0, pos);
     AnsiString caption = buffStr;         // Caption
     str = str.SubString(pos + 2, 255);

     pos = str.Pos("$") - 1;
     buffStr = str.SubString(0, pos);
     int left = buffStr.ToInt();           // Left
     str = str.SubString(pos + 2, 255);

     int top = str.ToInt();                // Top

     addLabel();
     labelList.back()->setCaption(visible, caption);
     labelList.back()->setPosition(left, top);
 }
 // get edge time from subTitle
 String str = chart->SubTitle->Text->Strings[0];

 int pos1 = str.Pos("$") - 1;
 String tmp = str.SubString(0, pos1);
 //tmp = Singleton::getInstance().TrueSeparator(tmp);
 double min = StrToFloat(tmp);
 str = str.SubString(pos1 + 2, 255);

 pos1 = str.Pos("$") - 1;
 tmp = str.SubString(0, pos1);
 //tmp = Singleton::getInstance().TrueSeparator(tmp);
 double max = StrToFloat(tmp);
 str = str.SubString(pos1 + 2, 255);

 build = StrToInt(str);
 chart->BottomAxis->SetMinMax(min, max);

 // Grid
 countHorizLine = LEFTAXISLENGHT / chart->LeftAxis->Increment - 0.5;
 countVertLine = (chart->BottomAxis->Maximum - chart->BottomAxis->Minimum) /
                    chart->BottomAxis->Increment - 0.5;
 int test = 45;
};


//==============================================================================
//            ChartToFile
//==============================================================================
void myChart::ChartToFile(const AnsiString& pathToTeeFile, bool includeData, bool textFormat)
{
 // save position and caption of text(labels) on chart. Format("Visible$Caption$Left$Top")
 chart->Title->Clear();
 for(std::list<myLabel*>::iterator i = labelList.begin(); i != labelList.end(); ++i){
    chart->Title->Text->Add( AnsiString( IntToStr((*i)->Visible) + "$" +
    (*i)->Caption + "$" + (*i)->Left + "$" + (*i)->Top) );
 }

 // save min-max of bottom axis and build type(no, slow, quick). Format("min$max$build")
 chart->SubTitle->Text->Strings[0] = FloatToStr(chart->BottomAxis->Minimum)
         + "$" + FloatToStr(chart->BottomAxis->Maximum) + "$" + IntToStr(build);

 // save parametr settings. Format("Title Nsis markerSymbol NStructRK afterComma Visible")
 for(list_it i = mainList.begin(); i != mainList.end(); ++i)
     (*i)->SaveSeriesTitle();

 SaveChartToFile(chart, pathToTeeFile, includeData, textFormat);    // встроенная
};


//==============================================================================
//       openChartFromFile
//==============================================================================
bool myChart::openChartFromFile(const String& teeName)
{
 // check teeName
 if( !FileExists(teeName))
 {
     if(ExtractFileName(teeName) == "Вкладка_1.tee")
         return false;
     if(teeName != "")
         ShowMessage("Файл \"" + teeName + "\" не найден. (OCFF)");
     return false;
 }

 LoadChartFromFile(dynamic_cast<TCustomChart*>(chart), teeName);   // встроенная
 loadEdit();

 // create
 for(int i = 0; i < (chart->SeriesList->Count - 1); ++i)
 {
     Parametr* p;
     if(chart->SeriesList->Items[i+1]->Tag)
        p = new ParameterRK(chart, i);
     else
        p = new ParameterFiz(chart, i);
     mainList.push_back(p);
 }
 timeBar->ChartToTimeBar();
 return true;
};


//==============================================================================
//            setMinMaxBottomAxis
//==============================================================================
void myChart::setMinMaxIncrementBottomAxis(int minTime, int maxTime){
 if( (minTime < 0) || (maxTime < 0) || (minTime >= maxTime) )
    return;
 chart->BottomAxis->SetMinMax(minTime * SEC, maxTime * SEC);
 chart->BottomAxis->Increment = ((maxTime - minTime) * SEC) / (countVertLine + 1);
};


//==============================================================================
//           addParametr
//==============================================================================
void myChart::addParametr(int numPasp, int numRK)
{
 if(numRK > 0)
 {
    ParameterRK *pr = new ParameterRK(numPasp, chart, numRK);
    mainList.push_back(pr);
 }
 else if(numRK == 0)
 {
    ParameterFiz *pf = new ParameterFiz(numPasp, chart);
    mainList.push_back(pf);
 }
};

// templates
//http://microsin.net/programming/pc/an-idiots-guide-to-cpp-templates-part1.html

//==============================================================================
//           deleteParametr
//==============================================================================
void myChart::deleteParametr(Parametr* P)
{
  mainList.remove(P);
  delete P;
  P = NULL;
  currentPar = NULL;
};

void myChart::deleteParametr(TChartAxis* axis)
{
  for(list_it b = mainList.begin(), e = mainList.end(); b != e; ++b)
    if( axis == (*b)->Axis ){
      mainList.remove(*b);
      delete *b;
      *b = NULL;
      currentPar = NULL;
      break;
    }
};


//==============================================================================
//             deleteAllParameters
//==============================================================================
void myChart::deleteAllParametrs()
{
 while( !mainList.empty()){
    Parametr* p = mainList.back();
    mainList.pop_back();
    delete p;
 }
 currentPar = NULL;
}


//==============================================================================
//           printParametrsTo
//==============================================================================
void myChart::printParametrsTo()
{
 AnsiString str = "";
 for(list_it i = mainList.begin(); i != mainList.end(); ++i)
    str += (*i)->GetSeriesTitle() + "; ";
 ShowMessage(str);
};

void myChart::printParametrsTo(TStringGrid* dest)
{
 dest->RowCount = 0;
 int i = 0;
 for(list_it b = mainList.begin(), e = mainList.end(); b != e; ++b)
 {
    dest->RowCount++;
    dest->Cells[0][i++] = (*b)->Axis->Title->Caption;
 }
 dest->RowCount--;
}

void myChart::printParametrsTo(TListBox* dest)
{
 dest->Clear();
 int i = 0;
 for(list_it b = mainList.begin(), e = mainList.end(); b != e; ++b){
     dest->AddItem((*b)->Axis->Title->Caption, dest);
     if( (*b) == getCurrentParametr() )
         dest->Selected[i] = true;
     i++;
 }
}

/*inline void myChart::printParametrsWithValue(TStringGrid* dest)
{
 for(list_it b = mainList.begin(), e = mainList.end(); b != e; ++b)
    dest->Cells[1][i++] = (*b)->Axis->Title->Caption;
}  */


//==============================================================================
//     getArrayOfParam
//==============================================================================
/*void myChart::getArrayOfParam(TStringGrid dest){
 int i = 0;
 for(list_it it = mainList.begin(), e = mainList.end(); it != e; ++it)
     dest->Cells[0][i++] = (*it)->Axis->Title->Caption;
}     */


//==============================================================================
//                     нажатие на ось
//==============================================================================
void __fastcall myChart::chartClickAxis(TCustomChart *Sender,
      TChartAxis *Axis, TMouseButton Button, TShiftState Shift, int X, int Y)
{
 if( (Axis == Axis->ParentChart->BottomAxis) ||
     (Axis == Axis->ParentChart->LeftAxis) ||
     (Axis == Axis->ParentChart->TopAxis) ||
     (Axis == Axis->ParentChart->RightAxis) )
     return;

 currentPar = findParByAxis(Axis);
 currentPar->showInfo();

 // control by button;
 if(button != NONE)
 {
    if(button == DEL){
      deleteParametr(currentPar->Axis);
      return;
    }
    if(button == MINMAX){
      createMinMaxEdit(Axis);
      return;
    }
    if(button == VISIBLE)
       currentPar->Axis->Visible = false;
 }

 chart->PopupMenu = _axisMenu;

 AxisMin = Axis->Minimum;
 AxisMax = Axis->Maximum;
 AxisIncrement = Axis->Increment;

 if(stretch == 0)
    stretch = 1;
 SelectAxis = true;
 // запоминаем по какой из частей оси кликнули
 UpHalfAxis = (Y < (Axis->IStartPos) + (Axis->IAxisSize) / 2) ? true : false;
};


//==============================================================================
//                     Mouse Down
//==============================================================================
void __fastcall myChart::chartMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 if(currentPar)
 {
    currentPar->slimAxis();
    //currentPar = NULL;
 }
 X0 = X;  Y0 = Y;

 if(Button == mbLeft && chart->ChartRect.Left < X   &&    // выделение мышью
                        X < chart->ChartRect.Right  &&    // временного отрезка
                        ! referButton               &&
                        chart->ChartRect.Top < Y    &&    // обрамление черным
                        Y < chart->ChartRect.Bottom &&    // цветом
                        chart->SeriesCount() > 1      )   //
 {
    double no;
    chart->SeriesList->Items[0]->GetCursorValues(CutX0, no);  // все равно к какой серии применять GetCursorValues
    //chart->Canvas->Pen->Mode = pmNotXor;                      // потому что все привязаны к нижней оси, а второй параметр не нужен
    //chart->Canvas->Brush->Style = bsClear;
    //chart->Canvas->Brush->Color = clBlack;

    //chart->Canvas->TextOutA(X, chart->LeftAxis->IEndPos + 6, ((TDateTime)CutX0).TimeString());
 }
 else{
     chart->Canvas->Pen->Mode = pmCopy;
     chart->Canvas->Brush->Color = clWhite;
 }

 if(Button == mbRight)
    chart->PopupMenu = zoomButton ? NULL : _contexMenu;

 cutIntervalButton = false;
 chart->Refresh();
 mouseDown = true;
};


//==============================================================================
//               перенос оси мышью
//==============================================================================
void myChart::AxisMove(double dy, double dx)
{
  currentPar->Axis->StartPosition += dy;
  currentPar->Axis->EndPosition += dy;
  currentPar->Axis->PositionPercent += dx;
};


//==============================================================================
//           растягивание оси
//==============================================================================
void myChart::AxisStretch(int PixelInCell, int y1)
{
 int v;
 if((Y0 - y1) > PixelInCell){
    Y0 = y1;
    v = floor((AxisMax - AxisMin) / currentPar->Axis->Increment + 1 + 0.5);
    currentPar->Axis->Increment = (currentPar->Axis->Maximum - currentPar->Axis->Minimum) / v;
    currentPar->Axis->StartPosition = currentPar->Axis->StartPosition - chart->LeftAxis->Increment;
 }
 if((Y0 - y1) < -PixelInCell){
    if((currentPar->Axis->Maximum - currentPar->Axis->Increment) <= currentPar->Axis->Minimum) return;
    Y0 = y1;
    v = floor((AxisMax - AxisMin) / currentPar->Axis->Increment - 1 + 0.5);
    currentPar->Axis->Increment = (currentPar->Axis->Maximum - currentPar->Axis->Minimum) / v;
    currentPar->Axis->StartPosition = currentPar->Axis->StartPosition + chart->LeftAxis->Increment;
 }
};


//==============================================================================
//               Увеличение/уменьшение оси
//==============================================================================
void myChart::MoveMaxMinAxis(const int PixelInCell, int y, const bool UpHalfAxis)
{
 if(UpHalfAxis){
    if((Y0 - y) > PixelInCell){
       Y0 = y;
       currentPar->Axis->Maximum = currentPar->Axis->Maximum + AxisIncrement;
       currentPar->Axis->StartPosition = currentPar->Axis->StartPosition - chart->LeftAxis->Increment;
    }
    if((Y0 - y) < -PixelInCell){
       if((currentPar->Axis->Maximum - currentPar->Axis->Increment) <= currentPar->Axis->Minimum)
          return;
       Y0 = y;
       currentPar->Axis->Maximum = currentPar->Axis->Maximum - AxisIncrement;
       currentPar->Axis->StartPosition = currentPar->Axis->StartPosition + chart->LeftAxis->Increment;
    }
 }
 else{
    if((Y0 - y) > PixelInCell){
       if((currentPar->Axis->Minimum + currentPar->Axis->Increment) >= currentPar->Axis->Maximum)
          return;
       Y0 = y;
       currentPar->Axis->Minimum = currentPar->Axis->Minimum + AxisIncrement;
       currentPar->Axis->EndPosition = currentPar->Axis->EndPosition - chart->LeftAxis->Increment;
    }
    if((Y0 - y) < -PixelInCell){
       Y0 = y;
       currentPar->Axis->Minimum = currentPar->Axis->Minimum - AxisIncrement;
       currentPar->Axis->EndPosition = currentPar->Axis->EndPosition + chart->LeftAxis->Increment;
    }
 }
};


//==============================================================================
//                       MouseMove
//==============================================================================
void __fastcall myChart::chartMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
 // draw zoom rectangle
 if(zoomButton){
    chart->Repaint();
    chart->Canvas->Brush->Style = bsClear;
    chart->Canvas->Rectangle(X - (chart->Width >> 2) / (kzoom + 1), Y - (chart->Height >> 2) / (kzoom + 1),
                             X + (chart->Width >> 2) / (kzoom + 1), Y + (chart->Height >> 2) / (kzoom + 1));
    return;
 }

 // при наведении на шкалу, она подсвечивается
 for(list_it i = mainList.begin(); i != mainList.end(); ++i)
 {
    if( (*i)->Axis->Clicked(X, Y) )
       (*i)->fullAxis();
    else
       (*i)->slimAxis();
 }

 // курсор в поле графиков
 if(chart->ChartRect.Left < X && X < chart->ChartRect.Right  &&
    chart->ChartRect.Top < Y  && Y < chart->ChartRect.Bottom &&
                                      chart->SeriesCount() > 1)
 {
    if(mouseDown && X0 != X){
       if(! referButton){      // выделение интервала
          chart->Refresh();
          chart->Canvas->Pen->Mode = pmNotXor;
          chart->Canvas->Brush->Color = clBlack;
          chart->Canvas->Rectangle(X0, chart->LeftAxis->IStartPos, X, chart->LeftAxis->IEndPos);

          double y;
          chart->SeriesList->Items[1]->GetCursorValues(CutX1, y);
          chart->Canvas->Brush->Color = clWhite;
          chart->Canvas->TextOutA(X, chart->LeftAxis->IEndPos + 6, ((TDateTime)CutX1).TimeString());
          chart->Canvas->TextOutA(X0, chart->LeftAxis->IEndPos + 6, ((TDateTime)CutX0).TimeString());

          cutIntervalButton = true;
          return;
       }
       else{                     // визирная линия
          double x, y;
          chart->SeriesList->Items[0]->GetCursorValues(x, y);
          chart->Refresh();
          chart->Canvas->Pen->Color = clBlack;   // for black refer line
          chart->Canvas->MoveTo(X, chart->LeftAxis->IStartPos);
          chart->Canvas->LineTo(X, chart->LeftAxis->IEndPos);

          chart->Canvas->Pen->Color = clWhite;
          chart->Canvas->TextOutA(X, chart->LeftAxis->IEndPos + 6, ((TDateTime)x).TimeString());

          for(list_it i = mainList.begin(), e = mainList.end(); i != e; ++i){
              if((*i)->GetSeries()->Count())
              {
                   int ct = (*i)->GetSeries()->Count();
                   float pr = (x - (*i)->GetSeries()->MinXValue()) / (float((*i)->GetSeries()->MaxXValue()) - (float)(*i)->GetSeries()->MinXValue());
                   float y7 = (*i)->GetSeries()->YValue[pr * ct];
                   chart->Canvas->TextOutA(X, (*i)->GetSeries()->CalcYPos(pr * ct), FormatFloat((*i)->afterComma, y7));
              }
          }
          return;
       }
    }
    else{        //    вывод численных значений
       if(chart->SeriesCount() > 1 && !referButton && !cutIntervalButton && !building){
           // чтобы не работало в пустых зонах
           int k = chart->SeriesList->Items[1]->Count();
           if( k < 1 ) return;
           int x0 = chart->SeriesList->Items[1]->CalcXPos(1);
           int x1 = chart->SeriesList->Items[1]->CalcXPos(k-1);
           if(X < x0 || X > x1 )
               return;
               
           double x, y;
           chart->SeriesList->Items[1]->GetCursorValues(x, y);
           chart->Refresh();
           chart->Canvas->Pen->Color = clGray;
           chart->Canvas->MoveTo(X, chart->LeftAxis->IStartPos);
           chart->Canvas->LineTo(X, chart->LeftAxis->IEndPos);

           int j = 0, countPoints = 0;
           float procent;
           double min, delta;

           for(list_it i = mainList.begin(); i != mainList.end(); ++i){
               if( countPoints = (*i)->GetSeries()->Count() ){
                  min = (*i)->GetSeries()->MinXValue();
                  delta = (*i)->GetSeries()->MaxXValue() - min;
                  procent = (x - min) / delta;
                  if(procent > 0){
                     stringGrid->Cells[0][j] = (*i)->Axis->Title->Caption;
                     stringGrid->Cells[1][j++] = FormatFloat((*i)->afterComma, (*i)->GetSeries()->YValue[procent * countPoints]);
                  }
               }
           }
           return;
       }
    }
 }

 // выбрана ось
 if(SelectAxis)
 {
    double dy = (LEFTAXISLENGHT / chart->LeftAxis->IAxisSize) * (Y - Y0),
           dx = (LEFTAXISLENGHT / chart->BottomAxis->IAxisSize) * (X - X0);
    int PixelInCell = chart->LeftAxis->IAxisSize / (LEFTAXISLENGHT / chart->LeftAxis->Increment);

    if(button == STRETCH)   // растяжка оси одинакова в двух режимах
       AxisStretch(PixelInCell, Y);
    else
    {  // УПРАВЛЕНИЕ КНОПКАМИ
       if(button != NONE)
       {
          if(button == MOVE)
          {
              AxisMove(dy, dx);
              X0 = X; Y0 =Y;
          }
          if(button == ADDINC)
              MoveMaxMinAxis(PixelInCell, Y, UpHalfAxis);
       }
       // УПРАВЛЕНИЕ ТОЛЬКО МЫШЬЮ
       else{
          if(stretch != 3)
          {
             AxisMove(dy, dx);
             X0 = X; Y0 =Y;
          }
          else
             MoveMaxMinAxis(PixelInCell, Y, UpHalfAxis);
       }
    }
    if(stretch == 1)
       stretch = 2;                                                                                                                                     //                                                                           //
 }
};


//--------------------------------------------------------------------------
//                            MouseUp
//---------------------------------------------------------------------------
void __fastcall myChart::chartMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
 if(SelectAxis)
 {
    if(linkAxisButton)
        LinkToGrid(currentPar->Axis);
    if(stretch == 2 || stretch == 3)
        stretch = 0;
    if(stretch == 1)
        stretch = 3;
    if(X < 5)
        currentPar->invisible();
 }

 mouseDown = false;
 SelectAxis = false;

 if(zoomButton)
 {
    if(Button == mbLeft && kzoom < 3)
    {
       ++kzoom;
       chart->Align = alNone;
       chart->Width *= 2;
       chart->Height *= 2;
       ((TScrollBox*)chart->Parent)->HorzScrollBar->Position = 2*X - chart->Width / (4*kzoom);
       ((TScrollBox*)chart->Parent)->VertScrollBar->Position = 2*Y - chart->Height / (4*kzoom);
       chart->Canvas->Font->Size << 1;
    }
    if(Button == mbRight && kzoom > 0){
       --kzoom;
       chart->Width /= 2;
       chart->Height /= 2;
       chart->Canvas->Font->Size >> 1;
    }

    chart->Refresh();
    //TabControl1->PopupMenu = NULL;
    ((TTabControl*)((chart->Parent)->Parent))->PopupMenu = NULL;
    return;
 }
};


//==============================================================================
//          LinkToGrid
//==============================================================================
void myChart::LinkToGrid(TChartAxis *Axis){
   double delta = chart->LeftAxis->Increment;
   //double heightGridCell = chart->LeftAxis->IAxisSize / countMainHorizLine;
   double lengthAxisInProcent = Axis->EndPosition - Axis->StartPosition;
   int a = (Axis->StartPosition + 0.5 * delta) / delta;    // округление за счет
   Axis->StartPosition = a*delta;
   Axis->EndPosition = a*delta + lengthAxisInProcent;

   /*double delta = Chart1->LeftAxis->Increment;
   double LengthAxisInProcent = Axis->EndPosition - Axis->StartPosition;
   int a = (Axis->StartPosition + 0.5 * delta) / delta;
   Axis->StartPosition = a * delta;
   Axis->EndPosition = a * delta + LengthAxisInProcent;     */
};


//==============================================================================
//     AxisNewPosition
//==============================================================================
void myChart::AxisNewPosition()
{
 int axisDeltaHorizontal = 0;
 double shiftEndPosition = 100;
 bool shift = false;

 for(list_it b = mainList.begin(), e = mainList.end(); b != e; ++b){
    TChartAxis* a = (*b)->Axis;
    double oldIncrement = ( a->EndPosition - a->StartPosition ) / (*b)->axisSizeInCell;
    double hightAboveFloor = ( 100 - a->EndPosition ) / oldIncrement;
    a->EndPosition = 100 - ( hightAboveFloor * chart->LeftAxis->Increment );
    a->StartPosition = a->EndPosition - ( chart->LeftAxis->Increment * (*b)->axisSizeInCell );

    // shift axis X position
    if( a->EndPosition < 5 ){
       if( shift ){
          a->EndPosition = shiftEndPosition;
          a->StartPosition = a->EndPosition - ( chart->LeftAxis->Increment * (*b)->axisSizeInCell );
          shiftEndPosition = a->StartPosition - chart->LeftAxis->Increment;
          if(a->StartPosition < -10)
             shift = false;
       }
       if( !shift ){
          axisDeltaHorizontal += -4;
          shift = true;
          a->EndPosition = shiftEndPosition;
          a->StartPosition = a->EndPosition - ( chart->LeftAxis->Increment * (*b)->axisSizeInCell );
          shiftEndPosition = a->StartPosition - chart->LeftAxis->Increment;
       }
    }
    else{
       shift = false;
       shiftEndPosition = 100;
    }
    a->PositionPercent += axisDeltaHorizontal;

    // shift chart margin
    if( a->PositionPercent < -(chart->MarginLeft + 2)){
       chart->MarginLeft += 3;
    }
 }
}


//==============================================================================
//           DrawEndItems
//==============================================================================
void myChart::DrawEndIdents()
{
   /*for(int i=0; i<Form1->KolSeries; i++){
      Line[i] = (TFastLineSeries *)Form1->Chart1->SeriesList->Items[i+1];
      if(! Line[i]->Count())
         return;
      Axis[i] = Form1->Chart1->CustomAxes->Items[i];
      if(printing){
         //Form1->Chart1->Canvas->Font->PixelsPerInch = (Form1->Edit2->Text).ToInt();
         //Form1->Chart1->Canvas->Font->Size = (Form1->Edit5->Text).ToInt();
         //Form1->Chart1->Canvas->Font->Height = (Form1->Edit7->Text).ToInt();
      }
      double YValue = Line[i]->CalcYPos(Line[i]->LastDisplayedIndex());
      double XValue = Line[i]->CalcXPos(Line[i]->LastDisplayedIndex());
      Form1->Chart1->Canvas->Font->Color = Line[i]->Pen->Color;
      Form1->Chart1->Canvas->TextOut(XValue+10, YValue-10, Axis[i]->Title->Caption);
   }  */
};


//==============================================================================
//             Перерисовка канвы
//==============================================================================
void __fastcall myChart::chartAfterDraw(TObject *Sender)
{
 if(building)
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
             if(printing)
                Chart1->Canvas->Font->Size = -2;
             else
                Chart1->Canvas->Font->Size = -12;
             Chart1->Canvas->Font->Color = Par[i]->Series->Color;
             for(int j=0; j<6; j++)
                Chart1->Canvas->TextOut(Par[i]->Series->CalcXPos(j*a+1), Par[i]->Series->CalcYPos(j*a+1)-15, Par[i]->markerSymbol);
          }
       }
    }
 }   */

 // Печать
 if(printing){
    for(int i = 0; i < 3; ++i){
      chart->Canvas->Font->Name = "Times New Roman";
      chart->Canvas->Font->PixelsPerInch = 96;                                 //(Edit2->Text).ToInt();
      chart->Canvas->Font->Height = -2;                                        // (Edit7->Text).ToInt();
      //chart->Canvas->TextOut(label[i]->Left, label[i]->Top, label[i]->Caption);
    }
    for(list_it i = mainList.begin(); i != mainList.end(); ++i)
        (*i)->DrawTitle(false, kzoom);
 }
 else{
    for(list_it i = mainList.begin(), e = mainList.end(); i != e; ++i){
        (*i)->DrawTitle(false, 0);
    }
 }
};


//==============================================================================
//             recognizeButton
//==============================================================================
void myChart::recognizeButton(TSpeedButton* b, bool checkBoxMouse)
{
  if( !checkBoxMouse)
    button = NONE;
  if(b->Name == "SpeedButtonMove")
    button = MOVE;
  if(b->Name == "SpeedButtonMaxMin")
    button = MINMAX;
  if(b->Name == "SpeedButtonAddInc")
    button = ADDINC;
  if(b->Name == "SpeedButtonStretch")
    button = STRETCH;
  if(b->Name == "SpeedButtonDelete")
    button = DEL;
  if(b->Name == "SpeedButtonVisible")
    button = VISIBLE;

  if(b->Name == "buttonZoomIn" && b->Down)
    zoomButton = true;
  else
    zoomButton = false;
  if(b->Name =="buttonReperLine" && b->Down)
    referButton = true;
  else
    referButton = false;
  if(b->Name == "buttonLinkingGrid" && b->Down)
    linkAxisButton = true;
  else
    linkAxisButton = false;
};


//==============================================================================
//       ButtonMinMaxOk                                                               // Error ! если при нажатии на кнопку
//==============================================================================      // ОК, ось не выделенна.
void __fastcall myChart::buttonMinMaxOkClick(TObject *Sender)
{
 int inc = (currentPar->Axis->Maximum - currentPar->Axis->Minimum)/currentPar->Axis->Increment;
 if( (editMin->Text).ToDouble() >= (editMax->Text).ToDouble() ){
    ShowMessage("Максимальное значение оси должно быть больше минимального!");
    return;
 }
 currentPar->Axis->SetMinMax(editMin->Text.ToDouble(), editMax->Text.ToDouble());
 currentPar->Axis->Increment = (currentPar->Axis->Maximum - currentPar->Axis->Minimum)/inc;

 deleteMinMaxEdit();
};


//==============================================================================
//         labelInfoOn   -  OFF
//==============================================================================
void myChart::labelInfoOn()
{
 labelInfo = new TLabel(chart);
 labelInfo->Parent = chart;
 labelInfo->Caption = "Для остановки построения нажмите клавишу \"Q\"";
 //labelInfo->Width = 200;
 labelInfo->Height = 30;
 labelInfo->Top = chart->Height >> 1;
 labelInfo->Left = chart->Width >> 2;
};

void myChart::labelInfoOff()
{
 if(labelInfo)
    delete labelInfo;
 labelInfo = 0;
};


//==============================================================================
//        createMinMaxEdit      -   delete
//==============================================================================
void myChart::createMinMaxEdit(TChartAxis* axis)
{
  //---- editMin
  if(editMax != 0)
  {
    delete editMax;
    editMax = 0;
  }
  editMax = new TEdit(chart);
  editMax->Parent = chart;

  editMax->BorderStyle = bsNone;
  editMax->Width = 40;
  editMax->Height = 17;
  axis->PositionUnits = muPixels;
  editMax->Left = axis->PosAxis - editMax->Width - 7;
  axis->PositionUnits = muPercent;
  editMax->Top = axis->IStartPos - editMax->Height/2;
  editMax->Text = axis->Maximum;

  //---- editMax
  if(editMin != 0)
  {
    delete editMin;
    editMin = 0;
  }
  editMin = new TEdit(chart);
  editMin->Parent = chart;

  editMin->BorderStyle = bsNone;
  editMin->Width = 40;
  editMin->Height = 17;
  axis->PositionUnits = muPixels;
  editMin->Left = axis->PosAxis - editMin->Width - 7;
  axis->PositionUnits = muPercent;
  editMin->Top = currentPar->Axis->IEndPos - editMin->Height/2;
  editMin->Text = currentPar->Axis->Minimum;

  //---- buttonMinMaxOk
  if(buttonMinMaxOk != 0)
  {
    delete buttonMinMaxOk;
    buttonMinMaxOk = 0;
  }
  buttonMinMaxOk = new TButton(chart);
  buttonMinMaxOk->Parent = chart;

  buttonMinMaxOk->Caption = "OK";
  buttonMinMaxOk->Width = 25;
  buttonMinMaxOk->Height = 17;
  buttonMinMaxOk->Left = editMin->Left + editMin->Width;
  buttonMinMaxOk->Top = editMin->Top;
  buttonMinMaxOk->OnClick = buttonMinMaxOkClick;
};

void myChart::deleteMinMaxEdit()
{
 if(editMin != 0)
 {
  delete editMin;
  editMin = 0;
 }
 if(editMax != 0)
 {
  delete editMax;
  editMax = 0;
 }
 if(buttonMinMaxOk != 0)
 {
  delete buttonMinMaxOk;
  buttonMinMaxOk = 0;
 }
};


//==============================================================================
//      clearAllSeries
//==============================================================================
void myChart::clearAllSeries()
{
 for(list_it i = mainList.begin(), j = mainList.end(); i != j; ++i)
    (*i)->GetSeries()->Clear();
 build = NO_BUILD;
};


//==============================================================================
//      addLabel
//==============================================================================
void myChart::addLabel()
{
 labelList.push_back(&myLabel(chart));
 labelList.back()->PopupMenu->Items->Items[0]->OnClick = deleteLabel;
};


//==============================================================================
//     deleteLabel
//==============================================================================
void __fastcall myChart::deleteLabel(TObject* Sender)
{
 myLabel* p = myLabel::getCurrentLabel();
 labelList.remove(myLabel::getCurrentLabel());
 delete p;
 p = 0;
};

//==============================================================================
//     deleteAllLabels
//==============================================================================
void myChart::deleteAllLabels()
{
 while( !labelList.empty())
 {
    myLabel* p = labelList.back();
    labelList.pop_back();
    delete p;
    p = NULL;
 }
}


//==============================================================================
//     setChartSettings
//==============================================================================
void myChart::setChartSettings(TChart* destChart, TChart* sourceChart)
{
 // Fields
 destChart->MarginLeft = sourceChart->MarginLeft;
 destChart->MarginTop = sourceChart->MarginTop;
 destChart->MarginRight = sourceChart->MarginRight;
 destChart->MarginBottom = sourceChart->MarginBottom;

 // Min, max, increment
 destChart->BottomAxis->SetMinMax(sourceChart->BottomAxis->Minimum, sourceChart->BottomAxis->Maximum);
 destChart->BottomAxis->Increment = sourceChart->BottomAxis->Increment;
 destChart->LeftAxis->SetMinMax(sourceChart->LeftAxis->Minimum, sourceChart->LeftAxis->Maximum);
 destChart->LeftAxis->Increment = sourceChart->LeftAxis->Increment;

 // countLines
 countHorizLine = LEFTAXISLENGHT / (sourceChart->LeftAxis->Increment) - 0.5;
 destChart->LeftAxis->Increment = sourceChart->LeftAxis->Increment;

 countVertLine =  (sourceChart->BottomAxis->Maximum - sourceChart->BottomAxis->Minimum) /
                  (sourceChart->BottomAxis->Increment) - 0.5;
 destChart->BottomAxis->Increment = sourceChart->BottomAxis->Increment;

 // Color
 destChart->Color = sourceChart->Color;
}


//==============================================================================
//     setCountHorizLine
//==============================================================================
void myChart::setCountHorizLine(int count)
{
 countHorizLine = count;
 chart->LeftAxis->Increment = LEFTAXISLENGHT / (countHorizLine + 1);
}

//==============================================================================
//     setCountVertLine
//==============================================================================
void myChart::setCountVertLine(int count)
{
 countVertLine = count;
 chart->BottomAxis->Increment = (chart->BottomAxis->Maximum - chart->BottomAxis->Minimum) /
                                                            (countVertLine + 1);
}


//==============================================================================
//      findParByNumber
//==============================================================================
Parametr* myChart::findParByNumber(int n)
{
 list_it i = mainList.begin();
 std::advance(i, n);
 return reinterpret_cast<Parametr*>(*i);
}

//==============================================================================
//      findParByAxis
//==============================================================================
Parametr* myChart::findParByAxis(TChartAxis* axis)
{
 for(list_it b = mainList.begin(), e = mainList.end(); b != e; ++b)
    if( (*b)->Axis == axis )
       return reinterpret_cast<Parametr*>(*b);
 return 0;
}


//==============================================================================
//      cutInterval
//==============================================================================
void myChart::cutInterval()
{
 if( !cutIntervalButton)
 {
    ShowMessage("Сначала выделите интервал");
    return;
 }
 if(CutX0 >= CutX1)
    std::swap(CutX0, CutX1);
 chart->BottomAxis->SetMinMax(CutX0, CutX1);
 chart->BottomAxis->Increment = (CutX1 - CutX0) / (countVertLine + 1);
 cutIntervalButton = false;
 timeBar->ChartToTimeBar();
}








