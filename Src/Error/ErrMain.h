#ifndef ErrMainH
#define ErrMainH

#include <windows.h>

#include "IOError.h"
#include "RNError.h"
//---------------------------------------------------------------------------
#define ERRMSG(hwnd, Caption, Msg)\
	(MessageBox((hwnd), (Msg), (Caption), MB_OK | MB_ICONERROR))
//---------------------------------------------------------------------------
#endif
