//---------------------------------------------------------------------------
#include <vcl.h>                    
#pragma hdrstop

#include "Main.h"

#include "Parametr.h"
#include "ParametrRK.h"
#include "ParametrFiz.h"
#include "UnitSettings.h"
#include "UnitAbout.h"
#include "UnitFormRashet.h"
#include "FileClassRashetParam.h"
#include "LibraryFile.h"
#include "startLog.h"
#include "log.h"

#include <stdio.h>
#include <dir.h>
#include <stdlib.h>
#include <shellapi.hpp>
#include <typeinfo.h>
#include "TeeAbout.hpp"
#include "teestore.hpp"
#include <string>
#include <math.h>
#include "teeprevi.hpp"
#include "Teengine.hpp"                                  
#include <iostream.h>
#include <fstream.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TeeComma"
#pragma link "TeeScroB"
#pragma link "TeeChartGrid"
#pragma link "TeePageNumTool"
#pragma link "TeeTools"
#pragma link "CSPIN"
#pragma link "TeeEdit"
#pragma link "TeeChartActions"
#pragma link "CGAUGES"
#pragma link "TeeOpenGL"
#pragma resource "*.dfm"
 TForm1 *Form1;

 typedef std::list<Parametr*>::iterator list_it;
 const double SEC = 1/86400.;  //  1/86400 часть суток равная 1 сек

 struct IndexBlocFileDatXX IndexBlocFileDatXX; // Хромцов 2013_07)15
 struct Razdel *PtrRazdel;                     // Хромцов 2013_07)15
 struct PaspChart *PtrPaspChart;               // Хромцов 2013_07)15
 struct RKChart *PtrRKChart;                   //  2013_10_11
 struct ParamXX *PtrParamXXChart;              //  2013_10_11
 struct GlobalFlagChart GlobalFlagChart, *PtrGlobalFlagChart;   // Хромцов 2013_07_15


//==============================================================================
//                 Конструктор главной формы
//==============================================================================
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
        , currentKadr(0)
        , no_value(3.3E+38)
        , isPaint(0)
 {
 Log::instance().Write("Record of log is started");
 mainChart = new myChart(ScrollBox1, StringGrid1, PopupMenu1, PopupMenuAxis);
 TeeCommander1->Panel  = mainChart->getChart();
 timeBar = new TimeBar(Panel1, mainChart);

 char tmp[255];
 GetCurrentDirectory(255, tmp);
 SourceDir = tmp;

 // create directories
 if ( !DirectoryExists(SourceDir + "\\Режимы\\") );
     CreateDir(SourceDir + "\\Режимы\\");
 if ( !DirectoryExists(SourceDir + "\\INI\\") );
     CreateDir(SourceDir + "\\INI\\");
 if ( !DirectoryExists(SourceDir + "\\Temp\\") );
     CreateDir(SourceDir + "\\Temp\\");
 if ( !DirectoryExists(SourceDir + "\\Log\\") );
     CreateDir(SourceDir + "\\Log\\");
 FileListBox1->Directory = SourceDir + "\\Режимы\\";

 PtrGlobalFlagChart = &GlobalFlagChart;
 WindowState = wsMaximized;

 // iniFiles
 iniFileMain = new TIniFile(SourceDir + "\\Chart.ini");
 AnsiString iniFileNameAny = iniFileMain->ReadString("Files", "LastFileIni", "");

 if(FileExists(iniFileNameAny))
 {
     iniFile = new CustomIniFile(iniFileNameAny);
     if(iniFile->fileError)
     {
         mainChart->chartInit();
         AddTab(SourceDir + "\\Temp\\Вкладка_1.tee");
     }
     else
     {
         LoadFlyingFile(iniFile->DataFile);
         OpenFormat(iniFile->Format);
     }
 }
 // use default ini file
 else
 {
     AnsiString iniFileDefault = SourceDir + "\\INI\\iniFileDefault.ini";
     if(! FileExists(iniFileDefault))
     {
         FILE* F;
         if((F = fopen(iniFileDefault.c_str(), "w+")) == NULL)
         {
             ShowMessage("Невозможно создать файл настройки по умолчанию. Запустите программу от имени Администратора или обратитесь к разработчику");
             fclose(F);
             Application->Terminate();
         }
         fclose(F);
     }
     iniFile = new CustomIniFile(iniFileDefault);
     mainChart->chartInit();
     // if this file is already exsist, load exsisting file (not empty form)
     AddTab(SourceDir + "\\Temp\\Вкладка_1.tee");
 }
}


//==============================================================================
//           LoadFlyingFile
//==============================================================================
void TForm1::LoadFlyingFile(const AnsiString& PathToFlyingFile)
{
 FlyingFile::Instance().initFlyingFile(PathToFlyingFile);
 iniFile->DataFile = PathToFlyingFile;
 mainChart->setMinMaxIncrementBottomAxis(FlyingFile::Instance().getSourceMinTime(),
                                         FlyingFile::Instance().getSourceMaxTime());
 Caption = "ChartPro   " + ExtractFileName(PathToFlyingFile);
 //timeBar->getMinMaxFullTime();
}


//==============================================================================
//             загрузить график из файлa
//==============================================================================
void __fastcall TForm1::buttonOpenChartClick(TObject *Sender)
{
 OpenDialogMode->InitialDir = iniFileMain->ReadString("Dir", "formatDir", "C:\\");
 OpenDialogMode->Title = "Выберите файл графического окна";
 if(OpenDialogMode->Execute())
    mainChart->openChartFromFile(OpenDialogMode->FileName);
 iniFileMain->WriteString("Dir", "formatDir", ExtractFileDir(OpenDialogMode->FileName));
 OpenDialogMode->Title = "Выберите файл режима";
}


//---------------------------------------------------------------------------
//           при передаче управления Form1                                           
//---------------------------------------------------------------------------
void __fastcall TForm1::FormActivate(TObject *Sender)
{
 stretch = 0;
 mainChart->getChart()->Repaint();
}

//---------------------------------------------------------------------------
//                      SpeedButton_Cut
//---------------------------------------------------------------------------
void __fastcall TForm1::buttonCutClick(TObject *Sender)
{
 mainChart->cutInterval();
}


//---------------------------------------------------------------------------
//                  SpeedButtonSaveChart
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButtonSaveChartClick(TObject *Sender)
{
 /*if(SaveDialogChart->Execute()){
    if(ReferLine)  DeleteReferLine();
    // здесь SaveSeriesTitle
    ChartToFile(SaveDialogChart->FileName, 0, 0);
    strcpy(Chart_Ini.pathToFormatka, SaveDialogChart->FileName.c_str());
    strcpy(Chart_Ini.pathToFormatka, SaveDialogChart->FileName.c_str());
    // здесь обратно LoatSeriesTitle
    for(int i=0; i<MKSERIES; i++){     // загружаем NSis
       if(Par[i] != NULL)
          Par[i]->LoatSeriesTitle();
    }
 } */
}


//--------------------------------------------------------------------------
//              загрузка форматки двойным щелчком по правой панели
//---------------------------------------------------------------------------
void __fastcall TForm1::FileListBox1DblClick(TObject *Sender)
{
 mainChart->openChartFromFile(FileListBox1->FileName);
}


//---------------------------------------------------------------------------
//               Изменение размера формы
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
 timeBar->ChartToTimeBar();
}


