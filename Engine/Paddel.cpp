#include "Paddel.h"

Paddel::Paddel( const Vector& pos_in )
	:
	pos( pos_in )
{
}

void Paddel::Move( const Vector& dir )
{
	pos += dir * speed;
}

void Paddel::Draw( Graphics& gfx ) const
{
	gfx.DrawRectHB( getHitBox(),PaddelColor );
}

bool Paddel::isCollidingWith( const HitBox& ball )
{
	if ( getHitBox().isOverlappingWith( ball ) )
	{
		return true;
	}
	return false;
}

bool Paddel::isCollidingWall( float wall,int lr )
{
	bool colliding = false;
	const HitBox hb = getHitBox();
	if ( lr == -1 )
	{
		if ( hb.left <= wall )
		{
			pos.x += hb.left - wall;
			colliding = true;
		}
	}
	else if ( lr == 1 )
	{
		if ( hb.right >= wall )
		{
			pos.x += hb.right - wall;
			colliding = true;
		}
	}
	return colliding;
}

HitBox Paddel::getHitBox() const
{
	return HitBox::fromCenter( pos,width / 2,height / 2 );
}
