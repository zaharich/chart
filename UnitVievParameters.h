//---------------------------------------------------------------------------

#ifndef Unit_PropertiesH
#define Unit_PropertiesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include "UnitMain_Chart.h"
#include <Buttons.hpp>
#include <Menus.hpp>
#include <ImgList.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
//---------------------------------------------------------------------------
class TForm_Properties : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TLabel *Label1;
        TEdit *Edit_search;
        TLabel *Label2;
        TPanel *Panel5;
        TPanel *Panel6;
        TStringGrid *StringGrid1;
        TStringGrid *StringGrid3;
        TStringGrid *StringGrid2;
        TSpeedButton *SpeedButtonAdd;
        TSpeedButton *SpeedButtonDelete;
        TSpeedButton *SpeedButtonCopy;
        TSpeedButton *SpeedButtonRename;
        TComboBox *ComboBoxRazdel;
        TLabel *Label3;
        TPanel *PanelRK;
        TSpeedButton *SpeedButtonOK;
        TListBox *ListBoxRK;
        TSpeedButton *SpeedButtonCancel;
        TSpeedButton *SpeedButton1;
        TSplitter *Splitter1;
        TPanel *Panel7;
        TSplitter *Splitter2;
        TSpeedButton *ButtonAll;
        TButton *Button1;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Edit_searchChange(TObject *Sender);
        void __fastcall StringGrid2SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall StringGrid2DblClick(TObject *Sender);
        void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall StringGrid1DblClick(TObject *Sender);
        void __fastcall StringGrid3SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall StringGrid3DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall ComboBoxRazdelSelect(TObject *Sender);
        void __fastcall SpeedButtonRenameClick(TObject *Sender);
        void __fastcall SpeedButtonOKClick(TObject *Sender);
        void __fastcall SpeedButtonCancelClick(TObject *Sender);
        void __fastcall StringGrid2KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonAllClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations

public:		// User declarations
        TSpeedButton* buttons[40];
        __fastcall TForm_Properties(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm_Properties *Form_Properties;
//---------------------------------------------------------------------------
#endif
