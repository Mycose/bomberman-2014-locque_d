//
// bomb_gl2d_btnloadgame.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects2D
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Thu Jun  2 10:21:00 2011 pierre le
// Last update Fri Jun  3 12:21:21 2011 pierre le
//

#ifndef		__BOMB_GL2D_BTNLOADGAME_HH__
# define	__BOMB_GL2D_BTNLOADGAME_HH__

# include	"bomb_gl2d_buttonmenuitem.hh"


namespace	GlGraphics
{
  class		LoadGameBtn : public GlButtonMenuItem
  {
  public:
    explicit LoadGameBtn(const Vector3f &position);
    virtual ~LoadGameBtn() {}

    virtual void	initialize(void);

    // Events for derived classes
    virtual void	OnItemUpdate(const gdl::GameClock &,
				     gdl::Input &);
    virtual void	OnMouseClick(void);
    virtual void	OnMouseEnter(void);
    virtual void	OnMouseLeave(void);
  };
}


#endif		// !__BOMB_GL2D_BTNLOADGAME_HH__
