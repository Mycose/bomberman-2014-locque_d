//
// bomb_gl2d_buttonmenuitem.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects2D
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri Jun  3 11:57:35 2011 pierre le
// Last update Sat Jun  4 12:33:40 2011 pierre le
//

#ifndef		__BOMB_GL2D_BUTTONMENUITEM_HH__
# define	__BOMB_GL2D_BUTTONMENUITEM_HH__

# include	"bomb_gl2d_menuitem.hh"


namespace	GlGraphics
{
  class		GlButtonMenuItem : public GlMenuItem
  {
  public:
    explicit GlButtonMenuItem(const Vector3f &position,
			      const Vector3f &size,
			      const gdl::Image &objImage,
			      const gdl::Image &objImageEntered);
    virtual ~GlButtonMenuItem() {}

    virtual void	initialize(void) = 0;

    // Redefined methods to allow dual state buttons
    virtual void	update(const gdl::GameClock &,
			       gdl::Input &);
    virtual void	draw(void);

    // Events are still pure
    virtual void	OnItemUpdate(const gdl::GameClock &,
				     gdl::Input &) = 0;
    virtual void	OnItemDraw(void) {}
    virtual void	OnMouseClick(void) = 0;
    virtual void	OnMouseEnter(void) = 0;
    virtual void	OnMouseLeave(void) = 0;

  private:
    // Additionnal entered image state
    gdl::Image		_objImageEntered;
    bool		_isOverButton;
  };
};


#endif		// !__BOMB_GL2D_BUTTONMENUITEM_HH__
