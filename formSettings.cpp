//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "formSettings.h"
#include "stdio.h"
#include "Main.h"
#include <string>
#include <iostream>
#include "Parametr.h"
#include "Singleton.h"
#include "Chart.h"                    // Хромцов 2013_07_15

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma link "TeeComma"
#pragma resource "*.dfm"
TFormVievParameters *FormVievParameters;
typedef std::list<Parametr*>::iterator list_it;

extern std::list<Parametr*> mainList;

__fastcall TFormVievParameters::TFormVievParameters(TComponent* Owner)
        : TForm(Owner)
        , buttonDown(false)
{
}

//---- заполняет список существующих параметров
void TFormVievParameters::packStringGridParameters()
{
 StringGrid1->RowCount = 1;
 int c = 0;
 for(list_it i = mainList.begin(), e = mainList.end(); i != e; ++i)
 {
     ++StringGrid1->RowCount;
     StringGrid1->Cells[0][c++] = (*i)->Axis->Title->Caption;
     int a = StringGrid1->RowCount;
 }
 --StringGrid1->RowCount;
}

//-----
void TFormVievParameters::packListBoxParam(TListBox* listBox)
{
 int n = 0;
 ListBoxParam->Clear();
 for(list_it i = mainList.begin(), e = mainList.end(); i != e; ++i)
 {
     listBox->AddItem((*i)->Axis->Title->Caption, this);
     if( (*i) == Singleton::getInstance().getParametr() )
         listBox->Selected[n] = true;
     ++n;
 }
}

//---- заполняет список разделов
void TFormVievParameters::packListBoxRazdel()
{
 String nameRazdel = "0";
 ListBoxRazdel->Clear();
 for(int i = 0; i < IndexBlocFileDatXX.KStructRazdel; ++i)
 {
    nameRazdel = (PtrRazdel + i)->Razdel;
    ListBoxRazdel->AddItem(nameRazdel, this);
    ListBoxRazdel->Selected[i] = true;
 }
}

//--------- функция подбирает высоту строчки
void RowHeight(TStringGrid * G)
{
 int max = G->Canvas->TextHeight(G->Cells[2][1]);
 for(int row = 0; row < G->RowCount; ++row)
     G->RowHeights[row] = max + 4;
}

//----- конвертирует short int NSis[4] в строчку AnsiString
AnsiString SistemToString(const struct PaspChart *Pasp)
{
   AnsiString str;
   for(int j = 0; j < 4; ++j)
      if( Pasp->NSis[j] != -1)
      {
         str += Pasp->NSis[j];
         str += " ";
      }
   return str;
}

//--------  поиск   ------------------
void TFormVievParameters::Search(const AnsiString& text)
{
   int n = 0;
   if(ComboBox2->ItemIndex == 0)
     n = findName("Идентификатор");
   else
     n = findName("Наименование");

   std::string symbol = text.c_str();
   if(symbol.empty())
      return;

   using namespace std;
   const int k = StringGridMain->ColCount;

   string **a = new string*[k];
   for(int i = 0 ; i < k; ++i)
      a[i] = new string[Kpar];


   int i_r = findName("Раздел");
   int i_z = findName("Замер");
   int i_i = findName("Идентификатор");
   int i_n = findName("Наименование");
   int i_s = findName("Системы");

   // считывание во временный массив
   for(int j = 0; j < Kpar; ++j)
   {
      a[i_r][j] = (PtrPaspChart + j)->Razdel;
      a[i_z][j] = (PtrPaspChart + j)->Zamer;
      a[i_i][j] = (PtrPaspChart + j)->Ident;
      a[i_n][j] = (PtrPaspChart + j)->Name;
      a[i_s][j] = SistemToString(PtrPaspChart + j).c_str();
   }

   // сравнение и перестановка
   string *b = new string[k];
   for(int j = 0; j < Kpar; ++j)
   {
      if( (a[n][j]).compare(0, symbol.size(), symbol, 0, symbol.size()) == 0 )
      {
         // запоминамем строчку
         for(int i = 0; i < k; ++i)
            b[i] = a[i][j];

         // все элементы до a[n][j] увеличивают индекс на 1
         for(int m = 0; m < k; ++m)
            for(int i = j; i > 0; --i)
               a[m][i] = a[m][i-1];

         // ставим symbol на первое место
         for(int i = 0; i < k; ++i)
            a[i][0] = b[i];
      }
   }

   // отсортированный массив выводим в StringGrid
   for(int j = 0; j < Kpar; ++j)
   {
      StringGridMain->Cells[i_r][j+1] = a[i_r][j].c_str();
      StringGridMain->Cells[i_z][j+1] = a[i_z][j].c_str();
      StringGridMain->Cells[i_i][j+1] = a[i_i][j].c_str();
      StringGridMain->Cells[i_n][j+1] = a[i_n][j].c_str();
      StringGridMain->Cells[i_s][j+1] = a[i_s][j].c_str();
      StringGridMain->TopRow = 0;
   }
   delete[] b;
   delete[] a;
}


