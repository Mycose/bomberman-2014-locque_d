//
// Plant.hh for  in /home/laille_n//projet/tek2/cpp/bomberman
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Fri Apr 29 14:36:55 2011 nicolas laille
// Last update Wed May 25 12:49:26 2011 nicolas laille
//

#ifndef		__PLANT_HH__
# define	__PLANT_HH__

#include	<list>

#include	"ABomberman.hh"
#include	"ABombe.hh"

class		Plant
{
public :
  Plant(ABomberman&, Map&);
  Plant(Plant &);
  ~Plant(void);

  Plant&	operator=(const Plant &);
  void		operator()(ABombe*&);
private :
  bool		plant;
  ABomberman&	bomberman;
  Map&		map;
};

#endif		/* __PLANT_HH__*/
