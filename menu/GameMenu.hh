//
// GameMenu.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/menu
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Tue May 31 14:45:40 2011 pierre le
// Last update Sun Jun  5 14:37:08 2011 nicolas laille
//

#ifndef		__GAMEMENU_HH__
# define	__GAMEMENU_HH__

# include	<list>
# include	<map>

# include	"IModule.hh"
# include	"bomb_gl2d_menuitem.hh"
# include	"bomb_gl2d_mainframe.hh"
# include	"bomb_gl2d_scoresframe.hh"
# include	"bomb_gl2d_newgameframe.hh"
# include	"bomb_gl2d_loadgameframe.hh"
# include	"bomb_gl2d_introframe.hh"

class		sendData;

class		GameMenu : public IModule
{
public:
  // IDs for menu frames
  enum		eMenuFrameId
    {
      FRAME_INTRO,
      FRAME_MAIN,
      FRAME_SCORES,
      FRAME_NEWGAME,
      FRAME_LOADGAME
    };

  // Constructors
  GameMenu(void);
  virtual ~GameMenu(void);

  // Interface functions
  virtual void		initialize(sendData&);
  virtual void		update(const gdl::GameClock &,
			       gdl::Input &);
  virtual void		draw(void);
  virtual void		unload(sendData&);
  virtual bool		isEnd(void);
  virtual IModule*	copy(void) const;

  // Current frame storage
  static eMenuFrameId	_currentFrame;

private:
  // Persistant objects (eg. background, ...)
  std::list<GlGraphics::GlObject *>	_objsList;

  bool		_end;

  // Menu frames
  void		loadFrame(eMenuFrameId frame);
  void		addFrame(eMenuFrameId frame, MenuFrame *module);

  MenuFrame*	_current;
  std::map<eMenuFrameId, MenuFrame*>	_menus;
};


#endif		// !__GAMEMENU_HH__
