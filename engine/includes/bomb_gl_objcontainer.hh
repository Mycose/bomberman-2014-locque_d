//
// bomb_gl_objcontainer.hh for Bobmerman in /home/le_b//projects/tek2/cpp/bomberman/workshop/engine
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Mon May 16 11:48:58 2011 pierre le
// Last update Thu May 26 11:39:45 2011 nicolas laille
//

#ifndef		__BOMB_GL_OBJCONTAINER_HH__
# define	__BOMB_GL_OBJCONTAINER_HH__

# include	<list>

# include	"bomb_gl_displist.hh"
# include	"bomb_gl_graphic.hh"


namespace	GlGraphics
{
  class		GlObjContainer
  {
  public:
    virtual ~GlObjContainer(){}

    void			addStaticObject(Graphic *);

  protected:
    GlDispList			_staticObjs;
  };
}


#endif		// !__BOMB_GL_OBJCONTAINER_HH__
