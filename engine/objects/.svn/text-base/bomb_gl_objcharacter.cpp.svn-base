//
// bomb_gl_objcharacter.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/workshop/engine/objects
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Mon May  9 15:34:09 2011 pierre le
// Last update Sun Jun  5 13:28:43 2011 nicolas laille
//

#include	<GL/gl.h>
#include	"AnimStates.hpp"

#include	"bomb_gl_drawableobjs.hh"

// Caution: positions sent to constructor refer to the MAP COORDINATES,
//          as for any other kind of object.
//          However, movements ordered by user through the keyboard change
//          the position in ABSOLUTE COORDINATES, to allow fluent movements.
//          This is why positions are converted in the constructor, but not
//          in the update function.


GlGraphics::DrawableObj::Character::Character(const Vector3f &position)
  : GlModelObj(position),
    _animState(gdl::Anim::PAUSE), _moving(false)
{
  // Load model from list
  //this->_model = gdl::Model(this->getModel(B_CHARACTER));
  this->_model = gdl::Model::load("./models/marvinLowLowPo.fbx");
}


void		GlGraphics::DrawableObj::Character::initialize(void)
{
  // Setup animations
  this->_model.cut_animation(this->_model, "Take 001",
			     34, 54, std::string("Running"));
  this->_model.set_anim_state("Running", gdl::Anim::LOOP);
  this->_model.set_anim_speed("Running", 0.25);
  this->_model.play("Running", gdl::Anim::LOOP);
}


void		GlGraphics::DrawableObj::Character::update(gdl::GameClock const &clock,
							   gdl::Input &)
{
  this->_model.update(clock);
}


void		GlGraphics::DrawableObj::Character::draw(void)
{
  //  gdl::Model::Begin();
  glPushMatrix();
  // Following additions are arbitrary and related to the model sizes.
  // May change depending on the model used.
  glTranslatef(_position.x + 120.0f, _position.y + 100.0f, _position.z);
  glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
  glRotatef(this->_rotation, 0.0f, 1.0f, 0.0f);
  glScalef(0.75, .50, 1.0);
  this->_model.draw();
  glPopMatrix();
  //  gdl::Model::End();
}


void		GlGraphics::DrawableObj::Character::animate(const std::string &animName,
							    gdl::Anim::AnimStates animState)
{
  this->_model.play(animName, animState);
  this->_animState = animState;
}
