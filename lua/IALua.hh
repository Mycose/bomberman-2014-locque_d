//
// IALua.hh for  in /home/locque_d//rendu/proj/Bomberman/bomberman-2014-locque_d/lua
//
// Made by damien locque
// Login   <locque_d@epitech.net>
//
// Started on  Mon May 23 10:00:46 2011 damien locque
// Last update Sat Jun  4 20:12:52 2011 damien locque
//

#ifndef _IALUA_HH_
#define _IALUA_HH_

#include "TMap.hh"
#include "lunar.hpp"
#include "IABomberman.hh"

#define method(class, name) {#name, &class::name}

class IABomberman;

class IALua
{
public :
  IALua(lua_State *);
  ~IALua();

  int getx(lua_State *);
  int gety(lua_State *);

  int doMove(lua_State *);
  int doAction(lua_State *);

  int isMiddleCase(lua_State *);
  int getMapWidth(lua_State *);
  int getMapHeight(lua_State *);

  int getDeath(lua_State *);
  int getBonus(lua_State *);
  int getPlayer(lua_State *);
  int getPuissance(lua_State *);
  int getCollision(lua_State *);
  int getDangerous(lua_State *);
  int getTmpDangerous(lua_State *);
  int setTmpDangerous(lua_State *);
  int getDestructible(lua_State *);

  int getObjectiveX(lua_State *);
  int getObjectiveY(lua_State *);
  int getNewObjective(lua_State *);
  int setNewObjective(lua_State *);

  int getNbBombMax(lua_State *);
  int getNbBombDispo(lua_State *);

  static const char className[];
  static Lunar<IALua>::RegType methods[];
private:
  IABomberman	*_objReal;
  IALua(const IALua &);
  IALua& operator=(const IALua &);
};

#endif /* !_IALUA_HH_ */
