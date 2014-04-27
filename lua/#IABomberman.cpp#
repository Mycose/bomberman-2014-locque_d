//
// IABomberman.cpp for  in /home/locque_d//rendu/proj/Bomberman/bomberman-2014-locque_d/lua
//
// Made by damien locque
// Login   <locque_d@epitech.net>
//
// Started on  Mon May 23 09:39:55 2011 damien locque
// Last update Sun Jun  5 11:08:16 2011 damien locque
//

#include <cstdlib>
#include <iostream>
#include "IABomberman.hh"
#include "converter.hpp"

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

IABomberman::IABomberman(Map& map) : ABomberman(0, 0), _map(map)
{
}

IABomberman::IABomberman(int x, int y, Map &map, const std::string &file) :
  ABomberman(x, y), _map(map), _file(file), _move(-1), _action(-1)
{
  std::cout << "IA [" << x << " - " << y << "]" << std::endl;
  this->_state = lua_open();
  luaL_openlibs(this->_state);
  Lunar<IALua>::Register(this->_state);
  lua_pushlightuserdata(this->_state, (void*)this);
  lua_setglobal(this->_state, "IA");
  this->getNewObjective();
}

IABomberman::~IABomberman()
{
}

Map &IABomberman::getMap() const
{
  return (this->_map);
}

int		IABomberman::update(gdl::Input&, Map& map)
{
  int		tmp;

  this->_action = -1;
  if (luaL_dofile(this->_state, this->_file.c_str()) != 0)
    {
      std::cerr << lua_tostring(this->_state, -1) << std::endl;
    }
  this->doAction(this->_action, map);
  map.setMapTableElement(this->getX(), this->getY(), false, PLAYER);
  tmp = this->doMove(this->_move, map);
  map.setMapTableElement(this->getX(), this->getY(), true, PLAYER);
  return (tmp);
}

void IABomberman::setAction(int action)
{
  this->_action = action;
}

void IABomberman::setMove(int move)
{
  this->_move = move;
}

int IABomberman::getObjectiveX() const
{
  return (this->_objective.first);
}

int IABomberman::getObjectiveY() const
{
  return (this->_objective.second);
}

void IABomberman::getNewObjective()
{
  int	x = 0;
  int	y = 0;
  bool	flag = false;
  while (!flag)
    {
      flag = true;
      x = (1 + rand() % (this->_map.getWidth() - 1));
      y = (1 + rand() % (this->_map.getHeight() - 1));
      if (this->_map.getMapTableElement(x, y, COLLISION))
	flag = false;
      if (this->_map.getMapTableElement(x, y, DANGEROUS))
	flag = false;
      if (this->_objective.first == x && this->_objective.second == y)
	flag = false;
    }
  this->_objective.first = x;
  this->_objective.second = y;
}

void IABomberman::setNewObjective(int x, int y)
{
  this->_objective.first = x;
  this->_objective.second = y;
}

bool IABomberman::isMiddleCase() const
{
  return ((!(this->x % BLOCK_SIZE) && !(this->y % BLOCK_SIZE)));
}

std::string	IABomberman::Serialize(const std::string& name)
{
  CMarkup	xml;

  xml.AddElem(name);
  xml.SetAttrib("ClassType", "IABomberman");
  xml.IntoElem();
  xml.AddElem("X", this->x);
  xml.AddElem("Y", this->y);
  xml.AddElem("LIFE", this->life);
  xml.AddElem("MOVESPEED", Convert<float>::convertToType(this->moveSpeed));
  xml.AddElem("SPEED", this->speed);
  xml.AddElem("PUISS", this->puiss);
  xml.AddElem("SCORE", this->score);
  xml.AddElem("MOVE", Convert<float>::convertToType(this->nextMove));
  xml.AddElem("FILE", this->_file);
  xml.AddElem("NEXTMOVE", this->_move);
  xml.AddElem("OBJECTIFX", this->_objective.first);
  xml.AddElem("OBJECTIFY", this->_objective.second);
  xml.AddSubDoc(this->SerializeBombs("BombsList"));
  xml.OutOfElem();
  return (xml.GetDoc());
}

void		IABomberman::Deserialize(const std::string& doc)
{
  std::string	str;
  CMarkup	xml(doc);

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
  xml.FindElem("FILE");
  this->_file = xml.GetData();
  xml.FindElem("NEXTMOVE");
  this->_move = MCD_STRTOINT(xml.GetData());
  xml.FindElem("OBJECTIFX");
  this->_objective.first = MCD_STRTOINT(xml.GetData());
  xml.FindElem("OBJECTIFY");
  this->_objective.second = MCD_STRTOINT(xml.GetData());
  std::cout << this->_file << std::endl;
  xml.FindElem("BombsList");
  str = xml.GetSubDoc();
  this->DeserializeBombs(str);
  this->setPosition(this->x, this->y);

  this->_state = lua_open();
  luaL_openlibs(this->_state);
  Lunar<IALua>::Register(this->_state);
  lua_pushlightuserdata(this->_state, (void*)this);
  lua_setglobal(this->_state, "IA");
  this->getNewObjective();
}
