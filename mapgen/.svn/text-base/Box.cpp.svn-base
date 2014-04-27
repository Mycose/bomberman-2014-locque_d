//
// Box.cpp for  in /home/locque_d//rendu/proj/Bomberman/mapgen
//
// Made by damien locque
// Login   <locque_d@epitech.net>
//
// Started on  Mon May  9 16:16:46 2011 damien locque
// Last update Sun Jun  5 13:02:26 2011 nicolas laille
//
#include	<iostream>
#include	<cstdlib>
#include	<ctime>

#include	"Box.hh"

#include	"BonusBomb.hh"
#include	"BonusPuiss.hh"
#include	"BonusSpeed.hh"

Box::Box(int x, int y)
  : ABlock(true, false, false, new GlGraphics::DrawableObj::DestructWall(GlGraphics::Vector3f(x * BLOCK_SIZE, y * BLOCK_SIZE)))
{
  this->x = x;
  this->y = y;
  this->addBonus(1, new BonusBomb(0, 0));
  this->addBonus(2, new BonusSpeed(0, 0));
  this->addBonus(3, new BonusPuiss(0, 0));
}

Box::~Box()
{
  std::map<int, IBonus*>::iterator	it;

  for (it = this->_bonus.begin(); it != this->_bonus.end(); it++)
    {
      if ((*it).second)
	delete ((*it).second);
    }
}

int		Box::explose(Map& map)
{
  ABlock	*tmp;

  tmp = this->getRandomBonus(this->x, this->y, map);
  map.setElement(this->x, this->y, tmp);
  map.setMapTableElement(x, y, false, DESTRUCT);
  map.setMapTableElement(this->x, this->y, false, DANGEROUS);
  return (tmp == NULL);
}

int		Box::getScore(void) const
{
  return (10);
}

ABlock*		Box::getRandomBonus(int x, int y, Map& map)
{
  int		random;

  random = (rand() % 5);
  if (this->_bonus[random])
    return (this->_bonus[random]->copy(x, y, map));
  else
    return (NULL);
}

void		Box::addBonus(int type, IBonus* bonus)
{
  this->_bonus.insert(std::pair<int, IBonus*>(type, bonus));
}

ABlock*		Box::copy(int x, int y, Map& map) const
{
  map.setMapTableElement(x, y, true, DESTRUCT);
  return (new Box(x, y));
}

std::string	Box::Serialize(const std::string& name)
{
  XMLParser	xml;

  xml.AddElem(name);
  xml.SetAttrib("ClassType", "Box");
  xml.IntoElem();
  xml.AddElem("X", this->x);
  xml.AddElem("Y", this->y);
  xml.OutOfElem();
  return (xml.GetDoc());
}

void		Box::Deserialize(const std::string& doc)
{
  XMLParser	xml(doc);

  xml.FindElem();
  xml.IntoElem();
  xml.FindElem("X");
  this->x = MCD_STRTOINT(xml.GetData());
  xml.FindElem("Y");
  this->y = MCD_STRTOINT(xml.GetData());
  xml.OutOfElem();
  this->setPosition(this->x * BLOCK_SIZE, this->y * BLOCK_SIZE);
}