//---------------------------------------------------------------------------
//                      Добавить/удалить Визирную линию
//---------------------------------------------------------------------------
void __fastcall TForm1::buttonReperLineClick(TObject *Sender)
{
 if(buttonReperLine->Down){
    // установить начальное положение реперной линии
    mainChart->getChart()->Canvas->Pen->Color = clBlack;
    mainChart->getChart()->Canvas->MoveTo(mainChart->getChart()->BottomAxis->IStartPos + 20, mainChart->getChart()->LeftAxis->IStartPos);
    mainChart->getChart()->Canvas->LineTo(mainChart->getChart()->BottomAxis->IStartPos + 20, mainChart->getChart()->LeftAxis->IEndPos);
    mainChart->getChart()->Canvas->Pen->Mode = pmCopy;
    mainChart->getChart()->Canvas->Pen->Color = clWhite;
 }
 mainChart->getChart()->Refresh();
 mainChart->recognizeButton((TSpeedButton*)Sender, CheckBoxMouse->Checked);
}


//                      Открыть диалог выбора Шрифта
//---------------------------------------------------------------------------
void __fastcall TForm1::BottonFontClick(TObject *Sender)
{
 FontDialog1->Execute();
}


//--------------------------------------------------------------------
//               Идентификаторы в конце убрать/поставить
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBoxEndIdentClick(TObject *Sender)
{
 mainChart->getChart()->Repaint();
}


//---------------------------------------------------------------------------
//                 убрать   Min Max с осей
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButtonMoveMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 /*EditMax->Visible = false;
 EditMin->Visible = false;
 EditMax->Parent = Panel2;
 EditMin->Parent = Panel2;
 ButtonMinMaxOk->Parent = Panel2;
 ButtonMinMaxOk->Visible = false;  */
}


/*void __fastcall TForm1::EditKolVertLinesKeyPress(TObject *Sender, char &Key)
{
 Singleton::getInstance().OnlyNumbers(Key, 0);
}    */


/*void __fastcall TForm1::buttonZoomInClick(TObject *Sender)
{
 mainChart->getChart()->Refresh();
 mainChart->getChart()->Canvas->Pen->Color = clBlack;
}   */


//==============================================================================
//      CreateString
//==============================================================================
void __fastcall TForm1::ButtonCreateStringClick(TObject *Sender)
{
 mainChart->addLabel();
}


//==============================================================================
//  Action   OpenFlyingFile
//==============================================================================
void __fastcall TForm1::AOpenFlyingFileExecute(TObject *Sender)
{
 OpenDialogData->InitialDir = iniFileMain->ReadString("Dir", "dataDir", "C:\\");
 if(! OpenDialogData->Execute())
    return;
 LoadFlyingFile(OpenDialogData->FileName);

 iniFile->DataFile = OpenDialogData->FileName;
 iniFileMain->WriteString("Dir", "dataDir", ExtractFileDir(OpenDialogData->FileName));
 //mainChart->setMinMaxBottomAxis(dataFile.getSourceMinTime(), dataFile.getSourceMaxTime());
}


//---------------------------------------------------------------------------
//   Action   OpenINI
//---------------------------------------------------------------------------
void __fastcall TForm1::AOpenINIExecute(TObject *Sender)
{
 //OpenDialogIni->InitialDir = iniFile->iniDir;
 OpenDialogIni->InitialDir = iniFileMain->ReadString("Dir", "iniDir", "C:\\");
 if(! OpenDialogIni->Execute())
     return;

 //iniFile->iniDir = OpenDialogIni->
 //           FileName.SubString(0, LastDelimiter("\\", OpenDialogIni->FileName));
 iniFileMain->WriteString("Dir", "iniDir", ExtractFileDir(OpenDialogIni->FileName));

 iniFile->openIni(OpenDialogIni->FileName);
 if(iniFile->fileError)
     return;
 LoadFlyingFile(iniFile->DataFile);
 OpenFormat(iniFile->Format);
}


//---------------------------------------------------------------------------
//  Action   SaveINI
//---------------------------------------------------------------------------
void __fastcall TForm1::ASaveINIExecute(TObject *Sender)
{
 SaveINI();
}


//---------------------------------------------------------------------------
//     Action   SaveINI
//---------------------------------------------------------------------------
void __fastcall TForm1::ASaveAllExecute(TObject *Sender)
{
// SaveDialogIni->InitialDir = iniFile->iniDir;
 SaveDialogIni->InitialDir = iniFileMain->ReadString("Dir", "iniDir", "C:\\");
 if(! SaveDialogIni->Execute())
    return;

 //iniFile->iniDir = SaveDialogIni->
 //FileName.SubString(0, LastDelimiter("\\", SaveDialogIni->FileName));
 iniFileMain->WriteString("Dir", "iniDir", ExtractFileDir(SaveDialogIni->FileName));

 iniFile->saveIniAs(SaveDialogIni->FileName);
}


//---------------------------------------------------------------------------
//  Action   SaveINIAs
//---------------------------------------------------------------------------
void __fastcall TForm1::ASaveINIAsExecute(TObject *Sender)
{
 //SaveDialogIni->InitialDir = iniFile->iniDir;
 SaveDialogIni->InitialDir = iniFileMain->ReadString("Dir", "iniDir", "C:\\");
 if(! SaveDialogIni->Execute())
    return;

 //iniFile->iniDir = SaveDialogIni->
 //           FileName.SubString(0, LastDelimiter("\\", SaveDialogIni->FileName));
 iniFileMain->WriteString("Dir", "iniDir", ExtractFileDir(SaveDialogIni->FileName));
 
 iniFile->saveIniAs(SaveDialogIni->FileName);
 iniFileMain->WriteString("Files", "LastFileIni", iniFile->iniFileName);
}

//----------------------------------------------------------------------------
//                   SaveINI
//----------------------------------------------------------------------------
void TForm1::SaveINI()
{
 //SaveDialogIni->InitialDir = iniFile->iniDir;
 SaveDialogIni->InitialDir = iniFileMain->ReadString("Dir", "iniDir", "C:\\");
 if(! FileExists(iniFile->iniFileName)){        // если на данный момент не выбрана настройка,
    if(! SaveDialogIni->Execute())
        return;

    //iniFile->iniDir = SaveDialogIni->
    //FileName.SubString(0, LastDelimiter("\\", SaveDialogIni->FileName));
    iniFileMain->WriteString("Dir", "iniDir", ExtractFileDir(SaveDialogIni->FileName));
    iniFile->iniFileName = SaveDialogIni->FileName;
 }

 if(! SaveDialogIni->Execute())
    return;

 //iniFile->iniDir = SaveDialogIni->
 //FileName.SubString(0, LastDelimiter("\\", SaveDialogIni->FileName));
 iniFileMain->WriteString("Dir", "iniDir", ExtractFileDir(SaveDialogIni->FileName));
 iniFile->saveIniAs(SaveDialogIni->FileName);
}


//---------------------------------------------------------------------------
//  Action   Print
//---------------------------------------------------------------------------
void __fastcall TForm1::ChartActionPrint1Execute(TObject *Sender)
{
 int FontPixelPerInch = mainChart->getChart()->Canvas->Font->PixelsPerInch;
 int FontSize = mainChart->getChart()->Canvas->Font->Size;
 int FontHeight = mainChart->getChart()->Canvas->Font->Height;

 printing = true;
 mainChart->getChart()->Canvas->Font->Name = "Times New Roman";
 mainChart->getChart()->Canvas->Font->PixelsPerInch = (Edit2->Text).ToInt();
 mainChart->getChart()->Canvas->Font->Size = (Edit5->Text).ToInt();
 mainChart->getChart()->Canvas->Font->Height = (Edit7->Text).ToInt();

 TeePreview(Form1, mainChart->getChart());
 printing = false;

 mainChart->getChart()->Canvas->Font->PixelsPerInch = FontPixelPerInch;
 mainChart->getChart()->Canvas->Font->Size = FontSize;
 mainChart->getChart()->Canvas->Font->Height = FontHeight;
}


