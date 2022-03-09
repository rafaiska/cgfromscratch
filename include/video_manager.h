#ifndef VIDEO_H_
#define VIDEO_H_

#include <SDL/SDL.h>

class Position {
	int x;
	int y;

public:
	Position(int p_x, int p_y): x(p_x), y(p_y){}
	void set(int p_x, int p_y){x = p_x; y = p_y;}
	int getx() const {return x;}
	int gety() const {return y;}
	Position operator+(Position p);
};

class VideoManager {
	SDL_Surface* mainScreen;
	Position newOrigin = Position(0, 0);

	Uint32 getIntColor(const SDL_Color& color);
	void changeSurfacePixel(const Position& pos, const SDL_Color& color);

public:
	VideoManager(int width, int height);
	~VideoManager();
	void wait(int ms);
	void putPixel(const Position& pos, const SDL_Color& color);
	void clearScreen();
};

#endif
