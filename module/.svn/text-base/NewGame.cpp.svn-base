//
// NewGame.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d/module
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Sat Jun  4 15:55:41 2011 nicolas laille
// Last update Sat Jun  4 20:18:59 2011 nicolas laille
//

#include	<sstream>

#include	"NewGame.hh"
#include	"sendData.hh"

NewGame::NewGame(void)
  : _sizeMap(9), _nbPlayer(2), _versus(false), _tmp(""), _end(false)
{
}

NewGame::~NewGame(void)
{
}

void		NewGame::incMapSize(void)
{
  this->_sizeMap += 2;
  this->_textMap->setText(this->getMapSize());
}

void		NewGame::decMapSize(void)
{
  if (this->_sizeMap > 11)
    this->_sizeMap -= 2;
  this->_textMap->setText(this->getMapSize());
}

void		NewGame::incNbPlayer(void)
{
  if (this->_nbPlayer < (this->_sizeMap / 2))
      this->_nbPlayer++;
  this->_textPlayer->setText(this->getNbPlayer());
}

void		NewGame::decNbPlayer(void)
{
  if (this->_nbPlayer > 2)
    this->_nbPlayer--;
  this->_textPlayer->setText(this->getNbPlayer());
}

void		NewGame::setVersus(void)
{
  this->_versus = !this->_versus;
  this->_textVersus->setText(this->getVersus());
}

void		NewGame::launch(void)
{
  this->_end = true;
}

bool		NewGame::isEnd(void) const
{
  return (this->_end);
}

void		NewGame::getData(sendData& data)
{
  this->_end = false;
  data.reset();
  data.setSizeMap(this->_sizeMap);
  data.setNbPlayer(this->_nbPlayer);
  data.setTwoPlayer(this->_versus);
  data.setLoad(GAME);
}

std::string const &	NewGame::getMapSize(void)
{
  std::stringstream	ss;

  ss << this->_sizeMap;
  this->_tmp = ss.str();
  return (this->_tmp);
}

std::string const &	NewGame::getNbPlayer(void)
{
  std::stringstream	ss;

  ss << this->_nbPlayer;
  this->_tmp = ss.str();
  return (this->_tmp);
}

std::string const &	NewGame::getVersus(void)
{
  std::stringstream	ss;

  if (this->_versus)
    ss << "VS";
  else
    ss << "Solo";
  this->_tmp = ss.str();
  return (this->_tmp);
}

void		NewGame::setTextMap(GlGraphics::TextBoxItem* map)
{
  this->_textMap = map;
}

void		NewGame::setTextPlayer(GlGraphics::TextBoxItem* player)
{
  this->_textPlayer = player;
}

void		NewGame::setTextVersus(GlGraphics::TextBoxItem* versus)
{
  this->_textVersus = versus;
}
