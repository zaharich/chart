//---------------------------------------------------------------------------
/*     Class "Parametr"                                                     */
/*     Zakharchuk Andrew                                                    */
//---------------------------------------------------------------------------
#ifndef Parametr_H
#define Parametr_H
//---------------------------------------------------------------------------
#include <Series.hpp>
#include <list>
#include "FlyingFile.h"


class Parametr
{
 protected:
        virtual void SetMinMaxAxis() = 0;   // установка мин, макс, инкремента оси
        int CountOfSystem();                // подсчет кол-ва систем у параметра
        int ChoiseSistem();                 // подбор номера системы
        int FindPosition();                 // TODO - подбор места на диаграмме

        struct PaspChart* tekPaspChart;     // указатель на текущий паспорт ( в структуре паспортов )
        TColor CurrentColor;                // запоминаем цвет (даже если параметр неактивен)

 public:
        TChartAxis *Axis;
        //TCustomLineSeries* Series;

        int NPasp;                          // номер паспорта
        int NSis;                           // номер системы
        int KolSis;                         // количество систем
        int axisSizeInCell;                 // размер оси в делениях сетки
        String afterComma;                  // кол-вo знаков после запятой
        String markerSymbol;                // символ маркера
        String seriesTitle;                 // идентификатор параметра и наименование серии

        // constructor and destructor
        virtual ~Parametr();
        Parametr(const int NumPasp, TChart* chart);
        Parametr(TChart* chart, int itemSeries);
        Parametr();

        // copy-constructor and assignment operation
        Parametr(const Parametr &P);
        const Parametr& operator = (const Parametr &P);

        void SetNSisInTitle(int ns);
        void DrawTitle(bool printing, int kzoom);

        void fullAxis();
        void slimAxis();

        // virtual methods
        virtual void LoadSeriesTitle() = 0;
        virtual void SaveSeriesTitle() = 0;
        virtual void showInfo() = 0;
        virtual void SeriesAdd(const double, const double) = 0;
        virtual bool GetTagSeries() = 0;
        virtual String GetSeriesTitle() = 0;
        virtual int GetSeriesWidth() = 0;
        virtual TCustomLineSeries* GetSeries() = 0;
        virtual void typeInfo(){ShowMessage("Parametr");};

        //static Parametr* findParBySeriesTitle(std::list<Parametr*> list, String& title);
        static Parametr* findParByAxisTitle(std::list<Parametr*> list, String& title);

        void visible(){Axis->Visible = true;};
        void invisible(){Axis->Visible = false;};

        //void LinkAxisToGrid(TChart* chart, TChartAxis* axis);
        //int GetNStructRK(int NumberRK, int max);
};

#endif Parametr_H
