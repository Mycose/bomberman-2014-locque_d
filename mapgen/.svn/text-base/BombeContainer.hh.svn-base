//
// BombeContainer.hh for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d/mapgen
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Thu Jun  2 11:08:30 2011 nicolas laille
// Last update Sat Jun  4 15:32:04 2011 nicolas laille
//

#ifndef		__BOMBECONTAINER_HH__
# define	__BOMBECONTAINER_HH__

#include	"ABlock.hh"

class		ABombe;

class		BombeContainer : public ABlock
{
public :
  BombeContainer(ABombe*, GlGraphics::GlObject*);
  ~BombeContainer();

  virtual int	explose(Map&);

  virtual ABlock*	copy(int, int, Map&) const;
  virtual std::string	Serialize(const std::string&);
  virtual void		Deserialize(const std::string&);

private :
  ABombe*	bombe;
};

#endif		/* __BOMBECONTAINER_HH__ */
