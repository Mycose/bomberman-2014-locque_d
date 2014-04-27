//
// BomberMain.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d/module
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Thu Jun  2 17:06:38 2011 nicolas laille
// Last update Sun Jun  5 11:45:09 2011 nicolas laille
//

#include	"BomberMain.hh"
#include	"BomberGame.hh"
#include	"BomberPause.hh"
#include	"BomberLoad.hh"

BomberMain::BomberMain()
  : _current(NULL)
{
  this->addModule(B_GAME, new BomberGame());
  this->addModule(B_PAUSE, new BomberPause());
  this->addModule(B_LOAD, new BomberLoad());
  this->loadModule(B_LOAD);
}

BomberMain::~BomberMain(void)
{
  std::map<eBomberModule, IBomberModule*>::iterator	it;

  for (it = this->_modules.begin(); it != this->_modules.end(); it++)
    delete (*it).second;
}

void		BomberMain::initialize(sendData& data)
{
  std::map<eBomberModule, IBomberModule*>::iterator	it;

  for (it = this->_modules.begin(); it != this->_modules.end(); it++)
    ((*it).second)->initialize(data);
}

void		BomberMain::update(const gdl::GameClock & gameClock, gdl::Input & input)
{
  if (this->_current)
    {
      if (this->_current->isEnd())
	this->loadModule(this->_current->nextModule());
    }
  if (this->_current)
    this->_current->update(gameClock, input);
}

void		BomberMain::draw(void)
{
  if (this->_current)
    this->_current->draw();
}

void		BomberMain::unload(sendData& data)
{
  data.reset();
  if (this->_current)
    this->_current->unload(data);
  data.setLoad(MENU);
}

bool		BomberMain::isEnd(void)
{
  if (this->_current)
    return (this->_current->isOver());
  return (false);
}

IModule*	BomberMain::copy(void) const
{
  return (new BomberMain());
}

void		BomberMain::loadModule(eBomberModule module)
{
  sendData	data;

  if (this->_modules.find(module) != this->_modules.end())
    {
      if (this->_current)
	this->_current->unload(data);
      this->_current = this->_modules[module];
      this->_current->load();
    }
}

void		BomberMain::addModule(eBomberModule num, IBomberModule *module)
{
  this->_modules.insert(std::pair<eBomberModule, IBomberModule *>(num, module));
}
