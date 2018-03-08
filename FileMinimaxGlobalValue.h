#ifndef FileMinimaxGlobalValueH
#define FileMinimaxGlobalValueH
//---------------------------------------------------------------------------
#include <fstream.h>
#define KPOLEIMAX     16           //кол-во полей для вывода в таблицы
#define KPASPTIME 32               // кол-во  паспортов времени
#define KHANDLE 100                // Максимальное кол-во  окон Пользователя
#define KSISTEMMAX  4              // Максимальное кол-во систем
struct FlagPotokVizual
{
bool DriverOpen;             // = true Драйвер ввода данных с борта запущен  // 2007_10_31
int     TipWindows;          // Тип Окна  =0 Контроль_Систем =1
int     TipPotoka;           // =0 не создан
                             // =1 Борт "Работа"
                             // =5 "File"
                             // =10 Борт "Тест"
char    NameTipPotoka[64];
//int     CloseDisminVizualPotok; //=1 Запрет на открытие потоков
                                // ISRDismin,ISRVizual
int     TipBort;             // 0 - Туполев 1 - ТН( контроль 6 отделение ЛИИ)
//int	FileFormat;	     // =1 открыт Файл форматы
                             // =2 Выбор Файла настройки,необходим для первой
                             //  перирисовки окна ChartMinimax
int	FileDat;	     // =1 открыт Файл данных
int     TipFileIni;          // Тип файла настройки
                             // =0 файл настройки старый
                             // =1 создать новый файл настройки
                             // =2 Работа по контролю Плат
                             // =3 Работа по контролю Систем

int     NVxodIni;            // 0 - первый вход с новым типом файла настройки
                             // 1- не первый вход
//int     ControlPlat;         // =1 Работа по контролю Плат
//int     ControlSistem;       // =1 Работа по контролю Систем
int     FlagFileOut;         // =0 Нет выходного файла
                             // =1 есть вывод в выходной файл
bool    FileOutNoWrite;      // = 1 отменить вывод в выходной файл
                             // (для управления записью в библиотеке пользователя)
int     Baza;
int TipBaza;                 // Откуда берется база =0 из базы =1 из файла данных
char NameTipBaza[32];        // Откуда берется база    "из базы" "из файла данных"
bool FlagEditionBaza;        // флаг редактирования базы  = false не редактировать
int     DllOpen;             // =1 программа пользователя подключена
                             // =0 нет
//int     Instal;             // =0 Параметры для визуализации не настроены
                             // =1         =|=                   настроены
int     FlagGrafik;           // =1 есть вывод в графическое окно
int     Graphics;            // =0 Нет Графиков
                             // =1 Есть Вывод графиков
int     TablRight;           // =1 Есть Вывод Данных в Правую Таблица
                             // =0 Нет
int     TablDown;            // =1 Есть Вывод Данных в Нижнюю Таблицу
                             // =0 Нет
int     ControlBort;         // =1 Есть вывод в окно контроля борта
                             // =0 Нет
//int     Nastroika0;          // =0 необходима начальная настройка
                             // т.е. было либо иззменение размеров окна
                             // либо смена формата,...
int     PageEndStop;            // Признак остановки ввода данных
                                // либо по концу страницы либо принудительно
                                // =0 нет остановки
int     EndVvodDat;          // Для правильного завершения Потока "Dismin"
                             // Признак завершения ввода потока данных
                             // либо по концу страницы,либо принудительно
                             // =1 данные подаются
//int     NastroikaChart;      // =1 Файл форматы открыт ,шкалы построены ...
//int     KadrObrab;           // =1 Кадр обработан, =2 Кадр в состоянии
                             // обработки
//int     PageBegin;           // Признак перехода на новую граф.страницу
int     TablDownBegin;       // Признак перехода на новую таблицу
//short int     *KadrDisminInp; // Адрес входного кадра для обработки
int     BortOffOn;            // =1 Ввод с Борта запущен
int     Test;                 // =1 Тестирование разрешено(начальная установка
                              //    события теста )
unsigned int Vivod;           // 32 разрядная маска
                              // 0р =1 есть вывод информации на график или таблицу
                              // 1р =1 есть вывод в окно BortControl
                              // ...
unsigned int VivodTek;        // контроль завершения вывода  информации
                              // согласно маски  Vivod
int ChangeFormat;             // Признак смены форматов; =1 на время перерисовки
                              // формата( шкал,сетки,шаблона таблицы ...) и инсталяции
int FlagDismin;
bool NoParam;                 // = true если параметр в списке не найден в базе
bool Reper;
bool Printer;                 // = true - вывод графики на принтер = false на дисплей
bool EditFormat;              // = true Фомат был изменен
int ArincIric;                // = 0 вид входного потока Arinc
                              // = 1 вид входного потока Iric
HWND HandleFormUser[KHANDLE];
HANDLE HandleMainFormMinimax;
int KWindowsUser;             // Кол-во окон пользователя
//int  CountWindowsUser;      //
int KFormControlSistem;
int KFormGrafic;
int KFormFileOut;
int KFormKonvert;
int MasFormControlSistem[KHANDLE];       // MasFormControlSistem[i] = -1 ,если окна с номером i не существует
int MasFormGrafic[KHANDLE];              // MasFormGrafic[i] = -1 ,если окна с номером i не существует
int MasFormFileOut[KHANDLE];             // MasFormFile[i] = -1 ,если окна с номером i не существует
int MasFormKonvert[KHANDLE];             // MasFormKonvert[i] = -1 ,если окна с номером i не существует
int MasHANDLE[KHANDLE];       // MasHANDLE[i] = -1 ,если окна с номером i не существует
int KClassSpisok;
int KClassFormat;
struct Ini * PtrIniBegin;     // Адрес Структуры Для Первого Окна
struct Ini * PtrIniEnd;       // Адрес Структуры Для Последнего Окна
char FileNameBaza[256];       // Имя Файла Базы данных
char FileNameLibrary[256];    // Имя Файла Библиотеки( для расчетных параметров )
char FileNameDataInp[256];        // Имя Файла Данных
char FileNameDataOut[256];        // Имя Файла Выходных Данных
int WindowsUserTek;               // Текущее окно пользователя
int NumberWindowsControlSistem;   // Номер Текущего окна
int NumberWindowsGrafic;          // Номер Текущего окна
int NumberWindowsFileOut;          // Номер Текущего окна
int NumberWindowsKonvert;          // Номер Текущего окна
int NumberClassFormat;       // Порядковый Номер экземпляра Класса FormatClass
int NumberClassSpisok;
bool Interfeis;                 // = true Единый для всех окон =false Автономный для каждого окна
char MinimaxWinDir[256];        // Имя Системной Папки
bool ChangeNastroiki;           // Флаг изменения настройки
int FlagOnPaintGrafic;                // < 2 - Обработчик SplitterRightLeftPaint
                                // не работает
int FlagTenzo;                  // если = 1 Получение стояночных кодов  // 2008_01_22
                                // если = 2 Обработка сучетом стояночных кодов
bool RegimBortFileOut;          // == false,       в разные      // 2008_02_16
                                // == true, запись в единый выходной бортовой файл
char IPAdresServer[32];         // 2009_07_08
char IPAdresClient[32];         // 2009_07_08
int NumberNakTN1PK;             // номер накопителя ТН1ПК (0,1 ...)                   
};
//------------------------------------------------------------------
//#define KKADRBUFINP 4 //16
#define KKADRBUFINP 16
#define KGRMAX 11
#define KFAZMAX 1024
struct WinSistTab //
	{
unsigned short int ScreenWidthMax;          // Ширина экрана дисплея в пикселях
int *BitNPodkadr;                           // Адрес массива Номер Подкадра{от номера бита]
unsigned short int NumberPixelBegin;        // Номер пикселя первой точки на графике
unsigned short int NumberPixelEnd;          // Номер пикселя последней точки на графике
unsigned short int ChangeStepIntervalTime;  // Признак изменения Шага об-ки,
                                            // Интервала,выбор нового аргумента
                                            // времени
int NBitReper;         // Номер пикселя Репера (от левой границы рамки)
//unsigned short int  *AdresKadrIntegrator;
//unsigned short int  LKadrIntegrator;
unsigned short int     *BufKadrIrigWrite; // Адрес буфера Файла IRIC  ВРЕМННО
unsigned short int      SizeBufKadrIrigWrite; // Размер буфера Файла IRIC ( в short int ) ВРЕМННО
unsigned char          *BufTN1PKWrite;
unsigned int            SizeBufTN1PKWrite;
short int NvxodIrig;        // Номер входа для IRIG    ВРЕМЕННО
unsigned short int     *BufInpKadr;       // Адрес буфера входного Файла Копии Потоков
unsigned short int     *BufInp; // Адрес входного буфера
unsigned short int     *KadrInp; // Адрес входного кадра для обработки
//unsigned short int     *KadrDehifrInp; // Адрес входного кадра для обработки
unsigned short int     LKadrInp; // Длина входного кадра для обработки
unsigned int           SizeBufInpKadr;  // Длина буфера входного Файла потоков
unsigned int           BufInpKadrIndex; //  индекс(номер слова) в буфере  потоков
unsigned int           KKadrIric;       // Кол-во каров Iric в файле данных
int                    NKadrTekIric;     // номер текущего кадра в файле данных
int                    NKadrTekDehifr;       // номер текущего кара в файле данных для расшифровки
int                    NKadrBeginPage;  // номер кадра в файле данных в начале страницы
      unsigned int KKadrBufInp; // Кол-во Кадров в буфере
      int NKadrBufInpEppTek; // Номер последнего заполненого кадра EPP
      int NKadrBufInpFileWriteTek; // Номер текущего незаписанного кадра
      int NKadrBufInpDehifrTek; // Номер последнего расшифр. кадра
//      short int *MarkerKadrBufInp;  // Адрес массива маркеров
                                    // маркер=1 кадр обработан обработчиком
                                    // прерывания приложения
                                    // =2 записан в файл
unsigned short int NGrMax;         // Номер старшей группы в кадре
unsigned short int KFazMax;        // Максимальное кол-во фаз в кадре
unsigned short int KKadrSek;       // кол-во кадров в секунде
unsigned short int KFazSek;        // кол-во фаз в секунде
//unsigned short int LTimeFaz_1024;  // Длительность фазы в долях от 1024
unsigned short int StepFrame;      // Через сколько слов производить
                                   // копировние Интегратора ВРЕМЕННО (для Iric)
unsigned short int StepFrameBaza;
int InformFrame;                   // Временно Информативность в циклах
unsigned short int NFazTek;
unsigned short int NGrTek;
unsigned short int NFazTekDehifr;
unsigned short int NGrTekDehifr;
//short int          NPaspTime[KPASPTIME]; // Массив номеров паспортов времени в структуре
short int          NPaspTime[32]; // Массив номеров паспортов времени в структуре
short int          KPaspTimeReal;        // Реальное кол-во пасортов
short int          NPaspTimeTek;            // Номер паспорта текущего времени в структуре Pasp
float *AdresTimeBort;
//float *AdresTimeDehifr;                 // Необходим для реального времени, всвязи с многопоточной работой
float *AdresTimeKadr;
float TimePage;                      // Кол-во секунд на странице
float TimeTekBort;
float TimeTekDehifr;                 // Необходим для реального времени, всвязи с многопоточной работой 2010_02_15
float TimeBegin;                     // Начальное время в данных
float TimeEnd;                       // Конечноеное время в данных
float TimeTekBortOldDehifr;          // для оределения дельты времени
float TimeTekBortOldVizual;          // для оределения дельты времени
float TimeTekKadr;
float TimeTekBeginPage;
float TimeTekEndPage;
float TimeBeginTN1PK;                // Время начала записи в файле ТН1ПК
float TimeEndTN1PK;
int FlagDehifr;
//unsigned short int  *AdresGr0InpDehifr; // Адрес нулевой группы
                                        // входного кадра для обработки
float              LTimeKadr;           // Длительность кадра в сек
float              LTimeFaz;            // Длительность фазы в сек
unsigned short int StepFazDehifr;       // Шаг дешифровки в фазах                 // Кол-во опросов за секунду   2013_01_14
unsigned short int StepFazVizual;       // Шаг визуализации в фазах
float              StepTimeDehifr;      // Шаг дешифровки в секундах
float              StepTimeVizual;      // Шаг визуал. в секундах
short int          StepKadrFaz;         // =0 обработка по фазам
                                        // =1 обработка по кадрам ( шаг об-ки
                                        // больше длительности кадра)
unsigned short int IndexBufInp;                   //
unsigned short int IndexBufInpDehifr;
unsigned int       CountFazDehifr;      // Счетчик фаз для Дешифровки кадрового времени
unsigned int       CountFazEpp;         // Счетчик фаз для При приеме с борта
FILE *StreamInp;
FILE *StreamOut;
char FileNameOut[128];
char FileNameInp[128];
int FileWriteCount;      // Счетчик файлов
unsigned int StepWrite;     // Шаг прореживания записи
unsigned int FlagWrite;              // =0 нет записи =1 запись
unsigned int WriteOffOn;    // =1 Запись запрещена =0 разрешена
                            // пока поток записи не завершится (ISRFileWrite)
unsigned int FileSizeTek;   // Размер файла копии
unsigned int CountFileWrite; // Счетчик записанных кадров
unsigned int CountFileWriteStep; // Счетчик кадров для записи без прореживания
unsigned int CountCloseFile;   // Счетчик количества закрытий файла
unsigned int CountPrerVizual;
/*short int *MasNstrNPasp;    // Указатель на массив номеров struct Pasp по алфавиту идентификаторов
short int *MasNstrNPaspZamer;    // Указатель на массив номеров struct Pasp по алфавиту точек замеров
short int *MasNstrNSistem;  // Указатель на массив номеров struct Sistem по алфавиту
short int *MasNstrNSistemNPasp;// Системы по алфавиту Параметры по алфавиту
                               // внутри систем
short int *MasNstrNPotok;  // Указатель на массив номеров struct Potok по алфавиту
short int *MasNstrNPotokNPasp;// Потоки по алфавиту Параметры по алфавиту
                               // внутри потоков
short int *MasNstrNRazdel;  // Указатель на массив номеров struct Razdel по алфавиту
short int *MasNstrNRazdelNPasp;// Разделы по алфавиту Параметры по алфавиту
                               // внутри разделов
                               */
short int KBlok;               // Кол-во блоков в системе сбора
struct Blok *AStructBlok;
struct Plata *AStructPlat;
struct Kanal *AStructKanal;
short int KFormatPlat;         // Общее Кол-во форматов по платам
short int NFormatPlat;         // Номер текущего формата по платам
bool FlagNoDehifrTime;         // =false Опорное Время(аргумент) не расшиф.
                               // Для того чтобы не было двойного расчета времени
                               // =true Время  расшиф.
bool FlagPiritTimeKadr0;       // ( для правильного расчета времени без миллисекунд)
                               // = false Счетчик кадров Времени Пирит Обнуляется
void *AdresParamProperty;      // Адрес  Параметра для определения его свойств
int KParamDllInp;              // Кол-во входных параметров для DLL (программы рользователя)
int KParamDllOut;              // Кол-во выходных параметров для DLL (из программы рользователя)
struct DllPar *PtrStructDllInp; // Адрес Временного буфера для структур входных параметров
struct DllPar *PtrStructDllOut; // Адрес Временного буфера для структур выходных параметров
bool ReperTimePirit;
unsigned short int *AdresKadrMcrpa;
int PageTop;
int PageBottom;
int PageLeft;
int PageRight;
int WidthLineSetka;           // Коэф.толщины линии сетки для принтера        //2010_10_25
int WidthLine;                // Коэф.толщины линии для принтера        //2007_11_01
int WidthLineDouble;          //  Коэф.толщины линии для принтера для разовой ком. при РК=1  //2007_11_01
bool FlagPotokNotKadr;          // =false если поток кадровый =true если некадровый
int NPaspTimeMarker_1;          // Временно пока в Базе Неопределен поток времени
short int KPoleiTablParam;     // Номер кол-во полей в FormParam
short int NColNPole[KPOLEIMAX];// Номер колонки,Номер поля
short int NPoleNCol[KPOLEIMAX];// Номер поля,Номер колонки
                                // 1-Идентификатор
                                // 2-СБИ
                                // 3-Система
String   NPoleNamePole[KPOLEIMAX];
//   {"Идентификатор","СБИ","Система","Адрес","Тип","Частота",
//    "Код","Физика","Точка замера","\0","\0","\0","\0","\0","\0","\0"};
	};

