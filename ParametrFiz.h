//---------------------------------------------------------------------------

#ifndef ParametrFizH
#define ParametrFizH
#include "Parametr.h"

class ParameterFiz : public Parametr
{
 private:
    virtual void SetMinMaxAxis();      // TODO rename SetMinMaxInc

 public:
    TFastLineSeries* Series;

    // constructors
    ParameterFiz() : Parametr() {Series = 0;};
    ParameterFiz(const int NumPasp, TChart* chart);
    ParameterFiz(TChart* chart, int itemSeries);
    ParameterFiz(const ParameterFiz &P);

    // destructor
    ~ParameterFiz(){delete Series;};

    // operations
    const ParameterFiz& operator = (const ParameterFiz &P);

    // methods
    void SeriesAdd(const double x, const double y){Series->AddXY(x, y);};
    bool GetTagSeries(){return Series->Tag;};                                   // RK = 1, Fiz = 0
    String GetSeriesTitle(){return Series->Title;};
    int GetSeriesWidth(){return Series->Pen->Width;};
    TCustomLineSeries* GetSeries(){return Series;};

    void LoadSeriesTitle();
    void SaveSeriesTitle();
    void showInfo();
};
//---------------------------------------------------------------------------
#endif
