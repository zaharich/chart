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
    String iniFileName;
    String DataFile;
    String Format;
    String Library;
    
    int fileError;

    static String dataDir;
    static String formatDir;
    static String iniDir;
    static String libDir;

    CustomIniFile(String& nameIniAny);
    ~CustomIniFile();

    void writeToIniFile();
    void readFromIniFile();
    void openIni(const String& nameIni);
    void saveIniAs(const String& nameIni);
};
#endif
