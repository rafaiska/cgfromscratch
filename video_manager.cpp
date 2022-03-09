/*
 * video_manager.c
 *
 *  Created on: 9 de mar. de 2022
 *      Author: rafael
 */

#include "video_manager.h"

Position Position::operator+(Position p) {
	return Position(this->getx() + p.getx(), this->gety() + p.gety());
}

VideoManager::VideoManager(int width, int height) {
	SDL_Init(SDL_INIT_VIDEO);
	mainScreen = SDL_SetVideoMode(width, height, 32, 0);
	newOrigin.set(width/2, height/2);
}

VideoManager::~VideoManager() {
	SDL_Quit();
}

Uint32 VideoManager::getIntColor(const SDL_Color& color) {
	Uint32 rVal = color.r << 16;
	Uint32 gVal = color.g << 8;
	Uint32 bVal = color.b << 0;
	return rVal + gVal + bVal;
}

void VideoManager::wait(int ms) {
	SDL_Delay(5000);
}

void VideoManager::changeSurfacePixel(const Position& pos, const SDL_Color& color) {
	Uint32 intcolor = getIntColor(color);
	Uint32 * const target_pixel = (Uint32 *) ((Uint8 *) mainScreen->pixels
	                                             + pos.gety() * mainScreen->pitch
	                                             + pos.getx() * mainScreen->format->BytesPerPixel);
	*target_pixel = intcolor;
}

void VideoManager::putPixel(const Position& pos, const SDL_Color& color) {
	Position corrected = newOrigin + pos;
	SDL_LockSurface(mainScreen);
	changeSurfacePixel(corrected, color);
	SDL_UnlockSurface(mainScreen);
	SDL_UpdateRect(mainScreen, 0, 0, 0, 0);
}

void VideoManager::clearScreen() {
	SDL_LockSurface(mainScreen);
	SDL_memset(mainScreen->pixels, 0, mainScreen->h * mainScreen->pitch);
	SDL_UnlockSurface(mainScreen);
}