//---------------------------------------------------------------------------
//  Action   Info
//---------------------------------------------------------------------------
void __fastcall TForm1::AInfoExecute(TObject *Sender)
{
 openSettingsPage(INFO_PAGE);
}


//---------------------------------------------------------------------------
//                  Play
//---------------------------------------------------------------------------
void __fastcall TForm1::buttonSlowBuiltClick(TObject *Sender)
{
 Build();
}


void TForm1::EndBuild()
{
 mainChart->labelInfoOff();
 building = false;
 buttonSlowBuilt->Enabled = true;
 buttonFastBuilt->Enabled = true;
 TabControl1->Enabled = true;
 CloseHandle(FlyingFile::Instance().getHandleFile());
};

void TForm1::InitBuild()
{
 TabControl1->Enabled = false;
 buttonSlowBuilt->Enabled = false;
 buttonFastBuilt->Enabled = false;
 building = true;
 mainChart->labelInfoOn();
}

//==============================================================================
//           Build
//==============================================================================
void TForm1::Build()
{
 clock_t startTime = clock();
 int start = 0, end = 0;         // start time and end time in count sec from 00:00:00
 int top = 0;
 int count = 0;

 InitBuild();

 // Установка Min,Max BottomAxis для интервала времени
 if(CheckBoxWithTime->Checked)
 {
    start = TimeToInt(EditStartTime->Text);     // начальное время интервала в кол-ве секунд с 00:00:00
    end   = TimeToInt(EditEndTime->Text);       // hh:mm:ss
    if(start == -1 || end == -1)
    {
       ShowMessage("Неправильно задан формат времени. Необходимо чч:мм:сс");
       EndBuild();
       return;
    }
    mainChart->getChart()->BottomAxis->SetMinMax(start * SEC, end * SEC);
 }
 else{
    start = mainChart->getChart()->BottomAxis->Minimum / SEC + 1;
    end = mainChart->getChart()->BottomAxis->Maximum / SEC;
 }
 timeBar->ChartToTimeBar();

 // open flying file
 fclose(FlyingFile::Instance().getStrData());
 FlyingFile::Instance().setHandleFile( CreateFile(iniFile->DataFile.c_str(), GENERIC_READ, 0,
                              NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL) );
 if(FlyingFile::Instance().getHandleFile() == NULL)
 {
     ShowMessage("Не удалось открыть полетный файл. Обратитесь к разработчику.");
     EndBuild();
     return;
 }

 // кол-во структур быстрого поиска = 86400 = кол-во сек в сутках
 int n = FlyingFile::Instance().getIndexBlocFileDatXX().LGif / sizeof(struct Gif);
 struct Gif *gifBuff = new struct Gif[n];

 DWORD bytefact;             // typedef unsigned long DWORD - число прочитанных байтов
 LARGE_INTEGER FilePoz;

 // int Позиция в файле(в байтах) начала структур Gif
 FilePoz.QuadPart = FlyingFile::Instance().getIndexBlocFileDatXX().IndexStructGif;
 SetFilePointer(FlyingFile::Instance().getHandleFile(), FilePoz.LowPart, &FilePoz.HighPart, FILE_BEGIN);
 ReadFile(FlyingFile::Instance().getHandleFile(), gifBuff, sizeof(struct Gif) * n, &bytefact, 0);

 bool find = false;
 for(int i = 0; i < n; ++i)
 {
    if(gifBuff[i].Time == start)
    {
       FilePoz.LowPart = gifBuff[i].Poz;
       FilePoz.HighPart = gifBuff[i].TimeHAE;
       SetFilePointer(FlyingFile::Instance().getHandleFile(), FilePoz.LowPart, &FilePoz.HighPart, FILE_BEGIN);
       find = true;
       break;
    }
 }
 if(! find)
 {
    ShowMessage("Начальное время не найдено! Обратитесь к разработчику.");
    EndBuild();
    return;
 }
 delete[] gifBuff;

 // for stop-build
 GetAsyncKeyState('Q');

 HANDLE hFlyingFile = FlyingFile::Instance().getHandleFile();
 size_t sizeTimXX = sizeof(struct TimXX);
 size_t sizeParamXXChart = sizeof(struct ParamXXChart);

 struct TimXX timXX;
 struct ParamXXChart *ptrParamXXChartTek = NULL;
 char *buf = new char[6 * 1000];     // sizeof(ParamXXXhart) = 6, 1000 - Максимально возможное кол-во параметров в фазе
 for(;;)
 {
    ReadFile(hFlyingFile, &timXX, sizeTimXX, &bytefact, 0);
    if(bytefact == 0) break;
    //========= read   TimXX.LFaz     TimXX.TInt  ======
    int sizeOfTInt = sizeof(timXX.TInt);
    int lFaz = timXX.LFaz;
    int kolParInFaza = (timXX.LFaz - sizeof(timXX.TInt)) / sizeParamXXChart;

    top = timXX.TInt / 1000;                                   // время фазы в мс
    if(top == end)
       break;

    //int div = top % 3600;
    int hh = top / 3600;
    top -= hh*3600;
    int mm = top / 60;
    top -= mm*60;
    int ss = top / 60;
    int ms = top - ss;

    //int ss = div % 60 / 1000;
    //int ms = div % 60 % 1000;
    double Yt = EncodeTime(hh, mm, ss, ms);
    //==================================================

    ReadFile(hFlyingFile, buf, sizeParamXXChart * kolParInFaza, &bytefact, 0);
    if(bytefact == 0)
       break;
    ptrParamXXChartTek = (struct ParamXXChart*)buf;

    int rk = 0, nPaspTek = 0, nSysTek = 0;
    for(int j = 0; j < kolParInFaza; ++j)
    {
       for(list_it i = mainChart->mainList.begin(), e = mainChart->mainList.end(); i != e; ++i)
       {
           if(ptrParamXXChartTek->NPasp == (*i)->NPasp && ptrParamXXChartTek->NSisNClov == (*i)->NSis )
           {
               if( (*i)->GetTagSeries() )  // RK
               {
                  if(rk = ((ptrParamXXChartTek->KodFizika.L) >> ((ParameterRK*)&i)->NRK-9) & 1)
                     (*i)->SeriesAdd(Yt, rk);
               }
               else
                  (*i)->SeriesAdd(Yt, ptrParamXXChartTek->KodFizika.F);
           }
       }
       ++ptrParamXXChartTek;
    }
    // Для визуализации построения графиков
    if(! (count % 50000))
        Application->ProcessMessages();
    ++count;

    // при нажатии на кнопку Q процесс построения останавливается
    if ((GetAsyncKeyState(int('Q')) & 1) != 0 || !building)
         break;
 }
 delete[] buf;
 EndBuild();

 //enum build = SLOW_BUILD
 mainChart->build = 1;
 timeBar->setCaptionCenterPanel((clock() - startTime)/CLOCKS_PER_SEC);
}


void __fastcall TForm1::buttonFastBuiltClick(TObject *Sender)
{
 FastBuild();
}


