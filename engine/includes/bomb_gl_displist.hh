//
// bomb_gl_displist.hh for Bobmerman in /home/le_b//projects/tek2/cpp/bomberman/workshop/engine/includes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri May 13 10:40:15 2011 pierre le
// Last update Thu May 26 11:38:06 2011 nicolas laille
//

#ifndef		__BOMB_GL_DISPLIST_HH__
# define	__BOMB_GL_DISPLIST_HH__

# include	<list>

# include	"Input.hpp"
# include	"GameClock.hpp"

# include	"bomb_gl_object.hh"
# include	"bomb_gl_graphic.hh"


namespace	GlGraphics
{
  class		GlDispList : public GlObject
  {
  public:
    GlDispList();
    virtual ~GlDispList();

    virtual void	initialize(void) {}
    virtual void	update(const gdl::GameClock &, gdl::Input &);
    virtual void	draw(void);

    void		addToList(Graphic *);

  private:
    // Display list in itself.
    GLuint		_dispList;
    // If true, calling addToList() will be forbidden.
    bool		_isListClosed;
    // Objects from which the draw() methods are called.
    std::list<Graphic *>	_objsList;

    void		listPrepare(void);
  };
}

#endif		// !__BOMB_GL_DISPLIST_HH__
