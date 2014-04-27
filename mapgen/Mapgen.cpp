//
// Mapgen.cpp for  in /home/locque_d//rendu/proj/Bomberman/bomberman-2014-locque_d/mapgen
//
// Made by damien locque
// Login   <locque_d@epitech.net>
//
// Started on  Thu May 12 14:35:19 2011 damien locque
// Last update Fri Jun  3 13:02:58 2011 nicolas laille
//
#include <iostream>
#include "Mapgen.hh"

Mapgen::Mapgen() : _map(), _playerpos()
{
}

Mapgen::~Mapgen()
{
}

void Mapgen::create(int width, int height, int nbPlayer)
{
  this->_map.create(width, height, nbPlayer, this->_playerpos);
}

Map&	Mapgen::getMap()
{
  return (this->_map);
}

Playerpos&	Mapgen::getPlayerpos()
{
  return (this->_playerpos);
}

std::string	Mapgen::Serialize(const std::string& name)
{
  std::string	str;
  XMLParser	xml;

  xml.AddElem(name);
  xml.SetAttrib("ClassType", "Mapgen");
  xml.IntoElem();
  xml.AddSubDoc(this->_map.Serialize("MAP"));
  xml.OutOfElem();
  return (xml.GetDoc());
}

void		Mapgen::Deserialize(const std::string& doc)
{
  XMLParser	xml(doc);

  xml.FindElem();
  xml.IntoElem();
  xml.FindElem("MAP");
  this->_map.Deserialize(xml.GetSubDoc());
  xml.OutOfElem();
}
