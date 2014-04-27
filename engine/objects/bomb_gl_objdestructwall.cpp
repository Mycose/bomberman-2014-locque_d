//
// bomb_gl_objdestructwall.cpp for Bobmerman in /home/le_b//projects/tek2/cpp/bomberman/workshop/engine/objects
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Tue May 10 12:02:11 2011 pierre le
// Last update Fri Jun  3 10:16:32 2011 pierre le
//

#include	<GL/gl.h>

#include	"bomb_gl_rendercontext.hh"
#include	"bomb_gl_drawableobjs.hh"


GlGraphics::DrawableObj::DestructWall::DestructWall(const Vector3f &position)
  : GlTexturedSquare(position, B_BREAKABLE_WALL)
{
}


void		GlGraphics::DrawableObj::DestructWall::initialize(void)
{
}


void		GlGraphics::DrawableObj::DestructWall::update(gdl::GameClock const &,
						  gdl::Input &)
{
}
