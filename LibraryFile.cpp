//---------------------------------------------------------------------------
#include <vcl.h>
//#include <windows.h>


#pragma hdrstop

//#include "FileMinimaxGlobalValue.h"
#include "Chart.h"
#include "LibraryFile.h"
#include <stdio.h>
#include <string.h>
//---------------------------------------------------------------------------

#pragma package(smart_init)
void (_stdcall *InitAPI)(void *,void *,void *,void *,void *,void *,void *,void *);
void (_stdcall *InitAdresAPIInp)(void);
void (_stdcall *InitAdresAPIOut)(void);
//void (_stdcall *InitAdresAPISistemStruct)(void *,void *,void *,void *,void *,void *,void *);
//void(_stdcall *InitAdresAPISistemStructMessage)(void *,int);
void (_stdcall *ProcUser)(void);
//bool (_stdcall *UserFormFun)(void);
//bool (_stdcall *UserFormGrafChartFun)(void);     // Для  Новой Графики Chart 2009_02_06
void (_stdcall *UserProcBeginInterval)(void);
void (_stdcall *UserProcEndInterval)(void);
void (_stdcall *UserProcNameFileOut)(void *);  // 2008_02_01
HINSTANCE dllInstance;
int KParamInp,KParamOut;
struct DllParRashet *PtrStructInp,*PtrStructOut;
char *BufParNo;
bool PriznakNoParDll;

