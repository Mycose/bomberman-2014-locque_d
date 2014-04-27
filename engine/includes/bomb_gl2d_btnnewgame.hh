//
// bomb_gl2d_btnnewgame.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Wed Jun  1 15:11:18 2011 pierre le
// Last update Sat Jun  4 13:14:38 2011 pierre le
//

#ifndef		__BOMB_GL2D_BTNNEWGAME_HH__
# define	__BOMB_GL2D_BTNNEWGAME_HH__

# include	"bomb_gl2d_buttonmenuitem.hh"


namespace	GlGraphics
{
  class		NewGameBtn : public GlButtonMenuItem
  {
  public:
    explicit NewGameBtn(const Vector3f &position);
    virtual ~NewGameBtn() {}

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
