/*
 * main.cpp
 *
 *  Created on: 7 de mar. de 2022
 *      Author: rafael
 */


#include "video_manager.hpp"

int main(int argc, char* argv[]) {
	VideoManager manager(300, 300);
	manager.clearScreen();
	SDL_Color color = {255, 255, 255};
	for(int i=0; i<20; ++i) {
		manager.putPixel(Position2D<int>(i, i), color);
	}
	manager.wait(5000);
}
