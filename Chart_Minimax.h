// Все нижележащие структуры должны быть удалены из файла  Minimax ShablonStruct.h а данный Файл должен быть подключен в файлу  Minimax ShablonStruct.h
#ifndef Chart_MinimaxH                              // Хромцов 2013_07_15
#define Chart_MinimaxH                              // Хромцов 2013_07_15
#define KSISTEM 3
#define CHART_LSCREEN 2000        // кол-во пикселей на дисплее по горизонтали
// ФОРМАТ ФАЙЛА ДАННЫХ 48ХХ
/*
struct IndexBlocFileDatXX
   {
   char TipData[256];                  // Тип данных
                                                  // "48FM"
                                                  // "48XX"
                                                  // "ТЕКСТОВЫЙ"
   char Ver[128];                      // Версия
   char Samolet[128];                  // "Ту-214 411"
   char Nakopitel[32];                 //  Наименование накопителя
   char DatePolet[64];                 // Дата полета
   int IndexBeginData;                 // Позиция в файле (в байтах) начала данных
   int IndexBazaMdb;                   // Позиция в файле (в байтах) начала Базы данных .mdb
   int LBazaMdb;                       // Размер (в байтах) Базы данных .mdb
   int IndexBazaBaz;                   // Позиция в файле(в байтах) начала Базы данных .baz
   int LBazaBaz;                       // Размер (в байтах) Базы данных .baz
   int IndexStructPaspChart;           // Позиция в файле(в байтах) начала Структур паспортов для файла документирования CHART
   int KStructPaspChart;               // Кол-во паспортов для файла документирования CHART
   int IndexStructRKChart;             // Позиция в файле(в байтах) начала единого массива структур RK
   int KStructRKChart;                 // Кол-во структур RK
   int TimeBegin;                      //  Время начала полета
   int TimeEnd;                        //  Время конца полета
   int DeltaTime;                      //  TimeEnd - TimeBegin
   int FTime;                          //  Частота следования меток времени
   int    F;                           // Частота Мах
   int IndexStructGif;                 // Позиция в файле(в байтах) начала Gif
   int LGif;                           // Размер (в байтах) Gif
   // int NStructPaspTimeChart;        // Порядковый Номер структуры ( в массиве структур паспортов ) паспорта Времени для файла документирования CHART
   char Rezerv[1376];                  // 1404
   // char Rezerv[1404];               // 2048
   };
*/
 struct PotokKadr            // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Структура объявлена также в файле "ShablonStruct.h" необходимо разобраться.
  {
 int IndexMas;         // Позиция в файле(в байтах) массива позиций выбранных
                       // параметров в Кадровом потоке
 short int KWord;
 short int NVxodKTF;   // Номер входа в выходном файле
 short int NStrNak;    // Номер структуры накопителя

  };

