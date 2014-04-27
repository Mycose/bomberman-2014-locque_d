//
// CheckBombe.hh for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Thu May 12 14:41:04 2011 nicolas laille
// Last update Mon May 23 16:00:17 2011 nicolas laille
//

#ifndef		__CHECKBOMBE_HH__
# define	__CHECKBOMBE_HH__

#include	"ABombe.hh"
#include	"Map.hh"
#include	"ABomberman.hh"

class		CheckBombe
{
public :
  CheckBombe(ABomberman&, Map&, const gdl::GameClock&);
  ~CheckBombe(void);

  void		operator()(ABombe*&);
private :
  ABomberman&	bomberman;
  Map&		map;
  const gdl::GameClock&	clock;
};

#endif		/* ! __CHECKBOMBE_HH__ */
