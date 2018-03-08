//---------------------------------------------------------------------------

#ifndef UnitFormPropertyPanelH
#define UnitFormPropertyPanelH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <ToolWin.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include "CSPIN.h"
#include "PERFGRAP.h"
#include "FormatClass.h"
#include "FileMinimaxGlobalValue.h"
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TFormPropertyPanel : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TFontDialog *FontDialogGraf;
        TColorDialog *ColorDialogBrush;
        TColorDialog *ColorDialogSetka;
        TFontDialog *FontDialogTabl;
        TActionList *ActionList1;
        TTabSheet *TabSheet2;
        TPanel *Panel11;
        TToolBar *ToolBar3;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton5;
        TPanel *Panel12;
        TLabel *Label20;
        TEdit *Edit1;
        TCheckBox *CheckBox11;
        TStringGrid *StringGrid2;
        TSplitter *Splitter3;
        TPanel *Panel13;
        TPanel *Panel14;
        TLabel *Label21;
        TEdit *Edit2;
        TStringGrid *StringGrid1;
        TListBox *ListBox1;
        TTabSheet *TabSheet3;
        TPanel *Panel15;
        TToolBar *ToolBar4;
        TSpeedButton *SpeedButton17;
        TSpeedButton *SpeedButton18;
        TSpeedButton *SpeedButton19;
        TSpeedButton *SpeedButton20;
        TSpeedButton *SpeedButton21;
        TPanel *Panel16;
        TCheckBox *CheckBox14;
        TStringGrid *StringGrid6;
        TSplitter *Splitter4;
        TPanel *Panel17;
        TPanel *Panel18;
        TLabel *Label23;
        TEdit *Edit16;
        TStringGrid *StringGrid5;
        TSpeedButton *SpeedButton10;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TGroupBox *GroupBox4;
        TRadioButton *RadioButton3;
        TRadioButton *RadioButton4;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn4;
        TBitBtn *BitBtn5;
        TTabSheet *TabSheet4;
        TPanel *Panel19;
        TToolBar *ToolBar5;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton11;
        TSpeedButton *SpeedButton8;
        TPanel *Panel20;
        TLabel *Label26;
        TEdit *Edit8;
        TCheckBox *CheckBox12;
        TStringGrid *StringGrid3;
        TSplitter *Splitter5;
        TPanel *Panel21;
        TPanel *Panel22;
        TLabel *Label27;
        TEdit *Edit7;
        TStringGrid *StringGrid4;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *Edit3;
        TUpDown *UpDown1;
        TEdit *Edit4;
        TUpDown *UpDown2;
        TLabel *Label16;
        TLabel *Label17;
        TEdit *Edit9;
        TSpeedButton *SpeedButton9;
        TEdit *Edit10;
        TButton *Button2;
        TTabSheet *TabSheet5;
        TPanel *Panel1;
        TGroupBox *GroupBox1;
        TLabel *Label11;
        TLabel *Label12;
        TEdit *Edit5;
        TEdit *Edit6;
        TLabel *Label5;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TCheckBox *CheckBox3;
        TCheckBox *CheckBox4;
        TCheckBox *CheckBox5;
        TCheckBox *CheckBox6;
        TCheckBox *CheckBox7;
        TCheckBox *CheckBox8;
        TCheckBox *CheckBox9;
        TCheckBox *CheckBox10;
        TLabel *Label6;
        TCSpinEdit *CSpinEdit1;
        TCSpinEdit *CSpinEdit2;
        TCSpinEdit *CSpinEdit3;
        TCSpinEdit *CSpinEdit4;
        TCSpinEdit *CSpinEdit5;
        TCSpinEdit *CSpinEdit6;
        TCSpinEdit *CSpinEdit7;
        TCSpinEdit *CSpinEdit8;
        TCSpinEdit *CSpinEdit9;
        TCSpinEdit *CSpinEdit10;
        TButton *Button3;
        TLabel *Label7;
        TCheckBox *CheckBox16;
        TCheckBox *CheckBox17;
        TLabel *Label8;
        TComboBox *ComboBox1;
        TLabel *Label15;
        TCheckBox *CheckBoxFormatAll;
        TLabel *Label9;
        TComboBox *ComboBox2;
        TLabel *Label10;
        TButton *Button1;
        TSpeedButton *SpeedButton12;
        TGroupBox *GroupBox2;
        TLabel *Label1;
        TComboBox *ComboBox3;
        TRadioButton *RadioButton5;
        TRadioButton *RadioButton6;
        TCheckBox *CheckBox13;
        TCSpinEdit *CSpinEdit11;
        TGroupBox *GroupBox3;
        TRadioButton *RadioButton7;
        TRadioButton *RadioButton8;
        TGroupBox *GroupBox5;
        TRadioButton *RadioButton9;
        TRadioButton *RadioButton10;
        TGroupBox *GroupBox6;
        TRadioButton *RadioButton11;
        TRadioButton *RadioButton12;
        void __fastcall StringGrid2DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall SpeedButton5Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton3Click(TObject *Sender);
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall StringGrid2SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall Edit3Exit(TObject *Sender);
        void __fastcall SpeedButton6Click(TObject *Sender);
        void __fastcall SpeedButton7Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
