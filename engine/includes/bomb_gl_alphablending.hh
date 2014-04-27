//
// bomb_gl_alphablending.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/includes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri Jun  3 15:36:35 2011 pierre le
// Last update Fri Jun  3 15:43:00 2011 pierre le
//

#ifndef		__BOMB_GL_ALPHABLENDING_HH__
# define	__BOMB_GL_ALPHABLENDING_HH__

# include	<GL/gl.h>


namespace	GlGraphics
{
  // class GlAlphablending
  // Allows display of the alpha channel in some textures

  class		GlAlphaBlending
  {
  public:
    GlAlphaBlending(void)
    {
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glEnable(GL_BLEND);
      glAlphaFunc(GL_GREATER,0.1f);
      glEnable(GL_ALPHA_TEST);
    }

    ~GlAlphaBlending(void)
    {
      glDisable(GL_BLEND);
      glDisable(GL_ALPHA_TEST);
    }
  };
}


#endif		// !__BOMB_GL_ALPHABLENDING_HH__
