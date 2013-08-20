#ifndef MainDefH
#define MainDefH
//---------------------------------------------------------------------------
typedef long double LD;
//---------------------------------------------------------------------------
struct TPointLD
{
	LD X;
   LD Y;
};
//---------------------------------------------------------------------------
struct TRectLD
{
	LD Left;
   LD Top;
   LD Right;
   LD Bottom;
	LD Width() const {return Right - Left;}
  	LD Height() const {return Bottom - Top ;}
   bool InRect(LD X, LD Y) const
   {
   	if(X >= Left && Y >= Top && X <= Right && Y <= Bottom)
      	return true;
      else
      	return false;
   }
};
//---------------------------------------------------------------------------
TPointLD PointLD(LD X, LD Y)
{
   TPointLD Point;
   Point.X = X;
   Point.Y = Y;
   return Point;
}
//---------------------------------------------------------------------------
TRectLD RectLD(LD Left, LD Top, LD Right, LD Bottom)
{
	TRectLD Rect;
   Rect.Left = Left;
   Rect.Top = Top;
   Rect.Right = Right;
   Rect.Bottom = Bottom;
   return Rect;
}
//---------------------------------------------------------------------------
#endif
