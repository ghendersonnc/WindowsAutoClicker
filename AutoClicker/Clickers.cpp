#include <Windows.h>
#include "Clickers.h"
#include <iostream>

namespace clicks {
	void autoClick() {
		while (GetKeyState(VK_F8) & 1) {

			// Untoggle F9 if pressed while autoClick is active
			if (GetKeyState(VK_F9) & 1) {
				keybd_event(VK_F9, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
				keybd_event(VK_F9, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
			}

			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			Sleep(50);

		}
	}

	void autoClickLock() {
		POINT point;
		GetCursorPos(&point);

		while (GetKeyState(VK_F9) & 1) {

			// Untoggle F8 if pressed while autoClickLock is active
			if (GetKeyState(VK_F8) & 1) {
				keybd_event(VK_F8, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
				keybd_event(VK_F8, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
			}

			SetCursorPos(point.x, point.y);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			Sleep(50);

		}
	}
}