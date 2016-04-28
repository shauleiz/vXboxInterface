#include <Xinput.h>

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the VDEVINTERFACE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// VDEVINTERFACE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef VDEVINTERFACE_EXPORTS
#define VDEVINTERFACE_API __declspec(dllexport)
#else
#define VDEVINTERFACE_API __declspec(dllimport)
#endif

//namespace TmpNS {
	extern "C"
	{
		/// Status
		inline VDEVINTERFACE_API BOOL 	__cdecl	 isVBusExists(void);
		inline VDEVINTERFACE_API BOOL	__cdecl	 GetNumEmptyBusSlots(UCHAR * nSlots);
		inline VDEVINTERFACE_API BOOL	__cdecl	 isControllerExists(UINT UserIndex);
		inline VDEVINTERFACE_API BOOL	__cdecl	 isControllerOwned(UINT UserIndex);


		// Virtual device Plug-In/Unplug
		inline VDEVINTERFACE_API BOOL	__cdecl	 PlugIn(UINT UserIndex);
		inline VDEVINTERFACE_API BOOL	__cdecl	 UnPlug(UINT UserIndex);
		inline VDEVINTERFACE_API BOOL	__cdecl	 UnPlugForce(UINT UserIndex);

		// Data Transfer (Data to the device)
		inline VDEVINTERFACE_API BOOL	__cdecl	 SetBtnA(UINT UserIndex, BOOL Press);
		inline VDEVINTERFACE_API BOOL	__cdecl	 SetBtnB(UINT UserIndex, BOOL Press);
		inline VDEVINTERFACE_API BOOL	__cdecl	 SetBtnX(UINT UserIndex, BOOL Press);
		inline VDEVINTERFACE_API BOOL	__cdecl	 SetBtnY(UINT UserIndex, BOOL Press);
		inline VDEVINTERFACE_API BOOL	__cdecl	 SetBtnStart(UINT UserIndex, BOOL Press);
		inline VDEVINTERFACE_API BOOL	__cdecl	 SetBtnBack(UINT UserIndex, BOOL Press);
		inline VDEVINTERFACE_API BOOL	__cdecl	 SetBtnLT(UINT UserIndex, BOOL Press); // Left Thumb/Stick
		inline VDEVINTERFACE_API BOOL	__cdecl	 SetBtnRT(UINT UserIndex, BOOL Press); // Right Thumb/Stick
		inline VDEVINTERFACE_API BOOL	__cdecl	 SetBtnLB(UINT UserIndex, BOOL Press); // Left Bumper
		inline VDEVINTERFACE_API BOOL	__cdecl	 SetBtnRB(UINT UserIndex, BOOL Press); // Right Bumper
		inline VDEVINTERFACE_API BOOL	__cdecl	 SetTriggerL(UINT UserIndex, BYTE Value); // Left Trigger
		inline VDEVINTERFACE_API BOOL	__cdecl	 SetTriggerR(UINT UserIndex, BYTE Value); // Right Trigger
		inline VDEVINTERFACE_API BOOL	__cdecl	 SetAxisX(UINT UserIndex, SHORT Value); // Left Stick X
		inline VDEVINTERFACE_API BOOL	__cdecl	 SetAxisY(UINT UserIndex, SHORT Value); // Left Stick Y
		inline VDEVINTERFACE_API BOOL	__cdecl	 SetAxisRx(UINT UserIndex, SHORT Value); // Right Stick X
		inline VDEVINTERFACE_API BOOL	__cdecl	 SetAxisRy(UINT UserIndex, SHORT Value); // Right Stick Y
		inline VDEVINTERFACE_API BOOL	__cdecl	 SetDpadUp(UINT UserIndex);
		inline VDEVINTERFACE_API BOOL	__cdecl	 SetDpadRight(UINT UserIndex);
		inline VDEVINTERFACE_API BOOL	__cdecl	 SetDpadDown(UINT UserIndex);
		inline VDEVINTERFACE_API BOOL	__cdecl	 SetDpadLeft(UINT UserIndex);
		inline VDEVINTERFACE_API BOOL	__cdecl	 SetDpadOff(UINT UserIndex);
		inline VDEVINTERFACE_API BOOL __cdecl	 SetDpad(UINT UserIndex, INT Value);

		// Data Transfer (Feedback from the device)
		inline VDEVINTERFACE_API BOOL	__cdecl	 GetLedNumber(UINT UserIndex, PBYTE pLed);
		inline VDEVINTERFACE_API BOOL	__cdecl	 GetVibration(UINT UserIndex, PXINPUT_VIBRATION pVib);
	}

//}