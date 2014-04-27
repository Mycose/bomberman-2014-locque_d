//
// bomb_gl_camera.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/workshop/tp
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Wed Apr 27 13:46:34 2011 pierre le
// Last update Sun Jun  5 10:01:09 2011 nicolas laille
//

# include	<iostream>
# include	<GL/gl.h>
# include	<GL/glu.h>

# include	"bomb_gl_engine.hh"
# include	"bomb_gl_object.hh"
# include	"bomb_gl_camera.hh"


GlGraphics::GlCamera::GlCamera(Graphic *bindToObject, GlViewField viewfield)
  : GlObject(Vector3f(0.0f, 0.0f, 900.0f)),
    _focusOn(bindToObject),
    _viewfield(viewfield)
{
}


void		GlGraphics::GlCamera::initialize(void)
{
}


void		GlGraphics::GlCamera::update(gdl::GameClock const &,
					     gdl::Input &)
{
}


void		GlGraphics::GlCamera::draw()
{
  if (this->_viewfield != GLV_SINGLESCR)
    {
      glViewport((this->_viewfield - 1) * (GlEngine::_winX / 2.0), 0,
		 GlEngine::_winX / 2.0, GlEngine::_winY);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluPerspective(70.0f, (GlEngine::_winX / 2.0) / GlEngine::_winY, 1.0f, 10000.0f);
      
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
    }
  else
    {
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluPerspective(70.0f, GlEngine::_winX / GlEngine::_winY, 1.0f, 10000.0f);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
    }
  glFlush();
  this->camLookAt();
}


void		GlGraphics::GlCamera::camLookAt(void)
{
  if (_focusOn == NULL)
    gluLookAt(_position.x + 400.0f, _position.y - 2500.0f, _position.z + 1500.0f,
	      400.0f, 0.0f, 0.0f,
	      0.0f, 1.0f, 0.0f);
  else
    gluLookAt(_focusOn->getPosition().x,
	      _focusOn->getPosition().y - 800.0f,
	      _focusOn->getPosition().z + 2000.0f,

	      _focusOn->getPosition().x,
	      _focusOn->getPosition().y,
	      _focusOn->getPosition().z,

	      0.0f, 1.0f, 0.0f);
}


void		GlGraphics::GlCamera::setFocusObject(Graphic *obj)
{
  _focusOn = obj;
}


void		GlGraphics::GlCamera::setViewField(GlViewField viewfield)
{
  this->_viewfield = viewfield;
}

GlGraphics::GlViewField	GlGraphics::GlCamera::getViewField(void) const
{
  return (this->_viewfield);
}