//----------------------------------------------------------
int  FunOpenLibrary(char *NameLibraryTek)  // 2007_09_18
{
//dllInstance = LoadLibrary("Hablon.dll");
dllInstance = LoadLibrary(NameLibraryTek);
if(dllInstance == NULL) return(-1);  // 2007_09_18
InitAPI = (void(_stdcall *)(void *,void *,void *,void *,void *,void *,void *,void *))GetProcAddress(dllInstance,"InitAPI");         // Получить Адреса функций
InitAdresAPIInp = (void(_stdcall *)(void))GetProcAddress(dllInstance,"InitAdresAPIInp");  // из Программы пользователя
InitAdresAPIOut = (void(_stdcall *)(void))GetProcAddress(dllInstance,"InitAdresAPIOut");  // ( DLL )
//InitAdresAPISistemStruct = (void(_stdcall *)(void *,void *,void *,void *,void *,void *,void *))GetProcAddress(dllInstance,"InitAdresAPISistemStruct");
//InitAdresAPISistemStructMessage = (void(_stdcall *)(void *,int))GetProcAddress(dllInstance,"InitAdresAPISistemStructMessage");
ProcUser = (void(_stdcall *)(void))GetProcAddress(dllInstance,"ProcUser");                //
//UserFormFun = (bool(_stdcall *)(void))GetProcAddress(dllInstance,"UserFormFun");                //
//UserFormGrafChartFun = (bool(_stdcall *)(void))GetProcAddress(dllInstance,"UserFormGrafChartFun");                // 2009_02_06
UserProcBeginInterval = (void(_stdcall *)(void))GetProcAddress(dllInstance,"UserProcBeginInterval");                //
UserProcEndInterval = (void(_stdcall *)(void))GetProcAddress(dllInstance,"UserProcEndInterval");                //
UserProcNameFileOut = (void(_stdcall *)(void *))GetProcAddress(dllInstance,"UserProcNameFileOut"); // 2008_02_01
InitAPI(FunAdresParamInp,FunAdresParamOut,qcg,rpr,prm,dif,sgl,tct); // Передача Адресов функций в Программу пользователя
KParamOut=0; PriznakNoParDll = false;
BufParNo = new char [16384];
strcpy( BufParNo," следующие параметры в библиотеке отсутствуют в базе Библиотека закрывается \n");
PtrStructOut = new struct DllParRashet [1000];
InitAdresAPIOut();     // Запуск Программы пользователя по получению адресов расчетных параметров
return(0); // 2007_09_18
}
//----------------------------------------------------------
void  FunLibraryInitOutGlobalValue()
{
PtrGlobalFlagChart->KParamRashDllOut=KParamOut;
PtrGlobalFlagChart->PtrStructDllOut=PtrStructOut;
}
//----------------------------------------------------------
void  FunLibraryDeInitOutGlobalValue()
{
PtrGlobalFlagChart->KParamRashDllOut=0;
 delete[] PtrStructOut; PtrStructOut = NULL; PtrGlobalFlagChart->PtrStructDllOut = NULL;
 if(BufParNo != NULL) {delete[] BufParNo; BufParNo = NULL;}
}
//----------------------------------------------------------
void  FunCloseLibrary()
{
FreeLibrary(dllInstance);
}
//----------------------------------------------------------
void * FunAdresParamInp(char *NameParamTek,int NSis,int FlagFizKod)
{
// NameParamTek - идентификатор
// NSis - номер системы
// FlagFizKod =0 для передачи (получения) адреса физики
//            =1 для передачи (получения) адреса кода
int i,j,ii;
i=0;
while(strcmp(NameParamTek,(PtrPaspChart+i)->Ident) != 0 )
 {
 i++;
  if(i == IndexBlocFileDatXX.KStructPaspChart)
  {
  strcat( BufParNo," "); strcat( BufParNo,NameParamTek);
  PriznakNoParDll = true; return(&i);
  }
 }
 if(strcmp((PtrPaspChart+i)->Ident,"toporn") == 0 )
 ii= 0;
  for(j=0; j<4; j++)
  {
   if((PtrPaspChart+i)->NSis[j] == NSis) break;
   if(j == 3 )
   {
   strcat( BufParNo," "); strcat( BufParNo,NameParamTek);strcat( BufParNo," Неправильный Номер системы ");
   PriznakNoParDll = true; return(&i);
   }
  }
if(FlagFizKod == 0) return(&((PtrPaspChart+i)->Fiz[NSis-1]));
else if(FlagFizKod == 1) return(&((PtrPaspChart+i)->Kod[NSis-1]));
}
//----------------------------------------------------------
//void FunAdresParamOut(char *NameParamTek,void *AParamTek,int ngr,unsigned char tip)
void FunAdresParamOut(char *NameParamTek,void *AParamTek,char *NameParamOporn,unsigned char tip,char *Name)
{
char Buf[128];
float *ParamTek;
int ngrtek;
strcpy((PtrStructOut+KParamOut)->name,NameParamTek);
strcpy((PtrStructOut+KParamOut)->name1,NameParamOporn);
strcpy((PtrStructOut+KParamOut)->name2,Name);
(PtrStructOut+KParamOut)->adres=AParamTek;  //(PtrStructOut+KParamOut)->ngr=ngr;
(PtrStructOut+KParamOut)->tip=tip;
KParamOut++;
}
//----------------------------------------------------------
#include <math.h>
#include <float.h>
#pragma pack(1)

/*=====================================================================*/
#pragma pack(1)
float qcg(float *vpr)
 {
      float v1,v2,v3,v4,qcg1,a1,a2;
      a1=(float)1225.;
      a2=(float)10332.3;
      if(*vpr<a1)
      {
	v1=(float)1.+(float)0.2*(*vpr/a1)*(*vpr/a1);
	v2=(float)pow((double)v1,(double)3.5)-(float)1.;
	qcg1=a2*v2;
      }
      else
      {
	v1=*vpr/a1;
	v2=(float)166.92*v1*v1*v1*v1*v1*v1*v1;
	v3=(float)7.*v1*v1-(float)1.;
	v4=(float)pow((double)v3,(double)2.5);
	v1=v2/v4-(float)1.;
	qcg1=a2*v1;
      }
      return(qcg1);
 }
/*=====================================================================*/

/* podprogramm rpr */
 float rpr(float *h)
 {
 float a,b,c,d,e,f,ph;
 a=(float )11000.;
 b=(float )44300.;
 c=(float )5.256;
 d=(float )6340.;
 e=(float )10332.3;
 f=(float)2314.;
 if(*h<a)
	ph=e*(float)pow((double)(1.0-*h/b),(double)c);
 else
	ph=f*(float)exp((double)(a/d-*h/d));
 return (ph);
 }



