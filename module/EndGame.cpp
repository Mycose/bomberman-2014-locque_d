//
// EndGame.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d/module
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Sat Jun  4 17:18:09 2011 nicolas laille
// Last update Sat Jun  4 18:06:48 2011 nicolas laille
//

#include	"EndGame.hh"
#include	"bomb_gl2d_picturebox.hh"
#include	"bomb_gl_engine.hh"

EndGame::EndGame(std::string name)
  : picture(new GlGraphics::PictureBox(GlGraphics::Vector3f(0, 0),
				       GlGraphics::Vector3f(GlEngine::_winX / 2.0, GlEngine::_winY),
				       gdl::Image::load(name)))
{
}

EndGame::~EndGame(void)
{
  delete this->picture;
}

void		EndGame::initialize(void)
{
}

void		EndGame::update(const gdl::GameClock &gc, gdl::Input &input)
{
  this->picture->update(gc, input);
}

void		EndGame::draw(GlGraphics::GlViewField view)
{
  if (view != GlGraphics::GLV_SINGLESCR)
    {
      glViewport((view - 1) * (GlEngine::_winX / 2.0), 0,
		 GlEngine::_winX / 2.0, GlEngine::_winY);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0, (GlEngine::_winX / 2.0), GlEngine::_winY, 0);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
    }
  else
    {
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0, (GlEngine::_winX / 2.0), GlEngine::_winY, 0);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
    }
  glFlush();
  this->picture->draw();
}

void		EndGame::unload(void)
{
}
