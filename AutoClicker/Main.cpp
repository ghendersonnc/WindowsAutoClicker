#include <iostream>
#include <Windows.h>

void autoClick();
void autoClickLock();

int main() {
	bool running = true;
	// Press NUMPAD5 to activate auto click
	while (running) {
		if (GetKeyState(VK_NUMPAD5) & 1) {
			autoClick();
		}

		if (GetKeyState(VK_NUMPAD6) & 1) {
			autoClickLock();
		}

		// Quit program, does not work while autoclicking is active
		if (GetKeyState(VK_ESCAPE) & 0x8000) {
			running = false;
		}

	}

	return 0;
}

void autoClick() {
	// Auto clicks 10 times per second
	while (GetKeyState(VK_NUMPAD5) & 1) {

		// Untoggle NUMPAD6 if pressed while autoClickLocl is active
		if (GetKeyState(VK_NUMPAD6) & 1) {
			keybd_event(VK_NUMPAD6, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
			keybd_event(VK_NUMPAD6, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
		}

		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		Sleep(50);
			
		std::cout << "press" << std::endl;
	}
}

void autoClickLock() {
	POINT point;
	GetCursorPos(&point);
	
	while (GetKeyState(VK_NUMPAD6) & 1) {

		// Untoggle NUMPAD5 if pressed while autoClickLock is active
		if (GetKeyState(VK_NUMPAD5) & 1) {
			keybd_event(VK_NUMPAD5, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
			keybd_event(VK_NUMPAD5, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
		}
		
		SetCursorPos(point.x, point.y);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		Sleep(50);

		std::cout << "press" << std::endl;
	}
}