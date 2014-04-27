//
// bomb_gl_objstrongwall.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/workshop/engine/objects
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Wed May  4 10:28:06 2011 pierre le
// Last update Fri Jun  3 10:16:58 2011 pierre le
//

#include	<GL/gl.h>

#include	"bomb_gl_rendercontext.hh"
#include	"bomb_gl_drawableobjs.hh"


GlGraphics::DrawableObj::StrongWall::StrongWall(const Vector3f &position)
  : GlTexturedSquare(position, B_SOLID_WALL)
{
}


void		GlGraphics::DrawableObj::StrongWall::initialize(void)
{
}


void		GlGraphics::DrawableObj::StrongWall::update(gdl::GameClock const &,
							    gdl::Input &)
{
}
