//
// IALua.cpp for  in /home/locque_d//rendu/proj/Bomberman/bomberman-2014-locque_d/lua
//
// Made by damien locque
// Login   <locque_d@epitech.net>
//
// Started on  Mon May 23 10:00:59 2011 damien locque
// Last update Sun Jun  5 11:09:48 2011 damien locque
//

#include "IALua.hh"
#include <iostream>

const char IALua::className[] = "IALua";
Lunar<IALua>::RegType IALua::methods[] = {
  method(IALua, getx),
  method(IALua, gety),
  method(IALua, doMove),
  method(IALua, doAction),
  method(IALua, getDeath),
  method(IALua, getBonus),
  method(IALua, getPuissance),
  method(IALua, getCollision),
  method(IALua, getDangerous),
  method(IALua, isMiddleCase),
  method(IALua, getPlayer),
  method(IALua, getDestructible),
  method(IALua, getObjectiveX),
  method(IALua, getObjectiveY),
  method(IALua, getNewObjective),
  method(IALua, setNewObjective),
  method(IALua, getNbBombMax),
  method(IALua, getNbBombDispo),
  method(IALua, getMapWidth),
  method(IALua, getMapHeight),
  method(IALua, getTmpDangerous),
  method(IALua, setTmpDangerous),
  {0,0}
};

IALua::IALua(lua_State *L)
{
  this->_objReal = static_cast<IABomberman *>(lua_touserdata(L, 1));
}

IALua::~IALua()
{

}

int	 IALua::doAction(lua_State *L)
{
  int action = static_cast<int>(luaL_checknumber(L, 1));
  this->_objReal->setAction(action);
  return (0);
}

int	IALua::doMove(lua_State *L)
{
  int move = static_cast<int>(luaL_checknumber(L, 1));
  this->_objReal->setMove(move);
  return (0);
}

int	IALua::getPuissance(lua_State *L)
{
  lua_pushinteger(L, this->_objReal->getPuiss());
  return (1);
}

int	IALua::getx(lua_State *L)
{
  lua_pushinteger(L, this->_objReal->getX());
  return (1);
}

int	IALua::gety(lua_State *L)
{
  lua_pushinteger(L, this->_objReal->getY());
  return (1);
}

int	IALua::isMiddleCase(lua_State *L)
{
  lua_pushboolean(L, this->_objReal->isMiddleCase());
  return (1);
}

int	IALua::getCollision(lua_State *L)
{
  if (lua_gettop(L) == 2 && lua_isnumber(L,1) && lua_isnumber(L,2))
    {
      int x = lua_tonumber(L,1);
      int y = lua_tonumber(L,2);
      lua_pushboolean(L, static_cast<int>(this->_objReal->getMap().getMapTableElement(x, y, COLLISION)));
    }
  else
    std::cerr << "GetCollision must have x and y value" << std::endl;
  return (1);
}

int	IALua::getDeath(lua_State *L)
{
  if (lua_gettop(L) == 2 && lua_isnumber(L,1) && lua_isnumber(L,2))
    {
      int x = lua_tonumber(L,1);
      int y = lua_tonumber(L,2);
      lua_pushboolean(L, static_cast<int>(this->_objReal->getMap().getMapTableElement(x, y, DEATH)));
    }
  else
    std::cerr << "GetDeath must have x and y value" << std::endl;
  return (1);
}

int	IALua::getBonus(lua_State *L)
{
  if (lua_gettop(L) == 2 && lua_isnumber(L,1) && lua_isnumber(L,2))
    {
      int x = lua_tonumber(L,1);
      int y = lua_tonumber(L,2);
      lua_pushboolean(L, static_cast<int>(this->_objReal->getMap().getMapTableElement(x, y, BONUS)));
    }
  else
    std::cerr << "GetBonus must have x and y value" << std::endl;
  return (1);
}

