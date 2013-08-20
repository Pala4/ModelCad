//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <ddraw.h>

#include "DDErrors.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
LPSTR DDErrToStr(int DDResult)
{
	LPSTR S = "";
   switch (DDResult)
   {
		case DDERR_ALREADYINITIALIZED: S = "Already initialized"; break;
		case DDERR_CANNOTATTACHSURFACE: S = "Can\'t attach surface"; break;
		case DDERR_CANNOTDETACHSURFACE: S = "Cannot detach surface"; break;
		case DDERR_CURRENTLYNOTAVAIL: S = "Currently not available"; break;
		case DDERR_EXCEPTION: S = "Exception"; break;
		case DDERR_GENERIC: S = "E_FAIL"; break;
		case DDERR_HEIGHTALIGN: S = "Height align"; break;
		case DDERR_INCOMPATIBLEPRIMARY: S = "Incompatible primary"; break;
		case DDERR_INVALIDCAPS: S = "Invalid caps"; break;
		case DDERR_INVALIDCLIPLIST: S = "Invalid clip list"; break;
		case DDERR_INVALIDMODE: S = "Invalid mode"; break;
		case DDERR_INVALIDOBJECT: S = "Invalid object"; break;
		case DDERR_INVALIDPARAMS: S = "E_INVALIDARG"; break;
		case DDERR_INVALIDPIXELFORMAT: S = "Invalid pixel format"; break;
		case DDERR_INVALIDRECT: S = "Invalid rectangle"; break;
		case DDERR_LOCKEDSURFACES: S = "Locked surfaces"; break;
		case DDERR_NO3D: S = "No 3D"; break;
		case DDERR_NOALPHAHW: S = "No alpha HW"; break;
		case DDERR_NOCLIPLIST: S = "No clip list"; break;
		case DDERR_NOCOLORCONVHW: S = "No color conv HW"; break;
		case DDERR_NOCOOPERATIVELEVELSET: S = "No cooperative level set"; break;
		case DDERR_NOCOLORKEY: S = "No color key"; break;
		case DDERR_NOCOLORKEYHW: S = "No color key HW"; break;
		case DDERR_NODIRECTDRAWSUPPORT: S = "No direct draw support"; break;
		case DDERR_NOEXCLUSIVEMODE: S = "No exclusive mode"; break;
		case DDERR_NOFLIPHW: S = "No flip HW"; break;
		case DDERR_NOGDI: S = "No GDI"; break;
		case DDERR_NOMIRRORHW: S = "No mirror HW"; break;
		case DDERR_NOTFOUND: S = "Not found"; break;
		case DDERR_NOOVERLAYHW: S = "No overlay HW"; break;
		case DDERR_NORASTEROPHW: S = "No rasterop HW"; break;
		case DDERR_NOROTATIONHW: S = "No rotation HW"; break;
		case DDERR_NOSTRETCHHW: S = "No stretch HW"; break;
		case DDERR_NOT4BITCOLOR: S = "Not 4-bit color"; break;
		case DDERR_NOT4BITCOLORINDEX: S = "Not 4-bit color index"; break;
		case DDERR_NOT8BITCOLOR: S = "Not 8-bit color"; break;
		case DDERR_NOTEXTUREHW: S = "No texture HW"; break;
		case DDERR_NOVSYNCHW: S = "No V sync HW"; break;
		case DDERR_NOZBUFFERHW: S = "No Z buffer HW"; break;
		case DDERR_NOZOVERLAYHW: S = "No Z overlay HW"; break;
		case DDERR_OUTOFCAPS: S = "Out of caps"; break;
		case DDERR_OUTOFMEMORY: S = "Out of memory"; break;
		case DDERR_OUTOFVIDEOMEMORY: S = "Out of video memory"; break;
		case DDERR_OVERLAYCANTCLIP: S = "Overlay can'\t clip"; break;
		case DDERR_OVERLAYCOLORKEYONLYONEACTIVE: S = "Overlay color key only one active"; break;
		case DDERR_PALETTEBUSY: S = "Palette busy"; break;
		case DDERR_COLORKEYNOTSET: S = "Color key not set"; break;
		case DDERR_SURFACEALREADYATTACHED: S = "Surface already attached"; break;
		case DDERR_SURFACEALREADYDEPENDENT: S = "Surface already dependent"; break;
		case DDERR_SURFACEBUSY: S = "Surface busy"; break;
		case DDERR_SURFACEISOBSCURED: S = "Surface is obscured"; break;
		case DDERR_SURFACELOST: S = "Surface lost"; break;
		case DDERR_SURFACENOTATTACHED: S = "Surface not attached"; break;
		case DDERR_TOOBIGHEIGHT: S = "Too big height"; break;
		case DDERR_TOOBIGSIZE: S = "Too big size"; break;
		case DDERR_TOOBIGWIDTH: S = "Too big width"; break;
		case DDERR_UNSUPPORTED: S = "Unsupported"; break;
		case DDERR_UNSUPPORTEDFORMAT: S = "Unsupported format"; break;
		case DDERR_UNSUPPORTEDMASK: S = "Unsupported mask"; break;
		case DDERR_VERTICALBLANKINPROGRESS: S = "Vertical blank in progress"; break;
		case DDERR_WASSTILLDRAWING: S = "Was still drawing"; break;
		case DDERR_XALIGN: S = "X align"; break;
		case DDERR_INVALIDDIRECTDRAWGUID: S = "Invalid DirectDraw GUID"; break;
		case DDERR_DIRECTDRAWALREADYCREATED: S = "DirectDraw already created"; break;
		case DDERR_NODIRECTDRAWHW: S = "No DirectDraw HW"; break;
		case DDERR_PRIMARYSURFACEALREADYEXISTS: S = "Primary surface already exists"; break;
		case DDERR_NOEMULATION: S = "No emulation"; break;
		case DDERR_REGIONTOOSMALL: S = "Region too small"; break;
		case DDERR_CLIPPERISUSINGHWND: S = "Clipper is using HWND"; break;
		case DDERR_NOCLIPPERATTACHED: S = "No clipper attached"; break;
		case DDERR_NOHWND: S = "No HWND"; break;
		case DDERR_HWNDSUBCLASSED: S = "HWND subclassed"; break;
		case DDERR_HWNDALREADYSET: S = "HWND already set"; break;
		case DDERR_NOPALETTEATTACHED: S = "No palette attached"; break;
		case DDERR_NOPALETTEHW: S = "No palette HW"; break;
		case DDERR_BLTFASTCANTCLIP: S = "BltFast can\'t clip"; break;
		case DDERR_NOBLTHW: S = "No blt HW"; break;
		case DDERR_NODDROPSHW: S = "No ddrops HW"; break;
		case DDERR_OVERLAYNOTVISIBLE: S = "Overlay not visible"; break;
		case DDERR_NOOVERLAYDEST: S = "No overlay dest"; break;
		case DDERR_INVALIDPOSITION: S = "Invalid position"; break;
		case DDERR_NOTAOVERLAYSURFACE: S = "Not an overlay surface"; break;
		case DDERR_EXCLUSIVEMODEALREADYSET: S = "Exclusive mode already set"; break;
		case DDERR_NOTFLIPPABLE: S = "Not flippable"; break;
		case DDERR_CANTDUPLICATE: S = "Can\'t duplicate"; break;
		case DDERR_NOTLOCKED: S = "Not locked"; break;
		case DDERR_CANTCREATEDC: S = "Can\'t create DC"; break;
		case DDERR_NODC: S = "No DC"; break;
		case DDERR_WRONGMODE: S = "Wrong mode"; break;
		case DDERR_IMPLICITLYCREATED: S = "Implicitly created"; break;
		case DDERR_NOTPALETTIZED: S = "Not palettized"; break;
		case DDERR_UNSUPPORTEDMODE: S = "Unsupported mode"; break;
		default: S = "Unknown"; break;
   }
   return S;
}
//---------------------------------------------------------------------------
