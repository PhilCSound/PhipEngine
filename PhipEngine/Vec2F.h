#pragma once
#include <string>
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
	bool operator ==(const Vec2F& _RHS);
	const std::string ToString();
	float DotProduct(const Vec2F& _Vec);
	bool IsZero();						//Change later with static consts
	bool CheckPerpendicular(const Vec2F& _Vec);

	//Member Variables
	float X;
	float Y;



private:
};