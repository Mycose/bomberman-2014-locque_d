//
// bomb_gl2d_loadgameframe.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects2D/menuframes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Sat Jun  4 10:54:01 2011 pierre le
// Last update Sun Jun  5 10:57:14 2011 pierre le
//

#ifndef		__BOMB_GL2D_LOADGAMEFRAME_HH__
# define	__BOMB_GL2D_LOADGAMEFRAME_HH__

# include	"MenuFrame.hh"

# include	"LoadGame.hh"

class		sendData;

namespace	GlGraphics
{
  class		LoadGameFrame : public MenuFrame
  {
  public:
    explicit LoadGameFrame(const Vector3f &position);
    virtual ~LoadGameFrame(void);

    virtual void	initialize(void);
    virtual void	load(sendData&);
    virtual void	unload(sendData &);
    virtual bool	isEnd(void) const;

  private :
    LoadGame	loadGame;
  };
}


#endif		// !__BOMB_GL2D_LAODGAMEFRAME_HH__
