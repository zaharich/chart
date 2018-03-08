//---------------------------------------------------------------------------

#ifndef startLogH
#define startLogH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TstartLogForm : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TTimer *Timer1;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TstartLogForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TstartLogForm *startLogForm;
//---------------------------------------------------------------------------
#endif
