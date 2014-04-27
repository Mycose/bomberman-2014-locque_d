//
// bomb_gl2d_btnpushaction.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects2D
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Sun Jun  5 13:47:18 2011 pierre le
// Last update Sun Jun  5 16:29:35 2011 nicolas laille
//

#include	"StrTexture.hh"

#include	"GameMenu.hh"
#include	"LoadGame.hh"

#include	"bomb_gl2d_btnaction.hh"
#include	"bomb_gl2d_buttonmenuitem.hh"
#include	"bomb_gl2d_btnpushaction.hh"


// For Load game class
template GlGraphics::PushActionBtn<LoadGame>::PushActionBtn(const Vector3f &position,
							    const Vector3f &size,
							    const std::string &text,
							    slotFunc funcToCall,
							    LoadGame &classToApply,
							    const gdl::Image &objImage,
							    const gdl::Image &objImageEntered);
template void	GlGraphics::PushActionBtn<LoadGame>::initialize(void);
template void	GlGraphics::PushActionBtn<LoadGame>::OnItemUpdate(const gdl::GameClock &,
							   gdl::Input &);
template void	GlGraphics::PushActionBtn<LoadGame>::OnMouseClick(void);
template void	GlGraphics::PushActionBtn<LoadGame>::OnMouseEnter(void);
template void	GlGraphics::PushActionBtn<LoadGame>::OnMouseLeave(void);
template void	GlGraphics::PushActionBtn<LoadGame>::setText(const std::string &);
template const std::string &GlGraphics::PushActionBtn<LoadGame>::getText(void) const;


template	<class SlotAction>
GlGraphics::PushActionBtn<SlotAction>::PushActionBtn(const Vector3f &position,
						 const Vector3f &size,
						 const std::string &text,
						 slotFunc funcToCall,
						 SlotAction &classToApply,
						 const gdl::Image &objImage,
						 const gdl::Image &objImageEntered)
  : BtnAction<SlotAction>(position, size, NULL, classToApply,
			  objImage, objImageEntered),
    _text(GlGraphics::Vector3f(position.x + 28, position.y + 12),
	  text, 30.0f, 16.0f),
    _slotFuncToCall(funcToCall)
{
}


template	<class SlotAction>
void		GlGraphics::PushActionBtn<SlotAction>::initialize(void)
{
}


template	<class SlotAction>
void		GlGraphics::PushActionBtn<SlotAction>::OnItemUpdate(const gdl::GameClock &,
						      gdl::Input &)
{
}


template	<class SlotAction>
void		GlGraphics::PushActionBtn<SlotAction>::OnItemDraw(void)
{
  this->_text.draw();
}


template	<class SlotAction>
void		GlGraphics::PushActionBtn<SlotAction>::OnMouseClick(void)
{
  if (_slotFuncToCall != NULL)
    (this->_classToApply.*_slotFuncToCall)(this->_text.getText());
}


template	<class SlotAction>
void		GlGraphics::PushActionBtn<SlotAction>::OnMouseEnter(void)
{
}


template	<class SlotAction>
void		GlGraphics::PushActionBtn<SlotAction>::OnMouseLeave(void)
{
}


template	<class SlotAction>
void		GlGraphics::PushActionBtn<SlotAction>::setText(const std::string &text)
{
  this->_text.setText(text);
}


template	<class SlotAction>
const std::string &GlGraphics::PushActionBtn<SlotAction>::getText(void) const
{
  return (_text.getText());
}
