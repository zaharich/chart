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
    : TChart(container)
    , currentPar(NULL)
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
{
  //chart = new TChart(container);
  Parent = container;
  Align = alClient;
  View3D = false;

  Series1 = new TFastLineSeries(this);           // без Series1 не будет
  Series1->ParentChart = this;                  // горизонтальных линий
  AddSeries(Series1);                     // сетки
  Series1->XValues->DateTime = true;

  Title->Clear();
  SubTitle->Text->Add(0);
  SubTitle->Text->Add(0);

  _contexMenu = contexMenu;
  _axisMenu = axisMenu;
  PopupMenu = _contexMenu;

  OnClickAxis = chartClickAxis;
  OnMouseDown = chartMouseDown;
  OnMouseMove = chartMouseMove;
  OnMouseUp = chartMouseUp;
  OnAfterDraw = chartAfterDraw;
};


//==============================================================================
//         ~myChart
//==============================================================================
__fastcall myChart::~myChart()
{
  delete Series1;
  //delete chart;
};


//==============================================================================
//               chartInit
//==============================================================================
void myChart::chartInit()
{
  BottomAxis->DateTimeFormat = "HH:mm:ss";
  BottomAxis->Axis->Width = 1;
  BottomAxis->Automatic = false;
  BottomAxis->SetMinMax(0., 1.);
  BottomAxis->Increment = 1. / (countVertLine + 1);
  BottomAxis->MinorTickCount = 0;
  BottomAxis->RoundFirstLabel = false;
  BottomAxis->LabelsSize = 1;
  BottomAxis->LabelsSeparation = 0;      // чтобы показывались все линии
  BottomAxis->PositionUnits = muPercent;

  LeftAxis->Axis->Width = 1;
  LeftAxis->Automatic = false;
  LeftAxis->SetMinMax(0, LEFTAXISLENGHT);
  LeftAxis->Increment = 5;
  LeftAxis->LabelsSeparation = 0;        // чтобы показывались все линии
  Color = clAqua;
  LeftAxis->LabelsFont->Color = Color;

  MarginTop = 2;
  MarginBottom = 3;
  MarginRight = 3;
  MarginLeft = 10;

  Zoom->Allow = false;
  Legend->Visible = false;
  Title->Visible = false;
  SubTitle->Visible = false;

  stretch = 0;
  button = MOVE;
};


