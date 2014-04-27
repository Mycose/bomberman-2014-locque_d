//
// ABlock.hh for  in /home/locque_d//rendu/proj/Bomberman/mapgen
//
// Made by damien locque
// Login   <locque_d@epitech.net>
//
// Started on  Mon May  9 15:28:47 2011 damien locque
// Last update Sat Jun  4 15:24:38 2011 nicolas laille
//

#ifndef		_ABLOCK_HH_
# define	_ABLOCK_HH_

#include	"bomb_gl_graphic.hh"
#include	"ISerializer.hh"

class		ACharacter;
class		ABomberman;
class		Map;

class		ABlock : public ISerializer, public GlGraphics::Graphic
{
public:
  ABlock(bool, bool, bool, GlGraphics::GlObject*);
  virtual ~ABlock();

  virtual int	explose(Map&);
  virtual void	operator()(ACharacter&, Map&);
  virtual void	operator()(ABomberman&, Map&);
  virtual int	getScore(void) const;
  virtual ABlock*	copy(int, int, Map&) const = 0;

  int		getX(void) const;
  int		getY(void) const;
  bool		getDestructible() const;
  bool		getCrossable() const;
  bool		isVoid() const;
protected :
  int		x;
  int		y;
  bool		_destructible;
  bool		_crossable;
  bool		_void;
};

#endif /* ! _ABLOCK_HH_ */
