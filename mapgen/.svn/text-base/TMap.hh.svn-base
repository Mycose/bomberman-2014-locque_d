//
// AMap.hh for  in /home/locque_d//rendu/proj/Bomberman
//
// Made by damien locque
// Login   <locque_d@epitech.net>
//
// Started on  Mon May 23 16:35:50 2011 damien locque
// Last update Sat Jun  4 17:07:30 2011 nicolas laille
//

#ifndef _TMAP_HH_
#define _TMAP_HH_

#include <string>

enum		maptype
  {
    COLLISION = 0b00000001,
    DANGEROUS = 0b00000010,
    OBJECTIVE = 0b00000100,
    DESTRUCT =  0b00001000,
    TMPDANG =	0b00010000,
    BONUS =	0b00100000,
    DEATH =     0b01000000,
    PLAYER =    0b10000000
  };

class TMap
{
public :
  TMap();
  ~TMap();
  void create(int, int);
  bool getxy(int, int, maptype) const;
  void setxy(int, int, bool, maptype);
private:
  int				_width;
  int				_height;
  std::string			_map;
};

#endif /* !_TMAP_HH_ */
