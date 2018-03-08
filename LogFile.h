#pragma once
//---------------------------------------------------------------------------
#ifndef LogFileH
#define LogFileH

#include <fstream.h>
#include <stdio.h>
#include <ctime>
#include <SysUtils.hpp>

class Log
{
 public:
    static Log* Instance();
    void write(const char* p);

 protected:
    Log();
    Log(const Log& src);
    const Log& operator = (const Log& src);

 private:
    static Log* _instance;
    static const char* logFileName;

    std::ofstream f;

    ~Log();
    char* getTime();
};
//---------------------------------------------------------------------------
#endif
