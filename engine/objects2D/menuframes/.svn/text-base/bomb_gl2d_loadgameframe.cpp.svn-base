//
// bomb_gl2d_loadgameframe.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects2D/menuframes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Sat Jun  4 10:51:28 2011 pierre le
// Last update Sun Jun  5 16:28:18 2011 nicolas laille
//

#include	"GameMenu.hh"
#include	"MenuFrame.hh"
#include	"StrTexture.hh"

#include	"bomb_gl2d_btnback.hh"
#include	"bomb_gl2d_btnaction.hh"
#include	"bomb_gl2d_btnlaunchgame.hh"
#include	"bomb_gl2d_btnpushaction.hh"
#include	"bomb_gl2d_loadgameframe.hh"
#include	"bomb_gl2d_picturebox.hh"
#include	"bomb_gl2d_textboxitem.hh"

#include	"sendData.hh"

GlGraphics::LoadGameFrame::LoadGameFrame(const Vector3f &position)
  : MenuFrame(position), loadGame()
{
}


GlGraphics::LoadGameFrame::~LoadGameFrame() {}


void		GlGraphics::LoadGameFrame::initialize(void)
{
  // Frame background
  addMenuItemToList(new GlGraphics::PictureBox(GlGraphics::Vector3f(this->_position.x,
								    this->_position.y),
					       GlGraphics::Vector3f(576, 512),
					       gdl::Image::load("./textures/frame_background.png")));

  // Load slots list
  for (size_t i = 0; i < 5; ++i)
    {
      addMenuItemToList(new GlGraphics::PushActionBtn<LoadGame>(GlGraphics::Vector3f(this->_position.x + 32,
										     this->_position.y + 96 + 80 * i),
								GlGraphics::Vector3f(512, 64),
								(!this->loadGame.End() ? this->loadGame.getNextSave() : "[Empty slot]"),
								(!this->loadGame.End() ? &LoadGame::buttonCall : NULL),
								this->loadGame,
								gdl::Image::load("./textures/text_box_flat.png"),
								gdl::Image::load("./textures/text_box_highlight_flat.png")));
    }

  // Title
  addMenuItemToList(new GlGraphics::PictureBox(GlGraphics::Vector3f(this->_position.x + 32,
								    this->_position.y + 16),
					       GlGraphics::Vector3f(512, 64),
					       gdl::Image::load("./textures/load_game_flat.png")));

  // Back button
  addMenuItemToList(new GlGraphics::BackBtn(GlGraphics::Vector3f(this->_position.x + 32 + 464,
								 this->_position.y + 490),
					    GameMenu::FRAME_MAIN));
}


void		GlGraphics::LoadGameFrame::load(sendData&)
{
}

void		GlGraphics::LoadGameFrame::unload(sendData &data)
{
  data.reset();
  data.setSaveName(this->loadGame.getSave());
  data.setLoad(GAME);
}


bool		GlGraphics::LoadGameFrame::isEnd(void) const
{
  return (this->loadGame.isEnd());
}
