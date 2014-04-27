//
// bomb_gl_objground.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/workshop/engine
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri May  6 14:49:49 2011 pierre le
// Last update Fri Jun  3 10:16:47 2011 pierre le
//

#include	<GL/gl.h>

#include	"bomb_blocktypes.hh"
#include	"bomb_gl_rendercontext.hh"
#include	"bomb_gl_drawableobjs.hh"


GlGraphics::DrawableObj::Ground::Ground(const Vector3f &size)
  : GlTexturedObj(Vector3f(0.0f, -size.y, 0.0f)), _size(size)
{
}


void		GlGraphics::DrawableObj::Ground::initialize(void)
{
}


void		GlGraphics::DrawableObj::Ground::update(gdl::GameClock const &,
							gdl::Input &)
{
}


void		GlGraphics::DrawableObj::Ground::draw(void)
{
  (this->getTexture(B_GROUND)).bind();
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  GlRenderContext	context(GL_QUADS);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);

  glTexCoord2f(0.0f, this->_size.y);
  glVertex3f(0.0f, (-this->_size.y + 1) * BLOCK_SIZE, 0.0f);

  glTexCoord2f(this->_size.x, this->_size.y);
  glVertex3f(this->_size.x * BLOCK_SIZE, (-this->_size.y + 1) * BLOCK_SIZE, 0.0f);

  glTexCoord2f(this->_size.x, 0.0f);
  glVertex3f(this->_size.x * BLOCK_SIZE, 0.0f, 0.0f);
}
