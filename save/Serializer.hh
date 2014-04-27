//
// Serializer.hh for bomber in /home/moriss_c//projs/bomberman/other
// 
// Made by clement morissard
// Login   <moriss_c@epitech.net>
// 
// Started on  Wed May 25 13:07:49 2011 clement morissard
// Last update Sat Jun  4 20:15:06 2011 nicolas laille
//

#ifndef		__SERIALIZER_HH__
# define	__SERIALIZER_HH__

#include <string>
#include <list>
#include <vector>

class ABomberman;
class ABlock;
class ABombe;
class Mapgen;
class Map;

#include "bomb_gl_camera.hh"

#include "XMLParser.hh"

class Serializer
{
public:
  Serializer();
  ~Serializer();

  void		createSave(std::list<ABomberman *>& pl, Mapgen& mapgen);
  bool		loadGame(std::string const &, std::list<ABomberman *>& pl, Mapgen& mapgen, std::list<GlGraphics::GlCamera>& cameras);

  std::string	SerializePlayers(std::list<ABomberman *>& players);
  void		DeserializePlayers(std::list<ABomberman *>& pl, Map& map, std::list<GlGraphics::GlCamera>& cameras);

  XMLParser const&	getCMarkup() const;
private:
  XMLParser	xml;
  std::string	_save;
};

#endif /* __SERIALIZER_HH__ */
