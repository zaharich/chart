//---------------------------------------------------------------------------

#ifndef UnitSettingsH
#define UnitSettingsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
#include <ImgList.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
#include <CheckLst.hpp>
#include "CSPIN.h"
#include "TeeComma.hpp"
#include <typeinfo.h>    // rtti провека допустимости в dynamic_cast
#include <string>
#include <vector>

#include "Main.h"
#include "FlyingFile.h"
#include "ParametrRK.h"

//---------------------------------------------------------------------------
class TFormSettings : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TSplitter *Splitter1;
        TSplitter *Splitter2;
        TPanel *Panel1;
        TPanel *Panel5;
        TSpeedButton *SpeedButtonAdd;
        TSpeedButton *SpeedButtonDelete;
        TSpeedButton *SpeedButtonCopy;
        TSpeedButton *SpeedButtonRename;
        TPanel *Panel6;
        TStringGrid *StringGrid1;
        TPanel *Panel2;
        TPanel *Panel3;
        TLabel *Label1;
        TEdit *editSearch;
        TPanel *Panel4;
        TStringGrid *StringGridMain;
        TPanel *PanelRK;
        TSpeedButton *SpeedButtonOK;
        TSpeedButton *SpeedButtonCancel;
        TListBox *ListBoxRK;
        TScrollBox *ScrollBoxRazdel;
        TPanel *PanelOfButtonAll;
        TSpeedButton *ButtonAll;
        TPanel *Panel7;
        TTabSheet *TabSheet3;
        TLabel *Label7;
        TEdit *EditEndTime;
        TEdit *EditStartTime;
        TButton *ButtonOK;
        TButton *Button2;
        TPanel *Panel8;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        TEdit *EditINIFile;
        TEdit *EditLibraryFile;
        TEdit *EditFormatFile;
        TEdit *EditFlyingFile;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TPanel *Panel9;
        TGroupBox *GroupBoxField;
        TGroupBox *gridGroupBox;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TComboBox *tipHorizLineBox;
        TComboBox *tipVertLineBox;
        TComboBox *tipVertDopLineBox;
        TLabel *Label11;
        TCSpinEdit *horizLineEdit;
        TCSpinEdit *vertLineEdit;
        TCSpinEdit *vertLineDopEdit;
        TCheckBox *makeAllCheckBox;
        TGroupBox *GroupBoxMargins;
        TCSpinEdit *editLeft;
        TCSpinEdit *editTop;
        TCSpinEdit *editRight;
        TCSpinEdit *editBottom;
        TColorBox *feildColorBox;
        TLabel *Label12;
        TTabSheet *TabSheet4;
        TPanel *Panel11;
        TPanel *Panel12;
        TPanel *Panel13;
        TGroupBox *GroupBoxGeneral;
        TGroupBox *GroupBoxAxis;
        TGroupBox *GroupBoxRK;
        TGroupBox *GroupBoxGraph;
        TPanel *Panel14;
        TEdit *EditIdent;
        TEdit *EditName;
        TComboBox *ComboBoxNSys;
        TEdit *EditMainName;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *LabelStepCount;
        TEdit *EditStepCount;
        TEdit *EditStep;
        TLabel *LabelStep;
        TLabel *LabelMin;
        TEdit *EditMin;
        TCheckBox *CheckBoxMarks;
        TEdit *EditMark;
        TComboBox *ComboBox1;
        TLabel *Label19;
        TListBox *ListBoxParam;
        TComboBox *ComboBox2;
        TTabSheet *TabSheet5;
        TGroupBox *GroupBox5;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TComboBox *ComboBox3;
        TButton *Button5;
        TPanel *Panel17;
        TGroupBox *GroupBox7;
        TGroupBox *GroupBox8;
        TPanel *Panel18;
        TGroupBox *GroupBox9;
        TGroupBox *GroupBox10;
        TGroupBox *GroupBox11;
        TRadioButton *RadioButton3;
        TRadioButton *RadioButton4;
        TRadioButton *RadioButton5;
        TRadioButton *RadioButton6;
        TRadioButton *RadioButton7;
        TRadioButton *RadioButton8;
        TRadioButton *RadioButton9;
        TRadioButton *RadioButton10;
        TRadioButton *RadioButton11;
        TRadioButton *RadioButton12;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton7;
        TLabel *Label2;
        TLabel *Label20;
        TLabel *Label21;
        TLabel *Label24;
        TLabel *Label23;
        TLabel *Label22;
        TLabel *Label25;
        TSpeedButton *SpeedButton10;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton9;
        TPanel *Panel10;
        TButton *okButton;
        TButton *noButton;
        TChart *exampleChart1;
        TFastLineSeries *Series1;
        TButton *searchButton;
        TCheckBox *CheckBoxVisible;
        TLabel *paspNLabel;
        TEdit *EditPaspN;
        TComboBoxEx *ComboBoxLineWidth;
        TLabel *Label16;
        TLabel *Label17;
        TComboBox *ComboBoxLineType;
        TLabel *Label18;
        TColorBox *ColorBox1;
        TLabel *LabelRKname;
        TEdit *EditMainNameRK;
        TLabel *LabelNrazr;
        TEdit *EditNrazr;
        TRadioGroup *RadioGroupVievRK;
        TRadioButton *RadioButtonFatSlim;
        TRadioButton *RadioButtonStepUp;
        TLabel *Label26;
        TComboBox *afterCommaComboBox;
  TPanel *RKListPanel;
  TLabel *LabelNStructRK;
  TEdit *EditNStructRK;
        TButton *Button1;
        TEdit *editMinChart;
        TEdit *editMaxChart;
        TEdit *editIncrement;
        TEdit *editMinLeft;
        TEdit *editMaxLeft;
        TEdit *editIncrementLeft;
        TChart *exampleChart;
        TCheckBox *CheckBoxAutoLeft;
        TCheckBox *CheckBoxAutoBottom;
  TButton *testPointSeriesButton;
        TScrollBox *ScrollBox1;
        TCheckListBox *CheckListBoxRazdel;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall editSearchChange(TObject *Sender);
        void __fastcall StringGridMainSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall StringGridMainDblClick(TObject *Sender);
        void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall SpeedButtonRenameClick(TObject *Sender);
        void __fastcall SpeedButtonOKClick(TObject *Sender);
        void __fastcall SpeedButtonCancelClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonAllClick(TObject *Sender);
        void __fastcall Splitter2Moved(TObject *Sender);
        void __fastcall StringGrid1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall StringGrid1DragOver(TObject *Sender,
          TObject *Source, int X, int Y, TDragState State, bool &Accept);
        void __fastcall StringGrid1DragDrop(TObject *Sender,
          TObject *Source, int X, int Y);
        void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall StringGridMainMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall StringGridMainDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall StringGridMainColumnMoved(TObject *Sender,
          int FromIndex, int ToIndex);
        void __fastcall StringGridMainMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall SpeedButtonDeleteClick(TObject *Sender);
        void __fastcall okButtonClick(TObject *Sender);
        void __fastcall editLeftChange(TObject *Sender);
        void __fastcall editTopChange(TObject *Sender);
        void __fastcall editRightChange(TObject *Sender);
        void __fastcall editBottomChange(TObject *Sender);
        void __fastcall horizLineEditChange(TObject *Sender);
        void __fastcall vertLineEditChange(TObject *Sender);
        void __fastcall vertLineDopEditChange(TObject *Sender);
        void __fastcall noButtonClick(TObject *Sender);
        void __fastcall TabSheet1Resize(TObject *Sender);
        void __fastcall ComboBoxLineTypeDrawItem(TWinControl *Control,
          int Index, TRect &Rect, TOwnerDrawState State);
        void __fastcall ComboBoxLineTypeSelect(TObject *Sender);
        void __fastcall EditStepCountKeyPress(TObject *Sender, char &Key);
        void __fastcall EditMinKeyPress(TObject *Sender, char &Key);
        void __fastcall feildColorBoxChange(TObject *Sender);
        void __fastcall TabSheet2Resize(TObject *Sender);
        void __fastcall ListBoxParamClick(TObject *Sender);
        void __fastcall StringGridMainMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall StringGridMainDragOver(TObject *Sender,
          TObject *Source, int X, int Y, TDragState State, bool &Accept);
        void __fastcall EditIdentChange(TObject *Sender);
        void __fastcall ListBoxParamDrawItem(TWinControl *Control,
          int Index, TRect &Rect, TOwnerDrawState State);
  void __fastcall RKListPanelMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
  void __fastcall RKListPanelMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void __fastcall RKListPanelMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Button1Click(TObject *Sender);
  void __fastcall testPointSeriesButtonClick(TObject *Sender);
        void __fastcall CheckListBoxRazdelClick(TObject *Sender);
        void __fastcall CheckListBoxRazdelMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);


