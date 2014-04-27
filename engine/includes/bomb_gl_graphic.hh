//
// bomb_gl_graphic.hh for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d/engine
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Tue May 24 13:32:25 2011 nicolas laille
// Last update Sat Jun  4 11:09:32 2011 nicolas laille
//

#ifndef		__BOMB_GL_GRAPHIC_HH__
# define	__BOMB_GL_GRAPHIC_HH__

#include	"bomb_gl_object.hh"
#include	"bomb_gl_rotativeobjs.hh"

namespace	GlGraphics
{
  class		Graphic
  {
  public :
    explicit Graphic(GlObject*);
    virtual ~Graphic();

    virtual void	initialize(void);
    virtual void	update(const gdl::GameClock &,
			       gdl::Input &);
    virtual void	draw(void);

    void		setPosition(const Vector3f &position);
    void		setPosition(int, int);
    const Vector3f	getPosition(void) const;

    void		setRotation(float);
    float		getRotation(void) const;

    void		setColor(const gdl::Color&);
  private :
    GlObject		*object;
  };
}

#endif		/* __BOMB_GL_GRAPHIC_HH__ */
