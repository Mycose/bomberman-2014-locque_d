//
// bomb_gl_objbonuspowerup.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Mon May 30 14:45:37 2011 pierre le
// Last update Fri Jun  3 10:16:18 2011 pierre le
//

#include	<GL/gl.h>

#include	"bomb_gl_matrix.hh"
#include	"bomb_gl_rendercontext.hh"
#include	"bomb_gl_rotativeobjs.hh"


GlGraphics::DrawableObj::BonusPowerup::BonusPowerup(const Vector3f &position)
  : RotativeObj(position, B_BONUS_POWERUP)
{
}


void		GlGraphics::DrawableObj::BonusPowerup::initialize(void)
{
}


void		GlGraphics::DrawableObj::BonusPowerup::update(gdl::GameClock const &,
							      gdl::Input &)
{
}
