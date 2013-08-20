#ifndef IOErrorH
#define IOErrorH
//---------------------------------------------------------------------------
#define ERRMSGIO(hwnd, Msg)\
	(MessageBox((hwnd), (Msg), "IOError", MB_OK | MB_ICONERROR))
//---------------------------------------------------------------------------
#endif
