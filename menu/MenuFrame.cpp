//
// MenuFrame.cpp for Bobmerman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/menu
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri Jun  3 10:25:48 2011 pierre le
// Last update Sat Jun  4 15:41:58 2011 pierre le
//

#include	"bomb_gl_object.hh"

#include	"MenuFrame.hh"


MenuFrame::MenuFrame(const GlGraphics::Vector3f &position)
  : GlGraphics::GlObject(position)
{
  _position.y = -_position.y;
}


MenuFrame::~MenuFrame(void)
{
  for (std::list<GlObject *>::iterator it = _menuContents.begin(); it != _menuContents.end(); ++it)
    delete *it;
}


void		MenuFrame::update(const gdl::GameClock &gc,
				  gdl::Input &input)
{
  // Update all objects
  for (std::list<GlObject *>::iterator it = _menuContents.begin(); it != _menuContents.end(); ++it)
    (*it)->update(gc, input);
  OnFrameUpdate(gc, input);
}


void		MenuFrame::draw(void)
{
  // Draw all objects
  for (std::list<GlObject *>::iterator it = _menuContents.begin(); it != _menuContents.end(); ++it)
    (*it)->draw();
  OnFrameDraw();
}


void		MenuFrame::OnFrameUpdate(const gdl::GameClock &,
					 gdl::Input &) {}


void		MenuFrame::OnFrameDraw() {}


GlGraphics::GlObject	*MenuFrame::addMenuItemToList(GlObject *obj)
{
  this->_menuContents.push_back(obj);
  return (obj);
}
