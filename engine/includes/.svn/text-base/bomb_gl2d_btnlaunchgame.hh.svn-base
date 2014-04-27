//
// bomb_gl2d_btnlaunchgame.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects2D
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri Jun  3 18:19:17 2011 pierre le
// Last update Fri Jun  3 18:19:18 2011 pierre le
//

#ifndef		__BOMB_GL2D_BTNNEWGAME_HH__
# define	__BOMB_GL2D_BTNNEWGAME_HH__

# include	"bomb_gl2d_buttonmenuitem.hh"


namespace	GlGraphics
{
  class		LaunchGameBtn : public GlButtonMenuItem
  {
  public:
    explicit LaunchGameBtn(const Vector3f &position);
    virtual ~LaunchGameBtn() {}

    virtual void	initialize(void);

    // Events for derived classes
    virtual void	OnItemUpdate(const gdl::GameClock &,
				     gdl::Input &);
    virtual void	OnMouseClick(void);
    virtual void	OnMouseEnter(void);
    virtual void	OnMouseLeave(void);
  };
}


#endif		// !__BOMB_GL2D_BTNNEWGAME_HH__
