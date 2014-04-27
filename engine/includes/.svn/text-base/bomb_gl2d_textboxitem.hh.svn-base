//
// bomb_gl2d_textboxitem.hh for Bobmerman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/includes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri Jun  3 16:33:45 2011 pierre le
// Last update Sat Jun  4 17:55:25 2011 pierre le
//

#ifndef		__BOMB_GL2D_TEXTBOXITEM_HH__
# define	__BOMB_GL2D_TEXTBOXITEM_HH__

# include	"StrTexture.hh"

# include	"bomb_gl2d_menuitem.hh"


namespace	GlGraphics
{
  class		TextBoxItem : public GlMenuItem
  {
  public:
    explicit TextBoxItem(const Vector3f &position,
			 const Vector3f &size,
			 const std::string &str = "");
    virtual ~TextBoxItem() {}

    virtual void	initialize(void);

    virtual void	OnItemUpdate(const gdl::GameClock &,
				     gdl::Input &);
    virtual void	OnItemDraw(void);

    virtual void	OnMouseClick(void);
    virtual void	OnMouseEnter(void);
    virtual void	OnMouseLeave(void);

    void		setText(const std::string &);
    const std::string &	getText(void) const;

  private:
    // Main components composing the final object
    StrTexture		_text;
  };
}


#endif		// !__BOMB_GL2D_TEXTBOXITEM_HH__
