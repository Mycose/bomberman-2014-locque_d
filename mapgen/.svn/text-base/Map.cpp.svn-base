//
// Map.cpp for  in /home/locque_d//rendu/proj/Bomberman/mapgen
//
// Made by damien locque
// Login   <locque_d@epitech.net>
//
// Started on  Tue May  3 16:09:34 2011 damien locque
// Last update Sun Jun  5 13:50:05 2011 nicolas laille
//

#include	<stdexcept>

#include	<cmath>
#include	"Map.hh"

#include	"BonusSpeed.hh"
#include	"BonusBomb.hh"
#include	"BonusPuiss.hh"
#include	"converter.hpp"
#include	"Wall.hh"
#include	"Box.hh"
#include	"Void.hh"

#include	"ABomberman.hh"

Map::Map() :
  _width(0), _height(0), _map(0), _voidclass(new BVoid(0, 0))
{
  this->_deseri.insert(std::pair<std::string, ABlock*>("Box", new Box(0, 0)));
  this->_deseri.insert(std::pair<std::string, ABlock*>("BonusSpeed", new BonusSpeed(0, 0)));
  this->_deseri.insert(std::pair<std::string, ABlock*>("BonusBomb", new BonusBomb(0, 0)));
  this->_deseri.insert(std::pair<std::string, ABlock*>("BonusPuiss", new BonusPuiss(0, 0)));
  this->_deseri.insert(std::pair<std::string, ABlock*>("BVoid", new BVoid(0, 0)));
  this->_deseri.insert(std::pair<std::string, ABlock*>("Fire", new BVoid(0, 0)));
  this->_deseri.insert(std::pair<std::string, ABlock*>("BWall", new BWall(0, 0)));
}

Map::~Map()
{
  std::map<std::string, ABlock*>::iterator	it;

  for (int y = 0 ; y < this->_height ; y++)
    for (int x = 0 ; x < this->_width ; x++)
      if (this->_map[y * this->_height + x]
	  && this->_map[y * this->_height + x] != NULL)
	delete this->_map[y * this->_height + x];
  delete this->_voidclass;
  for (it = this->_deseri.begin(); it != this->_deseri.end(); it++)
    delete (*it).second;
  this->_deseri.clear();
}

void		Map::create(int width, int height, int nbPlayer, Playerpos& playerpos)
{
  ABlock	*block;

  this->_width = width;
  this->_height = height;
  this->_nbPlayer = nbPlayer;
  this->_maptable.create(width, height);
  for (int y = 0 ; y < height ; y++)
    {
      for (int x = 0 ; x < width ; x++)
	{
	  block = NULL;
	  if ((x == 0 || y == 0 || (x + 1) == width || (y + 1) == height)
	      || ((((x % 2) == 0) && ((y % 2) == 0))
		  && x + 1 != (width -1) && y + 1 != (height -1)))
	    {
	      block = new BWall(x, y);
	      this->setMapTableElement(x, y, true, COLLISION);
	    }
	  this->_map.push_back(block);
	}
    }
  this->alea_box();
  this->set_player_positions(playerpos);
}

int		Map::getWidth() const
{
  return (this->_width);
}

int		Map::getHeight() const
{
  return (this->_height);
}

ABlock*		Map::getElement(int x, int y) const
{
  if (this->_map[(y * this->_height) + x] == NULL)
    return (this->_voidclass);
  return (this->_map[(y * this->_height) + x]);
}

bool		Map::getMapTableElement(int x, int y, maptype type) const
{
  return (this->_maptable.getxy(x, y, type));
}

void		Map::setMapTableElement(int x, int y, bool val, maptype type)
{
  this->_maptable.setxy(x, y, val, type);
}

void		Map::setElement(int x, int y, ABlock *elt)
{
  if (this->_map[(y * this->_height) + x] != NULL)
    delete this->_map[(y * this->_height) + x];
  this->_map[(y * this->_height) + x] = elt;
}

// Private

void		Map::alea_box()
{
  for (int i = 0 ; i < (this->_width * this->_height) ; i++)
    {
      int y = i % this->_width;
      int x = i / this->_width;

      if (((rand() % 4) >= 1) && this->getElement(x, y)->isVoid())
	{
	  this->setElement(x, y, new Box(x, y));
	  this->setMapTableElement(x, y, true, DESTRUCT);
	}
    }
}

bool		Map::put_player(int x, int y, Playerpos& players)
{
  int			stop = 3;
  if ((this->getElement(x, y)->getDestructible() || this->getElement(x, y)->isVoid()) && stop--)
    {
      this->setElement(x, y, NULL);
      this->setMapTableElement(x, y, false, DESTRUCT);
      players.addposition(x, y);
    }
  else
    return (false);
  if ((this->getElement(x + 1, y)->getDestructible() || this->getElement(x + 1, y)->isVoid()) && stop--)
    {
      this->setElement(x + 1, y, NULL);
      this->setMapTableElement(x + 1, y, false, DESTRUCT);
    }
  if ((this->getElement(x, y + 1)->getDestructible() || this->getElement(x, y + 1)->isVoid()) && stop--)
    {
      this->setElement(x, y + 1, NULL);
      this->setMapTableElement(x, y + 1, false, DESTRUCT);
    }
  if (stop > 0 && (this->getElement(x - 1, y)->getDestructible() || this->getElement(x - 1, y)->isVoid()) && stop--)
    {
      this->setElement(x - 1, y, NULL);
      this->setMapTableElement(x - 1, y, false, DESTRUCT);
    }
  if (stop > 0 && (this->getElement(x, y - 1)->getDestructible() || this->getElement(x, y - 1)->isVoid()))
    {
      this->setElement(x, y - 1, NULL);
      this->setMapTableElement(x, y - 1, false, DESTRUCT);
    }
  return (true);
}

