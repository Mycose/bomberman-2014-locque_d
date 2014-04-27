//
// Bombergame.hh for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Mon May 16 11:11:24 2011 nicolas laille
// Last update Sun Jun  5 16:18:06 2011 nicolas laille
//

#ifndef		__BOMBERGAME_HH__
# define	__BOMBERGAME_HH__

#include	<list>

# include	<Game.hpp>
# include	<GameClock.hpp>
# include	<Input.hpp>

# include	"Mapgen.hh"
# include	"Map.hh"
# include	"Playerpos.hh"
# include	"ABomberman.hh"
# include	"bomb_gl_objcontainer.hh"
# include	"bomb_gl_camera.hh"
# include	"IBomberModule.hh"
# include	"EndGame.hh"

class		sendData;

class		BomberGame : public IBomberModule, public GlGraphics::GlObjContainer
{
public :
  BomberGame();
  virtual ~BomberGame();

  // GDL-GL specific functions
  virtual void	initialize(sendData&);
  virtual void	load(void);
  virtual void	update(const gdl::GameClock &, gdl::Input &);
  virtual void	draw(void);
  virtual void	unload(sendData&);

  virtual bool	isEnd(void) const;
  virtual bool	isOver(void) const;
  virtual eBomberModule	nextModule(void);
private :
  void		initMap(Map& map);
  void		initPlayers(Map& map, Playerpos& players, bool two);

  void		addPlayer(ABomberman *, GlGraphics::GlViewField);
  void		removePlayer(ABomberman *);

  void		checkWin(void);

  Serializer		save;
  float			nextSave;
  Mapgen		mapgen;
  std::list<ABomberman *>	_players;
  std::list<GlGraphics::GlCamera>	_cameras;
  
  EndGame	_lose;
  EndGame	_win;
  bool		_pause;
  bool		_end;
  bool		_finish;
  bool		_bug;
};

#endif		/* ! __BOMBERGAME_HH__ */
