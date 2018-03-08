//---------------------------------------------------------------------------
#ifndef UnitFormPropertyGraphycH
#define UnitFormPropertyGraphycH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "FileMinimaxGlobalValue.h"
#include "FormatClass.h"
//---------------------------------------------------------------------------
class TFormPropertyGraphyc : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TLabel *Label1;
        TEdit *Edit1;
        TLabel *Label2;
        TEdit *Edit2;
        TSpeedButton *SpeedButton2;
        TLabel *Label4;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TCheckBox *CheckBox3;
        TLabel *Label5;
        TComboBox *ComboBox2;
        TCheckBox *CheckBox4;
        TLabel *Label6;
        TEdit *Edit4;
        TLabel *Label7;
        TEdit *Edit5;
        TLabel *Label8;
        TEdit *Edit6;
        TLabel *Label10;
        TEdit *Edit8;
        TLabel *Label11;
        TEdit *Edit9;
        TEdit *Edit11;
        TLabel *Label15;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton6;
        TComboBox *ComboBox1;
        TFontDialog *FontDialog1;
        TComboBox *ComboBox7;
        TLabel *Label16;
        TLabel *Label17;
        TUpDown *UpDown1;
        TEdit *Edit12;
        TGroupBox *GroupBox1;
        TComboBox *ComboBox3;
        TButton *Button1;
        TCheckBox *CheckBox5;
        TColorDialog *ColorDialog1;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton8;
        TLabel *Label3;
        TUpDown *UpDown2;
        TEdit *Edit3;
        TLabel *Label9;
        TEdit *Edit7;
        TFontDialog *FontDialogScal;
        TButton *Button2;
        TEdit *Edit10;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label18;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TLabel *Label19;
        TComboBox *ComboBox4;
        TEdit *Edit13;
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormDeactivate(TObject *Sender);
        void __fastcall SpeedButton5Click(TObject *Sender);
        void __fastcall SpeedButton6Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ComboBox1Select(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall ComboBox2Select(TObject *Sender);
private:	// User declarations
        FormatClass *PtrFormatClass;
public:		// User declarations
        __fastcall TFormPropertyGraphyc(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPropertyGraphyc *FormPropertyGraphyc;
//---------------------------------------------------------------------------
#endif
