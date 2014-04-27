//
// bomb_gl2d_btnhighscores.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects2D
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri Jun  3 11:40:29 2011 pierre le
// Last update Fri Jun  3 15:21:02 2011 pierre le
//

#include	<iostream>

#include	"GameMenu.hh"
#include	"Image.hpp"

#include	"bomb_gl2d_btnhighscores.hh"


GlGraphics::HighscoresBtn::HighscoresBtn(const Vector3f &position)
  : GlButtonMenuItem(position, Vector3f(512.0f, 64.0f),
		     gdl::Image::load("./textures/highscores_flat.png"),
		     gdl::Image::load("./textures/highscores_highlight_flat.png"))
{
}


void		GlGraphics::HighscoresBtn::initialize(void)
{
}


void		GlGraphics::HighscoresBtn::OnItemUpdate(const gdl::GameClock &,
						     gdl::Input &)
{
}


void		GlGraphics::HighscoresBtn::OnMouseClick(void)
{
  GameMenu::_currentFrame = GameMenu::FRAME_SCORES;
}


void		GlGraphics::HighscoresBtn::OnMouseEnter(void)
{
}


void		GlGraphics::HighscoresBtn::OnMouseLeave(void)
{
}