private:	// User declarations
        String SistemToString(const struct PaspChart *Pasp);
        void packListBoxRazdel();
        void filterRazdel(const String& nameRazdel);
        void Search(const String& text);
        int numCol(unsigned sumWidth, unsigned num, unsigned X);
        int findName(const String& s);
        void getAxisSettings();
        void setAxisSettings();
        void RowHeight(TStringGrid * G);
        int countCheckedItems(TCheckListBox* listBox);

        int fromNumRow;
        int choiceCol;
        bool colMoved;
        bool buttonDown, buttonPress;
        int Kpar;            // количество всех параметров
        int TekRow;          // номер строки параметра, который нужно добавить в определяюшую таблицу при двойном щелчке
        int X0, Y0;
        TFastLineSeries* Series;

        struct GridNode{
          std::string ident;
          std::string name;
          std::string razdel;
          std::string zamer;
          std::string systems;
        };
        std::vector<GridNode> v;
        void PackVectorGridNode();
        void FillMainStringGrid();


public:		// User declarations
        __fastcall TFormSettings(TComponent* Owner);
        void __fastcall OnlyNumbers(char &Key, bool Separator);
        String __fastcall TrueSeparator(const String& textEdit);
};

//---------------------------------------------------------------------------
extern PACKAGE TFormSettings *FormSettings;
//---------------------------------------------------------------------------
#endif
