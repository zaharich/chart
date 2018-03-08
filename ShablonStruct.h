//               DATA=2011.01.02     Единая структура паспортов
#ifndef ShablonStructH                              // Хромцов 2014_01_13
#define ShablonStructH                              // Хромцов 2014_01_13
#define KSISTEM 3                  // 2014_01_13
#define CHART_LSCREEN 2000        // кол-во пикселей на дисплее по горизонтали    // 2014_01_13
#define KGRMAX 11
#define SINXROCLOVO 0x55555555  //  синхрослово в файле данных формата XX
struct SisTable                 // Структура Системной таблицы
      {
       int    IndexSisTable;    // Начало структуры SisTable
       int    IndexPotok;       // Начало структуры Potok
       int    IndexPotokS;      // Начало структуры Potok
       int    IndexRazdel;      // Начало структуры Razdel
       int    IndexPasp;        // Начало структуры Pasp
       int    IndexTipPar;      // Начало структуры TipPar
       int    IndexBufNPasp2;   // Начало буфера № паспортов
       int    IndexRK;          // Начало структуры RK
       int    IndexDDK;         // Начало структуры RK
       int    IndexIndex;       // Начало индексного блока
       int    IndexNakopitel;   // Начало структуры Nakopitel
       int    LSisTable;        // Длина  системной таблицы
       int    LPotok;           // Длина  структуры потоков
       int    LPotokS;          // Длина  структуры потоков
       int    LRazdel;          // Длина  структуры разделов
       int    LPasp;            // Длина  структуры паспортов
       int    LTipPar;          // Длина  структуры типов
       int    LBlokTar;         // Длина  блока тарировок=0
       int    LRK;              // Длина структуры  RK
       int    LDDK;             // Длина структуры  DDK
       int    LIndex;           // Длина  массива индексного блока
       int    LNakopitel;       // Длина  структуры Nakopitel
       int    LBufNPasp;        // Длина  буфера № паспортов
       int    LFileStruct;      // Полная длина структур
       int    MasIndexBlok[256];// Массив адресов индексных блоков по NBxod
short  int    NSistem[256];     // Номера систем по потокам
short  int    MasPozKadr[256];  // Массив cчетчиков текущих позиций кадра (Для кадровых потоков)
short  int    KParTip[64];      // К-во паспортов по типпу параметра
short  int    KParGR[KGRMAX];   // Кол-во Параметров в группах (8 7 6 5 4 3 2 1 0)
short  int    KParTape[KGRMAX]; // Кол-во Параметров в Tape  (8 7 6 5 4 3 2 1 0)
short  int    LTape[KGRMAX];    // Длины Tape(в словах)      (8 7 6 5 4 3 2 1 0)
short  int    KNakopitel;       // К-во  Nakopitel
short  int    NProgGamma;       // К-во  Nakopitel
short  int    KPotS;            // К-во  всех потоков
short  int    KPot;             // К-во потоков интегральных
short  int    KRazdel;          // К-во Разделов
short  int    KPasp;            // К-во паспортов
short  int    KTipPar;          // К-во типпов параметров
short  int    KIndex;           // К-во
short  int    KRK;              // Общее количество  RK
short  int    KDDK;             // Общее количество  DDK
short  int    NPasp1;           // Номер Первого Паспорта Старшей Группы
short  int    NPaspTime[16];    // Номера паспортов времени
short  int    KPaspTime;        // К-во паспортов времени
      char    Zakaz[16];        // Заказ
      char    ProgramBaza[64];  // Какой программой формируются паспорта из БАЗЫ
      };

         struct Nakopitel                  // Структура накопителей
      {
        char  NameNak[32];        // Наименование накопителя
        char  TipNak[32];         // Тип накопителя (ТН1ПК,ТН1АЦ,МСРПА,Irig... )
short    int  NNak;              // Номер  накопителя
short    int  NStrPotS[32];      // Массив № структур потоковS
short    int  KStrPotS;          // К-во потоковS в накопителе
      };