//---------------------------------------------------------------------------
//   Построение короткого файла
//---------------------------------------------------------------------------
void TForm1::FastBuild()
{
 building = true;
 __int64 top = 0, top2 = 0;       // typedef __int64 LONGLONG

 struct MinMax *PtrMinMax, *PtrMinMaxTek;
 struct TimXX TimXX;

 fclose(FlyingFile::Instance().getStrData());   // TODO always close file (in another places)
 FILE* f = FlyingFile::Instance().getStrData();
 f = fopen(iniFile->DataFile.c_str(), "rb");

 if(FlyingFile::Instance().getStrData() == NULL) return;
 fseek(FlyingFile::Instance().getStrData(), FlyingFile::Instance().getIndexBlocFileDatXX().IndexBeginPackData, SEEK_SET);
 PtrMinMax = new struct MinMax[KSISTEM * FlyingFile::Instance().getKPasp()];

 // кол-во реальных секунд в упакованных данных
 for(int j = 0, kr = FlyingFile::Instance().getIndexBlocFileDatXX().KRealSecPackData; j < kr; ++j)
 {
     fread(&TimXX.TInt, sizeof(__int64), 1, FlyingFile::Instance().getStrData());
     fread(PtrMinMax, sizeof(struct MinMax),
            KSISTEM * FlyingFile::Instance().getKPasp(), FlyingFile::Instance().getStrData());

     top = TimXX.TInt;
     top2 = top + FlyingFile::Instance().getIndexBlocFileDatXX().KSecPiksel * 1000/2;

     double Yt = EncodeTime(top/3600000, (top%3600000)/60000,
                          (top%3600000)%60000/1000, (top%3600000)%60000%1000);
     double Yt2 = EncodeTime(top2/3600000, (top2%3600000)/60000,
                           (top2%3600000)%60000/1000, (top2%3600000)%60000%1000);

     for(list_it i = mainChart->mainList.begin(), e = mainChart->mainList.end(); i != e; ++i)
     {
         PtrMinMaxTek = PtrMinMax + ((*i)->NSis - 1) * FlyingFile::Instance().getKPasp() + (*i)->NPasp;
         if(PtrMinMaxTek->Max.F > no_value || PtrMinMaxTek->Max.F < -no_value ||
            PtrMinMaxTek->Min.F > no_value || PtrMinMaxTek->Min.F < -no_value)
            continue;
         (*i)->SeriesAdd(Yt, PtrMinMaxTek->Max.F);
         (*i)->SeriesAdd(Yt2, PtrMinMaxTek->Min.F);
     }
 }

 fclose(FlyingFile::Instance().getStrData());
 delete[] PtrMinMax;
 PtrMinMax = NULL;


 mainChart->build = 2;

 //---- для интервала времени
 if(CheckBoxWithTime->Checked)
 {
    int start = TimeToInt(EditStartTime->Text);     // начальное время интервала
    int end   = TimeToInt(EditEndTime->Text);       // hh:mm:ss
    if(end == -1 || start == -1)
    {
       ShowMessage("Неправильно задан формат времени. Необходимо чч:мм:сс");
       return;
    }
    mainChart->setMinMaxIncrementBottomAxis(start, end);
 }
 building = false;
}


