//
// bomb_gl2d_buttonmenuitem.cpp for Bobmerman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects2D
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri Jun  3 12:02:27 2011 pierre le
// Last update Sat Jun  4 12:33:19 2011 pierre le
//

#include	"GL/gl.h"

#include	"bomb_gl_rendercontext.hh"
#include	"bomb_gl_alphablending.hh"

#include	"bomb_gl2d_buttonmenuitem.hh"


GlGraphics::GlButtonMenuItem::GlButtonMenuItem(const Vector3f &position,
					       const Vector3f &size,
					       const gdl::Image &objImage,
					       const gdl::Image &objImageEntered)
  : GlMenuItem(position, size, objImage), _objImageEntered(objImageEntered),
    _isOverButton(false)
{
}


void		GlGraphics::GlButtonMenuItem::update(const gdl::GameClock &gc,
						     gdl::Input &input)
{
  static bool	lastMouseStateUp = false;

  if (isMouseOverItem(input) == true)
    {
      if (_isOverButton == false)
	{
	  _isOverButton = true;
	  OnMouseEnter();
	}
      if (input.isMouseButtonDown(gdl::Mouse::Left) == true
	  && lastMouseStateUp == false)
	OnMouseClick();
      lastMouseStateUp = input.isMouseButtonDown(gdl::Mouse::Left);
    }
  else
    {
      if (_isOverButton == true)
	{
	  _isOverButton = false;
	  OnMouseLeave();
	}
    }
  OnItemUpdate(gc, input);
}


void		GlGraphics::GlButtonMenuItem::draw(void)
{
  {
    if (_isOverButton == false)
      this->_objImage.bind();
    else
      this->_objImageEntered.bind();
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
  OnItemDraw();
}
