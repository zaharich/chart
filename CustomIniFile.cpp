#include "CustomIniFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

 String CustomIniFile::dataDir   = "C:\\";
 String CustomIniFile::formatDir = "C:\\";
 String CustomIniFile::iniDir    = "C:\\";
 String CustomIniFile::libDir    = "C:\\";

// на вход должны подаваться проверенные данные
CustomIniFile::CustomIniFile(String& nameIni)
                : iniFileName(nameIni)
                , fileError(0)
{
 iniFile = new TIniFile(iniFileName);
 readFromIniFile();
}


//===========================================================================
void CustomIniFile::openIni(const String& nameIni)
{
 if(! FileExists(nameIni)){
     ShowMessage("Файла настройки \"" + nameIni + "\" не найден!");
     return;
 }

 fileError = 0;
 checkIniPath(nameIni);
 if(fileError)
     return;

 delete iniFile;                 // delete old iniFile

 iniFileName = nameIni;
 iniFile = new TIniFile(nameIni);
 readFromIniFile();
}


//===========================================================================
CustomIniFile::~CustomIniFile()
{
 delete iniFile;
}


//===========================================================================
void CustomIniFile::readFromIniFile()
{
 DataFile = iniFile->ReadString("Start", "Flying" , "");
 Format   = iniFile->ReadString("Start", "Format" , "");
 Library  = iniFile->ReadString("Start", "Library", "");

 dataDir   = iniFile->ReadString("Dir", "initDirFlying" , "C:\\");
 formatDir = iniFile->ReadString("Dir", "initDirFormat" , "C:\\");
 iniDir    = iniFile->ReadString("Dir", "initDirInit"   , "C:\\");
 libDir    = iniFile->ReadString("Dir", "initDirLibrary", "C:\\");
 checkIniPath(iniFileName);
}


//===========================================================================
void CustomIniFile::writeToIniFile()
{
 iniFile->WriteString("Start", "Flying"  , DataFile);
 iniFile->WriteString("Start", "Format", Format);
 iniFile->WriteString("Start", "Library" , "Library_temporary_don't_use");

 iniFile->WriteString("Dir", "initDirFlying" , dataDir);
 iniFile->WriteString("Dir", "initDirFormat" , formatDir);
 iniFile->WriteString("Dir", "initDirInit"   , iniDir);
 iniFile->WriteString("Dir", "initDirLibrary", libDir);
}


//===========================================================================
void CustomIniFile::checkIniPath(const String& nameIni)
{
 // заводим временную переменную, для проверки корректности путей
 TIniFile *iniTemp = new TIniFile(nameIni);

 if(! FileExists(nameIni))
     showErrMessage(ANYINI_ERR, iniTemp);

 String s1 = iniTemp->ReadString("Start", "Flying", "");
 if(s1 == "" )
     fileError = DATAFILE_ERR;
 else if(! FileExists(s1))
          {
           showErrMessage(DATAFILE_ERR, iniTemp);
           fileError = DATAFILE_ERR;
          }

 String s2 = iniTemp->ReadString("Start", "Format" , "");
 if(s2 == "" || s2 == ".tee")
     fileError = FORMATKA_ERR;
 else if(! DirectoryExists(s2))
          {
           showErrMessage(FORMATKA_ERR, iniTemp);
           fileError = FORMATKA_ERR;
          }

 //if(! FileExists(iniTemp->ReadString("Start", "Library", "")))
 //    showErrMessage(LIBRARY_ERR);

 delete iniTemp;
}


//===========================================================================
void CustomIniFile::showErrMessage(int error, TIniFile* iniFile)
{
 String s = "0";
 switch(error)
 {
     case NO_ERR      :
         fileError = NO_ERR; return;
     case ANYINI_ERR  :
         s = iniFile->FileName;
         ShowMessage("Файл инициализации \"" + s + "\" не найден.(IF)");
         fileError = ANYINI_ERR; return;
     case DATAFILE_ERR:
         s = iniFile->ReadString("Start", "Flying", "");
         ShowMessage("Файл полета \"" + s + "\" не найден.(IF)");
         fileError = DATAFILE_ERR; return;
     case FORMATKA_ERR:
         s = iniFile->ReadString("Start", "Format", "");
         ShowMessage("Файл формата \"" + Format + "\" не найден.(IF)");
         fileError = FORMATKA_ERR; return;
     case LIBRARY_ERR :
         s = iniFile->ReadString("Start", "Library", "");
         ShowMessage("Файл бибилиотеки \"" + s + "\" не найден.(IF)");
         fileError = LIBRARY_ERR; return;
 }
}


//===========================================================================
void CustomIniFile::saveIniAs(const String& nameIni)
{
 if(! FileExists(nameIni)){
     FILE* F;
     if((F = fopen(nameIni.c_str(), "w+")) == NULL){
         ShowMessage("Файл инициализации \"" + nameIni + "\" не удается открыть/создать(CIF.SIA)");
         return;
     }
     fclose(F);
 }
 // delete old iniFile and create new file (new iniFile stand current iniFile)
 delete iniFile;
 iniFile = new TIniFile(nameIni);
 iniFileName = nameIni;
 fileError = 0;

 writeToIniFile();
 ShowMessage("Настройка сохранена в файле \"" + nameIni +"\"");
}

