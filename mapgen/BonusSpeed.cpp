//
// BonusSpeed.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Tue May 24 15:09:56 2011 nicolas laille
// Last update Sat Jun  4 15:38:34 2011 nicolas laille
//
#include	<iostream>
#include	"BonusSpeed.hh"

#include	"ABomberman.hh"
#include	"Bombe.hh"

BonusSpeed::BonusSpeed(int x, int y)
  : ABlock(false, true, false,
	   new GlGraphics::DrawableObj::BonusSpeed(GlGraphics::Vector3f(x * BLOCK_SIZE,
									y * BLOCK_SIZE)))
{
  this->x = x;
  this->y = y;
}

BonusSpeed::~BonusSpeed()
{
}

void		BonusSpeed::operator()(ABomberman& bomber, Map& map)
{
  bomber.setSpeed(bomber.getSpeed() * 2);
  map.setMapTableElement(x, y, false, BONUS);
  map.setElement(x, y, NULL);
}

ABlock*		BonusSpeed::copy(int x, int y, Map& map) const
{
  map.setMapTableElement(x, y, true, BONUS);
  return (new BonusSpeed(x, y));
}

std::string	BonusSpeed::Serialize(const std::string& name)
{
  XMLParser	xml;

  xml.AddElem(name);
  xml.SetAttrib("ClassType", "BonusSpeed");
  xml.IntoElem();
  xml.AddElem("X", this->x);
  xml.AddElem("Y", this->y);
  xml.OutOfElem();
  return (xml.GetDoc());
}

void		BonusSpeed::Deserialize(const std::string& doc)
{
  XMLParser	xml(doc);

  xml.FindElem();
  xml.IntoElem();
  xml.FindElem("X");
  this->x = MCD_STRTOINT(xml.GetData());
  xml.FindElem("Y");
  this->y = MCD_STRTOINT(xml.GetData());
  this->setPosition(this->x * BLOCK_SIZE, this->y * BLOCK_SIZE);
}
