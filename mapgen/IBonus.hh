//
// IBonus.hh for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Thu May 26 14:37:13 2011 nicolas laille
// Last update Sat Jun  4 15:38:25 2011 nicolas laille
//

#ifndef			__IBONUS_HH__
# define		__IBONUS_HH__

#include		"ABlock.hh"

class			Map;

class			IBonus
{
public :
  virtual ~IBonus(){}
  
  virtual ABlock*	copy(int, int, Map&) const = 0;
};

#endif			/* __IBONUS_HH__ */
