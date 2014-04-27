//
// ABomberman.hh for  in /home/laille_n//projet/tek2/cpp/bomberman
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Thu Apr 28 10:42:09 2011 nicolas laille
// Last update Sun Jun  5 13:26:23 2011 nicolas laille
//

#ifndef		__ABOMBERMAN_HH__
# define	__ABOMBERMAN_HH__

#include	<list>
#include	<map>
#include	<Input.hpp>
#include	<Clock.hpp>

class		ABomberman;

#include	"Map.hh"
#include	"ABombe.hh"
#include	"ACharacter.hh"

#include	"bomb_gl_drawableobjs.hh"

class		ABomberman : public ACharacter, public ISerializer
{
public :
  explicit ABomberman(int x, int y,
		      gdl::Keys::Key up = gdl::Keys::A,
		      gdl::Keys::Key down = gdl::Keys::B,
		      gdl::Keys::Key right = gdl::Keys::C,
		      gdl::Keys::Key left = gdl::Keys::D,
		      gdl::Keys::Key plant = gdl::Keys::A,
		      GlGraphics::GlObject* object = new GlGraphics::DrawableObj::Character(GlGraphics::Vector3f(0, 0)));
  virtual ~ABomberman(void);

  int		getPuiss(void) const;
  int		getScore(void) const;
  void		setPuiss(int);

  void		setWin(void);
  bool		getWin(void) const;

  int		getBombX(void) const;
  int		getBombY(void) const;

  int		getNbBombMax(void) const;
  int		getNbBombDispo(void);

  void		addBombe(ABombe*);

  void		doPlant(Map& map);
  bool		checkPlant();
  void		initBombes(Map& map);
  void		checkBombes(const gdl::GameClock&, Map& map);

  void		doAction(gdl::Input&, Map& map);
  void		doAction(int, Map& map);

  virtual void	update(const gdl::GameClock&, gdl::Input&, Map& map);
  virtual int	update(gdl::Input&, Map&) = 0;

  typedef void	(ABomberman::*funcAction)(Map& map);
  void		addAction(gdl::Keys::Key, funcAction action);

  bool		operator==(ABomberman&);
  bool		operator!=(ABomberman&);
  void		operator+=(int);

  std::string	SerializeBombs(const std::string& name);
  void		DeserializeBombs(const std::string& doc);

protected :
  float		moveSpeed;
  int		puiss;
  int		score;
  float		nextMove;

private :
  std::list<ABombe *>	bombes;
  std::map<gdl::Keys::Key, funcAction>	action;

  bool		_win;

  ABomberman(const ABomberman&);
  ABomberman&	operator=(const ABomberman&);
};

#endif		/* __ABOMBERMAN_HH__ */
