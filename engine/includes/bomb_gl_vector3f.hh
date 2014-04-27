//
// bomb_gl_vector3f.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/workshop/tp
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Wed Apr 27 13:11:32 2011 pierre le
// Last update Wed Jun  1 15:38:08 2011 pierre le
//

#ifndef		__BOMB_GL_VECTOR3F_HH__
# define	__BOMB_GL_VECTOR3F_HH__


namespace	GlGraphics
{
  class		Vector3f
  {
  public:
    float		x;
    float		y;
    float		z;

    Vector3f(float x = 0.0f,
	     float y = 0.0f,
	     float z = 1.0f);
  };
}


#endif		// !__BOMB_GL_VECTOR3F_HH__
