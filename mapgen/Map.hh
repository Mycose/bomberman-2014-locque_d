//
// Map.hh for  in /home/locque_d//rendu/proj/Bomberman/mapgen
//
// Made by damien locque
// Login   <locque_d@epitech.net>
//
// Started on  Tue May  3 16:09:18 2011 damien locque
// Last update Sun Jun  5 10:11:46 2011 nicolas laille
//


#ifndef _MAP_HH_
#define _MAP_HH_

class	Map;

#include	<Game.hpp>
#include	<vector>
#include	<Game.hpp>
#include	<Clock.hpp>
#include	<Input.hpp>
#include	<string>


#include	<map>

#include	"TMap.hh"
#include	"ABlock.hh"
#include	"Playerpos.hh"

class		ABomberman;

class Map : public ISerializer
{
public :
  Map();
  ~Map();
  int				getWidth() const;
  int				getHeight() const;
  ABlock			*getElement(int, int) const;
  void				setElement(int, int, ABlock *);
  void				create(int, int, int, Playerpos&);

  bool				getMapTableElement(int x, int y, maptype type) const;
  void				setMapTableElement(int x, int y, bool val, maptype type);

  virtual std::string		Serialize(const std::string& name);
  virtual void			Deserialize(const std::string& doc);

  std::string			SerializeBlocks(const std::string& name);
  void				DeserializeBlocks(const std::string& doc);

  // GRAPHICS
  void				initialize(void);
  void				update(ABomberman&, const gdl::GameClock&, gdl::Input&);
  void				draw(ABomberman&);
  void				unload(void);

private :
  int				_width;
  int				_height;
  int				_nbPlayer;
  std::vector<ABlock *>		_map;
  ABlock			*_voidclass;
  TMap				_maptable;
  void				alea_box();
  bool				set_player_positions(Playerpos&);
  bool				put_player(int, int, Playerpos&);

  std::map<std::string, ABlock *>	_deseri;
};

#endif /* !_MAP_HH_ */
