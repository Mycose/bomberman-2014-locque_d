--[[
  -- low.lua for  in /home/locque_d//rendu/proj/Bomberman/bomberman-2014-locque_d/lua/script
  --
  -- Made by damien locque
  -- Login   <locque_d@epitech.net>
  --
  -- Started on  Mon May 23 15:30:18 2011 damien locque
  -- Last update Sun Jun  5 11:12:38 2011 damien locque
]]--

UNKNOW	=	42
UP	=	0
DOWN	=	1
RIGHT	=	2
LEFT	=	3
BOMB	=	0
bomber	=	IALua(IA)
myx	=	bomber:getx()
myy	=	bomber:gety()
objx	=	bomber:getObjectiveX()
objy	=	bomber:getObjectiveY()
flag	=	true
dofile "lua/script/check.lua"
dofile "lua/script/table.lua"
dofile "lua/script/util.lua"
dofile "lua/script/struct.lua"
dofile "lua/script/objective.lua"
dofile "lua/script/offensive.lua"
dofile "lua/script/deffensive.lua"
dofile "lua/script/bomb_check.lua"

if not bomber:isMiddleCase() then
   flag = false
end

if flag == true and myx == objx and myy == objy then
   change_objective()
   objx	= bomber:getObjectiveX()
   objy	= bomber:getObjectiveY()
end

if flag == true and not bomber:getDangerous(myx, myy) == true then
   if can_attack() and try_put_bomb() then
      bomber:doAction(BOMB)
   else
      do_offensive()
   end
elseif flag == true then
   do_defensive()
end
