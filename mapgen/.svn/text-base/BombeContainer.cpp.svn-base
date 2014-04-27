//
// BombeContainer.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Thu Jun  2 11:20:35 2011 nicolas laille
// Last update Sat Jun  4 15:32:15 2011 nicolas laille
//
#include	<iostream>
#include	"BombeContainer.hh"
#include	"ABombe.hh"

BombeContainer::BombeContainer(ABombe* bombe, GlGraphics::GlObject* object)
  : ABlock(bombe->getDestructible(), bombe->getCrossable(), bombe->isVoid(), object),
    bombe(bombe)
{
  this->initialize();
}

BombeContainer::~BombeContainer()
{
}

int		BombeContainer::explose(Map& map)
{
  if (this->bombe)
    return (this->bombe->explose(map));
  return (1);
}

ABlock*		BombeContainer::copy(int, int, Map&) const
{
  return (NULL);
}

std::string	BombeContainer::Serialize(const std::string& name)
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

void		BombeContainer::Deserialize(const std::string& doc)
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