//---------------------------------------------------------------------------
//         активация формы
//---------------------------------------------------------------------------
void __fastcall TFormVievParameters::FormActivate(TObject *Sender)
{
 //===== Chart's tools =======
 exampleChart->Assign(Singleton::getInstance().getChart());

 if( !exampleChart->BottomAxis->Increment)
 {
     vertLineEdit->Enabled = false;
     vertLineDopEdit->Enabled = false;
     exampleChart->BottomAxis->Increment = 1;
     horizLineEdit->Enabled = false;
 }
 else
 {
     vertLineEdit->Enabled = true;
     vertLineDopEdit->Enabled = true;
     horizLineEdit->Enabled = true;
 }

 int temp = 0;
 temp = (exampleChart->LeftAxis->Maximum -
         exampleChart->LeftAxis->Minimum)/(exampleChart->LeftAxis->Increment) + 0.5;
 horizLineEdit->Text = IntToStr(temp - 1);

 temp = (exampleChart->BottomAxis->Maximum - exampleChart->BottomAxis->Minimum) /
                                         (exampleChart->BottomAxis->Increment) + 0.5;
 temp = temp ? (temp - 1) : temp;
 vertLineEdit->Text = temp;

 vertLineDopEdit->Text = exampleChart->BottomAxis->MinorTickCount;

 editLeft->Text   = exampleChart->MarginLeft;
 editTop->Text    = exampleChart->MarginTop;
 editRight->Text  = exampleChart->MarginRight;
 editBottom->Text = exampleChart->MarginBottom;
 feildColorBox->Selected = exampleChart->Color;
 

 //======== Information =========
 // Hint
 EditFlyingFile->Hint  = EditFlyingFile->Text;
 EditFormatFile->Hint  = EditFormatFile->Text;
 EditLibraryFile->Hint = EditLibraryFile->Text;
 EditINIFile->Hint     = EditINIFile->Text;
 // Text
 EditFlyingFile->Text  = Singleton::getInstance().iniFile->DataFile;
 EditFormatFile->Text  = Singleton::getInstance().iniFile->Format;
 EditLibraryFile->Text = Singleton::getInstance().iniFile->Library;
 if( ExtractFileName(Singleton::getInstance().iniFile->iniFileName) != "iniFileDefault.ini")
     EditINIFile->Text = Singleton::getInstance().iniFile->iniFileName;
 // Time
 if(&IndexBlocFileDatXX)
 {
     EditStartTime->Text = TDateTime(IndexBlocFileDatXX.TimeBegin * SEC);            
     EditEndTime->Text = TDateTime(IndexBlocFileDatXX.TimeEnd * SEC);
 }

 //======== Scales and graphts ======
 getAxisSettings();
 packListBoxParam(ListBoxParam);


 //======== Parameters ==========
 if(Global.strData == NULL)
     return;
 StringGridMain->RowCount = 0 ;
 Kpar = IndexBlocFileDatXX.KStructPaspChart;
 if( !Kpar)
     return;
 for(int i = 1; i < Kpar; ++i)
 {
     ++StringGridMain->RowCount;
     StringGridMain->Cells[0][i] = i;
     StringGridMain->Cells[1][i] = (PtrPaspChart + i - 1)->Razdel;
     StringGridMain->Cells[2][i] = (PtrPaspChart + i - 1)->Zamer;
     StringGridMain->Cells[3][i] = (PtrPaspChart + i - 1)->Ident;
     StringGridMain->Cells[4][i] = (PtrPaspChart + i - 1)->Name;
     StringGridMain->Cells[5][i] = SistemToString(PtrPaspChart + i - 1);
 }
 packListBoxRazdel();
 packStringGridParameters();
}


//---------------------------------------------------------------------------
// при вводе символа начинает осущетвляться ПОИСК
//--------------------------------------------------------------------------- 
void __fastcall TFormVievParameters::editSearchChange(TObject *Sender)
{
 Search(editSearch->Text);
}


//---------------------------------------------------------------------------
//      Выбор ячейки, если RK то появляется меню
//---------------------------------------------------------------------------
void __fastcall TFormVievParameters::StringGridMainSelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
 if(ARow == 0 || Global.strData == NULL)
     return;
 TekRow = ARow;
 unsigned identNum = findName("Идентификатор");

 //---  проверка на RK
 int j = 0;
 while( strcmp((PtrPaspChart + j)->Ident, StringGridMain->Cells[identNum][TekRow].c_str()) )
 {
    ++j;
    if(j >= IndexBlocFileDatXX.KStructPaspChart)
    {
       ShowMessage("Параметр "+StringGridMain->Cells[identNum][TekRow]+" не обнаружен");
       return;
    }
 }


 if((PtrPaspChart+j)->Tip == 0 || (PtrPaspChart+j)->Tip == 1)      // если параметр RK
 {
    fseek(Global.strData, IndexBlocFileDatXX.IndexStructRKChart, SEEK_SET);
    fread(PtrRKChart, sizeof(PtrRKChart), IndexBlocFileDatXX.KStructRKChart, Global.strData);  // читаем все паспорта RK команд
    int r=0;
    while( strcmp((PtrRKChart + r)->Ident, (PtrPaspChart + j)->Ident))
    {
       ++r;
       if(r >= IndexBlocFileDatXX.KStructRKChart)
       {
           ShowMessage("Параметр RK" + (String)((PtrRKChart+r)->Ident) + " не обнаружен");
           return;
       }
    }
    AnsiString mRK[33];      // массив обнулен
    int tekNRK = r;
    while(tekNRK)
    {
       mRK[(PtrRKChart + tekNRK)->NRazRK] = (PtrRKChart + tekNRK)->NameRK;
       tekNRK = (PtrRKChart + tekNRK)->NRK_SL;
    }
    ListBoxRK->Items->Clear();
    PanelRK->Visible = true;
    StringGridMain->Enabled = false;
    for(int i = 8; i < 32; ++i)
       ListBoxRK->Items->Add(IntToStr(i+1) + " " + mRK[i+1]);
 }
}


//---------------------------------------------------------------------------
//            двойным щелчком выбираем параметр для добавления
//----------------------------------------------------------------------------
void __fastcall TFormVievParameters::StringGridMainDblClick(TObject *Sender)
{
 if(TekRow == 0 || Global.strData == NULL)
     return;

 if(TekRow > Kpar)
    return;

 unsigned identNum = findName("Идентификатор");

 int j = 0;    // № pasp
 while( strcmp((PtrPaspChart + j)->Ident, StringGridMain->Cells[identNum][TekRow].c_str()))
 {
    ++j;
    if(j >= IndexBlocFileDatXX.KStructPaspChart)
    {
       ShowMessage("Параметр "+StringGridMain->Cells[identNum][TekRow]+" не обнаружен");
       return;
    }
 }
 Form1->CreateParametr(j);
 packStringGridParameters();
}



