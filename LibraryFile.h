//---------------------------------------------------------------------------
#pragma pack(1)
#ifndef LibraryFileH
#define LibraryFileH
//---------------------------------------------------------------------------
#define  KSTRUCTDLLPAR  1000;
extern int  FunOpenLibrary(char *);   
extern void  FunCloseLibrary();
extern void FunLibraryInitOutGlobalValue();
extern void FunLibraryDeInitOutGlobalValue();
extern void * FunAdresParamInp(char *,int,int);
extern void FunAdresParamOut(char *,void *,char*,unsigned char,char *);
extern float qcg(float *);
extern float rpr(float *);
extern float prm(float *,float *);
extern float dif(float *,float *);
extern float sgl(float *);
extern float tct(float *);

//extern void FunAdresSistemStruct(struct Pasp *);
extern void (_stdcall *InitAPI)(void *,void *,void *,void *,void *,void *,void *,void *);
extern void (_stdcall *InitAdresAPIInp)(void);
extern void (_stdcall *InitAdresAPIOut)(void);
//extern void (_stdcall *InitAdresAPISistemStruct)(void *,void *,void *,void *,void *,void *,void *);
//extern void(_stdcall *InitAdresAPISistemStructMessage)(void *,int);
extern void (_stdcall *ProcUser)(void);
//extern bool (_stdcall *UserFormFun)(void);
//extern bool (_stdcall *UserFormGrafChartFun)(void);
extern void (_stdcall *UserProcBeginInterval)(void);
extern void (_stdcall *UserProcEndInterval)(void);
extern void (_stdcall *UserProcNameFileOut)(void *);
extern char *BufParNo;
extern bool PriznakNoParDll;
#endif
 