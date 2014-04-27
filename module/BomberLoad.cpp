//
// BomberLoad.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Sat Jun  4 14:04:46 2011 nicolas laille
// Last update Sun Jun  5 16:24:44 2011 nicolas laille
//

#include	"BomberLoad.hh"
#include	"bomb_gl2d_picturebox.hh"
#include	"bomb_gl_engine.hh"

#include	"sendData.hh"

BomberLoad::BomberLoad(void)
  : _objsList(0), _end(false)
{
}

BomberLoad::~BomberLoad(void)
{
  for (std::list<GlGraphics::GlObject *>::iterator it = _objsList.begin();
       it != _objsList.end(); ++it)
    delete *it;
}

void		BomberLoad::initialize(sendData&)
{
  this->_objsList.push_back(new GlGraphics::PictureBox(GlGraphics::Vector3f(0, 0),
						       GlGraphics::Vector3f(1280, 800),
						       gdl::Image::load("./textures/Background.png")));

  this->_objsList.push_back(new GlGraphics::PictureBox(GlGraphics::Vector3f(50, 200),
						       GlGraphics::Vector3f(512, 500),
						       gdl::Image::load("./textures/touches.png")));

  for (std::list<GlGraphics::GlObject *>::iterator it = _objsList.begin();
       it != _objsList.end(); ++it)
    (*it)->initialize(); 
}

void		BomberLoad::load(void)
{
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0, 1280, 800, 0);
  
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
}

void		BomberLoad::update(const gdl::GameClock &gc, gdl::Input &input)
{
  if (input.isKeyDown(gdl::Keys::Return))
    this->_end = true;
  for (std::list<GlGraphics::GlObject *>::iterator it = _objsList.begin();
       it != _objsList.end(); ++it)
    (*it)->update(gc, input);
}

void		BomberLoad::draw(void)
{
  for (std::list<GlGraphics::GlObject *>::iterator it = _objsList.begin();
       it != _objsList.end(); ++it)
    (*it)->draw();
}

void		BomberLoad::unload(sendData&)
{
}

eBomberModule	BomberLoad::nextModule(void)
{
  this->_end = false;
  return (B_GAME);
}

bool		BomberLoad::isEnd(void) const
{
  return (this->_end);
}

bool		BomberLoad::isOver(void) const
{
  return (false);
}
