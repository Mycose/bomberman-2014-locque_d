//
// bomb_gl_objbomb.cpp for Bobmerman in /home/le_b//projects/tek2/cpp/bomberman/workshop/engine/objects
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Tue May 10 12:36:30 2011 pierre le
// Last update Fri Jun  3 10:16:06 2011 pierre le
//

#include	<iostream>

#include	<GL/gl.h>

#include	"bomb_gl_drawableobjs.hh"

GlGraphics::DrawableObj::Bomb::Bomb(const Vector3f &position)
  : GlModelObj(position)
{
}


void		GlGraphics::DrawableObj::Bomb::initialize(void)
{
  this->_model = this->getModel(B_BOMB);
}


void		GlGraphics::DrawableObj::Bomb::update(gdl::GameClock const &clock,
						      gdl::Input &)
{
  this->_model.update(clock);
}


void		GlGraphics::DrawableObj::Bomb::draw(void)
{
  glPushMatrix();
  // Following additions are arbitrary and related to the model sizes.
  // May change depending on the model used.
  glTranslatef(_position.x + 120.0f,
	       _position.y + 120.0f,
	       _position.z);
  glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
  glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
  //  glScalef(1.0, .75, 1.0);
  this->_model.draw();
  glPopMatrix();
}
