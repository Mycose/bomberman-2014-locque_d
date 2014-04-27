//
// bomb_gl_graphic.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d/engine
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Tue May 24 13:32:04 2011 nicolas laille
// Last update Sat Jun  4 11:10:09 2011 nicolas laille
//

#include	"bomb_gl_graphic.hh"

GlGraphics::Graphic::Graphic(GlGraphics::GlObject* object)
  : object(object)
{
}

GlGraphics::Graphic::~Graphic()
{
  if (this->object)
    delete this->object;
}

void		GlGraphics::Graphic::initialize(void)
{
  if (this->object)
    this->object->initialize();
}

void		GlGraphics::Graphic::update(const gdl::GameClock& gameClock, gdl::Input& input)
{
  if (this->object)
    this->object->update(gameClock, input);
}

void		GlGraphics::Graphic::draw(void)
{
  if (this->object)
    this->object->draw();
}

void		GlGraphics::Graphic::setPosition(const Vector3f &position)
{
  this->object->setPosition(position);
}

void		GlGraphics::Graphic::setPosition(int x, int y)
{
  this->object->setPosition(x, y);
}

const GlGraphics::Vector3f	GlGraphics::Graphic::getPosition(void) const
{
  return (this->object->getPosition());
}

void		GlGraphics::Graphic::setRotation(float rotation)
{
  this->object->setRotation(rotation);
}

float		GlGraphics::Graphic::getRotation(void) const
{
  return (this->object->getRotation());
}

void		GlGraphics::Graphic::setColor(const gdl::Color& color)
{
  if (this->object)
    this->object->setColor(color);
}
