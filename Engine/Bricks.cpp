#include "Bricks.h"

void BrickFrield::Init()
{
	for ( int y = 0; y < Rows; ++y )
	{
		for ( int x = 0; x < Collums; ++x )
		{
			bricks[y * Collums + x].setPos( Vector( x + 1.0f,y + 1.0f ) );
		}
	}
}

void BrickFrield::Draw( Graphics& gfx ) const
{
	for ( int y = 0; y < Rows; ++y )
	{
		for ( int x = 0; x < Collums; ++x )
		{
			if ( !Distroid[y * Collums + x] )
			{
				bricks[y * Collums + x].Draw( gfx );
			}
		}
	}
}

bool BrickFrield::isCollidingWith( const HitBox& ball_hb )
{
	for ( int y = 0; y < Rows; ++y )
	{
		for ( int x = 0; x < Collums; ++x )
		{
			if ( bricks[y * Collums + x].getHitBox().isOverlappingWith( ball_hb ) && !Distroid[y * Collums + x] )
			{
				Distroid[y * Collums + x] = true;
				return true;
			}
		}
	}
	return false;
}

void BrickFrield::Brick::setPos( Vector& pos_in )
{
	pos = pos_in;
}

void BrickFrield::Brick::Draw( Graphics& gfx ) const
{
	gfx.DrawRectHB( getHitBox().expand( -1.0f ),BrickColor );
}

HitBox BrickFrield::Brick::getHitBox() const
{
	return HitBox( pos * Vector( BrickWidth,BrickHeight ),BrickWidth,BrickHeight );
}
