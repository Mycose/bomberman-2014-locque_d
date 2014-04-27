//
// bomb_gl2d_btnhighscores.hh for Bobmerman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects2D
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri Jun  3 11:41:27 2011 pierre le
// Last update Fri Jun  3 12:20:57 2011 pierre le
//

#ifndef		__BOMB_GL2D_BTNHIGHSCORES_HH__
# define	__BOMB_GL2D_BTNHIGHSCORES_HH__

# include	"bomb_gl2d_buttonmenuitem.hh"


namespace	GlGraphics
{
  class		HighscoresBtn : public GlButtonMenuItem
  {
  public:
    explicit HighscoresBtn(const Vector3f &position);
    virtual ~HighscoresBtn() {}

    virtual void	initialize(void);

    // Events for derived classes
    virtual void	OnItemUpdate(const gdl::GameClock &,
				     gdl::Input &);
    virtual void	OnMouseClick(void);
    virtual void	OnMouseEnter(void);
    virtual void	OnMouseLeave(void);
  };
}


#endif		// !__BOMB_GL2D_BTNHIGHSCORES_HH__
