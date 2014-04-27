//
// TMap.cpp for  in /home/locque_d//rendu/proj/Bomberman
//
// Made by damien locque
// Login   <locque_d@epitech.net>
//
// Started on  Mon May 23 16:36:03 2011 damien locque
// Last update Fri Jun  3 17:49:52 2011 nicolas laille
//

#include <iostream>
#include "TMap.hh"

TMap::TMap()
{
}

TMap::~TMap()
{
}

void TMap::create(int width, int height)
{
  char c = 0;
  this->_map = "";
  this->_width = width;
  this->_height = height;
  for (int y = 0 ; y < height ; y++)
    for (int x = 0 ; x < width ; x++)
      this->_map += c;
}

bool TMap::getxy(int x, int y, maptype type) const
{
  return (this->_map[(y * this->_height) + x] & type);
}

void TMap::setxy(int x, int y, bool val, maptype type)
{
  if (val == this->getxy(x, y, type))
    return;
  if (val)
    this->_map[(y * this->_height) + x] |= type;
  else
    this->_map[(y * this->_height) + x] ^= type;
}
