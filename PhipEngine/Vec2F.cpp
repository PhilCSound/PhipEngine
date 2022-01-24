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

float Vec2F::DotProduct(const Vec2F & _Vec)
{
	return X * _Vec.X + Y * _Vec.Y;
}

bool Vec2F::IsZero()
{
	return ((X == 0) && (Y == 0));
}

//Tells if two vectors are 90 degrees from each other, it doesn't tell you if they intersect however.
bool Vec2F::CheckPerpendicular(const Vec2F & _Vec)
{
	return !DotProduct(_Vec);
}
