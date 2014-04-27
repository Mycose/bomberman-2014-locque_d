//
// ABlock.cpp for  in /home/locque_d//rendu/proj/Bomberman/mapgen
//
// Made by damien locque
// Login   <locque_d@epitech.net>
//
// Started on  Mon May  9 15:30:08 2011 damien locque
// Last update Wed Jun  1 17:29:47 2011 nicolas laille
//

#include	"ABlock.hh"
#include	"Map.hh"
#include	"ABomberman.hh"
#include	"ACharacter.hh"

ABlock::ABlock(bool dest, bool cross, bool vod, GlGraphics::GlObject* object)
  : Graphic(object),
    _destructible(dest), _crossable(cross), _void(vod)
{
}

ABlock::~ABlock()
{
}

int		ABlock::explose(Map&)
{
  return (1);
}

void		ABlock::operator()(ACharacter&, Map&)
{
}

void		ABlock::operator()(ABomberman&, Map&)
{
}

int		ABlock::getX(void) const
{
  return	(this->x);
}

int		ABlock::getY(void) const
{
  return	(this->y);
}

bool		ABlock::getDestructible() const
{
  return (this->_destructible);
}

bool		ABlock::getCrossable() const
{
  return (this->_crossable);
}

bool		ABlock::isVoid() const
{
  return (this->_void);
}

int		ABlock::getScore(void) const
{
  return	(0);
}