//---------------------------------------------------------------------------
//              запоминаем выбранную ячейку
//---------------------------------------------------------------------------
void __fastcall TFormVievParameters::StringGrid1SelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
 TekRow = ARow;
 String name = ((TStringGrid*)Sender)->Cells[0][TekRow];

 Singleton::getInstance().setParametr(Parametr::findParByAxisTitle(mainList, name));

 int pos = name.Pos(" ");
 if(pos)
     name = name.SubString(1, pos-1);

 for(int i = 1; i < StringGridMain->RowCount; ++i)
 {
     if(StringGridMain->Cells[findName("Идентификатор")][i] == name)
     {
         // подкрашиваем ячейку
         TGridRect myRect;
         myRect.Left = 0;
         myRect.Top  = i;
         myRect.Right = StringGridMain->ColCount;
         myRect.Bottom = i;
         StringGridMain->Selection = myRect;

         // перематываем таблицу на данный параметр
         if(i <= 2)   StringGridMain->TopRow = i;
         else         StringGridMain->TopRow = i - 2;
     }
 }
}


//---------------------------------------------------------------------------
//               Редактирование параметра
//---------------------------------------------------------------------------
void __fastcall TFormVievParameters::SpeedButtonRenameClick(TObject *Sender)
{
 PageControl1->ActivePage = TabSheet4;
 getAxisSettings();
 packListBoxParam(ListBoxParam);
}


//---------------------------------------------------------------------------
//    Разовые команды кнопка ОК
//---------------------------------------------------------------------------
void __fastcall TFormVievParameters::SpeedButtonOKClick(TObject *Sender)
{
 PanelRK->Visible = false;
 StringGrid1->Cells[0][StringGrid1->RowCount] = StringGridMain->Cells[findName("Идентификатор")][TekRow];
 ++StringGrid1->RowCount;

 unsigned identNum = findName("Идентификатор");
 int j = 0;
 while( strcmp((PtrPaspChart + j)->Ident, StringGridMain->Cells[identNum][TekRow].c_str()))
 {
    j++;
    if(j >= IndexBlocFileDatXX.KStructPaspChart)
    {
       ShowMessage("Параметр "+StringGridMain->Cells[identNum][TekRow]+" не обнаружен");
       return;
    }
 }
 Form1->CreateParametr(j);
 StringGridMain->Enabled = true;
 packStringGridParameters();
}


//---------------------------------------------------------------------------
//    Разовые команды кнопка Отмена
//---------------------------------------------------------------------------
void __fastcall TFormVievParameters::SpeedButtonCancelClick(TObject *Sender)
{
 PanelRK->Visible = false;
 StringGridMain->Enabled = true;
}


//---------------------------------------------------------------------------
// начальное расположение формы
//---------------------------------------------------------------------------
void __fastcall TFormVievParameters::FormCreate(TObject *Sender)
{
 FormVievParameters->Left   = Screen->Width / 8;
 FormVievParameters->Top    = 30;
 FormVievParameters->Height = Screen->Height - 60;
 FormVievParameters->Width  = Screen->Width * 3/4;

 StringGridMain->Cells[0][0] = "№";
 StringGridMain->Cells[1][0] = "Раздел";
 StringGridMain->Cells[2][0] = "Замер";
 StringGridMain->Cells[3][0] = "Идентификатор";
 StringGridMain->Cells[4][0] = "Наименование";
 StringGridMain->Cells[5][0] = "Системы";

 colMoved = 0;
}


//===========================================================================
void __fastcall TFormVievParameters::ButtonAllClick(TObject *Sender)
{
 StringGridMain->RowCount = 1;
 for(int k = 1; k < Kpar; ++k)
 {
     ++StringGridMain->RowCount;
     StringGridMain->Cells[0][k] = k;
     StringGridMain->Cells[findName("Раздел")       ][k] = (PtrPaspChart + k - 1)->Razdel;
     StringGridMain->Cells[findName("Замер")        ][k] = (PtrPaspChart + k - 1)->Zamer;
     StringGridMain->Cells[findName("Идентификатор")][k] = (PtrPaspChart + k - 1)->Ident;
     StringGridMain->Cells[findName("Наименование") ][k] = (PtrPaspChart + k - 1)->Name;
     StringGridMain->Cells[findName("Системы")      ][k] = SistemToString(PtrPaspChart + k - 1);
 }
 StringGridMain->Visible = true;
 for(int i = 0; i < ListBoxRazdel->Count; ++i)
     ListBoxRazdel->Selected[i] = true;
}


//===========================================================================
void TFormVievParameters::filterRazdel(const String& nameRazdel)
{
 int i = 0;
 for(i = 0; i < IndexBlocFileDatXX.KStructRazdel; ++i)
    if(nameRazdel == (PtrRazdel + i)->Razdel)
       break;
 int currPasp = (PtrRazdel + i)->NPasp1;

 bool first = false;
 int nRow = StringGridMain->RowCount;
 if(nRow == 1)
 {
    nRow = 0;
    first = true;
 }

 for(int j = nRow + 1; j < (PtrRazdel + i)->KPaspRazd + nRow; ++j)
 {
     ++StringGridMain->RowCount;
     StringGridMain->Cells[0][j] = j;
     StringGridMain->Cells[findName("Раздел")       ][j] = (PtrPaspChart + currPasp)->Razdel;
     StringGridMain->Cells[findName("Замер")        ][j] = (PtrPaspChart + currPasp)->Zamer;
     StringGridMain->Cells[findName("Идентификатор")][j] = (PtrPaspChart + currPasp)->Ident;
     StringGridMain->Cells[findName("Наименование") ][j] = (PtrPaspChart + currPasp)->Name;
     StringGridMain->Cells[findName("Системы")      ][j] = SistemToString(PtrPaspChart + currPasp);
     currPasp = (PtrPaspChart + currPasp)->N_pasps_razdel;
 }
 if(first)
     --StringGridMain->RowCount;
 StringGridMain->SetFocus();
}


