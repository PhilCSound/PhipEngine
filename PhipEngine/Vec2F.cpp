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

Vec2F & Vec2F::operator+=(const Vec2F & _RHS)
{
	X += _RHS.X;
	Y += _RHS.Y;
	return *this;
}

Vec2F Vec2F::operator-(const Vec2F & _RHS)
{
	return Vec2F(X - _RHS.X, Y - _RHS.Y);
}

Vec2F & Vec2F::operator-=(const Vec2F & _RHS)
{
	X -= _RHS.X;
	Y -= _RHS.Y;
	return *this;
}

Vec2F Vec2F::operator*(int _RHS)
{
	return Vec2F(X * _RHS, Y * _RHS);
}

Vec2F Vec2F::operator*(float _RHS)
{
	return Vec2F(X * _RHS, Y * _RHS);
}

Vec2F & Vec2F::operator*=(int _RHS)
{
	X *= _RHS;
	Y *= _RHS;
	return *this;
}

Vec2F & Vec2F::operator*=(float _RHS)
{
	X *= _RHS;
	Y *= _RHS;
	return *this;
}

bool Vec2F::operator==(const Vec2F & _RHS)
{
	return ((X == _RHS.X) && (Y = _RHS.Y));
}

const std::string Vec2F::ToString()
{
	return "X: " + std::to_string(X) + ". Y: " + std::to_string(Y) + ".";
}