//
// bomb_gl2d_menuitem.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Tue May 31 16:02:03 2011 pierre le
// Last update Fri Jun  3 17:45:06 2011 pierre le
//

#include	<GL/gl.h>

#include	"Image.hpp"

#include	"bomb_gl_engine.hh"
#include	"bomb_gl_rendercontext.hh"
#include	"bomb_gl_alphablending.hh"
#include	"bomb_gl2d_menuitem.hh"


GlGraphics::GlMenuItem::GlMenuItem(const Vector3f &position,
				   const Vector3f &size,
				   const gdl::Image &objImage)
  : GlObject(position), _objImage(objImage),
    _size(size)
{
  _position.y = -_position.y;
}


void		GlGraphics::GlMenuItem::update(const gdl::GameClock &gc,
					       gdl::Input &input)
{
  static bool	lastMouseStateUp = false;
  static bool	mouseOverItem = false;

  if (isMouseOverItem(input) == true)
    {
      if (mouseOverItem == false)
	{
	  mouseOverItem = true;
	  OnMouseEnter();
	}
      if (input.isMouseButtonDown(gdl::Mouse::Left) == true
	  && lastMouseStateUp == false)
	OnMouseClick();
      lastMouseStateUp = input.isMouseButtonDown(gdl::Mouse::Left);
    }
  else
    {
      if (mouseOverItem == true)
	{
	  mouseOverItem = false;
	  OnMouseLeave();
	}
    }
  OnItemUpdate(gc, input);
}


void		GlGraphics::GlMenuItem::draw(void)
{
  {
    this->_objImage.bind();
    GlAlphaBlending	alphablending;
    GlRenderContext	context(GL_QUADS);

    glTexCoord2d(0, 0);
    glVertex2d(this->_position.x,
	       this->_position.y);

    glTexCoord2d(0, 1);
    glVertex2d(this->_position.x,
	       this->_position.y + this->_size.y);

    glTexCoord2d(1, 1);
    glVertex2d(this->_position.x + this->_size.x,
	       this->_position.y + this->_size.y);

    glTexCoord2d(1, 0);
    glVertex2d(this->_position.x + this->_size.x,
	       this->_position.y);
  }

  // Execute eventually derived OnItemDraw(), for any other object
  // By default (which means if not redefined), this function does nothing.
  OnItemDraw();
}


bool		GlGraphics::GlMenuItem::isMouseOverItem(const gdl::Input &input)
{
  int		mouseX, mouseY;

  mouseX = input.getMousePositionX();
  mouseY = input.getMousePositionY();
  if (mouseX >= this->_position.x && mouseX <= this->_position.x + this->_size.x
      && mouseY >= this->_position.y && mouseY <= this->_position.y + this->_size.y)
    return (true);
  return (false);
}
