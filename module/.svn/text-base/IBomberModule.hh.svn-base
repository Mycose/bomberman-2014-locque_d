//
// IBomberModule.hh for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Fri May 27 12:20:47 2011 nicolas laille
// Last update Sun Jun  5 11:26:07 2011 nicolas laille
//

#ifndef		__IBOMBERMODULE_HH__
# define	__IBOMBERMODULE_HH__

#include	<Game.hpp>
#include	<GameClock.hpp>
#include	<Input.hpp>

enum		eBomberModule
  {
    B_GAME = 1,
    B_PAUSE = 2,
    B_LOAD = 3
  };

class		sendData;

class		IBomberModule
{
public :
  virtual ~IBomberModule(){};
  
  virtual void		initialize(sendData&) = 0;
  virtual void		load(void) = 0;
  virtual void		update(const gdl::GameClock &, gdl::Input &) = 0;
  virtual void		draw(void) = 0;
  virtual void		unload(sendData&) = 0;
  virtual bool		isEnd(void) const = 0;
  virtual bool		isOver(void) const = 0;
  virtual eBomberModule	nextModule(void) = 0;
};

#endif		/* __IBOMBERMODULE_HH__ */
