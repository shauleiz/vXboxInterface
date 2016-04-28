// vDevInterface.cpp : Defines the exported functions for the DLL application.
//
#pragma comment(lib, "vXboxInterface-Static")
#include "stdafx.h"
#include "..\API\vXboxInterface.h"
#include "vDevInterface.h"


extern "C"
{
	/// Status
	inline VDEVINTERFACE_API BOOL	__cdecl	 isVBusExists(void) { return  vXboxNS::isVBusExists(); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 GetNumEmptyBusSlots(UCHAR * nSlots) { return vXboxNS::GetNumEmptyBusSlots(nSlots); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 isControllerExists(UINT UserIndex) { return vXboxNS::isControllerExists(UserIndex); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 isControllerOwned(UINT UserIndex) { return vXboxNS::isControllerOwned(UserIndex); }


	// Virtual device Plug-In/Unplug
	inline VDEVINTERFACE_API BOOL	__cdecl	 PlugIn(UINT UserIndex) { return vXboxNS::PlugIn(UserIndex); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 UnPlug(UINT UserIndex) { return vXboxNS::UnPlug(UserIndex); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 UnPlugForce(UINT UserIndex) { return vXboxNS::UnPlugForce(UserIndex); }

	// Data Transfer (Data to the device)
	inline VDEVINTERFACE_API BOOL	__cdecl	 SetBtnA(UINT UserIndex, BOOL Press) { return vXboxNS::SetBtnA(UserIndex, Press); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 SetBtnB(UINT UserIndex, BOOL Press) { return vXboxNS::SetBtnB(UserIndex, Press); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 SetBtnX(UINT UserIndex, BOOL Press) { return vXboxNS::SetBtnX(UserIndex, Press); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 SetBtnY(UINT UserIndex, BOOL Press) { return vXboxNS::SetBtnY(UserIndex, Press); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 SetBtnStart(UINT UserIndex, BOOL Press) { return vXboxNS::SetBtnStart(UserIndex, Press); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 SetBtnBack(UINT UserIndex, BOOL Press) { return vXboxNS::SetBtnBack(UserIndex, Press); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 SetBtnLT(UINT UserIndex, BOOL Press) { return vXboxNS::SetBtnLT(UserIndex, Press); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 SetBtnRT(UINT UserIndex, BOOL Press) { return vXboxNS::SetBtnRT(UserIndex, Press); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 SetBtnLB(UINT UserIndex, BOOL Press) { return vXboxNS::SetBtnLB(UserIndex, Press); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 SetBtnRB(UINT UserIndex, BOOL Press) { return vXboxNS::SetBtnRB(UserIndex, Press); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 SetTriggerL(UINT UserIndex, BYTE Value) { return vXboxNS::SetTriggerL(UserIndex, Value); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 SetTriggerR(UINT UserIndex, BYTE Value) { return vXboxNS::SetTriggerR(UserIndex, Value); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 SetAxisX(UINT UserIndex, SHORT Value) { return vXboxNS::SetAxisX(UserIndex, Value); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 SetAxisY(UINT UserIndex, SHORT Value) { return vXboxNS::SetAxisY(UserIndex, Value); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 SetAxisRx(UINT UserIndex, SHORT Value) { return vXboxNS::SetAxisRx(UserIndex, Value); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 SetAxisRy(UINT UserIndex, SHORT Value) { return vXboxNS::SetAxisRy(UserIndex, Value); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 SetDpadUp(UINT UserIndex) { return vXboxNS::SetDpadUp(UserIndex); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 SetDpadRight(UINT UserIndex) { return vXboxNS::SetDpadRight(UserIndex); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 SetDpadDown(UINT UserIndex) { return vXboxNS::SetDpadDown(UserIndex); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 SetDpadLeft(UINT UserIndex) { return vXboxNS::SetDpadLeft(UserIndex); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 SetDpadOff(UINT UserIndex) { return vXboxNS::SetDpadOff(UserIndex); }
	inline VDEVINTERFACE_API BOOL __cdecl	 SetDpad(UINT UserIndex, INT Value) { return vXboxNS::SetDpad(UserIndex, Value); }

	// Data Transfer (Feedback from the device)
	inline VDEVINTERFACE_API BOOL	__cdecl	 GetLedNumber(UINT UserIndex, PBYTE pLed) { return vXboxNS::GetLedNumber(UserIndex, pLed); }
	inline VDEVINTERFACE_API BOOL	__cdecl	 GetVibration(UINT UserIndex, PXINPUT_VIBRATION pVib) { return vXboxNS::GetVibration(UserIndex, pVib); }
}
