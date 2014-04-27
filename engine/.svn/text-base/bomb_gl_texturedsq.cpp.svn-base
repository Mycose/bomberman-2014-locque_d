//
// bomb_gl_texturedsq.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/workshop/local_version/engine/includes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Mon May 30 12:00:16 2011 pierre le
// Last update Fri Jun  3 10:15:56 2011 pierre le
//

#include	<GL/gl.h>

#include	"bomb_gl_rendercontext.hh"
#include	"bomb_gl_object.hh"


GlGraphics::GlTexturedSquare::GlTexturedSquare(const Vector3f &position,
					       eBlockType blockId)
  : GlTexturedObj(position), _blockId(blockId)
{
}


void		GlGraphics::GlTexturedSquare::draw(void)
{
  (this->getTexture(this->_blockId)).bind();
  GlRenderContext	context(GL_QUADS);

  // Face A
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(this->_position.x,
	     this->_position.y,
	     0.0f);

  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(this->_position.x,
	     this->_position.y,
	     1.0f * BLOCK_SIZE);

  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(this->_position.x + BLOCK_SIZE,
	     this->_position.y,
	     1.0f * BLOCK_SIZE);

  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(this->_position.x + BLOCK_SIZE,
	     this->_position.y,
	     0.0f);

  // Face B
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(this->_position.x,
	     this->_position.y + BLOCK_SIZE,
	     0.0f);

  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(this->_position.x,
	     this->_position.y + BLOCK_SIZE,
	     1.0f * BLOCK_SIZE);

  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(this->_position.x,
	     this->_position.y,
	     1.0f * BLOCK_SIZE);

  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(this->_position.x,
	     this->_position.y,
	     0.0f);

  // Face C
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(this->_position.x + BLOCK_SIZE,
	     this->_position.y,
	     0.0f);

  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(this->_position.x + BLOCK_SIZE,
	     this->_position.y,
	     1.0f * BLOCK_SIZE);

  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(this->_position.x + BLOCK_SIZE,
	     this->_position.y + BLOCK_SIZE,
	     1.0f * BLOCK_SIZE);

  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(this->_position.x + BLOCK_SIZE,
	     this->_position.y + BLOCK_SIZE,
	     0.0f);

  // Face D
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(this->_position.x,
	     this->_position.y,
	     1.0f * BLOCK_SIZE);

  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(this->_position.x,
	     this->_position.y + BLOCK_SIZE,
	     1.0f * BLOCK_SIZE);

  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(this->_position.x + BLOCK_SIZE,
	     this->_position.y + BLOCK_SIZE,
	     1.0f * BLOCK_SIZE);

  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(this->_position.x + BLOCK_SIZE,
	     this->_position.y,
	     1.0f * BLOCK_SIZE);
}
