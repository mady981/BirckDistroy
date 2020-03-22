#pragma once
#include "Vector.h"
#include "HitBox.h"
#include "Graphics.h"

class BrickFrield
{
private:
	class Brick
	{
	public:
		void setPos( Vector& pos_in );
		void Draw( Graphics& gfx ) const;
		HitBox getHitBox() const;
	private:
		Vector pos;
	};
public:
	BrickFrield() = default;
	void Init();
	void Draw( Graphics& gfx ) const;
	bool isCollidingWith( const HitBox& ball_hb );
private:
	static constexpr int BrickWidth = 100;
	static constexpr int BrickHeight = 30;
	static constexpr int Rows = 4;
	static constexpr int Collums = Graphics::ScreenWidth / BrickWidth - 2;
	static constexpr Color BrickColor = { 128,128,128 };
private:
	Brick bricks[Collums * Rows];
	bool Distroid[Collums * Rows] = { false };
};