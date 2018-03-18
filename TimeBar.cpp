
#pragma hdrstop

#include "TimeBar.h"
#pragma package(smart_init)


const double TimeBar::SEC = 1/86400.;  //  1/86400 часть суток равная 1 сек

__fastcall TimeBar::TimeBar(TComponent* AOwner, myChart* ch)
                  : TComponent(AOwner)
{
 chart = ch;
 mainPanel = new TPanel(AOwner);
 mainPanel->Parent = (TPanel*)AOwner;
 mainPanel->Align = alClient;

 leftPanel = new TPanel(mainPanel);
 startSplitterPanel = new TPanel(mainPanel);
 rightPanel = new TPanel(mainPanel);
 endSplitterPanel = new TPanel(mainPanel);
 centerPanel = new TPanel(mainPanel);

 setPanelsPosition();

 _startPosition = centerPanel->Left;
 _endPosition = endSplitterPanel->Left - centerPanel->BorderWidth;

 getMinMaxChart();
 chart->setTimeBar(this);
}

__fastcall TimeBar::~TimeBar()
{
}


void TimeBar::setPanelsPosition()
{
 // leftPanel
 leftPanel->Parent = mainPanel;
 leftPanel->Width = 30;
 leftPanel->Constraints->MinWidth = 30;
 leftPanel->Color = clGray;
 leftPanel->Top = 0;
 leftPanel->Left = 0;

 // startSplitterPanel
 startSplitterPanel->Parent = mainPanel;
 startSplitterPanel->Color = clGreen;
 startSplitterPanel->Constraints->MinWidth = 5;
 startSplitterPanel->Constraints->MaxWidth = 5;
 startSplitterPanel->Cursor = crHSplit;
 startSplitterPanel->Top = 0;
 startSplitterPanel->Left = leftPanel->Width + leftPanel->BorderWidth;
 startSplitterPanel->OnMouseDown = bMouseDown;
 startSplitterPanel->OnMouseMove = bMouseMove;
 startSplitterPanel->OnMouseUp   = bMouseUp;

 // rightPanel
 rightPanel->Parent = mainPanel;
 rightPanel->Width = 30;
 rightPanel->Constraints->MinWidth = 30;
 rightPanel->Color = clGray;
 rightPanel->Top = 0;
 rightPanel->Left = mainPanel->Width - 2 * mainPanel->BorderWidth -
                                                 rightPanel->Width;
 // endSplitterPanel
 endSplitterPanel->Parent = mainPanel;
 endSplitterPanel->Color = clGreen;
 endSplitterPanel->Constraints->MinWidth = 5;
 endSplitterPanel->Constraints->MaxWidth = 5;
 endSplitterPanel->Cursor = crHSplit;
 endSplitterPanel->Top = 0;
 endSplitterPanel->Left = rightPanel->Left - startSplitterPanel->BorderWidth -
                                                      startSplitterPanel->Width;
 endSplitterPanel->OnMouseDown = bMouseDown;
 endSplitterPanel->OnMouseMove = aMouseMove;
 endSplitterPanel->OnMouseUp   = bMouseUp;

 // centerPanel
 centerPanel->Parent = mainPanel;
 centerPanel->Constraints->MinWidth = 20;
 centerPanel->Color = clSkyBlue;
 centerPanel->Top = 0;
 centerPanel->Left = startSplitterPanel->Left + startSplitterPanel->Width +
                                            2 * startSplitterPanel->BorderWidth;
 centerPanel->Width = endSplitterPanel->Left - centerPanel->Left;
 centerPanel->OnMouseDown = bMouseDown;
 centerPanel->OnMouseMove = cMouseMove;
 centerPanel->OnMouseUp   = bMouseUp;
}


void __fastcall TimeBar::bMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 MouseDown = true;
 X0 = X;
}

//----
void __fastcall TimeBar::bMouseMove(TObject *Sender, TShiftState Shift,
                               int X, int Y)
{
 if(MouseDown)
     startMove(X - X0);
}

//----
void __fastcall TimeBar::bMouseUp(TObject *Sender, TMouseButton Button,
                               TShiftState Shift, int X, int Y)
{
 MouseDown = false;
}

//----
void __fastcall TimeBar::aMouseMove(TObject *Sender, TShiftState Shift,
                               int X, int Y)
{
 if(MouseDown)
     endMove(X - X0);
}

