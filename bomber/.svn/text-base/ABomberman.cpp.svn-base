//
// ABomberman.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Thu Apr 28 10:41:54 2011 nicolas laille
// Last update Sun Jun  5 13:26:45 2011 nicolas laille
//

#include	<stdexcept>
#include	<algorithm>

#include	"ABomberman.hh"
#include	"Plant.hh"
#include	"Bombe.hh"
#include	"CheckBombe.hh"
#include	"converter.hpp"
#include	"RandColor.hh"

ABomberman::ABomberman(int x, int y,
		       gdl::Keys::Key up,
		       gdl::Keys::Key down,
		       gdl::Keys::Key right,
		       gdl::Keys::Key left,
		       gdl::Keys::Key plant,
		       GlGraphics::GlObject* object)
  : ACharacter(x, y, 3, up, down, right, left, object),
    moveSpeed(0.03), puiss(1), score(0), nextMove(0), bombes(0),
    _win(false)
{
  this->addAction(plant, &ABomberman::doPlant);
  this->addBombe(new Bombe(*this));
  this->setColor(RandColor::getRandColor());
}

ABomberman::~ABomberman(void)
{
  std::list<ABombe *>::iterator	it;

  for (it = this->bombes.begin(); it != this->bombes.end(); it++)
    delete (*it);
}

int		ABomberman::getPuiss(void) const
{
  return (this->puiss);
}

int		ABomberman::getScore(void) const
{
  return (this->score);
}

void		ABomberman::setPuiss(int puiss)
{
  this->puiss = puiss;
}

void		ABomberman::setWin(void)
{
  this->_win = true;
}

bool		ABomberman::getWin(void) const
{
  return (this->_win);
}

int		ABomberman::getBombX(void) const
{
  if ((this->x % BLOCK_SIZE) <= (BLOCK_SIZE / 2))
    return (this->getX());
  else
    return (this->getX() + 1);
}

int		ABomberman::getBombY(void) const
{
  if ((this->y % BLOCK_SIZE) <= (BLOCK_SIZE / 2))
    return (this->getY());
  else
    return (this->getY() + 1);
}

int		ABomberman::getNbBombMax(void) const
{
  return (this->bombes.size());
}

int		ABomberman::getNbBombDispo(void)
{
  int		res = 0;
  std::list<ABombe *>::iterator	it;

  for (it = this->bombes.begin(); it != this->bombes.end(); it++)
    if (!((*it)->getPlant()))
      res++;
  return (res);
}

void		ABomberman::addBombe(ABombe* bombe)
{

  this->bombes.push_back(bombe);
}

bool		ABomberman::checkPlant()
{
  std::list<ABombe *>::iterator	it;

  for (it = this->bombes.begin(); it != this->bombes.end(); it++)
    {
      if ((*it)->getPlant() && (this->getBombX() == (*it)->getX()
				&& this->getBombY() == (*it)->getY()))
	return (false);
    }
  return (true);
}

void		ABomberman::doPlant(Map& map)
{
  std::list<ABombe *>::iterator	it;

  if (!checkPlant())
    return ;
  for (it = this->bombes.begin(); it != this->bombes.end(); it++)
    {
      if (!(*it)->getPlant())
	{
	  (*it)->doPlant(this->getBombX(), this->getBombY(), this->getPuiss(), map);
	  return ;
	}
    }
}

void		ABomberman::checkBombes(const gdl::GameClock& clock, Map& map)
{
  CheckBombe	check(*this, map, clock);

  std::for_each(this->bombes.begin(), this->bombes.end(), check);
}

void		ABomberman::initBombes(Map& map)
{
  std::list<ABombe *>::iterator	it;

  for (it = this->bombes.begin(); it != this->bombes.end(); it++)
    {
      if ((*it)->getPlant())
	(*it)->setPlant(map);
    }
}

void		ABomberman::addAction(gdl::Keys::Key key, funcAction move)
{
  this->action.insert(std::pair<gdl::Keys::Key, funcAction>(key, move));
}

void		ABomberman::doAction(gdl::Input& input, Map& map)
{
  std::map<gdl::Keys::Key, funcAction>::iterator it;

  for (it = this->action.begin(); it != this->action.end(); it++)
    {
      if (input.isKeyDown((*it).first))
	(this->*(*it).second)(map);
    }
}

void		ABomberman::doAction(int action, Map& map)
{
  std::map<gdl::Keys::Key, funcAction>::iterator it;
  int		i;

  for (i = 0, it = this->action.begin(); it != this->action.end(); it++, i++)
    {
      if (i == action)
	(this->*(*it).second)(map);
    }
}

void		ABomberman::update(const gdl::GameClock& gameClock, gdl::Input& input, Map& map)
{
  this->checkBombes(gameClock, map);
  if (!this->isDead())
    {
      (*map.getElement(this->getX(), this->getY()))(*this, map);
      (*map.getElement(this->getBombX(), this->getY()))(*this, map);
      (*map.getElement(this->getX(), this->getBombY()))(*this, map);
      (*map.getElement(this->getBombX(), this->getBombY()))(*this, map);
      nextMove -= gameClock.getElapsedTime();
      if (nextMove <= 0 && this->update(input, map))
	nextMove = this->moveSpeed;
      reinterpret_cast<ACharacter *>(this)->update(gameClock, input);
    }
}

bool		ABomberman::operator==(ABomberman& bomber)
{
  return ((bomber.getX() == this->getX()) && (bomber.getY() == this->getY()));
}

void		ABomberman::operator+=(int score)
{
  this->score += score;
}

bool		ABomberman::operator!=(ABomberman& bomber)
{
  return (!((*this) == bomber));
}

std::string	ABomberman::SerializeBombs(const std::string& name)
{
  std::list<ABombe *>::iterator	it;
  int		i = 1;
  XMLParser	xml;

  xml.AddElem(name);
  xml.IntoElem();
  xml.AddElem("NbBombs", this->bombes.size());
  for (it = this->bombes.begin() ; it != this->bombes.end() ; ++it)
    {
      std::string str("Bomb" + Convert<int>::convertToType(i));

      xml.AddSubDoc((*it)->Serialize(str));
      ++i;
    }
  xml.OutOfElem();
  return (xml.GetDoc());
}

void		ABomberman::DeserializeBombs(const std::string& doc)
{
  int		i = 1;
  int		nbBombs;
  XMLParser	xml(doc);

  xml.FindElem();
  xml.IntoElem();
  xml.FindElem("NbBombs");
  nbBombs = MCD_STRTOINT(xml.GetData());
  while (i <= nbBombs && xml.FindElem("Bomb" + Convert<int>::convertToType(i)))
    {
      std::string bn("Bomb" + Convert<int>::convertToType(i));
      Bombe	*b = new Bombe(*this);

      b->Deserialize(xml.GetSubDoc());
      this->bombes.push_back(b);
      ++i;
    }
  //this->setColor(RandColor::getRandColor(this->getX(), this->getY(), this->getScore()));
}
