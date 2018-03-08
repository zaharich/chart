//---------------------------------------------------------------------------


#include <vcl.h>
#pragma hdrstop

#include "LibraryClass.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
LibraryClass *PtrLibraryClass=0;
HINSTANCE DllInstance;
void (_stdcall *InitAPI)(void *,void *);
void (_stdcall *InitAdresAPI)(void);

//---------------------------------------------------------------------------
 LibraryClass::LibraryClass(char *NameLibrary)
{
DllInstance = LoadLibrary(NameLibrary);
// Получить адреса функций из DLL(прикладной программы)
}
//---------------------------------------------------------------------------
 LibraryClass::~LibraryClass()
{
FreeLibrary(DllInstance);

}
//----------------------------------------------------------
void * LibraryClass::FunAdresParamInp(char *NameParamTek)
{
char Buf[128];
float ParamOut;
float *ParamTek;
ParamOut=100.;
strcpy(Buf,NameParamTek);
//ParamTek=(float *)AParamTek;
//AParamTek=(void *)&ParamOut;
return((void *)&ParamOut);
}
//----------------------------------------------------------
void  LibraryClass::FunAdresParamOut(char *NameParamTek,void *AParamTek,int ngr)
{
char Buf[128];
float *ParamTek;
int ngrtek;
//ParamOut=100.;
strcpy(Buf,NameParamTek);
ParamTek=(float *)AParamTek;
ngrtek=ngr;
}
//---------------------------------------------------------------------------
 LibraryClass::GoAdresInDll()
{
//HINSTANCE DllInstance;
//void (_stdcall *InitAPI)(void *,void *);
//void (_stdcall *InitAdresAPI)(void);
//void (_stdcall *InitAPI)((void *)FunAdresParamInp,(void *)FunAdresParamOut);
//Ptr=FunAdresParamInp;
InitAPI = (void(_stdcall *)(void *,void *))GetProcAddress(DllInstance,"InitAPI");
InitAdresAPI = (void(_stdcall *)(void))GetProcAddress(DllInstance,"InitAdresAPI");
InitAdresAPI();
Ptr=(void *)&(FunAdresParamInp(char *));
InitAPI(&FunAdresParamInp,FunAdresParamOut);
}

