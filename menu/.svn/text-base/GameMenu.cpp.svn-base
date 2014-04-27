//
// GameMenu.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/menu
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Tue May 31 14:55:57 2011 pierre le
// Last update Sun Jun  5 14:46:43 2011 nicolas laille
//

#include	"bomb_gl_vector3f.hh"
#include	"bomb_gl_engine.hh"

#include	"StrTexture.hh"
#include	"GameMenu.hh"

#include	"bomb_gl2d_picturebox.hh"
#include	"sendData.hh"

GameMenu::eMenuFrameId	GameMenu::_currentFrame = FRAME_MAIN;

// Constructors
GameMenu::GameMenu()
  :_current(NULL)
{
  this->addFrame(FRAME_INTRO, new GlGraphics::MenuIntroFrame(GlGraphics::Vector3f(0, 0)));
  this->addFrame(FRAME_MAIN, new GlGraphics::MenuMainFrame(GlGraphics::Vector3f(50, 200)));
  this->addFrame(FRAME_SCORES, new GlGraphics::MenuScoresFrame(GlGraphics::Vector3f(50, 200)));
  this->addFrame(FRAME_NEWGAME, new GlGraphics::NewGameFrame(GlGraphics::Vector3f(50, 200)));
  this->addFrame(FRAME_LOADGAME, new GlGraphics::LoadGameFrame(GlGraphics::Vector3f(50, 200)));
}


GameMenu::~GameMenu()
{
  // Delete persistant objects list
  for (std::list<GlGraphics::GlObject *>::iterator it = _objsList.begin();
       it != _objsList.end(); ++it)
    delete *it;
  for (std::map<eMenuFrameId, MenuFrame*>::iterator it = _menus.begin();
       it != _menus.end(); ++it)
    delete (*it).second;
}


// Interface functions

void		GameMenu::initialize(sendData& data)
{
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0, 1280, 800, 0);

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  // Initialize char map for StrTexture class
  GlGraphics::StrTexture::_charset = gdl::Image::load("./textures/font.png");
  for (char i = 0; i >= 0; ++i)
    GlGraphics::StrTexture::_charMap[i] =
      std::pair<float, float>((i % 16) * GlGraphics::RATIO_CHARSET,
			      (i / 16) * GlGraphics::RATIO_CHARSET);

  // Background, common to all menu frames displayed in the main menu
  this->_objsList.push_back(new GlGraphics::PictureBox(GlGraphics::Vector3f(0, 0),
						       GlGraphics::Vector3f(1280, 800),
						       gdl::Image::load("./textures/Background.png")));
  this->_objsList.push_back(new GlGraphics::StrTexture(GlGraphics::Vector3f(20, 770),
						       "Copyright(C) 2011 - LAILLE Nicolas, LE Pierre, LOCQUE Damien, MORISSARD Clement", 24, 10));

  // Setup current frame
  GameMenu::_currentFrame = data.getMenuLoad();

  // Initialize objects list
  for (std::list<GlGraphics::GlObject *>::iterator it = _objsList.begin();
       it != _objsList.end(); ++it)
    (*it)->initialize();

  // Initialize frames
  for (std::map<eMenuFrameId, MenuFrame*>::iterator it = _menus.begin();
       it != _menus.end(); ++it)
    ((*it).second)->initialize();
  this->loadFrame(GameMenu::_currentFrame);
  if (this->_current)
    this->_current->load(data);
}


void		GameMenu::update(const gdl::GameClock &gc,
				 gdl::Input &input)
{
  if (input.isKeyDown(gdl::Keys::Escape) == true)
    GameMenu::_currentFrame = FRAME_MAIN;

  // Update objects list
  for (std::list<GlGraphics::GlObject *>::iterator it = _objsList.begin();
       it != _objsList.end(); ++it)
    (*it)->update(gc, input);

  // Update current frame
  this->loadFrame(GameMenu::_currentFrame);
  if (this->_current)
    this->_current->update(gc, input);
}


void		GameMenu::draw(void)
{
  // Draw objects list
  for (std::list<GlGraphics::GlObject *>::iterator it = _objsList.begin();
       it != _objsList.end(); ++it)
    (*it)->draw();

  // Draw current frame
  this->loadFrame(GameMenu::_currentFrame);
  if (this->_current)
    this->_current->draw();
}

void		GameMenu::unload(sendData& data)
{
  this->loadFrame(GameMenu::_currentFrame);
  if (this->_current)
    this->_current->unload(data);
}

bool		GameMenu::isEnd(void)
{
  this->loadFrame(GameMenu::_currentFrame);
  if (this->_current)
    return (this->_current->isEnd());
  return (true);
}

IModule*	GameMenu::copy(void) const
{
  return (new GameMenu());
}

void		GameMenu::loadFrame(eMenuFrameId frame)
{
  static eMenuFrameId lastFrame = static_cast<eMenuFrameId>(-1);

  if (frame != lastFrame)
    {
      if (this->_menus.find(frame) != this->_menus.end())
	{
	  this->_current = this->_menus[frame];
	  lastFrame = frame;
	}
    }
}

void		GameMenu::addFrame(eMenuFrameId frame, MenuFrame *module)
{
  this->_menus.insert(std::pair<eMenuFrameId, MenuFrame *>(frame, module));
}
