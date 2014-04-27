//
// bomb_gl2d_btnaction.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects2D
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Sat Jun  4 17:52:41 2011 pierre le
// Last update Sun Jun  5 14:55:15 2011 pierre le
//

#include	<iostream>

#include	"Image.hpp"

#include	"GameMenu.hh"

#include	"NewGame.hh"
#include	"LoadGame.hh"
#include	"BomberPause.hh"
#include	"bomb_gl2d_mainframe.hh"

#include	"bomb_gl2d_btnaction.hh"


// For New game class
template GlGraphics::BtnAction<NewGame>::BtnAction(const Vector3f &,
						   const Vector3f &,
						   classFunc,
						   NewGame &,
						   const gdl::Image &,
						   const gdl::Image &);
template void	GlGraphics::BtnAction<NewGame>::initialize(void);
template void	GlGraphics::BtnAction<NewGame>::OnItemUpdate(const gdl::GameClock &,
							   gdl::Input &);
template void	GlGraphics::BtnAction<NewGame>::OnMouseClick(void);
template void	GlGraphics::BtnAction<NewGame>::OnMouseEnter(void);
template void	GlGraphics::BtnAction<NewGame>::OnMouseLeave(void);


// For Load game class
template GlGraphics::BtnAction<LoadGame>::BtnAction(const Vector3f &,
						    const Vector3f &,
						    classFunc,
						    LoadGame &,
						    const gdl::Image &,
						    const gdl::Image &);
template void	GlGraphics::BtnAction<LoadGame>::initialize(void);
template void	GlGraphics::BtnAction<LoadGame>::OnItemUpdate(const gdl::GameClock &,
							   gdl::Input &);
template void	GlGraphics::BtnAction<LoadGame>::OnMouseClick(void);
template void	GlGraphics::BtnAction<LoadGame>::OnMouseEnter(void);
template void	GlGraphics::BtnAction<LoadGame>::OnMouseLeave(void);


// For Main menu frame class
template GlGraphics::BtnAction<GlGraphics::MenuMainFrame>::BtnAction(const Vector3f &,
								     const Vector3f &,
								     classFunc,
								     GlGraphics::MenuMainFrame &,
								     const gdl::Image &,
								     const gdl::Image &);
template void	GlGraphics::BtnAction<GlGraphics::MenuMainFrame>::initialize(void);
template void	GlGraphics::BtnAction<GlGraphics::MenuMainFrame>::OnItemUpdate(const gdl::GameClock &,
							   gdl::Input &);
template void	GlGraphics::BtnAction<GlGraphics::MenuMainFrame>::OnMouseClick(void);
template void	GlGraphics::BtnAction<GlGraphics::MenuMainFrame>::OnMouseEnter(void);
template void	GlGraphics::BtnAction<GlGraphics::MenuMainFrame>::OnMouseLeave(void);


// For Bomber pause frame class
template GlGraphics::BtnAction<BomberPause>::BtnAction(const Vector3f &,
						       const Vector3f &,
						       classFunc,
						       BomberPause &,
						       const gdl::Image &,
						       const gdl::Image &);
template void	GlGraphics::BtnAction<BomberPause>::initialize(void);
template void	GlGraphics::BtnAction<BomberPause>::OnItemUpdate(const gdl::GameClock &,
							   gdl::Input &);
template void	GlGraphics::BtnAction<BomberPause>::OnMouseClick(void);
template void	GlGraphics::BtnAction<BomberPause>::OnMouseEnter(void);
template void	GlGraphics::BtnAction<BomberPause>::OnMouseLeave(void);


template	<class FrameAction>
GlGraphics::BtnAction<FrameAction>::BtnAction(const Vector3f &position,
					      const Vector3f &size,
					      classFunc funcToCall,
					      FrameAction &classToApply,
					      const gdl::Image &objImage,
					      const gdl::Image &objImageEntered)
  : GlButtonMenuItem(position, size,
		     objImage, objImageEntered),
    _funcToCall(funcToCall),
    _classToApply(classToApply)
{
}


template	<class FrameAction>
void		GlGraphics::BtnAction<FrameAction>::initialize(void)
{
}


template	<class FrameAction>
void		GlGraphics::BtnAction<FrameAction>::OnItemUpdate(const gdl::GameClock &,
						  gdl::Input &)
{
}


template	<class FrameAction>
void		GlGraphics::BtnAction<FrameAction>::OnMouseClick(void)
{
  if (_funcToCall != NULL)
    (_classToApply.*_funcToCall)();
}


template	<class FrameAction>
void		GlGraphics::BtnAction<FrameAction>::OnMouseEnter(void)
{
}


template	<class FrameAction>
void		GlGraphics::BtnAction<FrameAction>::OnMouseLeave(void)
{
}
