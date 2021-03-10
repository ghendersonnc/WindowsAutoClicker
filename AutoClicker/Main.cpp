#include <iostream>
#include <Windows.h>

void lockCursor(POINT);
void mouseClick();

int main() {
	bool running = true;
	// Press NUMPAD5 to activate auto click
	while (running) {
		if (GetKeyState(VK_NUMPAD5) & 1) {
			mouseClick();
		}

		// Quit program, does not work while autoclicking is active
		if (GetKeyState(VK_ESCAPE) & 0x8000) {
			running = false;
		}
	}

	return 0;
}

// Maintains cursor coordinates
void lockCursor(POINT point) {
	while (GetKeyState(VK_NUMPAD0) == 1) {
		SetCursorPos(point.x, point.y);

	}
}

void mouseClick() {
	POINT point;
	// Auto clicks 10 times per second
	while (GetKeyState(VK_NUMPAD5) == 1) {
		GetCursorPos(&point);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

		// Pressing NUMPAD0 locks cursor in place
		if (GetKeyState(VK_NUMPAD0) & 1) {
			lockCursor(point);
		}

		Sleep(100);
	}
}