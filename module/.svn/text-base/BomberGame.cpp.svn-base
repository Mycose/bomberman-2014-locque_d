//
// Bombergame.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Mon May 16 11:16:30 2011 nicolas laille
// Last update Sun Jun  5 16:33:55 2011 nicolas laille
//


#include	<iostream>
#include	<stdexcept>

#include	<GL/gl.h>
#include	<GL/glu.h>

#include	"bomb_gl_object.hh"
#include	"bomb_gl_engine.hh"
#include	"bomb_gl_drawableobjs.hh"
#include	"IABomberman.hh"
#include	"Bomberman.hh"

#include	"BomberGame.hh"

#include	"sendData.hh"

BomberGame::BomberGame()
  : save(), nextSave(0), mapgen(),
    _players(0), _cameras(0),
    _lose("./textures/Lose.png"),
    _win("./textures/Win.png"),
    _pause(false),
    _end(false),
    _finish(false),
    _bug(false)
{
}

BomberGame::~BomberGame()
{
  std::list<ABomberman *>::iterator	itp;

  this->_lose.unload();
  this->_win.unload();
  this->_pause = false;
  this->_end = false;
  this->_finish = false;
  for (itp = this->_players.begin(); itp != this->_players.end(); ++itp)
    delete (*itp);
  this->mapgen.getMap().unload();
  this->_players.clear();
  this->_cameras.clear();
}

void		BomberGame::initMap(Map& map)
{
  int		x;
  int		y;

  this->addStaticObject(new GlGraphics::Graphic(new GlGraphics::DrawableObj::Ground(GlGraphics::Vector3f(map.getWidth(), map.getHeight()))));
  for (y = 0; y < map.getHeight(); y++)
    {
      for (x = 0; x < map.getWidth(); x++)
	{
	  if (!map.getElement(x, y)->getDestructible() && !map.getElement(x, y)->getCrossable())
	    this->addStaticObject(map.getElement(x, y));
	}
    }
}

void		BomberGame::initPlayers(Map& map, Playerpos& players, bool two)
{
  int		x;

  for (x = 0; x < players.size(); x++)
    {
      if (x == 0)
	this->addPlayer(new Bomberman(players[x].first, players[x].second), (two ? GlGraphics::GLV_RIGHTSCR : GlGraphics::GLV_SINGLESCR));
      else if (x == 1 && two)
	{
	  this->addPlayer(new Bomberman(players[x].first, players[x].second,
					gdl::Keys::W,
					gdl::Keys::S,
					gdl::Keys::D,
					gdl::Keys::A,
					gdl::Keys::Space), GlGraphics::GLV_LEFTSCR);
	}
      else
	this->addPlayer(new IABomberman(players[x].first, players[x].second, map, "./lua/script/low.lua"), static_cast<GlGraphics::GlViewField>(-1));
    }
}

void		BomberGame::initialize(sendData& data)
{
  std::list<ABomberman *>::iterator	itp;
  std::list<GlGraphics::GlCamera>::iterator	itc;

  if (data.getSaveName() != ""
      && !this->save.loadGame(data.getSaveName(), this->_players, this->mapgen, this->_cameras))
    {
      this->_players.clear();
      this->_cameras.clear();
      this->_finish = true;
      this->_bug = true;
      return ;
    }
  else if (data.getSaveName() == "")
    {
      this->mapgen.create(data.getSizeMap(), data.getSizeMap(), data.getNbPlayer());
      this->initPlayers(this->mapgen.getMap(), this->mapgen.getPlayerpos(), data.getTwoPlayer());
    }
  for (itp = this->_players.begin(); itp != this->_players.end(); ++itp)
    (*itp)->initialize();
  for (itc = this->_cameras.begin(); itc != this->_cameras.end(); ++itc)
    (*itc).initialize();
  this->mapgen.getMap().initialize();
  this->initMap(this->mapgen.getMap());
  this->_staticObjs.initialize();
}

void		BomberGame::load(void)
{
  // Initialize OpenGL Settings
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}

void		BomberGame::checkWin(void)
{
  std::list<ABomberman *>::iterator	itbc;
  std::list<GlGraphics::GlCamera>::iterator	itc;
  int		alive;

  alive = 0;
  for (itbc = this->_players.begin(); itbc != this->_players.end(); itbc++)
    {
      if (!(*itbc)->isDead())
	alive++;
      if (alive > 1)
	return ;
    }
  for (itc = this->_cameras.begin(), itbc = this->_players.begin();
       itc != this->_cameras.end() && itbc != this->_players.end();
       ++itc, itbc++)
    {
      if (!(*itbc)->isDead())
	{
	  (*itbc)->setWin();
	  this->_end = true;
	  return ;
	}
    }
}

