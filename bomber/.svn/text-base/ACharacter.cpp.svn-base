//
// ACharacter.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d/bomber
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Thu May 12 11:55:06 2011 nicolas laille
// Last update Sat Jun  4 17:06:30 2011 nicolas laille
//

#include	<stdexcept>

#include	"ACharacter.hh"
#include	"ABlock.hh"
#include	"converter.hpp"

ACharacter::ACharacter(int x, int y, int life,
		       gdl::Keys::Key up,
		       gdl::Keys::Key down,
		       gdl::Keys::Key right,
		       gdl::Keys::Key left,
		       GlGraphics::GlObject* object)
  : Graphic(object),
    x(x * BLOCK_SIZE), y(y * BLOCK_SIZE), life(life), speed(1)
{
  this->addMove(up, &ACharacter::doUp);
  this->addMove(left, &ACharacter::doLeft);
  this->addMove(down, &ACharacter::doDown);
  this->addMove(right, &ACharacter::doRight);
  this->setPosition(this->x, this->y);
}

ACharacter::~ACharacter(void)
{
}

int		ACharacter::getLife(void) const
{
  return (this->life);
}

int		ACharacter::getSpeed(void) const
{
  return (this->speed);
}

bool		ACharacter::isDead(void) const
{
  return (this->life <= 0);
}

bool		ACharacter::view(const ACharacter& character) const
{
  return ((character.getX() >= (this->getX() - this->getViewX())
	   && character.getX() <= (this->getX() + this->getViewX()))
	  && (character.getY() >= (this->getY() - this->getViewY())
	      && character.getY() <= (this->getY() + this->getViewY())));
}

int		ACharacter::getX(void) const
{
  return (this->x / BLOCK_SIZE);
}

int		ACharacter::getY(void) const
{
  return (this->y / BLOCK_SIZE);
}

int		ACharacter::getCheckY(void) const
{
  return (this->getY() + ((this->y % BLOCK_SIZE) ? 1 : 0));
}

int		ACharacter::getCheckX(void) const
{
  return (this->getX() + ((this->x % BLOCK_SIZE) ? 1 : 0));
}

int		ACharacter::getViewX(void) const
{
  return	(6);
}

int		ACharacter::getViewY(void) const
{
  return	(7);
}

void		ACharacter::setLife(int life)
{
  this->life = life;
}

void		ACharacter::setSpeed(int speed)
{
  if (speed <= ((BLOCK_SIZE / MOVE_SIZE) / 2) && speed <= 2)
    {
      this->x = ((this->x / BLOCK_SIZE) * BLOCK_SIZE) + (((this->x % BLOCK_SIZE) / (MOVE_SIZE * speed)) * (MOVE_SIZE * speed));
      this->y = ((this->y / BLOCK_SIZE) * BLOCK_SIZE) + (((this->y % BLOCK_SIZE) / (MOVE_SIZE * speed)) * (MOVE_SIZE * speed));
      this->speed = speed;
    }
}

void		ACharacter::setX(int x)
{
  this->x = x;
}

void		ACharacter::setY(int y)
{
  this->y = y;
}

bool		ACharacter::doSingleRight(const Map& map)
{
  if ((map.getElement(this->getX() + 1, this->getY())->getCrossable()
       && map.getElement(this->getX() + 1, this->getCheckY())->getCrossable())
      || (map.getElement(this->getCheckX() + 1, this->getY())->getCrossable()
	  && map.getElement(this->getCheckX() + 1, this->getCheckY())->getCrossable()))
    {
      this->x += (MOVE_SIZE * this->getSpeed());
      this->setRotation(90);
      return (true);
    }
  return (false);
}

void		ACharacter::doRight(const Map& map)
{
  if (this->doSingleRight(map))
    return ;
  else if (((this->y % BLOCK_SIZE) <= (BLOCK_SIZE / 2))
	   && (map.getElement(this->getX() + 1, this->getY())->getCrossable()))
    this->doSingleUp(map);
  else if (((this->y % BLOCK_SIZE) >= (BLOCK_SIZE / 2))
	   && (map.getElement(this->getX() + 1, this->getY() + 1)->getCrossable()))
    this->doSingleDown(map);
}

