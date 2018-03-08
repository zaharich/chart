//---------------------------------------------------------------------------

#pragma hdrstop
#include "PathSettings.h"
#include "Dialogs.hpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

enum {NO_ERR, MAININI_ERR, ANYINI_ERR, DATAFILE_ERR, FORMATKA_ERR, LIBRARY_ERR};


IniSettings::IniSettings(AnsiString& nameIniAny)
{
 iniFileNameAny = nameIniAny;
 if(! FileExists(iniFileNameAny))
 {
     showErrMessage(ANYINI_ERR);
     return;
 }
 iniFileAny = new TIniFile(iniFileNameAny);

 // readPath
 readIniFile();
 //-------
 readDirPath();
}


//===========================================================================
void IniSettings::openAnyIni(AnsiString& nameIni)
{
 if(! FileExists(nameIni)
 {
     showErrMessage(ANYINI_ERR);
     return;
 }
 
 delete iniFileAny;
 iniFileAny = new TIniFile(nameIni);
 readIniFile();
 readDirPath();
}


//===========================================================================
IniSettings::~IniSettings()
{
 delete iniFileMain;
 delete iniFileAny;
}


//===========================================================================
void IniSettings::readIniFile()
{
 pathToDataFile = iniFileAny->ReadString("Start", "Flying", "");
 pathToFormatka = iniFileAny->ReadString("Start", "Formatka", "");
 pathToLibrary = iniFileAny->ReadString("Start", "Library", "");
 checkIniPath();
}


//===========================================================================
void IniSettings::readDirPath()
{
 initDirFlyingDialog = iniFileMain->ReadString("Dir", "initDirFlying", "C:\\");
 initDirInitDialog = iniFileMain->ReadString("Dir", "initDirInit", "C:\\");
 initDirFormatkaDialog = iniFileMain->ReadString("Dir", "initDirFormatka", "C:\\");
 initDirLibraryDialog = iniFileMain->ReadString("Dir", "initDirLibrary", "C:\\");
}


//===========================================================================
void IniSettings::writeIniFile()
{
 iniFileMain->WriteString("Files", "LastFileIni", iniFileNameAny);
 iniFileAny->WriteString("Start", "Flying"  , pathToDataFile);
 iniFileAny->WriteString("Start", "Formatka", pathToFormatka);
 iniFileAny->WriteString("Start", "Library" , "Library_temporary_don't_use");

 iniFileAny->WriteString("Dir", "Init", initDirInitDialog);
 iniFileAny->WriteString("Dir", "Flying", initDirFlyingDialog);
 iniFileAny->WriteString("Dir", "Formatka", initDirFormatkaDialog);
 iniFileAny->WriteString("Dir", "Library", initDirLibraryDialog);
}


//===========================================================================
void IniSettings::checkIniPath()
{
 if(! FileExists(pathToDataFile))
     showErrMessage(DATAFILE_ERR);

 if(! DirectoryExists(pathToFormatka))
     showErrMessage(FORMATKA_ERR);

 if(! FileExists(pathToLibrary))
     showErrMessage(LIBRARY_ERR);
}


//===========================================================================
void IniSettings::showErrMessage(int error)
{
 switch(error)
 {
     case NO_ERR      :
         fileError = NO_ERR; return;
     case MAININI_ERR :
         ShowMessage("Файл \"" + iniFileNameMain + "\" не найден.");
         fileError = MAININI_ERR; return;
     case ANYINI_ERR  :
         ShowMessage("Файл \"" + iniFileNameAny + "\" не найден.");
         fileError = ANYINI_ERR; return;
     case DATAFILE_ERR:
         ShowMessage("Файл \"" + pathToDataFile + "\" не найден.");
         fileError = DATAFILE_ERR; return;
     case FORMATKA_ERR:
         ShowMessage("Файл \"" + pathToFormatka + "\" не найден.");
         fileError = FORMATKA_ERR; return;
     case LIBRARY_ERR :
         ShowMessage("Файл \"" + pathToLibrary + "\" не найден.");
         fileError = LIBRARY_ERR; return;
 }
}

