#pragma once
#include "Vector.h"
class HitBox
{
public:
	HitBox() = default;
	HitBox( float left_in,float right_in,float top_in,float bottem_in );
	HitBox( const Vector& topleft,const Vector& bottemright );
	HitBox( const Vector& topleft,float width,float height );
	HitBox getexpand( float val );
	HitBox& expand( float val );
	bool isOverlappingWith( const HitBox& other ) const;
	bool isOverlappingWith( const Vector& other ) const;
	static HitBox fromCenter( const Vector & center,float half_width,float half_height );
public:
	float left;
	float right;
	float top;
	float bottem;
};