//===========================================================================
void __fastcall TFormVievParameters::ListBoxRazdelClick(TObject *Sender)
{
 TListBox* list = (TListBox*)Sender;
 StringGridMain->Visible = true;
 StringGridMain->RowCount = 0;

 size_t countSelect(0);
 bool find = false;
 for(int i = 0; i < list->Count; ++i)
 {
     if(list->Selected[i])
     {
         filterRazdel(list->Items->Strings[i]);
         find = true;
         ++countSelect;
     }
 }
 StringGridMain->Visible = (find) ? true : false;

 // выбран один параметр
 if((list->Count - countSelect) == 1)
 {
     StringGridMain->RowCount = 0;
     for(int i = 0; i < list->Count; ++i)
     {
         list->Selected[i] = !list->Selected[i];
         if(list->Selected[i])
            filterRazdel(list->Items->Strings[i]);
     }
 }
 ++StringGridMain->RowCount;
}


//============================================================================
void __fastcall TFormVievParameters::Splitter2Moved(TObject *Sender)
{
 // для красоты, чтоб кнопки были такой же ширины что и панель выбора раздела
 ButtonAll->Width = PanelOfButtonAll->Width - 3;
}


//=========================================================================
void __fastcall TFormVievParameters::StringGrid1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 StringGrid1->BeginDrag(false, 5);
 // вычисляем строчку, на которую нажали
 unsigned height = StringGrid1->RowHeights[0] + 1;
 fromNumRow = Y / height;
}

//=========================================================================
void __fastcall TFormVievParameters::StringGrid1DragOver(TObject *Sender,
      TObject *Source, int X, int Y, TDragState State, bool &Accept)
{
 if(Sender != Source)
 {
     // from main table
 }
 else
     Accept = true;
}


//==========================================================================
//    перемещение наименований по вертикали в левой таблице
//==========================================================================
void __fastcall TFormVievParameters::StringGrid1DragDrop(TObject *Sender,
      TObject *Source, int X, int Y)
{
 if(Sender == Source)
 {
     // вычисляем строчку в которую хотим перенести
     int height = StringGrid1->RowHeights[0] + 1;   // line height = 1
     int toNumRow = Y / height;

     AnsiString fromStr = StringGrid1->Cells[0][fromNumRow];

     if(fromNumRow > toNumRow)
         for(int i = fromNumRow; i > toNumRow; --i)
             StringGrid1->Cells[0][i] = StringGrid1->Cells[0][i-1];

     if(fromNumRow < toNumRow)
         for(int i = fromNumRow; i < toNumRow; ++i)
             StringGrid1->Cells[0][i] = StringGrid1->Cells[0][i+1];

     StringGrid1->Cells[0][toNumRow] = fromStr;
 }
 else
 {
     // from main table
     if(Global.strData == NULL)
         return;
     int top = StringGridMain->Selection.Top;
     int bottom = StringGridMain->Selection.Bottom;
     for(int i = top; i < bottom + 1; ++i)
     {
         TekRow = i;
         if(! TekRow || TekRow > Kpar)
             return;

         int j = 0;
         int numIdent = findName("Идентификатор");
         while( strcmp((PtrPaspChart + j)->Ident, StringGridMain->Cells[numIdent][TekRow].c_str()))
         {
             ++j;
             if(j >= IndexBlocFileDatXX.KStructPaspChart)
             {
                 ShowMessage("Параметр "+StringGridMain->Cells[numIdent][TekRow]+" не обнаружен");
                 return;
             }
         }
         Form1->CreateParametr(j);
     }
     packStringGridParameters();
 }
}


//===========================================================================
//  для раскраски наименований параметров в левой таблице
//===========================================================================
void __fastcall TFormVievParameters::StringGrid1DrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
 for(std::list<Parametr*>::iterator i = mainList.begin(); i != mainList.end(); ++i)
     if(StringGrid1->Cells[0][ARow] == (*i)->Axis->Title->Caption)
     {
         StringGrid1->Canvas->FillRect(Rect);
         StringGrid1->Canvas->Font->Color = (*i)->Axis->Axis->Color;
         StringGrid1->Canvas->TextOutA(Rect.Left + 3, Rect.Top + 3, StringGrid1->Cells[ACol][ARow]);
     }
}


//===========================================================================
//   узнаем номер столбца на который щелкнул пользователь (координата X)
//===========================================================================
int TFormVievParameters::numCol(unsigned sumWidth, unsigned num, unsigned X)
{
  sumWidth += StringGridMain->ColWidths[num];
  if(X < sumWidth)
      return num;
  else
  {
      ++num;
      return numCol(sumWidth, num, X);
  }
}


