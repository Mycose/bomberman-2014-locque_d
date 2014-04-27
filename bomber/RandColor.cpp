//
// RandColor.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d/bomber
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Sat Jun  4 11:23:46 2011 nicolas laille
// Last update Sun Jun  5 13:12:23 2011 nicolas laille
//

#include	<unistd.h>
#include	<cstdlib>

#include	"RandColor.hh"

static RandColor::sColorMap	colorseed[] =
  {
    {1, 255, 0, 0},
    {2, 0, 255, 0},
    {3, 0, 0, 255},
    {4, 255, 255, 0},
    {5, 255, 0, 255},
    {6, 0, 255, 255},
    {7, 255, 255, 255}
  };

gdl::Color	RandColor::getRandColor()
{
  static unsigned int	id = 1;
  gdl::Color	color(0, 0, 0);
  size_t	divisor;
  sColorMap	temp;

  id++;
  divisor = sizeof(colorseed) / sizeof(*colorseed);
  temp = colorseed[id / divisor + id % divisor - 1];
  color.r = temp.r;
  color.g = temp.g;
  color.b = temp.b;
  if ((size_t)id > divisor)
    {
      color.r += (!color.r ? 1 : -1) * (id - divisor) * 15;
      color.g += (!color.g ? 1 : -1) * (id - divisor) * 15;
      color.b += (!color.b ? 1 : -1) * (id - divisor) * 15;
    }
  return (color);
}
