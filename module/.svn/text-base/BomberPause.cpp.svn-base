//
// BomberPause.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d/module
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Thu Jun  2 17:19:21 2011 nicolas laille
// Last update Sun Jun  5 15:14:18 2011 nicolas laille
//

#include	"BomberPause.hh"
#include	"sendData.hh"

#include	"bomb_gl_engine.hh"
#include	"bomb_gl2d_picturebox.hh"
#include	"bomb_gl2d_btnaction.hh"

BomberPause::BomberPause(void)
  : _objsList(0), _end(false), _over(false)
{
}

BomberPause::~BomberPause(void)
{
  for (std::list<GlGraphics::GlObject *>::iterator it = _objsList.begin();
       it != _objsList.end(); ++it)
    delete *it;
}

void		BomberPause::initialize(sendData&)
{
  // Display background
  this->_objsList.push_back(new GlGraphics::PictureBox(GlGraphics::Vector3f(0, 0),
						       GlGraphics::Vector3f(1280, 800),
						       gdl::Image::load("./textures/Background.png")));

  // Display gray panel
  this->_objsList.push_back(new GlGraphics::PictureBox(GlGraphics::Vector3f(30, 200),
						       GlGraphics::Vector3f(544, 300),
						       gdl::Image::load("./textures/frame_background.png")));

  // Label
  this->_objsList.push_back(new GlGraphics::PictureBox(GlGraphics::Vector3f(46, 216),
						       GlGraphics::Vector3f(512, 64),
						       gdl::Image::load("./textures/gamepaused_flat.png")));

  // Resume button
  this->_objsList.push_back(new GlGraphics::BtnAction<BomberPause>(GlGraphics::Vector3f(46.0f, 320.0f),
								   GlGraphics::Vector3f(512.0f, 64.0f),
								   &BomberPause::setEnd,
								   *this,
								   gdl::Image::load("./textures/resume_btn_flat.png"),
								   gdl::Image::load("./textures/resume_btn_highlight_flat.png")));

  // Quit button
  this->_objsList.push_back(new GlGraphics::BtnAction<BomberPause>(GlGraphics::Vector3f(46.0f, 400.0f),
								   GlGraphics::Vector3f(512.0f, 64.0f),
								   &BomberPause::setOver,
								   *this,
								   gdl::Image::load("./textures/returnmenu_btn_flat.png"),
								   gdl::Image::load("./textures/returnmenu_btn_highlight_flat.png")));

  for (std::list<GlGraphics::GlObject *>::iterator it = _objsList.begin();
       it != _objsList.end(); ++it)
    (*it)->initialize();
}

void		BomberPause::load(void)
{
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0, 1280, 800, 0);

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
}

void		BomberPause::update(const gdl::GameClock &gc, gdl::Input &input)
{
  for (std::list<GlGraphics::GlObject *>::iterator it = _objsList.begin();
       it != _objsList.end(); ++it)
    (*it)->update(gc, input);
}

void		BomberPause::draw(void)
{
  for (std::list<GlGraphics::GlObject *>::iterator it = _objsList.begin();
       it != _objsList.end(); ++it)
    (*it)->draw();
}

void		BomberPause::unload(sendData& data)
{
  data.reset();
  data.setLoad(MENU);
  data.setLoadMenu(GameMenu::FRAME_MAIN);
}

eBomberModule	BomberPause::nextModule(void)
{
  this->_end = false;
  return (B_GAME);
}

bool		BomberPause::isEnd(void) const
{
  return (this->_end);
}

bool		BomberPause::isOver(void) const
{
  return (this->_over);
}


void		BomberPause::setEnd(void)
{
  this->_end = true;
}

void		BomberPause::setOver(void)
{
  this->_over = true;
}
