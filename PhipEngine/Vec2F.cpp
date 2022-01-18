#include "Vec2F.h"

//TODO: Templates. For now I am implementing as a Vec2 Float
//TODO: Finish writing this.

Vec2F::Vec2F(float _x, float _y) : X(_x), Y(_y)
{
}

Vec2F Vec2F::operator+(const Vec2F & _RHS)
{
	return Vec2F(X + _RHS.X, Y + _RHS.Y);
}

Vec2F Vec2F::operator-(const Vec2F & _RHS)
{
	return Vec2F(X - _RHS.X, Y - _RHS.Y);
}

bool Vec2F::operator==(const Vec2F & _RHS)
{
	return ((X == _RHS.X) && (Y = _RHS.Y));
}
