/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
    :
    wnd( wnd ),
    gfx( wnd ),
    wall( 0.0f,gfx.ScreenWidth,0.0f,gfx.ScreenHeight ),
    ball( { gfx.ScreenWidth / 2,gfx.ScreenHeight - 100 },{ 2,-5 } ),
    pad( { gfx.ScreenWidth / 2,gfx.ScreenHeight - 20 } )
{
    bf.Init();
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
    if ( !gameOver )
    {
        if ( wnd.kbd.KeyIsPressed( VK_LEFT ) )
        {
            dir = { -1,0 };
        }
        else if ( wnd.kbd.KeyIsPressed( VK_RIGHT ) )
        {
            dir = { 1,0 };
        }
        else
        {
            dir = { 0,0 };
        }
        if ( !( pad.isCollidingWall( wall.left,-1 ) && dir.x == -1 || pad.isCollidingWall( wall.right,1 ) && dir.x == 1 ) )
        {
            pad.Move( dir );
        }
        ball.MoveBy();
        if ( ball.getHitBox().bottem >= wall.bottem )
        {
            gameOver = true;
        }
        ball.isCollidingWith( wall );
        if ( bf.isCollidingWith( ball.getHitBox() ) || pad.isCollidingWith( ball.getHitBox() ) )
        {
            ball.ReboundY();
        }
    }
}

void Game::ComposeFrame()
{
    ball.Draw( gfx );
    bf.Draw( gfx );
    pad.Draw( gfx );
}
