//
// sendData.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Sat Jun  4 12:32:23 2011 nicolas laille
// Last update Sun Jun  5 14:43:28 2011 nicolas laille
//

#include	<sstream>

#include	"sendData.hh"

sendData::sendData()
  : sizeMap(0), nbPlayer(0), twoPlayer(false),
    saveName(""), score(0), player(""),
    load(MENU), loadmenu(GameMenu::FRAME_INTRO)
{
}
 
sendData::~sendData()
{
}

unsigned int	sendData::getSizeMap(void) const
{
  return (this->sizeMap);
}

unsigned int	sendData::getNbPlayer(void) const
{
  return (this->nbPlayer);
}

bool		sendData::getTwoPlayer(void) const
{
  return (this->twoPlayer);
}

std::string const&	sendData::getSaveName(void) const
{
  return (this->saveName);
}

int		sendData::getScore(void) const
{
  return (this->score);
}

eModule		sendData::getModuleLoad(void) const
{
  return (this->load);
}

GameMenu::eMenuFrameId	sendData::getMenuLoad(void) const
{
  return (this->loadmenu);
}

std::string const&	sendData::getPlayerScore(void) const
{
  return (this->player);
}

void		sendData::setSizeMap(unsigned int size)
{
  this->sizeMap = size;
}

void		sendData::setNbPlayer(unsigned int nb)
{
  this->nbPlayer = nb;
}

void		sendData::setTwoPlayer(bool two)
{
  this->twoPlayer = two;
}

void		sendData::setSaveName(std::string const& name)
{
  this->saveName = name;
}

void		sendData::setScore(unsigned int score)
{
  this->score = score;
}

void		sendData::setLoad(eModule module)
{
  this->load = module;
}
  
void		sendData::setLoadMenu(GameMenu::eMenuFrameId frame)
{
  this->loadmenu = frame;
}

void		sendData::setPlayerScore(int player)
{
  std::stringstream	ss;

  ss << "PL";
  ss << player;
  this->player = ss.str();
}

void		sendData::reset(void)
{
  this->sizeMap = 0;
  this->nbPlayer = 0;
  this->twoPlayer = false;
  this->saveName = "";
  this->score = 0;
  this->load = MENU;
  this->loadmenu = GameMenu::FRAME_INTRO;
}
