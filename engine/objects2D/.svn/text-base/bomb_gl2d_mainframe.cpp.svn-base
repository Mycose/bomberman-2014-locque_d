//
// bomb_gl2d_mainframe.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects2D
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri Jun  3 11:22:51 2011 pierre le
// Last update Fri Jun  3 11:43:44 2011 pierre le
//

#include	"MenuFrame.hh"
#include	"StrTexture.hh"

#include	"bomb_gl2d_mainframe.hh"

#include	"bomb_gl2d_btnnewgame.hh"
#include	"bomb_gl2d_btnloadgame.hh"
#include	"bomb_gl2d_btnquitgame.hh"
#include	"bomb_gl2d_btnhighscores.hh"


void		GlGraphics::MenuMainFrame::initialize(void)
{
  addMenuItemToList(new GlGraphics::NewGameBtn(GlGraphics::Vector3f(50, 200)));
  addMenuItemToList(new GlGraphics::LoadGameBtn(GlGraphics::Vector3f(50, 300)));
  addMenuItemToList(new GlGraphics::HighscoresBtn(GlGraphics::Vector3f(50, 400)));
  addMenuItemToList(new GlGraphics::QuitGameBtn(GlGraphics::Vector3f(50, 500)));
  addMenuItemToList(new GlGraphics::StrTexture(GlGraphics::Vector3f(20, 770),
					       "Copyright(C) 2011 - LAILLE Nicolas, LE Pierre, LOCQUE Damien, MORISSARD Clement", 24, 10));
}
