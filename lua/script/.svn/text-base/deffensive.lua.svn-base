--[[
  -- deffensive.lua for  in /home/locque_d//rendu/proj/Bomberman/maybe/bomberman-2014-locque_d
  --
  -- Made by damien locque
  -- Login   <locque_d@epitech.net>
  --
  -- Started on  Sat Jun  4 20:19:05 2011 damien locque
  -- Last update Sat Jun  4 20:19:42 2011 damien locque
]]--

function do_defensive()
   local tab = fill_table()
   s_setx(-1)
   s_sety(-1)
   s_setval(-1)
   for i = 0, (getWidth() * getHeight() - 1) do
      if tab[i] == -1 or tab[i] == 0 then
      elseif (s_getval() == -1 or s_getval() > tab[i]) and not bomber:getDangerous((myx - 5 + (i % getHeight())), (myy - 5 + math.floor(i / (getHeight())))) then
	 s_setx(i % getHeight())
	 s_sety(math.floor(i / getHeight()))
	 s_setval(tab[i])
      end
   end

   if s_getval() == -1 then
      bomber:doMove(UNKNOW)
   else
      while s_getval() > 1 do
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
   end
   if s_getx() - 5 == 0 and 0 > s_gety() - 5 then
      bomber:doMove(UP)
   elseif s_getx() - 5 == 0 then
      bomber:doMove(DOWN)
   elseif s_gety() - 5 == 0 and 0 > s_getx() -5 then
      bomber:doMove(LEFT)
   elseif s_gety() - 5 == 0 then
      bomber:doMove(RIGHT)
   else
      bomber:doMove(UNKNOW)
   end
end
