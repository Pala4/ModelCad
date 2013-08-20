//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <stdlib.h>
#include <time.h>

USERES("MCad.res");
USEFORM("GrpFrm.cpp", Form_Grafic);
USEUNIT("compl.cpp");
USEUNIT("MCBase.cpp");
USEUNIT("MCFile.cpp");
USEUNIT("MCOptions.cpp");
USEUNIT("MCSys.cpp");
USEUNIT("nrutil.cpp");
USEFORM("Unit_VvodPerFunc.cpp", Form_PerFunc);
USEUNIT("polynom.cpp");
USEFORM("ProjFrm.cpp", FProj);
USEFORM("OptionsFrm.cpp", FOptions);
USERES("MCadZ.res");
USEUNIT("GrpApi\Grp.cpp");
USEFORM("GrpApi\PropFrm.cpp", FProperty);
USEUNIT("Els.cpp");
USEUNIT("MCProj.cpp");
USEUNIT("MCApp.cpp");
USEFORM("MainFrm.cpp", FMain);
USELIB("Videvo\ddraw.lib");
USEUNIT("MCElBts.cpp");
USEFORM("SmPropFrm.cpp", FSmProp);
USEFORM("InPropFrm.cpp", FInProp);
USEUNIT("Elements\MCElement.cpp");
USEUNIT("Elements\MCStdElement.cpp");
USEUNIT("Elements\MCLink.cpp");
USEUNIT("Elements\Z\MCZ.cpp");
USEUNIT("Elements\K\MCK.cpp");
USEFORM("Elements\K\KPropFrm.cpp", FKProp);
USEUNIT("Elements\1P\MC1P.cpp");
USEUNIT("Elements\Free\MCFree.cpp");
USEUNIT("Elements\Sinus\MCSinus.cpp");
USEFORM("Elements\Sinus\SinPropFrm.cpp", FSinProp);
USEUNIT("Elements\NoSense\MCNoSense.cpp");
USEFORM("Elements\NoSense\NoSensePropFrm.cpp", FNoSenseProp);
USEUNIT("Elements\Rest\MCRest.cpp");
USEFORM("Elements\Rest\RestPropFrm.cpp", FRestProp);
USEUNIT("Elements\NoSenseRest\MCNoSenseRest.cpp");
USEFORM("Elements\NoSenseRest\NoSenseRestPropFrm.cpp", FNoSenseRestProp);
USEUNIT("Elements\Luft\MCLuft.cpp");
USEFORM("Elements\Luft\LuftPropFrm.cpp", FLuftProp);
USEUNIT("Elements\UBRelay\MCUBRelay.cpp");
USEFORM("Elements\UBRelay\UBRelayFrm.cpp", FUBRelayProp);
USEUNIT("Elements\NUBRelay\MCNUBRelay.cpp");
USEFORM("Elements\NUBRelay\NUBRelayPropFrm.cpp", FNUBRelayProp);
USEUNIT("Elements\P\MCP.cpp");
USEFORM("Elements\1P\PPropFrm.cpp", F1PProp);
USEFORM("Elements\P\PRegPropFrm.cpp", FPProp);
USEUNIT("Elements\PD\MCPD.cpp");
USEFORM("Elements\PD\PDRegPropFrm.cpp", FPDProp);
USEUNIT("Elements\I\MCI.cpp");
USEFORM("Elements\I\IRegPropFrm.cpp", FIProp);
USEUNIT("Elements\PI\MCPI.cpp");
USEFORM("Elements\PI\PIRegPropFrm.cpp", FPIProp);
USEUNIT("Elements\PID\MCPID.cpp");
USEFORM("Elements\PID\PIDRegPropFrm.cpp", FPIDProp);
USEUNIT("Elements\TL\MCTL.cpp");
USEFORM("CalcParamFrm.cpp", FCalcParam);
USEFORM("Elements\TL\TransLinkPropFrm.cpp", FTransLinkProp);
USEFORM("Elements\TL\CharFrm.cpp", FChar);
USEFORM("Elements\TL\NPCharFrm.cpp", FNPChar);
USEFORM("AboutFrm.cpp", FAbout);
USEFORM("Elements\Free\FreePropFrm.cpp", FFreeProp);
USEFORM("GaussNoisePropFrm.cpp", FGaussNoiseProp);
USEFORM("Elements\Z\ZPropFrm.cpp", FZProp);
USEFORM("GrpApi\GrpWin.cpp", FGrp);
USEUNIT("Field\MCField.cpp");
USEUNIT("Field\MCRender.cpp");
USEUNIT("Field\MCDDRender.cpp");
USEUNIT("Field\DDErrors.cpp");
USEUNIT("MCClipBoard.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
 		Application->Initialize();
		Application->CreateForm(__classid(TFMain), &FMain);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	return 0;
}
//---------------------------------------------------------------------------
