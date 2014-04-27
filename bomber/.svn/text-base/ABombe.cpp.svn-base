//
// ABombe.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Fri Apr 29 13:49:52 2011 nicolas laille
// Last update Sat Jun  4 11:14:03 2011 nicolas laille
//

#include	"ABombe.hh"

#include	"ABomberman.hh"

ABombe::ABombe(ABomberman& bomber, GlGraphics::GlObject* object)
  : ABlock(true, false, false, object),
    puiss(0), timer(-1), plant(false), explo(false),
    defUp(bomber, 0, -1), defDown(bomber, 0, 1), defLeft(bomber, 1, 0), defRight(bomber, -1, 0),
    bomber(bomber)
{
}

ABombe::ABombe(const ABombe& bombe, GlGraphics::GlObject* object)
  : ABlock(true, false, false, object),
    puiss(bombe.puiss), timer(bombe.timer), plant(bombe.plant),
    explo(bombe.explo), defUp(bombe.defUp), defDown(bombe.defDown),
    defLeft(bombe.defLeft), defRight(bombe.defRight), bomber(bomber)
{
}

ABombe::~ABombe(void)
{
}

bool		ABombe::getPlant(void) const
{
  return	(this->plant);
}

ABombe&		ABombe::operator=(const ABombe& bombe)
{
  if (this != &bombe)
    {
      this->puiss = bombe.puiss;
      this->timer = bombe.timer;
      this->plant = bombe.plant;
      this->explo = bombe.explo;
      this->defUp = bombe.defUp;
      this->defDown = bombe.defDown;
      this->defLeft = bombe.defLeft;
      this->defRight = bombe.defRight;
    }
  return (*this);
}
