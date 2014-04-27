//
// Plant.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Fri Apr 29 14:39:28 2011 nicolas laille
// Last update Sat Jun  4 11:14:33 2011 nicolas laille
//

#include	<iostream>

#include	"Plant.hh"

Plant::Plant(ABomberman& bomberman, Map& map)
  : plant(false), bomberman(bomberman), map(map)
{
}

Plant::Plant(Plant &plant)
  : plant(plant.plant), bomberman(plant.bomberman),
    map(plant.map)
{
}

Plant::~Plant(void)
{
}

void		Plant::operator()(ABombe*& bombe)
{
  if (!this->plant && !bombe->getPlant())
    {
      this->plant = true;
      bombe->doPlant(this->bomberman.getBombX(), this->bomberman.getBombY(), this->bomberman.getPuiss(), this->map);
      this->map.setElement(bombe->getX(), bombe->getY(), bombe);
    }
}

Plant&		Plant::operator=(const Plant &plant)
{
  if (this != &plant)
    {
      this->plant = plant.plant;
      this->map = plant.map;
    }
  return (*this);
}