#define KTIP 16
#include "ShablonStruct.h"
union TAK
{
struct     Arinc Arinc;
struct      Kadr Kadr;
struct       Tim Tim;
};
/*      struct TipPar TipPar[]=
                     {
                      {0,0,"0",0},
                      {1,0,"Tar",1},
                      {2,0,"Bcpi2",2},
                      {3,0,"Bcpi3",1},
                      {4,0,"Sat",1},
                      {5,0,"-",1},
                      {6,0,"-",1},
                      {7,0,"RK",1},
                      {8,0,"Pchi",2},
                      {9,0,"Cno",2},
                      {10,0,"Tenzo",1},
                      {20,0,"Arinc",2},
                      {21,0,"ArincRK",2},
                      {22,0,"ArincSat",2},
                      {23,0,"ArincTar",2},
                      {30,0,"Time",3},  //Время  московское
                     };

  */

struct Blok
{
char name[16];
short int nblok;
short int NCombo;           // Номер в списке ComboBox
short int KPlat;
struct Plata *AdresPlat;
};
struct Plata
{
char name[16];
short int nplat;
short int KKan;
short int NCombo;           // Номер в списке ComboBox
struct Kanal *AdrKan;
short int NFormat;     // Для Платы ЯКК(аналоговой)
};
struct Kanal
{
short int NFormat;   // Номер форматки для визуализации
short int NKan;    // Номер канала и Номер структуры struct Kanal могут не совпадать
short int NCombo;           // Номер в списке ComboBox
};


