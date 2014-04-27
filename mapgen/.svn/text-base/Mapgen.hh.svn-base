//
// Mapgen.hh for  in /home/locque_d//rendu/proj/Bomberman/bomberman-2014-locque_d/mapgen
//
// Made by damien locque
// Login   <locque_d@epitech.net>
//
// Started on  Thu May 12 14:35:16 2011 damien locque
// Last update Fri Jun  3 12:35:55 2011 nicolas laille
//

#ifndef _MAPGEN_HH_
#define _MAPGEN_HH_

#include	"Map.hh"
#include	"Playerpos.hh"

class		Mapgen : public ISerializer
{
public :
  Mapgen();
  ~Mapgen();
  void		create(int, int, int);
  Map&		getMap();
  Playerpos&	getPlayerpos();

  virtual std::string	Serialize(const std::string& name);
  virtual void		Deserialize(const std::string& doc);
private :
  Map		_map;
  Playerpos	_playerpos;

  Mapgen(const Mapgen &);
  Mapgen& operator=(const Mapgen &);
};

#endif /* !_MAPGEN_HH_ */
