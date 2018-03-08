// READ ONLY
#include <vcl.h>
#include <mem.h>

#include "User.h"
TFunAdresParamInp  *FunAdresParamInp = NULL;
TFunAdresParamOut  *FunAdresParamOut = NULL;
TFunAdresqcg *qcg = NULL;
TFunAdresrpr *rpr = NULL;
TFunAdresprm *prm = NULL;
TFunAdresdif *dif = NULL;
TFunAdressgl *sgl = NULL;
TFunAdrestct *tct = NULL;
//TFunAdresSistemStruct  *FunAdresSistemStruct = NULL;
//struct FlagPotokVizual *PtrFlagPotokVizualDLL = NULL;
//struct WinSistTab *PtrWinSistTabDLL = NULL;
//struct Pasp *PtrPaspDLL = NULL;
//struct SisTable *PtrSisTableDLL = NULL;
//struct Potok *PtrPotokDLL = NULL;
//struct Table *PtrTableDLL = NULL;
//struct TipPar *PtrTipParDLL = NULL;
//char    *PtrBlokRKDLL = NULL;
//struct Message *PtrMessageDLL = NULL;
//int KParamMessageDLL = 0;
//char *NameFileOutDLL = NULL;  // 2008_02_01


//--------------------------------------------------------------------------
//void _stdcall InitAPI(void* AFunAdresParamInp,void* AFunAdresParamOut,void *AFunAdresSistemStruct)
void _stdcall InitAPI(void* AFunAdresParamInp,void* AFunAdresParamOut,
void* Adresqcg,void* Adresrpr,void* Adresprm,void* Adresdif,void* Adressgl,void* Adrestct )
{
FunAdresParamInp = (TFunAdresParamInp *)AFunAdresParamInp;
FunAdresParamOut = (TFunAdresParamOut *)AFunAdresParamOut;
qcg = (TFunAdresqcg *)Adresqcg;
rpr = (TFunAdresrpr *)Adresrpr;
prm = (TFunAdresprm *)Adresprm;
dif = (TFunAdresdif *)Adresdif;
sgl = (TFunAdressgl *)Adressgl;
tct = (TFunAdrestct *)Adrestct;
//FunAdresSistemStruct = (TFunAdresSistemStruct *)AFunAdresSistemStruct;
}
//-----------------------------------------------------------------------------
/*
//-----------------------------------------------------------------------------
// Для передачи имени выходного файла
void _stdcall  UserProcNameFileOut(void *ANameFileOut)       // 2008_02_01
{
NameFileOutDLL  =(char *)ANameFileOut;
//FunAdresSistemStruct(PtrPaspDLL);
return;
}
*/
/*
//-----------------------------------------------------------------------------
// Получить из системы адреса Системных структур
void _stdcall  InitAdresAPISistemStruct(void *APtrFlagPotokVizual,
   void *APtrWinSistTab,void *ASisTable,void *APasp,void *APotok,
   void *ATipPar,void *ABlokRK)
{
PtrFlagPotokVizualDLL = (struct FlagPotokVizual *)APtrFlagPotokVizual;
PtrWinSistTabDLL = (struct WinSistTab *)APtrWinSistTab;
PtrSisTableDLL = (struct SisTable *)ASisTable;
PtrPaspDLL = (struct Pasp*)APasp;
//PtrPaspDLL = (struct Pasp *)APasp;
PtrPotokDLL = (struct Potok *)APotok;
//PtrTableDLL = (struct Table *)ATable;
PtrTipParDLL = (struct TipPar *)ATipPar;
//PtrBlok_tarDLL = (char    *)ABlok_tar;
PtrBlokRKDLL = (char *)ABlokRK;
//FunAdresSistemStruct(PtrPaspDLL);
}
*/
/*
//---------------------------------------------------------------------------
void _stdcall  InitAdresAPISistemStructMessage(void *AMessage,int KParamMessage)
{
PtrMessageDLL = (struct Message *)AMessage;
KParamMessageDLL = KParamMessage;
}
*/