// Редактировать структуру "Ini" ЗАПРЕЩЕНО
// Разрешается вводить новые поля только в конец структуры, перед полем "rezerv"
// уменьшив при этом размер поля "rezerv" на кол-во байт, необходимых для
// вновь вводимого поля
struct Ini
{
bool Interfeis;                 // = true Единый для всех окон = false Автономный для каждого окна
int TipWindows;   // Тип Окна  =0 Контроль_Систем =1
char NameTipWindows[64];   // Имя Типа Окна  ("Контроль_Систем" и т.д.)
HWND Handle;
int NumberWindows;           // Порядковый Номер Окна Для данной растройки
int NumberFormTip;           // Порядковый Номер Окна данного Типа
int NumberClassFormat;       // Порядковый Номер экземпляра Класса FormatClass
//int NumberClassTabl;         // Порядковый Номер экземпляра Класса TablClass
struct Ini * AdresPred;
struct Ini * AdresNext;
int  TipDataInp;             // Тип входных данных
                             // =0  данные отсутствуют
                             // =1 Борт "Работа"
                             // =2 "Копия IRIC_334_5"
                             // =3 "Копия МСРПА"
                             // =5 "Копия ТН1ПК"
                             // =10 Борт "Тест"

char NameTipDataInp[32];     // Имя Типа потока вводимых данных
//char TipBortInp[32];       // Тип Работы с Бортом  (Тест Работа)
char FileNameDataInp[256];   // Имя Файла вводимых данных
char FileNameBaza[256];      // Имя Файла Базы данных
char FileNameFormatka[256];  // Имя Файла Форматки
int TipBaza;                 // Откуда берется база =0 из базы =1 из файла данных
char NameTipBaza[32];        // Откуда берется база    "из базы" "из файла данных"
bool FlagEditionBaza;        // флаг редактирования базы  = false не редактировать
int  TipDataOut;             // =0 нет выходного файла =1 Текстовый =2 AVIONIX
char NameTipDataOut[32];         // Имя Типа выходного файла
char FileNameDataOut[256];   // Имя выходного Файла данных
char FileNameSpisok[256];    // Имя Файла списка выводимых параметров
char FileNameLibrary[256];   // Имя Файла Библиотеки( для расчетных параметров )
bool EditNameFileOut;        // = false Имя выходного файла получается Автоматически
float Top;
float Left;
float Width;
float Height;
int ArincIric;                // = 0 вид входного потока Arinc
                              // = 1 вид входного потока Iric

char rezerv[6433];
};

