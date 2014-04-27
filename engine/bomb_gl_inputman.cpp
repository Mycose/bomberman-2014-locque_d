//
// bomb_gl_inputman.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/workshop/engine/includes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri May 13 12:54:24 2011 pierre le
// Last update Mon May 16 12:44:48 2011 nicolas laille
//

#include	<stdexcept>

#include	"Input.hpp"

#include	"bomb_gl_inputman.hh"


GlGraphics::GlInputs::GlInputs(void)
  : _keyUp(gdl::Keys::Up),
    _keyDown(gdl::Keys::Down),
    _keyLeft(gdl::Keys::Left),
    _keyRight(gdl::Keys::Right),
    _keyDrop(gdl::Keys::Space)
{
}


void		GlGraphics::GlInputs::setupKeys(glKey keyUp,
						glKey keyDown,
						glKey keyLeft,
						glKey keyRight,
						glKey keyDrop)
{
  this->_keyUp = keyUp;
  this->_keyDown = keyDown;
  this->_keyLeft = keyLeft;
  this->_keyRight = keyRight;
  this->_keyDrop = keyDrop;
}


GlGraphics::eInputKey	GlGraphics::GlInputs::getKeys(void) const
{
  if (this->_input == NULL)
    throw std::runtime_error("GlInputs::getKeys: game clock not set.");
  if (this->_input->isKeyDown(_keyUp))
    return (K_UP);
  else if (this->_input->isKeyDown(_keyDown))
    return (K_DOWN);
  else if (this->_input->isKeyDown(_keyLeft))
    return (K_LEFT);
  else if (this->_input->isKeyDown(_keyRight))
    return (K_RIGHT);
  else if (this->_input->isKeyDown(_keyDrop))
    return (K_DROP);
  return (K_NONE);
}


void		GlGraphics::GlInputs::bindEngine(gdl::Input *input)
{
  this->_input = input;
}
