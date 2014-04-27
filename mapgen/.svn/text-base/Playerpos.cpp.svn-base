//
// Playerpos.cpp for  in /home/locque_d//rendu/proj/Bomberman/bomberman-2014-locque_d/mapgen
//
// Made by damien locque
// Login   <locque_d@epitech.net>
//
// Started on  Thu May 12 15:15:37 2011 damien locque
// Last update Tue May 24 12:20:02 2011 nicolas laille
//

#include "Playerpos.hh"

Playerpos::Playerpos()
{

}

Playerpos::~Playerpos()
{

}

void		Playerpos::addposition(int x, int y)
{
  std::pair<int, int>	couple(x, y);
  this->_perso_start.push_back(couple);
}

int		Playerpos::size(void) const
{
  return (this->_perso_start.size());
}

std::pair<int, int> Playerpos::operator[](int i)
{
  return (this->_perso_start[i]);
}
