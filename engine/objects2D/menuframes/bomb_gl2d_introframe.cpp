//
// bomb_gl2d_introframe.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects2D/menuframes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Sat Jun  4 15:36:42 2011 pierre le
// Last update Sun Jun  5 15:55:39 2011 pierre le
//

#include	"GameMenu.hh"
#include	"MenuFrame.hh"
#include	"sendData.hh"

#include	"bomb_gl2d_introframe.hh"


GlGraphics::MenuIntroFrame::MenuIntroFrame(const GlGraphics::Vector3f& position)
  : MenuFrame(position),
    _pictures(0),
    _currentSlide(0),
    _timeBeforeNext(nextFrame),
    _isSliding(false)
{
}


GlGraphics::MenuIntroFrame::~MenuIntroFrame(void)
{
  for (std::vector<PictureBox*>::iterator it = this->_pictures.begin(); it != this->_pictures.end(); it++)
    delete (*it);
}


void		GlGraphics::MenuIntroFrame::initialize(void)
{
  this->_pictures.push_back(new GlGraphics::PictureBox(GlGraphics::Vector3f(0, 0),
						       GlGraphics::Vector3f(frameWidth, 800),
						       gdl::Image::load("./textures/slide1.png")));
  this->_pictures.push_back(new GlGraphics::PictureBox(GlGraphics::Vector3f(frameWidth, 0),
						       GlGraphics::Vector3f(frameWidth, 800),
						       gdl::Image::load("./textures/slide2.png")));
  this->_pictures.push_back(new GlGraphics::PictureBox(GlGraphics::Vector3f(frameWidth, 0),
						       GlGraphics::Vector3f(frameWidth, 800),
						       gdl::Image::load("./textures/slide3.png")));
  this->_pictures.push_back(new GlGraphics::PictureBox(GlGraphics::Vector3f(frameWidth, 0),
						       GlGraphics::Vector3f(frameWidth, 800),
						       gdl::Image::load("./textures/slide4.png")));
  this->_pictures.push_back(new GlGraphics::PictureBox(GlGraphics::Vector3f(frameWidth, 0),
						       GlGraphics::Vector3f(frameWidth, 800),
						       gdl::Image::load("./textures/slide5.png")));
  for (std::vector<PictureBox*>::iterator it = this->_pictures.begin(); it != this->_pictures.end(); it++)
    (*it)->initialize();
}

void		GlGraphics::MenuIntroFrame::load(sendData&)
{
}

void		GlGraphics::MenuIntroFrame::unload(sendData&)
{
}

void		GlGraphics::MenuIntroFrame::OnFrameUpdate(const gdl::GameClock &clock,
							  gdl::Input &input)
{
  // Countdown
  this->_timeBeforeNext -= clock.getElapsedTime();

  // Trigger
  if (this->_timeBeforeNext <= 0)
    {
      this->_timeBeforeNext = nextFrame;
      if (_currentSlide != this->_pictures.size() - 1)
	_isSliding = true;
    }
  framesSlide();
  if (this->_currentSlide == (this->_pictures.size() - 1) && input.isKeyDown(gdl::Keys::Return))
    GameMenu::_currentFrame = GameMenu::FRAME_MAIN;
}

void		GlGraphics::MenuIntroFrame::OnFrameDraw()
{
  for (std::vector<PictureBox *>::iterator it = _pictures.begin(); it != _pictures.end(); ++it)
    (*it)->draw();
}


bool		GlGraphics::MenuIntroFrame::isEnd(void) const
{
  return (false);
}


void		GlGraphics::MenuIntroFrame::framesSlide(void)
{
  if (_isSliding == false)
    return ;
  PictureBox *	currPict = _pictures[_currentSlide];
  PictureBox *	nextPict = _pictures[_currentSlide + 1];

  if (nextPict->getPosX() != 0)
    {
      currPict->setPosX(currPict->getPosX() - 20);
      nextPict->setPosX(nextPict->getPosX() - 20);
    }
  else
    {
      _isSliding = false;
      _currentSlide++;
    }
}
