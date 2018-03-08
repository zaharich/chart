// READ ONLY
#pragma pack(1)
//#include "SistemStruct.h"
//#include "FileMinimaxGlobalValue.h"
typedef void * _stdcall TFunAdresParamInp(char *,int,int);
//typedef void _stdcall TFunAdresParamOut(char *NameParamTek,void *AdresParamTek,int ngr);
//typedef void _stdcall TFunAdresParamOut(char *,void *,int,unsigned char);
typedef void _stdcall TFunAdresParamOut(char *,void *,char *,unsigned char,char *);
typedef float _stdcall TFunAdresqcg(float *);
typedef float _stdcall TFunAdresrpr(float *);
typedef float _stdcall TFunAdresprm(float *,float *);
typedef float _stdcall TFunAdresdif(float *,float *);
typedef float _stdcall TFunAdressgl(float *);
typedef float _stdcall TFunAdrestct(float *);
//typedef void _stdcall TFunAdresSistemStruct(struct Pasp *);
// идентификатор
// Адрес параметра
// Номер группы
// Тип параметра f,i,l
extern TFunAdresParamInp *FunAdresParamInp;
extern TFunAdresParamOut *FunAdresParamOut;
extern TFunAdresqcg *qcg;
extern TFunAdresrpr *rpr;
extern TFunAdresprm *prm;
extern TFunAdresdif *dif;
extern TFunAdressgl *sgl;
extern TFunAdrestct *tct;
extern "C" __declspec(dllexport) void _stdcall InitAPI(void* AFunAdresParamInp,void* AFunAdresParamOut,
void* Adresqcg,void* Adresrpr,void* Adresprm,void* Adresdif,void* Adressgl,void* Adrestct );
extern "C" __declspec(dllexport) void _stdcall InitAdresAPIInp(void);
extern "C" __declspec(dllexport) void _stdcall InitAdresAPIOut(void);
//extern "C" __declspec(dllexport) void _stdcall InitAdresAPISistemStruct(void *,
// void *,void *,void *,void *,void *,void *);
//extern "C" __declspec(dllexport) void _stdcall InitAdresAPISistemStructMessage(void *,int);
extern "C" __declspec(dllexport) void _stdcall ProcUser(void);
//extern "C" __declspec(dllexport) bool _stdcall UserFormFun(void);
//extern "C" __declspec(dllexport) bool _stdcall UserFormGrafChartFun(void);
extern "C" __declspec(dllexport) void _stdcall UserProcBeginInterval(void);
//extern "C" __declspec(dllexport) void _stdcall UserProcNameFileOut(void *);   // 2008_02_01
extern "C" __declspec(dllexport) void _stdcall UserProcEndInterval(void);
//extern  TFunAdresSistemStruct  *FunAdresSistemStruct;
//extern struct FlagPotokVizual *PtrFlagPotokVizualDLL;
//extern struct WinSistTab *PtrWinSistTabDLL;
//extern struct SisTable *PtrSisTableDLL;
//extern struct Pasp *PtrPaspDLL;
//extern struct Potok *PtrPotokDLL;
//extern struct Table *PtrTableDLL;
//extern struct TipPar *PtrTipParDLL;
//extern char    *PtrBlok_tarDLL;
//extern char    *PtrBlokRKDLL;
//extern struct Message *PtrMessageDLL;
//extern int KParamMessageDLL;
//extern char    *NameFileOutDLL;              // 2008_02_01