struct Potok                     // Структура фактических интегрированных потоков
      {
        char  Potok[16];         // Наименование потока
        char  TipPot[16];         // Наименование потока (Arinc,Kadr, Time)
        char  FormatKadr[16];    //Формат кадра (Arinc,ГАММА,Mcrpa,Irig)
short    int  KSisPot;           // К-во систем в потоке
short    int  NSis[4];           // Номер системы (1,2,3,4)
short    int  NStrPotS[4];       // Номера структур в потоке S
short    int  NStrNak[4];        // Номера структур накопителей в которые вводятся потоки
short    int  NBxod[4];           // №   входа
short    int  NBxodKTF[4];        // №   входа КТФ
short    int  Lkc;                // Длина короткого цикла для потока Irig
short    int  KCikl;              // К-во циклов для потока Irig
short    int  NProgGamma;         // № Программы ГААМА
short    int  LKadr;             // Длина кадра
short    int  KKadr;             // К-во кадров в сек (для кадровых параметров)
short    int  NPasp1;            // Номер первого паспорта в потоке
short    int  NPasp2;            // N паспортa временая переменная
short    int  KPaspPot;          // К-во паспортов в потоке
short    int  NPotS;             // № cледующего потока по большому
short    int  NPotNak;           // № cледующего потока по накопителю
         int  IndexBlok;         // Индексный блок
         int  Inform;            // Информативность потока
      };

struct PotokS                     // Структура всех потоков
      {
        bool  Status;            //  1-Поток обрабатывается  0-нет
        char  Potok[16];         // Наименование потока
        char  TipPot[16];        // Тип потока (Arinc,Kadr.. )
        char  FormatKadr[16];    // Тип потока (Arinc,Kadr.. )
        char  Nakopitel[16];     // Накопитель (ТН1ПК,ТН1АЦ,Irig,МСРПА,ГАММА...)
short   int  Blok;
short   int  Plata;
short   int  Kan;
short   int  NNak;              // Номер структуры накопителя (0,1,2,3)
short   int  NTH;               // Номер накопителя
short   int  NSis;              // Номер системы
short   int  NBxod;             // Номер входа в накопитель(с 1 по  64)
short   int  NBxodKTF;          // Номер входа в КТФ(с 1 по  256)
short   int  Fmax;              // Максимальная частота параметров в потоке
      };

      struct Razdel                    // Cтруктура  разделов
      {
        bool  Status;            //  1-система обрабатывается  0-нет
        char  NSis[8];           // Порядковые номера систем (1,2,3,4)
        char  Razdel[32];        // Раздел перечня
short    int  NPasp1;            // Номер первого паспорта раздела
short    int  NPasp2;            // N паспортa следующего раздела
short    int  KPaspRazd;         // К-во паспортов раздела
      };

