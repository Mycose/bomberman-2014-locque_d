//
// bomb_gl2d_mainframe.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects2D
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri Jun  3 11:22:51 2011 pierre le
// Last update Sun Jun  5 14:54:58 2011 nicolas laille
//

#include	"MenuFrame.hh"
#include	"sendData.hh"

#include	"bomb_gl2d_mainframe.hh"

#include	"bomb_gl2d_btnnewgame.hh"
#include	"bomb_gl2d_btnloadgame.hh"
#include	"bomb_gl2d_btnhighscores.hh"
#include	"bomb_gl2d_btnaction.hh"


GlGraphics::MenuMainFrame::MenuMainFrame(const Vector3f &position)
  : MenuFrame(position), _end(false)
{
}


GlGraphics::MenuMainFrame::~MenuMainFrame() {}


void		GlGraphics::MenuMainFrame::initialize(void)
{
  addMenuItemToList(new GlGraphics::NewGameBtn(GlGraphics::Vector3f(this->_position.x,
								    this->_position.y)));
  addMenuItemToList(new GlGraphics::LoadGameBtn(GlGraphics::Vector3f(this->_position.x,
								     this->_position.y + 100)));
  addMenuItemToList(new GlGraphics::HighscoresBtn(GlGraphics::Vector3f(this->_position.x,
								       this->_position.y + 200)));
  addMenuItemToList(new GlGraphics::BtnAction<MenuMainFrame>(GlGraphics::Vector3f(this->_position.x,
										  this->_position.y + 300),
							     GlGraphics::Vector3f(512, 64),
							     &MenuMainFrame::setQuit,
							     *this,
							     gdl::Image::load("./textures/quit_game_flat.png"),
							     gdl::Image::load("./textures/quit_game_highlight_flat.png")));
}

void		GlGraphics::MenuMainFrame::load(sendData&)
{
}

void		GlGraphics::MenuMainFrame::unload(sendData &data)
{
  data.reset();
  data.setLoad(static_cast<eModule>(-1));
}

bool		GlGraphics::MenuMainFrame::isEnd(void) const
{
  return (this->_end);
}

void		GlGraphics::MenuMainFrame::setQuit(void)
{
  this->_end = true;
}
