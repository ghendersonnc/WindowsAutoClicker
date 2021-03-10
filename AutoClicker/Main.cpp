#include <iostream>
#include <Windows.h>
#include "Clickers.h"

// Clicks 20 times per second
using namespace clicks;

int main() {
	
	std::cout << "Press F8 to start autoclick" << std::endl;
	std::cout << "Press F9 to start autoclick (Locks cursor in place" << std::endl;
	bool running = true;
	// F8 and F9 start autoclick

	while (running) {
		if (GetKeyState(VK_F8) & 1) {
			// Normal auto clicking
			autoClick();
		}

		if (GetKeyState(VK_F9) & 1) {
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



