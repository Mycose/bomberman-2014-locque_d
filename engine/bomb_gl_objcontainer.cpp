//
// bomb_gl_objcontainer.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/workshop/engine
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Mon May 16 11:51:53 2011 pierre le
// Last update Thu May 26 11:38:58 2011 nicolas laille
//

#include	<list>

#include	"bomb_gl_object.hh"
#include	"bomb_gl_objcontainer.hh"

void		GlGraphics::GlObjContainer::addStaticObject(Graphic *add)
{
  this->_staticObjs.addToList(add);
}
