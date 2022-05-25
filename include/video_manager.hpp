#ifndef VIDEO_H_
#define VIDEO_H_

#include <SDL/SDL.h>
#include "utils.hpp"



class VideoManager {
	SDL_Surface* mainScreen;
	Position2D<int> newOrigin = Position2D<int>(0, 0);

	Uint32 getIntColor(const SDL_Color& color);
	void changeSurfacePixel(const Position2D<int>& pos, const SDL_Color& color);

public:
	VideoManager(int width, int height);
	~VideoManager();
	void wait(int ms);
	void putPixel(const Position2D<int>& pos, const SDL_Color& color);
	void clearScreen();
};

#endif