//==========================================================================
void __fastcall TFormVievParameters::StringGridMainMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 buttonDown = false;
 if(colMoved || X <= 0)
     return;

 choiceCol = numCol(0, 0, X);

 // сортировка не работает когда выбрано несклько разделов
 int temp(0);
 for(int i=0; i<ListBoxRazdel->Count; ++i)
     if(ListBoxRazdel->Selected[i])
         ++temp;
 if(ListBoxRazdel->Count != temp)
     return;

 // сортировка по алфавиту
 if( Y < StringGridMain->RowHeights[0])          // если нажали на первую строку
 {
     std::string *str_i = new std::string[Kpar + 1];
     std::string *str_n = new std::string[Kpar + 1];
     std::string *str_r = new std::string[Kpar + 1];
     std::string *str_z = new std::string[Kpar + 1];
     std::string *str_s = new std::string[Kpar + 1];


     for(int i = 0; i < Kpar; ++i)
     {
         str_i[i] = (PtrPaspChart + i)->Ident;
         str_n[i] = (PtrPaspChart + i)->Name;
         str_r[i] = (PtrPaspChart + i)->Razdel;
         str_z[i] = (PtrPaspChart + i)->Zamer;
         String s = SistemToString(PtrPaspChart + i);
         str_s[i] = s.c_str();
     }

     // сортировка по идентификатору
     if(choiceCol == findName("Идентификатор"))
     {
         for(int i=0; i < Kpar; ++i)
         {
             int mins = i;
             for(int j = i + 1; j < Kpar; ++j)
             {
                 if( (str_i[mins]).compare(str_i[j]) > 0)
                 {                                              // если s1 > s2 (т.е. s1 ниже по алфавиту чем s2)
                     std::string buff = str_i[mins];
                     str_i[mins] = str_i[j];
                     str_i[j] = buff;

                     buff = str_n[mins];
                     str_n[mins] = str_n[j];
                     str_n[j] = buff;

                     buff = str_r[mins];
                     str_r[mins] = str_r[j];
                     str_r[j] = buff;

                     buff = str_z[mins];
                     str_z[mins] = str_z[j];
                     str_z[j] = buff;

                     buff = str_s[mins];
                     str_s[mins] = str_s[j];
                     str_s[j] = buff;
                 }
             }
         }
     }

     // сортировка по имени
     if(choiceCol == findName("Наименование"))
     {
         for(int i=0; i < Kpar; i++)
         {
             int mins = i;
             for(int j = i + 1; j < Kpar; ++j)
             {
                if( (str_n[mins]).compare(str_n[j]) > 0)
                {                                         // если s1 > s2 (т.е. s1 ниже по алфавиту чем s2)
                    std::string buff = str_i[mins];
                    str_i[mins] = str_i[j];
                    str_i[j] = buff;

                    buff = str_n[mins];
                    str_n[mins] = str_n[j];
                    str_n[j] = buff;

                    buff = str_r[mins];
                    str_r[mins] = str_r[j];
                    str_r[j] = buff;

                    buff = str_z[mins];
                    str_z[mins] = str_z[j];
                    str_z[j] = buff;

                    buff = str_s[mins];
                    str_s[mins] = str_s[j];
                    str_s[j] = buff;
                }
             }
         }
     }

     // сортировка по разделу
     if(choiceCol == findName("Раздел"))
     {
         for(int i=0; i < Kpar; i++)
         {
             int mins = i;
             for(int j = i + 1; j < Kpar; ++j)
             {
                if( (str_r[mins]).compare(str_r[j]) > 0)
                {                                         // если s1 > s2 (т.е. s1 ниже по алфавиту чем s2)
                    std::string buff = str_i[mins];
                    str_i[mins] = str_i[j];
                    str_i[j] = buff;

                    buff = str_n[mins];
                    str_n[mins] = str_n[j];
                    str_n[j] = buff;

                    buff = str_r[mins];
                    str_r[mins] = str_r[j];
                    str_r[j] = buff;

                    buff = str_z[mins];
                    str_z[mins] = str_z[j];
                    str_z[j] = buff;

                    buff = str_s[mins];
                    str_s[mins] = str_s[j];
                    str_s[j] = buff;
                }
             }
         }
     }
     
     // отсортированный массив выводим в таблицу
     for(int i=1; i < Kpar; i++)
     {
         StringGridMain->Cells[findName("Идентификатор") ][i] = str_i[i-1].c_str();
         StringGridMain->Cells[findName("Наименование" ) ][i] = str_n[i-1].c_str();
         StringGridMain->Cells[findName("Раздел"       ) ][i] = str_r[i-1].c_str();
         StringGridMain->Cells[findName("Замер"        ) ][i] = str_z[i-1].c_str();
         StringGridMain->Cells[findName("Системы"      ) ][i] = str_s[i-1].c_str();
     }
     delete[] str_i;
     delete[] str_n;
     delete[] str_r;
     delete[] str_z;
     delete[] str_s;
 }

 StringGridMain->Visible = false;
 StringGridMain->Visible = true;
}


//============================================================================
void __fastcall TFormVievParameters::StringGridMainDrawCell(
      TObject *Sender, int ACol, int ARow, TRect &Rect,
      TGridDrawState State)
{
 if(ACol == choiceCol && ARow == 0 && !colMoved)
 {
     StringGridMain->Canvas->Brush->Color = clMenuHighlight;
     StringGridMain->Canvas->FillRect(Rect);
     StringGridMain->Canvas->TextOut(Rect.Left+5, Rect.Top+2, StringGridMain->Cells[ACol][ARow]);

     StringGridMain->Canvas->Font->Name = "Wingdings 3";
     StringGridMain->Canvas->TextOut(Rect.Right-14, Rect.Top+5, "q");
     StringGridMain->Canvas->Font->Name = "MS Sans Serif";

     RowHeight(StringGridMain);
 }
}


//============================================================================
void __fastcall TFormVievParameters::StringGridMainColumnMoved(
      TObject *Sender, int FromIndex, int ToIndex)
{
 colMoved = true;
}


