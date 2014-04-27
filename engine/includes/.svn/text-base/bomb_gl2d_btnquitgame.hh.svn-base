//
// bomb_gl2d_btnquitgame.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects2D
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Thu Jun  2 10:24:34 2011 pierre le
// Last update Sun Jun  5 13:59:34 2011 pierre le
//

#ifndef		__BOMB_GL2D_BTNQUITGAME_HH__
# define	__BOMB_GL2D_BTNQUITGAME_HH__

# include	"bomb_gl2d_buttonmenuitem.hh"


namespace	GlGraphics
{
  class		QuitGameBtn : public GlButtonMenuItem
  {
  public:
    explicit QuitGameBtn(const Vector3f &position);
    virtual ~QuitGameBtn() {}

    virtual void	initialize(void);

    // Events for derived classes
    virtual void	OnItemUpdate(const gdl::GameClock &,
				     gdl::Input &);
    virtual void	OnMouseClick(void);
    virtual void	OnMouseEnter(void);
    virtual void	OnMouseLeave(void);
  };
}


#endif		// !__BOMB_GL2D_BTNQUITGAME_HH__
