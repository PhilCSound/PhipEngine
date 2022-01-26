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

bool Vec2F::operator==(const Vec2F & _RHS) const
{
	return ((X == _RHS.X) && (Y == _RHS.Y));
}

const std::string Vec2F::ToString()
{
	return "X: " + std::to_string(X) + ". Y: " + std::to_string(Y) + ".";
}

float Vec2F::DotProduct(const Vec2F & _Vec)
{
	return X * _Vec.X + Y * _Vec.Y;
}

float Vec2F::CrossProduct(const Vec2F & _Vec1)
{
	return X * _Vec1.Y - Y * _Vec1.X;
}

float Vec2F::Distance(const Vec2F & _Vec1)
{
	float _x = _Vec1.X - X;
	float _y = _Vec1.Y - Y;
	return std::sqrtf(_x * _x + _y * _y);
}

float Vec2F::Angle(const Vec2F & _Vec1)
{
	float _x = _Vec1.X - X;
	float _y = _Vec1.Y - Y;
	return std::atan2f(_y, _x);
}

void Vec2F::Normalize()
{
	if (*this == Zero)
		return;

	float _mag = std::sqrtf(X * X + Y * Y);
	X /= _mag;
	Y /= _mag;
}

float Vec2F::DotProduct(const Vec2F & _Vec1, const Vec2F & _Vec2)
{
	return _Vec1.X * _Vec2.X + _Vec1.Y * _Vec2.Y;
}

float Vec2F::CrossProduct(const Vec2F & _Vec1, const Vec2F & _Vec2)
{
	return _Vec1.X * _Vec2.Y - _Vec1.Y * _Vec2.X;
}

bool Vec2F::CheckPerpendicular(const Vec2F & _Vec1, const Vec2F & _Vec2)
{
	if (DotProduct(_Vec1, _Vec2) == 0.0f)
		return true;
	return false;
}

float Vec2F::Distance(const Vec2F & _Vec1, const Vec2F & _Vec2)
{
	float _x = _Vec2.X - _Vec1.X;
	float _y = _Vec2.Y - _Vec1.Y;
	return std::sqrtf(_x * _x + _y * _y);
}

float Vec2F::Angle(const Vec2F & _Vec1, const Vec2F & _Vec2)
{
	float _x = _Vec2.X - _Vec1.X;
	float _y = _Vec2.Y - _Vec1.Y;
	return std::atan2f(_y, _x);
}

Vec2F Vec2F::Normalize(const Vec2F & _Vec1)
{
	if (_Vec1 == Zero)
		return _Vec1;
	float _mag = std::sqrtf(_Vec1.X * _Vec1.X + _Vec1.Y * _Vec1.Y);
	return Vec2F(_Vec1.X / _mag, _Vec1.Y / _mag);
}

const Vec2F Vec2F::Zero = Vec2F(0, 0);