//============================================================================
void __fastcall TFormVievParameters::StringGridMainMouseDown(
      TObject *Sender, TMouseButton Button, TShiftState Shift, int X,
      int Y)
{
 colMoved = false;
 buttonDown = true;
 //if( Button == mbRight)
 //    StringGridMain->BeginDrag(false, 10);
}


//===========================================================================
//    ищет столбец с идентификатором
//===========================================================================
int TFormVievParameters::findName(const AnsiString& s)
{
 for(int i = 0; i < StringGridMain->ColCount; ++i)
     if(StringGridMain->Cells[i][0] == s)
        return i;
 return 0;
}


//-----------------------------------------------------------------------------
//    копируем наименования параметров на главную форму
//-----------------------------------------------------------------------------
void __fastcall TFormVievParameters::FormClose(TObject *Sender,
      TCloseAction &Action)
{
 Singleton::getInstance().setVectorOfPar(StringGrid1);
}


//---------------------------------------------------------------------------
//     удаляем выбранную ячейку
//---------------------------------------------------------------------------
void __fastcall TFormVievParameters::SpeedButtonDeleteClick(
      TObject *Sender)
{
 //DeleteParametr(currentPar);
 for(int i = TekRow; i < StringGrid1->RowCount; ++i)          
     StringGrid1->Cells[0][i] = StringGrid1->Cells[0][i+1];
 --StringGrid1->RowCount;
}


//---------------------------------------------------------------------------
//          ОК
//---------------------------------------------------------------------------
void __fastcall TFormVievParameters::okButtonClick(TObject *Sender)
{
 Singleton::getInstance().setChart(exampleChart);
 setAxisSettings();
 FormVievParameters->ModalResult = 1;
}

//---------------------------------------------------------------------------
//        Отмена
//---------------------------------------------------------------------------
void __fastcall TFormVievParameters::noButtonClick(TObject *Sender)
{
 FormVievParameters->ModalResult = 2;
}


void TFormVievParameters::setAxisSettings()
{
 if( !Singleton::getInstance().getParametr())
     return;
 Parametr* curPar = Singleton::getInstance().getParametr();

 int stepcount = EditStepCount->Text.ToInt();
 float step = StrToFloat(TrueSeparator(EditStep->Text));
 float min = StrToFloat(TrueSeparator(EditMin->Text));
 float max = min + step* stepcount;

 TColor color = ColorBox1->Selected;

 curPar->Axis->Title->Caption = EditIdent->Text;
 curPar->Axis->SetMinMax(min, max);
 curPar->Axis->Increment = step;
 curPar->Axis->StartPosition =
 curPar->Axis->EndPosition - (exampleChart->LeftAxis->Increment)*stepcount;

 curPar->Axis->Axis->Color = color;
 curPar->Axis->Ticks->Color = color;
 curPar->Axis->Title->Font->Color = color;
 curPar->Series->Marks->Visible = CheckBoxMarks->Checked;
 curPar->MarkerSymbol = EditMark->Text;

 curPar->Series->Pen->Color = color;
 curPar->Series->Pen->Width = ComboBoxLineWidth->ItemIndex;

 switch(ComboBoxLineType->ItemIndex)
 {
    case 0:  curPar->Series->Pen->Style = psSolid;       break;
    case 1:  curPar->Series->Pen->Style = psDash;        break;
    case 2:  curPar->Series->Pen->Style = psDot;         break;
    case 3:  curPar->Series->Pen->Style = psDashDot;     break;
    case 4:  curPar->Series->Pen->Style = psDashDotDot;  break;
    case 5:  curPar->Series->Pen->Style = psClear;       break;
    case 6:  curPar->Series->Pen->Style = psInsideFrame; break;
    default: ShowMessage("Error FormVievParameters::ComboBoxLineType - no style");
 }
 if(curPar->Series->Pen->Width != 1 &&
    curPar->Series->Pen->Style != psSolid)
    ShowMessage("Cтили линии со штрихами и пунктирами доступны только при толщине = 1");

 //установка нового номера системы
 SetNSis(curPar->Series, ComboBoxNSys->ItemIndex + 1);
}


//---------------------------------------------------------------------------
//      Изменение полей показательного Chart
//---------------------------------------------------------------------------
void __fastcall TFormVievParameters::editLeftChange(TObject *Sender)
{
 if(editLeft->Text == "") return;
 exampleChart->MarginLeft = StrToInt(editLeft->Text);
}
//---------------------------------------------------------------------------
void __fastcall TFormVievParameters::editTopChange(TObject *Sender)
{
 if(editTop->Text == "") return;
 exampleChart->MarginTop = StrToInt(editTop->Text);
}
//---------------------------------------------------------------------------
void __fastcall TFormVievParameters::editRightChange(TObject *Sender)
{
 if(editRight->Text == "") return;
 exampleChart->MarginRight = StrToInt(editRight->Text);
}
//---------------------------------------------------------------------------
void __fastcall TFormVievParameters::editBottomChange(TObject *Sender)
{
 if(editBottom->Text == "") return;
 exampleChart->MarginBottom = StrToInt(editBottom->Text);
}

//---------------------------------------------------------------------------
void __fastcall TFormVievParameters::horizLineEditChange(TObject *Sender)
{
 if(horizLineEdit->Text == "" || horizLineEdit->Text.ToInt() <= 0)
     return;
 int a = (exampleChart->LeftAxis->Maximum - exampleChart->LeftAxis->Minimum);
 int b = horizLineEdit->Text.ToInt() + 1;
 double i = (double)a / (double)b;
 exampleChart->LeftAxis->Increment = i;
 exampleChart->Refresh();
}

