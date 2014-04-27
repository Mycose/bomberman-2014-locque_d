//
// bomb_gl2d_newgameframe.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects2D/menuframes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri Jun  3 17:00:30 2011 pierre le
// Last update Sun Jun  5 14:47:39 2011 nicolas laille
//

#include	"GameMenu.hh"
#include	"MenuFrame.hh"
#include	"StrTexture.hh"
#include	"sendData.hh"

#include	"bomb_gl2d_btnback.hh"
#include	"bomb_gl2d_btnaction.hh"
#include	"bomb_gl2d_btnsoloversus.hh"
#include	"bomb_gl2d_btnlaunchgame.hh"
#include	"bomb_gl2d_newgameframe.hh"
#include	"bomb_gl2d_picturebox.hh"
#include	"bomb_gl2d_textboxitem.hh"


GlGraphics::NewGameFrame::NewGameFrame(const Vector3f &position)
  : MenuFrame(position), newGame()
{
}


GlGraphics::NewGameFrame::~NewGameFrame()
{
}


void		GlGraphics::NewGameFrame::initialize(void)
{
  // Frame background
  addMenuItemToList(new GlGraphics::PictureBox(GlGraphics::Vector3f(this->_position.x,
								    this->_position.y),
					       GlGraphics::Vector3f(576, 512),
					       gdl::Image::load("./textures/frame_background.png")));

  // Title
  addMenuItemToList(new GlGraphics::PictureBox(GlGraphics::Vector3f(this->_position.x + 32,
								    this->_position.y + 16),
					       GlGraphics::Vector3f(512, 64),
					       gdl::Image::load("./textures/new_game_flat.png")));

  //
  // MAP SIZE CHANGER
  //

  // Text label -- Map size area
  addMenuItemToList(new GlGraphics::StrTexture(GlGraphics::Vector3f(this->_position.x + 32,
								    this->_position.y + 140),
					       "Map size", 32, 16));
  
  // Text box -- Size of the map
  GlGraphics::TextBoxItem *mapSizeBox =
    reinterpret_cast<GlGraphics::TextBoxItem *>(addMenuItemToList(new GlGraphics::TextBoxItem(GlGraphics::Vector3f(this->_position.x + 300,
														     this->_position.y + 128),
											      GlGraphics::Vector3f(96, 48),
											      "9")));
  this->newGame.setTextMap(mapSizeBox);
  
  // Plus button -- increment textbox
  addMenuItemToList(new GlGraphics::BtnAction<NewGame>(GlGraphics::Vector3f(this->_position.x + 400,
									    this->_position.y + 128),
						       GlGraphics::Vector3f(48, 48),
						       &NewGame::incMapSize,
						       this->newGame,
						       gdl::Image::load("./textures/plus_btn_flat.png"),
						       gdl::Image::load("./textures/plus_btn_highlight_flat.png")));
  
  // Minus button -- increment textbox
  addMenuItemToList(new GlGraphics::BtnAction<NewGame>(GlGraphics::Vector3f(this->_position.x + 450,
									    this->_position.y + 128),
						       GlGraphics::Vector3f(48, 48),
						       &NewGame::decMapSize,
						       this->newGame,
						       gdl::Image::load("./textures/minus_btn_flat.png"),
						       gdl::Image::load("./textures/minus_btn_highlight_flat.png")));


  //
  // PLAYERS NB. CHANGER
  //

  // Text label -- nb players
  addMenuItemToList(new GlGraphics::StrTexture(GlGraphics::Vector3f(this->_position.x + 32,
								    this->_position.y + 200),
					       "Nb. of players", 32, 16));

  GlGraphics::TextBoxItem *nbPlayersBox =
    reinterpret_cast<GlGraphics::TextBoxItem *>(addMenuItemToList(new GlGraphics::TextBoxItem(GlGraphics::Vector3f(this->_position.x + 300,
														   this->_position.y + 196),
											      GlGraphics::Vector3f(96, 48),
											      "2")));
  this->newGame.setTextPlayer(nbPlayersBox);
  // Plus button -- increment textbox
  addMenuItemToList(new GlGraphics::BtnAction<NewGame>(GlGraphics::Vector3f(this->_position.x + 400,
									    this->_position.y + 196),
						       GlGraphics::Vector3f(48, 48),
						       &NewGame::incNbPlayer,
						       this->newGame,
						       gdl::Image::load("./textures/plus_btn_flat.png"),
						       gdl::Image::load("./textures/plus_btn_highlight_flat.png")));


  // Minus button -- increment textbox
  addMenuItemToList(new GlGraphics::BtnAction<NewGame>(GlGraphics::Vector3f(this->_position.x + 450,
									    this->_position.y + 196),
						       GlGraphics::Vector3f(48, 48),
						       &NewGame::decNbPlayer,
						       this->newGame,
						       gdl::Image::load("./textures/minus_btn_flat.png"),
						       gdl::Image::load("./textures/minus_btn_highlight_flat.png")));


  //
  // SELECT NB OF HUMAN PLAYERS
  //

  // Text label -- nb human players
  GlGraphics::TextBoxItem *nbHumansBox =
    reinterpret_cast<GlGraphics::TextBoxItem *>(addMenuItemToList(new GlGraphics::TextBoxItem(GlGraphics::Vector3f(this->_position.x + 32,
														   this->_position.y + 274),
											      GlGraphics::Vector3f(100, 48),
											      "Solo")));
  this->newGame.setTextVersus(nbHumansBox);

  // Solo/versus button -- trigger
  addMenuItemToList(new GlGraphics::BtnAction<NewGame>(GlGraphics::Vector3f(this->_position.x + 148,
									    this->_position.y + 266),
						       GlGraphics::Vector3f(350, 64),
						       &NewGame::setVersus,
						       this->newGame,
						       gdl::Image::load("./textures/player_select_btn_flat.png"),
						       gdl::Image::load("./textures/player_select_btn_highlight_flat.png")));

  //
  // MISC.
  //

  // Launch game button
  addMenuItemToList(new GlGraphics::BtnAction<NewGame>(GlGraphics::Vector3f(this->_position.x + 144,
									    this->_position.y + 400),
						       GlGraphics::Vector3f(256, 64),
						       &NewGame::launch,
						       this->newGame,
						       gdl::Image::load("./textures/launch_game_flat.png"),
						       gdl::Image::load("./textures/launch_game_highlight_flat.png")));

  // Back button
  addMenuItemToList(new GlGraphics::BackBtn(GlGraphics::Vector3f(this->_position.x + 32 + 464,
								 this->_position.y + 490),
					    GameMenu::FRAME_MAIN));
}

void		GlGraphics::NewGameFrame::load(sendData&)
{
}

void		GlGraphics::NewGameFrame::unload(sendData &data)
{
  this->newGame.getData(data);
}


bool		GlGraphics::NewGameFrame::isEnd(void) const
{
  return (this->newGame.isEnd());
}
