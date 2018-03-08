//---------------------------------------------------------------------------
#pragma hdrstop

#include "Grid.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


grid::grid(TChart* c)
     :maxLeftAxis(100)
{
  chart = new TChart(c);
}

grid::~grid()
{
 delete chart;
}




