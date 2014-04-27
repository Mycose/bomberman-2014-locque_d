//
// Serializer.cpp for bomberman in /home/moriss_c//projs/Bomberman/local
// 
// Made by clement morissard
// Login   <moriss_c@epitech.net>
// 
// Started on  Thu May 26 14:56:48 2011 clement morissard
// Last update Sun Jun  5 16:33:08 2011 nicolas laille
//

#include <stdexcept>
#include <list>
#include <sstream>
#include <iostream>

#include "converter.hpp"
#include "intlen.hpp"

#include "Mapgen.hh"
#include "Map.hh"
#include "Bombe.hh"
#include "Bomberman.hh"
#include "IABomberman.hh"

#include "Serializer.hh"

Serializer::Serializer()
  : xml()
{
}

Serializer::~Serializer()
{
}

bool		Serializer::loadGame(std::string const & load, std::list<ABomberman *>& pl, Mapgen& mapgen, std::list<GlGraphics::GlCamera>& cameras)
{
  if (load == "")
    return (false);
  try
    {
      std::cout << "Load File : " << load << std::endl;
      this->xml.Load(load);
      this->xml.FindElem("BOMBERMANSAVE");
      this->xml.IntoElem();
      this->xml.FindElem("MAPGEN");
      mapgen.Deserialize(this->xml.GetSubDoc());
      this->xml.ResetPos();
      this->xml.FindElem("BOMBERMANSAVE");
      this->xml.IntoElem();      
      this->DeserializePlayers(pl, mapgen.getMap(), cameras);
    }
  catch (std::runtime_error e)
    {
      std::cerr << "Load File : " << load << " FAILED" << std::endl;
      return (false);
    }
  return (true);
}

void		Serializer::createSave(std::list<ABomberman *>& pl, Mapgen& mapgen)
{
  std::string		str;
  std::stringstream	ss;
  time_t              t = time(NULL);
  struct tm           *tim;
  XMLParser		x;

  tim = localtime(&t);
  ss << "Savegames/Bomberman-";
  if (Length::intLen(tim->tm_mday) == 1)
    ss << '0';
  ss << tim->tm_mday << '-';
  if (Length::intLen(tim->tm_mon + 1) == 1)
    ss << '0';
  ss << tim->tm_mon << '-' << (1900 + tim->tm_year) << '-';
  if (Length::intLen(tim->tm_hour) == 1)
    ss << '0';
  ss << tim->tm_hour << '-';
  if (Length::intLen(tim->tm_min) == 1)
    ss << '0';
  ss << tim->tm_min << ".xml";
  this->_save = ss.str();

  x.AddElem("BOMBERMANSAVE");
  x.IntoElem();
  x.AddSubDoc(this->SerializePlayers(pl));
  x.AddSubDoc(mapgen.Serialize("MAPGEN"));
  std::cout << "New Save: " << this->_save << std::endl;
  x.Save(this->_save);
}

std::string		Serializer::SerializePlayers(std::list<ABomberman *>& players)
{
  std::list<ABomberman *>::iterator it;
  std::string	str;
  int		i = 1;
  XMLParser	xml;

  xml.AddElem("PlayersList");
  xml.IntoElem();
  xml.AddElem("NbPlayers", players.size());
  if (players.size() != 0)
    {
      for (it = players.begin() ; it != players.end() ; ++it)
	{
	  std::string str("Player" + Convert<float>::convertToType(i));

	  xml.AddSubDoc((*it)->Serialize(str));
	  ++i;
	}
    }
  xml.OutOfElem();
  return (xml.GetDoc());
}

void		 	Serializer::DeserializePlayers(std::list<ABomberman *>& pl, Map& map, std::list<GlGraphics::GlCamera>& cameras)
{
  std::string		str;
  int			i = 1;
  int			real = 0;
  int			nbPlayer;

  this->xml.FindElem("PlayersList");
  this->xml.IntoElem();
  this->xml.FindElem("NbPlayers");
  nbPlayer = MCD_STRTOINT(xml.GetData());
  while (i <= nbPlayer && this->xml.FindElem("Player" + Convert<float>::convertToType(i)))
    {
      std::string	pn("Player" + Convert<float>::convertToType(i));

      std::cout << pn << std::endl;
      if (this->xml.GetAttrib("ClassType") == "Bomberman")
	{
	  Bomberman	*b;
	  if (!real)
	    b = new Bomberman(0, 0);
	  else
	    b = new Bomberman(0, 0,
			      gdl::Keys::W,
			      gdl::Keys::S,
			      gdl::Keys::D,
			      gdl::Keys::A,
			      gdl::Keys::Space);
	  str = this->xml.GetSubDoc();
	  b->Deserialize(str);
	  b->initBombes(map);
	  pl.push_back(b);
	  ++i;
	  real++;
	  if (real == 1)
	    cameras.push_back(GlGraphics::GlCamera(b, GlGraphics::GLV_SINGLESCR));
	  else if (real == 2)
	    {
	      cameras.front().setViewField(GlGraphics::GLV_LEFTSCR);
	      cameras.push_back(GlGraphics::GlCamera(b, GlGraphics::GLV_RIGHTSCR));
	    }
	}
      else if (this->xml.GetAttrib("ClassType") == "IABomberman")
	{
	  IABomberman	*ia = new IABomberman(map);

	  str = this->xml.GetSubDoc();
	  ia->Deserialize(str);
	  ia->initBombes(map);
	  pl.push_back(ia);
	  ++i;
	}
      else
	throw std::runtime_error("Attribute unknown, save corrupted");
    }
}

XMLParser const&	Serializer::getCMarkup() const
{
  return (this->xml);
}
