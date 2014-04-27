//
// bomb_gl2d_btnback.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/includes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri Jun  3 16:00:47 2011 pierre le
// Last update Fri Jun  3 16:09:25 2011 pierre le
//

#ifndef		__BOMB_GL2D_BTNBACK_HH__
# define	__BOMB_GL2D_BTNBACK_HH__

# include	"bomb_gl2d_buttonmenuitem.hh"


namespace	GlGraphics
{
  class		BackBtn : public GlButtonMenuItem
  {
  public:
    explicit BackBtn(const Vector3f &position,
		     GameMenu::eMenuFrameId frameAction = GameMenu::FRAME_MAIN);
    virtual ~BackBtn() {}

    virtual void	initialize(void);

    // Events for derived classes
    virtual void	OnItemUpdate(const gdl::GameClock &,
				     gdl::Input &);
    virtual void	OnMouseClick(void);
    virtual void	OnMouseEnter(void);
    virtual void	OnMouseLeave(void);

  private:
    GameMenu::eMenuFrameId	_frameAction;
  };
}


#endif		// !__BOMB_GL2D_BTNBACK_HH__
