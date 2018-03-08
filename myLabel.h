/** Класс добавляет функциональность для класса TLabel (для установки на TChart)
 * @autor Zakharchuk Andrew
*/

#ifndef myLabelH
#define myLabelH

#include "StdCtrls.hpp"
#include "Chart.hpp"
#include <list>
#include "log.h"

#include <iostream>
#include <fstream>
#include <cstdio>

class Log;
//---------------------------------------------------------------------------
class myLabel :public TLabel
{
 private:
    int X0, Y0;
    bool mouseDown;
    int id;

    TEdit* edit;
    TMenuItem* menuItem;

    //Log plog;

    /** Пишем в лог строку
    *   @param str - строка, которая будет записана в log файл
    */
    void writeToLog(AnsiString& str);

    static myLabel* currentLabel;
    static int labelId;

    void __fastcall labelMouseDown(TObject *Sender,
        TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall labelMouseMove(TObject *Sender, TShiftState Shift,
        int X, int Y);
    void __fastcall labelMouseUp(TObject *Sender, TMouseButton Button,
        TShiftState Shift, int X, int Y);
    void __fastcall labelDblClick(TObject *Sender);

    void __fastcall editKeyDown(TObject *Sender, WORD &Key,
       TShiftState Shift);

 public:
    __fastcall myLabel(Classes::TComponent* AOwner);
    __fastcall ~myLabel();

    void __fastcall setPosition(int left, int top){Left = left; Top = top;};
    void __fastcall setCaption(bool visible, AnsiString caption){Visible = visible; Caption = caption;};

    static myLabel* getCurrentLabel(){return currentLabel;};
    void deleteAllLabels();

    static std::list<myLabel*> labelList;
};
#endif
