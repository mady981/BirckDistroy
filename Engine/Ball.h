#pragma once
#include "Vector.h"
#include "HitBox.h"
#include "Graphics.h"
class Ball
{
public:
	Ball( const Vector& pos_in,const Vector& vel_in );
	void MoveBy();
	void Draw( Graphics& gfx ) const;
	bool isCollidingWith( const HitBox& wall );
	void ReboundX();
	void ReboundY();
	HitBox getHitBox() const;
private:
	static constexpr int radius = 10;
	static constexpr Color BallColor = { 255,255,0 };
	Vector pos; 
	Vector vel;
};

