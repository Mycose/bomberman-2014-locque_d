//
// Void.cpp for  in /home/locque_d//rendu/proj/Bomberman/mapgen
//
// Made by damien locque
// Login   <locque_d@epitech.net>
//
// Started on  Mon May  9 15:45:46 2011 damien locque
// Last update Sat Jun  4 15:29:14 2011 nicolas laille
//
#include <iostream>
#include "Void.hh"

BVoid::BVoid(int, int)
  : ABlock(false, true, true, NULL)
{
  this->x = 0;
  this->y = 0;
}

BVoid::~BVoid()
{
}

ABlock*		BVoid::copy(int x, int y, Map&) const
{
  return (new BVoid(x, y));
}

std::string	BVoid::Serialize(const std::string& name)
{
  XMLParser	xml;

  xml.AddElem(name);
  xml.SetAttrib("ClassType", "BVoid");
  xml.IntoElem();
  xml.AddElem("X", this->x);
  xml.AddElem("Y", this->y);
  xml.OutOfElem();
  return (xml.GetDoc());
}

void		BVoid::Deserialize(const std::string& doc)
{
  XMLParser	xml(doc);

  xml.FindElem();
  xml.IntoElem();
  xml.FindElem("X");
  this->x = MCD_STRTOINT(xml.GetData());
  xml.FindElem("Y");
  this->y = MCD_STRTOINT(xml.GetData());
  xml.OutOfElem();
}
