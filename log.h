//---------------------------------------------------------------------------

#ifndef logH
#define logH
//---------------------------------------------------------------------------
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <system.hpp>
#include <sysUtils.hpp>
#include <dialogs.hpp>

class Log {
public:
    void Write(char* logline);
    static Log& instance();

private:
    char* _fileName;
    char* getTime();
    char* getFormatDate();
    void createPathToLogFile();

    // anybody can not create object
    Log(){createPathToLogFile();};
    ~Log();

    // ban copy-constructor and operation =
    Log(const Log&);
    Log& operator = (const Log&);
};

#endif
