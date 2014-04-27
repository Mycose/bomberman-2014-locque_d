--[[
  -- objective.lua for  in /home/locque_d//rendu/proj/Bomberman/maybe/bomberman-2014-locque_d
  --
  -- Made by damien locque
  -- Login   <locque_d@epitech.net>
  --
  -- Started on  Sun Jun  5 11:10:15 2011 damien locque
  -- Last update Sun Jun  5 11:22:55 2011 damien locque
]]--

function change_objective()
   local tab = fill_table()
   s_setx(-1)
   s_sety(-1)
   s_setval(-1)
   local xsave = 0;
   local ysave = 0;

   for i = 0, (getWidth() * getHeight() - 1) do
      if tab[i] == -1 or tab[i] == 0 then
      elseif (s_getval() == -1 or s_getval() > tab[i]) and bomber:getBonus((myx - 5 + (i % getHeight())), (myy - 5 + math.floor(i / (getHeight())))) then
	 s_setx(i % getHeight())
	 s_sety(math.floor(i / getHeight()))
	 s_setval(tab[i])
      end
   end

   if s_getval() < 0 or s_getval() > 3 then
      s_setx(-1)
      s_sety(-1)
      s_setval(-1)
      for i = 0, (getWidth() * getHeight() - 1) do
	 if tab[i] == -1 or tab[i] == 0 then
	 elseif (s_getval() == -1 or s_getval() > tab[i]) and bomber:getPlayer((myx - 5 + (i % getHeight())), (myy - 5 + math.floor(i / (getHeight())))) then
	    s_setx(i % getHeight())
	    s_sety(math.floor(i / getHeight()))
	    s_setval(tab[i])
	 end
      end
   end

   if s_getval() < 0 or s_getval() > 3 then
      bomber:getNewObjective()
      return (false)
   end

   xsave = s_getx()
   ysave = s_gety()

   while s_getval() > 1 do
      if bomber:getDeath((myx - 5 + s_getx()), (myy - 5 + s_gety())) then
	 bomber:getNewObjective()
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
   bomber:setNewObjective(myx + xsave - 5, myy + ysave - 5)
   return (true)
end