//----
void __fastcall TimeBar::cMouseMove(TObject *Sender, TShiftState Shift,
                               int X, int Y)
{
 if(MouseDown)
     centerMove(X - X0);
}


void TimeBar::startMove(int delta)
{
 if( (centerPanel->Width - delta) < centerPanel->Constraints->MinWidth ||
     (leftPanel->Width + delta) < leftPanel->Constraints->MinWidth        )
     return;
 // move and resize centerPanel
 centerPanel->Left += delta;
 centerPanel->Width -= delta;

 // move startSplitterPanel
 startSplitterPanel->Left += delta;

 // resize leftPanel
 leftPanel->Width += delta;

 // chart minimum
 float partInProcent = ((float)centerPanel->Left - _startPosition) / (_endPosition - _startPosition);
 float ChangeMin = (FlyingFile::Instance().getSourceMaxTime() - FlyingFile::Instance().getSourceMinTime()) * partInProcent * SEC;
 _minimumChart = FlyingFile::Instance().getSourceMinTime() * SEC + ChangeMin;

 setMin();
}


void TimeBar::endMove(int delta)
{
 while(centerPanel->Width + delta < centerPanel->Constraints->MinWidth)
     ++delta;
 while(rightPanel->Width - delta  < rightPanel->Constraints->MinWidth)
     --delta;
 // resize centerPanel
 centerPanel->Width += delta;

 // move endSplitterPanel
 endSplitterPanel->Left += delta;

 // move and resize rightPanel
 rightPanel->Width -= delta;
 rightPanel->Left += delta;

 // chart maximum
 if(_minimumChart >= _maximumChart)
     return;
 float partInProcent = (_endPosition - ((float)centerPanel->Left + (float)centerPanel->Width)) /
                                                                        (_endPosition - _startPosition);
 float ChangeMin = (FlyingFile::Instance().getSourceMaxTime() - FlyingFile::Instance().getSourceMinTime()) * partInProcent * SEC;
 _maximumChart = FlyingFile::Instance().getSourceMaxTime() * SEC - ChangeMin;

 setMax();
}


void TimeBar::centerMove(int delta)
{
 if( (rightPanel->Width - delta)  < rightPanel->Constraints->MinWidth  ||
     (leftPanel->Width + delta)   < leftPanel->Constraints->MinWidth        )
     return;
 startMove(delta);
 endMove(delta);
}

// public functions

void TimeBar::getMinMaxChart()
{
  _minimumChart = chart->BottomAxis->Minimum;
  _maximumChart = chart->BottomAxis->Maximum;
}


void TimeBar::setMin()
{
 if(_minimumChart >= _maximumChart)
    return;
 chart->BottomAxis->Minimum = _minimumChart;
 chart->BottomAxis->Increment = (_maximumChart - _minimumChart) / (chart->getCountVertLine() + 1);
}


void TimeBar::setMax()
{
 if(_minimumChart >= _maximumChart)
    return;
 chart->BottomAxis->Maximum = _maximumChart;
 chart->BottomAxis->Increment = (_maximumChart - _minimumChart) / (chart->getCountVertLine() + 1);
}


void TimeBar::ChartToTimeBar()
{
 getMinMaxChart();

 // new _startPosition, _endPosition
 setPanelsPosition();
 _startPosition = centerPanel->Left;
 _endPosition = endSplitterPanel->Left - centerPanel->BorderWidth;

 // minimum
 float a = (chart->BottomAxis->Minimum - FlyingFile::Instance().getSourceMinTime() * SEC);
 float b = (FlyingFile::Instance().getSourceMaxTime() - FlyingFile::Instance().getSourceMinTime()) * SEC;
 float partInProcent =  a / b ;
 float change = (_endPosition - _startPosition) * partInProcent;
 startMove(change);

 // maximum
 a = (FlyingFile::Instance().getSourceMaxTime()*SEC - chart->BottomAxis->Maximum);
 partInProcent = a / b;
 change = (_endPosition - _startPosition) * partInProcent;
 endMove(-change);
}


void TimeBar::setCaptionCenterPanel(String& str)
{
 centerPanel->Caption = str;
 centerPanel->Height = mainPanel->Height;
}









