--[[
  -- bomb_check.lua for  in /home/locque_d//rendu/proj/Bomberman/bomberman-2014-locque_d/lua/script
  --
  -- Made by damien locque
  -- Login   <locque_d@epitech.net>
  --
  -- Started on  Fri Jun  3 17:51:17 2011 damien locque
  -- Last update Sun Jun  5 11:13:23 2011 damien locque
]]--

function try_put_bomb()
   for y = 0,bomber:getMapHeight() - 1 do
      for x = 0,bomber:getMapWidth() - 1 do
	 if bomber:getDangerous(x, y) == true then
	    bomber:setTmpDangerous(x, y, true)
	 else
	    bomber:setTmpDangerous(x, y, false)
	 end
      end
   end
   bomber:setTmpDangerous(myx, myy, true)

   for i = 1,bomber:getPuissance() do
      if bomber:getCollision(myx, myy + i) or bomber:getDestructible(myx, myy + i) then
	 break
      end
      bomber:setTmpDangerous(myx, myy + i, true)
   end
   for i = 1,bomber:getPuissance() do
      if bomber:getCollision(myx, myy - i) or bomber:getDestructible(myx, myy - i) then
	 break
      end
      bomber:setTmpDangerous(myx, myy - i, true)
   end

   for i = 1,bomber:getPuissance() do
      if bomber:getCollision(myx + i, myy) or bomber:getDestructible(myx + i, myy) then
	 break
      end
      bomber:setTmpDangerous(myx + i, myy, true)
   end
   for i = 1,bomber:getPuissance() do
      if bomber:getCollision(myx - i, myy) or bomber:getDestructible(myx - i, myy) then
	 break
      end
      bomber:setTmpDangerous(myx - i, myy, true)
   end

   local tab = fill_table()
   s_setx(-1)
   s_sety(-1)
   s_setval(-1)
   for i = 0, (getWidth() * getHeight() - 1) do
      if tab[i] == -1 or tab[i] == 0 then
      elseif (s_getval() == -1 or s_getval() > tab[i]) and not bomber:getTmpDangerous((myx - 5 + (i % getHeight())), (myy - 5 + math.floor(i / (getHeight())))) then
	 s_setx(i % getHeight())
	 s_sety(math.floor(i / getHeight()))
	 s_setval(tab[i])
      end
   end
   if s_getval() < 0 or s_getval() > 3 then
      return (false)
   end
   while s_getval() > 1 do
      if bomber:getDeath((myx - 5 + s_getx()), (myy - 5 + s_gety())) then
	 return (false)
      end
      if tab[(s_gety() * getHeight()) + s_getx() + 1] == (s_getval() - 1) then
	 s_setx(s_getx() + 1)
	 s_setval(tab[(s_gety() * getHeight()) + s_getx()])
      elseif tab[(s_gety() * getHeight()) + s_getx() - 1] == (s_getval() - 1) then
	 s_setx(s_getx() - 1)
	 s_setval(tab[(s_gety() * getHeight()) + s_getx()])
      elseif tab[((s_gety() - 1) * getHeight()) + s_getx()] == (s_getval() - 1) then
	 s_sety(s_gety() - 1)
	 s_setval(tab[(s_gety() * getHeight()) + s_getx()])
      elseif tab[((s_gety() + 1) * getHeight()) + s_getx()]  == (s_getval() - 1) then
	 s_sety(s_gety() + 1)
	 s_setval(tab[(s_gety() * getHeight()) + s_getx()])
      end
   end
   return (true)
end