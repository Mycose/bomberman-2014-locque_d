//
// bomb_gl2d_btnsoloversus.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/includes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Sat Jun  4 14:33:33 2011 pierre le
// Last update Sat Jun  4 14:34:10 2011 pierre le
//

#ifndef		__BOMB_GL2D_BTNSOLOVERSUS_HH__
# define	__BOMB_GL2D_BTNSOLOVERSUS_HH__

# include	"bomb_gl2d_buttonmenuitem.hh"
# include	"bomb_gl2d_textboxitem.hh"


namespace	GlGraphics
{
  class		BtnSoloVersus : public GlButtonMenuItem
  {
  public:
    explicit BtnSoloVersus(const Vector3f &position,
		     TextBoxItem *textBoxToChange);
    virtual ~BtnSoloVersus() {}

    virtual void	initialize(void);

    // Events for derived classes
    virtual void	OnItemUpdate(const gdl::GameClock &,
				     gdl::Input &);
    virtual void	OnMouseClick(void);
    virtual void	OnMouseEnter(void);
    virtual void	OnMouseLeave(void);

  private:
    TextBoxItem *	_textBoxToChange;
  };
}


#endif		// !__BOMB_GL2D_BTNSOLOVERSUS_HH__