// ФОРМАТ ФАЙЛА ДАННЫХ 48ХХ
  struct IndexBlocFileDatXX
{
char TipData[256];                  // Тип данных
                                                  // "48FM"
                                                  // "48XX"
                                                  // "ТЕКСТОВЫЙ"
char Ver[128];                           // Версия
char Samolet[128];                    // "Ту-214 411"
char Nakopitel[32];                 //  Наименование накопителя
char DatePolet[64];                    // Дата полета
 int IndexBeginData;                  // Позиция в файле (в байтах) начала данных
 int IndexBazaMdb;                   // Позиция в файле (в байтах) начала Базы данных .mdb
 int LBazaMdb;                          // Размер (в байтах) Базы данных .mdb
 int IndexBazaBaz;                    // Позиция в файле(в байтах) начала Базы данных .baz
 int LBazaBaz;                           // Размер (в байтах) Базы данных .baz
 int IndexStructPaspChart;         // Позиция в файле(в байтах) начала Структур паспортов для файла документирования CHART
 int KStructPaspChart;                // Кол-во паспортов для файла документирования CHART
 int IndexStructRKChart;            // Позиция в файле(в байтах) начала единого массива структур RK
 int KStructRKChart;                 // Кол-во структур RK
 int TimeBegin;                       //  Время начала полета
 int TimeEnd;                          //  Время конца полета
 int DeltaTime;                        //  TimeEnd - TimeBegin
 int FTime;                                  //  Частота следования меток времени
 int    F;                                        // Частота Мах
 int IndexStructGif;                       // Позиция в файле(в байтах) начала Gif
 int LGif;                                     // Размер (в байтах) Gif
// int NStructPaspTimeChart;       // Порядковый Номер структуры ( в массиве структур паспортов ) паспорта Времени для файла документирования CHART
 short int KRealPotokKadr;         // Реальное кол-во Кадровых потоков
 struct PotokKadr PotokKadr[4];
 int IndexBeginPackData;                  // Позиция в файле (в байтах) начала упакованных данных
 int LPackData;                           // Длина (в байтах) упакованных данных
 short int KSecPiksel;                    // кол-во секунд в пикселе ( степень сжатия данных)
 bool FlagPackData;                       // = false , если  упакованных данные в файле данных отсутствуют
                                          // = true                -"-                         присутствуют
 short int KRealSecPackData;                  // кол-во реальных секунд в упакованных данных
 char Rezerv[1321];                     // 1404

// char Rezerv[1323];                     // 1404
// char Rezerv[1334];                     // 1404
// char Rezerv[1376];                     // 1404
// char Rezerv[1404];                    // 2048
};



struct  PaspChart                      // Структура   паспортов параметров
   {
   char   Razdel[32];
   char   Ident[16];
   char   Zamer[16];                   // Точка замера
   char    Name[128];                  //  Наименование параметра
   char    Razm[16];                   // Размерность
   char   TipS[16];                    //  Тип параметра :   Kod16, Kod32,RK, Float, Double, Время
   short int   Tip;                    //  Тип параметра :   если тип параметра Целый 16р(Kod16) Tip =0
                                       //                      -"-              Целый 32р(Kod32 Arinc) Tip =1
                                       //                      -"-              Вещественный Float Tip = 2
                                       //                      -"-              Вещественный Double Tip = 3
   short   int    F;                   //  Частота регистрации
   float    Min;                       // Min значение параметра в массиве
   float    Max;                       // Mах значение параметра в массиве
   short   int    NStrRK1;             //  № первой структуры RK
   short   int    KRK;                 // К-во  разовых команд в слове
   short   int  NSis[4];               // Номера систем (1,2,3,4)
   int   NPasp;                        // Номер паспорта по базе
   float Fiz[4];                       //
   unsigned int Kod[4];
   char   Rezerv[228];                 // Резерв
   };

struct  RKChart                        // Структура   RK
   {
   char Ident[16];                     // Общий идентификатор таблицы параметров
   char   NameRK[128];                 // Наименование RK
   short   int    NRazRK;              //  № разряда
   short     int   NRK_SL;             // № следующей структуры RK c одинаковым идентификатором
   char Rezerv[108];                   // Резерв   124
   };


struct  TimXX
   {
   unsigned int TInt  :32;
   unsigned int KParFaz  :16;          // Кол-во байт в фазе без байт для времени
   };


struct  ParamXX
   {
   union KodFizika
      {
      unsigned short int i[2];
      unsigned int L;
      float F;
      }KodFizika;
   unsigned int NPasp :14;
   unsigned int NSisNClov :2;
   };




 struct Gif
  {
  unsigned  int Time;         // Текущая секунда
  unsigned int TimeHAE;      // Номер полной 32 разр. сетки
  unsigned int Poz;          // Позиция в байтах (в файле данных) слова времени с целой секундой
  };

struct MinMax
   {
    union Min
     {
     float F;
     int   L;
     short int I[2];
     }Min;
    union Max
     {
     float F;
     int   L;
     short int I[2];
     }Max;
   };             // 8 байт

#endif       // Хромцов 2013_07_15

