//---------------------------------------------------------------------------

#ifndef UnitFormRashetH
#define UnitFormRashetH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFormRashet : public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TBitBtn *BitBtn4;
        TBitBtn *BitBtn5;
        TMemo *Memo1;
        TOpenDialog *OpenDialogFileRashet;
        TSaveDialog *SaveDialogFileRashet;
        void __fastcall BitBtn5Click(TObject *Sender);
        void __fastcall BitBtn4Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormRashet(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRashet *FormRashet;
//---------------------------------------------------------------------------
#endif
