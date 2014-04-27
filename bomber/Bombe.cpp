//
// Bombe.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Fri Apr 29 13:52:23 2011 nicolas laille
// Last update Sat Jun  4 15:31:54 2011 nicolas laille
//

#include	<iostream>

#include	"Bombe.hh"
#include	"bomb_gl_drawableobjs.hh"
#include	"ABomberman.hh"
#include	"converter.hpp"
#include	"BombeContainer.hh"

Bombe::Bombe(ABomberman& bomber)
  : ABombe(bomber, NULL)
{
  this->initialize();
}

Bombe::Bombe(const Bombe& bombe)
  : ABombe(bombe, NULL)
{
  this->initialize();
}

Bombe::~Bombe()
{
}

void		Bombe::doPlant(int x, int y, int puiss, Map& map)
{
  this->x = x;
  this->y = y;
  this->puiss = puiss;
  this->plant = true;
  this->timer = 4;
  this->setPlant(map);
}

void		Bombe::setPlant(Map& map)
{
  if (this->plant && !this->explo)
    {
      BombeContainer*	tmp;
      
      this->defUp.setOrig(this->getX(), this->getY(), this->puiss, map);
      this->defDown.setOrig(this->getX(), this->getY(), this->puiss, map);
      this->defLeft.setOrig(this->getX(), this->getY(), this->puiss, map);
      this->defRight.setOrig(this->getX(), this->getY(), this->puiss, map);
      tmp = this->container();
      tmp->setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
      map.setElement(x, y, tmp);
      map.setMapTableElement(x, y, true, COLLISION);
    }
  else if (this->plant && this->explo)
    {
      this->defUp.setFire(map);
      this->defDown.setFire(map);
      this->defLeft.setFire(map);
      this->defRight.setFire(map);
    }
}

void		Bombe::doExplose(Map& map)
{
  map.setElement(this->getX(), this->getY(), NULL);
  this->defUp.explose(this->puiss, map);
  this->defDown.explose(this->puiss, map);
  this->defRight.explose(this->puiss, map);
  this->defLeft.explose(this->puiss, map);
  this->timer = 1;
  this->explo = true;
  map.setMapTableElement(x, y, false, COLLISION);
}

void		Bombe::explosed(Map& map)
{
  this->explo = false;
  this->plant = false;
  this->defUp.deleteFire(map);
  this->defDown.deleteFire(map);
  this->defLeft.deleteFire(map);
  this->defRight.deleteFire(map);
  this->timer = -1;
}

void		Bombe::checkBombe(const gdl::GameClock& clock, Map& map)
{
  if (this->timer != -1 && this->plant == true)
    {
      if (this->timer > 0)
	this->timer -= clock.getElapsedTime();
      else if (this->timer <= 0 && !this->explo)
	this->doExplose(map);
      else if (this->timer <= 0 && this->explo)
	this->explosed(map);
    }
}

int		Bombe::explose(Map& map)
{
  this->doExplose(map);
  return (1);
}

BombeContainer*	Bombe::container(void)
{
  return (new BombeContainer(this, new GlGraphics::DrawableObj::Bomb(GlGraphics::Vector3f(0, 0))));
}

ABlock*		Bombe::copy(int, int, Map&) const
{
  return (NULL);
}

std::string		Bombe::Serialize(const std::string& name)
{
  XMLParser	xml;

  xml.AddElem(name);
  xml.SetAttrib("ClassType", "Bombe");
  xml.IntoElem();
  xml.AddElem("PUISS", this->puiss);
  xml.AddElem("TIMER", Convert<float>::convertToType(this->timer));
  xml.AddElem("PLANT", this->plant);
  xml.AddElem("EXPLO", this->explo);
  xml.AddSubDoc(defUp.Serialize("defUp"));
  xml.AddSubDoc(defDown.Serialize("defDown"));
  xml.AddSubDoc(defLeft.Serialize("defLeft"));
  xml.AddSubDoc(defRight.Serialize("defRight"));
  xml.AddElem("X", this->x);
  xml.AddElem("Y", this->y);
  xml.OutOfElem();
  return (xml.GetDoc());
}

void		Bombe::Deserialize(const std::string& doc)
{
  std::string	str;
  XMLParser	xml(doc);
  
  xml.FindElem();
  xml.IntoElem();
  xml.FindElem("PUISS");
  this->puiss = MCD_STRTOINT(xml.GetData());
  xml.FindElem("TIMER");
  this->timer = Convert<float>::convertToType(xml.GetData());
  xml.FindElem("PLANT");
  this->plant = MCD_STRTOINT(xml.GetData());
  xml.FindElem("EXPLO");
  this->explo = MCD_STRTOINT(xml.GetData());
  xml.FindElem("defUp");
  this->defUp.Deserialize(xml.GetSubDoc());
  xml.FindElem("defDown");
  this->defDown.Deserialize(xml.GetSubDoc());
  xml.FindElem("defLeft");
  this->defLeft.Deserialize(xml.GetSubDoc());
  xml.FindElem("defRight");
  this->defRight.Deserialize(xml.GetSubDoc());
  xml.FindElem("X");
  this->x = MCD_STRTOINT(xml.GetData());
  xml.FindElem("Y");
  this->y = MCD_STRTOINT(xml.GetData());
  xml.OutOfElem();
}
