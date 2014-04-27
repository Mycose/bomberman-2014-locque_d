//
// bomb_gl2d_textboxitem.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/includes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri Jun  3 16:39:37 2011 pierre le
// Last update Sat Jun  4 17:56:06 2011 pierre le
//

#include	"bomb_gl2d_textboxitem.hh"


GlGraphics::TextBoxItem::TextBoxItem(const Vector3f &position,
						  const Vector3f &size,
						  const std::string &str)
  : GlMenuItem(position, size, gdl::Image::load("./textures/text_box_flat.png")),
    _text(Vector3f(position.x + 5, position.y + 5), str, size.y / 1.33f, 20.0f)
{
}


void		GlGraphics::TextBoxItem::initialize() {}


void		GlGraphics::TextBoxItem::OnItemUpdate(const gdl::GameClock &,
						      gdl::Input &) {}


void		GlGraphics::TextBoxItem::OnItemDraw(void)
{
  this->_text.draw();
}


void		GlGraphics::TextBoxItem::OnMouseClick(void) {}


void		GlGraphics::TextBoxItem::OnMouseEnter(void) {}


void		GlGraphics::TextBoxItem::OnMouseLeave(void) {}


void		GlGraphics::TextBoxItem::setText(const std::string &str)
{
  this->_text.setText(str);
}


const std::string &	GlGraphics::TextBoxItem::getText(void) const
{
  return (this->_text.getText());
}
