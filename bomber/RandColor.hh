//
// RandColor.hh for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d/bomber
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Sat Jun  4 11:19:08 2011 nicolas laille
// Last update Sun Jun  5 13:12:32 2011 nicolas laille
//

#ifndef		__RANDCOLOR_HH__
# define	__RANDCOLOR_HH__

#include	<Color.hpp>

class		RandColor
{
public :
  static gdl::Color	getRandColor(void);

  struct	sColorMap
  {
    char		id;
    unsigned char	r;
    unsigned char	g;
    unsigned char	b;
  };  
};

#endif		/* __RANDCOLOR_HH__ */