//---------------------------------------------------------------------------
void __fastcall TFormVievParameters::vertLineEditChange(TObject *Sender)
{
 if(vertLineEdit->Text == "" || vertLineEdit->Text.ToInt() <= 0)
    return;
 Form1->countMainVertLine = vertLineEdit->Text.ToInt();
 double i =
 ((exampleChart->BottomAxis->Maximum - exampleChart->BottomAxis->Minimum))
                                          / (vertLineEdit->Text.ToDouble() + 1);
 exampleChart->BottomAxis->Increment = i;
}

//---------------------------------------------------------------------------
void __fastcall TFormVievParameters::vertLineDopEditChange(TObject *Sender)
{
 if(vertLineDopEdit->Text == "" || vertLineDopEdit->Text.ToInt() < 0)
     return;
 exampleChart->BottomAxis->MinorTickCount = vertLineDopEdit->Text.ToInt();
}
//---------------------------------------------------------------------------


void __fastcall TFormVievParameters::TabSheet1Resize(TObject *Sender)
{
 // размеры exampleChart пропорциональны главному Chart
 exampleChart->Width = TabSheet1->Width - Panel9->Width - 5;
 exampleChart->Height = Singleton::getInstance().getKChart() * exampleChart->Width;
 exampleChart->Top    = (TabSheet1->Height - 10 - Panel10->Height - exampleChart->Height)/2 + 15;
 exampleChart->Left   = Panel9->Width + 3;
}


void __fastcall TFormVievParameters::ComboBoxLineTypeDrawItem(
      TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State)
{
 ComboBoxLineType->Canvas->FillRect(Rect);
 switch(Index)
 {
    case 0:  ComboBoxLineType->Canvas->Pen->Style = psSolid;       break;
    case 1:  ComboBoxLineType->Canvas->Pen->Style = psDash;        break;
    case 2:  ComboBoxLineType->Canvas->Pen->Style = psDot;         break;
    case 3:  ComboBoxLineType->Canvas->Pen->Style = psDashDot;     break;
    case 4:  ComboBoxLineType->Canvas->Pen->Style = psDashDotDot;  break;
    case 5:  ComboBoxLineType->Canvas->Pen->Style = psClear;       break;
    case 6:  ComboBoxLineType->Canvas->Pen->Style = psInsideFrame; break;
    default: ShowMessage("Mistake::ComboBoxLineTypeDrawItem");
 }
 ComboBoxLineType->Canvas->MoveTo(Rect.Left + 5, Rect.Top + 5);
 ComboBoxLineType->Canvas->LineTo(Rect.Right - 5, Rect.Top + 5);        
}
//---------------------------------------------------------------------------

void __fastcall TFormVievParameters::ComboBoxLineTypeSelect(
      TObject *Sender)
{
 ComboBoxLineType->Enabled = false;
 ComboBoxLineType->Enabled = true;        
}
//---------------------------------------------------------------------------

void __fastcall TFormVievParameters::EditStepCountKeyPress(TObject *Sender,
      char &Key)
{
 OnlyNumbers(Key, 0);      // без запятых
}

void __fastcall TFormVievParameters::EditMinKeyPress(TObject *Sender,
      char &Key)
{
 OnlyNumbers(Key, 1);
}



//---------------------------------------------------------------------------
//    Запрещаем вводить буквы
//---------------------------------------------------------------------------
void TFormVievParameters::OnlyNumbers(char &Key, bool Separator)
{
 Set <Char, 0, 255> Dig;
 if(! Separator )
 {
    if(! (Dig <<'0'<<'1'<<'2'<<'3'<<'4'<<'5'<<'6'
              <<'7'<<'8'<<'9'<<'\b').Contains(Key))
      {Key = 0; Beep(); }
 }
 else
 {
    if(! (Dig <<'0'<<'1'<<'2'<<'3'<<'4'<<'5'<<'6'
              <<'7'<<'8'<<'9'<<'.'<<','<<'-'<<'\b').Contains(Key))
      {Key = 0; Beep(); }
 }
}

//---------------------------------------------------------------------------
//  Функция устанавливает правильный разделитель целой и дробной части
//  независимо от того что ввел пользователь "." или ","
//---------------------------------------------------------------------------
String TFormVievParameters::TrueSeparator(const AnsiString& textEdit)
{
 AnsiString sep = AnsiString(DecimalSeparator);  // текущий разделитель
 int i = 0;
 if ( i != textEdit.Pos(",") )
 {     //запятая
    i = textEdit.Pos(",");
    if(sep == ",")
       return textEdit;
    else
       return textEdit.SubString(1, i - 1) + "." +
              textEdit.SubString(i + 1, 255);
 }
 else if(i != textEdit.Pos("."))
 {     // точка
    i = textEdit.Pos(".");
    if(sep == ".")
       return textEdit;
    else
       return textEdit.SubString(1, i - 1) + "," +
              textEdit.SubString(i + 1, 255);
 }
 else  // число без разделителя
    return textEdit;
}

//---------------------------------------------------------------------------

String TFormVievParameters::SetNSis(TChartSeries* Line, int NSis)
{
   int i = Line->Title.Pos(" ");
   AnsiString S2 = Line->Title.SubString(1, i - 1) + IntToStr(NSis) +
                   Line->Title.SubString(i + 1, 255);
   return S2;
}


void __fastcall TFormVievParameters::feildColorBoxChange(TObject *Sender)
{
 exampleChart->Color = feildColorBox->Selected;
 exampleChart->LeftAxis->LabelsFont->Color = feildColorBox->Selected;
}
//---------------------------------------------------------------------------


void __fastcall TFormVievParameters::TabSheet2Resize(TObject *Sender)
{
 int w = (StringGridMain->Width - 10) / 27;
 StringGridMain->ColWidths[0] = w;
 StringGridMain->ColWidths[findName("Раздел")       ] = 4*w;
 StringGridMain->ColWidths[findName("Замер")        ] = 2*w;
 StringGridMain->ColWidths[findName("Идентификатор")] = 3*w;
 StringGridMain->ColWidths[findName("Наименование") ] = 14*w;
 StringGridMain->ColWidths[findName("Системы")      ] = 2*w;
 ButtonAll->Width = PanelOfButtonAll->Width - 3;
 StringGrid1->ColWidths[0] = StringGrid1->Width - 4;
}



