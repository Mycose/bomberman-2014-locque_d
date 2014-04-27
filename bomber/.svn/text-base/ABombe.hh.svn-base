//
// Abombe.hh for  in /home/laille_n//projet/tek2/cpp/bomberman
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Fri Apr 29 13:43:20 2011 nicolas laille
// Last update Fri Jun  3 16:37:36 2011 nicolas laille
//

#ifndef		__ABOMBE_HH__
# define	__ABOMBE_HH__

#include	"Map.hh"
#include	"ABlock.hh"
#include	"bomb_gl_object.hh"
#include	"Fire.hh"

class		ABomberman;
class		BombeContainer;

class		ABombe : public ABlock
{
public :
  ABombe(ABomberman&, GlGraphics::GlObject*);
  ABombe(const ABombe&, GlGraphics::GlObject*);

  virtual ~ABombe(void);

  virtual bool	getPlant(void) const;

  virtual void	setPlant(Map&) = 0;
  virtual void	doPlant(int, int, int, Map&) = 0;
  virtual void	doExplose(Map& map) = 0;
  virtual void	checkBombe(const gdl::GameClock&, Map& map) = 0;
  virtual void	explosed(Map& map) = 0;

  virtual BombeContainer*	container() = 0;
protected :
  int		puiss;
  float		timer;
  bool		plant;
  bool		explo;
  Fire		defUp;
  Fire		defDown;
  Fire		defLeft;
  Fire		defRight;
  ABomberman&	bomber;

private :
  ABombe&	operator=(const ABombe&);
};

#endif		/* __ABOMBE_HH__ */