struct DllPar
{
char name[16];                    // Идентификатор расчетного параметра
void *adres;
char name1[16];                   // Идентификатор опорного параметра
//int ngr;
char tip;
char name2[64];                   // Наименование параметра
void *adrespaspopornpar;              // 2013_05_06    Адрес паспорта опорного параметра
void *adrespaspraspar;                // 2013_05_06    Адрес паспорта расчетного параметра
};

#define KPotokAringMax 64
#define KPrerInit 100      // Кол-во прерываний для определения кол-ва потоков
#define SinxrWord1 0xd99
#define SinxrWord2 0x87d
#define MaskFrame 0x00f8
struct Test
{
int   KPrerInitMax;
unsigned short int *AringKadrAdres[KPotokAringMax];// Указатели на буфера входных кадров
unsigned short int *GammaKadrAdres[4];              // Указатели на буфера входных кадров
unsigned short int *MsrpaKadrAdres[2];              // Указатели на буфера входных кадров
/*int IrigCountKadr[2];      // Кол-во принятых кадров
int IrigLKadr[2];          // Длина кадра в словах
int IrigKFrame[2];         // Кол-во циклов
int IrigLFrame[2];         // длина цикла
int IrigSboiKadr[2];       // Кол-во сбойных кадров
int IrigInform[2];         // Информативность
int IrigDlitKadr[2];       // Длительность кадра
*/
int *AringAdresCount[KPotokAringMax];  // Указатели на буфера адресов счетчиков
                                       //
int AringInform[KPotokAringMax];
};
//-------------------------------------
    struct PotokBort
    {
    bool AringTime;
    short int NCanal;
    short int TipPotoka;
    short int NumberWord;
    int NumberTimeIntegrator;  // Номер позиции первого слова времени ТН1ПК в интеграторе
    union                      // Слово ARINC
     {
     unsigned int l;
     unsigned short int i[2];
     }un;
    };
