//---------------------------------------------------------------------------

#ifndef LibraryClassH
#define LibraryClassH
//---------------------------------------------------------------------------
class LibraryClass
{
public:
      LibraryClass(char *);
      ~LibraryClass();
      GoAdresInDll();
void *FunAdresParamInp(char *);
void  FunAdresParamOut(char *NameParamTek,void *AParamTek,int ngr);
//HINSTANCE DllInstance;
//void (_stdcall *InitAPI)(void *,void *);
//void (_stdcall *InitAdresAPI)(void);
void *Ptr;
private:
};
extern PACKAGE LibraryClass *PtrLibraryClass;
#endif
