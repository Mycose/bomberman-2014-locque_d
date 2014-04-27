//
// bomb_gl_camera.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/workshop/tp
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Wed Apr 27 13:43:53 2011 pierre le
// Last update Sat Jun  4 17:48:35 2011 nicolas laille
//

#ifndef		__BOMB_GL_CAMERA_HH__
# define	__BOMB_GL_CAMERA_HH__

# include	"GameClock.hpp"
# include	"Input.hpp"

# include	"bomb_gl_object.hh"
# include	"bomb_gl_vector3f.hh"
# include	"bomb_gl_graphic.hh"


namespace	GlGraphics
{
  enum		GlViewField
    {
      GLV_SINGLESCR = 0,
      GLV_LEFTSCR = 1,
      GLV_RIGHTSCR = 2
    };

  class		GlCamera : public GlObject
  {
  public:
    GlCamera(Graphic *bindToObject = NULL,
	     GlViewField viewfield = GLV_SINGLESCR);

    virtual void	initialize(void);
    virtual void	update(gdl::GameClock const &, gdl::Input &);
    virtual void	draw(void);

    void		setViewField(GlViewField viewfield);
    void		setFocusObject(Graphic *);
    GlViewField		getViewField(void) const;

  private:
    Graphic		*_focusOn;
    GlViewField		_viewfield;

    // Camera internal functions
    void		camLookAt(void);
  };
}


#endif		// !__BOMB_GL_CAMERA_HH__
