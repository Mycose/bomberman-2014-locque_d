//
// bomb_gl_engine.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/workshop/tp
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Wed Apr 27 12:56:51 2011 pierre le
// Last update Sun Jun  5 16:14:45 2011 pierre le
//

#include	<iostream>
#include	<stdexcept>

#include	<cstdlib>
#include	<ctime>

#include	<GL/gl.h>
#include	<GL/glu.h>

#include	<ModelException.hpp>

#include	"bomb_gl_engine.hh"

#include	"GameMenu.hh"
#include	"BomberMain.hh"
#include	"HighScore.hh"
#include	"LoadGame.hh"


GlEngine::GlEngine(const std::string &winTitle)
  : _winTitle(winTitle), current(NULL)
{
  srand(time(0) * getpid());
}


GlEngine::~GlEngine()
{
  for (std::map<eModule, IModule*>::iterator it = this->_modules.begin();
       it != this->_modules.end(); it++)
    delete ((*it).second);
}


void		GlEngine::initialize(void)
{
  try
    {
      sendData	data;

      // Window own settings
      window_.setTitle(this->_winTitle);
      window_.setWidth(this->_winX);
      window_.setHeight(this->_winY);
      window_.create();

      // Initialize objects textures
      GlGraphics::GlTexturedObj::putTexture(B_SOLID_WALL,
					    gdl::Image::load("./textures/cobblestone.bmp"));
      GlGraphics::GlTexturedObj::putTexture(B_BREAKABLE_WALL,
					    gdl::Image::load("./textures/weak_wall.bmp"));
      GlGraphics::GlTexturedObj::putTexture(B_GROUND,
					    gdl::Image::load("./textures/grass.bmp"));
      GlGraphics::GlTexturedObj::putTexture(B_FIRE,
					    gdl::Image::load("./textures/fire.bmp"));
      GlGraphics::GlTexturedObj::putTexture(B_BONUS_BOMB,
					    gdl::Image::load("./textures/Bombe.png"));
      GlGraphics::GlTexturedObj::putTexture(B_BONUS_POWERUP,
					    gdl::Image::load("./textures/Fire-1.png"));
      GlGraphics::GlTexturedObj::putTexture(B_BONUS_SPEED,
					    gdl::Image::load("./textures/flying_shoe.png"));

      // Initialize objects 3D models
      GlGraphics::GlModelObj::putModel(B_CHARACTER,
				       gdl::Model::load("./models/marvinLowLowPo.fbx"));
      GlGraphics::GlModelObj::putModel(B_BOMB,
				       gdl::Model::load("./models/bomb.fbx"));

      // Module loader
      data.reset();
      this->addModule(GAME, new BomberMain());
      this->addModule(MENU, new GameMenu());
      this->loadModule(MENU, data);
    }
  catch (std::exception e)
    {
      std::cerr << e.what() << std::endl;
      this->window_.close();
    }
  catch (std::invalid_argument* e)
    {
      std::cerr << e->what() << std::endl;
      this->window_.close();
    }
  catch (gdl::ModelException* e)
    {
      std::cerr << e->what() << std::endl;
      this->window_.close();
    }
}


void		GlEngine::update(void)
{
  try
    {
      sendData	data;

      if (!this->current->isEnd())
	this->current->update(gameClock_, input_);
      else
	{
	  this->current->unload(data);
	  if (data.getModuleLoad() == static_cast<eModule>(-1))
	    this->window_.close();
	  else
	    this->loadModule(data.getModuleLoad(), data);
	}
    }
  catch (const std::exception &e)
    {
      std::cerr << "Bomberman has encountered an error and must be closed: ";
      std::cerr << e.what() << std::endl;
      this->window_.close();
    }
  catch (gdl::ModelException* e)
    {
      std::cerr << e->what() << std::endl;
      this->window_.close();
    }
  catch (std::invalid_argument* e)
    {
      std::cerr << e->what() << std::endl;
      this->window_.close();
    }
}


void		GlEngine::draw(void)
{
  try
    {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
      glClearDepth(1.0f);
      this->current->draw();
      this->window_.display();
    }
  catch (std::exception e)
    {
      std::cerr << e.what() << std::endl;
      this->window_.close();
    }
  catch (gdl::ModelException* e)
    {
      std::cerr << e->what() << std::endl;
      this->window_.close();
    }
  catch (std::invalid_argument* e)
    {
      std::cerr << e->what() << std::endl;
      this->window_.close();
    }
}


void		GlEngine::unload(void)
{
  sendData	data;

  if (this->current)
    this->current->unload(data);
}

void		GlEngine::loadModule(eModule module, sendData& data)
{
  if (this->_modules.find(module) != this->_modules.end())
    {
      if (this->current)
	{
	  this->current->unload(data);
	  delete (this->current);
	}
      this->current = this->_modules[module]->copy();
      this->current->initialize(data);
    }
}

void		GlEngine::addModule(eModule num, IModule *module)
{
  this->_modules.insert(std::pair<eModule, IModule *>(num, module));
}
