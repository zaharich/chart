//---------------------------------------------------------------------------

#ifndef PathSettingsH
#define PathSettingsH

#include "inifiles.hpp"
//---------------------------------------------------------------------------

class CustomIniFile
{
 private:
    TIniFile *iniFileAny;
    AnsiString iniFileNameAny;

    void showErrMessage(int error);
    void checkIniPath();
    void createIniFile();

 public:
    AnsiString pathToDataFile;
    AnsiString pathToFormatka;
    AnsiString pathToLibrary;

    AnsiString initDirFlyingDialog;
    AnsiString initDirInitDialog;
    AnsiString initDirFormatkaDialog;
    AnsiString initDirLibraryDialog;

    int fileError;

    IniSettings(AnsiString& nameIniAny);
    ~IniSettings();

    void writeIniFile();
    void readIniFile();
    void readDirPath();
    void openAnyIni(AnsiString& nameIni);

};


#endif
