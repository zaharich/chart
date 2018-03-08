//---------------------------------------------------------------------------

#ifndef GridH
#define GridH
#include "Chart.hpp"
//---------------------------------------------------------------------------
class grid
{
 private:
     TChart* chart;

     // HorizAxis
     const float maxLeftAxis;
     float       incrementLeftAxis;
     int         countHorizLines;
     bool        visibleHorizLines;

     // VertLines
     float minBottomAxis;
     float maxBottomAxis;
     float incrementBottomAxis;
     int   countVertLines;
     bool  visibleVertLines;

     // MinorLines
     int  countMinorLines;
     bool visibleMinorLines;

 public:
     grid(TChart* c);
     ~grid();

     void setCountHorizLines(int n);
     void setVisibleHorizLines(bool v);

     void setMinMaxBottomAxis(int min, int max);
     void setCountVertLines(int n);
     void setVisibleVertLines(bool v);

     void setCountMinorLines(int n);
     void setVisibleMinorLines(bool v);
};

#endif
 