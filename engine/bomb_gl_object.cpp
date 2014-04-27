//
// bomb_gl_object.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/workshop/engine
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri Apr 29 10:44:51 2011 pierre le
// Last update Sun Jun  5 13:29:31 2011 nicolas laille
//

#include	"bomb_gl_object.hh"


//
// Basic GlObject
//

GlGraphics::GlObject::GlObject(const Vector3f &position)
  : _rotation(0.0f)
{
  _position.x = position.x;
  _position.y = -position.y;
  _position.z = position.z;
}


void				GlGraphics::GlObject::setPosition(const Vector3f &position)
{
  _position.x = position.x;
  _position.y = -position.y;
  _position.z = position.z;
}

void				GlGraphics::GlObject::setPosition(int x, int y)
{
  _position.x = x;
  _position.y = -y;
}

const GlGraphics::Vector3f	GlGraphics::GlObject::getPosition(void) const
{
  return (_position);
}

void				GlGraphics::GlObject::setRotation(float angle)
{
  this->_rotation = angle;
}

float				GlGraphics::GlObject::getRotation(void) const
{
  return (this->_rotation);
}

void				GlGraphics::GlObject::setColor(const gdl::Color&)
{
}

//
// Texture object based on baseline GlObject
//

std::map<eBlockType, gdl::Image>	GlGraphics::GlTexturedObj::_texList;

GlGraphics::GlTexturedObj::GlTexturedObj(const Vector3f &position)
  : GlObject(position) {}


gdl::Image &	GlGraphics::GlTexturedObj::getTexture(eBlockType blockId)
{
  return (GlTexturedObj::_texList[blockId]);
}


void		GlGraphics::GlTexturedObj::putTexture(eBlockType blockId,
						      const gdl::Image &texture)
{
  GlTexturedObj::_texList[blockId] = texture;
}


//
// 3D model object based on baseline GlObject
//

std::map<eBlockType, gdl::Model>	GlGraphics::GlModelObj::_modelList;

GlGraphics::GlModelObj::GlModelObj(const Vector3f &position)
  : GlObject(position)
{
}

gdl::Model &	GlGraphics::GlModelObj::getModel(eBlockType blockId)
{
  return (GlGraphics::GlModelObj::_modelList[blockId]);
}


void		GlGraphics::GlModelObj::putModel(eBlockType blockId,
						 const gdl::Model &model)
{
  GlGraphics::GlModelObj::_modelList[blockId] = model;
}

void		GlGraphics::GlModelObj::setColor(const gdl::Color& color)
{
  this->_model.set_default_model_color(color);  
}
