//
// Fire.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Thu May 12 15:48:36 2011 nicolas laille
// Last update Sat Jun  4 19:23:36 2011 nicolas laille
//

#include	"Fire.hh"
#include	"ACharacter.hh"
#include	"ABomberman.hh"

Fire::Fire(ABomberman& bomber, int defX, int defY, int x, int y)
  : ABlock(false, true, false,
	   new GlGraphics::DrawableObj::FireBlock(GlGraphics::Vector3f(0, 0))),
    bomber(bomber), origX(0), origY(0), maxX(0), maxY(0),
    defX(defX), defY(defY), puiss(0)
{
  this->x = x;
  this->y = y;
  this->setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
}

Fire::Fire(const Fire& fire)
  : ABlock(true, true, false,
	   new GlGraphics::DrawableObj::FireBlock(GlGraphics::Vector3f(0, 0))),
    bomber(fire.bomber), origX(fire.origX), origY(fire.origY),
    maxX(fire.maxX), maxY(fire.maxY), defX(fire.defX), defY(fire.defY),
    puiss(fire.puiss)
{
}

Fire::~Fire(void)
{
}


void		Fire::setOrig(int x, int y, int puiss, Map &map)
{
  int		tmp = 0;
  bool		stop = false;
  int		tmp_x;
  int		tmp_y;

  this->origX = x;
  this->origY = y;
  while (puiss-- >= 0 && !stop)
    {
      tmp_x = this->origX + (this->defX * tmp);
      tmp_y = this->origY + (this->defY * tmp);
      if (!map.getElement(tmp_x, tmp_y)->getCrossable() && !map.getElement(tmp_x, tmp_y)->getDestructible())
	return ;
      if (map.getElement(tmp_x, tmp_y)->getDestructible())
	return ;
      map.setMapTableElement(tmp_x, tmp_y, true, DANGEROUS);
      tmp++;
    }
}

void		Fire::explose(int puiss, Map& map)
{
  int		tmp;
  int		tmp_x;
  int		tmp_y;
  bool		stop;

  tmp = 0;
  stop = false;
  this->maxX = this->origX;
  this->maxY = this->origY;
  while (puiss-- >= 0 && !stop)
    {
      tmp_x = this->origX + (this->defX * tmp);
      tmp_y = this->origY + (this->defY * tmp);
      if (!map.getElement(tmp_x, tmp_y)->getCrossable() && !map.getElement(tmp_x, tmp_y)->getDestructible())
	return ;
      this->bomber += map.getElement(tmp_x, tmp_y)->getScore();
      if (map.getElement(tmp_x, tmp_y)->getDestructible()
	  && (tmp_x != this->origX || tmp_y != this->origY))
	if (!(stop = map.getElement(tmp_x, tmp_y)->explose(map)))
	  return ;
      map.setMapTableElement(tmp_x, tmp_y, true, DANGEROUS);
      map.setMapTableElement(tmp_x, tmp_y, true, DEATH);
      map.setElement(tmp_x, tmp_y, new Fire(this->bomber, 0, 0, tmp_x, tmp_y));
      this->maxX = tmp_x;
      this->maxY = tmp_y;
      tmp++;
    }
}

void		Fire::deleteFire(Map& map)
{
  int		tmp;
  int		tmp_x;
  int		tmp_y;
  bool		stop;

  tmp = 0;
  stop = false;
  while (!stop)
    {
      tmp_x = this->origX + (this->defX * tmp);
      tmp_y = this->origY + (this->defY * tmp);
      map.setElement(tmp_x, tmp_y, NULL);
      map.setMapTableElement(tmp_x, tmp_y, false, DANGEROUS);
      map.setMapTableElement(tmp_x, tmp_y, false, DEATH);
      if (tmp_x == this->maxX && tmp_y == this->maxY)
	stop = true;
      tmp++;
    }
}

void		Fire::setFire(Map& map)
{
  int		tmp;
  int		tmp_x;
  int		tmp_y;
  bool		stop;

  tmp = 0;
  stop = false;
  while (!stop)
    {
      tmp_x = this->origX + (this->defX * tmp);
      tmp_y = this->origY + (this->defY * tmp);
      map.setElement(tmp_x, tmp_y, new Fire(this->bomber, 0, 0, tmp_x, tmp_y));
      map.setMapTableElement(tmp_x, tmp_y, true, DANGEROUS);
      map.setMapTableElement(tmp_x, tmp_y, true, DEATH);
      if (tmp_x == this->maxX && tmp_y == this->maxY)
	stop = true;
      tmp++;
    }
}

void		Fire::operator()(ACharacter& character, Map&)
{
  character.setLife(character.getLife() - 1);
}

void		Fire::operator()(ABomberman& character, Map& map)
{
  character.setLife(character.getLife() - 1);
  if (character != this->bomber)
    this->bomber += 10;
  map.setMapTableElement(character.getX(), character.getY(), false, PLAYER);
}

Fire&		Fire::operator=(const Fire& fire)
{
  if (this != &fire)
    {
      this->origX = fire.origX;
      this->origY = fire.origY;
      this->maxX = fire.maxX;
      this->maxY = fire.maxY;
      this->defX = fire.defX;
      this->defY = fire.defY;
      this->puiss = fire.puiss;
    }
  return (*this);
}

ABlock*		Fire::copy(int, int, Map&) const
{
  return (NULL);
}

std::string       Fire::Serialize(const std::string& name)
{
  XMLParser	xml;

  xml.AddElem(name);
  xml.SetAttrib("ClassType", "Fire");
  xml.IntoElem();
  xml.AddElem("ORIGX", this->origX);
  xml.AddElem("ORIGY", this->origY);
  xml.AddElem("MAXX", this->maxX);
  xml.AddElem("MAXY", this->maxY);
  xml.AddElem("DEFX", this->defX);
  xml.AddElem("DEFY", this->defY);
  xml.AddElem("PUISS", this->puiss);
  xml.AddElem("X", this->x);
  xml.AddElem("Y", this->y);
  xml.OutOfElem();
  return (xml.GetDoc());
}

void		Fire::Deserialize(const std::string& doc)
{
  XMLParser	xml(doc);

  xml.FindElem();
  xml.IntoElem();
  xml.FindElem("ORIGX");
  this->origX = MCD_STRTOINT(xml.GetData());
  xml.FindElem("ORIGY");
  this->origY = MCD_STRTOINT(xml.GetData());
  xml.FindElem("MAXX");
  this->maxX = MCD_STRTOINT(xml.GetData());
  xml.FindElem("MAXY");
  this->maxY = MCD_STRTOINT(xml.GetData());
  xml.FindElem("DEFX");
  this->defX = MCD_STRTOINT(xml.GetData());
  xml.FindElem("DEFY");
  this->defY = MCD_STRTOINT(xml.GetData());
  xml.FindElem("PUISS");
  this->puiss = MCD_STRTOINT(xml.GetData());
  xml.FindElem("X");
  this->x = MCD_STRTOINT(xml.GetData());
  xml.FindElem("Y");
  this->y = MCD_STRTOINT(xml.GetData());
  this->_void = MCD_STRTOINT(xml.GetData());
}
