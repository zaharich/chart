
#include "ShablonStruct.h"                  // Хромцов 2014_01_13
#ifndef ChartH                              // Хромцов 2013_07_15
#define ChartH                              // Хромцов 2013_07_15

//static unsigned int IndexOutChart,NumberFull32;
// char BufGif[sizeof(struct Gif) * 3600 * 24];
// if(IndexOutChart > 0x7fffffff) { NumberFull32++;  IndexOutChart = IndexOutChart  - 0x7fffffff;}
 struct GlobalFlagChart                 // Хромцов 2013_07_15
 {
 bool RashetLibrary;   // = false библиотека расчетных параметров отключена
                       // = true                 -"-              подключена
 char NameDllRashetLibrary[1024];               // Путь к библиотеке расчетных параметров
 int KParamRashDllOut;                          // Кол-во параметров расчетных (не библиотечных)
 struct DllParRashet *PtrStructDllOut;
 char RashetParPathCompiler[1024];                           // Путь к компилятору для расчетных параметров
 char RashetUserLib[1024];                      // Путь к Программам для создания библиотек расчетных параметров
 char NameFileRashetTxt[1024];                  // Путь к текстовому файлу расчетных параметров  .txt
 char rezerv[1015];
 };

 struct DllParRashet
 {
    char name[16];                    // Идентификатор расчетного параметра
    void *adres;
    char name1[16];                   // Идентификатор опорного параметра
    //int ngr;
    char tip;
    char name2[64];                   // Наименование параметра
    void *adrespaspopornpar;              // 2013_05_06    Адрес паспорта опорного параметра
    void *adrespaspraspar;                // 2013_05_06    Адрес паспорта расчетного параметра
    char rezerv[148];
 };

extern PACKAGE struct PaspChart *PtrPaspChart;  // Хромцов 2013_07_15
extern PACKAGE struct IndexBlocFileDatXX IndexBlocFileDatXX; // Хромцов 2013_07)15
extern PACKAGE struct GlobalFlagChart *PtrGlobalFlagChart;  // Хромцов 2013_07_15
extern PACKAGE struct Chart_Ini Chart_Ini; //  2013_10_11
extern PACKAGE struct RKChart *PtrRKChart; //  2013_10_11
extern PACKAGE struct ParamXX *PtrParamXX; //  2013_10_11
extern PACKAGE struct TimXX TimXX;         //  2013_10_11
extern PACKAGE struct Global Global;
extern PACKAGE struct Razdel *PtrRazdel;   // 2014_01_
#endif       // Хромцов 2013_07_15

