// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include <stdio.h>

#include "..\API\vXboxInterface.h"

#ifndef XBOX
#pragma comment(lib, "vXboxInterface")
//#pragma comment(lib, "vXboxInterface-Static")

int main()
{
	BOOL res;
	UCHAR nEmpty;


	// Test if bus exists
	BOOL bus = isVBusExists();
	if (bus)
		printf("Virtual Xbox bus exists\n\n");
	else
	{
		printf("Virtual Xbox bus does NOT exist - Aborting\n\n");
		getchar();
		return -1;
	}




	// Install Virtual Devices
	for (UINT i = 0; i < 6; i++)
	{
		res = GetNumEmptyBusSlots(&nEmpty);
		if (res)
			printf("\n\nNumber of Empty Slots: %d\n",nEmpty);
		else
			printf("\n\nCannot determine Number of Empty Slots");

		res = isControllerExists(i);
		printf("\nisControllerExists(%d): %X\n", i, res);
		res = isControllerOwned(i);
		printf("\nisControllerOwned(%d): %X\n", i, res);
		res = PlugIn(i);
		printf("Plug-in device %d: %X\n", i, res);
		res = isControllerExists(i);
		printf("isControllerExists(%d): %X\n", i, res);
		res = isControllerOwned(i);
		printf("\nisControllerOwned(%d): %X\n", i, res);
	}
	printf("\n");
	SetTriggerL(2, 0);
	SetTriggerR(2, 0);

	for (int T = 0; T < 100; T++)
	{
		SetAxisX(1, T * 300);
		SetAxisY(1, (T * 300)*-1);
		SetAxisRx(1, T * 100);
		SetAxisRy(1, (T * 100)*-1);
		switch (T)
		{
			case 0:
				SetDpadUp(1);
				SetBtnA(1, FALSE);
				SetBtnB(1, TRUE);
				break;
			case 20:
				SetDpadRight(1);
				SetBtnB(1, FALSE);
				break;
			case 40:
				SetDpadDown(1);
				break;
			case 60:
				SetDpadLeft(1);
				break;
			case 80:
				SetDpad(1, DPAD_UP|DPAD_RIGHT);
				break;
			case 99:
				SetDpadOff(1);
				SetBtnA(1, TRUE);
				break;
		}
		
		SetTriggerL(1, 2 * T);
		SetTriggerR(1, 57 +(2 * T));
		Sleep(100);
	}
	SetTriggerL(1, 255);
	SetTriggerR(1, 255);

	printf("Press any key to detect device feedback \n");
	getchar();

	//WORD LeftMotor, RightMotor;
	UCHAR Led;
	BOOL Led_Ok, Vib_Ok;
	XINPUT_VIBRATION Vib;
	int iDev = 0;
	while (getchar() != 'q')
	{
		for (iDev = 1; iDev < 5; iDev++)
		{
			Led_Ok = GetLedNumber(iDev, &Led);
			Vib_Ok = GetVibration(iDev, &Vib);
			printf("LED: %d; Left Motor: %d; Right Motor: %d  \n", Led, Vib.wLeftMotorSpeed, Vib.wRightMotorSpeed);
		};
	}

	printf("Press any key to remove devices \n");
	getchar();

#if 1
	// UnInstall Virtual Devices
	for (UINT i = 0; i < 6; i++)
	{
		res = UnPlugForce(i);
		printf("UnPlug (Forced) device %d: %X\n", i, res);
	}
#endif // 0

	printf("Press any key to exit \n");
	getchar();

	return 0;

}
#else // XBOX
int main()
{
	printf("NOT Xbox mode\n");
	return 0;
}

#endif // XBOX 