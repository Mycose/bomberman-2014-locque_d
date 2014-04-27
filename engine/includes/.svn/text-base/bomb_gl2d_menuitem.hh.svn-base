//
// bomb_gl2d_menuitem.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/includes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Tue May 31 15:12:59 2011 pierre le
// Last update Fri Jun  3 17:24:20 2011 pierre le
//

#ifndef		__BOMB_GL2D_MENUITEM_HH__
# define	__BOMB_GL2D_MENUITEM_HH__

# include	"bomb_gl_object.hh"


namespace	GlGraphics
{
  class		GlMenuItem : public GlObject
  {
  public:
    explicit GlMenuItem(const Vector3f &position,
			const Vector3f &size,
			const gdl::Image &objImage);
    virtual ~GlMenuItem() {}

    virtual void	initialize(void) = 0;
    virtual void	update(const gdl::GameClock &,
			       gdl::Input &);
    virtual void	draw(void);

    // Events for derived classes
    virtual void	OnItemUpdate(const gdl::GameClock &,
				     gdl::Input &) = 0;
    virtual void	OnItemDraw(void) {}
    virtual void	OnMouseClick(void) = 0;
    virtual void	OnMouseEnter(void) = 0;
    virtual void	OnMouseLeave(void) = 0;

  protected:
    // Button states graphics
    gdl::Image		_objImage;

    // Button properties
    Vector3f		_size;

    bool		isMouseOverItem(const gdl::Input &);
  };
}


#endif		// !__BOMB_GL2D_MENUITEM_HH__