struct Pasp                       // Структура паспортов
        {
        bool Status;              //  1-паспорт обрабатывается  0-нет
        char Potok[16];           // Наименование Потока
        char TipPotok[16];        // Тип потока
        char Ident[16];           // Идентификатор параметра
        char Zamer[16];           // Замер
        char Adrec8[8];           // Адрес 8
        char Dathik[16];          // Датчик
        char Tipr;                // float-f,int-i,...
        char Razm[16];            // Размерность
        char Tips[16];            // TAR,ARING,RK,satelit...
        char Data[12];            // Дата
        char Name[128];           // Наименование параметра
        char NC_NCL[64];          // Содержимое поля NC_NCL БАЗЫ
short   int  KSis;                // К-во систем параметра
short   int  KPoz;                // К-во слов (Позиций) параметра
short   int  Kcl;                 // К-во слов параметра во входном kадре
short   int  NPot;                // N потока в структуре POTOK
short   int  NClova;              // N текущего слова в паспорте
short   int  NSis[4];             // Номера систем (1,2,3,4 в любой последовательности)
short   int  Poz1[4];             // Позиции параметра (Sek:   Poz1[0]-точный)
                                  //
                                  // Первые позиции для систем Arinc
        int   Kod[4];             // Коды параметра во входном кадре
      float   Fiz[4];             // Физические значения параметров
short   int  NRazd;               // N раздела перечня
short   int  Servis;              // Рабочая ячейка
short   int  Adrec10;             // Адрес 10
short   int  Tip;                 // Номер TAR,ARING,RK,satelit...(определяется структурой TipPar)
short   int  F;                   // Частота опроса параметра в сек
short   int  f;                   // Частота опроса параметра в кадре
short   int  Ngr;                 // Номер группы
short   int  NRK1;                // Номер первой RK
short   int  KRK;                 // К-во Разовых команд RK
short   int  N_pasp_sat;          // №  паспорта сателита (Калибровка  либо код max для Тar)
        int  N_pasp_sat1;         //NGr=Arinc   NGr  в смежной позиции канала темп.N_pasp_sat1=-2
                                  //NGr=KanTemp NGr находится в канале температур  N_pasp_sat1=-3
                                  //NGr=HET     NGr нет,емпература в канале одна   N_pasp_sat1=-4
                                  //NGr=IdentNGr    NGr задан в виде Sat  N_pasp_sat1=NPasp
                                  // №  паспорта грубого канала для секц. датчика
short   int  N_pasp_sat2;         // №  паспорта холодного спая для БСПИ3
unsigned short   int  N_pasps;             // N  следующего  паспорта в группе
unsigned short   int  N_pasps_sis;         // N  следующего  паспорта в системе (Разделе)
unsigned short   int  N_pasps_pot;         // N  следующего  паспорта в потоке
unsigned short   int  N_pasps_inf;         // N  следующего  паспорта по информации
unsigned short   int  K_pasps_inf;         // К-во паспортов по информации
         float  Min;                       // Минимальное значение параметра
                                           // MIN процент грубого канала по типу SEK
         float  Max;                       // Максимальное значение параметра
                                           // MAX процент грубого канала по типу SEK
         float  Corect;                    // Корекция значения параметра
         void  *AdresPar;                  //
         void  *AdresKod;                  //
         class  DehifrClass *adres_class_dehifr; // адрес экземпляра класса расшифровки параметра
// ЕДИНЫЙ ТАРИРОВОЧНЫЙ БЛОК
  short int r[3];                  // Tar - Разряды регистрации
  short int d;                     // Диапазон параметра 180 либо 360
  short int ng;                    // Номер групы
  short int nmrg;                  // Номер младшего разряда группы
  short int NDiap;                 // Номер диапазона БСПИ3, № ветки для секционированого датчика
  short int model;                 // N модели TIME
  short int pok;                   // Показатель опорной частоты
  short int m;                     // Передаточное напряжение
  short int kz;                    // Коэф. загрубления, К-во веток секционированого датчика
  short int KodSt;                 // Код стояночный для Tenzo
  short int SPol;                  // Степень полинома для TAR (1-5) либо К-во точек для Inter
       char var;                   // r-cr s-cs z-cz признак цены разряда
     double cr;                    // Цена  младшего разряда, делитель для APFT
     double kapr[6];               // Коэффициенты аппроксимации для TAR,TENZO
                                   // Кapr[0]- Точка переключения секц. датчика Sek
                                   // kapr[1,2,3,4,5]-Коэфф.аппроксим. для точных ветвей секц. датчика Sek
                                   // kapr[0] - временно в паспорте опорного времени  -ячейка для хранения точного времени в секундах типа double
        };

struct TipPar                      // Описатель типпа параметра
      {
         short int  Tip;           //  Номер модели дешифровки
         short int  modif;         //  Подтип модели
              char  TipS[16];      //  Тип дешифровки символьный
         short int  LPar;          //  Длина параметра в кадре СБИ в 16р словах
         short int  maska;         //  маска в кадре СБИ 0 либо 1
         short int  LMinimax;      //  Длина параметра в кадре MINIMAX
              char  TipPar;        //  Тип параметра(f,i,l)
         short int  KPar;          //  К-во параметров данного типпа
      };

 struct RK                     // Единая структура RK и ArincRK
     {
          char Potok[16];     // Поток
          char Ident[16];     // Общий идентификатор таблицы RK
          char Name [128];     // Наименование RK
     short int NRazRK;        // Номер разряда RK
     short int Adrec;         // Адрес RK
     short int EXTR;          // Признак экстремальной команды
     short int NRK_SL;        // № следующей структуры RK c одинаковым идентификатором
     };

struct DDK                    // Структура DDK  r18.3=cs
                              // Структура DDK  r18=cs (По умолчанию=.4)
     {
     short int R;             // Номер разряда тетрады
     short int KRazTet;       // К-во разрядов тетрады
         float cr;            // Цена  разряда тетрады
     };


// Структура файла 48FM  от 10.07.2010
//====================================
   struct  Tim
        {
        unsigned int TInt  :32;
        unsigned int NFaz  :12;
        unsigned int Tip   :4;
        };


struct  Arinc
        {
        unsigned int Kod   :24;
        unsigned int Adrec :8;
        unsigned int NBxod :12;
        unsigned int Tip   :4;
        };

struct  Kadr
        {
        unsigned int Kod1  :16;
        unsigned int Kod2  :16;
        unsigned int NBxod :12;
        unsigned int Tip   :4;
        };



