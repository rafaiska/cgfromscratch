#ifndef VIDEO_H_
#define VIDEO_H_

#include <SDL/SDL.h>

template <class T> class Position2D {
public:
	T x;
	T y;
	Position2D(T p_x, T p_y): x(p_x), y(p_y){}
	Position2D<T> operator+(Position2D<T> p);
};

template <class T> class Position3D {
public:
	T x;
	T y;
	T z;
	Position3D(T p_x, T p_y, T p_z): x(p_x), y(p_y), z(p_z){}
	Position3D(Position2D<T> p2d);
	Position3D<T> operator+(Position3D<T> p);
};


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
