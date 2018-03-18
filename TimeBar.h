/*
/*  Class TimeBar - пользовательский класс, состоящий из TPanel и TSplitter,
/*  представляет из себя полосу имитирующую ScrollBar относительно полного
/*  времени полета. Привязывается к классу myChart, используются данные из
/*  класса FlyingFile.
/*  Захарчук А.В.
/*                                                                           */
//---------------------------------------------------------------------------
#ifndef TimeBarH
#define TimeBarH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <ExtCtrls.hpp>
#include <SysUtils.hpp>

#include "myChart.h"
#include "FlyingFile.h"

class myChart;


class TimeBar : public TComponent
{
 public:
     __fastcall TimeBar(TComponent* AOwner, myChart* ch);
     __fastcall ~TimeBar();

     void getMinMaxChart();

     void setMin();
     void setMax();

     void ChartToTimeBar();

     void setCaptionCenterPanel(String&);

 private:
    static const double SEC;
    myChart* chart;

    TPanel* mainPanel;
    TPanel* leftPanel;
    TPanel* startSplitterPanel;
    TPanel* centerPanel;
    TPanel* endSplitterPanel;
    TPanel* rightPanel;

    // these feild need read
    float _minimumChart;
    float _maximumChart;

    // this feild calculate
    int _startPosition;
    int _endPosition;

    bool MouseDown;
    int X0;

    void startMove(int delta);
    void endMove(int delta);
    void centerMove(int delta);

    void setPanelsPosition();


__published:
    void __fastcall bMouseDown(TObject *Sender, TMouseButton Button,
                               TShiftState Shift, int X, int Y);
    void __fastcall bMouseMove(TObject *Sender, TShiftState Shift,
                               int X, int Y);
    void __fastcall bMouseUp(TObject *Sender, TMouseButton Button,
                               TShiftState Shift, int X, int Y);
    void __fastcall aMouseMove(TObject *Sender, TShiftState Shift,
                               int X, int Y);
    void __fastcall cMouseMove(TObject *Sender, TShiftState Shift,
                               int X, int Y);
};
//---------------------------------------------------------------------------
#endif