// Структура  32-разрядного слова индексного блока
//================================================
struct  Index
        {
         unsigned int NSis :4;       // Номер системы для Arinc
          unsigned int NCl :4;       // Status=0 - Позиция пересылается в паспорт по номеру Ncl
        unsigned int KPasp :8;       // Количество паспортов на одной позиции кадра
unsigned int IndexBufNPasp :16;      // Индекс буфера № паспортов
        };
// Структура  32-разрядного слова адресной шины Дамьен
//====================================================
struct  AdrecDamen
        {
        unsigned int Tip    :6;  // Тип параметра 26-31
        unsigned int End    :2;  //  24-25 разряд: 24=1-Конец фазы 25=1- Конец кадра
        unsigned int NBlok  :3;  // 21-23 разряд:№ Блока
        unsigned int NPlata :5;  // 16-19 разряд:№ Платы
        unsigned int Adrec  :8;  // 8-15  разряд:Адрес паораметра
        unsigned int MSB    :3;  //   5   разряд: 1-MSB  2=LSB
        unsigned int NKan   :5;  // 0-2   разряд:  № Канала
        };

// Формат выходного файла
// ЗАГОЛОВОК:
       // структура                                 struct IndexBlocFileDatVer3
       // Тип данных                                                  char[256]
       // Версия MinimaxWin                                           char[256]
// Данные в формате 3 Версии MinimaxWin
 struct PotokKadr
  {
 int IndexMas;         // Позиция в файле(в байтах) массива позиций выбранных
                       // параметров в Кадровом потоке
 short int KWord;
 short int NVxodKTF;   // Номер входа в выходном файле
 short int NStrNak;    // Номер структуры накопителя

  };

struct IndexBlocFileDatVer3
{
 int IndexBeginData;   // Позиция в файле(в байтах) начала данных
 int IndexBazaMdb;     // Позиция в файле(в байтах) начала Базы данных .mdb
 int LBazaMdb;         // Размер (в байтах) Базы данных .mdb
 int IndexBazaBaz;     // Позиция в файле(в байтах) начала Базы данных .baz
 int LBazaBaz;         // Размер (в байтах) Базы данных .baz
 int IndexOldHeadTN1;  // Позиция в файле(в байтах) начала старого заголовка ТН1
 int LOldHeadTN1;      // Размер (в байтах)  старого заголовка ТН1
 int TimeBegin;        //  Опорное Время начальное
 int TimeEnd;          //       -||-     конечное
 int FTime;            //  Частота следования меток времени
 int DeltaTime;        //  TimeEnd - TimeBegin
 int TimeHAEBegin;     //  ХАЕ     Время начальное
 int TimeHAEEnd;       //       -||-     конечное
 int FTimeHAE;         //  Частота следования меток времени ХАЕ
 int DeltaTimeHAE;     //  TimeHAEEnd - TimeHAEBegin
 short int KRealPotokKadr;  // Реальное кол-во Кадровых потоков
 struct PotokKadr PotokKadr[4];
 char NameBaza[64];          // Неполное Имя базы без директорий и расширений     // По заказу 15650 2014_11_11
 char Rezerv[90];     // 154                                                      // По заказу 15650 2014_11_11
// char Rezerv[154];     //  //                                                   // По заказу 15650 2014_11_11
// char Rezerv[186];     // 196
// char Rezerv[196];     // 228
// char Rezerv[228];     // 228
};





/*IndexBlocFileDatVer3,*PtrIndex;
char TipData[256];     // Тип данных
                       // "МСРПА"
                       // "IRIC"
                       // "ТН1ПК"
                       // "ТН1АЦ"
char Ver[256];         // Версия
// Имя опорного времени(по которому велась текущая обработка)         char[256]
*/

//------------------------------------------------------------------------------

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
// short int KRealPotokKadr;         // Реальное кол-во Кадровых потоков  2014_01_28
// struct PotokKadr PotokKadr[4];          // 2014_01_28
 int IndexBeginPackData;                  // Позиция в файле (в байтах) начала упакованных данных
 int LPackData;                           // Длина (в байтах) упакованных данных
 short int KSecPiksel;                    // кол-во секунд в пикселе ( степень сжатия данных)
 bool FlagPackData;                       // = false , если  упакованных данные в файле данных отсутствуют
                                          // = true                -"-                         присутствуют
 short int KRealSecPackData;                  // кол-во реальных секунд в упакованных данных
 int IndexStructRazdel;                   //  Позиция в файле(в байтах) начала Структур Разделов
 int KStructRazdel;                       //  Кол-во  Структур Разделов
 char NameBaza[64];          // Неполное Имя базы без директорий и расширений     // По заказу 15650 2014_11_11
 char Rezerv[1291];                                                               // По заказу 15650 2014_11_11