//-------------------------------------

struct Irig
{
unsigned short int *AdresKadr;          // Указатель на буфер входного кадра
bool PriznakPotoka;            //0-false-поток отсутствует, 1-true-присутствует
unsigned short int Kadr;          //признак начала кадра
unsigned short int Kadr0;          //=1 найдено начало первого кадра
unsigned short int LKadr;
unsigned short int LFrame;
               int Inform;         // Информативность в словах
         short int KKadr;          // Кол-во кадров в сек
unsigned short int NumberWord;      //текущее кол-во слов в цикле
unsigned short int NumberWordKadr;  //текущее кол-во слов в кадре
unsigned short int CountSinxrWord1;
unsigned int CountSboiWord;          // Кол-во сбойных слов в потоке
unsigned int CountSboiKadr;          // Кол-во сбоев счетчика кадров в потоке
unsigned short int CountSinxrWord2;
bool SinxrWordsSearch;
unsigned short int KFrame;           //Кол-во циклов в кадре
unsigned short int NumberFrame;      // Текущий номер цикла
int CountKadr;            //счетчик кадров в файле
int KondihKadr;
int SboiKadr;
//unsigned int AdresSboi[KSboiMax];
short int NumberSboi;
};
//-------------------------------------

struct Gamma
{
unsigned short int *AdresKadr;          // Указатель на буфер входного кадра
bool PriznakPotoka;            //0-false-поток отсутствует, 1-true-присутствует
unsigned short int Kadr;          //признак начала кадра
unsigned short int Kadr0;          //=1 найдено начало первого кадра
unsigned short int LKadr;
unsigned short int LFrame;
               int Inform;         // Информативность в словах
         short int KKadr;          // Кол-во кадров в сек
unsigned short int NumberWord;      //текущее кол-во слов в цикле
unsigned short int NumberWordKadr;  //текущее кол-во слов в кадре
unsigned short int CountSinxrWord1;
unsigned int CountSboiWord;          // Кол-во сбойных слов в потоке
unsigned int CountSboiKadr;          // Кол-во сбоев счетчика кадров в потоке
unsigned short int CountSinxrWord2;
bool SinxrWordsSearch;
unsigned short int KFrame;           //Кол-во циклов в кадре
unsigned short int NumberFrame;      // Текущий номер цикла
int CountKadr;            //счетчик кадров в файле
int KondihKadr;
int SboiKadr;
//unsigned int AdresSboi[KSboiMax];
short int NumberSboi;
};
#define KPOTOKARING 64
#define KPOTOKIRIG 2
#define LKADRARING  256
struct AringTest
{
unsigned short int *AdresKadr; // Указатель на буфер входного кадра
int *AdresCount;      // Адрес счетчиков информативности параметров
bool PriznakPotoka;            //0-false-поток отсутствует, 1-true-присутствует
unsigned short int NumberWord;      //текущее кол-во слов в цикле
unsigned int CountSboiWord;          // Кол-во сбойных слов в потоке
int CountWord;
int KondihKadr;
int SboiKadr;
unsigned short int AdresTek;         //Номер текушего адреса
};
struct TimeTest
{
bool PriznakPotoka;            //0-false-поток отсутствует, 1-true-присутствует
unsigned int TimeWord;          // Кол-во слов в потоке
unsigned int CountWord;
unsigned int KondihKadr;
unsigned int SboiKadr;
};
// Структура  48-разрядного слова времени
//=======================================