//==============================================================================
//           loadEdit
//==============================================================================
void myChart::loadEdit()
{
 //String str, bufStr;         // todo          values for this function or two different functions
 //int pos = 0;
 for(int i = 0; i < Title->Text->Count; ++i){
     String str = Title->Text->Strings[i];
     int pos = str.Pos("$") - 1;
     String buffStr = str.SubString(0, pos);
     bool visible = buffStr.ToInt();
     str = str.SubString(pos + 2, 255);      // +2 чтобы не захватывать разделитель $

     pos = str.Pos("$") - 1;
     buffStr = str.SubString(0, pos);
     String caption = buffStr;         // Caption
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
 String str = SubTitle->Text->Strings[0];

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
 BottomAxis->SetMinMax(min, max);

 // Grid
 countHorizLine = LEFTAXISLENGHT / LeftAxis->Increment - 0.5;
 countVertLine = (BottomAxis->Maximum - BottomAxis->Minimum) /
                    BottomAxis->Increment - 0.5;
 int test = 45;
};


//==============================================================================
//            ChartToFile
//==============================================================================
void myChart::ChartToFile(const String& pathToTeeFile, bool includeData, bool textFormat)
{
 // save position and caption of text(labels) on chart. Format("Visible$Caption$Left$Top")
 Title->Clear();
 for(std::list<myLabel*>::iterator i = labelList.begin(); i != labelList.end(); ++i){
    Title->Text->Add( String( IntToStr((*i)->Visible) + "$" +
    (*i)->Caption + "$" + (*i)->Left + "$" + (*i)->Top) );
 }

 // save min-max of bottom axis and build type(no, slow, quick). Format("min$max$build")
 SubTitle->Text->Strings[0] = FloatToStr(BottomAxis->Minimum)
         + "$" + FloatToStr(BottomAxis->Maximum) + "$" + IntToStr(build);

 // save parametr settings. Format("Title Nsis MarkerSymbol NStructRK afterComma Visible")
 for(list_it i = mainList.begin(); i != mainList.end(); ++i)
     (*i)->SaveSeriesTitle();
 SaveChartToFile(this, pathToTeeFile, includeData, textFormat);    // встроенная
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

 LoadChartFromFile(dynamic_cast<TCustomChart*>(this), teeName);   // встроенная
 loadEdit();

 // create
 for(int i = 0; i < (SeriesList->Count - 1); ++i)
 {
     Parametr* p;
     if(SeriesList->Items[i+1]->Tag)
        p = new ParameterRK(this, i);
     else
        p = new ParameterFiz(this, i);
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
 BottomAxis->SetMinMax(minTime * SEC, maxTime * SEC);
 BottomAxis->Increment = ((maxTime - minTime) * SEC) / (countVertLine + 1);
};


//==============================================================================
//           addParametr
//==============================================================================
void myChart::addParametr(int numPasp, int numRK)
{
 if(numRK > 0)
 {
    ParameterRK *pr = new ParameterRK(numPasp, this, numRK);
    mainList.push_back(pr);
 }
 else if(numRK == 0)
 {
    ParameterFiz *pf = new ParameterFiz(numPasp, this);
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
 String str = "";
 for(list_it i = mainList.begin(); i != mainList.end(); ++i)
    str += (*i)->GetSeries()->Title + "; ";
 ShowMessage(str);
};

void myChart::printParametrsTo(TStringGrid* dest)
{
 dest->RowCount = 0;
 int i = 0;
 for(list_it b = mainList.begin(), e = mainList.end(); b != e; ++b){
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
 currentPar->ShowInfo();

 // control by button;
 if(button != NONE){
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

 PopupMenu = _axisMenu;

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
 if(currentPar){
    currentPar->SlimAxis();
    currentPar = NULL;
 }
 X0 = X;  Y0 = Y;

 if(Button == mbLeft && ChartRect.Left < X   &&    // выделение мышью
                        X < ChartRect.Right  &&    // временного отрезка
                        ! referButton               &&
                        ChartRect.Top < Y    &&    // обрамление черным
                        Y < ChartRect.Bottom &&    // цветом
                        SeriesCount() > 1      )   //
 {
    double no;
    SeriesList->Items[0]->GetCursorValues(CutX0, no);  // все равно к какой серии применять GetCursorValues
    //Canvas->Pen->Mode = pmNotXor;                      // потому что все привязаны к нижней оси, а второй параметр не нужен
    //Canvas->Brush->Style = bsClear;
    //Canvas->Brush->Color = clBlack;

    //Canvas->TextOutA(X, LeftAxis->IEndPos + 6, ((TDateTime)CutX0).TimeString());
 }
 else{
     Canvas->Pen->Mode = pmCopy;
     Canvas->Brush->Color = clWhite;
 }

 if(Button == mbRight)
    PopupMenu = zoomButton ? NULL : _contexMenu;

 cutIntervalButton = false;
 Refresh();
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
  //currentPar->ShowInfo();
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
    currentPar->Axis->StartPosition = currentPar->Axis->StartPosition - LeftAxis->Increment;
 }
 if((Y0 - y1) < -PixelInCell){
    if((currentPar->Axis->Maximum - currentPar->Axis->Increment) <= currentPar->Axis->Minimum) return;
    Y0 = y1;
    v = floor((AxisMax - AxisMin) / currentPar->Axis->Increment - 1 + 0.5);
    currentPar->Axis->Increment = (currentPar->Axis->Maximum - currentPar->Axis->Minimum) / v;
    currentPar->Axis->StartPosition = currentPar->Axis->StartPosition + LeftAxis->Increment;
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
       currentPar->Axis->StartPosition = currentPar->Axis->StartPosition - LeftAxis->Increment;
    }
    if((Y0 - y) < -PixelInCell){
       if((currentPar->Axis->Maximum - currentPar->Axis->Increment) <= currentPar->Axis->Minimum)
          return;
       Y0 = y;
       currentPar->Axis->Maximum = currentPar->Axis->Maximum - AxisIncrement;
       currentPar->Axis->StartPosition = currentPar->Axis->StartPosition + LeftAxis->Increment;
    }
 }
 else{
    if((Y0 - y) > PixelInCell){
       if((currentPar->Axis->Minimum + currentPar->Axis->Increment) >= currentPar->Axis->Maximum)
          return;
       Y0 = y;
       currentPar->Axis->Minimum = currentPar->Axis->Minimum + AxisIncrement;
       currentPar->Axis->EndPosition = currentPar->Axis->EndPosition - LeftAxis->Increment;
    }
    if((Y0 - y) < -PixelInCell){
       Y0 = y;
       currentPar->Axis->Minimum = currentPar->Axis->Minimum - AxisIncrement;
       currentPar->Axis->EndPosition = currentPar->Axis->EndPosition + LeftAxis->Increment;
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
    Repaint();
    Canvas->Brush->Style = bsClear;
    Canvas->Rectangle(X - (Width >> 2) / (kzoom + 1), Y - (Height >> 2) / (kzoom + 1),
                             X + (Width >> 2) / (kzoom + 1), Y + (Height >> 2) / (kzoom + 1));
    return;
 }

 // при наведении на шкалу, она подсвечивается
 for(list_it i = mainList.begin(); i != mainList.end(); ++i){
    if( (*i)->Axis->Clicked(X, Y) )
       (*i)->FullAxis();
    else
       (*i)->SlimAxis();
 }

 // курсор в поле графиков
 if(ChartRect.Left < X && X < ChartRect.Right  &&
    ChartRect.Top < Y  && Y < ChartRect.Bottom &&
                                      SeriesCount() > 1)
 {
    if(mouseDown && X0 != X){
       if(! referButton){      // выделение интервала
          Refresh();
          Canvas->Pen->Mode = pmNotXor;
          Canvas->Brush->Color = clBlack;
          Canvas->Rectangle(X0, LeftAxis->IStartPos, X, LeftAxis->IEndPos);

          double y;
          SeriesList->Items[1]->GetCursorValues(CutX1, y);
          Canvas->Brush->Color = clWhite;
          Canvas->TextOutA(X, LeftAxis->IEndPos + 6, ((TDateTime)CutX1).TimeString());
          Canvas->TextOutA(X0, LeftAxis->IEndPos + 6, ((TDateTime)CutX0).TimeString());

          cutIntervalButton = true;
          return;
       }
       else{                     // визирная линия
          double x, y;
          SeriesList->Items[0]->GetCursorValues(x, y);
          Refresh();
          Canvas->Pen->Color = clBlack;   // for black refer line
          Canvas->MoveTo(X, LeftAxis->IStartPos);
          Canvas->LineTo(X, LeftAxis->IEndPos);

          Canvas->Pen->Color = clWhite;
          Canvas->TextOutA(X, LeftAxis->IEndPos + 6, ((TDateTime)x).TimeString());

          for(list_it i = mainList.begin(), e = mainList.end(); i != e; ++i){
              if((*i)->GetSeries()->Count())
              {
                   int ct = (*i)->GetSeries()->Count();
                   float pr = (x - (*i)->GetSeries()->MinXValue()) / (float((*i)->GetSeries()->MaxXValue()) - (float)(*i)->GetSeries()->MinXValue());
                   float y7 = (*i)->GetSeries()->YValue[pr * ct];
                   Canvas->TextOutA(X, (*i)->GetSeries()->CalcYPos(pr * ct), FormatFloat((*i)->afterComma, y7));
              }
          }
          return;
       }
    }
    else{        //    вывод численных значений
       if(SeriesCount() > 1 && !referButton && !cutIntervalButton && !building){
           // чтобы не работало в пустых зонах
           int k = SeriesList->Items[1]->Count();
           if( k < 1 ) return;
           int x0 = SeriesList->Items[1]->CalcXPos(1);
           int x1 = SeriesList->Items[1]->CalcXPos(k-1);
           if(X < x0 || X > x1 )
               return;
               
           double x, y;
           SeriesList->Items[1]->GetCursorValues(x, y);
           Refresh();
           Canvas->Pen->Color = clGray;
           Canvas->MoveTo(X, LeftAxis->IStartPos);
           Canvas->LineTo(X, LeftAxis->IEndPos);

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
 if(SelectAxis){
    double dy = (LEFTAXISLENGHT / LeftAxis->IAxisSize) * (Y - Y0),
           dx = (LEFTAXISLENGHT / BottomAxis->IAxisSize) * (X - X0);
    int PixelInCell = LeftAxis->IAxisSize / (LEFTAXISLENGHT / LeftAxis->Increment);

    if(button == STRETCH)   // растяжка оси одинакова в двух режимах
       AxisStretch(PixelInCell, Y);
    else{
       // УПРАВЛЕНИЕ КНОПКАМИ
       if(button != NONE){
          if(button == MOVE){
              AxisMove(dy, dx);
              X0 = X; Y0 =Y;
          }
          if(button == ADDINC)
              MoveMaxMinAxis(PixelInCell, Y, UpHalfAxis);
       }
       // УПРАВЛЕНИЕ ТОЛЬКО МЫШЬЮ
       else{
          if(stretch != 3){
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
 if(SelectAxis){
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

 // ZOOM - ZOOM
 if(zoomButton){
    if(Button == mbLeft && kzoom < 3){
       ++kzoom;
       Align = alNone;
       Width *= 2;
       Height *= 2;
       ((TScrollBox*)Parent)->HorzScrollBar->Position = 2*X - Width / (4*kzoom);
       ((TScrollBox*)Parent)->VertScrollBar->Position = 2*Y - Height / (4*kzoom);
       Canvas->Font->Size << 1;
    }
    if(Button == mbRight && kzoom > 0){
       --kzoom;
       Width /= 2;
       Height /= 2;
       Canvas->Font->Size >> 1;
    }

    Refresh();
    //TabControl1->PopupMenu = NULL;
    ((TTabControl*)((Parent)->Parent))->PopupMenu = NULL;
    return;
 }
};


//==============================================================================
//          LinkToGrid
//==============================================================================
void myChart::LinkToGrid(TChartAxis *Axis){
   double delta = LeftAxis->Increment;
   //double heightGridCell = LeftAxis->IAxisSize / countMainHorizLine;
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
    a->EndPosition = 100 - ( hightAboveFloor * LeftAxis->Increment );
    a->StartPosition = a->EndPosition - ( LeftAxis->Increment * (*b)->axisSizeInCell );

    // shift axis X position
    if( a->EndPosition < 5 ){
       if( shift ){
          a->EndPosition = shiftEndPosition;
          a->StartPosition = a->EndPosition - ( LeftAxis->Increment * (*b)->axisSizeInCell );
          shiftEndPosition = a->StartPosition - LeftAxis->Increment;
          if(a->StartPosition < -10)
             shift = false;
       }
       if( !shift ){
          axisDeltaHorizontal += -4;
          shift = true;
          a->EndPosition = shiftEndPosition;
          a->StartPosition = a->EndPosition - ( LeftAxis->Increment * (*b)->axisSizeInCell );
          shiftEndPosition = a->StartPosition - LeftAxis->Increment;
       }
    }
    else{
       shift = false;
       shiftEndPosition = 100;
    }
    a->PositionPercent += axisDeltaHorizontal;

    // shift chart margin
    if( a->PositionPercent < -(MarginLeft + 2)){
       MarginLeft += 3;
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
                Chart1->Canvas->TextOut(Par[i]->Series->CalcXPos(j*a+1), Par[i]->Series->CalcYPos(j*a+1)-15, Par[i]->MarkerSymbol);
          }
       }
    }
 }   */

 // Печать
 if(printing){
    for(int i = 0; i < 3; ++i){
      Canvas->Font->Name = "Times New Roman";
      Canvas->Font->PixelsPerInch = 96;                                 //(Edit2->Text).ToInt();
      Canvas->Font->Height = -2;                                        // (Edit7->Text).ToInt();
      //Canvas->TextOut(label[i]->Left, label[i]->Top, label[i]->Caption);
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
 labelInfo = new TLabel(this);
 labelInfo->Parent = this;
 labelInfo->Caption = "Для остановки построения нажмите клавишу \"Q\"";
 //labelInfo->Width = 200;
 labelInfo->Height = 30;
 labelInfo->Top = Height >> 1;
 labelInfo->Left = Width >> 2;
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
  //---- editMax
  if(editMax != 0){
    delete editMax;
    editMax = 0;
  }
  editMax = new TEdit(this);
  editMax->Parent = this;

  editMax->BorderStyle = bsNone;
  editMax->Width = 40;
  editMax->Height = 17;
  axis->PositionUnits = muPixels;
  editMax->Left = axis->PosAxis - editMax->Width - 7;
  axis->PositionUnits = muPercent;
  editMax->Top = axis->IStartPos - editMax->Height/2;
  editMax->Text = axis->Maximum;

  //---- editMin
  if(editMin != 0){
    delete editMin;
    editMin = 0;
  }
  editMin = new TEdit(this);
  editMin->Parent = this;

  editMin->BorderStyle = bsNone;
  editMin->Width = 40;
  editMin->Height = 17;
  axis->PositionUnits = muPixels;
  editMin->Left = axis->PosAxis - editMin->Width - 7;
  axis->PositionUnits = muPercent;
  editMin->Top = currentPar->Axis->IEndPos - editMin->Height/2;
  editMin->Text = currentPar->Axis->Minimum;

  //---- buttonMinMaxOk
  if(buttonMinMaxOk != 0){
    delete buttonMinMaxOk;
    buttonMinMaxOk = 0;
  }
  buttonMinMaxOk = new TButton(this);
  buttonMinMaxOk->Parent = this;

  buttonMinMaxOk->Caption = "OK";
  buttonMinMaxOk->Width = 25;
  buttonMinMaxOk->Height = 17;
  buttonMinMaxOk->Left = editMin->Left + editMin->Width;
  buttonMinMaxOk->Top = editMin->Top;
  buttonMinMaxOk->OnClick = buttonMinMaxOkClick;
};

void myChart::deleteMinMaxEdit()
{
 if(editMin != 0){
  delete editMin;
  editMin = 0;
 }
 if(editMax != 0){
  delete editMax;
  editMax = 0;
 }
 if(buttonMinMaxOk != 0){
  delete buttonMinMaxOk;
  buttonMinMaxOk = 0;
 }
};


//==============================================================================
//      ClearAllSeriesData
//==============================================================================
void myChart::ClearAllSeriesData()
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
  labelList.push_back(&myLabel(this));
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
 while( !labelList.empty()){
    myLabel* p = labelList.back();
    labelList.pop_back();
    delete p;
    p = 0;
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
 LeftAxis->Increment = LEFTAXISLENGHT / (countHorizLine + 1);
}

//==============================================================================
//     setCountVertLine
//==============================================================================
void myChart::setCountVertLine(int count)
{
 countVertLine = count;
 BottomAxis->Increment = (BottomAxis->Maximum - BottomAxis->Minimum) /
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
 if( !cutIntervalButton){
    ShowMessage("Сначала выделите интервал");
    return;
 }
 if(CutX0 >= CutX1)
    std::swap(CutX0, CutX1);
 BottomAxis->SetMinMax(CutX0, CutX1);
 BottomAxis->Increment = (CutX1 - CutX0) / (countVertLine + 1);
 cutIntervalButton = false;
 timeBar->ChartToTimeBar();
}