bool		ACharacter::doSingleLeft(const Map& map)
{
  if ((map.getElement(this->getCheckX() - 1, this->getY())->getCrossable()
       && map.getElement(this->getCheckX() - 1, this->getCheckY())->getCrossable())
      || (map.getElement(this->getX() - 1, this->getY())->getCrossable()
	  && map.getElement(this->getX() - 1, this->getCheckY())->getCrossable()))
    {
      this->x -= (MOVE_SIZE * this->getSpeed());
      this->setRotation(270);
      return (true);
    }
  return (false);
}

void		ACharacter::doLeft(const Map& map)
{
  if (this->doSingleLeft(map))
    return ;
  else if (((this->y % BLOCK_SIZE) <= (BLOCK_SIZE / 2))
	   && (map.getElement(this->getX() - 1, this->getY())->getCrossable()))
    this->doSingleUp(map);
  else if (((this->y % BLOCK_SIZE) >= (BLOCK_SIZE / 2))
	   && (map.getElement(this->getX() - 1, this->getY() + 1)->getCrossable()))
    this->doSingleDown(map);  
}

bool		ACharacter::doSingleUp(const Map& map)
{
  if ((map.getElement(this->getCheckX(), this->getCheckY() - 1)->getCrossable()
       && map.getElement(this->getX(), this->getCheckY() - 1)->getCrossable())
      || (map.getElement(this->getCheckX(), this->getY() - 1)->getCrossable()
	  && map.getElement(this->getX(), this->getY() - 1)->getCrossable()))
    {
      this->y -= (MOVE_SIZE * this->getSpeed());
      this->setRotation(180);
      return (true);
    }
  return (false);
}

void		ACharacter::doUp(const Map& map)
{
  if (this->doSingleUp(map))
    return ;
  else if (((this->x % BLOCK_SIZE) <= (BLOCK_SIZE / 2))
	   && (map.getElement(this->getX(), this->getY() - 1)->getCrossable()))
    this->doSingleLeft(map);
  else if (((this->x % BLOCK_SIZE) >= (BLOCK_SIZE / 2))
	   && (map.getElement(this->getX() + 1, this->getY() - 1)->getCrossable()))
    this->doSingleRight(map);
}

bool		ACharacter::doSingleDown(const Map& map)
{
  if ((map.getElement(this->getCheckX(), this->getY() + 1)->getCrossable()
       && map.getElement(this->getX(), this->getY() + 1)->getCrossable())
      || (map.getElement(this->getCheckX(), this->getCheckY() + 1)->getCrossable()
	  && map.getElement(this->getX(), this->getCheckY() + 1)->getCrossable()))
    {
      this->y += (MOVE_SIZE * this->getSpeed());
      this->setRotation(0);
      return (true);
    }
  return (false);
}

void		ACharacter::doDown(const Map& map)
{
  if (this->doSingleDown(map))
    return ;
  else if (((this->x % BLOCK_SIZE) <= (BLOCK_SIZE / 2))
	   && (map.getElement(this->getX(), this->getY() + 1)->getCrossable()))
    this->doSingleLeft(map);
  else if (((this->x % BLOCK_SIZE) >= (BLOCK_SIZE / 2))
      && (map.getElement(this->getX() + 1, this->getY() + 1)->getCrossable()))
    this->doSingleRight(map);
}

void		ACharacter::addMove(gdl::Keys::Key i, funcMove move)
{
  this->move.insert(this->move.begin(), std::pair<gdl::Keys::Key, funcMove>(i, move));
}

int		ACharacter::doMove(gdl::Input& input, const Map& map)
{
  std::map<gdl::Keys::Key, funcMove>::iterator it;
  int		tmp;

  for (it = this->move.begin(), tmp = 0; it != this->move.end(); it++)
    {
      if (input.isKeyDown((*it).first))
	{
	  (this->*(*it).second)(map);
	  tmp = 1;
	  break ;
	}
    }
  this->setPosition(this->x, this->y);    
  return (tmp);
}

int		ACharacter::doMove(int move, const Map& map)
{
  std::map<gdl::Keys::Key, funcMove>::iterator it;
  int		tmp;

  for (it = this->move.begin(), tmp = 0; it != this->move.end(); it++)
    {
      if ((*it).first == move)
	{
	  (this->*(*it).second)(map);
	  tmp = 1;
	  break ;
	}
    }
  this->setPosition(this->x, this->y);
  return (tmp);
}
