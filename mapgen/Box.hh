//
// Box.hh for  in /home/locque_d//rendu/proj/Bomberman/mapgen
//
// Made by damien locque
// Login   <locque_d@epitech.net>
//
// Started on  Mon May  9 16:15:00 2011 damien locque
// Last update Sat Jun  4 15:38:10 2011 nicolas laille
//

#ifndef		_BOX_HH_
#define		_BOX_HH_

#include	<map>

#include	"Map.hh"
#include	"ABlock.hh"
#include	"ACharacter.hh"
#include	"bomb_gl_drawableobjs.hh"
#include	"IBonus.hh"

class		Box : public ABlock
{
public :
  Box(int, int);
  virtual ~Box();

  virtual int	explose(Map&);
  virtual int	getScore(void) const;

  virtual ABlock*	copy(int, int, Map&) const;
  virtual std::string	Serialize(const std::string& name);
  virtual void		Deserialize(const std::string& doc);

private :
  void		addBonus(int, IBonus*);
  ABlock*	getRandomBonus(int, int, Map&);
  std::map<int, IBonus*>	_bonus;
};

#endif /* !_BOX_HH_ */
