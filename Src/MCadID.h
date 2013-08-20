#ifndef _ICARID_H_
#define _ICARID_H_

enum T_ID
{
	ID_NONE,
   ID_ARROW,
   ID_STDELEMENT,
   ID_TRANSLINK,
   ID_Z,
   ID_SUMMATOR,
   ID_SUMMATOR1,
   ID_UNIT,
   ID_UZEL,
   ID_LINK,
   ID_IN,
   ID_OUT,
   ID_GAUSSNOISE,
   ID_SINUS,
   ID_FREE,
   ID_NOSENSE,
   ID_REST,
   ID_NOSENSEREST,
   ID_LUFT,
   ID_UBRELAY,
   ID_NUBRELAY,
   ID_K,
   ID_1P,
   ID_P,
   ID_PD,
   ID_I,
   ID_PI,
   ID_PID
};

enum T_ORIENT
{
   OR_NONE = 0,
	OR_LEFT = 1,
   OR_RIGHT = 2,
   OR_TOP = 4,
   OR_BOTTOM = 8,
   OR_BUSY = 16
};

enum T_TYPE_ID
{
	ID_INT = 0,
   ID_BOOL = 1,
   ID_LD = 2,
   ID_STRING = 4,
   ID_ARRAY = 8,
   ID_LONGDOUBLE = 16
};

#endif //ifndef _ICARID_H_
