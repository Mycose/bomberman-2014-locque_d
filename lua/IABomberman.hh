//
// IABomberman.hh for  in /home/locque_d//rendu/proj/Bomberman/bomberman-2014-locque_d/lua
//
// Made by damien locque
// Login   <locque_d@epitech.net>
//
// Started on  Mon May 23 09:39:42 2011 damien locque
// Last update Fri Jun  3 17:54:38 2011 damien locque
//

#ifndef _IABOMBERMAN_HH_
#define _IABOMBERMAN_HH_

// test
#include	<string>
#include	<Input.hpp>
#include	"Map.hh"
#include	"IALua.hh"
#include	"lunar.hpp"
#include	"ABomberman.hh"
#include	"bomb_gl_inputman.hh"
// test

class IABomberman : public ABomberman
{
public :
  IABomberman(Map& map);
  IABomberman(int, int, Map &, const std::string &);
  virtual ~IABomberman();
  virtual int update(gdl::Input&, Map& map);
  Map &getMap() const;
  void setAction(int);
  void setMove(int);
  int getObjectiveX() const;
  int getObjectiveY() const;
  void getNewObjective();
  void setNewObjective(int, int);
  bool isMiddleCase() const;

  virtual std::string	Serialize(const std::string& name);
  virtual void		Deserialize(const std::string& doc);

private:
  Map &_map;
  lua_State *		_state;
  std::string		_file;
  std::pair<int, int>	_objective;
  int			_move;
  int			_action;
  IABomberman(const IABomberman &);
  IABomberman& operator=(const IABomberman &);
};

#endif /* !_IABOMBERMAN_HH_ */