void TFormVievParameters::getAxisSettings()
{
 if( !Singleton::getInstance().getParametr())
 {
     GroupBox1->Enabled = false;
     GroupBox2->Enabled = false;
     GroupBox3->Enabled = false;
     GroupBox4->Enabled = false;
 }
 else
 {
     GroupBox1->Enabled = true;
     GroupBox2->Enabled = true;
     GroupBox3->Enabled = true;
     GroupBox4->Enabled = true;
     Parametr* curPar = Singleton::getInstance().getParametr();

     if(curPar)
     {
         // мин, макс, инкремент, цвет оси
         EditMin->Text = FormatFloat("0.00", curPar->Axis->Minimum);
         EditStep->Text = FormatFloat("0.00", curPar->Axis->Increment);
         int n =  (curPar->Axis->Maximum -
                   curPar->Axis->Minimum) /
                   curPar->Axis->Increment + 0.5;
         EditStepCount->Text = n;
         ColorBox1->Selected = curPar->Axis->Axis->Color;

         // идентификатор, наименование
         EditIdent->Text = curPar->Axis->Title->Caption;
         EditName->Text = curPar->Series->Title;
         EditMainName->Text = String((PtrPaspChart + curPar->NPasp)->Name);

         //номер системы
         ComboBoxNSys->Items->Clear();                  // сколько систем ,
         for(int i = 0; i < (curPar->KolSis); ++i)      // столько и пунктов
             ComboBoxNSys->Items->Add(i+1);             // в выпадающем списке
         ComboBoxNSys->ItemIndex = curPar->NSis - 1;

         // маркеры
         EditMark->Text = curPar->MarkerSymbol;

         //---- разовые команда
         if(curPar->NRK != -1 && ((PtrPaspChart + curPar->NPasp)->Tip == 0 || (PtrPaspChart + curPar->NPasp)->Tip == 1))
            EditMainName->Text = curPar->NameRK;

         // тип и толщина линии
         if(curPar->Series->Count() < 1)
         {
             ComboBoxLineType->Enabled = false;
             ComboBoxLineWidth->Enabled = false;
             return;
         }
         else
         {
             ComboBoxLineType->Enabled = true;
             switch(curPar->Series->Pen->Style)
             {
                 case psSolid:       ComboBoxLineType->ItemIndex = 0;  break;
                 case psDash:        ComboBoxLineType->ItemIndex = 1;  break;
                 case psDot:         ComboBoxLineType->ItemIndex = 2;  break;
                 case psDashDot:     ComboBoxLineType->ItemIndex = 3;  break;
                 case psDashDotDot:  ComboBoxLineType->ItemIndex = 4;  break;
                 case psClear:       ComboBoxLineType->ItemIndex = 5;  break;
                 case psInsideFrame: ComboBoxLineType->ItemIndex = 6;  break;
                 default:ShowMessage("Mistake in difinition SeriesLine style");
             }
             ComboBoxLineWidth->Enabled = true;
             switch(curPar->Series->Pen->Width)
             {
                 case 0:  ComboBoxLineWidth->ItemIndex = 0;  break;
                 case 1:  ComboBoxLineWidth->ItemIndex = 1;  break;
                 case 2:  ComboBoxLineWidth->ItemIndex = 2;  break;
                 case 3:  ComboBoxLineWidth->ItemIndex = 3;  break;
                 case 4:  ComboBoxLineWidth->ItemIndex = 4;  break;
                 case 5:  ComboBoxLineWidth->ItemIndex = 5;  break;
                 case 6:  ComboBoxLineWidth->ItemIndex = 6;  break;
                 default:ShowMessage("Mistake in difintion SeriesLine Pen width");
             }
         }
     }
 }
}


//-----------------------------------------------------------------------------
//          выбор параметра из списка
//-----------------------------------------------------------------------------
void __fastcall TFormVievParameters::ListBoxParamClick(TObject *Sender)
{
 String namePar = ListBoxParam->Items->Strings[ListBoxParam->ItemIndex];
 if(Singleton::getInstance().getParametr())
     if(namePar != Singleton::getInstance().getParametr()->Axis->Title->Caption)
         setAxisSettings();

 for(std::list<Parametr*>::iterator i = mainList.begin(); i != mainList.end(); ++i)
    if( namePar == (*i)->Axis->Title->Caption )
        Singleton::getInstance().setParametr(*i);

 if(Singleton::getInstance().getParametr())
     getAxisSettings();
}


void __fastcall TFormVievParameters::StringGridMainMouseMove(
      TObject *Sender, TShiftState Shift, int X, int Y)
{
 static bool drag = false;
 if (X < 20 && buttonDown && !drag)
 {
     colMoved = false;
     StringGridMain->BeginDrag(false, 10);
     drag = true;
 }
}
//---------------------------------------------------------------------------

void __fastcall TFormVievParameters::StringGridMainDragOver(
      TObject *Sender, TObject *Source, int X, int Y, TDragState State,
      bool &Accept)
{
 Accept = false;
}
//---------------------------------------------------------------------------


void __fastcall TFormVievParameters::EditIdentChange(TObject *Sender)
{
 int n = (EditIdent->Text).Length();
 if ( n > 16 )
 {
     EditIdent->Text = (EditIdent->Text).SubString(1, 16);
     ShowMessage("Ограничение по количеству символов. 16 ");
 }
}
//---------------------------------------------------------------------------