//        void __fastcall TabSheet7Show(TObject *Sender);
//        void __fastcall TabSheet5Show(TObject *Sender);
        void __fastcall TabControl1Change(TObject *Sender);
        void __fastcall BitBtn10Click(TObject *Sender);
        void __fastcall BitBtn6Click(TObject *Sender);
        void __fastcall Edit2Change(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall StringGrid4ColumnMoved(TObject *Sender,
          int FromIndex, int ToIndex);
        void __fastcall StringGrid3SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall StringGrid1Click(TObject *Sender);
        void __fastcall StringGrid1MouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall StringGrid3DragOver(TObject *Sender,
          TObject *Source, int X, int Y, TDragState State, bool &Accept);
        void __fastcall StringGrid3DragDrop(TObject *Sender,
          TObject *Source, int X, int Y);
        void __fastcall ComboBox2Change(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall SpeedButton8Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall SpeedButton9Click(TObject *Sender);
        void __fastcall SpeedButton10Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Edit52Change(TObject *Sender);
        void __fastcall SpeedButton51Click(TObject *Sender);
        void __fastcall SpeedButton52Click(TObject *Sender);
        void __fastcall SpeedButton56Click2(TObject *Sender);
        void __fastcall SpeedButton57Click(TObject *Sender);
        void __fastcall SpeedButton58Click(TObject *Sender);
        void __fastcall StringGrid53DragDrop(TObject *Sender,
      TObject *Source, int X, int Y);
        void __fastcall StringGrid53DragOver(TObject *Sender,
      TObject *Source, int X, int Y, TDragState State, bool &Accept);
        void __fastcall StringGrid53SelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect);
        void __fastcall Edit52Change2(TObject *Sender);
        void __fastcall SpeedButton56Click22(TObject *Sender);
        void __fastcall StringGrid54ColumnMoved(TObject *Sender,
      int FromIndex, int ToIndex);
        void __fastcall StringGrid54MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y);
        void __fastcall StringGrid2MouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall SpeedButton11Click(TObject *Sender);
        void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall ListBox1DblClick(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall SpeedButton12Click(TObject *Sender);
        void __fastcall RadioButton11Click(TObject *Sender);
        void __fastcall RadioButton12Click(TObject *Sender);
private:	// User declarations
        TStringGrid *StringGrid100;
        void    SortPolei(TStringGrid *StringGrid100);
        void    TabControlCh();
        void    TablOpenOldNastr();
        void    TablSaveNewNastr();
        int FlagChangeTabString;
        bool FlagMove;
        int NumberMarker;
        int RowDragDrop;     // Ќомер строки в Ћевой таблице при перетаскивании параметра из правой табл.
        int RowMouseDown;      // Ќомер строки в ѕравой табл. при перетаскивании параметра из нее в левую таблицу
        bool FlagMoveLeft;     // ѕризнак перетаскивани€ строки в левой таблице
        int BeginRowStringGridLeft;  // Ќомер перетаскиваемой строки в левой  таблице
        int NRazrRK;                 // Ќомер разр€да разовой команды
        int TipRK;                   // 21-arinc 5- шестнадцатиразр€дные
        int RowEnd;        //  текущий Ќомер переносимой строки в левой таблице
public:		// User declarations
        __fastcall TFormPropertyPanel(TComponent* Owner);
          FormatClass *PtrFormatClass;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPropertyPanel *FormPropertyPanel;
//---------------------------------------------------------------------------
#endif
