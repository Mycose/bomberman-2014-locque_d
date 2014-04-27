//
// Wall.hh for  in /home/locque_d//rendu/proj/Bomberman/mapgen
//
// Made by damien locque
// Login   <locque_d@epitech.net>
//
// Started on  Mon May  9 15:51:41 2011 damien locque
// Last update Sat Jun  4 15:28:50 2011 nicolas laille
//

#ifndef _WALL_HH_
#define _WALL_HH_

#include	"ABlock.hh"
#include	"Map.hh"
#include	"bomb_gl_drawableobjs.hh"

class		BWall : public ABlock
{
public :
  BWall(int, int);
  virtual ~BWall();

  virtual ABlock*	copy(int, int, Map&) const;
  virtual std::string	Serialize(const std::string& name);
  virtual void		Deserialize(const std::string& doc);
};

#endif /* !_WALL_HH_ */
