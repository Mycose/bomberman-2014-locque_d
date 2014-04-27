//
// bomb_gl2d_picturebox.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects2D
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Thu Jun  2 17:52:52 2011 pierre le
// Last update Sun Jun  5 14:33:23 2011 pierre le
//

#include	<iostream>

#include	"Image.hpp"

#include	"bomb_gl2d_picturebox.hh"


GlGraphics::PictureBox::PictureBox(const Vector3f &position,
				   const Vector3f &size,
				   const gdl::Image &picture)
  : GlMenuItem(position, size, picture)
{
}


void		GlGraphics::PictureBox::initialize(void)
{
}


void		GlGraphics::PictureBox::OnItemUpdate(const gdl::GameClock &,
						     gdl::Input &)
{
}


void		GlGraphics::PictureBox::OnMouseClick(void)
{
}


void		GlGraphics::PictureBox::OnMouseEnter(void)
{
}


void		GlGraphics::PictureBox::OnMouseLeave(void)
{
}


void		GlGraphics::PictureBox::setPosition(float x, float y)
{
  _position.x = x;
  _position.y = y;
}


void		GlGraphics::PictureBox::setPosX(float x)
{
  _position.x = x;
}


void		GlGraphics::PictureBox::setPosY(float y)
{
  _position.y = y;
}


const GlGraphics::Vector3f &	GlGraphics::PictureBox::getPosition(void) const
{
  return (_position);
}


float		GlGraphics::PictureBox::getPosX(void) const
{
  return (_position.x);
}


float		GlGraphics::PictureBox::getPosY(void) const
{
  return (_position.y);
}
