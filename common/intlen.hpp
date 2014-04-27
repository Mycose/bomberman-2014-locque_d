//
// intlen.hpp for bomberman in /home/moriss_c//projs/Bomberman/bomberman-2014-locque_d/save
// 
// Made by clement morissard
// Login   <moriss_c@epitech.net>
// 
// Started on  Mon May 30 15:16:02 2011 clement morissard
// Last update Wed Jun  1 14:58:22 2011 clement morissard
//

#ifndef __LENGTH_HPP__
# define __LENGTH_HPP__

#include <sstream>

class	Length
{
public:
  static int	intLen(int nb)
  {
    std::stringstream	ss;

    ss << nb;
    return (ss.str().size());
  }
};

#endif // __LENGTH_HPP__