//==============================================================================
//   нажатие кнопок меню
//==============================================================================
void __fastcall TForm1::MEditClick(TObject *Sender)
{
 ToolBar1->Visible = false;
 Panel2->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MmanagementClick(TObject *Sender)
{
 ToolBar1->Visible = true;
 Panel2->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::NAboutClick(TObject *Sender)
{
 FormAbout->ShowModal();
}






 //---- МАРКЕРЫ
 /* вариант 1
 /* выводить на канву текст( букву) шрифтом Wingdings
 /* проблемы: настройка перед печатью, обновление канвы каждый раз после перерисовки */
 /*int a = Par[1]->Series->Count()/5;
 mainChart->getChart()->Canvas->Font->Name = "webdings";
 mainChart->getChart()->Canvas->Font->Color = Par[1]->Series->Color;
 mainChart->getChart()->Canvas->Font->Size = mainChart->getChart()->Canvas->Font->Size + 10;
 for(int i=0; i<5; i++)
   mainChart->getChart()->Canvas->TextOut(Par[1]->Series->CalcXPos(i*a+1), Par[1]->Series->CalcYPos(i*a+1), "a");       */


 // вариант 2
 /* ставить рисунки, которые содержатся в папке */
 /*Par[1]->Series->Marks->DrawEvery = 40000;
 Par[1]->Series->Marks->Visible = true;
 Par[1]->Series->Marks->Style = smsSeriesTitle;
 Par[1]->Series->Marks->Picture->LoadFromFile("Path");    */

void __fastcall TForm1::N6Click(TObject *Sender)       // 2013_07_15    Хромцов   Создать или Редактировать файл расчетных параметров
{
int i;
 ToolBar1->Visible = false;
 Panel2->Visible = false;
 FormRashet->Memo1->Visible = false;
// NameFileRashetTxt = "123";
// i=NameFileRashetTxt.AnsiPos("\0");
 i=NameFileRashetTxt.AnsiCompare("\0");
 if(i != 0)   FormRashet->Memo1->Lines->LoadFromFile(NameFileRashetTxt);
 else FormRashet->Memo1->Clear();
 FormRashet->Memo1->Visible = true;
 FormRashet->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N7Click(TObject *Sender)       // 2013_07_15    Хромцов  Подключить  расчетные параметры
{
int ret;
// TStringList *TextFile;
// TextFile = new  TStringList();

  if(OpenDialogFileRashet->Execute())
  {
//  if(NameFileRashetTxt[1] != '\0') NameFileRashetTxt[1] = '\0';
  FormRashet->Memo1->Visible = false;
  NameFileRashetTxt = OpenDialogFileRashet->FileName;
//  FormRashet->Memo1->Lines->LoadFromFile(NameFileRashetTxt);
  if(PtrClassRashetParam != NULL) { delete PtrClassRashetParam; PtrClassRashetParam = NULL; }
  PtrClassRashetParam = new ClassRashetParam(NameFileRashetTxt);
   //  Анализ текстового файла расчетных параметров,
   //  Создание символьного файла библиотеки DLL,
   //  Компиляция, создание библиотеки DLL,

 //ret = FunLibrery(PtrGlobalFlagChart->NameDllRashetLibrary);  //  Подключение библиотеки
 FunLibrery(PtrGlobalFlagChart->NameDllRashetLibrary);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N8Click(TObject *Sender)      // 2013_07_15    Хромцов   Отключить расчетные параметры
{
NameFileRashetTxt = '\0';
   // Отключить  библиотеку
}

//---------------------------------------------------------------------------
TForm1::FunLibrery(char Name[])           // Хромцов 2013_07_15
{
int ret;
char txt[256];

 if(PtrGlobalFlagChart->RashetLibrary == true ) { FunLibraryDeInitOutGlobalValue(); FunCloseLibrary(); }
 ret = FunOpenLibrary(Name);  // 2007_09_18
  if(ret == -1)
 {
  strcpy(txt,"Файл библиотеки  "); strcat(txt,Name);
  strcat(txt,"   не найден");
  MessageBox(NULL,txt,"Info",MB_ICONINFORMATION);
  PtrGlobalFlagChart->RashetLibrary = false;
  PtrGlobalFlagChart->NameDllRashetLibrary[0] = '\0';
  return(-1);
 }
  FunLibraryInitOutGlobalValue();
  PtrGlobalFlagChart->RashetLibrary = true;
//  ret = OpenBaza(PtrFlagPotokVizual->FileNameBaza,0);                              // Необходимо доработать подсоединение расчетных паспортов
// if(ret != 0) { FunLibraryDeInitOutGlobalValue();    FunCloseLibrary(); return(-1);}
// InitAdresAPISistemStruct((void *)PtrFlagPotokVizual,(void *)PtrWinSistTab,(void *)PtrSisTable,(void *)PtrPasp,(void *)PtrPotok,
// (void *)PtrTipPar,(void *)PtrBlokRK);
 InitAdresAPIInp();
  if( PriznakNoParDll == true)
   {
//   MessageBox(NULL,BufParNo,"Входные Параметры библиотеки ",MB_ICONINFORMATION);     // ДОРАБОТАТЬ   ????????????????????????????????
//   delete[] BufParNo; BufParNo = NULL; PriznakNoParDll = false;                      // ДОРАБОТАТЬ   ????????????????????????????????
   FunLibraryDeInitOutGlobalValue();    FunCloseLibrary();
   PtrGlobalFlagChart->RashetLibrary = false;
   return(-1);
   }
 return(0);
}  // Хромцов 2013_07_15


//--------------------------------------------------------------------------
//    Button 100%
//--------------------------------------------------------------------------
void __fastcall TForm1::buttonFullTimeClick(TObject *Sender)
{
 if(buttonZoomIn->Down){
     mainChart->getChart()->Align = alClient;
     return;
 }
 mainChart->setMinMaxIncrementBottomAxis(FlyingFile::Instance().getSourceMinTime(),
                                         FlyingFile::Instance().getSourceMaxTime());
 timeBar->ChartToTimeBar();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::buttonLinkingGridClick(TObject *Sender)
{
 for(list_it i = mainChart->mainList.begin(), e = mainChart->mainList.end(); i != e; ++i)
    mainChart->LinkToGrid((*i)->Axis);
}


//---------------------------------------------------------------------------
//   Открытие окна для ввода диапазона
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBoxWithTimeClick(TObject *Sender)
{
 if(CheckBoxWithTime->Checked)
    while(Panel10->Width < 394)
       ++Panel10->Width;
 else{
    while(Panel10->Width > 71)
       --Panel10->Width;
    return;
 }
 // заполнение окон диапазона
 if(TimeToInt(EditStartTime->Text) == -1 || TimeToInt(EditEndTime->Text) == -1){
    EditStartTime->Text = EncodeTime(FlyingFile::Instance().getSourceMinTime() / 3600,
                  (FlyingFile::Instance().getSourceMinTime() % 3600) / 60, (FlyingFile::Instance().getSourceMinTime() % 3600) % 60, 0);
    EditEndTime->Text = EncodeTime(FlyingFile::Instance().getSourceMaxTime() / 3600,
                  (FlyingFile::Instance().getSourceMaxTime() % 3600) / 60, (FlyingFile::Instance().getSourceMaxTime() % 3600) % 60, 0);
    deltaTimeEdit->Text = TimeToInt(EditEndTime->Text) - TimeToInt(EditStartTime->Text);
 }
}


//---------------------------------------------------------------------------
//    Удаление содержимого папки Temp
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
 //SaveCurrentTab(SourceDir + "\\Temp\\");

 AnsiString dirName = SourceDir + "\\Temp\\";
 TSearchRec sr;

 if ( !FindFirst(dirName + "\\*.*", faAnyFile, sr)){
    do{
       if (!(sr.Name=="." || sr.Name=="..")){           // это не удаляем
          FileSetAttr(dirName + "\\" + sr.Name, 0);
          DeleteFile(dirName + "\\" + sr.Name);         // удаляем файл
       }
    }
    while ( !FindNext(sr));                     
 }
 FindClose(sr);
 DeleteFile((SourceDir + "//INI//iniFileDefault.ini").c_str());
}


//--------------------------------------------------------------------------
//       Кнопка Выбор цвета
//--------------------------------------------------------------------------
void __fastcall TForm1::buttonColorClick(TObject *Sender)
{
 if(buttonColor->Down ){
  while(PanelColor->Width < 74)
     ++PanelColor->Width;
 }
 else{
  while(PanelColor->Width > 33)
     --PanelColor->Width;
 }
}

//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBoxLineWidthClick(TObject *Sender)
{
 SpeedButtonMove->Down = false;
 SpeedButtonMaxMin->Down = false;
 SpeedButtonAddInc->Down = false;
 SpeedButtonStretch->Down = false;
 SpeedButtonDelete->Down = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ComboBoxLineWidthBeginEdit(TObject *Sender)
{
 TComboBoxEx* box = dynamic_cast<TComboBoxEx*>(Sender);
 box->Color = clWhite;
}
//---------------------------------------------------------------------------


//==============================================================================
//  Удаление текущей вкладки
//==============================================================================
void __fastcall TForm1::NDeleteTabClick(TObject *Sender)
{
 DeleteCurrentTab(0);
}


//==============================================================================
//     SaveFormatAs...               Menu
//==============================================================================
void __fastcall TForm1::NFormatSaveAsClick(TObject *Sender)
{
 SaveCurrentTab(SourceDir + "\\Temp\\");
 SaveFormatAs();
 // SaveFormatAs -> SaveCurrentTab -> (*i)->SaveSeriesTitle
 // Title заполнен атрибутами NSis MarkerSymbol NStructRK afterComma visible
 // необходимо очистить Title
 for(list_it i = mainChart->mainList.begin(); i != mainChart->mainList.end(); ++i)
     (*i)->LoadSeriesTitle();

 //http://forum.vingrad.ru/forum/topic-269512.html#st_15_view_0
 //сохранение в один файл
}


//==============================================================================
//      NewFormat
//==============================================================================
void TForm1::NewFormat()
{
 String path = SourceDir + "\\Temp\\Новая_вкладка.fmt";
 FILE* fout = fopen(path.c_str(), "w");

 if(fout){
     String dirName = SourceDir + "\\Temp\\Новая_вкладка\\";
     CreateDir(dirName);
     fprintf(fout, "%s", dirName.c_str());

     iniFile->Format = path;
     fclose(fout);
 }
}


//==============================================================================
//     OpenFormat Menu
//==============================================================================
void __fastcall TForm1::NFormatOpenClick(TObject *Sender)
{
 OpenDialogFormat->InitialDir = iniFileMain->ReadString("Dir", "formatDir", "C:\\");
 if(! OpenDialogFormat->Execute())  return;

 mainChart->deleteAllParametrs();

 while(TabControl1->Tabs->Count)
    TabControl1->Tabs->Delete(0);

 String path = OpenDialogFormat->FileName;
 path = path.SubString(1, path.Length() - 4) + "\\";        // path.fmt -> path переход с .fmt к //

 //iniFile->formatDir = OpenDialogFormat->FileName.SubString(0, LastDelimiter("\\", OpenDialogFormat->FileName));
 iniFileMain->WriteString("Dir", "formatDir", ExtractFileDir(OpenDialogFormat->FileName));

 OpenFormat(path);
 iniFile->Format = path;
}


//==============================================================================
//    OpenFormat
//==============================================================================
void TForm1::OpenFormat(const String& pathToFormatka)
{
 // existing file check
 String fileName = pathToFormatka.SubString(0, pathToFormatka.Length() - 1) + ".fmt";
 if( !FileExists(fileName))
 {
     ShowMessage("Файла формата \"" + fileName + "\" не существует");
     return;
 }

 // delete all tabs
 while(TabControl1->Tabs->Count)
    DeleteCurrentTab(1);

 //  C://...// *.tee  -  copy to  -  C://...//Temp//*.tee
 TSearchRec sr;
 if ( !FindFirst(pathToFormatka + "*.*", faAnyFile, sr))
 {
    do
    {
       if ( !(sr.Name=="." || sr.Name==".."))
       {
           CopyFile( (pathToFormatka + sr.Name).c_str(),
                     (SourceDir + "\\Temp\\" + sr.Name).c_str(), false);
           AddTab(SourceDir + "\\Temp\\" + sr.Name);
       }
    }
    while ( !FindNext(sr));     // ищем пока не найдем все
    FindClose(sr);
 }
}


//==============================================================================
//   SaveFormatAs
//==============================================================================
void TForm1::SaveFormatAs()
{
 SaveDialogFormat->InitialDir = iniFileMain->ReadString("Dir", "formatDir", "C:\\");
 if( !SaveDialogFormat->Execute()) return;
 iniFileMain->WriteString("Dir", "formatDir", ExtractFileDir(OpenDialogFormat->FileName));
 SaveFormat(SaveDialogFormat->FileName);
}


//---------------------------------------------------------------------------
//      SaveFormat
//---------------------------------------------------------------------------
void TForm1::SaveFormat(const String& nameFormatka)
{
 String dir = nameFormatka.SubString(1, nameFormatka.Length() - 4) + "\\";

 FILE* fout = fopen(nameFormatka.c_str(), "w");
 if(fout)
 {
     // удаление прежних файлов в папке
     if( DirectoryExists(dir) )
     {
         TSearchRec sr;
         if ( !FindFirst(dir + "*.*", faAnyFile, sr))
         {
             do
             {
                 if ( !(sr.Name=="." || sr.Name==".."))
                     DeleteFile(dir + sr.Name);
             }
             while ( !FindNext(sr));     // ищем пока не найдем все
         }
     }

     CreateDir(dir);
     fprintf(fout, "%s", dir.c_str());   // зачем в файл пишем путь?
     iniFile->Format = dir;

     // copy from Temp  ->  dirName
     TSearchRec sr;
     String tmpName = SourceDir + "\\Temp\\";
     if ( !FindFirst(tmpName + "\\*.*", faAnyFile, sr))
     {
         do
         {
             if (!(sr.Name=="." || sr.Name==".."))        // не копируем . & ..
                 CopyFile((tmpName + sr.Name).c_str(), (dir + sr.Name).c_str(), 0);
         }
         while ( !FindNext(sr));     // ищем пока не найдем все
     }
     FindClose(sr);
     ShowMessage("Сохранено в " + (String)iniFile->Format);
 }
 else
    ShowMessage("Не удалось сохранить форматку!(Файл не открыт " + nameFormatka + ")");
 fclose(fout);
}



//---------------------------------------------------------------------------
//                До переключения вкладки
//---------------------------------------------------------------------------
void __fastcall TForm1::TabControl1Changing(TObject *Sender,
      bool &AllowChange)
{
 // remove additional elements from chart
 if(building){
     mainChart->labelInfoOff();
     building = false;
 }

 mainChart->deleteMinMaxEdit();

 if(PanelRenameTab->Parent != Panel11){
     oldNameEdit->Visible = true;
     Label5->Visible = true;
     PanelRenameTab->Visible = false;
     PanelRenameTab->Parent = Panel11;
 }
 //--------------------------------------------
 // сохранение текущей вкладки в файл *.tee без данных в папку "Temp"
 // а если режим то сохраняем с данными в указанную в pathMode директорию
 /*bool find = false;
 int i = -1;
 for(i = 0; i < numMode.size(); ++i){
    if(numMode[i] == TabControl1->TabIndex){
       find = true;
       break;
    }
 }
 if(find)
    mainChart->ChartToFile(pathMode[i], 1, 0);
 else */

 SaveCurrentTab(SourceDir + "\\Temp\\");
 mainChart->deleteAllParametrs();
 mainChart->deleteAllLabels();
};


//---------------------------------------------------------------------------
//                TabControlChange        После переключения вкладки
//---------------------------------------------------------------------------
void __fastcall TForm1::TabControl1Change(TObject *Sender)
{
 // for mode
 /*for(unsigned i = 0; i < numMode.size(); ++i)
 {
    if(numMode[i] == TabControl1->TabIndex)
    {
       //OpenChartFromFile(pathMode[i]);
        mainChart->openChartFromFile(pathMode[i]);
       return;
    }
 }
 */

 // загрузить новую форматку -  она должна быть в папке Temp
 String name = SourceDir + "\\Temp\\" +
               TabControl1->Tabs->Strings[TabControl1->TabIndex] + ".tee";
 if( !FileExists(name))
     mainChart->deleteAllParametrs();
 else{
     mainChart->openChartFromFile(name);
     if(mainChart->build == 1) Build();
     if(mainChart->build == 2) FastBuild();
     mainChart->printParametrsTo(StringGrid1);
 }
};


//---------------------------------------------------------------------------
//     AddTab
//---------------------------------------------------------------------------
void TForm1::AddTab(const String& pathToTeeFile)
{
 // if tab is first
 if( !TabControl1->Tabs->Count)
 {
    mainChart->openChartFromFile(pathToTeeFile);
    // if form didn't paint
    if(mainChart->build == 1) Build();
    if(mainChart->build == 2) FastBuild();
    mainChart->printParametrsTo(StringGrid1);
 }
 String name = ExtractFileName(pathToTeeFile);
 TabControl1->Tabs->Add(name.SubString(1, name.Length() - 4)); // чтобы убрать .tee
}


//---------------------------------------------------------------------------
//     SaveCurrentTab
//---------------------------------------------------------------------------
void TForm1::SaveCurrentTab(const String& path)
{
 if(TabControl1->TabIndex < 0) return;
 String name = path + TabControl1->Tabs->Strings[TabControl1->TabIndex] + ".tee";
 mainChart->ChartToFile(name, 0, 1);
}


//---------------------------------------------------------------------------
//     DeleteCurrentTab
//---------------------------------------------------------------------------
void TForm1::DeleteCurrentTab(const bool loadAnotherChart)
{
 int newIndex = TabControl1->TabIndex - 1;
 if(newIndex < 0 || newIndex > TabControl1->Tabs->Count)
    newIndex = 0;

 DeleteFile(SourceDir + "\\Temp\\" +
                    TabControl1->Tabs->Strings[TabControl1->TabIndex] + ".tee");
 TabControl1->Tabs->Delete(TabControl1->TabIndex);

 mainChart->deleteAllParametrs();
 TabControl1->TabIndex = newIndex;

 if(loadAnotherChart)
    return;

 if( !TabControl1->Tabs->Count)
 {
     TabControl1->Tabs->Add("Новая_вкладка.tee");
     return;
 }
 String name = TabControl1->Tabs->Strings[newIndex];
 mainChart->openChartFromFile(SourceDir + "\\Temp\\" + name + ".tee");
}


//--------------------------------------------------------------------------- объединить с RepeatTabName
//      RenameTab                                                            т.к. используется всего один раз
//---------------------------------------------------------------------------
void TForm1::RenameTab(const String& name)
{
 int n = TabControl1->TabIndex;
 String oldName = TabControl1->Tabs->Strings[n];
 String newName = name;

 int c = RepeatTabName(name);
 if(c)
    newName = name + "(" + IntToStr(c) + ")";

 TabControl1->Tabs->Strings[n] = newName;
 RenameFile(SourceDir + "\\Temp\\" + oldName + ".tee",
            SourceDir + "\\Temp\\" + newName + ".tee");
}


//----------------------------------------------------------------------------  переделать!
//   потому что после двух вкладок функция не работает  name - name(1) - name(1)
//----------------------------------------------------------------------------
int TForm1::RepeatTabName(const String& name)
{
 TSearchRec sr;
 String fullName = name + ".tee";
 int n = 0;
 if ( !FindFirst(SourceDir + "\\Temp\\" + "\\*.*", faAnyFile, sr))
 {
    do
    {
       if (sr.Name == fullName)
          ++n;
    }
    while ( !FindNext(sr));
 }
 return n;
}

//---------------------------------------------------------------------------
//    RenameTabClick
//---------------------------------------------------------------------------
void __fastcall TForm1::NRenameTabClick(TObject *Sender)
{
 PanelRenameTab->Parent = mainChart->getChart();
 PanelRenameTab->Visible = true;
 PanelRenameTab->Top = 20;
 PanelRenameTab->Left = mainChart->getChart()->Width / 2;

 oldNameEdit->Text = TabControl1->Tabs->Strings[TabControl1->TabIndex];
 newNameEdit->Text = "новая_вкладка";
}

//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonOKRenameClick(TObject *Sender)
{
 // check name
 for(int i = 0; i < TabControl1->Tabs->Count; ++i)
     if(newNameEdit->Text == TabControl1->Tabs->Strings[i]){
         newNameEdit->Text = newNameEdit->Text + IntToStr(random(10));
         ShowMessage("Вкладка с таким именем уже существует. Придумайте другое имя");
         return;
     }

 // rename Tab
 if(oldNameEdit->Visible)
     RenameTab(newNameEdit->Text);
 else{    // new Tab
     TabControl1->Tabs->Add(newNameEdit->Text);
     // save current chart and delete all series and axis and text
     Form1->TabControl1->OnChanging(Sender, 0);
     // AutoChoose new Tab
     TabControl1->TabIndex = TabControl1->Tabs->IndexOf(newNameEdit->Text);
 }

 // close Panel
 oldNameEdit->Visible = true;
 Label5->Visible = true;
 PanelRenameTab->Visible = false;
 PanelRenameTab->Parent = Panel11;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonExitRenameClick(TObject *Sender)
{
 oldNameEdit->Visible = true;
 Label5->Visible = true;
 PanelRenameTab->Visible = false;
 PanelRenameTab->Parent = Panel11;
}


//---------------------------------------------------------------------------
//        Поменять вкладки местами
//---------------------------------------------------------------------------
void __fastcall TForm1::TabControl1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 if(Button == mbRight)
     TabControl1->PopupMenu = PopupMenuTab;
 else{
     X0=X;
     Y0=Y;
     TabControl1->BeginDrag(false, 5);
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TabControl1DragOver(TObject *Sender,
      TObject *Source, int X, int Y, TDragState State, bool &Accept)
{
  Accept = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TabControl1DragDrop(TObject *Sender,
      TObject *Source, int X, int Y)
{
 TabControl1->Tabs->Move(TabControl1->IndexOfTabAt(X0, Y0), TabControl1->IndexOfTabAt(X, Y));
}


//---------------------------------------------------------------------------
//   Открыть режим
//---------------------------------------------------------------------------
void __fastcall TForm1::NOpenRegimClick(TObject *Sender)
{
 OpenDialogMode->InitialDir = SourceDir + "\\Режимы\\";
 if(! OpenDialogMode->Execute())
    return;

 numMode.push_back(TabControl1->Tabs->Count);
 pathMode.push_back(OpenDialogMode->FileName);
 AddTab(OpenDialogMode->FileName);
}

//---------------------------------------------------------------------------
//    Сохранить режим как...
//---------------------------------------------------------------------------
void __fastcall TForm1::NSaveAsClick(TObject *Sender)
{
 SaveDialogMode->InitialDir = SourceDir + "\\Режимы\\";
 if(! SaveDialogMode->Execute())
    return;
 //ChartToFile(SaveDialogMode->FileName, 1, 0);
 mainChart->ChartToFile(SaveDialogMode->FileName, 1, 0);
}



void CutString(AnsiString** Mass, AnsiString& S, int i)
{
 int b = 0;                          // number of word
 int length = S.Length();
 while(length > 0)
 {
    int n = 1;
    while(AnsiString(S[n]) == " ")  // find first number symbol not NUll
    {
       n++;
       if(n >= length)
          return;
    }

    int s = n;                       // word started with symbol number n...
    while(AnsiString(S[s]) != " ")
    {
       s++;
       if(s >= length)
          break;
    }                                // ...and ended with symbol nymber s

    if( !i)
       Mass[b] = new AnsiString[50];

    Mass[b][i] = AnsiString(S.SubString(n, s-n));
    S = S.SubString(s, length);
    length = S.Length();
    b++;
 }
 return;
}

void testTxt(AnsiString** Mass)
{
 FILE* test;
 fopen("D:\Резервное_копирование\2014.02.04\_test.txt", "w+");
}


//----------------------------------------------------------------------------
//   Open Txt file                                                               !!! Work work work
//----------------------------------------------------------------------------
void __fastcall TForm1::NOpenTxtClick(TObject *Sender)
{
 OpenDialogTxt->Execute();
 
 char Buf[1024];
 AnsiString **strMass = new AnsiString*[50];

 FILE* file;
 file = fopen(OpenDialogTxt->FileName.c_str(), "r+");
 if(! file)
 {
     ShowMessage("Txt file isn't open");
     return;
 }

 AnsiString S;
 int c = 0;

 while(! feof(file))
 {
    if( fgets(Buf, 2048, file) == NULL )
    {
        ShowMessage("Can not read first string in text file " + OpenDialogTxt->FileName);
        return;
    }
    int poz = ftell(file);
    S = AnsiString(Buf);
    S = S.SubString(1, poz - 2);   // убираем символ \n
    CutString(strMass, S, c);
    ++c;
 }
}


//---------------------------------------------------------------------------
//    вопрос перед выходом из программы
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
 /* changeFlag = 0 т.е. изменений в форматке нет.
    Если 1. Нажали на ось(кликнули, передвинули)
         2. Вошли в настройки оси или поля
 */
 //if(!changeFlag)
 //    return;
 int res = Application->MessageBoxA(
                        "Сохранить форматку и настройку? \n \n"
                        "(Отмена - продолжение работы)",
                        "Подтвердите завершение работы",
                        MB_YESNOCANCEL + MB_ICONQUESTION);
 switch(res){
     case IDYES:
                  SaveAllSettings();
                  break;
     case IDCANCEL:
                  CanClose = false;
 }
}


//---------------------------------------------------------------------------
//   сохранение настроек, форматок
//---------------------------------------------------------------------------
void TForm1::SaveAllSettings()
{
 if(ExtractFileName(iniFile->iniFileName) == "iniFileDefault.ini"){
     // запуск диалога открытия ini-файлов
     //OpenDialogIni->InitialDir = iniFile->iniDir;
     OpenDialogIni->InitialDir = iniFileMain->ReadString("Dir", "iniDir", "C:\\");
     if( !OpenDialogIni->Execute())
         return;
     //iniFile->iniDir = SaveDialogIni->
     //      FileName.SubString(1, LastDelimiter("\\", SaveDialogIni->FileName));
     iniFileMain->WriteString("Dir", "iniDir", ExtractFileDir(SaveDialogIni->FileName));

     // сохраняем в файл ini    OpenDialogIni->FileName - становится текущим ini
     iniFile->saveIniAs(OpenDialogIni->FileName);
 }

 SaveCurrentTab(SourceDir + "\\Temp\\");
 if( !DirectoryExists(iniFile->Format))
     SaveFormatAs();
 else
     SaveFormat(iniFile->Format.SubString(1, iniFile->Format.Length() - 1) + ".fmt");

 iniFile->writeToIniFile();
 iniFileMain->WriteString("Files", "LastFileIni", iniFile->iniFileName);
}


//---------------------------------------------------------------------------
void __fastcall TForm1::NExitClick(TObject *Sender)
{
 Close();
}


void __fastcall TForm1::NnewTab2Click(TObject *Sender)
{
 PanelRenameTab->Parent = mainChart->getChart();
 PanelRenameTab->Visible = true;
 PanelRenameTab->Top = 20;
 PanelRenameTab->Left = mainChart->getChart()->Width / 2;

 newNameEdit->Text = "Новая вкладка";
 newNameEdit->SetFocus();
 oldNameEdit->Visible = false;
 Label5->Visible = false;
}


//------------------------------------------------------------------------------
//    пункты главного popup-меню
//------------------------------------------------------------------------------
void __fastcall TForm1::MParametrsClick(TObject *Sender)
{
 openSettingsPage(PARAMETER_PAGE);
}

void __fastcall TForm1::NMarginSettingsClick(TObject *Sender)
{
 openSettingsPage(CHART_PAGE);
}

void __fastcall TForm1::NFormatCurrentPropertiesClick(TObject *Sender)
{
 openSettingsPage(MAIN_PAGE);
}


//------------------------------------------------------------------------------
//   function  openSettingsPage
//------------------------------------------------------------------------------
void TForm1::openSettingsPage(int nPage)
{
 int min = mainChart->getChart()->BottomAxis->Minimum;
 int max = mainChart->getChart()->BottomAxis->Maximum;
 FormSettings->PageControl1->ActivePageIndex = nPage;
 SaveChartToFile(mainChart->getChart(), SourceDir + "\\~copybufferchart", 0, 0);
 // ShowModal return 1 when click OK on FormSettings, and return 2 when click Отмена
 if(FormSettings->ShowModal() == 1){
    mainChart->printParametrsTo(StringGrid1);
    if(buttonLinkingGrid->Down)
       for(list_it i = mainChart->mainList.begin(), e = mainChart->mainList.end(); i != e; ++i){
          mainChart->AxisNewPosition();
          mainChart->LinkToGrid((*i)->Axis);
       }
 }
}


//==============================================================================
//   пункты popup-меню шкалы
//==============================================================================
void __fastcall TForm1::SettingsClick(TObject *Sender)
{
 openSettingsPage(AXIS_PAGE);
}

void __fastcall TForm1::DeleteClick(TObject *Sender)
{
 mainChart->deleteParametr(mainChart->getCurrentParametr());
}
//--------------------------------------------------------------------------


void __fastcall TForm1::PageControl1Resize(TObject *Sender)
{
 StringGrid1->DefaultColWidth = StringGrid1->ClientWidth / 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
 startLogForm->ShowModal();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::forwardKadrButtonClick(TObject *Sender)
{
 int X = mainChart->getChart()->Series[0]->CalcXPosValue(mainChart->getChart()->BottomAxis->Minimum + currentKadr);
 currentKadr += SEC;

 mainChart->getChart()->Refresh();
 mainChart->getChart()->Canvas->Pen->Color = clBlack;
 mainChart->getChart()->Canvas->MoveTo(X, mainChart->getChart()->LeftAxis->IStartPos);
 mainChart->getChart()->Canvas->LineTo(X, mainChart->getChart()->LeftAxis->IEndPos);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::deltaTimeEditChange(TObject *Sender)
{
 if(deltaTimeEdit->Text == "")
     return;

 int delta = StrToInt(deltaTimeEdit->Text);
 if(delta < 0)
     delta = -delta;
 if( delta > (FlyingFile::Instance().getSourceMaxTime() - FlyingFile::Instance().getSourceMinTime()) )
     delta = FlyingFile::Instance().getSourceMaxTime() - FlyingFile::Instance().getSourceMinTime();

 int t0 = TimeToInt(EditStartTime->Text);
 int t1 = TimeToInt(EditEndTime->Text);
 if(t0 == -1 || t1 == -1)
     return;
 if(t0 < FlyingFile::Instance().getSourceMinTime() || t0 < FlyingFile::Instance().getSourceMinTime())
 {
     t0 = FlyingFile::Instance().getSourceMinTime();
     t1 = t0 + delta;
 }
 if(t0 > FlyingFile::Instance().getSourceMaxTime() || t1 > FlyingFile::Instance().getSourceMaxTime())
 {
     t1 = FlyingFile::Instance().getSourceMaxTime();
     t0 = t1 - delta;
 }
 if(t0 > t1)
     t1 = t0 + delta;

 double temp = IntToTime(t0 * 1000);
 EditStartTime->Text = ((TDateTime)temp).TimeString();
 temp = IntToTime(t0 * 1000 + delta * 1000);
 EditEndTime->Text = ((TDateTime)temp).TimeString();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::EditStartTimeKeyPress(TObject *Sender, char &Key)
{
 Set <Char, 0, 255> Dig;
 if(! (Dig << '0' << '1' << '2' << '3' << '4' << '5' << '6'
           << '7' << '8' << '9' << ':' <<'\b').Contains(Key))
 {Key = 0; Beep(); }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditEndTimeChange(TObject *Sender)
{
 if(EditEndTime->Text == "")
     return;
 int t0 = TimeToInt(EditStartTime->Text);
 int t1 = TimeToInt(EditEndTime->Text);
 if(t0 == -1 || EditStartTime->Text.Length() < 8)
     EditStartTime->Color = clBtnShadow;
 else
     EditStartTime->Color = clWhite;
 if(t1 == -1 || EditEndTime->Text.Length() < 8)
     EditEndTime->Color = clBtnShadow;
 else
     EditEndTime->Color = clWhite;
 if(t0 == -1 || t1 == -1 || EditStartTime->Text.Length() < 8 || EditEndTime->Text.Length() < 8)
     return;

 deltaTimeEdit->Text = t1 - t0;
}
//-----------------------------------------------------------------------


void __fastcall TForm1::buttonOpenFormatClick(TObject *Sender)
{
 //OpenDialogFormat->InitialDir = iniFile->formatDir;
 OpenDialogFormat->InitialDir = iniFileMain->ReadString("Dir", "formatDir", "C:\\");
 if(OpenDialogFormat->Execute())
     mainChart->openChartFromFile(OpenDialogFormat->FileName);
 iniFileMain->WriteString("Dir", "formatDir", ExtractFileDir(OpenDialogFormat->FileName));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton2Click(TObject *Sender) // SaveALL
{
 SaveAllSettings();
}

//---------------------------------------------------------------------------
int TForm1::getNFreeSeries()
{
 /*int сountEmptySeries = 0;
 for(list_it b = mainChart->mainList.begin(), e = mainChart->mainList.end(); b != e; ++i)
     if( !(*b)->Series->Count() )
         ++countEmptySeries;
 return countEmptySeries; */
 return 0;
}


void __fastcall TForm1::Button1Click(TObject *Sender)
{
 mainChart->printParametrsTo();
}



void __fastcall TForm1::SpeedButtonMaxMinClick(TObject *Sender)
{
 mainChart->recognizeButton((TSpeedButton*)Sender, CheckBoxMouse->Checked);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::esClick(TObject *Sender)
{
 mainChart->deleteAllLabels();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::buttomAddLabelClick(TObject *Sender)
{
 for(int i = 0; i < 1000; ++i){
    mainChart->addLabel();
 }
}
//---------------------------------------------------------------------------


//==============================================================================
//    переводит время в формате(hh:mm:ss) в количество секунд
//==============================================================================
int TForm1::TimeToInt(const AnsiString& S)
{
   int n = S.Pos(":");
   if(!n)
       return -1;

   // hours
   AnsiString s1 = S.SubString(0, n-1);
   if(s1 == "")
       return -1;
   int hou = StrToInt(s1);

   // minutes
   AnsiString s2 = S.SubString(n+1, 255);
   n = s2.Pos(":");
   if(!n)
       return -1;
   s1 = s2.SubString(0, n-1);
   if(s1 == "")
       return -1;
   int min = StrToInt(s1);

   // sec
   s2 = s2.SubString(n+1, 255);
   if(s2 == "")
       return -1;
   int sec = StrToInt(s2);

   return (hou*3600 + min*60 + sec);
}


double TForm1::IntToTime(const int time)
{
 int hh = time / 3600000;
 int mm = (time % 3600000) / 60000;
 int ss = (time % 3600000) % 60000 / 1000;
 int ms = (time % 3600000) % 60000 % 1000;
 return EncodeTime(hh, mm, ss, ms);     // unsigned short
}


void __fastcall TForm1::FormCreate(TObject *Sender)
{
 int test = 90;
}
//---------------------------------------------------------------------------


/*bool TForm1::PrintParameterListToFile(const String* fileName, std::list<Parametr*>::iterator list)
{
 if(list.empty())
    return false;
 ofstream output(fileName.c_str());
 if( !output)
    return false;
 for(list_it i = list.begin(), j = list.end(); i != j; ++i)
 {

 }
}     */