/* podprogramma prm      */
 float prm(float *q,float *ph)
{
 double a,b,c;
 float a1=(float )1.892,a2=(float )2.55,a3=(float )4.1,
 a4=(float )6.15,a5=(float )8.1;
 if(*ph==(float)0) return((float)0);
 a=(*q+(*ph))/(*ph);
 if(a<a1)
 {
 if(a==0) a=1;
 c=pow((double)a,(double)0.285714);
 if(c<1) c=1;
 c=sqrt((float)((c-1)/(float)0.2));
 return ((float)c);
 }
 if(a>=a1&&(a)<a2)
 {
 b=(a-(float)1.85)/(float)0.75;
 c=(float)0.9806823+(float)0.3446655273*b-(float)0.08312988281*b*b+
   (float)0.021881103515*b*b*b;
 return((float)c);
 }
 if(a>=a2&&(a)<a3)
 {
 b=(a-(float )2.5)/(float )1.7;
 c=(float )1.2295+(float )0.5683*b-(float )0.0972*b*b;
 return((float)c);
 }
 if(a>=a3&&(a)<a4)
 {
 b=(a-(float)4)/(float)2.2;
 c=(float )1.6473999023+(float )0.52447509765*b-(float )0.08068847656*b*b+
   (float )0.015197753906*b*b*b;
 return((float)c);
 }
 if(a>=a4&&(a)<a5)
 {
 b=(a-(float)5.9)/(float )2.3;
 c=(float )2.050048828+(float )0.4370117187*b-(float )0.04431152343*b*b+
   (float )0.0056152343*b*b*b;
 return((float)c);
 }
 if(a>=a5)
 {
 b=(a-(float)8)/(float)5;
 c=(float)2.416625976+(float)0.8048095703*b-(float)0.1284179687*b*b+
   (float)0.02685546876*b*b*b;
 return((float)c);
 }
return(0);
}





/* podprogramma dif  */
// float f[],*df;
 float dif(float *f,float *df)
 {
 float b[10];
 b[0]=(float)0.058275058;
 b[1]=(float)-0.057109557;
 b[2]=(float)-0.1033411;
 b[3]=(float)-0.097707847;
 b[4]=(float)-0.057498057;
 b[5]=(float)0.057498057;
 b[6]=(float)0.097707847;
 b[7]=(float)0.1033411;
 b[8]=(float)0.057109557;
 b[9]=(float)-0.058275058;
 return((b[0]*f[0]+b[1]*f[1]+b[2]*f[2]+b[3]*f[3]+b[4]*f[4]+
	b[5]*f[6]+b[6]*f[7]+b[7]*f[8]+b[8]*f[9]+b[9]*f[10])/(*df));
 }



 /* podprogramma sgl  */
// float f[];
 float sgl(float *f)
 {
 float b[11];
 b[0]=(float)-0.083916084;
 b[1]=(float)0.020979021;
 b[2]=(float)0.1025641;
 b[3]=(float)0.16083916;
 b[4]=(float)0.19580419;
 b[5]=(float)0.20745921;
 b[6]=(float)0.19580419;
 b[7]=(float)0.16083916;
 b[8]=(float)0.1025641;
 b[9]=(float)0.020979021;
 b[10]=(float)-0.083916084;
 return(b[0]*f[0]+b[1]*f[1]+b[2]*f[2]+b[3]*f[3]+b[4]*f[4]+
    b[5]*f[5]+b[6]*f[6]+b[7]*f[7]+b[8]*f[8]+b[9]*f[9]+b[10]*f[10]);
 }


/* podprogramm tct */
 float tct(float *h)
 {
 float a;
 if(*h<(float )11000.)a=(float)288.15-(float)0.0065*(*h);else
	     a=(float)216.67;
 return (a);
 }


