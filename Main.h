//---------------------------------------------------------------------------
#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <TeeFunci.hpp>
#include <Graphics.hpp>
#include <DbChart.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include "Chart.h"
#include "TeeComma.hpp"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include "TeeScroB.hpp"
#include <Grids.hpp>
#include <ImgList.hpp>
#include <AppEvnts.hpp>
#include <MPlayer.hpp>
#include "TeeChartGrid.hpp"
#include <TeCanvas.hpp>
#include <TeeLisB.hpp>
#include "TeePageNumTool.hpp"
#include "TeeTools.hpp"
#include <FileCtrl.hpp>
#include <ToolWin.hpp>
#include "CSPIN.h"
#include "TeeEdit.hpp"
#include <ActnList.hpp>
#include <ActnMan.hpp>
#include "TeeChartActions.hpp"
#include <StdActns.hpp>
#include "CGAUGES.h"
#include "TeeOpenGL.hpp"
#include "inifiles.hpp"
#include <map>
#include <vector>
#include <list>

#include "TimeBar.h";
#include "myChart.h"
#include "CustomIniFile.h"
#include "FlyingFile.h"


//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TPopupMenu *PopupMenu1;
        TMenuItem *NAddParameter;
        TMenuItem *NMarginSettings;
        TOpenDialog *OpenDialogData;
        TOpenDialog *OpenDialogFormat;
        TPanel *Panel2;
        TPanel *Panel1;
        TPopupMenu *PopupMenuAxis;
        TMenuItem *Settings;
        TSaveDialog *SaveDialogFormat;
        TMenuItem *Delete;
        TSplitter *Splitter1;
        TPageControl *PageControl1;
        TTabSheet *TabSheet2;
        TFileListBox *FileListBox1;
        TMenuItem *N5;
        TPanel *Panel3;
        TEdit *Edit1;
        TImageList *ImageList1;
        TImageList *ImageListPageControl2;
        TFontDialog *FontDialog1;
        TOpenDialog *OpenDialogIni;
        TSaveDialog *SaveDialogIni;
        TSplitter *Splitter7;
        TMenuItem *NPaste;
        TMainMenu *MainMenu1;
        TMenuItem *MFile;
        TMenuItem *MHelp;
        TMenuItem *NOpen;
        TMenuItem *NLibrary;
        TMenuItem *LibraryOpen;
        TMenuItem *LibraryClose;
        TMenuItem *NSettings;
        TMenuItem *NSettingsOpen;
        TMenuItem *NSettingsSave;
        TMenuItem *NSettingsSaveAs;
        TMenuItem *N1;
        TMenuItem *NSaveGraphtAs;
        TMenuItem *N2;
        TMenuItem *NPrint;
        TMenuItem *N3;
        TMenuItem *NExit;
        TActionList *ActionList1;
        TFileExit *Exit;
        TAction *AOpenINI;
        TAction *AOpenLibrary;
        TAction *AOpenMode;
        TChartActionPrint *ChartActionPrint1;
        TAction *ASaveINI;
        TAction *ASaveMode;
        TAction *ASaveAll;
        TAction *ASaveAsPicture;
        TAction *AAxisMove;
        TAction *AAxisStretch;
        TAction *AAxisAdd;
        TAction *AAxisDelete;
        TAction *AAxisSetMinMax;
        TAction *AOpenFlyingFile;
        TAction *AInfo;
        TMenuItem *NExport;
        TMenuItem *NExportTXT;
        TMenuItem *NExportEXC;
        TToolBar *ToolBar1;
        TToolButton *ToolButton5;
        TToolButton *ToolButton3;
        TToolButton *ToolButton10;
        TToolButton *ToolButton13;
        TToolButton *ToolButton17;
        TSpeedButton *buttonOpenFlyingFile;
        TSpeedButton *buttonOpenINI;
        TSpeedButton *buttonPrint;
        TSpeedButton *buttonSlowBuilt;
        TSpeedButton *buttonFastBuilt;
        TSpeedButton *buttonFullTime;
        TSpeedButton *SpeedButton9;
        TSpeedButton *SpeedButton10;
        TSpeedButton *SpeedButton11;
        TSpeedButton *SpeedButton12;
        TSpeedButton *SpeedButton15;
        TSpeedButton *buttonSelectColor;
        TSpeedButton *buttonLinkingGrid;
        TSpeedButton *buttonInfo;
        TToolButton *ToolButton1;
        TMenuItem *MParametrs;
        TMenuItem *MEdit;
        TMenuItem *Mmanagement;
        TMenuItem *MLibrary;
        TMenuItem *Mregime;
        TMenuItem *NOpenFormatka;
        TMenuItem *NInfo;
        TMenuItem *NAbout;
        TMenuItem *NFormatOpen;
        TMenuItem *NFormatSave;
        TMenuItem *NFormatSaveAs;
        TAction *ASaveINIAs;
        TMenuItem *N4;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *N8;
        TOpenDialog *OpenDialogFileRashet;
        TMenuItem *NFormatCurrentProperties;
        TSpeedButton *buttonZoomIn;
        TSpeedButton *buttonReperLine;
        TSpeedButton *buttonOpenChart;
        TSpeedButton *buttonCut;
        TTabControl *TabControl1;
        TScrollBox *ScrollBox1;
        TPanel *Panel10;
        TCheckBox *CheckBoxWithTime;
        TEdit *EditStartTime;
        TEdit *EditEndTime;
        TToolButton *ToolButton4;
        TMenuItem *NRegim;
        TMenuItem *NOpenRegim;
        TMenuItem *NSaveRegim;
        TMenuItem *NSaveAs;
        TPopupMenu *PopupMenuTab;
        TMenuItem *NDeleteTab;
        TMenuItem *NRenameTab;
        TMenuItem *NCopyTab;
        TMenuItem *NPasteTab;
        TOpenDialog *OpenDialogMode;
        TSaveDialog *SaveDialogMode;
        TMenuItem *NOpenTxt;
        TOpenDialog *OpenDialogTxt;
        TTabSheet *TabSheet1;
        TStringGrid *StringGrid1;
        TMenuItem *NnewTab;
        TSpeedButton *forwardSubKadrButton;
        TSpeedButton *forwardKadrButton;
        TSpeedButton *backKadrButton;
        TSpeedButton *backSubKadrButton;
        TEdit *deltaTimeEdit;
        TLabel *Label7;
        TPanel *Panel11;
        TPanel *PanelRenameTab;
        TGroupBox *GroupBox2;
        TLabel *Label6;
        TLabel *Label5;
        TEdit *oldNameEdit;
        TEdit *newNameEdit;
        TButton *ButtonOKRename;
        TButton *ButtonExitRename;
        TSpeedButton *SpeedButton2;
        TSpeedButton *buttonOpenFormat;
        TBitBtn *BottonFont;
        TSpeedButton *SpeedButtonVisible;
        TSpeedButton *SpeedButtonDelete;
        TSpeedButton *SpeedButtonStretch;
        TSpeedButton *SpeedButtonAddInc;
        TSpeedButton *SpeedButtonMaxMin;
        TSpeedButton *SpeedButtonMove;
        TCheckBox *CheckBoxMouse;
        TLabel *Label2;
        TLabel *Label1;
        TPanel *Panel12;
        TTeeCommander *TeeCommander1;
        TButton *Button3;
        TEdit *Edit7;
        TEdit *Edit5;
        TEdit *Edit2;
        TEdit *Edit6;
        TSpeedButton *SpeedButton4;
        TPanel *PanelColor;
        TSpeedButton *buttonColor;
        TColorBox *ColorBox1;
  TButton *Button1;
  TSpeedButton *buttomAddLabel;
  TSpeedButton *SpeedButton1;
  TMenuItem *NNewFormat;
  TChart *Chart1;
        void __fastcall buttonOpenChartClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall buttonCutClick(TObject *Sender);
        void __fastcall SpeedButtonSaveChartClick(TObject *Sender);
        void __fastcall DeleteClick(TObject *Sender);
        void __fastcall FileListBox1DblClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall buttonReperLineClick(TObject *Sender);
        void __fastcall BottonFontClick(TObject *Sender);
        void __fastcall CheckBoxEndIdentClick(TObject *Sender);
        void __fastcall SpeedButtonMoveMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ButtonCreateStringClick(TObject *Sender);
        void __fastcall AOpenFlyingFileExecute(TObject *Sender);
        void __fastcall AOpenINIExecute(TObject *Sender);
        void __fastcall ASaveINIExecute(TObject *Sender);
        void __fastcall ChartActionPrint1Execute(TObject *Sender);
        void __fastcall buttonSlowBuiltClick(TObject *Sender);
        void __fastcall TabControl1Change(TObject *Sender);
        void __fastcall AInfoExecute(TObject *Sender);
        void __fastcall TabControl1Changing(TObject *Sender,
          bool &AllowChange);
        void __fastcall MParametrsClick(TObject *Sender);
        void __fastcall MEditClick(TObject *Sender);
        void __fastcall MmanagementClick(TObject *Sender);
        void __fastcall NAboutClick(TObject *Sender);
        void __fastcall ASaveAllExecute(TObject *Sender);
        void __fastcall NFormatOpenClick(TObject *Sender);

        void __fastcall ASaveINIAsExecute(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
        void __fastcall N7Click(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall buttonFullTimeClick(TObject *Sender);
        void __fastcall buttonLinkingGridClick(TObject *Sender);
        void __fastcall CheckBoxWithTimeClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall buttonColorClick(TObject *Sender);
        void __fastcall ComboBoxLineWidthClick(TObject *Sender);
        void __fastcall ComboBoxLineWidthBeginEdit(TObject *Sender);
        void __fastcall buttonFastBuiltClick(TObject *Sender);
        void __fastcall NDeleteTabClick(TObject *Sender);
        void __fastcall NRenameTabClick(TObject *Sender);
        void __fastcall ButtonOKRenameClick(TObject *Sender);
        void __fastcall ButtonExitRenameClick(TObject *Sender);
        void __fastcall TabControl1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall NOpenRegimClick(TObject *Sender);
        void __fastcall NSaveAsClick(TObject *Sender);
        void __fastcall NOpenTxtClick(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall NExitClick(TObject *Sender);
        void __fastcall NFormatSaveAsClick(TObject *Sender);
        void __fastcall NnewTab2Click(TObject *Sender);
        void __fastcall NMarginSettingsClick(TObject *Sender);
        void __fastcall SettingsClick(TObject *Sender);
        void __fastcall PageControl1Resize(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall forwardKadrButtonClick(TObject *Sender);
        void __fastcall deltaTimeEditChange(TObject *Sender);
        void __fastcall EditStartTimeKeyPress(TObject *Sender, char &Key);
        void __fastcall EditEndTimeChange(TObject *Sender);
        void __fastcall buttonOpenFormatClick(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall NFormatCurrentPropertiesClick(TObject *Sender);
        void __fastcall TabControl1DragDrop(TObject *Sender,
          TObject *Source, int X, int Y);
        void __fastcall TabControl1DragOver(TObject *Sender,
          TObject *Source, int X, int Y, TDragState State, bool &Accept);
  void __fastcall Button1Click(TObject *Sender);
  void __fastcall SpeedButtonMaxMinClick(TObject *Sender);
  void __fastcall esClick(TObject *Sender);
  void __fastcall buttomAddLabelClick(TObject *Sender);
  void __fastcall FormCreate(TObject *Sender);

private:	// User declarations
 const float no_value;        // значение для отсутсвия данных на графике быстр.построения
 TimeBar* timeBar;
 bool isPaint;                // means that form1 is already paint

public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
 FunLibrery(char *);
 String NameFileRashetTxt;                    // 2013_07_15    Хромцов  имя текстового файла расчетных параметров

 TForm1();
 myChart* mainChart;
 CustomIniFile* iniFile;
 TIniFile *iniFileMain;

 bool printing, building;                     // флаги: в данный момент идет печать, построение
 int X0, Y0;                                  // начальные координаты нажатой мыши
 int stretch;                                 // переменная для растяжки оси при управлении полностью на мыши
 double currentKadr;
 double CutX0, CutX1;                         // значения X Для вырезания временной области

 String SourceDir;                        // директория с программой

 std::vector<int> numMode;
 std::vector<String> pathMode;

private:
   int getNFreeSeries();                      // count of empty series

   void LoadFlyingFile(const String& PathToFlyingFile);
   void SaveINI();

   void FastBuild();
   void Build();
   void InitBuild();
   void EndBuild();

   // Format
   void NewFormat();
   void OpenFormat(const String& pathToFormatka);
   void SaveFormat(const String& nameFormatka);
   void SaveFormatAs();

   // Tabs
   void AddTab(const String& pathToTeeFile);
   void SaveCurrentTab(const String& pathToFormatDir);
   void DeleteCurrentTab(const bool loadAnotherChart);
   void RenameTab(const String& Rename);
   void CopyTab();
   int  RepeatTabName(const String& name);

   void SaveAllSettings();

   enum {CHART_PAGE, PARAMETER_PAGE, INFO_PAGE, AXIS_PAGE, MAIN_PAGE};
   void openSettingsPage(int nPage);

   int TimeToInt(const String& S);
   double IntToTime(const int time);
   bool PrintParameterListToFile(const String* fileName, std::list<Parametr*>::iterator list);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif


