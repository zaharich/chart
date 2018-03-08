//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "stdio.h"                              
#include <string>
#include <iostream>

#include "UnitSettings.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma link "TeeComma"
#pragma resource "*.dfm"

 const double SEC = 1/86400.;  //  1/86400 часть суток равная 1 сек
 TFormSettings *FormSettings;
 typedef std::list<Parametr*>::iterator list_it;

 __fastcall TFormSettings::TFormSettings(TComponent* Owner)
        : TForm(Owner)
        , buttonDown(false)
        , buttonPress(false)
 {
 }


//---------------------------------------------------------------------------
//        начальное расположение формы
//---------------------------------------------------------------------------
void __fastcall TFormSettings::FormCreate(TObject *Sender)
{
 FormSettings->Left   = Screen->Width / 8;
 FormSettings->Top    = 30;
 FormSettings->Height = Screen->Height - 60;
 FormSettings->Width  = Screen->Width * 3/4;

 StringGridMain->Cells[0][0] = "№";
 StringGridMain->Cells[1][0] = "Раздел";
 StringGridMain->Cells[2][0] = "Замер";
 StringGridMain->Cells[3][0] = "Идентификатор";
 StringGridMain->Cells[4][0] = "Наименование";
 StringGridMain->Cells[5][0] = "Системы";

 colMoved = 0;
}


//---------------------------------------------------------------------------
//         активация формы
//---------------------------------------------------------------------------
void __fastcall TFormSettings::FormActivate(TObject *Sender)
{
 LoadChartFromFile(exampleChart, Form1->SourceDir + "\\~copybufferchart");
 //Form1->mainChart->setChartSettings(exampleChart, Form1->mainChart->getChart());  // вариант 2 переноса chart
 //exampleChart->Assign(Form1->mainChart->getChart());                              // вариант 3 переноса chart

 // Chart's size and position
 exampleChart->Align = clNone;
 exampleChart->Height = (Form1->mainChart->getChart()->Height * exampleChart->Width) /
                        (float)Form1->mainChart->getChart()->Width;
 exampleChart->Top = (TabSheet1->Height - 10 - Panel10->Height - exampleChart->Height)/2 + 15;
 exampleChart->Left = Panel9->Width + 3;

 if( !exampleChart->BottomAxis->Increment){
     vertLineEdit->Enabled = false;
     vertLineDopEdit->Enabled = false;
     exampleChart->BottomAxis->Increment = 1;
     horizLineEdit->Enabled = false;
 }
 else{
     vertLineEdit->Enabled = true;
     vertLineDopEdit->Enabled = true;
     horizLineEdit->Enabled = true;
 }

 horizLineEdit->Text = Form1->mainChart->getCountHorizLine();
 vertLineEdit->Text = Form1->mainChart->getCountVertLine();
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
 EditMainNameRK->Hint  = EditMainNameRK->Text;

 // Text
 EditFlyingFile->Text  = Form1->iniFile->DataFile;
 EditFormatFile->Text  = Form1->iniFile->Format;
 EditLibraryFile->Text = Form1->iniFile->Library;
 if( ExtractFileName(Form1->iniFile->iniFileName) != "iniFileDefault.ini")
     EditINIFile->Text = Form1->iniFile->iniFileName;

 // Time
 if(&FlyingFile::Instance().getIndexBlocFileDatXX()){
     EditStartTime->Text = TDateTime(FlyingFile::Instance().getSourceMinTime() * SEC);
     EditEndTime->Text = TDateTime(FlyingFile::Instance().getSourceMaxTime() * SEC);
 }

 //======== Scales and graphts ======
 if( !Form1->mainChart->getCurrentParametr())
    Form1->mainChart->setCurrentParametr(reinterpret_cast<Parametr*>( *Form1->mainChart->mainList.begin() ));
 getAxisSettings();
 Form1->mainChart->printParametrsTo(ListBoxParam);

 //======== Parameters ==========
 if(FlyingFile::Instance().getStrData() == NULL)
     return;
 StringGridMain->RowCount = 0 ;
 if( !(Kpar = FlyingFile::Instance().getKPasp()) )
     return;
 for(int i = 1; i < Kpar; ++i){
     ++StringGridMain->RowCount;
     StringGridMain->Cells[0][i] = i;
     StringGridMain->Cells[1][i] = (FlyingFile::Instance().getPtrPaspChart() + i - 1)->Razdel;
     StringGridMain->Cells[2][i] = (FlyingFile::Instance().getPtrPaspChart() + i - 1)->Zamer;
     StringGridMain->Cells[3][i] = (FlyingFile::Instance().getPtrPaspChart() + i - 1)->Ident;
     StringGridMain->Cells[4][i] = (FlyingFile::Instance().getPtrPaspChart() + i - 1)->Name;
     StringGridMain->Cells[5][i] = SistemToString(FlyingFile::Instance().getPtrPaspChart() + i - 1);
 }
 packListBoxRazdel();
 Form1->mainChart->printParametrsTo(StringGrid1);
}


//---------------------------------------------------------------------------
// при вводе символа начинает осущетвляться ПОИСК
//--------------------------------------------------------------------------- 
void __fastcall TFormSettings::editSearchChange(TObject *Sender)
{
 Search(editSearch->Text);
}


//---------------------------------------------------------------------------
//      Выбор ячейки, если RK то появляется меню
//---------------------------------------------------------------------------
void __fastcall TFormSettings::StringGridMainSelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
 if(ARow == 0 || FlyingFile::Instance().getStrData() == NULL)
     return;
 TekRow = ARow;
 int identNum = findName("Идентификатор");
 int j = FlyingFile::Instance().findPaspByIdent(StringGridMain->Cells[identNum][TekRow]);

 // если параметр RK
 if((FlyingFile::Instance().getPtrPaspChart()+j)->Tip == 0 || (FlyingFile::Instance().getPtrPaspChart()+j)->Tip == 1){
    int r = FlyingFile::Instance().findPaspRKByIdent((FlyingFile::Instance().getPtrPaspChart() + j)->Ident);

    // проходим по всем паспортам_RK (признак конца NRK_SL == 0)
    AnsiString mRK[33];
    int tekNRK = r;
    while(tekNRK){
       mRK[(FlyingFile::Instance().getPtrRKChart() + tekNRK)->NRazRK] = (FlyingFile::Instance().getPtrRKChart() + tekNRK)->NameRK;
       tekNRK = (FlyingFile::Instance().getPtrRKChart() + tekNRK)->NRK_SL;
    }

    // заполнение таблицы разовых команд одного параметра
    ListBoxRK->Items->Clear();
    PanelRK->Visible = true;
    PanelRK->Width = StringGridMain->Width - 50;
    SpeedButtonCancel->Left = PanelRK->Width - SpeedButtonCancel->Width - 30;
    SpeedButtonOK->Left = SpeedButtonCancel->Left - SpeedButtonOK->Width - 30;
    StringGridMain->Enabled = false;

    for(int i = 8; i < 32; ++i)
       ListBoxRK->Items->Add(IntToStr(i+1) + " " + mRK[i+1]);
 }
}


//------------------------------------------------------------------------------
//            двойным щелчком выбираем параметр для добавления
//------------------------------------------------------------------------------
void __fastcall TFormSettings::StringGridMainDblClick(TObject *Sender)
{
 if( (TekRow == 0) || (TekRow > Kpar) || (FlyingFile::Instance().getStrData() == NULL) )
     return;

 int identNum = findName("Идентификатор");
 int j = FlyingFile::Instance().findPaspByIdent(StringGridMain->Cells[identNum][TekRow]);
 Form1->mainChart->addParametr(j);
 Form1->mainChart->printParametrsTo(StringGrid1);
}



//------------------------------------------------------------------------------
//        выбор параметра в таблице существующих параметров
//------------------------------------------------------------------------------
void __fastcall TFormSettings::StringGrid1SelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
 TekRow = ARow;
 Form1->mainChart->setCurrentParametr((Form1->mainChart->findParByNumber(ARow)));
 String name = (Form1->mainChart->getCurrentParametr())->GetSeriesTitle();

 for(int i = 1; i < StringGridMain->RowCount; ++i)
 {
    if(StringGridMain->Cells[findName("Идентификатор")][i] == name)
    {
       // подкрашиваем ячейку в главной таблице
       TGridRect myRect;
       myRect.Left = 0;
       myRect.Top  = i;
       myRect.Right = StringGridMain->ColCount;
       myRect.Bottom = i;
       StringGridMain->Selection = myRect;
       // перематываем главную таблицу на данный параметр
       StringGridMain->TopRow = (i <= 2) ? (i) : (i - 2);
       break;
    }
 }
}


//---------------------------------------------------------------------------
//               Редактирование параметра
//---------------------------------------------------------------------------
void __fastcall TFormSettings::SpeedButtonRenameClick(TObject *Sender)
{
 PageControl1->ActivePage = TabSheet4;
 getAxisSettings();
 Form1->mainChart->printParametrsTo(ListBoxParam);
}


//---------------------------------------------------------------------------
//    Разовые команды кнопка ОК
//---------------------------------------------------------------------------
void __fastcall TFormSettings::SpeedButtonOKClick(TObject *Sender)
{
 AnsiString identName = StringGridMain->Cells[findName("Идентификатор")][TekRow];
 int j = FlyingFile::Instance().findPaspByIdent(identName);
 if(j < 0)
   return;

 StringGrid1->RowCount++;
 StringGrid1->Cells[0][StringGrid1->RowCount] = identName;

 // get NRazRK
 (ListBoxRK->ItemIndex < 0) ? Form1->mainChart->addParametr(j) :
                              Form1->mainChart->addParametr(j, ListBoxRK->ItemIndex + 9);
}


//---------------------------------------------------------------------------
//    Разовые команды кнопка Отмена
//---------------------------------------------------------------------------
void __fastcall TFormSettings::SpeedButtonCancelClick(TObject *Sender)
{
 PanelRK->Visible = false;
 StringGridMain->Enabled = true;
}


//===========================================================================
void __fastcall TFormSettings::ButtonAllClick(TObject *Sender)
{
 StringGridMain->RowCount = 1;
 for(int k = 1; k < Kpar; ++k){
     ++StringGridMain->RowCount;
     StringGridMain->Cells[0][k] = k;
     StringGridMain->Cells[findName("Раздел")       ][k] = (FlyingFile::Instance().getPtrPaspChart() + k - 1)->Razdel;
     StringGridMain->Cells[findName("Замер")        ][k] = (FlyingFile::Instance().getPtrPaspChart() + k - 1)->Zamer;
     StringGridMain->Cells[findName("Идентификатор")][k] = (FlyingFile::Instance().getPtrPaspChart() + k - 1)->Ident;
     StringGridMain->Cells[findName("Наименование") ][k] = (FlyingFile::Instance().getPtrPaspChart() + k - 1)->Name;
     StringGridMain->Cells[findName("Системы")      ][k] = SistemToString(FlyingFile::Instance().getPtrPaspChart() + k - 1);
 }
 StringGridMain->Visible = true;
 for(int i = 0; i < ListBoxRazdel->Count; ++i)
     ListBoxRazdel->Selected[i] = true;
}


//===========================================================================
void TFormSettings::filterRazdel(const String& nameRazdel)
{
 int i = 0;
 for(i = 0; i < FlyingFile::Instance().getKRazdel(); ++i)
    if(nameRazdel == (FlyingFile::Instance().getPtrRazlel() + i)->Razdel)
       break;
 int currPasp = (FlyingFile::Instance().getPtrRazlel() + i)->NPasp1;

 bool first = false;
 int nRow = StringGridMain->RowCount;
 if(nRow == 1){
    nRow = 0;
    first = true;
 }

 for(int j = nRow + 1; j < (FlyingFile::Instance().getPtrRazlel() + i)->KPaspRazd + nRow; ++j){
     ++StringGridMain->RowCount;
     StringGridMain->Cells[0][j] = j;
     StringGridMain->Cells[findName("Раздел")       ][j] = (FlyingFile::Instance().getPtrPaspChart() + currPasp)->Razdel;
     StringGridMain->Cells[findName("Замер")        ][j] = (FlyingFile::Instance().getPtrPaspChart() + currPasp)->Zamer;
     StringGridMain->Cells[findName("Идентификатор")][j] = (FlyingFile::Instance().getPtrPaspChart() + currPasp)->Ident;
     StringGridMain->Cells[findName("Наименование") ][j] = (FlyingFile::Instance().getPtrPaspChart() + currPasp)->Name;
     StringGridMain->Cells[findName("Системы")      ][j] = SistemToString(FlyingFile::Instance().getPtrPaspChart() + currPasp);
     currPasp = (FlyingFile::Instance().getPtrPaspChart() + currPasp)->N_pasps_razdel;
 }
 if(first)
     --StringGridMain->RowCount;
 StringGridMain->SetFocus();
}


//===========================================================================
void __fastcall TFormSettings::ListBoxRazdelClick(TObject *Sender)
{
 TListBox* list = (TListBox*)Sender;
 StringGridMain->Visible = true;
 StringGridMain->RowCount = 0;

 size_t countSelect(0);
 bool find = false;
 for(int i = 0; i < list->Count; ++i){
     if(list->Selected[i]){
         filterRazdel(list->Items->Strings[i]);
         find = true;
         ++countSelect;
     }
 }
 StringGridMain->Visible = (find) ? true : false;

 // выбран один параметр
 if((list->Count - countSelect) == 1){
     StringGridMain->RowCount = 0;
     for(int i = 0; i < list->Count; ++i){
         list->Selected[i] = !list->Selected[i];
         if(list->Selected[i])
            filterRazdel(list->Items->Strings[i]);
     }
 }
 ++StringGridMain->RowCount;
}


//============================================================================
void __fastcall TFormSettings::Splitter2Moved(TObject *Sender)
{
 // для красоты, чтоб кнопки были такой же ширины что и панель выбора раздела
 ButtonAll->Width = PanelOfButtonAll->Width - 3;
}


//==============================================================================
//      StringGrid1     MouseDown
//==============================================================================
void __fastcall TFormSettings::StringGrid1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 StringGrid1->BeginDrag(false, 5);
 // calculate row
 fromNumRow = Y / (StringGrid1->RowHeights[0] + 1);
}

//=========================================================================
void __fastcall TFormSettings::StringGrid1DragOver(TObject *Sender,
      TObject *Source, int X, int Y, TDragState State, bool &Accept)
{
 if(Sender != Source){
     // from main table
 }
 else
     Accept = true;
}


//==========================================================================
//    перемещение наименований по вертикали в левой таблице
//==========================================================================
void __fastcall TFormSettings::StringGrid1DragDrop(TObject *Sender,
      TObject *Source, int X, int Y)
{
 if(Sender == Source){
    int toNumRow = Y / (StringGrid1->RowHeights[0] + 1);
    list_it it1 = Form1->mainChart->mainList.begin();
    std::advance(it1, fromNumRow);
    list_it it2 = Form1->mainChart->mainList.begin();
    std::advance(it2, toNumRow);
    // swap
    Form1->mainChart->mainList.splice(it2, Form1->mainChart->mainList, it1);
    Form1->mainChart->printParametrsTo(StringGrid1);
    Form1->mainChart->setCurrentParametr(0);
 }
 else{
    // from main table
    if(FlyingFile::Instance().getStrData() == NULL)
       return;
    int top = StringGridMain->Selection.Top;
    int bottom = StringGridMain->Selection.Bottom;
    for(int i = top; i <= bottom; ++i){
       TekRow = i;
       if(! TekRow || TekRow > Kpar)
          return;
       int numIdent = findName("Идентификатор");
       int j = FlyingFile::Instance().findPaspByIdent(StringGridMain->Cells[numIdent][TekRow]);
       Form1->mainChart->addParametr(j);
    }
    Form1->mainChart->printParametrsTo(StringGrid1);
 }
}


//===========================================================================
//  для раскраски наименований параметров в левой таблице
//===========================================================================
void __fastcall TFormSettings::StringGrid1DrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
 if(Form1->mainChart->mainList.begin() == Form1->mainChart->mainList.end())
    return;
 list_it x = Form1->mainChart->mainList.begin();
 std::advance(x, ARow);
 StringGrid1->Canvas->FillRect(Rect);
 StringGrid1->Canvas->Font->Color = (*x)->Axis->Axis->Color;
 StringGrid1->Canvas->TextOutA(Rect.Left + 3, Rect.Top + 3, StringGrid1->Cells[ACol][ARow]);
}


//===========================================================================
//   узнаем номер столбца на который щелкнул пользователь (координата X)
//===========================================================================
int TFormSettings::numCol(unsigned sumWidth, unsigned num, unsigned X)
{
  sumWidth += StringGridMain->ColWidths[num];
  if(X < sumWidth)
      return num;
  else{
      ++num;
      return numCol(sumWidth, num, X);
  }
}


//==========================================================================
void __fastcall TFormSettings::StringGridMainMouseUp(TObject *Sender,
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


     for(int i = 0; i < Kpar; ++i){
         str_i[i] = (FlyingFile::Instance().getPtrPaspChart() + i)->Ident;
         str_n[i] = (FlyingFile::Instance().getPtrPaspChart() + i)->Name;
         str_r[i] = (FlyingFile::Instance().getPtrPaspChart() + i)->Razdel;
         str_z[i] = (FlyingFile::Instance().getPtrPaspChart() + i)->Zamer;
         String s = SistemToString(FlyingFile::Instance().getPtrPaspChart() + i);
         str_s[i] = s.c_str();
     }

     // сортировка по идентификатору
     if(choiceCol == findName("Идентификатор"))
     {
         for(int i=0; i < Kpar; ++i){
             int mins = i;
             for(int j = i + 1; j < Kpar; ++j){
                 if( (str_i[mins]).compare(str_i[j]) > 0){  // если s1 > s2 (т.е. s1 ниже по алфавиту чем s2)
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
     if(choiceCol == findName("Наименование")){
         for(int i=0; i < Kpar; i++){
             int mins = i;
             for(int j = i + 1; j < Kpar; ++j){
                if( (str_n[mins]).compare(str_n[j]) > 0){  // если s1 > s2 (т.е. s1 ниже по алфавиту чем s2)
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
void __fastcall TFormSettings::StringGridMainDrawCell(
      TObject *Sender, int ACol, int ARow, TRect &Rect,
      TGridDrawState State)
{
 if(ACol == choiceCol && ARow == 0 && !colMoved){
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
void __fastcall TFormSettings::StringGridMainColumnMoved(
      TObject *Sender, int FromIndex, int ToIndex)
{
 colMoved = true;
}


//============================================================================
void __fastcall TFormSettings::StringGridMainMouseDown(
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
int TFormSettings::findName(const AnsiString& s)
{
 for(int i = 0; i < StringGridMain->ColCount; ++i)
     if(StringGridMain->Cells[i][0] == s)
        return i;
 return 0;
}


//-----------------------------------------------------------------------------
//    копируем наименования параметров на главную форму
//-----------------------------------------------------------------------------
void __fastcall TFormSettings::FormClose(TObject *Sender,
      TCloseAction &Action)
{
 //Singleton::getInstance().setVectorOfPar(StringGrid1);
}


//---------------------------------------------------------------------------
//     удаляем выбранную ячейку
//---------------------------------------------------------------------------
void __fastcall TFormSettings::SpeedButtonDeleteClick(
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
void __fastcall TFormSettings::okButtonClick(TObject *Sender)
{
 setAxisSettings();
 Form1->mainChart->setChartSettings(Form1->mainChart->getChart(), exampleChart);     // this?
 FormSettings->ModalResult = 1;
}

//---------------------------------------------------------------------------
//        Отмена
//---------------------------------------------------------------------------
void __fastcall TFormSettings::noButtonClick(TObject *Sender)
{
 FormSettings->ModalResult = 2;
}


//---------------------------------------------------------------------------
//      Применение настроек к оси
//---------------------------------------------------------------------------
void TFormSettings::setAxisSettings()
{
 if( !Form1->mainChart->getCurrentParametr())
     return;
 Parametr* curPar = Form1->mainChart->getCurrentParametr();

 // min max axis
 int stepcount = EditStepCount->Text.ToInt();
 double step = atof(TrueSeparator(EditStep->Text).c_str());
 double min = atof(TrueSeparator(EditMin->Text).c_str());
 double max = min + step*stepcount;


 // title, position
 curPar->Axis->Title->Caption = EditName->Text;
 curPar->Axis->SetMinMax(min, max);
 curPar->Axis->Increment = step;
 curPar->Axis->StartPosition =
 curPar->Axis->EndPosition - (exampleChart->LeftAxis->Increment)*stepcount;

 // visible
 (CheckBoxVisible->Checked) ? curPar->invisible() : curPar->visible();

 // color, marks
 TColor color = ColorBox1->Selected;
 curPar->Axis->Axis->Color = color;
 curPar->Axis->Ticks->Color = color;
 curPar->Axis->Title->Font->Color = color;
// curPar->Series->Marks->Visible = CheckBoxMarks->Checked;
 curPar->MarkerSymbol = EditMark->Text;

 // line style
 /*curPar->Series->Pen->Color = color;
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
 if(curPar->Series->Pen->Width != 1 && curPar->Series->Pen->Style != psSolid)
    ShowMessage("Cтили линии со штрихами и пунктирами доступны только при толщине = 1");  */

 // NSis
 curPar->NSis = ComboBoxNSys->Text.ToInt();
 int i = curPar->Axis->Title->Caption.Pos(" ");
 if(i > 0)
     curPar->Axis->Title->Caption = curPar->Axis->Title->Caption.SubString(1, i - 1) + " " + IntToStr(curPar->NSis);

 // afterComma
 switch(afterCommaComboBox->ItemIndex)
 {
    case 0: curPar->afterComma = "0"; curPar->Axis->AxisValuesFormat = "0"; break;
    case 1: curPar->afterComma = "0.0"; curPar->Axis->AxisValuesFormat = "0.0"; break;
    case 2: curPar->afterComma = "0.00"; curPar->Axis->AxisValuesFormat = "0.00"; break;
    case 3: curPar->afterComma = "0.000"; curPar->Axis->AxisValuesFormat = "0.000"; break;
    case 4: curPar->afterComma = "0.0000"; curPar->Axis->AxisValuesFormat = "0.0000"; break;
    default: curPar->afterComma = "0"; curPar->Axis->AxisValuesFormat = "0"; break;
 }
}


//---------------------------------------------------------------------------
//      Изменение полей показательного Chart
//---------------------------------------------------------------------------
void __fastcall TFormSettings::editLeftChange(TObject *Sender)
{
 if(editLeft->Text == "") return;
 exampleChart->MarginLeft = StrToInt(editLeft->Text);
}
//---------------------------------------------------------------------------
void __fastcall TFormSettings::editTopChange(TObject *Sender)
{
 if(editTop->Text == "") return;
 exampleChart->MarginTop = StrToInt(editTop->Text);
}
//---------------------------------------------------------------------------
void __fastcall TFormSettings::editRightChange(TObject *Sender)
{
 if(editRight->Text == "") return;
 exampleChart->MarginRight = StrToInt(editRight->Text);
}
//---------------------------------------------------------------------------
void __fastcall TFormSettings::editBottomChange(TObject *Sender)
{
 if(editBottom->Text == "") return;
 exampleChart->MarginBottom = StrToInt(editBottom->Text);
}


//==============================================================================
//     LineEditChange                 change horizontal increment may only in this place
//==============================================================================
void __fastcall TFormSettings::horizLineEditChange(TObject *Sender)
{
 if(horizLineEdit->Text == "" || horizLineEdit->Text.ToInt() <= 0)
    return;
 double delta = exampleChart->LeftAxis->Maximum - exampleChart->LeftAxis->Minimum;
 int countHorizLine = (horizLineEdit->Text.ToInt() + 1);
 exampleChart->LeftAxis->Increment = delta / countHorizLine;

 editMinLeft->Text = exampleChart->LeftAxis->Minimum;     // test
 editMaxLeft->Text = exampleChart->LeftAxis->Maximum;     // test
 editIncrementLeft->Text = exampleChart ->LeftAxis->CalcIncrement();
}

//---------------------------------------------------------------------------
void __fastcall TFormSettings::vertLineEditChange(TObject *Sender)
{
 if(vertLineEdit->Text == "" || vertLineEdit->Text.ToInt() <= 0)
    return;
 double delta = exampleChart->BottomAxis->Maximum - exampleChart->BottomAxis->Minimum;
 int countVertLine = (vertLineEdit->Text.ToInt() + 1);
 exampleChart->BottomAxis->Increment = delta / countVertLine;

 editMinChart->Text = exampleChart->BottomAxis->Minimum;     // test
 editMaxChart->Text = exampleChart->BottomAxis->Maximum;     // test
 editIncrement->Text = exampleChart->BottomAxis->CalcIncrement();
}

//---------------------------------------------------------------------------
void __fastcall TFormSettings::vertLineDopEditChange(TObject *Sender)
{
 if(vertLineDopEdit->Text == "" || vertLineDopEdit->Text.ToInt() < 0)
     return;
 exampleChart->BottomAxis->MinorTickCount = vertLineDopEdit->Text.ToInt();
}


//==============================================================================
//     TabSheetResize
//==============================================================================
void __fastcall TFormSettings::TabSheet1Resize(TObject *Sender)
{
 // размеры exampleChart пропорциональны главному Chart
 // exampleChart->Align = clNone;
 exampleChart->Width = TabSheet1->Width - Panel9->Width - 5;
 exampleChart->Height = ((float)Form1->mainChart->getChart()->Height / (float)Form1->mainChart->getChart()->Width)
                        * (float)exampleChart->Width;
 exampleChart->Top    = (TabSheet1->Height - 10 - Panel10->Height - exampleChart->Height)/2 + 15;
 exampleChart->Left   = Panel9->Width + 3;
 //CheckBoxAutoLeft->Checked = exampleChart->LeftAxis->Axis->in
 //CheckBoxAutoBottom->Checked = exampleChart->BottomAxis->Automatic;
}


void __fastcall TFormSettings::ComboBoxLineTypeDrawItem(
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

void __fastcall TFormSettings::ComboBoxLineTypeSelect(
      TObject *Sender)
{
 ComboBoxLineType->Enabled = false;
 ComboBoxLineType->Enabled = true;        
}
//---------------------------------------------------------------------------

void __fastcall TFormSettings::EditStepCountKeyPress(TObject *Sender,
      char &Key)
{
 OnlyNumbers(Key, 0);    // без запятых
}

void __fastcall TFormSettings::EditMinKeyPress(TObject *Sender,
      char &Key)
{
 OnlyNumbers(Key, 1);
}



void __fastcall TFormSettings::feildColorBoxChange(TObject *Sender)
{
 exampleChart->Color = feildColorBox->Selected;
 exampleChart->LeftAxis->LabelsFont->Color = feildColorBox->Selected;
}
//---------------------------------------------------------------------------


void __fastcall TFormSettings::TabSheet2Resize(TObject *Sender)
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


//==============================================================================
//         getAxisSettings
//==============================================================================
void TFormSettings::getAxisSettings()
{
 if( !Form1->mainChart->getCurrentParametr())
 {
     GroupBoxGeneral->Enabled = false;
     GroupBoxAxis->Enabled = false;
     GroupBoxRK->Enabled = false;
     GroupBoxGraph->Enabled = false;
 }
 else
 {
     GroupBoxGeneral->Enabled = true;
     GroupBoxAxis->Enabled = true;
     GroupBoxRK->Enabled = true;
     GroupBoxGraph->Enabled = true;
     Parametr* curPar = Form1->mainChart->getCurrentParametr();

     if(curPar)
     {
         // мин, макс, инкремент, цвет оси
         EditMin->Text = FormatFloat(curPar->afterComma, curPar->Axis->Minimum);
         EditStep->Text = FormatFloat(curPar->afterComma, curPar->Axis->Increment);
         EditStepCount->Text = static_cast<int>((curPar->Axis->Maximum - curPar->Axis->Minimum) /
                                curPar->Axis->Increment + 0.5);
         ColorBox1->Selected = curPar->Axis->Axis->Color;

         // идентификатор, наименование
         EditName->Text = curPar->Axis->Title->Caption;
         EditIdent->Text = curPar->GetSeriesTitle();
         EditMainName->Text = String((FlyingFile::Instance().getPtrPaspChart() + curPar->NPasp)->Name);
         EditPaspN->Text = curPar->NPasp;

         //номер системы
         ComboBoxNSys->Items->Clear();                   // сколько систем ,
         for(int i = 0; i < (curPar->KolSis); ++i)       // столько и пунктов
             ComboBoxNSys->Items->Add(i+1);              // в выпадающем списке
         ComboBoxNSys->ItemIndex = curPar->NSis - 1;

         // видимая/ невидимая
         CheckBoxVisible->Checked = !curPar->Axis->Visible;

         // маркеры
         EditMark->Text = curPar->MarkerSymbol;

         //---- разовые команда
         if( curPar->GetTagSeries() )
         {
         //if(curPar->NRK != -1 && ((FlyingFile::Instance().getPtrPaspChart() + curPar->NPasp)->Tip == 0 || (FlyingFile::Instance().getPtrPaspChart() + curPar->NPasp)->Tip == 1)){
             ParameterRK* p = dynamic_cast<ParameterRK*>(curPar);
             EditMainNameRK->Text = p->NameRK;
             EditNrazr->Text = p->NRK;
             EditNStructRK->Text = p->NStructRK;
         }

         // afterComma
         int n = curPar->afterComma.Length() - 2;
         afterCommaComboBox->ItemIndex = n < 0 ? 0 : n;

         // тип и толщина линии
         /*if(curPar->Series->Count() < 1)
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
             }       */
             ComboBoxLineWidth->Enabled = true;
             switch( curPar->GetSeriesWidth() )
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
         //}
     }
 }
}


//-----------------------------------------------------------------------------
//          выбор параметра из списка
//-----------------------------------------------------------------------------
void __fastcall TFormSettings::ListBoxParamClick(TObject *Sender)
{
 // устанавливаем настройки предудущего (до клика) параметра
 setAxisSettings();

 // установка нового текущего параметра
 list_it i = Form1->mainChart->mainList.begin();
 std::advance(i, ListBoxParam->ItemIndex);
 Form1->mainChart->setCurrentParametr(reinterpret_cast<Parametr*>(*i));

 // вывод на форму настроек нового параметра
 getAxisSettings();
}


void __fastcall TFormSettings::StringGridMainMouseMove(
      TObject *Sender, TShiftState Shift, int X, int Y)
{
 static bool drag = false;
 if (X < 20 && buttonDown && !drag){
     colMoved = false;
     StringGridMain->BeginDrag(false, 10);
     drag = true;
 }
}
//---------------------------------------------------------------------------

void __fastcall TFormSettings::StringGridMainDragOver(
      TObject *Sender, TObject *Source, int X, int Y, TDragState State,
      bool &Accept)
{
 Accept = false;
}
//---------------------------------------------------------------------------


void __fastcall TFormSettings::EditIdentChange(TObject *Sender)
{
 if ( (EditIdent->Text).Length() > 16 ){
     EditIdent->Text = (EditIdent->Text).SubString(1, 16);
     ShowMessage("Ограничение по количеству символов. 16 ");
 }
}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------
//   Окрашивает текст названия в списке настроек параметра
//---------------------------------------------------------------------------
void __fastcall TFormSettings::ListBoxParamDrawItem(TWinControl *Control,
      int Index, TRect &Rect, TOwnerDrawState State)
{
 /*for(list_it i = Form1->mainChart->mainList.begin(); i != Form1->mainChart->mainList.end(); ++i)
     if(ListBoxParam->Items->Strings[Index] == (*i)->Axis->Title->Caption){
         ListBoxParam->Canvas->FillRect(Rect);
         ListBoxParam->Canvas->Font->Color = (*i)->Axis->Axis->Color;
         ListBoxParam->Canvas->TextOutA(Rect.Left + 3, Rect.Top, (*i)->Axis->Title->Caption);
     }  */
 list_it i = Form1->mainChart->mainList.begin();
 std::advance(i, Index);
 ListBoxParam->Canvas->FillRect(Rect);
 ListBoxParam->Canvas->Font->Color = (*i)->Axis->Axis->Color;
 ListBoxParam->Canvas->TextOutA(Rect.Left + 3, Rect.Top, (*i)->Axis->Title->Caption);
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
//  Функция устанавливает правильный разделитель целой и дробной части
//  независимо от того что ввел пользователь "." или ","
//---------------------------------------------------------------------------
String __fastcall TFormSettings::TrueSeparator(const AnsiString& textEdit){
 AnsiString sep = AnsiString(DecimalSeparator);  // текущий разделитель
 int i = 0;
 if ( i != textEdit.Pos(",") ){     //запятая
    i = textEdit.Pos(",");
    if(sep == ",")
       return textEdit;
    else
       return textEdit.SubString(1, i - 1) + "." +
              textEdit.SubString(i + 1, 255);
 }
 else if(i != textEdit.Pos(".")){     // точка
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
//    Запрещаем вводить буквы
//---------------------------------------------------------------------------
void __fastcall TFormSettings::OnlyNumbers(char &Key, bool Separator){
 Set <Char, 0, 255> Dig;
 if(! Separator ){
    if(! (Dig <<'0'<<'1'<<'2'<<'3'<<'4'<<'5'<<'6'<<'7'<<'8'<<'9'<<'\b').Contains(Key)){
       Key = 0;
       Beep();
    }
 }
 else if(! (Dig <<'0'<<'1'<<'2'<<'3'<<'4'<<'5'<<'6'<<'7'<<'8'<<'9'<<'.'<<','<<'-'<<'\b').Contains(Key)){
    Key = 0;
    Beep();
 }
}


//---------------------------------------------------------------------------
//   Move PanelRK
//---------------------------------------------------------------------------
void __fastcall TFormSettings::RKListPanelMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 buttonPress = true;
 X0 = X;
 Y0 = Y;
}

void __fastcall TFormSettings::RKListPanelMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
 if(buttonPress){
    PanelRK->Top += Y - Y0;
    PanelRK->Left += X - X0;
 }
}

void __fastcall TFormSettings::RKListPanelMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 buttonPress = false;
}


//---------------------------------------------------------------------------
// Заполнение списка разделов
//---------------------------------------------------------------------------
void TFormSettings::packListBoxRazdel()
{
 String nameRazdel = "0";
 ListBoxRazdel->Clear();
 for(int i = 0, kr = FlyingFile::Instance().getKRazdel(); i < kr; ++i){
    nameRazdel = (FlyingFile::Instance().getPtrRazlel() + i)->Razdel;
    ListBoxRazdel->AddItem(nameRazdel, this);
    ListBoxRazdel->Selected[i] = true;
 }
}


//---------------------------------------------------------------------------
// Подбор высоты строки
//---------------------------------------------------------------------------
void TFormSettings::RowHeight(TStringGrid * G)
{
 int max = G->Canvas->TextHeight(G->Cells[2][1]);
 for(int row = 0; row < G->RowCount; ++row)
     G->RowHeights[row] = max + 4;
}


//---------------------------------------------------------------------------
// конвертирует short int NSis[4] в строчку AnsiString
//---------------------------------------------------------------------------
AnsiString TFormSettings::SistemToString(const struct PaspChart *Pasp)
{
 AnsiString str;
 for(int j = 0; j < 4; ++j)
    if( Pasp->NSis[j] != -1){
       str += Pasp->NSis[j];
       str += " ";
    }
 return str;
}


//---------------------------------------------------------------------------
// Поиск
//---------------------------------------------------------------------------
void TFormSettings::Search(const AnsiString& text)
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

   // считывание во временный массив из структуры PtrPaspChart
   /*for(int j = 0; j < Kpar; ++j)
   {
      a[i_r][j] = (PtrPaspChart + j)->Razdel;
      a[i_z][j] = (PtrPaspChart + j)->Zamer;
      a[i_i][j] = (PtrPaspChart + j)->Ident;
      a[i_n][j] = (PtrPaspChart + j)->Name;
      a[i_s][j] = SistemToString(PtrPaspChart + j).c_str();
   }    */
   // альтернативное считывание из таблицы StringGridMain
   for(int j = 0; j < Kpar; ++j)
   {
      a[i_r][j] = (StringGridMain->Cells[i_r][j]).c_str();
      a[i_z][j] = (StringGridMain->Cells[i_z][j]).c_str();
      a[i_i][j] = (StringGridMain->Cells[i_i][j]).c_str();
      a[i_n][j] = (StringGridMain->Cells[i_n][j]).c_str();
      a[i_s][j] = (StringGridMain->Cells[i_s][j]).c_str();
   }


   for(int j = 0; j < Kpar; ++j){
       if( std::string::npos != a[n][j].find(symbol)){
           if(j <= 2)   StringGridMain->TopRow = j;
           else         StringGridMain->TopRow = j-2;
           // draw the cell
           TGridRect myRect;
           myRect.Left = 0;
           myRect.Top  = j;
           myRect.Right = StringGridMain->ColCount;
           myRect.Bottom = j;
           StringGridMain->Selection = myRect;
           break;
       }
   }

   // сравнение и перестановка
   //string *b = new string[k];
   /*for(int j = 0; j < Kpar; ++j)
   {
      if( (a[n][j]).compare(0, symbol.size(), symbol, 0, symbol.size()) == 0 )
      {
          if(j <= 2)   StringGridMain->TopRow = j-1;
          else         StringGridMain->TopRow = j-3;
          // подкрашиваем ячейку
          TGridRect myRect;
          myRect.Left = 0;
          myRect.Top  = j-1;
          myRect.Right = StringGridMain->ColCount;
          myRect.Bottom = j-1;
          StringGridMain->Selection = myRect;      */
         /*
         // запоминамем строчку
         for(int i = 0; i < k; ++i)
            b[i] = a[i][j];

         // все элементы до a[n][j] увеличивают индекс на 1
         for(int m = 0; m < k; ++m)
            for(int i = j; i > 0; --i)
               a[m][i] = a[m][i-1];

         // ставим symbol на первое место
         for(int i = 0; i < k; ++i)
            a[i][0] = b[i];        */
   /*   }
   }    */

   // отсортированный массив выводим в StringGrid
   /*for(int j = 0; j < Kpar; ++j)
   {
      StringGridMain->Cells[i_r][j+1] = a[i_r][j].c_str();
      StringGridMain->Cells[i_z][j+1] = a[i_z][j].c_str();
      StringGridMain->Cells[i_i][j+1] = a[i_i][j].c_str();
      StringGridMain->Cells[i_n][j+1] = a[i_n][j].c_str();
      StringGridMain->Cells[i_s][j+1] = a[i_s][j].c_str();
      StringGridMain->TopRow = 0;
   }                 */
   //delete[] b;
   for(int i = 0 ; i < k; ++i)
      delete a[i];
   delete[] a;
}






void __fastcall TFormSettings::Button1Click(TObject *Sender)
{
 AlphaBlend = true;
 AlphaBlendValue = 90;
}
//---------------------------------------------------------------------------



void __fastcall TFormSettings::testPointSeriesButtonClick(TObject *Sender)
{
 TPointSeries* series = new TPointSeries(exampleChart);
 exampleChart->AddSeries(series);
 int pointCount = 20;
 double* X = new double(pointCount);
 double* Y = new double(pointCount);
 for(int i = 0; i < pointCount; ++i){
    X[i] = i;
    Y[i] = i;
 }
 series->AddArray(X, pointCount, Y, pointCount);
}
//---------------------------------------------------------------------------