void		BomberGame::update(const gdl::GameClock &gameClock_, gdl::Input &input_)
{
  std::list<ABomberman *>::iterator	itp;
  std::list<ABomberman *>::iterator	itbc;
  std::list<GlGraphics::GlCamera>::iterator	itc;
  int		alive;

  if (!this->_end)
    {
      if (input_.isKeyDown(gdl::Keys::F5) && this->nextSave <= 0)
	{
	  this->nextSave = 5;
	  this->save.createSave(this->_players, this->mapgen);
	}
      if (input_.isKeyDown(gdl::Keys::Escape))
	this->_pause = true;
      if (this->nextSave > 0)
	this->nextSave -= gameClock_.getElapsedTime();
      for (itp = this->_players.begin(); itp != this->_players.end(); ++itp)
	(*itp)->update(gameClock_, input_, this->mapgen.getMap());
      for (alive = 0, itc = this->_cameras.begin(), itbc = this->_players.begin();
	   itc != this->_cameras.end() && itbc != this->_players.end();
	   ++itc, itbc++)
	{
	  if (!(*itbc)->isDead())
	    {
	      (*itc).update(gameClock_, input_);
	      this->mapgen.getMap().update((*(*itbc)), gameClock_, input_);
	      alive++;
	    }
	}
      this->_end = !alive;
      if (alive == 1)
	this->checkWin();
    }
  else
    {
      if (input_.isKeyDown(gdl::Keys::Return))
	this->_finish = true;
    }
}

void		BomberGame::draw(void)
{
  std::list<ABomberman *>::iterator	itp;
  std::list<ABomberman *>::iterator	itbc;
  std::list<GlGraphics::GlCamera>::iterator	itc;

  for (itc = this->_cameras.begin(), itbc = this->_players.begin();
       itc != this->_cameras.end() && itbc != this->_players.end();
       ++itc, itbc++)
    {
      (*itc).draw();
      if ((*itbc)->isDead())
	this->_lose.draw((*itc).getViewField());
      else if ((*itbc)->getWin())
	this->_win.draw((*itc).getViewField());
      else
	{
	  for (itp = this->_players.begin(); itp != this->_players.end(); ++itp)
	    {
	      if (!(*itp)->isDead()
		  && (*itbc)->view(*(*itp)))
		(*itp)->draw();
	    }
	  this->mapgen.getMap().draw((*(*itbc)));
	  this->_staticObjs.draw();
	}
    }
}

void		BomberGame::unload(sendData& data)
{
  std::list<ABomberman *>::iterator	itbc;
  std::list<GlGraphics::GlCamera>::iterator	itc;
  int		highscore;
  int		loop;
  
  if (!this->_bug)
    {
      highscore = -1;
      for (loop = 1, itc = this->_cameras.begin(), itbc = this->_players.begin();
	   itc != this->_cameras.end() && itbc != this->_players.end();
	   ++itc, itbc++, loop++)
	{
	  if (highscore < (*itbc)->getScore())
	    {
	      highscore = (*itbc)->getScore();
	      data.setPlayerScore(loop);
	    }
	}  
      data.setScore(highscore);
      data.setLoadMenu(GameMenu::FRAME_SCORES);
    }
  else
    data.setLoadMenu(GameMenu::FRAME_MAIN);
  glDisable(GL_DEPTH_TEST);
  glViewport(0, 0, GlEngine::_winX, GlEngine::_winY);
}

bool		BomberGame::isEnd(void) const
{
  return (this->_pause);
}

bool		BomberGame::isOver(void) const
{
  return (this->_finish);
}

eBomberModule	BomberGame::nextModule(void)
{
  if (this->_pause)
    {
      this->_pause = false;
      return (B_PAUSE);
    }
  return (B_LOAD);
}

void		BomberGame::addPlayer(ABomberman *bomber, GlGraphics::GlViewField cam)
{
  this->_players.push_back(bomber);
  if (cam != -1)
    this->_cameras.push_back(GlGraphics::GlCamera(bomber, cam));
}

void		BomberGame::removePlayer(ABomberman *bomber)
{
  this->_players.remove(bomber);
}
