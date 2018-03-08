#pragma once
//---------------------------------------------------------------------------
#ifndef CustomIniFileH
#define CustomIniFileH
//---------------------------------------------------------------------------
#include "inifiles.hpp"
#include <stdio.h>
#include <Dialogs.hpp>


class CustomIniFile
{
 private:
    TIniFile *iniFile;

    void showErrMessage(int error, TIniFile* iniFile);
    void checkIniPath(const String& nameIni);

    enum {NO_ERR, ANYINI_ERR, DATAFILE_ERR, FORMATKA_ERR, LIBRARY_ERR};
    
 public:
    AnsiString iniFileName;
    AnsiString DataFile;
    AnsiString Format;
    AnsiString Library;
    
    int fileError;

    static AnsiString dataDir;
    static AnsiString formatDir;
    static AnsiString iniDir;
    static AnsiString libDir;

    CustomIniFile(AnsiString& nameIniAny);
    ~CustomIniFile();

    void writeToIniFile();
    void readFromIniFile();
    void openIni(const AnsiString& nameIni);
    void saveIniAs(const AnsiString& nameIni);
};
#endif
