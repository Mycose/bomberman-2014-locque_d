//
// bomb_gl2d_newgameframe.cpp<2> for Bobmerman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects2D/menuframes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri Jun  3 17:02:27 2011 pierre le
// Last update Sun Jun  5 11:49:56 2011 nicolas laille
//

#ifndef		__BOMB_GL2D_NEWGAMEFRAME_HH__
# define	__BOMB_GL2D_NEWGAMEFRAME_HH__

# include	"NewGame.hh"
# include	"MenuFrame.hh"

class		sendData;


namespace	GlGraphics
{
  class		NewGameFrame : public MenuFrame
  {
  public:
    explicit NewGameFrame(const Vector3f &position);
    virtual ~NewGameFrame(void);

    virtual void	initialize(void);
    virtual void	load(sendData&);
    virtual void	unload(sendData &);
    virtual bool	isEnd(void) const;

  private:
    NewGame		newGame;
  };
}


#endif		// !__BOMB_GL2D_NEWGAMEFRAME_HH__
