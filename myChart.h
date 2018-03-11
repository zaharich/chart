//---------------------------------------------------------------------------

#ifndef myChartH
#define myChartH

#include <vcl.h>
#include <list>
#include <vector>
#include <typeinfo>
#include "Chart.hpp"
#include "Series.hpp"
#include "Dialogs.hpp"
#include "teestore.hpp"
#include "math.h"
#include "grids.hpp"
#include "Buttons.hpp"
#include <ComCtrls.hpp>

#include "Parametr.h"
#include "ParametrRK.h"
#include "ParametrFiz.h"
#include "TimeBar.h"
#include "myLabel.h"

class Parametr;
class TimeBar;

//---------------------------------------------------------------------------
class myChart
{
  private:
    TChart* chart;
    TFastLineSeries* Series1;

    // Additional elements
    TLabel* labelInfo;
    TEdit* editMin;
    TEdit* editMax;
    TButton* buttonMinMaxOk;

    TimeBar* timeBar;
    Parametr* currentPar;
    TStringGrid* stringGrid;

    enum {NONE, MOVE, MINMAX, ADDINC, STRETCH, DEL, VISIBLE, ZOOMIN}button;
    bool zoomButton;
    bool referButton;
    bool linkAxisButton;
    bool cutIntervalButton;

    // Constants
    static const int MAXCOUNTSERIES;
    static const double LEFTAXISLENGHT;
    static const double SEC;

    bool SelectAxis, mouseDown, UpHalfAxis;  // флаги - ось выбрана, нажали на ось, выбрали верхнюю часть оси
    bool printing, building;                 // флаги - в данный момент идет печать
    int X0, Y0;
    int stretch;
    int kzoom;
    double CutX0, CutX1;
    double AxisMin, AxisMax, AxisIncrement;

    // Context menus
    TPopupMenu* _contexMenu;
    TPopupMenu* _axisMenu;

    // Grid
    int countHorizLine;
    int countVertLine;
    int heightGridCell;
    float procentHeightCell;

    // Axis actions
    void AxisMove(double dy, double dx);
    void AxisStretch(int PixelInCell, int y1);
    void MoveMaxMinAxis(const int PixelInCell, int y, const bool UpHalfAxis);
    void createMinMaxEdit(TChartAxis* axis);


  public:
    myChart(TScrollBox* container, TStringGrid* sg, TPopupMenu* menu, TPopupMenu* axisMenu);
    ~myChart();

    enum {NO_BUILD, SLOW_BUILD, FAST_BUILD}build;
    std::list<Parametr*> mainList;
    Parametr* findParByNumber(int n);
    Parametr* findParByAxis(TChartAxis* axis);
    std::list<myLabel*> labelList;

    // grid lines
    void setCountHorizLine(int count);
    int getCountHorizLine(){return countHorizLine;};
    void setCountVertLine(int count);
    int getCountVertLine(){return countVertLine;};

    // init, save, load, get chart
    void chartInit();
    TChart* getChart(){return chart;};
    void loadEdit();
    void saveEdit();
    bool openChartFromFile(const String& teeName);
    void ChartToFile(const AnsiString& pathToFile, bool includeData, bool textFormat);
    void setChartSettings(TChart* destChart, TChart* sourceChart);

    void setMinMaxIncrementBottomAxis(int minTime, int maxTime);
    void LinkToGrid(TChartAxis* axis);
    void AxisNewPosition();
    void clearAllSeries();

    // add, delete Parametrs
    void addParametr(int numPasp, int numRK = 0);
    void deleteParametr(Parametr* P);
    void deleteParametr(TChartAxis* axis);
    void deleteAllParametrs();

    // print parametrs list to ...
    void printParametrsTo();
    void printParametrsTo(TStringGrid* dest);
    void printParametrsTo(TListBox* dest);

    // current Parametr
    void setCurrentParametr(Parametr* p){currentPar = p;};
    Parametr* getCurrentParametr(){return currentPar;};

    // Additional elements
    void DrawEndIdents();
    void labelInfoOn();
    void labelInfoOff();
    void deleteMinMaxEdit();
    void setTimeBar(TimeBar* tb){timeBar = tb;};
    bool getCutIntervalButton(){return cutIntervalButton;};
    void cutInterval();

    // functions with labels
    void addLabel();
    void __fastcall deleteLabel(TObject* Sender);
    void deleteAllLabels();

    void recognizeButton(TSpeedButton* b, bool checkBoxMouse);

    // axis events
    void __fastcall chartClickAxis(TCustomChart *Sender,
      TChartAxis *Axis, TMouseButton Button, TShiftState Shift, int X,
      int Y);
    void __fastcall chartMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall chartMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y);
    void __fastcall chartMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y);

    void __fastcall chartAfterDraw(TObject *Sender);
    void __fastcall buttonMinMaxOkClick(TObject *Sender);
};
#endif
