#pragma once
#include "Vector.h"
#include "HitBox.h"
#include "Graphics.h"
class Paddel
{
public:
	Paddel( const Vector& pos_in );
	void Move( const Vector& dir );
	void Draw( Graphics& gfx ) const;
	bool isCollidingWith( const HitBox& ball );
	bool isCollidingWall( float wall,int lr );
	HitBox getHitBox() const;
private:
	static constexpr int width = 100;
	static constexpr int height = 20;
	static constexpr Color PaddelColor = Colors::Blue;
	static constexpr float speed = 2.5f;
private:
	Vector pos;
};

