#ifndef UTILS_H_
#define UTILS_H_

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

#endif