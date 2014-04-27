//
// IModule.hh for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Fri May 27 12:20:47 2011 nicolas laille
// Last update Sat Jun  4 20:21:24 2011 nicolas laille
//

#ifndef		__IMODULE_HH__
# define	__IMODULE_HH__

#include	<Game.hpp>
#include	<GameClock.hpp>
#include	<Input.hpp>

enum		eModule
  {
    GAME = 1,
    MENU = 2
  };

class		sendData;

class		IModule
{
public :
  virtual ~IModule(){};

  virtual void		initialize(sendData&) = 0;
  virtual void		update(const gdl::GameClock &, gdl::Input &) = 0;
  virtual void		draw(void) = 0;
  virtual void		unload(sendData&) = 0;
  virtual bool		isEnd(void) = 0;
  virtual IModule*	copy(void) const = 0;
};

#endif		/* __IMODULE_HH__ */
