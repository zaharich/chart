//---------------------------------------------------------------------------

#ifndef FileClassRashetParamH
#define FileClassRashetParamH
#define COMPILER_R  ":\\MinimaxWin_ВЕРСИЯ_48FM\\Chart\\Компилятор_расч_пар"
#define DLL_R  ":\\MinimaxWin_ВЕРСИЯ_48FM\\Chart\\DLL"                            // Путь к дополнительным модулям  для получения динамической библиотеки расчетных параметров  
//---------------------------------------------------------------------------
class ClassRashetParam
{
public:
//      ClassRashetParam(char *);
      ClassRashetParam(String);
      ~ClassRashetParam();
private:
fun1(void);                 // Анализ текстового файла с рачетными параметрами
fun2(void);                 // Формирование символьного файла DLL.cpp
fun3(void);                 // компиляция, компоновка,создание файла .DLL
bool FunExit(bool);         //
//fun4(void);                 // создание файла .DLL
TStringList *TextFile;      // текстовый файл с рачетными параметрами
TStringList *OutIdent;      // Список выходных(расчетных) идентификаторов
TStringList *InpIdent;      // Список входных( из паспортов) идентификаторов
TStringList *FunOut;        // Список выходных(расчетных) функций InitAdresAPIOut
TStringList *FunInp;        // Список входных функций InitAdresAPIInp
TStringList *FunUser;       // Список алгоритма ProcUser
String NameFileTxt;         // Имя текстового файла с рачетными параметрами
String NameFileDLLCpp;      // Имя выходного символьного  файла библиотеки с рачетными параметрами
TStringList *CompilerCfg;     // Переменные окружения  компиятора bcc32.cfg
TStringList *LinkerCfg;       // Переменные окружения компоновщика ilink32.cfg
TStringList *BatFile;         // Пакетный файл rashet.bat
STARTUPINFO StartUpInfo;
PROCESS_INFORMATION lpProcessInformation;
SECURITY_ATTRIBUTES ProcessAtr,TheardAtr;
};
extern PACKAGE ClassRashetParam *PtrClassRashetParam;
#endif
