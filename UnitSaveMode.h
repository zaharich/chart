//---------------------------------------------------------------------------

#ifndef UnitSaveModeH
#define UnitSaveModeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormSaveMode : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TLabel *Label1;
        TComboBox *ComboBox1;
        TButton *Button2;
private:	// User declarations
public:		// User declarations
        __fastcall TFormSaveMode(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSaveMode *FormSaveMode;
//---------------------------------------------------------------------------
#endif