// char Rezerv[1355];                                                             // По заказу 15650 2014_11_11
// char Rezerv[1313];                     // 2014_01_28
// char Rezerv[1321];                     // 1404
};

//------------------------------------------------------------------------------

struct  PaspChart                          // Структура   паспортов параметров
 {
  char   Razdel[32];
  char   Ident[16];
  char   Zamer[16];                      // Точка замера
  char    Name[128];                     //  Наименование параметра
  char    Razm[16];                       // Размерность
  char   TipS[16];                         //  Тип параметра :   Kod16, Kod32,RK, Float, Double, Время
  short int   Tip;                         //  Тип параметра :   если тип параметра Целый 16р(Kod16) Tip =0
                                           //                      -"-              Целый 32р(Kod32 Arinc) Tip =1
                                           //                      -"-              Вещественный Float Tip = 2
                                           //                      -"-              Вещественный Double Tip = 3
  short   int    F;                            //  Частота регистрации
  float    Min;                               // Min значение параметра в массиве
  float    Max;                              // Mах значение параметра в массиве
  short   int    NStrRK1;              //  № первой структуры RK
  short   int    KRK;                     // К-во  разовых команд в слове
  short   int  NSis[4];                   // Номера систем (1,2,3,4)
  int   NPasp;                            // Номер паспорта по базе
   float Fiz[4];                       //    // 2014_01_13
   unsigned int Kod[4];                     // 2014_01_13
  unsigned short   int  N_pasps_razdel;   // N  следующего  паспорта в Разделе
   short int   NRazdel;                   // номер структуры раздела      // 2014_04_08
   char   Rezerv[224];                    // Резерв     // 2014_04_08
//   char   Rezerv[226];                 // Резерв     // 2014_04_08
//   char   Rezerv[228];                 // Резерв     // 2014_01_13
//    char   Rezerv[260];                   // Резерв    // 2014_01_13
 };

struct  RKChart                      // Структура   RK
 {
 char Ident[16];                     // Общий идентификатор таблицы параметров
 char   NameRK[128];                 // Наименование RK
 short   int    NRazRK;              //  № разряда
 short     int   NRK_SL;             // № следующей структуры RK c одинаковым идентификатором
 char Rezerv[108];                   // Резерв   124
 };

 struct Gif                  // 2014_01_13
  {
  unsigned  int Time;        // Текущая секунда
  unsigned int TimeHAE;      // Номер полной 32 разр. сетки
  unsigned int Poz;          // Позиция в байтах (в файле данных) слова времени с целой секундой
  };

struct MinMax                  // 2014_01_13
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
//=============================================================================
struct  TimXX
        {
        unsigned short int LFaz;       // Длина фазы в байтах
        LONGLONG TInt;                 // 64-разрядной (тип long) записью времени фазы в 100-наносекундных интервалах.
        };
        
struct  TimXXS
        {
        unsigned int Sinxroclovo;
        struct  TimXX TimXX;
        };
/*
struct  TimXX
        {
        unsigned int TInt  :32;
        unsigned int KParFaz  :16;       // Кол-во байт в фазе без байт для времени
        };
*/
/*
struct  ParamXX                           // 2014_01_13
        {
        unsigned int LDat :3;             // кол-во слов(16р) данных для параметра
        unsigned int NPasp :13;           // номер паспорта
        };
*/

struct  ParamXXAnalog                           // 2014_01_13    Для конвертирования (БСПИ2,БСПИ3,ПЧИ,...многословных параметров в формат 48ХХ)
        {
        unsigned int Kod :12;              // код аналового параметра (Гамма,IRIG, ...)
        unsigned int NSlov :4;             // номер слова (1,2,...)
        };
struct  ParamXX                           // 2014_01_13
        {
        unsigned short int NSis_NClov :2;       // номер системы для штатных потоков, номер слова параметра для экспериментальных потоков
        unsigned short int NPasp :14;           // номер паспорта
        };

//=============================================================================

struct  ParamXXChart                     // 2014_01_13
        {
          union KodFizika
          {
          unsigned short int i[2];
          unsigned int L;
          float F;
          }KodFizika;
        unsigned short int NSisNClov :2;
        unsigned short int NPasp :14;
        };
/*
struct  ParamXXChart                     // 2014_01_13
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
  */

#endif       // Хромцов 2014_01_13

