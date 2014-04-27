//
// Character.hh for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d/bomber
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Thu May 12 11:46:59 2011 nicolas laille
// Last update Sat Jun  4 10:27:16 2011 nicolas laille
//

#ifndef		__ACHARACTER_HH__
# define	__ACHARACTER_HH__

#include	<map>
#include	<Input.hpp>

#include	"Map.hh"
#include	"bomb_gl_graphic.hh"

const int	MOVE_SIZE = 32.0f;

class		ACharacter : public GlGraphics::Graphic
{
public :
  ACharacter(int x, int y, int life,
	     gdl::Keys::Key up,
	     gdl::Keys::Key down,
	     gdl::Keys::Key right,
	     gdl::Keys::Key left,
	     GlGraphics::GlObject* object);
  virtual ~ACharacter();

  int		getLife(void) const;
  int		getSpeed(void) const;
  int		getX(void) const;
  int		getY(void) const;
  int		getCheckX(void) const;
  int		getCheckY(void) const;
  int		getViewX(void) const;
  int		getViewY(void) const;
  void		setLife(int);
  void		setX(int);
  void		setY(int);
  void		setSpeed(int);

  bool		isDead(void) const;
  bool		view(const ACharacter&) const;

  virtual void	doRight(const Map& map);
  virtual void	doLeft(const Map& map);
  virtual void	doUp(const Map& map);
  virtual void	doDown(const Map& map);

  virtual bool	doSingleRight(const Map& map);
  virtual bool	doSingleLeft(const Map& map);
  virtual bool	doSingleUp(const Map& map);
  virtual bool	doSingleDown(const Map& map);

  typedef void	(ACharacter::*funcMove)(const Map& map);
  void		addMove(gdl::Keys::Key, funcMove move);
  int		doMove(gdl::Input&, const Map& map);
  int		doMove(int, const Map& map);

protected :
  int		x;
  int		y;
  int		life;
  int		speed;

private :
  std::map<gdl::Keys::Key, funcMove>	move;
};

#endif		/* __ACHARACTER_HH__ */
