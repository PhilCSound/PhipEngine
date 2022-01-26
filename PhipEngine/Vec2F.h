#pragma once
#include <string>
#include <cmath>
#include "SFML/System.hpp"


//TODO: Templates? For now I am implementing as a Vec2 Float
//TODO: Add more useful functions.
class Vec2F
{

public:
	//Member Functions
	Vec2F(float _x = 0, float _y = 0); //Constructor
	
	Vec2F operator +(const Vec2F& _RHS);
	Vec2F& operator +=(const Vec2F& _RHS);
	Vec2F operator -(const Vec2F& _RHS);
	Vec2F& operator -=(const Vec2F& _RHS);
	Vec2F operator *(int _RHS);
	Vec2F operator *(float _RHS);
	Vec2F& operator *=(int _RHS);
	Vec2F& operator *=(float _RHS);
	bool operator ==(const Vec2F& _RHS) const;
	const std::string ToString();
	float DotProduct(const Vec2F& _Vec1);
	float CrossProduct(const Vec2F& _Vec1);
	float Distance(const Vec2F& _Vec1);
	float Angle(const Vec2F& _Vec1);
	void Normalize();

	//Static Functions
	static float DotProduct(const Vec2F& _Vec1, const Vec2F& _Vec2);
	static float CrossProduct(const Vec2F& _Vec1, const Vec2F& _Vec2);
	static bool CheckPerpendicular(const Vec2F& _Vec1, const Vec2F& _Vec2);
	static float Distance(const Vec2F& _Vec1, const Vec2F& _Vec2);
	static float Angle(const Vec2F& _Vec1, const Vec2F& _Vec2);
	static Vec2F Normalize(const Vec2F& _Vec1);

	//Static Variables
	static const Vec2F Zero;

	//Member Variables
	float X;
	float Y;



private:
};