/*
struct  TimDehifr
        {
        unsigned int TInt :32;
        unsigned int Rez   :12;
        unsigned int Rez1   :1;
        unsigned int Tip   :3;
        };
*/
struct  TimDehifr
        {
        unsigned int TInt :32;
        unsigned int Faza :12;
        unsigned int Tip   :4;
        };
/*struct StBit1
     {
      unsigned int maker :3;
      unsigned int adres :21;
      unsigned int  :8;
     };

struct StBit2Gamma
     {
      unsigned int  :8;
      unsigned int ml :12;
      unsigned int st :12;
     };
struct StBit2
     {
      unsigned int  :8;
      unsigned int kod :24;
     }; */
extern PACKAGE struct FlagPotokVizual *PtrFlagPotokVizual;
extern PACKAGE struct WinSistTab *PtrWinSistTab;
extern PACKAGE struct Test *PtrTest;
extern PACKAGE struct SisTable *PtrSisTable; // Структура Системной таблицы
//extern PACKAGE struct Cbi       *PtrCbi;
//extern PACKAGE struct Table     *PtrTable;
extern PACKAGE struct TipPar    *PtrTipPar;
extern PACKAGE char  *PtrBlok_tar;    // блок тарировочных фрагментов
extern PACKAGE struct RK  *PtrBlokRK;       // блок описния разовых команд
extern PACKAGE struct DDK  *PtrBlokDDK;       // блок описния двоично-десятичных параметров
//extern PACKAGE unsigned short int  *PtrBlokArinc;    // блок позиций параметров типа  Arinc в Интеграторе
//extern PACKAGE unsigned short int  *PtrBlokIndex;    // блок позиций параметров типа  не Arinc в Интеграторе
//extern PACKAGE unsigned short int  *PtrBlokIndex;    // блок позиций параметров типа  не Arinc в Интеграторе
extern PACKAGE unsigned int  *PtrBlokIndex;    // блок позиций параметров типа  не Arinc в Интеграторе
extern PACKAGE struct Upr *PtrUpr;          // Управляющая талица
extern PACKAGE struct Potok *PtrPotok;
extern PACKAGE struct PotokS *PtrPotokS;
//extern PACKAGE struct Sistem *PtrSistem;
extern PACKAGE struct Razdel *PtrRazdel;
extern PACKAGE struct Pasp *PtrPasp;
extern PACKAGE struct Nakopitel *PtrNakopitel;
//extern PACKAGE struct Integrator  *PtrIntegrator;
//extern PACKAGE struct Potok  StructPotok,*PtrStructPotok;
extern PACKAGE struct Irig  StructIrig[2],*PtrStructIrig;
extern PACKAGE struct TimeTest  StructTimeTest,*PtrStructTimeTest;
extern PACKAGE struct Gamma  StructGamma,*PtrStructGamma;
extern PACKAGE struct AringTest  StructAringTest[KPOTOKARING],*PtrStructAringTest;
extern PACKAGE unsigned short int LTape[KGRMAX];
extern PACKAGE unsigned short  int MasGrFaz[KFAZMAX];
extern PACKAGE struct PotokBort  StructPotokBort,*PtrStructPotokBort;
extern PACKAGE unsigned short  int *BufIndexBufNPasp2;     // Буфер № паспортов   2010_05_20

//extern PACKAGE struct Ini       *PtrIni,*PtrIniOld;
#endif

