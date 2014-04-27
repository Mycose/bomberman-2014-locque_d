//
// bomb_gl_displist.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/workshop/engine/includes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri May 13 10:43:24 2011 pierre le
// Last update Thu May 26 11:38:38 2011 nicolas laille
//

#include	<GL/gl.h>

#include	<stdexcept>

#include	"bomb_gl_vector3f.hh"
#include	"bomb_gl_displist.hh"


GlGraphics::GlDispList::GlDispList()
  : GlObject(Vector3f()), _dispList(0), _isListClosed(false)
{
}


GlGraphics::GlDispList::~GlDispList()
{
  glDeleteLists(this->_dispList, 1);
}


void		GlGraphics::GlDispList::update(const gdl::GameClock &clock,
					       gdl::Input &input)
{
  std::list<Graphic *>::iterator	it;

  for (it = this->_objsList.begin(); it != this->_objsList.end(); ++it)
    (*it)->update(clock, input);
}


void		GlGraphics::GlDispList::draw(void)
{
  if (this->_isListClosed == false)
    this->listPrepare();
  glCallList(this->_dispList);
}


void		GlGraphics::GlDispList::addToList(Graphic *obj)
{
  if (this->_isListClosed == true)
    throw std::runtime_error("GlDispList::addToList: attempt to add an object to a closed list.");
  this->_objsList.push_back(obj);
}


void		GlGraphics::GlDispList::listPrepare(void)
{
  std::list<Graphic *>::iterator	it;

  // Initialize display list
  if (this->_objsList.size() == 0)
    throw std::invalid_argument("GlDispList::constructor: no object in list.");
  if ((_dispList = glGenLists(this->_objsList.size())) == 0)
    throw std::runtime_error("GlDispList::constructor: error while generating list.");

  // Fill list
  glNewList(this->_dispList, GL_COMPILE);
  for (it = this->_objsList.begin(); it != this->_objsList.end(); ++it)
    (*it)->draw();
  glEndList();
  this->_isListClosed = true;
}
