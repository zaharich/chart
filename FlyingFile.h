//---------------------------------------------------------------------------
#ifndef FlyingFileH
#define FlyingFileH
//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>

#include "chart.h"


class FlyingFile
{
  private:
    // pointers to start of array structurs in file
    FILE* strData;                                                              // pointer to structure FILE of flying file
    HANDLE hFileData;
    struct IndexBlocFileDatXX IndexBlocFileDatXX;                               // ױנמלצמג 2013_07)15
    struct Razdel *PtrRazdel;                                                   // ױנמלצמג 2013_07)15
    struct PaspChart *PtrPaspChart;                                             // ױנמלצמג 2013_07)15
    struct RKChart *PtrRKChart;                                                 //  2013_10_11
    struct ParamXX *PtrParamXXChart;                                            //  2013_10_11
    struct TimXX TimXX;                                                         //  2013_10_11
    struct GlobalFlagChart GlobalFlagChart, *PtrGlobalFlagChart;                // ױנמלצמג 2013_07_15
    int kStructRazd;
    int kPasp;                                                                  // count of pasports
    int kStructRK;

    int sourceMinTime;
    int sourceMaxTime;                                                          // time start|end of record flying data

  public:
    // init
    void initFlyingFile(const String& pathToFlyingFile);

    // find
    int findPaspByIdent(const String& ident);
    int findPaspRKByIdent(const String& ident);
    int findNStructRKByIdentNRK(const String& ident, const int nRK);

    // return number of structure RK by ident

    // getters
    FILE* getStrData(){return strData;};
    
    HANDLE getHandleFile(){return hFileData;};
    void setHandleFile(HANDLE h){hFileData = h;};

    PaspChart* getPtrPaspChart(){return PtrPaspChart;};
    Razdel* getPtrRazlel(){return PtrRazdel;};
    RKChart* getPtrRKChart(){return PtrRKChart;};
    struct IndexBlocFileDatXX getIndexBlocFileDatXX(){return IndexBlocFileDatXX;};

    int getKPasp(){return kPasp;};
    int getKRazdel(){return kStructRazd;};
    int getKStructRK(){return kStructRK;};

    int getSourceMinTime(){return sourceMinTime;};
    int getSourceMaxTime(){return sourceMaxTime;};

    // Singleton
    static FlyingFile& Instance();

  protected:
    // private constructor, copy constructor and assignment operator
    FlyingFile(){strData = NULL;};
    FlyingFile(const &FlyingFile);
    FlyingFile& operator=(&FlyingFile);
};
#endif
