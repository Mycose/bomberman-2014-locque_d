//
// Bonuspuiss.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Tue May 24 15:09:56 2011 nicolas laille
// Last update Sat Jun  4 15:38:42 2011 nicolas laille
//

#include	"BonusPuiss.hh"

#include	"ABomberman.hh"
#include	"Bombe.hh"

BonusPuiss::BonusPuiss(int x, int y)
  : ABlock(false, true, false,
	   new GlGraphics::DrawableObj::BonusPowerup(GlGraphics::Vector3f(x * BLOCK_SIZE,
									  y * BLOCK_SIZE)))
{
  this->x = x;
  this->y = y;
}

BonusPuiss::~BonusPuiss()
{
}

void		BonusPuiss::operator()(ABomberman& bomber, Map& map)
{
  bomber.setPuiss(bomber.getPuiss() + 1);
  map.setMapTableElement(x, y, false, BONUS);
  map.setElement(x, y, NULL);
}

ABlock*		BonusPuiss::copy(int x, int y, Map& map) const
{
  map.setMapTableElement(x, y, true, BONUS);
  return (new BonusPuiss(x, y));
}

std::string	BonusPuiss::Serialize(const std::string& name)
{
  XMLParser	xml;

  xml.AddElem(name);
  xml.SetAttrib("ClassType", "BonusPuiss");
  xml.IntoElem();
  xml.AddElem("X", this->x);
  xml.AddElem("Y", this->y);
  xml.OutOfElem();
  return (xml.GetDoc());
}

void		BonusPuiss::Deserialize(const std::string& doc)
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
