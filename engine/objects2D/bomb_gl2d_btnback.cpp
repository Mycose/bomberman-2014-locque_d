//
// bomb_gl2d_btnback.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/includes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri Jun  3 15:59:39 2011 pierre le
// Last update Fri Jun  3 16:09:32 2011 pierre le
//

#include	<iostream>

#include	"Image.hpp"

#include	"GameMenu.hh"

#include	"bomb_gl2d_btnback.hh"


GlGraphics::BackBtn::BackBtn(const Vector3f &position,
			     GameMenu::eMenuFrameId frameAction)
  : GlButtonMenuItem(position, Vector3f(48.0f, 48.0f),
		     gdl::Image::load("./textures/back_btn_flat.png"),
		     gdl::Image::load("./textures/back_btn_highlight_flat.png")),
    _frameAction(frameAction)
{
}


void		GlGraphics::BackBtn::initialize(void)
{
}


void		GlGraphics::BackBtn::OnItemUpdate(const gdl::GameClock &,
						     gdl::Input &)
{
}


void		GlGraphics::BackBtn::OnMouseClick(void)
{
  GameMenu::_currentFrame = _frameAction;
}


void		GlGraphics::BackBtn::OnMouseEnter(void)
{
}


void		GlGraphics::BackBtn::OnMouseLeave(void)
{
}
