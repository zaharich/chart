//---------------------------------------------------------------------------


#pragma hdrstop

#include "CustomChart.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
const int CustomChart::MAXCOUNTSERIES = 50;
const double CustomChart::LEFTAXISLENGHT = 100;
const double CustomChart::SEC = 1/86400;


//==============================================================================
//             CustomChart
//==============================================================================
CustomChart::CustomChart(TScrollBox* container){
  chart = new TChart(container);
  chart->Parent = container;
  chart->Align = alClient;
  chart->View3D = false;

  Series1 = new TFastLineSeries(chart);          // без Series1 не будет
  Series1->ParentChart = chart;                  // горизонтальных линий
  chart->AddSeries(Series1);                     // сетки
  Series1->XValues->DateTime = true;

  chart->Title->Clear();
  chart->SubTitle->Text->Add(0);
  chart->SubTitle->Text->Add(0);

};


//==============================================================================
//         ~CustomChart
//==============================================================================
CustomChart::~CustomChart(){
  delete Series1;
  delete chart;
};


//==============================================================================
//               chartInit
//==============================================================================
void CustomChart::chartInit(){
  chart->BottomAxis->DateTimeFormat = "HH:mm:ss";
  chart->BottomAxis->Axis->Width = 1;
  chart->BottomAxis->Automatic = false;
  //chart->BottomAxis->SetMinMax(SourceMinTime*SEC, SourceMaxTime*SEC);
  //chart->BottomAxis->Increment = (SourceMaxTime - SourceMinTime)*SEC / countMainVertLine;
  chart->BottomAxis->MinorTickCount = 0;
  chart->BottomAxis->RoundFirstLabel = false;
  chart->BottomAxis->LabelsSize = 1;
  chart->BottomAxis->PositionUnits = muPercent;

  chart->LeftAxis->Axis->Width = 1;
  chart->LeftAxis->Automatic = false;
  chart->LeftAxis->SetMinMax(0, LEFTAXISLENGHT);
  chart->LeftAxis->Increment = 5;
  chart->LeftAxis->LabelsFont->Color = chart->Color;

  chart->MarginTop = 2;
  chart->MarginBottom = 3;
  chart->MarginRight = 3;
  chart->MarginLeft = 10;
  chart->Color = clAqua;
};


//==============================================================================
//           loadEdit
//==============================================================================
void CustomChart::loadEdit(){
  if(chart->Title->Text->Strings[0] == "TChart")
    return;
  /*for(int i = 0; i < 3; ++i)
  {
      //label[i] = new TLabel(Chart1);
      label[i]->Parent      = Chart1;
      label[i]->OnMouseDown = LabelExample->OnMouseDown;
      label[i]->OnMouseMove = LabelExample->OnMouseMove;
      label[i]->OnMouseUp   = LabelExample->OnMouseUp;
      label[i]->OnDblClick  = LabelExample->OnDblClick;
      label[i]->PopupMenu   = LabelPopupMenu;

      AnsiString st = Chart1->Title->Text->Strings[i];
      int pos1 = st.Pos("$") - 1;
      AnsiString buff_st = st.SubString(0, pos1);
      label[i]->Visible = buff_st.ToInt();
      st = st.SubString(pos1 + 2, 255);                 // +2 чтобы не захватывать разделитель $

      pos1 = st.Pos("$") - 1;
      buff_st = st.SubString(0, pos1);
      label[i]->Caption = buff_st;            // Text
      st = st.SubString(pos1 + 2, 255);

      pos1 = st.Pos(" ")-1;
      buff_st = st.SubString(0, pos1);
      label[i]->Left = buff_st.ToInt();       // Left
      st = st.SubString(pos1+2, 255);

      label[i]->Top = st.ToInt();             // Top
  }  */

   // вытаскиваем время из subTitle
   String str = chart->SubTitle->Text->Strings[0];
   int pos1 = str.Pos("$") - 1;
   String tmp = str.SubString(0, pos1);
   //tmp = Singleton::getInstance().TrueSeparator(tmp);
   double min = StrToFloat(tmp);
   tmp = str.SubString(pos1 + 2, 255);
   //tmp = Singleton::getInstance().TrueSeparator(tmp);
   double max = StrToFloat(tmp);

   if(min < SourceMinTime*SEC || max > SourceMaxTime*SEC)
      chart->BottomAxis->SetMinMax(SourceMinTime * SEC, SourceMaxTime * SEC);
   else
      chart->BottomAxis->SetMinMax(min, max);
};


//==============================================================================
//       openChartFromFile
//==============================================================================
void CustomChart::openChartFromFile(const String& teeName){
 if( !FileExists(teeName))
 {
     if(ExtractFileName(teeName) == "Вкладка_1.tee")
         return;
     if(teeName != "")
         ShowMessage("Файл \"" + teeName + "\" не найден. (OCFF)");
     return;
 }
 LoadChartFromFile(dynamic_cast<TCustomChart*>(chart), teeName); // встроенная функция
 loadEdit();
};

