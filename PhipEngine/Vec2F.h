#pragma once
#include <string>
#include "SFML/System.hpp"


//TODO: Templates. For now I am implementing as a Vec2 Float
//TODO: Finish writing this.
class Vec2F
{

public:
	//Member Functions
	Vec2F(float _x = 0, float _y = 0); //Constructor
	
	//sf::Vector2f ToSFMLVec2f();
	//const std::string ToString();
	Vec2F operator +(const Vec2F& _RHS);
	Vec2F operator -(const Vec2F& _RHS);
	bool operator ==(const Vec2F& _RHS);
	
	
	//Member Variables
	float X;
	float Y;



private:
};