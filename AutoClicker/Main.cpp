#include <iostream>
#include <Windows.h>
#include "Clickers.h"

// Clicks 20 times per second
using namespace clicks; // From Clickers.h

int main() {
	bool running = true;
	// Press NUMPAD5 to activate auto click
	while (running) {
		if (GetKeyState(VK_NUMPAD5) & 1) {
			// Normal auto clicking
			autoClick();
		}

		if (GetKeyState(VK_NUMPAD6) & 1) {
			// Locks cursor at current coordinates and auto clicks
			autoClickLock();
		}

		// Quit program, does not work while autoclicking is active
		if (GetKeyState(VK_ESCAPE) & 0x8000) {
			running = false;
		}

	}

	return 0;
}



