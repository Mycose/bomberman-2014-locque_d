//
// bomb_gl_objrotativeobj.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Mon May 30 11:29:39 2011 pierre le
// Last update Fri Jun  3 10:15:45 2011 pierre le
//

#include	<GL/gl.h>
#include	<cstdlib>

#include	"bomb_gl_matrix.hh"
#include	"bomb_gl_rendercontext.hh"
#include	"bomb_gl_rotativeobjs.hh"


GlGraphics::RotativeObj::RotativeObj(const Vector3f &position,
				     eBlockType blockId)
  : GlTexturedObj(position), _rotAngle(0.0f), _blockId(blockId)
{
}


void		GlGraphics::RotativeObj::draw(void)
{
  (this->getTexture(this->_blockId)).bind();
  GlMatrix		matrix;

  glTranslatef(_position.x + BLOCK_SIZE / 2,
	       _position.y + BLOCK_SIZE / 2,
	       _position.z);
  glScalef(0.65f, 0.65f, 0.65f);
  glRotatef(this->_rotAngle, 0.0f, 0.0f, 1.0f);
  if (++(this->_rotAngle) >= 360)
    this->_rotAngle = 0;

  // Rotating cube - side faces
  for (int i = 0; i < 4; ++i)
    {
      glRotatef(i * 90.0f,
		0.0f,
		0.0f,
		1.0f);

      GlRenderContext	context(GL_QUADS);

      glTexCoord2f(0.0f, 0.0f);
      glVertex3f(-BLOCK_SIZE / 2,
		 -BLOCK_SIZE / 2,
		 0.0f);

      glTexCoord2f(0.0f, 1.0f);
      glVertex3f(-BLOCK_SIZE / 2,
		 -BLOCK_SIZE / 2,
		 1.0f * BLOCK_SIZE);

      glTexCoord2f(1.0f, 1.0f);
      glVertex3f(BLOCK_SIZE / 2,
		 -BLOCK_SIZE / 2,
		 1.0f * BLOCK_SIZE);

      glTexCoord2f(1.0f, 0.0f);
      glVertex3f(BLOCK_SIZE / 2,
		 -BLOCK_SIZE / 2,
		 0.0f);
    }

  // Rotating cube - upper/bottom faces
  {
    GlRenderContext	context(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-BLOCK_SIZE / 2,
	       -BLOCK_SIZE / 2,
	       1.0f * BLOCK_SIZE);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-BLOCK_SIZE / 2,
	       BLOCK_SIZE / 2,
	       1.0f * BLOCK_SIZE);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(BLOCK_SIZE / 2,
	       BLOCK_SIZE / 2,
	       1.0f * BLOCK_SIZE);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(BLOCK_SIZE / 2,
	       -BLOCK_SIZE / 2,
	       1.0f * BLOCK_SIZE);
  }
}
