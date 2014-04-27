//
// Bomberman.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Fri Apr 29 15:08:51 2011 nicolas laille
// Last update Sun Jun  5 10:45:10 2011 nicolas laille
//

#include	<iostream>
#include	<stdexcept>

#include	"converter.hpp"
#include	"Bomberman.hh"

Bomberman::Bomberman(int x, int y,
		     gdl::Keys::Key up,
		     gdl::Keys::Key down,
		     gdl::Keys::Key right,
		     gdl::Keys::Key left,
		     gdl::Keys::Key plant)
  : ABomberman(x, y, up, down, right, left, plant)
{
  std::cout << "Bomberman [" << x << " - " << y << "]" << std::endl;
}

Bomberman::~Bomberman(void)
{
}

int		Bomberman::update(gdl::Input& input, Map& map)
{
  int		tmp;

  this->doAction(input, map);
  map.setMapTableElement(this->getX(), this->getY(), false, PLAYER);
  tmp = this->doMove(input, map);
  map.setMapTableElement(this->getX(), this->getY(), true, PLAYER);
  return (tmp);
}

std::string	Bomberman::Serialize(const std::string& name)
{
  XMLParser	xml;

  xml.AddElem(name);
  xml.SetAttrib("ClassType", "Bomberman");
  xml.IntoElem();
  xml.AddElem("X", this->x);
  xml.AddElem("Y", this->y);
  xml.AddElem("LIFE", this->life);
  xml.AddElem("MOVESPEED", Convert<float>::convertToType(this->moveSpeed));
  xml.AddElem("SPEED", this->speed);
  xml.AddElem("PUISS", this->puiss);
  xml.AddElem("SCORE", this->score);
  xml.AddElem("MOVE", Convert<float>::convertToType(this->nextMove));
  xml.AddSubDoc(this->SerializeBombs("BombsList"));
  xml.OutOfElem();
  return (xml.GetDoc());
}

void		Bomberman::Deserialize(const std::string& doc)
{
  XMLParser	xml(doc);

  xml.FindElem();
  xml.IntoElem();
  xml.FindElem("X");
  this->x = MCD_STRTOINT(xml.GetData());
  xml.FindElem("Y");
  this->y = MCD_STRTOINT(xml.GetData());
  xml.FindElem("LIFE");
  this->life = MCD_STRTOINT(xml.GetData());
  xml.FindElem("MOVESPEED");
  this->moveSpeed = Convert<float>::convertToType(xml.GetData());
  xml.FindElem("SPEED");
  this->speed = MCD_STRTOINT(xml.GetData());
  xml.FindElem("PUISS");
  this->puiss = MCD_STRTOINT(xml.GetData());
  xml.FindElem("SCORE");
  this->score = MCD_STRTOINT(xml.GetData());
  xml.FindElem("MOVE");
  this->nextMove = Convert<float>::convertToType(xml.GetData());
  xml.FindElem("BombsList");
  this->DeserializeBombs(xml.GetSubDoc());
  this->setPosition(this->x, this->y);
}
