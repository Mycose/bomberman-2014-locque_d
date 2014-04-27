--[[
  -- check.lua for  in /home/locque_d//rendu/proj/Bomberman/bomberman-2014-locque_d
  --
  -- Made by damien locque
  -- Login   <locque_d@epitech.net>
  --
  -- Started on  Mon May 30 17:45:41 2011 damien locque
  -- Last update Sun Jun  5 11:19:16 2011 damien locque
]]--

function check_left(movx, movy)
   if not bomber:getDangerous(myx - 1, myy) and not bomber:getCollision(myx - 1, myy) then
      if bomber:getDestructible(myx - 1, myy) and try_put_bomb() then
	 bomber:doAction(BOMB)
      elseif bomber:getDestructible(myx - 1, myy) then
	 change_objective()
      end
      bomber:doMove(LEFT)
   elseif myy > objy and not bomber:getDangerous(myx, myy -1) and not bomber:getCollision(myx, myy - 1) then
      if bomber:getDestructible(myx, myy - 1) and try_put_bomb() then
	 bomber:doAction(BOMB)
      elseif bomber:getDestructible(myx, myy - 1) then
	 change_objective()
      end
      bomber:doMove(UP)
   elseif not bomber:getDangerous(myx, myy + 1) and not bomber:getCollision(myx, myy + 1) then
      if bomber:getDestructible(myx, myy + 1) and try_put_bomb() then
	 bomber:doAction(BOMB)
      elseif bomber:getDestructible(myx, myy + 1) then
	 change_objective()
      end
	 bomber:doMove(DOWN)
   elseif not bomber:getDangerous(myx + 1, myy) and not bomber:getCollision(myx + 1, myy) then
      change_objective()
      bomber:doMove(RIGHT)
   else
      change_objective()
      bomber:doMove(UNKNOW)
   end
end

function check_right(movx, movy)
   if not bomber:getDangerous(myx + 1, myy) and not bomber:getCollision(myx + 1, myy) then
      if bomber:getDestructible(myx + 1, myy) and try_put_bomb() then
	 bomber:doAction(BOMB)
      elseif bomber:getDestructible(myx + 1, myy) then
	 change_objective()
      end
      bomber:doMove(RIGHT)
   elseif myy > objy and not bomber:getDangerous(myx, myy - 1) and not bomber:getCollision(myx, myy - 1) then
      if bomber:getDestructible(myx, myy - 1) and try_put_bomb() then
	 bomber:doAction(BOMB)
      elseif bomber:getDestructible(myx, myy -1) then
	 change_objective()
      end
	 bomber:doMove(UP)
   elseif not bomber:getDangerous(myx, myy + 1) and not bomber:getCollision(myx, myy + 1) then
      if bomber:getDestructible(myx, myy + 1) and try_put_bomb() then
	 bomber:doAction(BOMB)
      elseif bomber:getDestructible(myx, myy + 1) then
	 change_objective()
      end
      bomber:doMove(DOWN)
   elseif not bomber:getDangerous(myx - 1, myy) and not bomber:getCollision(myx - 1, myy) then
      change_objective()
      bomber:doMove(LEFT)
   else
      change_objective()
      bomber:doMove(UNKNOW)
   end
end

function check_up(movx, movy)
   if not bomber:getDangerous(myx, myy - 1) and not bomber:getCollision(myx, myy - 1) then
      if bomber:getDestructible(myx, myy - 1) and try_put_bomb() then
	 bomber:doAction(BOMB)
      elseif bomber:getDestructible(myx, myy - 1) then
	 change_objective()
      end
      bomber:doMove(UP)
   elseif myx > objx and not bomber:getDangerous(myx - 1, myy) and not bomber:getCollision(myx - 1, myy) then
      if bomber:getDestructible(myx - 1, myy) and try_put_bomb() then
	 bomber:doAction(BOMB)
      elseif bomber:getDestructible(myx - 1, myy) then
	 change_objective()
      end
      bomber:doMove(LEFT)
   elseif not bomber:getDangerous(myx + 1, myy) and not bomber:getCollision(myx + 1, myy) then
      if bomber:getDestructible(myx + 1, myy) and try_put_bomb() then
	 bomber:doAction(BOMB)
      elseif bomber:getDestructible(myx + 1, myy) then
	 change_objective()
      end
      bomber:doMove(RIGHT)
   elseif not bomber:getDangerous(myx, myy + 1) and not bomber:getCollision(myx, myy + 1) then
      change_objective()
      bomber:doMove(DOWN)
   else
      change_objective()
      bomber:doMove(UNKNOW)
   end
end

function check_down(movx, movy)
   if not bomber:getDangerous(myx, myy + 1) and not bomber:getCollision(myx, myy + 1) then
      if bomber:getDestructible(myx, myy + 1) and try_put_bomb() then
	 bomber:doAction(BOMB)
      elseif bomber:getDestructible(myx, myy + 1) then
	 change_objective()
      end
      bomber:doMove(DOWN)
   elseif myx > objx and not bomber:getDangerous(myx - 1, myy) and not bomber:getCollision(myx - 1, myy) then
      if bomber:getDestructible(myx - 1, myy) and try_put_bomb() then
	 bomber:doAction(BOMB)
      elseif bomber:getDestructible(myx - 1, myy) then
	 change_objective()
      end
      bomber:doMove(LEFT)
   elseif not bomber:getDangerous(myx + 1, myy) and not bomber:getCollision(myx + 1, myy) then
      if bomber:getDestructible(myx + 1, myy) and try_put_bomb() then
	 bomber:doAction(BOMB)
      elseif bomber:getDestructible(myx + 1, myy) then
	 change_objective()
      end
      bomber:doMove(RIGHT)
   elseif not bomber:getDangerous(myx, myy - 1) and not bomber:getCollision(myx, myy - 1) then
      change_objective()
      bomber:doMove(UP)
   else
      change_objective()
      bomber:doMove(UNKNOW)
   end
end
