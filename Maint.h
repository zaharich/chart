//---------------------------------------------------------------------------

#ifndef MaintH
#define MaintH
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
#include "TimeBar.h";
#include "CustomIniFile.h"

 const unsigned MKSERIES = 60;         // ћаксимальное кол-во серий
 const double LEFTAXIS = 100;
 //const double SEC = 1/86400.;  //  1/86400 часть суток равна€ 1 сек

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
        TSplitter *SplitterStart;
        TSplitter *SplitterEnd;
        TPanel *PanelStart;
        TPanel *PanelEnd;
        TPanel *PanelScroll;
        TSaveDialog *SaveDialogIni;
        TTabSheet *TabSheet3;
        TPanel *Panel11;
        TMemo *Memo1;
        TSplitter *Splitter7;
        TLabel *LabelExample;
        TEdit *EditExample;
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
        TToolButton *ToolButton26;
        TEdit *Edit4;
        TEdit *Edit8;
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
        TSpeedButton *buttonSettingsGrid;
        TSpeedButton *SpeedButton20;
        TSpeedButton *buttonInfo;
        TToolButton *ToolButton1;
        TPanel *Panel8;
        TGroupBox *GroupBoxMarks;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label22;
        TEdit *Edit3;
        TCheckBox *CheckBoxMarks;
        TComboBox *ComboBox3;
        TPanel *Panel7;
        TGroupBox *GroupBoxStrings;
        TSpeedButton *ButtonCreateString;
        TLabel *Label21;
        TPanel *Panel6;
        TGroupBox *GroupBoxArg;
        TLabel *Label16;
        TLabel *Label17;
        TLabel *Label20;
        TComboBox *ComboBox2;
        TPanel *Panel5;
        TGroupBox *GroupBox5;
        TSpeedButton *SpeedButtonGridEnable;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label19;
        TGroupBox *GroupBoxMargins;
        TCSpinEdit *CSpinEditLeft;
        TCSpinEdit *CSpinEditBottom;
        TCSpinEdit *CSpinEditTop;
        TCSpinEdit *CSpinEditRight;
        TCSpinEdit *EditKolVertLines;
        TCSpinEdit *EditKolHorizLines;
        TPanel *Panel9;
        TGroupBox *GroupBoxFlags;
        TLabel *Label23;
        TLabel *Label2;
        TLabel *Label1;
        TCheckBox *CheckBoxEndIdent;
        TCheckBox *CheckBox1;
        TEdit *EditMin;
        TEdit *EditMax;
        TPanel *Panel4;
        TGroupBox *GroupBox8;
        TSpeedButton *SpeedButtonStretch;
        TLabel *Label18;
        TSpeedButton *SpeedButtonMove;
        TSpeedButton *SpeedButtonMaxMin;
        TSpeedButton *SpeedButtonAddInc;
        TSpeedButton *SpeedButtonDelete;
        TColorBox *ColorBoxLine;
        TComboBoxEx *ComboBoxLineWidth;
        TComboBox *ComboBoxLineType;
        TBitBtn *BottonFont;
        TCheckBox *CheckBoxMouse;
        TSplitter *Splitter6;
        TSplitter *Splitter5;
        TSplitter *Splitter4;
        TSplitter *Splitter3;
        TSplitter *Splitter2;
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
        TButton *ButtonMinMaxOk;
        TCSpinEdit *EditMinorCount;
        TMenuItem *N4;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *N8;
        TOpenDialog *OpenDialogFileRashet;
        TMenuItem *NFormatCurrentProperties;
        TSpeedButton *buttonZoomIn;
        TSpeedButton *buttonReperLine;
        TSpeedButton *buttonLoadChart;
        TToolButton *ToolButton2;
        TSpeedButton *buttonCut;
        TSpeedButton *buttonSaveChart;
        TTabControl *TabControl1;
        TScrollBox *ScrollBox1;
        TChart *Chart1;
        TPageNumTool *ChartTool1;
        TSpeedButton *SpeedButton1;
        TPanel *Panel10;
        TCheckBox *CheckBoxWithTime;
        TEdit *EditStartTime;
        TEdit *EditEndTime;
        TToolButton *ToolButton4;
        TPanel *PanelColor;
        TColorBox *ColorBox1;
        TSpeedButton *buttonColor;
        TPopupMenu *LabelPopupMenu;
        TMenuItem *LabelDeleteMenu;
        TMenuItem *LableFontMenu;
        TMenuItem *NRegim;
        TMenuItem *NOpenRegim;
        TMenuItem *NSaveRegim;
        TMenuItem *NSaveAs;
        TPopupMenu *PopupMenuTab;
        TMenuItem *NDeleteTab;
        TMenuItem *NRenameTab;
        TMenuItem *NCopyTab;
        TMenuItem *NPasteTab;
        TPanel *PanelRenameTab;
        TLabel *Label5;
        TLabel *Label6;
        TEdit *Edit9;
        TButton *ButtonOKRename;
        TEdit *Edit10;
        TButton *ButtonExitRename;
        TOpenDialog *OpenDialogMode;
        TSaveDialog *SaveDialogMode;
        TPanel *Panel12;
        TTeeCommander *TeeCommander1;
        TButton *Button3;
        TEdit *Edit7;
        TEdit *Edit5;
        TEdit *Edit2;
        TEdit *Edit6;
        TEdit *EditInfo;
        TMenuItem *NOpenTxt;
        TOpenDialog *OpenDialogTxt;
        TLabel *LabelStartTime;
        TLabel *LabelEndTime;
        TTabSheet *TabSheet1;
        TStringGrid *StringGrid1;
        TMenuItem *NnewTab;
        void __fastcall Chart1ClickAxis(TCustomChart *Sender,
          TChartAxis *Axis, TMouseButton Button, TShiftState Shift, int X,
          int Y);
        void __fastcall Chart1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Chart1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall buttonLoadChartClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Chart1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall buttonCutClick(TObject *Sender);
        void __fastcall SettingsClick(TObject *Sender);
        void __fastcall SpeedButtonSaveChartClick(TObject *Sender);
        void __fastcall DeleteClick(TObject *Sender);
        void __fastcall SpeedButtonGridEnableClick(TObject *Sender);
        void __fastcall EditMinorCountChange(TObject *Sender);
        void __fastcall SplitterStartCanResize(TObject *Sender, int &NewSize,
          bool &Accept);
        void __fastcall SplitterEndCanResize(TObject *Sender, int &NewSize,
          bool &Accept);
        void __fastcall PanelScrollMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall PanelScrollMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall PanelScrollMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall FormCanResize(TObject *Sender, int &NewWidth,
          int &NewHeight, bool &Resize);
        void __fastcall Panel1CanResize(TObject *Sender, int &NewWidth,
          int &NewHeight, bool &Resize);
        void __fastcall FileListBox1DblClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall buttonReperLineClick(TObject *Sender);
        void __fastcall Chart1AfterDraw(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall ComboBoxLineTypeDrawItem(TWinControl *Control, int Index,
          TRect &Rect, TOwnerDrawState State);
        void __fastcall BottonFontClick(TObject *Sender);
        void __fastcall CSpinEditRightChange(TObject *Sender);
        void __fastcall CSpinEditTopChange(TObject *Sender);
        void __fastcall CSpinEditBottomChange(TObject *Sender);
        void __fastcall CSpinEditLeftChange(TObject *Sender);
        void __fastcall CheckBoxEndIdentClick(TObject *Sender);
        void __fastcall CSpinEditMinorCountChange(TObject *Sender);
        void __fastcall SplitterStartMoved(TObject *Sender);
        void __fastcall SplitterEndMoved(TObject *Sender);
        void __fastcall SpeedButtonMoveMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Memo1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Memo1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Memo1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall ComboBoxLineTypeSelect(TObject *Sender);
        void __fastcall EditKolVertLinesChange(TObject *Sender);
        void __fastcall EditKolHorizLinesChange(TObject *Sender);
        void __fastcall EditKolVertLinesKeyPress(TObject *Sender,
          char &Key);
        void __fastcall buttonZoomInClick(TObject *Sender);
        void __fastcall ButtonCreateStringClick(TObject *Sender);
        void __fastcall LabelExampleMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall LabelExampleMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall LabelExampleMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall LabelExampleDblClick(TObject *Sender);
        void __fastcall EditExampleKeyPress(TObject *Sender, char &Key);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall AOpenFlyingFileExecute(TObject *Sender);
        void __fastcall AOpenINIExecute(TObject *Sender);
        void __fastcall ASaveINIExecute(TObject *Sender);
        void __fastcall ChartActionPrint1Execute(TObject *Sender);
        void __fastcall buttonSlowBuiltClick(TObject *Sender);
        void __fastcall NNewListClick(TObject *Sender);
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
        //void __fastcall ASaveFormatAsExecute(TObject *Sender);
        void __fastcall ASaveINIAsExecute(TObject *Sender);
        void __fastcall ButtonMinMaxOkClick(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
        void __fastcall N7Click(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall buttonFullTimeClick(TObject *Sender);
        void __fastcall buttonLinkingGridClick(TObject *Sender);
        void __fastcall CheckBoxWithTimeClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall buttonColorClick(TObject *Sender);
        void __fastcall EditMaxKeyPress(TObject *Sender, char &Key);
        void __fastcall LabelDeleteMenuClick(TObject *Sender);
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
        void __fastcall PanelEndClick(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall NExitClick(TObject *Sender);
        void __fastcall NFormatSaveAsClick(TObject *Sender);
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall NnewTab2Click(TObject *Sender);
private:	// User declarations

public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        FunLibrery(char *);
 TForm1();
 bool SelectAxis, Mouse_Down, UpHalfAxis;     // флаги: ќсь выбрана, мышь нажата, нажали на верхнюю часть оси
 bool SplitterMoved;                  // «апрет мен€ть размеры PanelScroll
 bool Button, GraphIsBuilting;

 int countMainVertLine;                       // кол-во главных вертикальных полос
 int X0, Y0;                                  // начальные координаты нажатой мыши
 int stretch;                                 // переменна€ дл€ раст€жки оси при управлении полностью на мыши
 int SourseWidth, StartPanel, EndPanel;       // ширина окна, стартовой панели и конечной панели(необходимо дл€ нижней полосы)
 int knp;                                     // кол-во новых параметров
 int SourseMinTime, SourseMaxTime;            // минимальное врем€, макс врем€
 TObject* TekLabel;                           // ссылка на текущий Label (дл€ удалени€)

 double AxisMax, AxisMin, AxisIncrement;
 double CutX0, CutX1;                         // значени€ X ƒл€ вырезани€ временной области

 TFastLineSeries *Series1;
 TLabel *label[3];                            // кол-во надписей на диаграмме
 TChartTitle *tit[3];

 TimeBar* timeBar;

 TIniFile *iniFileMain;
 AnsiString iniFileNameMain;
 AnsiString SourseDir;                        // директори€ с программой

 String NameFileRashetTxt;                    // 2013_07_15    ’ромцов  им€ текстового файла расчетных параметров
 CustomIniFile *iniFile;

 std::vector<int> numMode;
 std::vector<String> pathMode;

 struct Arrays
 {
    unsigned  NS;                       // номер системы параметра
    unsigned  MasNumberPasp;            // номер паспорта
    unsigned  NPar;                     // номер параметра в системе выведенных параметров
 };

private:
   void DeleteAllParameters();
   void CreateSmallFile();
   void SetTimeBar(const float CurrStart, const float CurrEnd);
   void DrawEndIdents();
   void LinkToGrid(TChartAxis *Axis);

   void LoadFlyingFile(const AnsiString& PathToFlyingFile);
   void LoadEdit();
   void ChartToFile(const AnsiString& pathToTeeFile, bool includeData, bool textFormat);
   void OpenChartFromFile(const AnsiString& TeeName);
   void SaveINI();

   void FastBuilt();                // main function
   void Built();

   // Format
   void NewFormat();
   void OpenFormat(const String& pathToFormatka);
   void SaveFormat(const String& nameFormatka);

   // Tabs
   void AddTab(const String& pathToTeeFile);
   void SaveCurrentTab(const String& pathToFormatDir);
   void DeleteCurrentTab(const bool loadAnotherChart);
   void RenameTab(const String& Rename);
   void CopyTab();
   int  RepeatTabName(const String& name);

   void SaveAllSettings();

public:
   void CreateParametr(int i);
   void DeleteParametr(int& n);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif


