//---------------------------------------------------------------------------
#pragma package(smart_init)
#include "LogFile.h"

Log* Log::_instance = 0;
const char* Log::logFileName = "D:\\Резервное_копирование__\\2017.02.01\\Режимы\\logFile.txt";

//===========================================================================
Log* Log::Instance(){
 if(_instance == 0){
    _instance = new Log;
 }
 return _instance;
}


//===========================================================================
Log::Log(const Log& src){
  
}


//============================================================================
/*Log::Log(const char* fileName){
  char tmp[255];
  GetCurrentDirectory(255, tmp);
  logFileName = strcat(tmp, fileName);

  if( !FileExists(AnsiString(logFileName)) )
    logFileName = strcat(tmp, "\\LogFile.txt");
}  */


//=============================================================================
Log::Log()
{
 //char tmp[255];
 //GetCurrentDirectory(255, tmp);
 //logFileName = strcat(tmp, "\\LogFile.txt");
 write("Log file create");
}


//============================================================================
Log::~Log()
{
 write("The end of the  log file");
}


//=============================================================================
char* Log::getTime()
{
 time_t* t;
 time(t);   // текущая дата в секундах
 return ctime(t);
}


//============================================================================
void Log::write(const char* str)
{
 /*FILE *f;
 if(f = fopen(logFileName, "a+"))
 {
    char* tempStr = "";
    strncat(tempStr, getTime(), strlen(getTime()) - 1);
    strcat(tempStr, str);
    fwrite(str, sizeof(char), strlen(tempStr), f);
    fclose(f);
 }    */

 //C++ style  don't work...
 /*ofstream f(logFileName, ios::out | ios::app);
 f << getTime() << " : " << str << std::endl;
 f.close();  */
}










