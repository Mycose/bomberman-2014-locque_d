//
// BonusSpeed.hh for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Tue May 24 15:08:01 2011 nicolas laille
// Last update Sat Jun  4 15:39:16 2011 nicolas laille
//

#ifndef		__BONUSSPEED_HH__
# define	__BONUSSPEED_HH__

#include	"IBonus.hh"
#include	"Map.hh"

class		ABomberman;

class		BonusSpeed : public IBonus, public ABlock
{
public :
  explicit BonusSpeed(int, int);
  virtual ~BonusSpeed();

  virtual void	operator()(ABomberman&, Map&);

  virtual std::string	Serialize(const std::string& name);
  virtual void		Deserialize(const std::string& doc);

  virtual ABlock*	copy(int, int, Map&) const;
};

#endif		/* __BONUSSPEED_HH__ */
