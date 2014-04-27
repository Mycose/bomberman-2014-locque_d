//
// bomb_gl2d_btnloadgame.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Wed Jun  1 15:01:05 2011 pierre le
// Last update Sat Jun  4 11:05:28 2011 pierre le
//

#include	<iostream>

#include	"Image.hpp"

#include	"GameMenu.hh"
#include	"bomb_gl2d_btnloadgame.hh"


GlGraphics::LoadGameBtn::LoadGameBtn(const Vector3f &position)
  : GlButtonMenuItem(position, Vector3f(512.0f, 64.0f),
		     gdl::Image::load("./textures/load_game_flat.png"),
		     gdl::Image::load("./textures/load_game_highlight_flat.png"))
{
}


void		GlGraphics::LoadGameBtn::initialize(void)
{
}


void		GlGraphics::LoadGameBtn::OnItemUpdate(const gdl::GameClock &,
						     gdl::Input &)
{
}


void		GlGraphics::LoadGameBtn::OnMouseClick(void)
{
  GameMenu::_currentFrame = GameMenu::FRAME_LOADGAME;
}


void		GlGraphics::LoadGameBtn::OnMouseEnter(void)
{
}


void		GlGraphics::LoadGameBtn::OnMouseLeave(void)
{
}
