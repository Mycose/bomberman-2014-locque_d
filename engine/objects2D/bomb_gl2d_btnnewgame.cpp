//
// bomb_gl2d_btnnewgame.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Wed Jun  1 15:01:05 2011 pierre le
// Last update Fri Jun  3 17:09:05 2011 pierre le
//

#include	<iostream>

#include	"Image.hpp"

#include	"GameMenu.hh"
#include	"bomb_gl2d_btnnewgame.hh"


GlGraphics::NewGameBtn::NewGameBtn(const Vector3f &position)
  : GlButtonMenuItem(position, Vector3f(512.0f, 64.0f),
		     gdl::Image::load("./textures/new_game_flat.png"),
		     gdl::Image::load("./textures/new_game_highlight_flat.png"))
{
}


void		GlGraphics::NewGameBtn::initialize(void)
{
}


void		GlGraphics::NewGameBtn::OnItemUpdate(const gdl::GameClock &,
						     gdl::Input &)
{
}


void		GlGraphics::NewGameBtn::OnMouseClick(void)
{
  GameMenu::_currentFrame = GameMenu::FRAME_NEWGAME;
}


void		GlGraphics::NewGameBtn::OnMouseEnter(void)
{
}


void		GlGraphics::NewGameBtn::OnMouseLeave(void)
{
}