int	IALua::getPlayer(lua_State *L)
{
  if (lua_gettop(L) == 2 && lua_isnumber(L,1) && lua_isnumber(L,2))
    {
      int x = lua_tonumber(L,1);
      int y = lua_tonumber(L,2);
      lua_pushboolean(L, static_cast<int>(this->_objReal->getMap().getMapTableElement(x, y, PLAYER)));
    }
  else
    std::cerr << "GetPlayer must have x and y value" << std::endl;
  return (1);
}

int	IALua::getDangerous(lua_State *L)
{
  if (lua_gettop(L) == 2 && lua_isnumber(L,1) && lua_isnumber(L,2))
    {
      int x = lua_tonumber(L,1);
      int y = lua_tonumber(L,2);
      lua_pushboolean(L, static_cast<int>(this->_objReal->getMap().getMapTableElement(x, y, DANGEROUS)));
    }
  else
    std::cerr << "GetDangerous must have x and y value" << std::endl;
  return (1);
}

int	IALua::getDestructible(lua_State *L)
{
  if (lua_gettop(L) == 2 && lua_isnumber(L,1) && lua_isnumber(L,2))
    {
      int x = lua_tonumber(L,1);
      int y = lua_tonumber(L,2);
      lua_pushboolean(L, static_cast<int>(this->_objReal->getMap().getMapTableElement(x, y, DESTRUCT)));
    }
  else
    std::cerr << "GetDestructible must have x and y value" << std::endl;
  return (1);
}

int	IALua::getTmpDangerous(lua_State *L)
{
  if (lua_gettop(L) == 2 && lua_isnumber(L,1) && lua_isnumber(L,2))
    {
      int x = lua_tonumber(L,1);
      int y = lua_tonumber(L,2);
      lua_pushboolean(L, static_cast<int>(this->_objReal->getMap().getMapTableElement(x, y, TMPDANG)));
    }
  else
    std::cerr << "GetTmpDangerous must have x and y value" << std::endl;
  return (1);
}

int	IALua::setTmpDangerous(lua_State *L)
{
  if (lua_gettop(L) == 3 && lua_isnumber(L,1) && lua_isnumber(L,2) && lua_isboolean(L,3))
    {
      int x = lua_tonumber(L,1);
      int y = lua_tonumber(L,2);
      bool val = lua_toboolean(L,3);
      this->_objReal->getMap().setMapTableElement(x, y, val, TMPDANG);
    }
  else
    std::cerr << "SetTmpDangerous must have x and y value and bool value" << std::endl;
  return (1);
}

int	IALua::getObjectiveX(lua_State *L)
{
  lua_pushinteger(L, this->_objReal->getObjectiveX());
  return (1);
}

int	IALua::getObjectiveY(lua_State *L)
{
  lua_pushinteger(L, this->_objReal->getObjectiveY());
  return (1);
}

int	IALua::getNewObjective(lua_State *L)
{
  static_cast<void>(L);
  this->_objReal->getNewObjective();
  return (0);
}

int	IALua::setNewObjective(lua_State *L)
{
  if (lua_gettop(L) == 2 && lua_isnumber(L,1) && lua_isnumber(L,2))
    {
      int x = lua_tonumber(L,1);
      int y = lua_tonumber(L,2);
      this->_objReal->setNewObjective(x, y);
    }
  else
    std::cerr << "SetNewObjective must have x and y value" << std::endl;
  return (0);
}

int	IALua::getNbBombMax(lua_State *L)
{
  lua_pushinteger(L, this->_objReal->getNbBombMax());
  return (1);
}

int	IALua::getNbBombDispo(lua_State *L)
{
  lua_pushinteger(L, this->_objReal->getNbBombDispo());
  return (1);
}

int	IALua::getMapWidth(lua_State *L)
{
  lua_pushinteger(L, this->_objReal->getMap().getWidth());
  return (1);
}

int	IALua::getMapHeight(lua_State *L)
{
  lua_pushinteger(L, this->_objReal->getMap().getHeight());
  return (1);
}
