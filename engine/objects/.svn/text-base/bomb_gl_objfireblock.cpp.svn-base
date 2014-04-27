//
// bomb_gl_objfireblock.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Thu May 26 13:49:17 2011 pierre le
// Last update Fri Jun  3 10:16:38 2011 pierre le
//

#include	<cstdlib>

#include	<GL/gl.h>

#include	"bomb_gl_matrix.hh"
#include	"bomb_gl_rendercontext.hh"
#include	"bomb_gl_drawableobjs.hh"


GlGraphics::DrawableObj::FireBlock::FireBlock(const Vector3f &position)
  : GlTexturedObj(position)
{
}


void		GlGraphics::DrawableObj::FireBlock::initialize(void)
{
}


void		GlGraphics::DrawableObj::FireBlock::update(gdl::GameClock const &,
							   gdl::Input &)
{
}


void		GlGraphics::DrawableObj::FireBlock::draw(void)
{
  (this->getTexture(B_FIRE)).bind();
  GlMatrix		matrix;

  glTranslatef(_position.x + BLOCK_SIZE / 2, _position.y + BLOCK_SIZE / 2, _position.z);
  glScalef(0.99f, 0.99f, 1.0f);

  // Particles generator
  for (int i = 0; i < 50; ++i)
    {
      float		tempX, tempY, tempZ;
      tempX = rand() % BLOCK_SIZE;
      tempY = rand() % BLOCK_SIZE;
      tempZ = rand() % BLOCK_SIZE;

      GlRenderContext	context(GL_TRIANGLES);

      glTexCoord2f(0.0f, 0.0f);
      glVertex3f(-BLOCK_SIZE / 2 + tempX,
		 -BLOCK_SIZE / 2 + tempY,
		 tempZ);

      glTexCoord2f(0.0f, 1.0f);
      glVertex3f(-BLOCK_SIZE / 2 + tempX,
		 -BLOCK_SIZE / 2 + tempY + 8.0f,
		 tempZ);

      glTexCoord2f(1.0f, 1.0f);
      glVertex3f(-BLOCK_SIZE / 2 + tempX + 8.0f,
		 -BLOCK_SIZE / 2 + tempY + 8.0f,
		 tempZ);
    }

  // Burnout floor
  {
    GlRenderContext	context(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-BLOCK_SIZE / 2,
	       -BLOCK_SIZE / 2,
	       0.01f);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-BLOCK_SIZE / 2,
	       BLOCK_SIZE / 2,
	       0.01f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(BLOCK_SIZE / 2,
	       BLOCK_SIZE / 2,
	       0.01f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(BLOCK_SIZE / 2,
	       -BLOCK_SIZE / 2,
	       0.01f);
  }

  // Burnout area
  for (int i = 0; i < 4; ++i)
    {
      glRotatef(i * 90.0f,
		0.0f,
		0.0f,
		1.0f);

      GlRenderContext	context(GL_TRIANGLES);

      glTexCoord2f(0.0f, 0.0f);
      glVertex3f(-BLOCK_SIZE / 2,
		 -BLOCK_SIZE / 2,
		 0.0f);

      glTexCoord2f(0.5f, 1.0f);
      glVertex3f(0.0f,
		 0.0f,
		 1.0f * BLOCK_SIZE);

      glTexCoord2f(1.0f, 0.0f);
      glVertex3f(BLOCK_SIZE / 2,
		 -BLOCK_SIZE / 2,
		 0.0f);
    }
}
