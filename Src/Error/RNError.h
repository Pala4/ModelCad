#ifndef RNErrorH
#define RNErrorH
//---------------------------------------------------------------------------
#define ERRMSGRN(hwnd, Msg)\
	(MessageBox((hwnd), (Msg), "Render Error", MB_OK | MB_ICONERROR))
#define ERR1 "ERR1: Ошибка инициализации рендеринга"
#define ERR2 "ERR2: Ошибка деинициализации рендеринга"
//---------------------------------------------------------------------------
#endif
