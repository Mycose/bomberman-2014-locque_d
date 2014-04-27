//
// bomb_gl_matrix.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/workshop/engine
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri Apr 29 10:52:37 2011 pierre le
// Last update Fri May 13 14:20:16 2011 pierre le
//

#ifndef		__BOMB_GL_MATRIX_HH__
# define	__BOMB_GL_MATRIX_HH__

# include	<GL/gl.h>


// class GlMatrix
// Allows scope-based automatization of glPushMatrix(3G) and glPopMatrix(3G).


namespace	GlGraphics
{
  class		GlMatrix
  {
  public:
    GlMatrix()
    { glPushMatrix(); }
    ~GlMatrix()
    { glPopMatrix(); }
  };
}


#endif		// !__BOMB_GL_MATRIX_HH__
