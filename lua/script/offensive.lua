--[[
  -- offensive.lua for  in /home/locque_d//rendu/proj/Bomberman/maybe/bomberman-2014-locque_d
  --
  -- Made by damien locque
  -- Login   <locque_d@epitech.net>
  --
  -- Started on  Sat Jun  4 20:18:34 2011 damien locque
  -- Last update Tue Jul  5 15:33:55 2011 damien locque
]]--


function can_attack()
   for i = 1,bomber:getPuissance() do
      if bomber:getCollision(myx, myy + i) or bomber:getDestructible(myx, myy + i) then
	 break
      end
      if bomber:getPlayer(myx, myy + i) then
	 return (true)
      end
   end

   for i = 1,bomber:getPuissance() do
      if bomber:getCollision(myx, myy - i) or bomber:getDestructible(myx, myy - i) then
	 break
      end
      if bomber:getPlayer(myx, myy - i) then
	 return (true)
      end
   end

   for i = 1,bomber:getPuissance() do
      if bomber:getCollision(myx + i, myy) or bomber:getDestructible(myx + i, myy) then
	 break
      end
      if bomber:getPlayer(myx + i, myy) then
	 return (true)
      end
   end

   for i = 1,bomber:getPuissance() do
      if bomber:getCollision(myx - i, myy) or bomber:getDestructible(myx - i, myy) then
	 break
      end
      if bomber:getPlayer(myx - i, myy) then
	 return (true)
      end
   end
   return (false)
end

function do_offensive()
   local movx = ABS(myx - objx)
   local movy = ABS(myy - objy)
   if movx > movy then
      if myx > objx then
	 check_left(movx, movy)
      else
	 check_right(movx, movy)
      end
   else
      if myy > objy then
	 check_up(movx, movy)
      else
	 check_down(movx, movy)
      end
   end
end
