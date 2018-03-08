//---------------------------------------------------------------------------


#include <vcl.h>
#include <dir.h>
#pragma hdrstop
#include <stdio.h>
#include "Chart.h"

#include "FileClassRashetParam.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//===========================================================================
ClassRashetParam *PtrClassRashetParam = 0;
//ClassRashetParam::ClassRashetParam( char *name_file)
ClassRashetParam::ClassRashetParam( String name_file)
{
bool i;
String Stroka;
NameFileTxt = name_file;
TextFile = new  TStringList();
OutIdent = new  TStringList();
InpIdent = new  TStringList();
FunInp = new  TStringList();
FunOut = new  TStringList();
FunUser = new  TStringList();
CompilerCfg = new  TStringList();
LinkerCfg = new  TStringList();
BatFile = new  TStringList();
TextFile->LoadFromFile(name_file);
fun1();
fun2();
fun3();
}
//===========================================================================
ClassRashetParam::~ClassRashetParam()
{
}
//===========================================================================
ClassRashetParam::fun1(void)
{
String Stroka,StrokaOut,StrokaInp,Stroka1,StrokaInp1;
char StrokaChar[256],StrokaCharFun[256],ch,NSis,*c1,IdentNSis[64],Ident[64];
int kstrok,i,LIdent,j,index,count,indexBegin,indexEnd,LStroka,k;
bool Priznak;
Priznak = false;
//ch= 'A';
//ch = 'a';
//strcpy(StrokaChar,"0123456789AaBbWwYyXxZzUu _=+-/*():;@#$%^&");
kstrok = TextFile->Count;
  for(i=0; i<kstrok; i++)
  {
  Priznak = false;
  Stroka = TextFile->Strings[i];  Stroka1 = Stroka;
  strcpy(StrokaChar,Stroka.c_str());
  LStroka = Stroka.Length();
  LIdent = Stroka.AnsiPos("=");  LIdent--;
  StrokaOut = Stroka.SubString(1,LIdent);
  OutIdent->Add(StrokaOut);
  index = LIdent+1; count = LStroka - LIdent;
  StrokaOut = Stroka.SubString(index,count);
    while(index <LStroka)
    {
    NSis = '1';
    while((StrokaChar[index] < 'A') || (StrokaChar[index] > 'z')) { index++; if(index >= LStroka) { Priznak = true; break; }}
    if(Priznak == true) break;
    indexBegin = index;
    index++;
    while((StrokaChar[index] >= '0') && (StrokaChar[index] <= 'z')) index++;
    indexEnd = index;
    StrokaInp = Stroka.SubString(indexBegin+1,indexEnd - indexBegin);
    StrokaInp1 = StrokaInp; StrokaInp1.Insert("*",1);
    InpIdent->Add(StrokaInp1);
    strcpy(IdentNSis,StrokaInp.c_str());
    strcpy(Ident,IdentNSis);
    c1=strrchr(Ident,(int)'_');  if(c1 != NULL) { NSis = *(c1+1);  *c1='\0'; }
    StrokaInp = StrokaInp + " = (float *)FunAdresParamInp(\"" + Ident + "\"," + NSis + ",0);";
//p067 = (float *)FunAdresParamInp("p067",1,0);                  // ПРИМЕР
    FunInp->Add(StrokaInp);
    k = Stroka1.AnsiPos(IdentNSis); Stroka1.Insert("*",k);
    }
   StrokaOut = "FunAdresParamOut(\"";
   StrokaOut = StrokaOut + OutIdent->Strings[i] + "\",(void *)&" + OutIdent->Strings[i] + ",\"" + Ident + "\",'f',\"Расчетный параметр\");";
//FunAdresParamOut("p067_r",(void *)&p067_r,"p067",'f',"Частота вращения ротора НД дв1 расч.");  // ПРИМЕР
   FunOut->Add(StrokaOut);
   StrokaInp = "if(*";
   StrokaInp = StrokaInp + IdentNSis + " != 0xffffffff)  " + Stroka1 + "     else  " + OutIdent->Strings[i] + " = 0xffffffff;";
   FunUser->Add(StrokaInp);
  }
}
//============================================================================
//===========================================================================
ClassRashetParam::fun2(void)
{
FILE *strcpp;
int i;
NameFileDLLCpp = NameFileTxt;
i = NameFileDLLCpp.AnsiPos(".");  NameFileDLLCpp.Delete(i,4); NameFileDLLCpp.Insert(".cpp",i);
strcpp = fopen(NameFileDLLCpp.c_str(),"w");
fprintf(strcpp,"#include \"Hablon.h\" \n#include <stdio.h>\n#include <math.h>\n\n");
fprintf(strcpp,"float ");
 for(i=0; i < InpIdent->Count; i++)
 {
 fprintf(strcpp,InpIdent->Strings[i].c_str());
 if(i < (InpIdent->Count - 1)) fprintf(strcpp,","); else fprintf(strcpp,";");
 if((i%20 == 0) && (i != 0))  fprintf(strcpp,"\n");
 }
fprintf(strcpp,"\n\n");

fprintf(strcpp,"float ");
 for(i=0; i < OutIdent->Count; i++)
 {
 fprintf(strcpp,OutIdent->Strings[i].c_str());
 if(i < (OutIdent->Count - 1)) fprintf(strcpp,","); else fprintf(strcpp,";");
 if((i%20 == 0) && (i != 0))  fprintf(strcpp,"\n");
 }
 fprintf(strcpp,"\n\n");

fprintf(strcpp,"void _stdcall InitAdresAPIInp(void)\n");
fprintf(strcpp,"{\n");
fprintf(strcpp,"int i,j,k;\n");
 for(i=0; i < FunInp->Count; i++)
 {
 fprintf(strcpp,FunInp->Strings[i].c_str()); fprintf(strcpp,"\n");
 }
fprintf(strcpp,"return;\n");
fprintf(strcpp,"}");
fprintf(strcpp,"\n\n");

fprintf(strcpp,"void _stdcall InitAdresAPIOut(void)\n");
fprintf(strcpp,"{\n");
fprintf(strcpp,"int i,j,k;\n");
 for(i=0; i < FunOut->Count; i++)
 {
 fprintf(strcpp,FunOut->Strings[i].c_str()); fprintf(strcpp,"\n");
 }
fprintf(strcpp,"return;\n");
fprintf(strcpp,"}");
fprintf(strcpp,"\n\n");

fprintf(strcpp,"void _stdcall ProcUser(void)\n");
fprintf(strcpp,"{\n");
fprintf(strcpp,"int i,j,k;\n");
 for(i=0; i < FunUser->Count; i++)
 {
 fprintf(strcpp,FunUser->Strings[i].c_str()); fprintf(strcpp,"\n");
 }
fprintf(strcpp,"return;\n");
fprintf(strcpp,"}");
fprintf(strcpp,"\n");
fclose(strcpp);
//-----------------------------------------------------------------------------
}
//===========================================================================
ClassRashetParam::fun3(void)
{
char APchar[254],APcharName[254];
String  StrokaTek,StrokaTek1;
int i,NumberDisk;
char path[1024],path1[1024],*c1;
strcpy(path,"X:\\");
NumberDisk=getdisk() +'A';
path[0] = NumberDisk;
//i=getcurdir(0,path);
//i=getcurdir(0,path+3);
//strcpy(path,ChartDir.c_str());
//PtrGlobalFlagChart->RashetParPathCompiler = (char)NumberDisk;
PtrGlobalFlagChart->RashetParPathCompiler[0] = NumberDisk;
//strcat(PtrGlobalFlagChart->RashetParPathCompiler,":\\MinimaxWin_ВЕРСИЯ_48FM\\Chart\\Компилятор_расч_пар");
strcat(PtrGlobalFlagChart->RashetParPathCompiler,COMPILER_R);
//strcpy(path,PtrGlobalFlagChart->RashetParPathCompiler);
//c1=strrchr(path,(int)'\\');    *c1='\0';
//strcat(path,"\\БИБЛИОТЕКА РАСЧЕТНЫХ ПАРАМЕТРОВ");
//strcat(path,"\\DLL");
//strcpy(PtrGlobalFlagChart->RashetUserLib,path);

PtrGlobalFlagChart->RashetUserLib[0] = NumberDisk;
strcat(PtrGlobalFlagChart->RashetUserLib,DLL_R);

StrokaTek = "-I\"";
StrokaTek = StrokaTek + PtrGlobalFlagChart->RashetParPathCompiler + "\\Include\";"
 + "\"" + PtrGlobalFlagChart->RashetParPathCompiler + "\\Include\\vcl\"";
CompilerCfg->Add(StrokaTek);
StrokaTek = "-L\"";
StrokaTek = StrokaTek + PtrGlobalFlagChart->RashetParPathCompiler + "\\lib\";" + "\""
 + PtrGlobalFlagChart->RashetParPathCompiler + "\\lib\\obj\";"
 + "\"" +  + PtrGlobalFlagChart->RashetParPathCompiler + "\\lib\\release\";" + "\""
 + PtrGlobalFlagChart->RashetParPathCompiler + "\\lib\\PSDK\"";
CompilerCfg->Add(StrokaTek);
StrokaTek = PtrGlobalFlagChart->RashetParPathCompiler;
StrokaTek = StrokaTek + "\\bcc32.cfg";
CompilerCfg->SaveToFile(StrokaTek);

StrokaTek = "-L\"";
StrokaTek = StrokaTek + PtrGlobalFlagChart->RashetParPathCompiler + "\\lib\";" + "\""
+ PtrGlobalFlagChart->RashetParPathCompiler + "\\lib\\obj\";"
+ "\"" +  + PtrGlobalFlagChart->RashetParPathCompiler + "\\lib\\release\"";
LinkerCfg->Add(StrokaTek);
StrokaTek = PtrGlobalFlagChart->RashetParPathCompiler;
StrokaTek = StrokaTek + "\\ilink32.cfg";
LinkerCfg->SaveToFile(StrokaTek);

//StrokaTek = "@echo off ";
//BatFile->Add(StrokaTek);

StrokaTek = "path ";
StrokaTek = StrokaTek + PtrGlobalFlagChart->RashetParPathCompiler + "\\bin;%path%";
BatFile->Add(StrokaTek);

strcpy(path,PtrGlobalFlagChart->RashetUserLib);
strcat(path,"\\Rashet.cpp");

CopyFile(NameFileDLLCpp.c_str(),path,0);
DeleteFile(NameFileDLLCpp);
//MoveFileEx(NameFileDLLCpp.c_str(),path,0);
strcpy(path,"Rashet.cpp");

c1=strrchr(path,(int)'.');    *c1='\0';
StrokaTek = "set app=";
StrokaTek = StrokaTek + path;
BatFile->Add(StrokaTek);
StrokaTek = "if exist %app%.dll del %app%.dll";
BatFile->Add(StrokaTek);
StrokaTek = "if exist %app%.obj del %app%.obj";
BatFile->Add(StrokaTek);
//StrokaTek = "bcc32.exe -I%include% -L%lib%  -Od -3 -a1 -tWU -tWD %app%.cpp ";
StrokaTek = "bcc32.exe -I%include% -L%lib%  -Od -3 -a1 -tWU -tWD %app%.cpp user.cpp > errout.txt";
BatFile->Add(StrokaTek);
StrokaTek = "rem -Od    -оптимзации нет (NONE)             опция компилятора";
BatFile->Add(StrokaTek);
StrokaTek = "rem -3     -инструкции для процессора 80386   опция компилятора";
BatFile->Add(StrokaTek);
StrokaTek = "rem -a1    -упаковка (#pragma pack(1)) Byte   опция компилятора";
BatFile->Add(StrokaTek);
StrokaTek = "rem -tWU   -Поддержка Unicode строк           опция компилятора";
BatFile->Add(StrokaTek);
StrokaTek = "rem -tWD   -Для компиляции DLL библиотек      опция компилятора";
BatFile->Add(StrokaTek);
//StrokaTek = PtrGlobalFlagChart->RashetParPathCompiler;
StrokaTek = PtrGlobalFlagChart->RashetUserLib;
StrokaTek = StrokaTek + "\\Rashet.bat";
//StrokaTek = StrokaTek + "\\UnitKons.exe";
BatFile->SaveToFile(StrokaTek);

     StrokaTek1 = GetCurrentDir();
     SetCurrentDir(PtrGlobalFlagChart->RashetUserLib);

CreateProcess(NULL,StrokaTek.c_str(),&ProcessAtr,&TheardAtr,false,CREATE_DEFAULT_ERROR_MODE,
              NULL,NULL,&StartUpInfo,&lpProcessInformation);
if(lpProcessInformation.hProcess != NULL) { FunExit(false); Sleep(500); }

strcpy(path,"Rashet.dll");
strcpy(path1,NameFileDLLCpp.c_str());
c1=strrchr(path1,(int)'.');    *c1='\0';
strcat(path1,".dll");
CopyFile(path,path1,0);
strcpy(PtrGlobalFlagChart->NameDllRashetLibrary,path1);
SetCurrentDir(StrokaTek1);

}
//---------------------------------------------------------------------------
bool  ClassRashetParam::FunExit(bool Flag)
{
DWORD lpExitCode,lpExitCodeThread;
//m1: GetExitThread = GetExitCodeThread(lpProcessInformation.hThread,&lpExitCodeThread);
// GetExit = GetExitCodeProcess(lpProcessInformation.hProcess,&lpExitCode);
m1:GetExitCodeThread(lpProcessInformation.hThread,&lpExitCodeThread);
 GetExitCodeProcess(lpProcessInformation.hProcess,&lpExitCode);
 if(lpExitCode == STILL_ACTIVE) { Sleep(1000);  goto m1; }
 TerminateProcess(lpProcessInformation.hProcess,lpExitCode);
}

