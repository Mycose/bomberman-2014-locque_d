//
// Wall.cpp for  in /home/locque_d//rendu/proj/Bomberman/mapgen
//
// Made by damien locque
// Login   <locque_d@epitech.net>
//
// Started on  Mon May  9 15:56:30 2011 damien locque
// Last update Sat Jun  4 15:33:06 2011 nicolas laille
//
#include <iostream>
#include "Wall.hh"

BWall::BWall(int x, int y)
  : ABlock(false, false, false, new GlGraphics::DrawableObj::StrongWall(GlGraphics::Vector3f(x * BLOCK_SIZE, y * BLOCK_SIZE)))
{
  this->x = x;
  this->y = y;
}

BWall::~BWall()
{
}

ABlock*		BWall::copy(int x, int y, Map& map) const
{
  map.setMapTableElement(x, y, true, COLLISION);
  return (new BWall(x, y));
}

std::string	BWall::Serialize(const std::string& name)
{
  XMLParser	xml;

  xml.AddElem(name);
  xml.SetAttrib("ClassType", "BWall");
  xml.IntoElem();
  xml.AddElem("X", this->x);
  xml.AddElem("Y", this->y);
  xml.OutOfElem();
  return (xml.GetDoc());
}

void		BWall::Deserialize(const std::string& doc)
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
