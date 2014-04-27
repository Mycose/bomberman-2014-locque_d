//
// CheckBombe.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Thu May 12 14:43:35 2011 nicolas laille
// Last update Tue May 24 12:26:17 2011 nicolas laille
//

#include	"CheckBombe.hh"

CheckBombe::CheckBombe(ABomberman& bomberman, Map&map, const gdl::GameClock& clock)
  : bomberman(bomberman), map(map),
    clock(clock)
{
}

CheckBombe::~CheckBombe(void)
{
}

void		CheckBombe::operator()(ABombe*& bombe)
{
  bombe->checkBombe(this->clock, this->map);
}
