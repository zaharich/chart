//---------------------------------------------------------------------------
#pragma hdrstop

#include "log.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#include "log.h"

Log& Log::instance(){
  static Log* log = new Log();
  return *log;
}


//--------------------------------------------------------------------------
void Log::createPathToLogFile(){
  _fileName = new char[255];
  char tmp[255];
  GetCurrentDirectory(255, tmp);
  strcpy(_fileName, "");
  strcat(_fileName, tmp);
  strcat(_fileName, "\\Log\\");
  int b = 56;

  char* data = new char[80];

  strcpy(data, getFormatDate());
  strcat(data, ".txt");

  strcat(_fileName, data);
  Write("Start working. Class Log has been created asdfasdfasdfasdfasdfasdfasdfasdfasdfasdf");
  delete data;
}

//---------------------------------------------------------------------------
char* Log::getTime()
{
 time_t rawtime;
 time( &rawtime );   // текущая дата в секундах
 return ctime( &rawtime );
}

//---------------------------------------------------------------------------
char* Log::getFormatDate(){

  struct tm* timeinfo;
  char buffer [80];

  // time_t - предназначен для хранения времени. От содержит каледарное время
  // в форме, в которой оно возвращается функцией time() и обрабатывается функцией difftime()
  time_t rawtime;

  // time - возвращает текущие дату/время в виде time_t
  time (&rawtime);

  // localtime - convert time_t to struct tm as local time
  timeinfo = localtime(&rawtime);

  strftime (buffer,80,"%Y-%m-%d",timeinfo);
  String test = buffer;
  return buffer;
}

//---------------------------------------------------------------------------
void Log::Write(char* logline)
{
  if( FILE *f = fopen(_fileName, "a") )
  {
    fprintf(f, "%-50s : %30s ", logline, getTime());
    fclose(f);
  }
  else
    ShowMessage("Can't open file " + String(_fileName) + ". from class Log");
}

//---------------------------------------------------------------------------
Log::~Log()
{
  Write("Destroy class Log. The end of session");
  delete _fileName;
}

//http://www.pvsm.ru/programmirovanie/36008
