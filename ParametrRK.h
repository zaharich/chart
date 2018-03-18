//---------------------------------------------------------------------------

#ifndef ParametrRKH
#define ParametrRKH
#include "Parametr.h"
//---------------------------------------------------------------------------
class ParameterRK : public Parametr
{
 private:
    virtual void SetMinMaxAxis();

 public:
    TAreaSeries* Series;
    int NStructRK;
    int NRK;
    String NameRK;

    // constructors
    ParameterRK() : Parametr() {NStructRK = 0; NRK = 0; NameRK = "";};
    ParameterRK(const int NumPasp, TChart* chart, const int nRK);
    ParameterRK(TChart* chart, const int itemSeries);
    ParameterRK(const ParameterRK &P);

    // destructor
    ~ParameterRK(){delete Series;};

    // operations
    const ParameterRK& operator = (const ParameterRK &P);

    // methods
    void SeriesAdd(const double x, const double y){Series->AddXY(x, y);};
    int GetSeriesWidth(){return Series->Pen->Width;};
    TCustomLineSeries* GetSeries(){return Series;};

    void LoadSeriesTitle();
    void SaveSeriesTitle();
    void ShowInfo();
};

#endif
