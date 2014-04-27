--[[
  -- table.lua for  in /home/locque_d//rendu/proj/Bomberman/bomberman-2014-locque_d
  --
  -- Made by damien locque
  -- Login   <locque_d@epitech.net>
  --
  -- Started on  Sun May 29 18:39:48 2011 damien locque
  -- Last update Wed Jul  6 15:51:59 2011 damien locque
]]--

local Width = 11
local Height = 11

function init_tab()
   local tab = {}
   for i = 0,((Width * Height) -1) do
      tab[i] = -1
   end
   return (tab)
end

function getWidth()
   return (Width)
end

function getHeight()
   return (Height)
end

function fill_rec(tab, x, y, inc)
   if x == 10 or y == 10 or x == 0 or y == 0 then
      return (tab)
   end
   if not bomber:getCollision((myx + x - 5) + 1, (myy + y - 5)) and not bomber:getDestructible((myx + x - 5) + 1, (myy + y - 5)) and (inc < tab[(y * Height) + x + 1] or tab[(y * Height) + x + 1] == -1) then
      tab[(y * Height) + x + 1] = inc
      tab = fill_rec(tab, x + 1, y, inc + 1)
   end
   if not bomber:getCollision((myx + x - 5) - 1, (myy + y - 5)) and not bomber:getDestructible((myx + x - 5) - 1, (myy + y - 5)) and (inc < tab[(y * Height) + x - 1] or tab[(y * Height) + x - 1] == -1) then
      tab[(y * Height) + x - 1] = inc
      tab = fill_rec(tab, x - 1, y, inc + 1)
   end
   if not bomber:getCollision((myx + x - 5), (myy + y - 5) + 1) and not bomber:getDestructible((myx + x - 5), (myy + y - 5) + 1) and (inc < tab[((y + 1) * Height) + x] or tab[((y + 1) * Height) + x] == -1) then
      tab[((y + 1) * Height) + x] = inc
      tab = fill_rec(tab, x, y + 1, inc + 1)
   end
   if not bomber:getCollision((myx + x - 5), (myy + y - 5) - 1) and not bomber:getDestructible((myx + x - 5), (myy + y - 5) - 1) and (inc < tab[((y - 1) * Height) + x]  or tab[((y - 1) * Height) + x] == -1) then
      tab[((y - 1) * Height) + x] = inc
      tab = fill_rec(tab, x, y - 1, inc + 1)
   end
   return (tab)
end

function fill_table()
   local tab = init_tab()
   tab[(5 * Height) + 5] = 0
   tab = fill_rec(tab, 5, 5, 1)
   return (tab)
end