bool		Map::set_player_positions(Playerpos& players)
{
  int		tmp;
  int		pair;
  int		nbPlayer;
  int		divw;
  int		divh;

  nbPlayer = 0;
  tmp = sqrt(this->_nbPlayer);
  tmp = ((tmp == 0) ? 1 : tmp);
  pair = (this->_nbPlayer % 2);
  if (tmp > 1 && !pair)
    {
      divw = (this->_width - 3) / (tmp - 1);
      divh = (this->_height - 3) / (this->_nbPlayer / tmp);
    }
  else if (tmp > 1)
    {
      divw = (this->_width - 3) / tmp;
      divh = (this->_height - 3) / (this->_nbPlayer / tmp);
    }
  else
    {
      divw = (this->_width - 3) / tmp;
      divh = (this->_height - 3) / tmp;
    }
  for (int x = 1 ; x <= this->_width && nbPlayer < this->_nbPlayer; x += divw)
    for (int y = 1 ; y <= this->_height && nbPlayer < this->_nbPlayer; y += divh)
      {
	if (this->put_player(x, y, players))
	  nbPlayer++;
      }
  return (true);
}


void			Map::initialize(void)
{
  std::vector<ABlock *>::iterator	it;

  for (it = this->_map.begin(); it != this->_map.end(); it++)
    {
      if ((*it) && ((*it)->getDestructible() || (*it)->getCrossable()))
	(*it)->initialize();
    }
}

void			Map::update(ABomberman& bomber, const gdl::GameClock &gameClock_, gdl::Input &input_)
{
  ABlock*		tmp;
  int			x;
  int			tmpx;
  int			y;

  tmpx = (bomber.getX() - bomber.getViewX());
  tmpx = ((tmpx >= 0) ? tmpx : 0);
  y = (bomber.getY() - bomber.getViewY());
  y = ((y >= 0) ? y : 0);
  for (;y <= (bomber.getY() + bomber.getViewY()) && y < this->_height; y++)
    {
      for (x = tmpx;x <= (bomber.getX() + bomber.getViewX()) && x < this->_width; x++)
	{
	  tmp = this->getElement(x, y);
	  if (tmp->getDestructible() || tmp->getCrossable())
	    tmp->update(gameClock_, input_);
	}
    }
}

void			Map::draw(ABomberman& bomber)
{
  ABlock*		tmp;
  int			x;
  int			tmpx;
  int			y;

  tmpx = (bomber.getX() - bomber.getViewX());
  tmpx = (tmpx >= 0) ? tmpx : 0;
  y = (bomber.getY() - bomber.getViewY());
  y = (y >= 0) ? y : 0;
  for (;y <= (bomber.getY() + bomber.getViewY()) && y < this->_height; y++)
    {
      for (x = tmpx;x <= (bomber.getX() + bomber.getViewX()) && x < this->_width; x++)
	{
	  tmp = this->getElement(x, y);
	  if (tmp->getDestructible() || tmp->getCrossable())
	    tmp->draw();
	}
    }
}

void			Map::unload(void)
{
}

std::string		Map::SerializeBlocks(const std::string& name)
{
  std::vector<ABlock *>::iterator	it;
  XMLParser			xml;
  unsigned int			i = 1;

  xml.AddElem(name);
  xml.IntoElem();
  for (it = this->_map.begin(); it != this->_map.end(); it++, i++)
    {
      std::string	str("Block" + Convert<unsigned int>::convertToType(i));

      if ((*it) != NULL)
	xml.AddSubDoc((*it)->Serialize(str));
      else
	xml.AddSubDoc(this->_voidclass->Serialize(str));
    }
  xml.OutOfElem();
  return (xml.GetDoc());
}

void			Map::DeserializeBlocks(const std::string& doc)
{
  std::string		str;
  XMLParser		xml(doc);
  int			i = 1;
  int			x;
  int			y;
  int			nbBlock;

  xml.FindElem();
  xml.IntoElem();
  nbBlock = this->_width * this->_height;
  while (i <= nbBlock && xml.FindElem("Block" + Convert<int>::convertToType(i)))
    {
      std::string	type;
      ABlock*		tmp;

      str = xml.GetSubDoc();
      x = (i - 1) % this->_width;
      y = (i - 1)/ this->_height;
      type = xml.GetAttrib("ClassType");
      if (this->_deseri.find(type) != this->_deseri.end())
	{
	  tmp = (this->_deseri[type])->copy(x, y, *this);
	  tmp->Deserialize(str);
	  this->_map.push_back(tmp);	  
	}
      else
	throw std::runtime_error("Classtype unknown, save corrupted");
	++i;
    }
}


std::string			Map::Serialize(const std::string& name)
{
  std::string	str;
  XMLParser	xml;

  xml.AddElem(name);
  xml.IntoElem();
  xml.AddElem("WIDTH", this->_width);
  xml.AddElem("HEIGHT", this->_height);
  xml.AddElem("NBPLAYER", this->_nbPlayer);
  xml.AddSubDoc(this->SerializeBlocks("BlockList"));
  xml.OutOfElem();
  return (xml.GetDoc());
}

void				Map::Deserialize(const std::string& doc)
{
  XMLParser	xml(doc);

  xml.FindElem();
  xml.IntoElem();
  xml.FindElem("WIDTH");
  this->_width = MCD_STRTOINT(xml.GetData());
  xml.FindElem("HEIGHT");
  this->_height = MCD_STRTOINT(xml.GetData());
  this->_maptable.create(this->_width, this->_height);
  xml.FindElem("NBPLAYER");
  this->_nbPlayer = MCD_STRTOINT(xml.GetData());
  xml.FindElem("BlockList");
  this->DeserializeBlocks(xml.GetSubDoc());
}
