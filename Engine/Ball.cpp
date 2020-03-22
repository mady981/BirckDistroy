#include "Ball.h"

Ball::Ball( const Vector& pos_in,const Vector& vel_in )
	:
	pos( pos_in ),
	vel( vel_in )
{
}

void Ball::MoveBy()
{
	pos += vel;
}

void Ball::Draw( Graphics& gfx ) const
{
	gfx.DrawBall( pos,radius,BallColor );
}

bool Ball::isCollidingWith( const HitBox& wall )
{
	bool colliding = false;
	const HitBox hb = getHitBox();
	if ( hb.left <= wall.left )
	{
		pos.x += hb.left - wall.left;
		ReboundX();
		colliding = true;
	}
	else if ( hb.right >= wall.right )
	{
		pos.x += hb.right - wall.right;
		ReboundX();
		colliding = true;
	}
	if ( hb.top <= wall.top )
	{
		pos.y += hb.top - wall.top;
		ReboundY();
		colliding = true;
	}
	else if ( hb.bottem >= wall.bottem )
	{
		pos.y += hb.bottem - wall.bottem;
		ReboundY();
		colliding = true;
	}
	return colliding;
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

HitBox Ball::getHitBox() const
{
	return HitBox::fromCenter( pos,radius,radius );
}
